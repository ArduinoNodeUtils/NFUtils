// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#include <Wire.h>
#include <ArduinoLogging.h>
#include "nfutils/InputPullupButton.h"

namespace nfutils {

InputPullupButton::InputPullupButton(int pin, Logger& logger): _pin(pin), _logger(logger) {
    pinMode(_pin, INPUT_PULLUP);
}

ButtonState InputPullupButton::read() {
    return _buttonState;
}

ButtonState InputPullupButton::readAndUpdate() {

    ButtonState buttonState = ButtonState::ReleasedIdle;

    LOG_DEBUG(_logger, "current button value: %d", _buttonValue);

    PinStatus newButtonValue = digitalRead(_pin);
    if (newButtonValue != _buttonValue) {
        for (int i = 0; i < 10; i++) {
            delay(5);
            newButtonValue = digitalRead(_pin);
            if (newButtonValue == _buttonValue) {
                break;
            }
        }
    }

    LOG_DEBUG(_logger, "new button value: %d", newButtonValue);
    if (newButtonValue != _buttonValue) {
        if (!newButtonValue) {
            buttonState = ButtonState::Pressed;
        } else {
            buttonState = ButtonState::Released;
        }
    } else {
        if (!_buttonValue) {
            buttonState = ButtonState::PressedIdle;
        } else {
            buttonState = ButtonState::ReleasedIdle;
        }
    }
    _buttonValue = newButtonValue;
    _buttonState = buttonState;
    return buttonState;
}

}
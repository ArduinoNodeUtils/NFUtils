// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include <Logger.h>

#include "InputElement.h"
// #include <api/Common.h>
namespace nfutils {

    enum class ButtonState: int {
        ReleasedIdle,
        PressedIdle,
        Pressed,
        Released
    };
    
    class InputPullupButton: public InputElement<ButtonState> {
    
    public:
        InputPullupButton(int pin, Logger& logger);
    
        ButtonState readAndUpdate();
        ButtonState read();
    
    private:
        pin_size_t _pin;
        Logger& _logger;
    
        PinStatus _buttonValue = HIGH;
        ButtonState _buttonState = ButtonState::ReleasedIdle;
    };

}
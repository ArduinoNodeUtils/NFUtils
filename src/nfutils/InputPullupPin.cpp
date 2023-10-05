// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#include "nfutils/InputPullupPin.h"


namespace nfutils {

InputPullupPin::InputPullupPin(const pin_size_t pin, DigitalReadFuncType digitalReadFunc) 
    : _pin(pin), _digitalReadFunc(digitalReadFunc) {
        pinMode(_pin, INPUT_PULLUP);
    }

bool InputPullupPin::read() {
    auto val = _digitalReadFunc(_pin);
    return val == LOW;
}

}
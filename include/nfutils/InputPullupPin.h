// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include "InputElement.h"
#include "Common.h"
#include <Wire.h>

namespace nfutils {
    class InputPullupPin : public InputElement<bool> {
    public:
        InputPullupPin(const pin_size_t pin,
                       DigitalReadFuncType digitalReadFunc=digitalRead);
        bool read();
    private:
        const pin_size_t _pin;
        DigitalReadFuncType _digitalReadFunc;
    };
}
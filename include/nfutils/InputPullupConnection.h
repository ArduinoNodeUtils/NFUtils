// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include "InputElement.h"
#include "Common.h"
#include <Wire.h>

namespace nfutils {

    enum class InputConnectionState : int {
        Disconnected,
        Connected
    };
    
    class InputPullupConnection : public InputElement<InputConnectionState> {
    public:
        InputPullupConnection(const pin_size_t pin,
                              DigitalReadFuncType digitalReadFunc=digitalRead);
        InputConnectionState read();
    private:
        const pin_size_t _pin;
        DigitalReadFuncType _digitalReadFunc;
    };
}
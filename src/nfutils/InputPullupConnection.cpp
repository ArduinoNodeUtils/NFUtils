// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#include "nfutils/InputPullupConnection.h"

namespace nfutils {

InputPullupConnection::InputPullupConnection(const pin_size_t pin, DigitalReadFuncType digitalReadFunc) 
    : _pin(pin), _digitalReadFunc(digitalReadFunc) {
        pinMode(_pin, INPUT_PULLUP);
    }

InputConnectionState InputPullupConnection::read() {
    auto val = _digitalReadFunc(_pin);

    if (val == LOW) {
        return InputConnectionState::Connected;
    } else {
        return InputConnectionState::Disconnected;
    }
}

}
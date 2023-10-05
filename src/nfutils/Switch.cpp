// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#include "nfutils/Switch.h"

#include <Wire.h>

namespace nfutils {

Switch::Switch(const pin_size_t pin, const PinStatus onStatus) : _pin(pin), _onStatus(onStatus) {
    pinMode(_pin, INPUT);
}

bool Switch::read() {
    return digitalRead(_pin) == _onStatus;
}

}
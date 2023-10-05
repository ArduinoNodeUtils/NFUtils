// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include <Arduino.h>
#include "InputElement.h"

namespace nfutils {

class Switch : public InputElement<bool> {
public:
    Switch(const pin_size_t pin, const PinStatus onStatus=HIGH);

    bool read() override;
private:
    const pin_size_t _pin;
    const PinStatus _onStatus;
};

}
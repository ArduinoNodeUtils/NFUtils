// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include <type_traits>

#include "Range.h"

#include "Common.h"
#include "InputElement.h"


namespace nfutils {

template <typename T>
class PotentioMeter : public InputElement<T> {
public:
    PotentioMeter(const int pin, Range<T> limits, AnalogReadFuncType analogReadFunc=analogRead)
    : _pin(pin), _limits(limits), _range(limits.max - limits.min), _analogReadFunc(analogReadFunc) {
        static_assert(std::is_arithmetic<T>::value, "Not an arithmetic type");
    }

    T read() {
        auto analog = _analogReadFunc(_pin);
        float val = static_cast<float>(analog);

        auto calc = float (val / 1023.0) * _range + _limits.min;

        return static_cast<T>(calc);
    }

    T min() {
        return _limits.min;
    }

    T max() {
        return _limits.max;
    }

private:
    const int _pin;
    const Range<T> _limits;
    const T _range;
    AnalogReadFuncType _analogReadFunc;
};

}

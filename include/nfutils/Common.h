// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include <Arduino.h>
#include <Wire.h>

#include <functional>

#include <nf/StdMessages.h>
#include <nf/Vector.h>

namespace nfutils {

    typedef PinStatus (*DigitalReadFuncType)(pin_size_t);
    typedef void (*DigitalWriteFuncType)(pin_size_t, PinStatus);
    typedef int (*AnalogReadFuncType)(pin_size_t);
    typedef void (*AnalogWriteFuncType)(pin_size_t, int);
    typedef void (*PinModeFuncType)(pin_size_t, PinMode);
    
    template <class T>
    using MessageCallback = std::function<void (nf::Message<T>*)>;
    
    template <typename T> int sgn(T val) {
        return (T(0) < val) - (val < T(0));
    }
    
    template <typename T, size_t S>
    T reduce(const nf::Vector<T, S>& data, const std::function<T(T,T)>& fn, const T initialValue) {
        auto accu = initialValue;
    
        for (auto val : data) {
            accu = fn(accu, val);
        }
        return accu;
    }
}
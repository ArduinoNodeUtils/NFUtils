// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

namespace nfutils {

template <typename T>
class Range {
    public:
    
    Range(const T minimum, const T maximum): min(minimum), max(maximum), absolute(max-min) {}
    Range() {}
    
    T min;
    T max;
    T absolute;

};

}
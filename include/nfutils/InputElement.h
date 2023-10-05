// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

namespace nfutils {
    template <typename T>
    class InputElement {
    public:
        virtual T read() = 0;
    };
}
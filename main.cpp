// @file      main.cpp
// @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2021 Ignacio Vizzo, all rights reserved
#include <thread>

#include "ScopeTimer.h"

int main() {
    {
        ScopeTimer<std::micro> t1("microsecs counter");
        std::this_thread::sleep_for(std::chrono::microseconds(1000));
    }
    {
        ScopeTimer<std::milli> t1("miliseconds counter");
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    return 0;
}

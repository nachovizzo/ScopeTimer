// @file      ScopeTimer.h
// @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2021 Ignacio Vizzo, all rights reserved
//
// Partially inspired in Open3D/cpp/utility/Timer.h
#pragma once
#include <fmt/core.h>

#include <chrono>
#include <ratio>
#include <string>

// Pick on of this clock ratios, defined in the <ratio> header file
// typedef ratio<1,       1000000000000000000> atto;
// typedef ratio<1,          1000000000000000> femto;
// typedef ratio<1,             1000000000000> pico;
// typedef ratio<1,                1000000000> nano;
// typedef ratio<1,                   1000000> micro;
// typedef ratio<1,                      1000> milli;
// typedef ratio<1,                       100> centi;
// typedef ratio<1,                        10> deci;
// typedef ratio<                       10, 1> deca;
// typedef ratio<                      100, 1> hecto;
// typedef ratio<                     1000, 1> kilo;
// typedef ratio<                  1000000, 1> mega;
// typedef ratio<               1000000000, 1> giga;
// typedef ratio<            1000000000000, 1> tera;
// typedef ratio<         1000000000000000, 1> peta;
// typedef ratio<      1000000000000000000, 1> exa;
template <typename Period = std::milli, typename FloatT = double>
class ScopeTimer {
public:
    using TimeT = std::chrono::duration<FloatT, Period>;
    ScopeTimer(const std::string &timer_info) : timer_info_(timer_info) { Start(); }
    ~ScopeTimer() {
        Stop();
        Print();
    }

    // Avoid strange creation of the ScopteTimer object
    ScopeTimer() = delete;
    ScopeTimer(const ScopeTimer &) = delete;
    void operator=(const ScopeTimer &) = delete;

private:
    inline void Start() { start_time_ = GetSystemTime(); }
    inline void Stop() { end_time_ = GetSystemTime(); }
    inline void Print() { fmt::print("{} took {:.2f} ms.\n", timer_info_, GetDuration()); }
    inline FloatT GetDuration() { return end_time_ - start_time_; }
    inline FloatT GetSystemTime() {
        TimeT current_time = std::chrono::high_resolution_clock::now().time_since_epoch();
        return current_time.count();
    }

private:
    FloatT start_time_ = 0.0;
    FloatT end_time_ = 0.0;
    std::string timer_info_;
};

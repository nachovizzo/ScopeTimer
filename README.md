# ScopeTimer Header Only Library

## How to use it?

Easy cheesy: If you need milliseconds, just specify it and the compiler will do the rest of the work:

```cpp
#include "ScopeTimer.h"
{
    ScopeTimer<std::milli> t("miliseconds counter");
    // do important stuff
}
```

The results would be:

```shell
miliseconds counter took 1000.12 milliseconds.
```

You are more like a microsecond person?

```cpp
#include "ScopeTimer.h"
{
    ScopeTimer<std::micro> t("microsecs counter");
    // do even more important work
}
```

The results would be:

```shell
microsecs counter took 1279.50 microseconds.
```

## Period duration supported

The ones in the standard C++ library (`#include <ratio>`):

```cpp
typedef ratio<1,       1000000000000000000> atto;
typedef ratio<1,          1000000000000000> femto;
typedef ratio<1,             1000000000000> pico;
typedef ratio<1,                1000000000> nano;
typedef ratio<1,                   1000000> micro;
typedef ratio<1,                      1000> milli;
typedef ratio<1,                       100> centi;
typedef ratio<1,                        10> deci;
typedef ratio<                       10, 1> deca;
typedef ratio<                      100, 1> hecto;
typedef ratio<                     1000, 1> kilo;
typedef ratio<                  1000000, 1> mega;
typedef ratio<               1000000000, 1> giga;
typedef ratio<            1000000000000, 1> tera;
typedef ratio<         1000000000000000, 1> peta;
typedef ratio<      1000000000000000000, 1> exa;
```

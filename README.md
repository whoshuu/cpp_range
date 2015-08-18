# C++ Range

[![Build Status](https://travis-ci.org/whoshuu/cpp_range.svg?branch=master)](https://travis-ci.org/whoshuu/cpp_range)

Have your cake and eat it too. Who says you can't have nice things in an efficient, type-safe, compiled language? Don't let your Python-slinging coworkers have the last laugh, this is C++ Range:

```c++
#include <iostream>
#include "range.h"

using namespace whoshuu;

int main(int argc, char** argv) {
    for (auto i : range(100)) {
        std::cout << i << std::endl; // Prints 0 to 99
    }

    for (auto i : range(10, 100)) {
        std::cout << i << std::endl; // Prints 10 to 99
    }

    for (auto i : range(10, 0, -1) {
        std::cout << i << std::endl; // Prints 10 to 1, counting down
    }

    for (auto i : range(2.718, 100.0, 3.14) {
        std::cout << i << std::endl; // Prints 2.178 to 96.918, by increments of π, yum!
    }
}
```

## Benchmarks

Here's a benchmark using gcc-5.1 with -O2 optimization of my library against a [naive vector range implementation](https://gist.github.com/whoshuu/246b10cdd7341895453f) and [basic for-loop](https://gist.github.com/whoshuu/6eea496a891ef03a5b9e):

![C++ Range Benchmark](https://raw.githubusercontent.com/whoshuu/cpp_range/master/benchmark/benchmark.png)

As you can see, C++ Range behaves identically to a basic for-loop, and both outperform the vector implementation considerably (the last data point is left off because it would ruin the nice benchmark image here!).

You can find raw data for the analysis [here](https://github.com/whoshuu/cpp_range/blob/master/benchmark/benchmark.csv).

## Install

Just throw the header into your project, be wary of the `whoshuu` namespace, and let it rip!

## Other libraries

For a more fully featured iterator toolset, check out Ryan Haining's [cppitertool](https://github.com/ryanhaining/cppitertools) library, which implements most of the Python itertool module in C++. There's also Eric Niebler's [range-v3](https://github.com/ericniebler/range-v3), a formally proposed range library for the C++ standard library.

## Requirements

The only explicit requirement is a C++11 compatible compiler such as clang or gcc. The minimum required version of gcc is unknown, so if anyone has trouble using library with a specific version of gcc, do let me know.

## Contributing

Please fork this repository and contribute back using [pull requests](https://github.com/whoshuu/cpp_range/pulls). Features can be requested using [issues](https://github.com/whoshuu/cpp_range/issues). All code, comments, and critiques are greatly appreciated.

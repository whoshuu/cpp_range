#include <exception>
#include <limits>

#include <gtest/gtest.h>

#include "range.h"


using namespace whoshuu;

TEST(RangeIntegerTests, ValueStopTest) {
    for (auto stop = 0; stop < 100; ++stop) {
        auto expected = 0;
        for (auto computed : range(stop)) {
            EXPECT_EQ(expected, computed);
            ++expected;
        }
    }
}

TEST(RangeIntegerTests, ValueStartStopTest) {
    for (auto start = -100; start < 100; ++start) {
        for (auto stop = start; stop < 100; ++stop) {
            auto expected = start;
            for (auto computed : range(start, stop)) {
                EXPECT_EQ(expected, computed);
                ++expected;
            }
        }
    }
}

TEST(RangeIntegerTests, ValueStartStopStepTest) {
    for (auto start = -100; start < 100; ++start) {
        for (auto stop = start; stop < 100; ++stop) {
            for (auto step = 1; step < 100; ++step) {
                auto expected = start;
                for (auto computed : range(start, stop, step)) {
                    EXPECT_EQ(expected, computed);
                    expected += step;
                }
            }
        }
    }
}

TEST(RangeIntegerTests, ValueStopReverseTest) {
    for (auto stop = 100; stop > 0; --stop) {
        auto expected = 100;
        for (auto computed : range(100, stop, -1)) {
            EXPECT_EQ(expected, computed);
            --expected;
        }
    }
}

TEST(RangeIntegerTests, ValueStartStopReverseTest) {
    for (auto start = 100; start > -100; --start) {
        for (auto stop = start; stop > -100; --stop) {
            auto expected = start;
            for (auto computed : range(start, stop, -1)) {
                EXPECT_EQ(expected, computed);
                --expected;
            }
        }
    }
}

TEST(RangeIntegerTests, ValueStartStopStepReverseTest) {
    for (auto start = 100; start > -100; --start) {
        for (auto stop = start; stop > -100; --stop) {
            for (auto step = -1; step > -100; --step) {
                auto expected = start;
                for (auto computed : range(start, stop, step)) {
                    EXPECT_EQ(expected, computed);
                    expected += step;
                }
            }
        }
    }
}

TEST(RangeIntegerTests, ValueNegativeStopExceptionTest) {
    bool thrown = false;
    try {
        range(-10);
    } catch (const std::invalid_argument& e) {
        thrown = true;
        EXPECT_EQ(std::string{"Range arguments must result in termination"},
                  std::string{e.what()});
    }
    EXPECT_TRUE(thrown);
}

TEST(RangeIntegerTests, ValueStartLargerThanStopExceptionTest) {
    bool thrown = false;
    try {
        range(11, 10);
    } catch (const std::invalid_argument& e) {
        thrown = true;
        EXPECT_EQ(std::string{"Range arguments must result in termination"},
                  std::string{e.what()});
    }
    EXPECT_TRUE(thrown);
}

TEST(RangeIntegerTests, ValueStepWrongDirectionExceptionTest) {
    bool thrown = false;
    try {
        range(0, 10, -1);
    } catch (const std::invalid_argument& e) {
        thrown = true;
        EXPECT_EQ(std::string{"Range arguments must result in termination"},
                  std::string{e.what()});
    }
    EXPECT_TRUE(thrown);
}

TEST(RangeIntegerTests, ValueAnotherStepWrongDirectionExceptionTest) {
    bool thrown = false;
    try {
        range(10, 0, 1);
    } catch (const std::invalid_argument& e) {
        thrown = true;
        EXPECT_EQ(std::string{"Range arguments must result in termination"},
                  std::string{e.what()});
    }
    EXPECT_TRUE(thrown);
}

TEST(RangeIntegerTests, ValueZeroStepExceptionTest) {
    bool thrown = false;
    try {
        range(0, 10, 0);
    } catch (const std::invalid_argument& e) {
        thrown = true;
        EXPECT_EQ(std::string{"Range step argument must not be zero"},
                  std::string{e.what()});
    }
    EXPECT_TRUE(thrown);
}

TEST(RangeIntegerTests, IntegerWrapAroundTest) {
    bool thrown = false;
    try {
        range(int64_t{1}, std::numeric_limits<int64_t>::min(), int64_t{1});
    } catch (const std::invalid_argument& e) {
        thrown = true;
        EXPECT_EQ(std::string{"Range arguments must result in termination"},
                  std::string{e.what()});
    }
    EXPECT_TRUE(thrown);
}

TEST(RangeFloatTests, ValueStopTest) {
    for (auto stop = 0.f; stop < 100.f; ++stop) {
        auto expected = 0.f;
        for (auto computed : range(stop)) {
            EXPECT_EQ(expected, computed);
            ++expected;
        }
    }
}

TEST(RangeFloatTests, ValueStartStopTest) {
    for (auto start = -100.f; start < 100.f; ++start) {
        for (auto stop = start; stop < 100.f; ++stop) {
            auto expected = start;
            for (auto computed : range(start, stop)) {
                EXPECT_EQ(expected, computed);
                ++expected;
            }
        }
    }
}

TEST(RangeFloatTests, ValueStartStopStepTest) {
    for (auto start = -100.f; start < 100.f; ++start) {
        for (auto stop = start; stop < 100.f; ++stop) {
            for (auto step = 1.5f; step < 100.f; ++step) {
                auto expected = start;
                for (auto computed : range(start, stop, step)) {
                    EXPECT_EQ(expected, computed);
                    expected += step;
                }
            }
        }
    }
}

TEST(RangeFloatTests, ValueStopReverseTest) {
    for (auto stop = 100.f; stop > 0.f; --stop) {
        auto expected = 100.f;
        for (auto computed : range(100.f, stop, -1.5f)) {
            EXPECT_EQ(expected, computed);
            expected -= 1.5f;
        }
    }
}

TEST(RangeFloatTests, ValueStartStopReverseTest) {
    for (auto start = 100.f; start > -100.f; --start) {
        for (auto stop = start; stop > -100.f; --stop) {
            auto expected = start;
            for (auto computed : range(start, stop, -1.5f)) {
                EXPECT_EQ(expected, computed);
                expected -= 1.5f;
            }
        }
    }
}

TEST(RangeFloatTests, ValueStartStopStepReverseTest) {
    for (auto start = 100.f; start > -100.f; --start) {
        for (auto stop = start; stop > -100.f; --stop) {
            for (auto step = -1.5f; step > -100.f; --step) {
                auto expected = start;
                for (auto computed : range(start, stop, step)) {
                    EXPECT_EQ(expected, computed);
                    expected += step;
                }
            }
        }
    }
}

TEST(RangeFloatTests, ValueNegativeStopExceptionTest) {
    bool thrown = false;
    try {
        range(-10.f);
    } catch (const std::invalid_argument& e) {
        thrown = true;
        EXPECT_EQ(std::string{"Range arguments must result in termination"},
                  std::string{e.what()});
    }
    EXPECT_TRUE(thrown);
}

TEST(RangeFloatTests, ValueStartLargerThanStopExceptionTest) {
    bool thrown = false;
    try {
        range(11.f, 10.f);
    } catch (const std::invalid_argument& e) {
        thrown = true;
        EXPECT_EQ(std::string{"Range arguments must result in termination"},
                  std::string{e.what()});
    }
    EXPECT_TRUE(thrown);
}

TEST(RangeFloatTests, ValueStepWrongDirectionExceptionTest) {
    bool thrown = false;
    try {
        range(0.f, 10.f, -1.f);
    } catch (const std::invalid_argument& e) {
        thrown = true;
        EXPECT_EQ(std::string{"Range arguments must result in termination"},
                  std::string{e.what()});
    }
    EXPECT_TRUE(thrown);
}

TEST(RangeFloatTests, ValueAnotherStepWrongDirectionExceptionTest) {
    bool thrown = false;
    try {
        range(10.f, 0.f, 1.f);
    } catch (const std::invalid_argument& e) {
        thrown = true;
        EXPECT_EQ(std::string{"Range arguments must result in termination"},
                  std::string{e.what()});
    }
    EXPECT_TRUE(thrown);
}

TEST(RangeFloatTests, ValueZeroStepExceptionTest) {
    bool thrown = false;
    try {
        range(0.f, 10.f, 0.f);
    } catch (const std::invalid_argument& e) {
        thrown = true;
        EXPECT_EQ(std::string{"Range step argument must not be zero"},
                  std::string{e.what()});
    }
    EXPECT_TRUE(thrown);
}

TEST(RangeDoubleTests, ValueStopTest) {
    for (auto stop = 0.; stop < 100.; ++stop) {
        auto expected = 0.;
        for (auto computed : range(stop)) {
            EXPECT_EQ(expected, computed);
            ++expected;
        }
    }
}

TEST(RangeDoubleTests, ValueStartStopTest) {
    for (auto start = -100.; start < 100.; ++start) {
        for (auto stop = start; stop < 100.; ++stop) {
            auto expected = start;
            for (auto computed : range(start, stop)) {
                EXPECT_EQ(expected, computed);
                ++expected;
            }
        }
    }
}

TEST(RangeDoubleTests, ValueStartStopStepTest) {
    for (auto start = -100.; start < 100.; ++start) {
        for (auto stop = start; stop < 100.; ++stop) {
            for (auto step = 1.5; step < 100.; ++step) {
                auto expected = start;
                for (auto computed : range(start, stop, step)) {
                    EXPECT_EQ(expected, computed);
                    expected += step;
                }
            }
        }
    }
}

TEST(RangeDoubleTests, ValueStopReverseTest) {
    for (auto stop = 100.; stop > 0.; --stop) {
        auto expected = 100.;
        for (auto computed : range(100., stop, -1.5)) {
            EXPECT_EQ(expected, computed);
            expected -= 1.5;
        }
    }
}

TEST(RangeDoubleTests, ValueStartStopReverseTest) {
    for (auto start = 100.; start > -100.; --start) {
        for (auto stop = start; stop > -100.; --stop) {
            auto expected = start;
            for (auto computed : range(start, stop, -1.5)) {
                EXPECT_EQ(expected, computed);
                expected -= 1.5;
            }
        }
    }
}

TEST(RangeDoubleTests, ValueStartStopStepReverseTest) {
    for (auto start = 100.; start > -100.; --start) {
        for (auto stop = start; stop > -100.; --stop) {
            for (auto step = -1.5; step > -100.; --step) {
                auto expected = start;
                for (auto computed : range(start, stop, step)) {
                    EXPECT_EQ(expected, computed);
                    expected += step;
                }
            }
        }
    }
}

TEST(RangeDoubleTests, ValueNegativeStopExceptionTest) {
    bool thrown = false;
    try {
        range(-10.);
    } catch (const std::invalid_argument& e) {
        thrown = true;
        EXPECT_EQ(std::string{"Range arguments must result in termination"},
                  std::string{e.what()});
    }
    EXPECT_TRUE(thrown);
}

TEST(RangeDoubleTests, ValueStartLargerThanStopExceptionTest) {
    bool thrown = false;
    try {
        range(11., 10.);
    } catch (const std::invalid_argument& e) {
        thrown = true;
        EXPECT_EQ(std::string{"Range arguments must result in termination"},
                  std::string{e.what()});
    }
    EXPECT_TRUE(thrown);
}

TEST(RangeDoubleTests, ValueStepWrongDirectionExceptionTest) {
    bool thrown = false;
    try {
        range(0., 10., -1.);
    } catch (const std::invalid_argument& e) {
        thrown = true;
        EXPECT_EQ(std::string{"Range arguments must result in termination"},
                  std::string{e.what()});
    }
    EXPECT_TRUE(thrown);
}

TEST(RangeDoubleTests, ValueAnotherStepWrongDirectionExceptionTest) {
    bool thrown = false;
    try {
        range(10., 0., 1.);
    } catch (const std::invalid_argument& e) {
        thrown = true;
        EXPECT_EQ(std::string{"Range arguments must result in termination"},
                  std::string{e.what()});
    }
    EXPECT_TRUE(thrown);
}

TEST(RangeDoubleTests, ValueZeroStepExceptionTest) {
    bool thrown = false;
    try {
        range(0., 10., 0.);
    } catch (const std::invalid_argument& e) {
        thrown = true;
        EXPECT_EQ(std::string{"Range step argument must not be zero"},
                  std::string{e.what()});
    }
    EXPECT_TRUE(thrown);
}

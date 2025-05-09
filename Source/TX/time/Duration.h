#pragma once
#include "TX/time/Clock.h"

namespace TX::time {
class Duration final {
public:
  explicit Duration(int64_t n) : inner(n) {}
  static Duration Second(int n) { return Duration(n * 1'000'000'000); }
  static Duration Minute(int n) { return Duration(n * 1'000'000'000 * 60); }
  static Duration Hour(int n) { return Duration(n * 1'000'000'000 * 60 * 60); }

  [[nodiscard]] int64_t NanoSeconds() const { return inner; }
  [[nodiscard]] int64_t MicroSeconds() const { return inner / 1'000; }
  [[nodiscard]] int64_t MilliSeconds() const { return inner / 1'000'000; }

  [[nodiscard]] double Seconds() const {
    int64_t sec = inner / 1'000'000'000;
    int64_t nsec = inner % 1'000'000'000;
    return static_cast<double>(sec) + static_cast<double>(nsec) / 1e9;
  }
  [[nodiscard]] double Minutes() const {
    int64_t min = inner / (60 * 1'000'000'000LL);
    int64_t nsec = inner % (60 * 1'000'000'000LL);
    return static_cast<double>(min) + static_cast<double>(nsec) / (60 * 1e9);
  }
  [[nodiscard]] double Hours() const {
    int64_t hour = inner / (60 * 60 * 1'000'000'000LL);
    int64_t nsec = inner % (60 * 60 * 1'000'000'000LL);
    return static_cast<double>(hour) +
           static_cast<double>(nsec) / (60 * 60 * 1e9);
  }

  [[nodiscard]] Duration Truncate(Duration m) const {
    return Duration(m.inner <= 0 ? inner : (inner - inner % m.inner));
  }

  Duration operator+(Duration &other) const {
    return Duration(inner + other.inner);
  }
  Duration operator-(Duration &other) const {
    return Duration(inner - other.inner);
  }
  Duration operator*(Duration &other) const {
    return Duration(inner * other.inner);
  }
  Duration operator/(Duration &other) const {
    return Duration(inner / other.inner);
  }
  Duration operator%(Duration &other) const {
    return Duration(inner % other.inner);
  }

  [[nodiscard]] Clock::TimePoint TimePoint() const {
    Clock::TimePoint tp{};
    int64_t sec = inner / 1'000'000'000LL;
    int64_t nsec = inner % 1'000'000'000LL;
    tp.sec = sec;
    tp.nsec = nsec;
    return tp;
  }

private:
  friend class Time;
  int64_t inner;
};

}; // namespace TX::time
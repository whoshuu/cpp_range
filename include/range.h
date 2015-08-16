#ifndef WHOSHUU_Range_H
#define WHOSHUU_Range_H

#include <exception>


namespace whoshuu {
namespace detail {

template <typename T>
class Range {
  public:
    Range(const T& start, const T& stop, const T& step) : start_{start}, stop_{stop}, step_{step} {
        if (step_ == 0) {
            throw std::invalid_argument("Range step argument must not be zero");
        } else {
            auto difference = stop_ - start_;
            if ((difference < 0 && step_ > 0) || (difference > 0 && step_ < 0)) {
                throw std::invalid_argument("Range arguments must result in termination");
            }
        }
    }
    
    class iterator {
      public:
        typedef std::forward_iterator_tag iterator_category;
        typedef T value_type;
        typedef T& reference;
        typedef T* pointer;

        iterator(value_type value, value_type step) : value_{value}, step_{step} {}
        iterator operator++() { value_ += step_; return *this; }
        reference operator*() { return value_; }
        const pointer operator->() { return &value_; }
        bool operator==(const iterator& rhs) { return step_ > 0 ? value_ >= rhs.value_
                                                                : value_ <= rhs.value_; }
        bool operator!=(const iterator& rhs) { return step_ > 0 ? value_ < rhs.value_
                                                                : value_ > rhs.value_; }
        
      private:
        const T step_;
        value_type value_;
    };
    
    iterator begin() const {
        return iterator(start_, step_);
    }
    
    iterator end() const {
        return iterator(stop_, step_);
    }
  
  private:
    const T start_;
    const T stop_;
    const T step_;
};

} // namespace detail

template <typename T>
detail::Range<T> range(const T& stop) {
    return detail::Range<T>(T{0}, stop, T{1});
}

template <typename T>
detail::Range<T> range(const T& start, const T& stop) {
    return detail::Range<T>(start, stop, T{1});
}

template <typename T>
detail::Range<T> range(const T& start, const T& stop, const T& step) {
    return detail::Range<T>(start, stop, step);
}

} // namespace whoshuu

#endif /* WHOSHUU_Range_H */

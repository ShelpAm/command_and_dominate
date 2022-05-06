#ifndef SMALL_UTILITY_REFERENCE_COUNTING_REFERENCE_COUNTED_POINTER_H_     
#define SMALL_UTILITY_REFERENCE_COUNTING_REFERENCE_COUNTED_POINTER_H_

#include "small_utility/reference_counting/reference_holder.h"

namespace small_utility {

namespace reference_counting {

template<typename T>
class ReferenceCountedPointer {
 public:
  // Constructors
  ReferenceCountedPointer(ReferenceCountedPointer<T> const &rhs);
  ReferenceCountedPointer(
      ReferenceHolder<T>const *const reference_holder_pointer);
  ReferenceCountedPointer(T *const T_pointer);
  // Assignment operators
  ReferenceCountedPointer<T> &operator=(ReferenceCountedPointer<T> const &rhs);
  ReferenceCountedPointer &operator=(
      ReferenceHolder<T> const *const reference_holder_pointer);
  ReferenceCountedPointer<T> &operator=(T *const T_pointer);
  // Destructor
  ~ReferenceCountedPointer();
  // Other operators
  T *const operator->() { return reference_holder_pointer_->reference; }

  ReferenceHolder<T> const *const ReferenceHolderPointer() const {
    return reference_holder_pointer_;
  }

 private:
  ReferenceHolder<T> *reference_holder_pointer_;
};

template<typename T>
ReferenceCountedPointer<T>::ReferenceCountedPointer(
    ReferenceCountedPointer<T> const &rhs) {
  ReferenceCountedPointer<T> temp(rhs->ReferenceHolderPointer());
  Swap(temp);
}

template<typename T>
ReferenceCountedPointer<T>::ReferenceCountedPointer(
    ReferenceHolder<T> const *const reference_holder_pointer)
    : reference_holder_pointer_(reference_holder_pointer) {
  ++reference_holder_pointer_->count;
}

template<typename T>
ReferenceCountedPointer<T>::ReferenceCountedPointer(T *const T_pointer)
    : reference_holder_pointer_(new ReferenceHolder<T>) {
  reference_holder_pointer_->reference = T_pointer;
  reference_holder_pointer_->count = 1;
}

template<typename T>
ReferenceCountedPointer<T> &ReferenceCountedPointer<T>::operator=(
    ReferenceCountedPointer<T> const &rhs) {
  ReferenceCountedPointer<T> temp(rhs->ReferenceHolder());
  Swap(temp);
}

template<typename T>
ReferenceCountedPointer<T> &ReferenceCountedPointer<T>::operator=(
    ReferenceHolder<T> const *const reference_holder_pointer) {
  ReferenceCountedPointer<T> temp(reference_holder_pointer);
  Swap(temp);
}

template<typename T>
ReferenceCountedPointer<T> &ReferenceCountedPointer<T>::operator=(
    T *const T_pointer) {
  ReferenceCountedPointer<T> temp(T_pointer);
  Swap(temp);
}

template<typename T>
ReferenceCountedPointer<T>::~ReferenceCountedPointer() {
  --reference_holder_pointer_->count;
  if (!reference_holder_pointer_->count) {
    delete reference_holder_pointer_;
  }
}

} // namespace reference_counting

} // namespace small_utility

#endif // !SMALL_UTILITY_REFERENCE_COUNTING_REFERENCE_COUNTED_POINTER_H_

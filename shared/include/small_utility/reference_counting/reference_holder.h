#ifndef SMALL_UTILITY_REFERENCE_COUNTING_REFERENCE_HOLDER_H_
#define SMALL_UTILITY_REFERENCE_COUNTING_REFERENCE_HOLDER_H_

namespace small_utility {

namespace reference_counting {

template<typename type>
class ReferenceHolder {
 public:
  type *reference;
  int count;
};

} // namespace reference_counting

} // namespace small_utility

#endif // !SMALL_UTILITY_REFERENCE_COUNTING_REFERENCE_HOLDER_H_

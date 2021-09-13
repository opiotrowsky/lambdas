#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

// use STL algorithm to check if all elements are divisible by 3
// implement 3 versions:
// * lambda
// * functor
// * function

class Modulo3 {
public:
    bool operator() (int num) {
        return num % 3 == 0;
    }
};

bool DivisibleBy3(int num) {
    return num % 3 == 0;
}

int main() {
    std::vector<int> numbers = {18, 21, 36, 90, 27, 14, 103};
    std::vector<int> nums1, nums2, nums3;

    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(nums1), [](int x){ return x % 3 == 0; });
    std::copy(nums1.begin(), nums1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(nums2), Modulo3());
    std::copy(nums2.begin(), nums2.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(nums3), DivisibleBy3);
    std::copy(nums3.begin(), nums3.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    return 0;
}

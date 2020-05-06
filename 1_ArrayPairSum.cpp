/**
Given an integer array, output all pairs that sum up to a specific value k.
*/

#include <iostream>
#include <numeric>
#include <vector>
#include <set>

template<typename T, typename S,
         typename = std::enable_if_t<std::is_integral_v<T> && std::is_integral_v<S>>>
auto validPairSum(const std::vector<T> &input, const S sumValue) {

    std::vector<std::pair<T,T>> result;

    if(input.size() > 2 && sumValue > 0) {

        std::set<T> seen;

        for(const auto & number : input) {
            
            auto target = sumValue - number;

            if(seen.find(target) == seen.end()) {
                seen.insert(number);    
            }
            else {
                result.emplace_back(target,number);
            }
        }
    }

    return result;
}

int main() {  

    // First test: for k = 5, resulting pairs should be [2,3] and [1,4]
    {
        std::vector<int> testVector(10);
        std:iota(testVector.begin(), testVector.end(), 1);
        const int k{5};
        const auto resultingPairs{validPairSum(testVector, k)};

        bool testPassed{false};
        std::cout << "Resulting Pairs: ";
        for(const auto &pair : resultingPairs) {

            std::cout << "[" << pair.first << "," << pair.second << "]";
            if(pair.first + pair.second == k) {
                testPassed = true;
            }
            else {
                testPassed = false;
            }
        }

        std::string testResult{testPassed ? "Passed" : "Failed"};
        std::cout << "\nTest " << testResult; 
    }

    return 0;
}

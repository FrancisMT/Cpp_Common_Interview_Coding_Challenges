/**
Given a non-empty array of integers, every element appears twice except for one. Find that single one.
*/

#include <set>
#include <vector>
#include <iostream>

int findNumber(const std::vector<int>& inVector) {

    std::multiset<int> uniqueNumbers{inVector.begin(), inVector.end()};

    int result{};
    for(const auto number : inVector) {

        if(uniqueNumbers.count(number) == 1) {
            result = number;
            break;
        }
    }

    return result;
}

int main() {
    const auto result{findNumber({1,1,2,2,3,3,4})};
    std::cout << "Expected Result is 4: " << result << '\n';

    return 0;
}
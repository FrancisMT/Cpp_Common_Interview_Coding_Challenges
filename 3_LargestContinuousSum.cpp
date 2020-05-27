/**
Given an array of integers (positive and negative) find the largest continuous sum.
*/

#include <iostream>
#include <vector>

int32_t LargestContinuousSum(const std::vector<int>& integerArray) {

    if(integerArray.size() == 0) {
        return 0;
    }

    int32_t largestSum{0};
    int32_t currentSum{0};

    const auto updateResult = [&largestSum, &currentSum](){
        if(currentSum > largestSum) {
            largestSum = currentSum;
            currentSum = 0;
        }};

    for(const auto integer : integerArray) {
        int32_t temp = currentSum + integer;

        if(temp > currentSum) {
            currentSum = temp;

            // Corner case where we are at the last element of the array
            if(integer == integerArray.back()) {
                updateResult();
            }
        }
        else{
            updateResult();
        }
    }

    return largestSum;
}

int main() {
    
    {
        const std::vector<int> testArray{1,-2,5,-1,2};
        std::cout << "Expected Result: 5" << '\n' << "Actual Result: " << LargestContinuousSum(testArray) << '\n';
    }
    {
        const std::vector<int> testArray{5, -1, -2, 3, -2};
        std::cout << "Expected Result: 5" << '\n' << "Actual Result: " << LargestContinuousSum(testArray) << '\n';
    }
    {
        const std::vector<int> testArray{ 5, 7, -13, 10, 5 };
        std::cout << "Expected Result: 15" << '\n' << "Actual Result: " << LargestContinuousSum(testArray) << '\n';
    }
    {
        const std::vector<int> testArray{0};
        std::cout << "Expected Result: 0" << '\n' << "Actual Result: " << LargestContinuousSum(testArray) << '\n';
    }
    {
        const std::vector<int> testArray{999999999};
        std::cout << "Expected Result: 999999999" << '\n' << "Actual Result: " << LargestContinuousSum(testArray) << '\n';
    }
    {
        const std::vector<int> testArray{-40,1,40,-50,1,50,-20,1,20,0,0};
        std::cout << "Expected Result: 51" << '\n' << "Actual Result: " << LargestContinuousSum(testArray) << '\n';
    }
    {
        const std::vector<int> testArray{2,-2,5,-5,6,-6};
        std::cout << "Expected Result: 6" << '\n' << "Actual Result: " << LargestContinuousSum(testArray) << '\n';
    }
    {
        const std::vector<int> testArray{1,-2,5,-1,6};
        std::cout << "Expected Result: 6" << '\n' << "Actual Result: " << LargestContinuousSum(testArray) << '\n';
    }

    return 0;
}
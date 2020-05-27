/**
There is an array of non-negative integers.
A second array is formed by shuffling the elements of the first array and deleting a random element.
Given these two arrays, find which element is missing in the second array.
*/

#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

#define ALTERNATIVESOLVE 1

uint32_t findDeletedElement(const std::vector<uint32_t> &ogVector, const std::vector<uint32_t> &shuffledVector)
{

#if ALTERNATIVESOLVE

    std::map<uint32_t, int> elementMap;
    for (const auto &shuffledElement : shuffledVector)
    {
        ++elementMap[shuffledElement];
    }

    for (const auto &ogElement : ogVector)
    {
        if (--elementMap[ogElement] != 0)
        {
            return ogElement;
        }
    }

    return 0;

#else

    uint32_t res{0};
    for (const auto e : ogVector)
    {
        res = res ^ e;
    }
    for (const auto e : shuffledVector)
    {
        res = res ^ e;
    }

    // An XOR of all the elements of an array will always return that which has no pair.
    return res;
#endif
}

int main()
{

    {
        const std::vector<uint32_t> originalVector{1, 2, 3, 4, 5, 6};
        const std::vector<uint32_t> shuffledVector{2, 1, 3, 6, 4};
        std::cout << "Expected value is 5. Got: " << findDeletedElement(originalVector, shuffledVector) << '\n';
    }
    {
        const std::vector<uint32_t> originalVector{1, 2, 1, 1};
        const std::vector<uint32_t> shuffledVector{2, 1, 1};
        std::cout << "Expected value is 1. Got: " << findDeletedElement(originalVector, shuffledVector) << '\n';
    }

    return 0;
}
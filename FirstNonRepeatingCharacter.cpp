/**
Given a string, find the first non-repeating character in it and return it's index.
If it doesn't exist, return -1.

Examples:
s = "leetcode"
return 0.


s = "loveleetcode",
return 2.
*/

#include <set>
#include <utility>
#include <iostream>
#include <algorithm>

int findIndex(const std::string& inString) {

    std::set<std::pair<char, int>> seenChars;

    for(int i = 0; i < inString.size(); ++i) {

        auto findResult = std::find_if(seenChars.begin(), seenChars.end(), [character = inString[i]](const std::pair<char,int>& currentPair ){
            return currentPair.first == character;
        });

        if(findResult == seenChars.end()){
            seenChars.insert({inString[i], i});
        }
        else {
            seenChars.erase(findResult);
        }
    }

    auto result = std::min_element(seenChars.begin(), seenChars.end(), [](std::pair<char, int> a, std::pair<char, int> b){
        return a.second < b.second;
    });

    return result == seenChars.end() ? -1 : result->second;
}


int main() {

    {
        const auto result{findIndex("")};
        std::cout << "Expected Result is -1: " << result << '\n';
    }
    {
        const auto result{findIndex("leetcode")};
        std::cout << "Expected Result is 0: " << result << '\n';
    }
    {
        const auto result{findIndex("loveleetcode")};
        std::cout << "Expected Result is 2: " << result << '\n';
    }

    return 0;
}

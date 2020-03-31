/**
We are given 3 strings: str1, str2, and str3. Str3 is said to be a shuffle of 
str1 and str2 if it can be formed by interleaving the characters of str1 and 
str2 in a way that maintains the left to right ordering of the characters from 
each string. For example, given str1="abc" and str2="def", str3="dabecf" is a 
valid shuffle since it preserves the character ordering of the two strings. 
So, given these 3 strings write a function that detects whether str3 is a valid 
shuffle of str1 and str2.
Assume there is no repeated characters between str1 and str2 and inside the strings.
*/

#include <iostream>

bool checkShuffle(const std::string & stringA, const std::string & stringB, const std::string & shuffledString) {
    
  // Size check
  if(stringA.size() + stringB.size() != shuffledString.size()) {
    return false;
  }
  
  // Perfect concatenation check
  if((stringA + stringB) == shuffledString) {
    return true;
  }

  // Check if both strA and strB characters exist in strS (in the correct order) 
  {
    uint32_t indexA = 0;
    uint32_t indexB = 0;
  
    for(size_t index = 0; index < shuffledString.size(); ++index) {

      if(indexA < stringA.size() && shuffledString[index] == stringA[indexA]) {
        ++indexA;
      }
      else if(indexB < stringB.size() && shuffledString[index] == stringB[indexB]) {
        ++indexB;
      }
      else {      
        return false;        
      }
    }
  }
  return true;
}

int main() {
  
  // Test case 1
  std::string 
    strA("abcs"),
    strB("edf"),
    strSA("dabecf");
  
  const auto outputLambda = [&]() -> std::string {
    return (checkShuffle(strA, strB, strSA) ? "passed" : "failed");
  };
  
  std::cout << "Expected to fail: " << outputLambda() << "\n";  

  // Test case 2
  strA.clear();
  strA = "abc";
  strB.clear();
  strB = "edf";
  strSA.clear();
  strSA = "abcedf";
  
  std::cout << "Expected to pass: " << outputLambda() << "\n";  

  // Test case 3
  strA.clear();
  strA = "abc";
  strB.clear();
  strB = "def";
  strSA.clear();
  strSA = "dabecf";
  
  std::cout << "Expected to pass: " << outputLambda() << "\n";  

  // Test case 4
  strA.clear();
  strA = "abc";
  strB.clear();
  strB = "def";
  strSA.clear();
  strSA = "dabfce";
  
  std::cout << "Expected to fail: " << outputLambda() << "\n";  

  return 0;
}

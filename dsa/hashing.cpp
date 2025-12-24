#include <bits/stdc++.h>

/*
*Let’s first try to understand the importance of hashing using an example:

Given an array of integers: [1, 2, 1, 3, 2] and we are given some queries: [1,
3, 4, 2, 10]. For each query, we need to find out how many times the number
appears in the array. For example, if the query is 1 our answer would be 2, and
if the query is 4 the answer will be 0.

Similarly, the following will be the answers to the given queries:
* */

int main() {
  int freqOf = 1;
  int max = 12;
  int arr[10] = {1, 2, 3, 3, 3, 3, 8, 9, 10, 3};
  int hashArr[max];
  for (int i = 0; i < 10; i++) {
    hashArr[arr[i]]++;
  }
  std::cout << "Freq of " << freqOf << ": " << hashArr[freqOf] << std::endl;
  return 0;
}

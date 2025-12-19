#include <bits/stdc++.h>
#include <iostream>
#include <utility>

using namespace std;

void printFrom1(int n) {
  if (n == 1) {
    cout << n << endl;
    return;
  }

  printFrom1(n - 1);
  cout << n << endl;
}

void printFromN(int n) {

  cout << n << endl;
  if (n == 1) {
    return;
  }

  printFromN(n - 1);
}

int factorial(int n) {
  if (n == 1) {
    return 1;
  }
  return n * factorial(n - 1);
}

void reverseAnArray(int arr[], int start, int end) {
  if (start == end or end < start) {
    return;
  }
  swap(arr[start], arr[end]);
  start++;
  end--;
  reverseAnArray(arr, start, end);
};

void palindromeCheck(string s, int start, int end) {
  if (start == end || start > end) {
    cout << " It is palindrome ! \n";
    return;
  }
  if (s[start] != s[end]) {
    cout << " It is not palindrome ! \n";
    return;
  }
  start++;
  end--;
  palindromeCheck(s, start, end);
}

int fibo(int N) {
  // Base case: if N is 0 or 1, return N itself
  if (N <= 1) {
    return N;
  }

  // Recursive case: sum of (N-1)th and (N-2)th Fibonacci numbers
  int last = fibo(N - 1);  // (N-1)th Fibonacci
  int slast = fibo(N - 2); // (N-2)th Fibonacci

  return last + slast;
}

int main() {
  int n = 5;
  string s = "ni";
  cout << fibo(n);
  return 0;
}

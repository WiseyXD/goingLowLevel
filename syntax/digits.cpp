#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int countDigits(int n) {
  int ans = 0;
  while (n > 0) {
    n /= 10;
    ans++;
  }

  return ans;
}

int reverseNumber(int n) {
  int ans = 0;
  int numberOfDigits = countDigits(n);
  while (n > 0 && numberOfDigits > 0) {
    int lastDigit = n % 10;
    ans = ans * 10 + lastDigit;
    n /= 10;
    numberOfDigits--;
  }

  /* 123 -> 321    */
  return ans;
}

int main() {
  int ans;
  int n = 123123;
  ans = reverseNumber(n);
  cout << ans << endl;
  return ans;
}

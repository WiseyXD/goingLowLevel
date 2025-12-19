#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
  // Brute force
  pair<int, int> input = {40, 5};

  int min = input.first > input.second ? input.second : input.first;
  int max = input.first < input.second ? input.second : input.first;

  // for (int i = min; i > 0; i--) {
  //   if (min % i == 0 && max % i == 0) {
  //     cout << "ans is : " << i << endl;
  //     return 0;
  //   }
  // }

  int a = min;
  int b = max;

  // euclidian algo -> gcd(max%min , min) -> gcd(0,ans (this value is the GCD))
  // and O(phie of n)
  while (a != 0 && b != 0) {
    if (a > b) {
      a = a % b;
    } else {
      b = b % a;
    }
  }
  if (a == 0) {
    cout << "ans is : " << b << endl;
  } else {

    cout << "ans is : " << a << endl;
  }

  return 0;
}

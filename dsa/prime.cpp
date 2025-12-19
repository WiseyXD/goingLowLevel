#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main() {
  int n = 523;

  int counter = 0;

  for (int i = 1; i <= n; i++) {
    if (counter > 2) {
      cout << "Is not prime !" << endl;
      return 0;
    }
    if (n % i == 0) {
      counter++;
    }
  }
  if (counter == 2) {
    cout << "Is prime" << endl;
    return 0;

  } else {
    cout << "Is not prime" << endl;
    return 0;
  }
}

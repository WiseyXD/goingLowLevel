#include <iostream>
using namespace std;

class Smartphone {
public:
  virtual void clickSelfie() = 0;
  virtual void call() = 0;
};

class Android : public Smartphone {
public:
  void clickSelfie() { cout << "Android selfie clicked \n"; }
  void call() { cout << "called from Android \n"; }
};

class IPhone : public Smartphone {
public:
  void clickSelfie() { cout << "IPhone click selfie \n"; }
  void call() { cout << "called from IPhone \n"; }
};

int main() {
  Smartphone *phone1 = new Android();
  IPhone phone2;

  phone1->clickSelfie();
  phone1->call();

  phone2.call();
  return 0;
}

#include <iostream>
using namespace std;

/*
Abstraction Example:

- Smartphone is an abstract class (cannot be instantiated).
- It defines "what" operations a smartphone must support (clickSelfie, call)
  without providing the internal implementation.
- Android and IPhone provide their own implementations for these functions.
- Main function interacts only with the abstract interface, not caring
  about how each phone performs the actions.
*/

class Smartphone {
public:
  // Pure virtual functions → forces derived classes to implement them
  virtual void clickSelfie() = 0;
  virtual void call() = 0;
};

class Android : public Smartphone {
public:
  // Android-specific implementation of abstract methods
  void clickSelfie() { cout << "Android selfie clicked \n"; }
  void call() { cout << "called from Android \n"; }
};

class IPhone : public Smartphone {
public:
  // iPhone-specific implementation of abstract methods
  void clickSelfie() { cout << "IPhone click selfie \n"; }
  void call() { cout << "called from IPhone \n"; }
};

int main() {
  // Using abstraction: interacting via base class pointer
  Smartphone *phone1 = new Android();

  // Object of derived class directly
  IPhone phone2;

  phone1->clickSelfie();
  phone1->call();

  phone2.call();

  return 0;
}

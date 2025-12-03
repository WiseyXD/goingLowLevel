#include <iostream>
using namespace std;

/*
Abstraction Example:

- Smartphone is an abstract base class with pure virtual functions.
  It only specifies *what* operations a smartphone must perform
  (clickSelfie, call) — not *how* they are implemented.

- Android and IPhone provide their own implementations of these
  abstract operations.

- In main(), we use a base-class pointer (Smartphone*) to interact with
  different smartphone types without knowing the internal details.
  This demonstrates abstraction + polymorphism.

- A virtual destructor is added to ensure proper cleanup when deleting
  derived objects through a base-class pointer.
*/

class Smartphone {
public:
  // Virtual destructor → ensures correct destructor runs when deleting via base
  // pointer
  virtual ~Smartphone() {}

  // Pure virtual functions → must be implemented by derived classes
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
  // Allocated dynamically → requires delete later
  Smartphone *phone1 = new Android();

  // Stack object → no delete needed
  IPhone phone2;

  // Using the abstract interface
  phone1->clickSelfie();
  phone1->call();

  phone2.call();

  // Proper cleanup of dynamically allocated object
  delete phone1;

  return 0;
}

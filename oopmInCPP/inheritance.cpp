#include <iostream>
using namespace std;

/*
Inheritance Example:

- Employee is the base class holding common attributes (Name, Role, Age)
  and common behavior (askForRaise).

- Developer and Teacher inherit from Employee and reuse its properties
  and methods.

- Each derived class adds its own behavior:
    Developer → fixingBugs()
    Teacher   → teaching()

- Constructors of derived classes call the base class constructor
  to initialize shared data (Name, Role, Age).
*/

class Employee {
private:
  string Name;
  string Role;
  int Age;

public:
  // Base class constructor initializes shared fields
  Employee(string name, string role, int age) {
    Name = name;
    Role = role;
    Age = age;
  }

  string getName() { return Name; }
  void setName(string name) { Name = name; }

  // Common functionality available to all employees
  void askForRaise() {
    if (Age > 21) {
      cout << Name << " is Promoted!" << endl;
    } else {
      cout << Name << " no promotion for you" << endl;
    }
  }
};

class Developer : public Employee {
private:
  string FavProgrammingLang;

public:
  // Derived class constructor calls base class constructor
  Developer(string name, string role, int age, string favProgrammingLang)
      : Employee(name, role, age) {
    FavProgrammingLang = favProgrammingLang;
  }

  // Developer-specific behavior
  void fixingBugs() { cout << getName() << " is fixing bugs!" << endl; }
};

class Teacher : public Employee {
private:
  string FavSubject;

public:
  // Derived class constructor calls base class constructor
  Teacher(string name, string role, int age, string favSubject)
      : Employee(name, role, age) {
    FavSubject = favSubject;
  }

  // Teacher-specific behavior
  void teaching() {
    cout << getName() << " is teaching " << FavSubject << endl;
  }
};

int main() {
  // Creating derived class objects
  Developer d("Aryan", "Fullstack Developer", 22, "JS");
  d.fixingBugs();

  Teacher t("Harshi", "Professor", 21, "Maths");
  t.teaching();

  // Reusing base class functionality
  t.askForRaise();
  d.askForRaise();

  return 0;
}

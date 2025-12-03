#include <iostream>

using namespace std;

/*
Polymorphism Example:

- The base class Employee defines a virtual method work().
  This allows derived classes to override it with their own behavior.

- When using pointers or references to the base class (Employee*),
  C++ determines at runtime which version of work() to call:
      Developer::work()
      Teacher::work()
      Employee::work()

- This is called Runtime Polymorphism (Dynamic Dispatch).

- Important:
    Employee d = Developer(...)   // ❌ causes object slicing
    Employee t = Teacher(...)     // Derived parts are lost

  But:
    Employee* e1 = new Developer(...)  // ✔ dynamic binding preserved
    Employee* e2 = new Teacher(...)

  Using pointers avoids slicing and enables true polymorphism.
*/

class Employee {
private:
  string Name;
  string Role;
  int Age;

public:
  Employee(string name, string role, int age) {
    Name = name;
    Role = role;
    Age = age;
  }

  string getName() { return Name; }
  void setName(string name) { Name = name; }

  void askForRaise() {
    if (Age > 21) {
      cout << Name << " is Promoted!" << endl;
    } else {
      cout << Name << " no promotion for you" << endl;
    }
  }

  // Virtual function → enables polymorphism
  virtual void work() { cout << Name << " is checking some emails." << endl; }
};

class Developer : public Employee {
private:
  string FavProgrammingLang;

public:
  Developer(string name, string role, int age, string favProgrammingLang)
      : Employee(name, role, age) {
    FavProgrammingLang = favProgrammingLang;
  }

  void fixingBugs() { cout << getName() << " is fixing bugs!" << endl; }

  // Overridden function → Developer-specific behavior
  void work() { cout << getName() << " is coding a new project." << endl; }
};

class Teacher : public Employee {
private:
  string FavSubject;

public:
  Teacher(string name, string role, int age, string favSubject)
      : Employee(name, role, age) {
    FavSubject = favSubject;
  }

  void teaching() {
    cout << getName() << " is teaching " << FavSubject << endl;
  }

  // Overridden function → Teacher-specific behavior
  void work() {
    cout << getName() << " is checking some notes of her students." << endl;
  }
};

int main() {
  // ❌ Sliced objects: treated as Employee only (not polymorphic)
  Employee d = Developer("Aryan", "Fullstack Developer", 22, "JS");
  Employee t = Teacher("Harshi", "Professor", 21, "Maths");

  // ✔ True polymorphism using base class pointers
  Employee *e1 = new Developer("Aryan", "Fullstack Developer", 22, "JS");
  Employee *e2 = new Teacher("Harshi", "Professor", 21, "Maths");

  e2->work(); // Calls Teacher::work()
  e1->work(); // Calls Developer::work()

  return 0;
}

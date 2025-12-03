#include <iostream>
using namespace std;

class Employee {
private:
  string Name;
  string Role;
  int Age;

public:
  Employee(string name, string role, int age) {
    Name = name;
    Age = age;
    Role = role;
  }
  string getName() { return Name; };
  void setName(string name) { Name = name; };
  void askForRaise() {
    if (Age > 21) {
      cout << Name << " is Promoted!" << endl;
    } else {
      cout << Name << " no promotion for you" << endl;
    }
  };
};

class Developer : public Employee {
private:
  string FavProgrammingLang;

public:
  Developer(string name, string role, int age, string favProgrammingLang)
      : Employee(name, role, age) {
    FavProgrammingLang = favProgrammingLang;
  }
  void fixingBugs() { cout << getName() << " is fixing bugs!" << endl; };
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
  };
};

int main() {
  Developer d = Developer("Aryan", "Fullstack Developer", 22, "JS");
  d.fixingBugs();
  Teacher t = Teacher("Harshi", "Professor", 21, "Maths");
  t.teaching();
  t.askForRaise();
  d.askForRaise();
  return 0;
}

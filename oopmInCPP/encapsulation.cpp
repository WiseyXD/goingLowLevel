#include <iostream>
using namespace std;

/*
Encapsulation means:

- Keep data private → You made Name, Age, and Course private.
- Control access through public methods → You exposed getters and setters for
controlled access.
*/

class Student {
private:
  string Name;
  int Age;
  string Course;

public:
  void setAge(int age) { Age = age; };
  int getAge() { return Age; };
  void setName(string name) { Name = name; };
  string getName() { return Name; };
  void setCourse(string course) { Course = course; };
  string getCourse() { return Course; };
};

int main() {
  Student student;
  student.setAge(12);
  student.setName("Aryna");
  student.setCourse("CS");

  cout << student.getCourse() << endl;
  cout << student.getAge() << endl;
  cout << student.getName();

  return 0;
}

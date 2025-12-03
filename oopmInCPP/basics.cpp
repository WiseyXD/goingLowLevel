#include <iostream>

using namespace std;

class Employee {
private:
  int Age;
  string Name;
  string Address;
  int WorkEx;

public:
  Employee(string name, int age, string address, int workEx) {
    Age = age;
    Name = name;
    Address = address;
  }

  void introduceYourself() {
    cout << "Name : " << Name << endl;
    cout << "Age : " << Age << endl;
    cout << "Work Experience: " << WorkEx << endl;
  }
};

int main() {
  Employee emp1 = Employee("Aryan", 22, "Dresden", 1);
  emp1.introduceYourself();
  return 0;
}

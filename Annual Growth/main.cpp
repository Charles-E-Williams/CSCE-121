#include <iostream>
#include <string>
using namespace std;

int main() {

  string firstName, lastName;
  int birthYear,feet,inches;


  cin >> firstName >> lastName;
  cin >> birthYear >> feet >> inches;

//output user information
  cout << "First name: " << firstName << endl;
  cout << "Last name: " << lastName << endl;
  cout << "Birth year: " << birthYear << endl;
  cout << "Height in feet (do not include inches): " << feet << endl;
  cout << "Height in inches (do not include feet): " << inches << endl;

// output data interpretation

  int age = 2020 - birthYear;
  double centi = (feet*12 + inches) * 2.54;
  double average = (centi - 51) / age;

  cout << "Hello " << firstName << " " << lastName << ".\n";
  cout << "You are " << age << " years old in 2020.\n";
  cout << "Your height is " << centi << " cm.\n";
  cout << "You grew an average of " << average << " cm per year (assuming you were 51 cm at birth).\n";

  return 0;


}

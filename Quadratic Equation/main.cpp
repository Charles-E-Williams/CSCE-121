#include <iostream>
#include <cmath>
using namespace std;


int main() {

  double a, b, c;
  cin >> a >> b >> c;

  if (a == 0 && b == 0 && c == 0) {
    cout << a << "x^2 + " << b << "x " << "+ " << c << " = 0" << endl;
    cout << "Unable to determine root(s).\n";
    return 0;
  }
  else if (a == 0 && b == 0) {
    if (c > 0) {
      cout << a << "x^2 + " << b << "x " << "+ " << c << " = 0" << endl;
      }

    else if (c < 0) {
      cout << a << "x^2 + " << b << "x " << "- " << fabs(c) << " = 0" << endl;
    }
    cout << "Unable to determine root(s).\n";
    return 0;
  }

  else if (a == 0 && (b > 0 || b < 0) && (c < 0 || c > 0)) {
    if (c > 0 && b > 0) {
      cout << a << "x^2 + " << b << "x " << "+ " << c << " = 0" << endl;
      }

    else if (c < 0 && b > 0) {
      cout << a << "x^2 + " << b << "x " << "- " << fabs(c) << " = 0" << endl;
    }

    else if (c < 0 && b < 0) {
      if (c > 0) {
        cout << a << "x^2 - " << b << "x " << "- " << c << " = 0" << endl;
        }

      else if (c < 0) {
        cout << a << "x^2 + " << b << "x " << "- " << fabs(c) << " = 0" << endl;
      }
    }

    cout << "x = " << -(c/b) << endl;
    return 0;
  }

  /* output the quadratic equation for the user to see. */
  if (a > 0 && b > 0 && c > 0) {
    cout << a << "x^2 + " << b << "x " << "+ " << c << " = 0" << endl;
  }

  else if (a < 0 && b > 0 && c > 0) {
    cout << "-" << fabs(a) << "x^2 + " << b << "x " << "+ " << c << " = 0" << endl;

  }

  else if (b < 0  && a > 0 && c > 0) {
    cout << a << "x^2 - " << fabs(b) << "x " << "+ " << c << " = 0" << endl;

  }

  else if (c < 0  && a > 0 && b > 0) {
    cout << a << "x^2 + " << b << "x " << "- " << fabs(c) << " = 0" << endl;

  }

  else if (a < 0 && b < 0 && c > 0 ) {
    cout << "-" << fabs(a) << "x^2 - " << fabs(b) << "x " << "+ " << c << " = 0" << endl;

  }

  else if (a < 0 && c < 0 && b > 0) {
    cout << "-" << fabs(a) << "x^2 + " << b << "x " << "- " << fabs(c) << " = 0" << endl;

  }

  else if (b < 0 && c < 0 && a > 0) {
    cout << a << "x^2 - " << fabs(b) << "x " << "- " << fabs(c) << " = 0" << endl;

  }

  else if (a < 0 && c < 0 && b < 0) {
    cout << "-" << fabs(a) << "x^2 - " << fabs(b) << "x " << "- " << fabs(c) << " = 0" << endl;

  }

  double disc = pow(b,2) - 4*a*c;

  if (disc < 0) {

    if (a > 0 && (b > 0 || b < 0) && (c < 0 || c > 0)) {
    cout << "x = " << -b / (2*a) << " - " << sqrt(4*a*c - pow(b,2)) / fabs((2*a)) << + "i\n";
    cout << "x = " << -b / (2*a) << " + " << sqrt(4*a*c - pow(b,2)) / fabs((2*a)) << + "i\n";
      }


    if (a < 0 && (b > 0 || b < 0) && (c < 0 || c > 0)) {
      cout << "x = " << -b / (2*a) << " + " << sqrt(4*a*c - pow(b,2)) / fabs((2*a)) << + "i\n";
      cout << "x = " << -b / (2*a) << " - " << sqrt(4*a*c - pow(b,2)) / fabs((2*a)) << + "i\n";
      }

  }

  else if (disc == 0) {

    cout << "x = " << -b/(2*a) << endl;
  }

  else if (disc > 0) {

    double r1 = (-b + sqrt(disc))/(2*a);
    double r2 = (-b - sqrt(disc))/(2*a);

    cout << "x = " << r2 << endl;
    cout << "x = " << r1 << endl;
   }

  return 0;

}

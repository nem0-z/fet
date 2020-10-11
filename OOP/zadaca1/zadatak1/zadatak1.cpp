#include <cmath>
#include <iostream>
namespace temps {
const double cels2fahr = 1.8;
const double cels2kelv = 273.15;
const double fahr2kelv = 0.5555;
}  
namespace speed {
const double kmh2mph = 0.621;
}
namespace length {
const double inch2cm = 2.54;
const double feet2met = 0.305;
const long double ly2km = 9.461 * pow(10, 12);
}  
namespace weight {
const double kg2ft = 2.205;

}
namespace fuelEcon {
const double x = 282.481;
}
void menu(void) {
  std::cout << "Welcome to Unit converter. Please enter one of the following "
               "options: "
            << std::endl;
  std::cout << "1.Temperature" << std::endl;
  std::cout << "2. Speed" << std::endl;
  std::cout << "3. Length" << std::endl;
  std::cout << "4. Weight" << std::endl;
  std::cout << "5. Fuel economy" << std::endl;
}
void menu1(void) {
  std::cout << "Please choose converter: " << std::endl;
  std::cout << "1. Celsius to Fahrenheit" << std::endl;
  std::cout << "2. Fahrenheit to Celsius" << std::endl;
  std::cout << "3. Celsius to Kelvin" << std::endl;
  std::cout << "4. Kelvin to Celsius" << std::endl;
  std::cout << "5. Fahrehnheit to Kelvin" << std::endl;
  std::cout << "6. Kelvin to Fahrenheit" << std::endl;
}
void menu2(void) {
  std::cout << "Please choose converter: " << std::endl;
  std::cout << "1. Kilometers per hour to Miles per hour" << std::endl;
  std::cout << "2. Miles per hour to Kilometers per hour" << std::endl;
}
void menu3(void) {
  std::cout << "Please choose converter: " << std::endl;
  std::cout << "1. Light years to Kilometers" << std::endl;
  std::cout << "2. Kilometers to Light years" << std::endl;
  std::cout << "3. Inches to Centimeters" << std::endl;
  std::cout << "4. Centimeters to Inches" << std::endl;
      std::cout
            << "5. Feet to Meters" << std::endl;
  std::cout << "6. Meters to Feet" << std::endl;
}
void menu4(void) {
  std::cout << "Please choose converter: " << std::endl;
  std::cout << "1. Kilograms to Pounds" << std::endl;
  std::cout << "2. Pounds to Kilograms" << std::endl;
}
void menu5(void) {
  std::cout << "Please choose converter: " << std::endl;
  std::cout << "1. l/100km to mpg" << std::endl;
  std::cout << "2. mpg to l/100km" << std::endl;
}
double unos(void) {
  double a;
  std::cout << "Enter the value: " << std::endl;
  std::cin >> a;
  return a;
}
void ispis(double a) { std::cout << "Converted value is: " << a << std::endl; }
int main(int argc, char *argv[]) {
  auto opt = 0;
  menu();
  std::cin >> opt;
  if (opt == 1) {
    auto opt1 = 0;
    menu1();
    std::cin >> opt1;
    double temp = unos();
    if (opt1 == 1) {
      temp = temp * (temps::cels2fahr) + 32;
    }
    if (opt1 == 2) {
      temp = (temp - 32) * temps::fahr2kelv;
    }
    if (opt1 == 3) {
      temp += temps::cels2kelv;
    }
    if (opt1 == 4) {
      temp -= temps::cels2kelv;
    }
    if (opt1 == 5) {
      temp = (temp - 32) * temps::fahr2kelv + temps::cels2kelv;
    }
    if (opt1 == 6) {
      temp = (temp - temps::cels2kelv) * temps::cels2fahr + 32;
    }
    ispis(temp);
  } else if (opt == 2) {
    auto opt2 = 0;
    menu2();
    std::cin >> opt2;
    double speed = unos();
    if (opt2 == 1) {
      speed *= speed::kmh2mph;
    }
    if (opt2 == 2) {
      speed /= speed::kmh2mph;
    }
    ispis(speed);
  } else if (opt == 3) {
    auto opt3 = 0;
    menu3();
    std::cin >> opt3;
    double len = unos();
    if (opt3 == 1) {
      len *= length::ly2km;
    }
    if (opt3 == 2) {
      len /= length::ly2km;
    }
    if (opt3 == 3) {
      len *= length::inch2cm;
    }
    if (opt3 == 4) {
      len /= length::inch2cm;
    }
    if (opt3 == 5) {
      len *= length::feet2met;
    }
    if (opt3 == 6) {
      len /= length::feet2met;
    }
    ispis(len);
  } else if (opt == 4) {
    auto opt4 = 0;
    menu4();
    std::cin >> opt4;
    double weight = unos();
    if (opt4 == 1) {
      weight *= weight::kg2ft;
    }
    if (opt4 == 2) {
      weight /= weight::kg2ft;
    }
    ispis(weight);
  } else if (opt == 5) {
    auto opt5 = 0;
    menu5();
    std::cin >> opt5;
    double econ = unos();
    if (opt5 == 1) {
      econ = (fuelEcon::x) / econ;
    }
    if (opt5 == 2) {
      econ = (fuelEcon::x) / econ;
    }
    ispis(econ);
  }
  return 0;
}

#include <iostream>
#include <string>

class Vehicle {
  public:
  size_t age;
  double weight;
  double fuelCount;
  double mileage;
  std::string licensePlates;

  virtual double milesPerYr() const { return mileage / age; }
  virtual double weightPerWheel() = 0;

  std::istream& load(std::istream& in) {
    std::cout << "Enter age,weight,fuel,mileage and license plates:"
              << std::endl;
    in >> age >> weight >> fuelCount >> mileage >> licensePlates;
    return in;
  }
  friend std::ostream& output(std::ostream& out);

  virtual ~Vehicle() { std::cout << "Vehicle destroyed" << std::endl; }
};

class Car : public Vehicle {
  public:
  double* foo = new double[50];
  double weightPerWheel() override { return weight / 4; }
  Car() { std::cout << "Car constructed" << std::endl; }
  ~Car() {
    std::cout << "Car destructed" << std::endl;
    delete[] foo;
  }
};

class Bus : public Vehicle {
  public:
  double weightPerWheel() override { return weight / 12; }
  Bus() { std::cout << "Bus constructed" << std::endl; }
  ~Bus() { std::cout << "Bus destructed" << std::endl; }
};

class Truck : public Vehicle {
  public:
  double weightPerWheel() override { return weight / 8; }
  Truck() { std::cout << "Truck constructed" << std::endl; }
  ~Truck() { std::cout << "Truck destructed" << std::endl; }
};

std::ostream& output(std::ostream& out, Vehicle* vehicle) {
  out << "Age,weight,fuel,mileage and license plates:\n"
      << vehicle->age << std::endl
      << vehicle->weight << std::endl
      << vehicle->fuelCount << std::endl
      << vehicle->mileage << std::endl
      << vehicle->licensePlates << std::endl;
  return out;
}

int main(int argc, char* argv[]) {
  while (true) {
    Vehicle* x = new Car{};
  }
  // superb.load(std::cin);
  // output(std::cout,&superb);
  // std::cout << "Weigth per wheel: " << superb.weightPerWheel() << std::endl;
  // std::cout << "Miles per year: " << superb.milesPerYr() << std::endl;
  // // superb.seats = 7; //private
  // std::cout << "--------------------------" << std::endl;
  // Truck kamijon;
  // kamijon.load(std::cin);
  // output(std::cout,&kamijon);
  // std::cout << "Weigth per wheel: " << kamijon.weightPerWheel() << std::endl;
  // std::cout << "Miles per year: " << kamijon.milesPerYr() << std::endl;
  // std::cout << "--------------------------" << std::endl;
  // Bus avtobus;
  // avtobus.load(std::cin);
  // output(std::cout, &avtobus);
  // std::cout << "Weigth per wheel: " << avtobus.weightPerWheel() << std::endl;
  // std::cout << "Miles per year: " << avtobus.milesPerYr() << std::endl;
  // std::cout << "--------------------------" << std::endl;

  return 0;
}


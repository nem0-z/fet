#include <bitset>
#include <iostream>
void printBits(unsigned short const& reg) {
  std::bitset<16> bits(reg);
  std::cout << bits << std::endl;
  std::cout << std::endl;
}
unsigned short printMenu(void) {
  unsigned short opcija;
  std::cout << std::endl << "###################" << std::endl;
  std::cout << "1. Print register" << std::endl;
  std::cout << "2. Set bit in register" << std::endl;
  std::cout << "3. Reset bit in register" << std::endl;
  std::cout << "4. Swap registers" << std::endl;
  std::cout << "5. Exit" << std::endl << std::endl;
  std::cout << "Enter your choice: ";
  std::cin >> opcija;
  return opcija;
}
void resetReg(unsigned short& reg) {
  unsigned short pos;
  std::cout << "Enter position of bit you want to reset: ";
  std::cin >> pos;
  reg &= ~(1 << (pos - 1));
  std::cout << "New register value is : " << reg << std::endl;
  printBits(reg);
}
void setReg(unsigned short& reg) {
  unsigned short pos;
  std::cout << "Enter position of bit you want to set: ";
  std::cin >> pos;
  reg |= (1 << (pos - 1));
  std::cout << "New register value is : " << reg << std::endl;
  printBits(reg);
}
unsigned short chooseReg(unsigned short& reg1, unsigned short& reg2,
                         unsigned short& regMain) {
  unsigned short opcija;
  std::cout << "Select register you want to view/edit: ";
  std::cin >> opcija;
  if (opcija == 1)
    regMain = reg1;
  else if (opcija == 2)
    regMain = reg2;
  return opcija;
}
void swapReg(unsigned short& reg1, unsigned short& reg2) {
  reg2 = reg1 + reg2;
  reg1 = reg2 - reg1;
  reg2 = reg2 - reg1;
  std::cout << "Registers swapped successfully!" << std::endl;
}
void selectReg(unsigned short& reg1, unsigned short& reg2,
               unsigned short& regMain, unsigned short const opcija) {
  if (opcija == 1)
    reg1 = regMain;
  else if (opcija == 2)
    reg2 = regMain;
}
int main(void) {
  unsigned short reg1 = 0, reg2 = 0, reg = 0;
  unsigned short opcijaMenu, brojRegistra;
  while (1) {
    brojRegistra = chooseReg(reg1, reg2, reg);
    opcijaMenu = printMenu();
    if (opcijaMenu == 1)
      printBits(reg);
    else if (opcijaMenu == 2) {
      setReg(reg);
      selectReg(reg1, reg2, reg, brojRegistra);
    } else if (opcijaMenu == 3) {
      resetReg(reg);
      selectReg(reg1, reg2, reg, brojRegistra);
    } else if (opcijaMenu == 4) {
      swapReg(reg1, reg2);
    } else if (opcijaMenu == 5) {
      return 0;
    } else {
      std::cout << "Wrong choice! " << std::endl;
      break;
    }
  }

  return 0;
}

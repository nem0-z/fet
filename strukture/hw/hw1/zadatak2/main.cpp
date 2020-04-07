#include <iostream>
#include "dna_storage.hpp"

int printMenu()
{
  int choice = -1;
  std::cout << "\n1. Print\n";
  std::cout << "2. Print <pos> <len>\n";
  std::cout << "3. Insert <pos> <lanac>\n";
  std::cout << "4. Remove <pos> <len>\n";
  std::cout << "5. Store <file>\n";
  std::cout << "6. Load <file>\n";
  std::cout << "7. Exit\n\n";
  std::cout << "Your choice: ";
  std::cin >> choice;
  return choice;
}

int main(int argc, char const *argv[])
{
  DNAStorage myStorage{};
  int pos, len;
  std::string lanac, filename;
  std::cout << "Welcome to DNA storage. Please enter one of the following "
               "options:\n\n";
  while (1)
  {
    try
    {
      int choice = printMenu();
      if (choice == 1)
      {
        myStorage.print(std::cout);
      }
      else if (choice == 2)
      {
        std::cout << "Position: ";
        std::cin >> pos;
        std::cout << "Length: ";
        std::cin >> len;
        myStorage.print(std::cout, pos, len);
      }
      else if (choice == 3)
      {
        std::cout << "Position: ";
        std::cin >> pos;
        std::cout << "Value: ";
        std::cin >> lanac;
        myStorage.insert(pos, lanac);
      }
      else if (choice == 4)
      {
        std::cout << "Position: ";
        std::cin >> pos;
        std::cout << "Length: ";
        std::cin >> len;
        myStorage.remove(pos, len);
      }
      else if (choice == 5)
      {
        std::cout << "File: ";
        std::cin >> filename;
        myStorage.store(filename);
      }
      else if (choice == 6)
      {
        std::cout << "File: ";
        std::cin >> filename;
        myStorage.load(filename);
      }
      else if (choice == 7)
      {
        break;
      }
      else
      {
        std::cout << "Wrong input!" << std::endl;
      }
    }
    catch (std::logic_error exception)
    {
      std::cout << exception.what() << std::endl;
    }
    catch (std::runtime_error exception)
    {
      std::cout << exception.what() << std::endl;
    }
    catch (std::out_of_range exception)
    {
      std::cout << exception.what() << std::endl;
    }
  }

  return 0;
}

#include <iostream>
#include <string>
using std::string;
int main(void) {
  /*
   string text("zlatan");
  std::cout << text << std::endl;
  string a;  // prazan string
  // std::cout << a << std::endl;
  std::cout << text.size() << std::endl;
  // std::cout << a.size() << std::endl;
  string text1("rijec1");
  string text2("rijec2");
  string text3 = text1 + text2;
  std::cout << text3 << std::endl;
  std::cout << text3.size() << std::endl;
  string b(10, 'x');  // jos jedan nacin inicijalizacije
  std::cout << b << std::endl;
  std::cout << b.size() << std::endl;  // duzina stringa
  // za onaj gore string text
  std::cout << text[0] << std::endl;
  std::cout << text[1] << std::endl;
  std::cout << text[2] << std::endl;
  std::cout << text[3] << std::endl;
  std::cout << text[4] << std::endl;
  std::cout << text[5] << std::endl;
  std::cout << text[15] << std::endl;  // van granica smo - nedefinisano
  std::cout << text.at(1) << std::endl;
  std::cout << text.at(15)
  << std::endl;  // izbacuje error - pametniji od onog gor
  string e;
  std::cin >> e;
  std::cout << "Unijeli ste: " << e << std::endl;
  // provjeri da li se unos zavrsava sa a
  if (e[e.size() - 1] == 'a') {
    std::cout << "svaka cast" << std::endl;
  }
  if (e.back() == 'a') {  // uzima zadnji karakter
  std::cout << "svaka cast" << std::endl;
  }
  // if (a.front() == 'a') {  // uzima prvi karakter
    // std::cout << "svaka cast" << std::endl;
  // }
  // a.pop_back();  // ukloni zadnji karakter
  // std::cout << a << std::endl;
  // e[0]='t';     //na int poziciju doda char
  // e.insert(1,'x'); //na int poziciju doda char
  // if (!a.empty() && a.back() == 'a')  // ako je string prazan
  // */
  string q, w;
  std::cout << "Unesi rijec:" << std::endl;
  std::cin >> q;
  std::cout << "Unijeli ste:" << q << std::endl;
  std::cin.clear();
  std::cin.ignore(10000,'\n');  // uvijek ova 2 u paru idu, cin.ignore ide sve do \n u
                          // ovom slucaju ili dok ne prodje int karaktera
  std::cout << "Unesi rijec:" << std::endl;
  std::cin >> w;
  std::cout << "Unijeli ste:" << w << std::endl;
  string linija;
  std::cin >> linija;
  std::getline(std::cin,linija);
  return 0;
}

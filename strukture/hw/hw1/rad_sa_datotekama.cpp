#include <fstream> // zaglavlje za rad sa fileovima
#include <string>
#include <iostream>

struct Osoba {
  std::string ime;
  std::string prezime;
};

// navedene klase koriste std::ostream klasu za rad sa ispisom, te kod
// rada sa fileovima koristimo potpuno isti tip klase. 
std::ostream& operator<<(std::ostream& out, const Osoba& o) {
  return out << o.ime << " " << o.prezime << std::endl;
}

void upisi(std::ostream& out) {
  out << 1 << std::endl;
}


int main(int argc, char *argv[])
{

  // Objekat tipa ofstream otvara file za ispis - output file stream
  // Otvara se file "data.txt"
  std::ofstream output{"data.txt"};
  if (output.is_open()) {
    // možemo provjeriti da li je file stvarno otvoren
  }

  // rad sa ofstreamom je sličan radu sa cout objektom
  output << "Hello, world!" << std::endl;
  upisi(output);
  Osoba o{"Student", "Studentic"};
  output << o << std::endl;

  // Potrebno je zatvoriti file kada zavrsimo sa radom
  output.close();


  // Objekat tipa ifstream otvara file za ucitavanje - input file stream
  // Otvara se file "data.txt"
  std::ifstream input{"data.txt"};

  if (input.is_open()) {
    // možemo provjeriti da li je file stvarno otvoren
  }

  // rad sa ifstreamom je slican radu sa cin objektom
  std::string s, ime, prezime;
  int n;
  std::getline(input, s);
  std::cout << s << std::endl;

  input >> n;
  std::cout << n << std::endl;

  input >> ime >> prezime;
  std::cout << ime << " " << prezime << std::endl;

  // Potrebno je zatvoriti file kada zavrsimo sa radom
  input.close();


  return 0;
}

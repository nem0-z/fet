#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <iterator>
#include "univ2.hpp"

std::list<Predmet>::const_iterator nadjiPredmet(std::list<Predmet>& lista,
                                                std::string key) {
  for (auto i = lista.begin(); i != lista.end(); ++i) {
    if ((*i).naziv == key) return i;
  }
  return lista.end();
}

void unosPredmeta(std::list<Predmet>& lista) {
  std::string naziv, odsjek;
  Predmet dummy;
  std::cout << "Unesi naziv predmeta: ";
  std::cin >> naziv;
  auto testIterator = nadjiPredmet(lista, naziv);
  if (testIterator != lista.end()) {
    std::cout << "Error!Taj predmet je vec unesen!\n";
    return;
  } else {
    dummy.naziv = naziv;
    std::cout << "Unesi odsjek predmeta: ";
    std::cin >> odsjek;
    dummy.odsjek = odsjek;
  }
  lista.push_back(dummy);
}

std::vector<Student>::iterator nadjiIndeks(std::vector<Student>& kont,
                                                 std::string indeks) {
  for (auto i = kont.begin(); i != kont.end(); ++i) {
    if ((*i).brojIndeksa == indeks) return i;
  }
  return kont.end();
}

OcjenaIzPredmeta upisOcjene(std::list<Predmet> predmeti)
{ 
  int testOcjena=-1;
  std::string testPredmet{};
  OcjenaIzPredmeta test;
  std::cout << "#####Unos ocjena#####\n";
    std::cout << "Predmet za koji upisujes ocjenu: ";
    std::getline(std::cin, testPredmet);
    std::cin.clear();
    auto tmp = nadjiPredmet(predmeti, testPredmet);
    if (tmp == predmeti.end()) {
      std::cout << "Error!Taj predmet ne postoji!\n";
      return upisOcjene(predmeti);
    } else {
      test.predmet = tmp;
    }
    while (testOcjena < 6 || testOcjena > 10) {
      std::cout
          << "Unesi ocjenu (unos se ponavlja dok ne uneses validnu ocjenu): ";
      std::cin >> testOcjena;
    }
    test.ocjena = testOcjena;
    return test;

}
void unosStudenta(std::vector<Student>& vectStudenata,
                  std::list<Predmet>& predmeti) {
  OcjenaIzPredmeta test;
  Student dummy;
  std::vector<OcjenaIzPredmeta> ocjene;
  std::string indeks, ime, prezime, grad, testPredmet;
  std::cout << "Broj indeksa: ";
  std::cin >> indeks;
  dummy.brojIndeksa=indeks;
  std::cin.clear();
  std::cin.ignore();
  auto testIterator = nadjiIndeks(vectStudenata, indeks);
  if (testIterator != vectStudenata.end()) {
    std::cout << "Error!Taj student je vec unesen!\n";
    return;
  } else {
    std::cout << "Ime studenta: ";
    std::getline(std::cin, ime);
    dummy.ime = ime;
    std::cout << "Prezime studenta: ";
    std::getline(std::cin, prezime);
    dummy.prezime = prezime;
    std::cout << "Grad: ";
    std::getline(std::cin, grad);
    dummy.grad = grad;
    auto ocjena = upisOcjene(predmeti);
    ocjene.push_back(ocjena);
    dummy.ocjena = ocjene;
    vectStudenata.push_back(dummy);
  }
}

void editStudenta(std::vector<Student>& vectStudenata,
                  std::list<Predmet>& listaPredmeta) {
  std::string indeks;
  int izbor = -1;
  std::cout << "Broj indeksa studenta: ";
  std::cin >> indeks;
  auto testIterator = nadjiIndeks(vectStudenata, indeks);
  if (testIterator == vectStudenata.end()) {
    std::cout << "Nemamo tog studenta na stanju, navratite uskoro!\n";
    return;
  } else {
    std::cout << "#####EDIT MODE#####\n";
    std::cout<< "1.Edit broj indeksa\n2.Edit ime\n3.Edit prezime"
                "\n4.Edit grad\n5.Brisi sve ocjene\n6.Dodaj ocjenu\n";
    std::cout<<"Vas izbor: ";
    std::cin>>izbor;
    std::cin.clear();
    std::cin.ignore();
    if (izbor == 1)
    {
      std::string dummy;
        std::cout<<"Unesi novi broj indeksa: ";
        std::cin>>dummy;
        (*testIterator).brojIndeksa = dummy;
    }
    else if(izbor == 2)
    {
      std::string dummy;
      std::cout<<"Unesi novo ime: ";
      std::getline(std::cin,dummy);
      (*testIterator).ime = dummy;
    }
    else if(izbor == 3)
    {
      std::string dummy;
      std::cout<<"Unesi novo prezime: ";
      std::getline(std::cin,dummy);
      (*testIterator).prezime = dummy;
    }
    else if(izbor == 4)
    {
      std::string dummy;
      std::cout<<"Unesi novi grad: ";
      std::getline(std::cin,dummy);
      (*testIterator).grad = dummy;
    }
    else if(izbor == 5)
    {
      ((*testIterator).ocjena).clear();
    }
    else if (izbor == 6){
     auto ocjena = upisOcjene(listaPredmeta);
    ((*testIterator).ocjena).push_back(ocjena);
    }
    else 
    {
      std::cout<<"Error!Pogresan unos!";
    }
  }
}

void ispisOcjena(std::vector<Student>::iterator it, std::list<Predmet>& lista)
{
  std::cout<<"Ocjena\tPredmet\n";
  auto test = (*it).ocjena;
  for ( auto i = test.begin(); i!= test.end(); ++i)
  {
    auto foo = (*i).predmet;
    std::cout<<(*i).ocjena<<"\t"<<(*foo).naziv<<std::endl;
  }
}

void printStudenta(std::vector<Student>& vect, std::list<Predmet>& lista)
{
  std::string indeks;
  std::cout<<"Unesi broj indeksa: ";
  std::cin>>indeks;
  auto tmp = nadjiIndeks(vect,indeks);
  if (tmp == vect.end())
  {
    std::cout<<"Nemamo tog studenta na stanju, navratite ponovo!\n";
    return ;
  }
  else
  {
      std::cout<<"Broj indeksa: ";
      std::cout<<(*tmp).brojIndeksa<<std::endl;
      std::cout<<"Ime: ";
      std::cout<<(*tmp).ime<<std::endl;
      std::cout<<"Prezime: ";
      std::cout<<(*tmp).prezime<<std::endl;
      std::cout<<"Grad: ";
      std::cout<<(*tmp).grad<<std::endl;
      std::cout<<"#####OCJENE#####\n";
      ispisOcjena(tmp,lista);
  }
}



#pragma once
#include <list>
#include <string>
#include <vector>
struct Predmet {
  std::string naziv;
  std::string odsjek;
};

struct OcjenaIzPredmeta {
  int ocjena;
  std::list<Predmet>::const_iterator predmet;
};

struct Student {
  std::string brojIndeksa;
  std::string ime;
  std::string prezime;
  std::string grad;
  std::vector<OcjenaIzPredmeta> ocjena;
};

std::list<Predmet>::const_iterator nadjiPredmet(std::list<Predmet>& lista,
                                                std::string key);

void unosPredmeta(std::list<Predmet>& lista);

std::vector<Student>::iterator nadjiIndeks(std::vector<Student>& kont,
                                           std::string indeks);

void unosStudenta(std::vector<Student>& vectStudenata,
                  std::list<Predmet>& predmeti);

void editStudenta(std::vector<Student>& vectStudenata,
                  std::list<Predmet>& listaPredmeta);

void ispisOcjena(std::vector<Student>::iterator it, std::list<Predmet>& lista);

void printStudenta(std::vector<Student>& vect, std::list<Predmet>& lista);

OcjenaIzPredmeta upisOcjene(std::list<Predmet> predmeti);



 



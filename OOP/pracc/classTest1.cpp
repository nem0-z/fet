#include <iostream> 
using namespace std; 
class mojaKlasa{
  int realni,imaginarni;
  public:
 explicit mojaKlasa(){
    realni = 0;
    imaginarni =0;
  }
  explicit mojaKlasa(int a, int b)
  {
    realni = a;
    imaginarni = b;
  }

  void readNr(){
    cout<<realni<<" + i"<<imaginarni<<endl;}
   void setFirst(int a){
    realni = a;
  }
  void setSecond(int a){
    imaginarni = a;
  }
  void print(void){
    cout<<realni<<" + i"<<imaginarni<<endl;
  }
};

  

int main(int argc, char *argv[])
{
  mojaKlasa foo;
  // foo.readNr();
  // mojaKlasa<int> bar{ 2,5 };
  // bar.readNr();
  // mojaKlasa<int> tar{bar};
  // tar.readNr();
  // tar.setFirst(1204);
  // tar.readNr();
  cout<<"Unesi realni broj ";
  int unos;
  cin>>unos;
  foo.setFirst(unos);
  cout<<"Unesi imaginarni broj ";
  cin>>unos;
  foo.setSecond(unos);
  foo.print();
  return 0;
}

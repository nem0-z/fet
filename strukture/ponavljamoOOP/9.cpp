#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class Radnik{       
    public:
    Radnik() = default;
    Radnik(const char* ime, bool status, uint_fast64_t plata) :
    ime_{ime},status_{status},plata_{plata}{
        std::cout << "Custom constructor P1MP MY RIDE" << std::endl;
    }
    void setName(const char* str){
        ime_ = str;
    }
    void setStatus(bool foo){
        status_ = foo;
    }
    int getPlata(void) const{
        return plata_;
    }
    bool poredi(const Radnik& drugi){
        if (plata_>drugi.getPlata()) return true;
        return false;
    }
    void setPlata(int);
    std::ostream& ispisi(std::ostream&);
    friend std::ostream& operator<<(std::ostream& stream, const Radnik& meho);

     private:
    const char* ime_{};
    bool status_{};
    uint_fast64_t plata_;
}; 

std::ostream& operator<<(std::ostream& stream, const Radnik& meho){
    stream<<meho.ime_<<" "<<meho.status_<<" "<<meho.plata_<<endl;
    return stream;
}
void Radnik::setPlata(int val){
    plata_ = val;
}

std::ostream& Radnik::ispisi(std::ostream& stream){
    stream<<ime_<<" "<<status_<<" "<<plata_<<endl;
    return stream;
}

// std::ostream& Radnik::operator<<(std::ostream& stream,const Radnik& bracurda){
//     stream<<bracurda.ime_<<" "<<bracurda.status_<<" "<<bracurda.plata_<<endl;
//     return stream;
// }

int main(int argc, char const *argv[])
{
    const char* str = "Hello";
    std::cout << strlen(str) << std::endl;
    Radnik brato{"Meho",true,6000};
    Radnik noviBrato;
    noviBrato.setName("Amer");
    noviBrato.setStatus(false);
    noviBrato.setPlata(1000);
    std::cout << brato.poredi(noviBrato) << std::endl;
    std::cout << noviBrato << std::endl;
    return 0;
}

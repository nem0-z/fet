#ifndef _ELEM_H_
#define _ELEM_H_
#include <iostream>

struct El {
  El(){std::cout<<"El constructor"<<std::endl;}
  El(const El&){std::cout<<"El copy constructor"<<std::endl;}
  El(El&&){std::cout<<"El move constructor"<<std::endl;}
  El& operator=(const El&){std::cout<<"El copy assignment"<<std::endl; return *this;}
  El& operator=(El&&){std::cout<<"El move assignment"<<std::endl;return *this;}
  ~El(){std::cout<<"El destructor"<<std::endl;}
};
#endif /* ifndef _ELEM_H_ */

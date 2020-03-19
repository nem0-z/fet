#include <iostream>
#include <vector>
#include <list>
using namespace std;
template <class InputIterator, class OutputIterator>
  OutputIterator mojCopy (InputIterator first, InputIterator last, OutputIterator result)
{
    while(first!=last)
    {
      *result = *first;
      ++first;
      ++result;
    }
    return result;
}

template<class OutputIterator>
void mojPrint(OutputIterator start, OutputIterator end)
{
  while(start!=end)
  {
    cout<<*start++<<" ";

  }
    cout<<endl;
}
int main(int argc, char *argv[])
{
  vector<int> x={10,20,30,40,50,60,70};
  std::vector<int> myvector = {5,5,5,5,5,5,5,5,5};

  mojCopy( x.begin(),x.end(), myvector.begin() );

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;


return 0;
}

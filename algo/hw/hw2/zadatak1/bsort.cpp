#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

template <typename It>
void printArr(It begin, It end)
{
    while (begin != end)
        std::cout << *begin++ << " ";
    std::cout << std::endl;
}

auto makeArr(void)
{
    std::vector<int> v;
    int i = 200;
    while (i--)
        v.push_back(i);
    std::random_shuffle(v.begin(), v.end());
    return v;
}

template <typename It>
void bubblesort(It begin, It end)
{
    It i, j, i1, i2;
    while (begin != end)
    {
        i = begin;
        j = --end;
        while (i != j)
        {
          i1 = i;
          i2 = ++i;
            if (*i1 > *i2)
                std::swap(*i1, *i2);
        }
    }
}

int main(void)
{
    std::vector<int> v = makeArr();
    std::cout << "Before sorting: " << std::endl;
    printArr(v.begin(), v.end());
    auto now = std::chrono::system_clock::now();
    bubblesort(v.begin(), v.end());
    auto finish = std::chrono::system_clock::now();
    auto elapsed = finish - now;
    std::cout << "After sorting: " << std::endl;
    printArr(v.begin(), v.end());
    std::cout << "Time elapsed: " << elapsed.count() / 1000 << "us" << std::endl;
}

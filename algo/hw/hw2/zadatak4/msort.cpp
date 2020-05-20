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
    int i = 2000;
    while (i--)
        v.push_back(i);
    std::random_shuffle(v.begin(), v.end());
    return v;
}

template <typename It>
void merge(It s1, It e1, It s2, It e2)
{
    It i1, i2;
    while (s1 != e1)
    {
        if (*s2 < *s1)
        {
            std::swap(*s1, *s2);
            i1 = s2;
            i2 = ++s2;
            --s2;
            while (*i1 > *i2 && i2 != e2)
                std::swap(*i1++, *i2++);
        }
        ++s1;
    }
}

template <typename It>
void mergesort(It begin, It end)
{
    const int size = end - begin;
    if (size <= 1)
        return;
    It mid = begin + size / 2;
    mergesort(begin, mid);
    mergesort(mid, end);
    merge(begin, mid, mid, end);
}

int main(void)
{
    std::vector<int> v = makeArr();
    std::cout << "Before sorting: " << std::endl;
    printArr(v.begin(), v.end());
    auto now = std::chrono::system_clock::now();
    mergesort(v.begin(), v.end());
    auto finish = std::chrono::system_clock::now();
    auto elapsed = finish - now;
    std::cout << "After sorting: " << std::endl;
    printArr(v.begin(), v.end());
    std::cout << "Time elapsed: " << elapsed.count() / 1000 << "us" << std::endl;
}

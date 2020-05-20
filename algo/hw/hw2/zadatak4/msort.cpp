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
void merge(It s1, It e1, It s2, It e2, It dest)
{
    while (s1 != e1 && s2 != e2)
    {
        if (*s1 <= *s2)
            *dest++ = *s1++;
        else
            *dest++ = *s2++;
    }
    while (s1 != e1)
        *dest++ = *s1++;
    while (s2 != e2)
        *dest++ = *s2++;
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

    std::vector<typename It::value_type> tmp;
    tmp.resize(size);
    // merge(begin, mid, mid, end, tmp.begin());
    merge(begin, mid, mid, end, begin);
    // std::copy(tmp.begin(), tmp.end(), begin);
}

template <typename It>
void mergeshit(It s1, It e1, It s2, It e2, It dest)
{
    std::cout << "Prvi niz: " << std::endl;
    printArr(s1, e1);
    std::cout << "Drugi niz: " << std::endl;
    printArr(s2, e2);
    for (int i = 0; i < 20; ++i)
        *s1++ = i;
}

int main(void)
{
    // std::vector<int> v = makeArr();
    // std::cout << "Before sorting: " << std::endl;
    // printArr(v.begin(), v.end());
    // auto now = std::chrono::system_clock::now();
    // mergesort(v.begin(), v.end());
    // auto finish = std::chrono::system_clock::now();
    // auto elapsed = finish - now;
    // std::cout << "After sorting: " << std::endl;
    // printArr(v.begin(), v.end());
    // std::cout << "Time elapsed: " << elapsed.count() / 1000 << "us" << std::endl;
    std::vector<int> v{1, 4, 9, 8};
    std::vector<int> x{2, 3, 5, 11};
    std::vector<int> l;
    l.resize(x.size() + v.size());
    printArr(l.begin(), l.end());
    // mergeshit(v.begin(), v.end(), x.begin(), x.end(),l.begin());
    // printArr(l.begin(), l.end());
    mergeshit(v.begin(), v.end(), x.begin(), x.end(), v.begin());
    printArr(v.begin(), v.end());
}

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
    int i = 20;
    while (i--)
        v.push_back(i);
    std::random_shuffle(v.begin(), v.end());
    return v;
}

template <typename It>
void selectionsort(It begin, It end)
{
    It i, min;
    while (begin != end)
    {
        i = min = begin;
        while (i != end)
        {
            It t1 = i++;
            if (*min > *t1)
                min = t1;
        }
        std::swap(*begin++, *min);
    }
}

int main(void)
{

    std::vector<int> v = makeArr();
    std::cout << "Before sorting: " << std::endl;
    printArr(v.begin(), v.end());
    auto now = std::chrono::system_clock::now();
    selectionsort(v.begin(), v.end());
    auto finish = std::chrono::system_clock::now();
    auto elapsed = finish - now;
    std::cout << "After sorting: " << std::endl;
    printArr(v.begin(), v.end());
    std::cout << "Time elapsed: " << elapsed.count() / 1000 << "us" << std::endl;
}
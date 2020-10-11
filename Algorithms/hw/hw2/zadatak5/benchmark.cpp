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
    int i = 50000;
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

template <typename It>
void insertionsort(It begin, It end)
{
    It dummyBegin, dummyEnd, i, j;
    for (dummyBegin = begin, dummyEnd = --end; begin != dummyEnd;)
    {
        i = begin;
        j = ++begin;
        while (*j < *i && j != dummyBegin)
            std::swap(*j--, *i--);
    }
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

namespace QS
{

    template <typename It>
    void insertionsort(It begin, It end)
    {
        for (It dummyBegin = begin, dummyEnd = --end; begin != dummyEnd;)
        {
            It i = begin;
            It j = ++begin;
            while (*j < *i && j != dummyBegin)
                std::swap(*j--, *i--);
        }
    }
    template <typename It>
    It partition(It begin, It end)
    {
        It pivot = --end;
        while (begin <= end)
        {
            if (begin > --end)
                break;
            // cheeky decrement end and check for overlap
            while (*begin <= *pivot && begin != pivot)
                ++begin;
            while (*end > *pivot)
                --end;
            if (begin < end)
                std::swap(*begin++, *end);
        }
        std::swap(*begin, *pivot);
        return begin;
    }

    template <typename It>
    void quicksort(It begin, It end)
    {
        const int size = end - begin;
        if (size <= 1)
            return;
        if (size < 10)
        {
            insertionsort(begin, end);
            return;
        }
        It partition_point = QS::partition(begin, end);
        quicksort(begin, partition_point);
        quicksort(++partition_point, end);
    }
} // namespace QS

int main(void)
{
    std::cout << "Let's just trust me that those sorts work and let's just bench times so we don't waste time on std::cout lol\n"
              << std::endl;
    std::cout << "Sorting 20000 elements\n"
              << std::endl;
    {
        std::cout << "Bubble sort:" << std::endl;
        std::vector<int> v = makeArr();
        // std::cout << "Before sorting: " << std::endl;
        // printArr(v.begin(), v.end());
        auto now = std::chrono::system_clock::now();
        bubblesort(v.begin(), v.end());
        auto finish = std::chrono::system_clock::now();
        auto elapsed = finish - now;
        // std::cout << "After sorting: " << std::endl;
        // printArr(v.begin(), v.end());
        std::cout << "Time elapsed: " << elapsed.count() / 1000000 << "ms" << std::endl;
    }
    {
        std::cout << "\nSelection sort:" << std::endl;
        std::vector<int> v = makeArr();
        // std::cout << "Before sorting: " << std::endl;
        // printArr(v.begin(), v.end());
        auto now = std::chrono::system_clock::now();
        selectionsort(v.begin(), v.end());
        auto finish = std::chrono::system_clock::now();
        auto elapsed = finish - now;
        // std::cout << "After sorting: " << std::endl;
        // printArr(v.begin(), v.end());
        std::cout << "Time elapsed: " << elapsed.count() / 1000000 << "ms" << std::endl;
    }
    {
        std::cout << "\nInsertion sort:" << std::endl;
        std::vector<int> v = makeArr();
        // std::cout << "Before sorting: " << std::endl;
        // printArr(v.begin(), v.end());
        auto now = std::chrono::system_clock::now();
        insertionsort(v.begin(), v.end());
        auto finish = std::chrono::system_clock::now();
        auto elapsed = finish - now;
        // std::cout << "After sorting: " << std::endl;
        // printArr(v.begin(), v.end());
        std::cout << "Time elapsed: " << elapsed.count() / 1000000 << "ms" << std::endl;
    }
    {
        std::cout << "\nInplace merge sort (square complexity):" << std::endl;
        std::vector<int> v = makeArr();
        // std::cout << "Before sorting: " << std::endl;
        // printArr(v.begin(), v.end());
        auto now = std::chrono::system_clock::now();
        mergesort(v.begin(), v.end());
        auto finish = std::chrono::system_clock::now();
        auto elapsed = finish - now;
        // std::cout << "After sorting: " << std::endl;
        // printArr(v.begin(), v.end());
        std::cout << "Time elapsed: " << elapsed.count() / 1000000 << "ms" << std::endl;
    }
    {
        std::cout << "\nQuick sort go brrrr:" << std::endl;
        std::vector<int> v = makeArr();
        // std::cout << "Before sorting: " << std::endl;
        // printArr(v.begin(), v.end());
        auto now = std::chrono::system_clock::now();
        QS::quicksort(v.begin(), v.end());
        auto finish = std::chrono::system_clock::now();
        auto elapsed = finish - now;
        // std::cout << "After sorting: " << std::endl;
        // printArr(v.begin(), v.end());
        std::cout << "Time elapsed: " << elapsed.count() / 1000000 << "ms" << std::endl;
    }
    return 0;
}

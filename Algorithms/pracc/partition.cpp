#include <iostream>
#include <algorithm>

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void partition(int *arr, int size)
{
    int start = 0;
    int end = size - 2;
    int pivot = size - 1;
    while (start < end)
    {
        while (arr[start] < arr[pivot] && start < end)
            ++startS;
        while (arr[end] > arr[pivot])
            --end;
        std::swap(arr[start], arr[end]);
        ++start;
        --end;
    }
    std::swap(arr[start], arr[pivot]);
}

int main(int argc, const char **argv)
{
    int arr[] = {14, 5, 2, 6, 9, 2, 7, 3};
    printArr(arr, sizeof(arr) / sizeof(int));
    partition(arr, sizeof(arr) / sizeof(int));
    printArr(arr, sizeof(arr) / sizeof(int));
    return 0;
}
#include "task8.h"

std::vector<ImplementationResult> Task8::runImplementations()
{
    std::vector<int> big_arr(100000, 2);
    std::fill(big_arr.begin() + 30000, big_arr.begin() + 60000, 0);
    std::fill(big_arr.begin() + 60000, big_arr.end(), 1);
    std::vector<int> arr1 = big_arr, arr2 = big_arr, arr3 = big_arr;

    std::vector<ImplementationResult> results;
    results.push_back(runAndMeasure([&]() { sortFlag(arr1); }, "Three ptr"));
    results.push_back(runAndMeasure([&]() { sortFlagCounting(arr2); }, "Counting"));
    results.push_back(runAndMeasure([&]() { sortFlagPartition(arr3); }, "Partition"));

    return results;
}

void Task8::sortFlag(std::vector<int>& arr) 
{
    int64_t low = 0;           // Указатель на границу нулей
    int64_t mid = 0;           // Указатель на текущий элемент
    int64_t high = arr.size() - 1; // Указатель на границу двоек

    while (mid <= high) {
        switch (arr[mid]) 
        {
        case 0:
            std::swap(arr[low], arr[mid]);
            low++;
            mid++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            std::swap(arr[mid], arr[high]);
            high--;
            // mid не увеличиваем, т.к. после обмена на позиции mid
            // может оказаться 0 или 1, которые нужно обработать.
            break;
        }
    }
}

// Реализация с подсчётом (Counting Sort) - тоже линейное время
void Task8::sortFlagCounting(std::vector<int>& arr) 
{
    size_t count0 = 0;
    size_t count1 = 0;
    size_t count2 = 0;

    // Подсчитываем количество 0, 1 и 2
    for (int x : arr) 
    {
        if (x == 0)
            count0++;
        else if (x == 1)
            count1++;
        else
            count2++;
    }

    // Перезаписываем массив
    size_t i = 0;
    while (count0 > 0) 
    {
        arr[i++] = 0;
        count0--;
    }
    while (count1 > 0) 
    {
        arr[i++] = 1;
        count1--;
    }
    while (count2 > 0) 
    {
        arr[i++] = 2;
        count2--;
    }
}

void Task8::sortFlagPartition(std::vector<int>& arr) 
{
    auto it1 = std::partition(arr.begin(), arr.end(), [](int x) { return x == 0; });
    std::partition(it1, arr.end(), [](int x) { return x == 1; });
}
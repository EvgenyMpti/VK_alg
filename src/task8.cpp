#include "task8.h"

std::vector<ImplementationResult> Task8::runImplementations
(std::vector<int>& arr)
{
    std::vector<ImplementationResult> results;

    results.push_back(runAndMeasure([&]() { sortFlag(arr); }, "Three ptr"));
    results.push_back(runAndMeasure([&]() { sortFlagCounting(arr); }, "Counting"));
    results.push_back(runAndMeasure([&]() { sortFlagPartition(arr); }, "Partition"));

    return results;
}

std::pair<int, std::vector<ImplementationResult>> Task8::getStat()
{
    std::vector<int> arr(100000, 2);
    std::fill(arr.begin() + 30000, arr.begin() + 60000, 0);
    std::fill(arr.begin() + 60000, arr.end(), 1);
    return { 8, runImplementations(arr) };
}

void Task8::sortFlag(std::vector<int>& arr) {
    int low = 0;           // Указатель на границу нулей
    int mid = 0;           // Указатель на текущий элемент
    int high = arr.size() - 1; // Указатель на границу двоек

    while (mid <= high) {
        switch (arr[mid]) {
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
void Task8::sortFlagCounting(std::vector<int>& arr) {
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    // Подсчитываем количество 0, 1 и 2
    for (int x : arr) {
        if (x == 0) {
            count0++;
        }
        else if (x == 1) {
            count1++;
        }
        else {
            count2++;
        }
    }

    // Перезаписываем массив
    int i = 0;
    while (count0 > 0) {
        arr[i++] = 0;
        count0--;
    }
    while (count1 > 0) {
        arr[i++] = 1;
        count1--;
    }
    while (count2 > 0) {
        arr[i++] = 2;
        count2--;
    }
}

void Task8::sortFlagPartition(std::vector<int>& arr) {
    auto it1 = std::partition(arr.begin(), arr.end(), [](int x) { return x == 0; });
    std::partition(it1, arr.end(), [](int x) { return x == 1; });
}
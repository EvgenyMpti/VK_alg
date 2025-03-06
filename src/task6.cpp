#include "task6.h"

std::vector<ImplementationResult> Task6::runImplementations
    (std::vector<int>& arr1, std::vector<int>& arr2)
{
    std::vector<ImplementationResult> results;

    results.push_back(runAndMeasure([&]() { mergeArrays(arr1, arr2); }, "merge Arrays"));
    results.push_back(runAndMeasure([&]() { mergeArraysSort(arr1, arr2); }, "merge & sort"));

    return results;
}

std::pair<int, std::vector<ImplementationResult>> Task6::getStat()
{
    std::vector<int> arr1(100000), arr2(100000);
    std::iota(arr1.begin(), arr1.end(), 1);
    std::iota(arr2.begin(), arr2.end(), 40000);
    arr1.resize(arr1.size() + arr2.size(), 0);
    return { 6, runImplementations(arr1, arr2) };
}

void Task6::mergeArrays(std::vector<int>& arr1, const std::vector<int>& arr2) {
    if (arr1.empty() || arr2.empty())
        return;

    const size_t n = arr2.size();
    const size_t m = arr1.size() - n;

    int i = m - 1;       // Указатель на последний значимый элемент arr1
    int j = n - 1;       // Указатель на последний элемент arr2
    int k = m + n - 1;    // Указатель на текущую позицию в arr1 (с конца)

    while (i >= 0 && j >= 0) {
        if (arr1[i] > arr2[j]) {
            arr1[k] = arr1[i];
            i--;
        }
        else {
            arr1[k] = arr2[j];
            j--;
        }
        k--;
    }

    // Если остались элементы в arr2, копируем их в arr1
    while (j >= 0) {
        arr1[k] = arr2[j];
        j--;
        k--;
    }
}

void Task6::mergeArraysSort(std::vector<int>& arr1, const std::vector<int>& arr2) {
    const size_t n = arr2.size();
    const size_t m = arr1.size() - n;

    // Сначала копируем arr2 в конец arr1 (где нули)
    for (int i = 0; i < n; ++i) {
        arr1[m + i] = arr2[i];
    }

    // Теперь сортируем весь arr1
    std::sort(arr1.begin(), arr1.end());
}
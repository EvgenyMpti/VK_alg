#include "task5.h"

std::vector<ImplementationResult> Task5::runImplementations()
{
    std::vector<int> arr1(10000), arr2(10000);
    std::iota(arr1.begin(), arr1.end(), 1);
    std::iota(arr2.begin(), arr2.end(), 4000);

    std::vector<ImplementationResult> results;
    results.push_back(runAndMeasure([&]() { mergeTwoPointers(arr1, arr2); }, "Two Pointers"));
    results.push_back(runAndMeasure([&]() { mergeWithSort(arr1, arr2); }, "Merge With Sort"));
    results.push_back(runAndMeasure([&]() { mergeWithInsertion(arr1, arr2); }, "n Insertion"));

    return results;
}

// Метод двух указателей
std::vector<int> Task5::mergeTwoPointers(const std::vector<int>& arr1, const std::vector<int>& arr2) 
{
    std::vector<int> merged;
    merged.reserve(arr1.size() + arr2.size());

    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) 
    {
        if (arr1[i] <= arr2[j]) 
        {
            merged.push_back(arr1[i]);
            i++;
        }
        else 
        {
            merged.push_back(arr2[j]);
            j++;
        }
    }

    // Добавляем "хвосты"
    while (i < arr1.size()) 
    {
        merged.push_back(arr1[i]);
        i++;
    }
    while (j < arr2.size()) 
    {
        merged.push_back(arr2[j]);
        j++;
    }

    return merged;
}

// Объединение с последующей сортировкой
std::vector<int> Task5::mergeWithSort(const std::vector<int>& arr1, const std::vector<int>& arr2) 
{
    std::vector<int> merged = arr1;
    merged.insert(merged.end(), arr2.begin(), arr2.end()); 
    std::sort(merged.begin(), merged.end()); 
    return merged;
}

// Объединение с вставками
std::vector<int> Task5::mergeWithInsertion(const std::vector<int>& arr1, const std::vector<int>& arr2)
{
    std::vector<int> merged = arr1;
    for (int val : arr2)
    {
        auto it = std::lower_bound(merged.begin(), merged.end(), val);
        merged.insert(it, val);
    }
    return { merged };
}
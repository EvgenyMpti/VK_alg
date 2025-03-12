#include "task10.h"

std::vector<ImplementationResult> Task10::runImplementations()
{
    std::vector<int> big_arr(100000, 0);
    std::iota(big_arr.begin(), big_arr.end(), 1);
    std::vector<int> arr1 = big_arr, arr2 = big_arr, arr3 = big_arr;

    std::vector<ImplementationResult> results;

    results.push_back(runAndMeasure([&]() { moveZerosStablePartition(arr1); }, "Stable Partition"));
    results.push_back(runAndMeasure([&]() { moveZerosTwoPointers(arr2); }, "Two Pointers"));
    results.push_back(runAndMeasure([&]() { moveZerosShift(arr3); }, "Shift move"));

    return results;
}

void Task10::moveZerosStablePartition(std::vector<int>& arr) 
{
    std::stable_partition(arr.begin(), arr.end(), [](int x) { return x != 0; });
}

void Task10::moveZerosTwoPointers(std::vector<int>& arr) 
{
    int nonZeroPos = 0; // Указатель на позицию, куда будем ставить ненулевой элемент

    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] != 0) 
        {
            // Если нашли ненулевой элемент, меняем его с элементом на позиции nonZeroPos
            if (i != nonZeroPos)
                std::swap(arr[i], arr[nonZeroPos]);
            nonZeroPos++; // Увеличиваем позицию для следующего ненулевого элемента
        }
    }
}

void Task10::moveZerosShift(std::vector<int>& arr) 
{
    int nonZeroIndex = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0) 
        {
            if (i != nonZeroIndex) // не двигаем если элемент уже стоит на своем месте
            { 
                int temp = arr[i];
                for (size_t j = i; j > nonZeroIndex; j--)
                    arr[j] = arr[j - 1];
                arr[nonZeroIndex] = temp;
            }
            nonZeroIndex++;
        }
    }
}
#include "task9.h"

std::vector<ImplementationResult> Task9::runImplementations()
{
    std::vector<int> big_arr(100000, 0);
    std::fill(big_arr.begin() + 30000, big_arr.end(), 4);
    std::vector<int> arr1 = big_arr, arr2 = big_arr, arr3 = big_arr;

    std::vector<ImplementationResult> results;
    results.push_back(runAndMeasure([&]() { moveEvenStablePartition(arr1); }, "Stable Partition"));
    results.push_back(runAndMeasure([&]() { moveEvenTwoPointers(arr2); }, "Two Pointers"));
    results.push_back(runAndMeasure([&]() { moveEvenTwoPointersAlt(arr3); }, "Two Pointers fast"));

    return results;
}

void Task9::moveEvenStablePartition(std::vector<int>& arr) 
{
    std::stable_partition(arr.begin(), arr.end(), [](int x) { return x % 2 == 0; });
}

void Task9::moveEvenTwoPointers(std::vector<int>& arr) 
{
    size_t evenPos = 0; // Указатель на позицию, куда будем ставить следующее четное число

    for (size_t i = 0; i < arr.size(); ++i) 
    {
        if (arr[i] % 2 == 0) 
        {
            // Если нашли четное число, перемещаем его на позицию evenPos
            if (i != evenPos) 
            {
                int temp = arr[i]; //сохраняем
                for (size_t j = i; j > evenPos; --j) // сдвигаем
                    arr[j] = arr[j - 1];
                arr[evenPos] = temp;
            }
            evenPos++;
        }
    }
}

void Task9::moveEvenTwoPointersAlt(std::vector<int>& arr) 
{
    int i = 0;
    int j = 0;

    while (j < arr.size()) 
    {
        if (arr[j] % 2 == 0) 
        {
            std::swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }
}
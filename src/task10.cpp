#include "task10.h"

std::vector<ImplementationResult> Task10::runImplementations
(std::vector<int>& arr)
{
    std::vector<ImplementationResult> results;

    results.push_back(runAndMeasure([&]() { moveZerosStablePartition(arr); }, "Stable Partition"));
    results.push_back(runAndMeasure([&]() { moveZerosTwoPointers(arr); }, "Two Pointers"));
    results.push_back(runAndMeasure([&]() { moveZerosShift(arr); }, "Shift move"));

    return results;
}

std::pair<int, std::vector<ImplementationResult>> Task10::getStat()
{
    std::vector<int> arr(100000, 0);
    std::iota(arr.begin(), arr.end(), 1);
    return { 10, runImplementations(arr) };
}

void Task10::moveZerosStablePartition(std::vector<int>& arr) {
    std::stable_partition(arr.begin(), arr.end(), [](int x) { return x != 0; });
}

void Task10::moveZerosTwoPointers(std::vector<int>& arr) {
    int nonZeroPos = 0; // Указатель на позицию, куда будем ставить ненулевой элемент

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] != 0) {
            // Если нашли ненулевой элемент, меняем его с элементом на позиции nonZeroPos
            if (i != nonZeroPos) {
                std::swap(arr[i], arr[nonZeroPos]);
            }
            nonZeroPos++; // Увеличиваем позицию для следующего ненулевого элемента
        }
    }
}

void Task10::moveZerosShift(std::vector<int>& arr) {
    int n = arr.size();
    int nonZeroIndex = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            if (i != nonZeroIndex) { // не двигаем если элемент уже стоит на своем месте
                int temp = arr[i];
                for (int j = i; j > nonZeroIndex; j--) {
                    arr[j] = arr[j - 1];
                }
                arr[nonZeroIndex] = temp;
            }
            nonZeroIndex++;
        }
    }
}
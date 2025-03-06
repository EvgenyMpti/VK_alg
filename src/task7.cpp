#include "task7.h"

std::vector<ImplementationResult> Task7::runImplementations
(std::vector<int>& arr)
{
    std::vector<ImplementationResult> results;

    results.push_back(runAndMeasure([&]() { sortZeroOne(arr); }, "Two side"));
    results.push_back(runAndMeasure([&]() { sortZeroOneCounting(arr); }, "Counting"));
    results.push_back(runAndMeasure([&]() { sortZeroOneShift(arr); }, "One side"));
    results.push_back(runAndMeasure([&]() { sortZeroOnePartition(arr); }, "Partition"));

    return results;
}

std::pair<int, std::vector<ImplementationResult>> Task7::getStat()
{
    std::vector<int> arr(100000, 1);
    std::fill(arr.begin(), arr.begin() + 50000, 0);
    return { 7, runImplementations(arr) };
}

void Task7::sortZeroOne(std::vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        // Находим первый 1 слева
        while (left < right && arr[left] == 0) {
            left++;
        }

        // Находим первый 0 справа
        while (left < right && arr[right] == 1) {
            right--;
        }

        // Если left всё ещё меньше right, меняем элементы местами
        if (left < right) {
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

void Task7::sortZeroOneCounting(std::vector<int>& arr) {
    int countZero = 0;
    for (int x : arr) {
        if (x == 0) {
            countZero++;
        }
    }

    // Перезаписываем массив
    for (int i = 0; i < arr.size(); ++i) {
        if (i < countZero) {
            arr[i] = 0;
        }
        else {
            arr[i] = 1;
        }
    }
}

void Task7::sortZeroOneShift(std::vector<int>& arr) {
    int zeroPos = 0; // Позиция, куда будем ставить следующий 0
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == 0) {
            // Если нашли 0, меняем его с элементом на позиции zeroPos
            if (i != zeroPos) { // Проверка i != zeroPos нужна, чтобы не менять 0 сам с собой.
                std::swap(arr[i], arr[zeroPos]);
            }
            zeroPos++; // Увеличиваем позицию для следующего 0
        }
    }
}

void Task7::sortZeroOnePartition(std::vector<int>& arr) {
    std::partition(arr.begin(), arr.end(), [](int x) { return x == 0; });
}
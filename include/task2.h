#pragma once

#include "task.h"

/*
Дан отсортированный по возрастанию массив целых чисел и некоторое число target. 
Необходимо найти два числа в массиве, которые в сумме дают заданное значение target и вернуть их индексы.
*/

class Task2 : public Task {
public:
    struct TwoSumResult {
        bool found;
        int index1;
        int index2;

        bool operator==(const TwoSumResult& other) const {
            return found == other.found && index1 == other.index1 && index2 == other.index2;
        }
    };
    std::vector<ImplementationResult> runImplementations(const std::vector<int>& nums, int target);
    std::pair<int, std::vector<ImplementationResult>> getStat() override;

    TwoSumResult twoPointers(const std::vector<int>& nums, int target);     // O(n)
    TwoSumResult hashTable(const std::vector<int>& nums, int target);       // O(n) + память, поиск O(1)
    TwoSumResult binarySearch(const std::vector<int>& nums, int target);    // O(n log n)
    TwoSumResult bruteForce(const std::vector<int>& nums, int target);      // O(n^2)
};

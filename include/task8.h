#pragma once

#include "task.h"

/*
Дан массив состоящий из нулей, единиц и двоек.
Необходимо его отсортировать за линейное время.
*/

class Task8 : public Task {
public:
    std::vector<ImplementationResult> runImplementations(std::vector<int>& arr);
    std::pair<int, std::vector<ImplementationResult>> getStat() override;

    void sortFlag(std::vector<int>& arr);           // O(n)
    void sortFlagCounting(std::vector<int>& arr);   // O(n)
    void sortFlagPartition(std::vector<int>& arr);  // O(n)
};
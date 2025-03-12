#pragma once

#include "task.h"

/*
Дан массив состоящий из нулей, единиц и двоек.
Необходимо его отсортировать за линейное время.
*/

class Task8 : public Task {
public:
    Task8()
    {
        desc_ = "Sort 0,1 and 2 in-place";
    }
    std::vector<ImplementationResult> runImplementations() override;

    void sortFlag(std::vector<int>& arr);           // O(n)
    void sortFlagCounting(std::vector<int>& arr);   // O(n)
    void sortFlagPartition(std::vector<int>& arr);  // O(n)
};
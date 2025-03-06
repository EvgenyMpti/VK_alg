#pragma once

#include "task.h"

/*
Написать функцию, которая принимает на вход два отсортированных односвязных списка и объединяет их в один отсортированный список. При этом затраты по памяти должны быть O(1)
Входные данные: list1 = [3, 6, 8], list2 = [4, 7, 9, 11]
Выходные: [3,4,6,7,8,9,11]
*/

class Task17 : public Task {
public:
    std::vector<ImplementationResult> runImplementations();
    std::pair<int, std::vector<ImplementationResult>> getStat() override;

    ListNodeRaw* mergeTwoLists(ListNodeRaw* list1, ListNodeRaw* list2);
};

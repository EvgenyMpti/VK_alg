#pragma once

#include "task.h"

/*
Дан односвязный список. Необходимо проверить, является ли этот список циклическим.
Циклическим (кольцевым) списком называется список у которого последний узел ссылается на один из предыдущих узлов.
*/

class Task11 : public Task {
public:
    Task11()
    {
        desc_ = "Determine if linked list is cyclic";
    }
    std::vector<ImplementationResult> runImplementations() override;

    bool hasCycleHashSet(ListNode* head);    // O(N) коллизии(N^2) + mem O(N)
    bool hasCycleFloyd(ListNode* head);      // O(N)
};
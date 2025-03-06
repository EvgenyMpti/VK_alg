#pragma once

#include "task.h"

/*
Дан односвязный список. Необходимо проверить, является ли этот список циклическим.
Циклическим (кольцевым) списком называется список у которого последний узел ссылается на один из предыдущих узлов.
*/

class Task11 : public Task {
public:
    std::vector<ImplementationResult> runImplementations(std::shared_ptr<ListNode> head);
    std::pair<int, std::vector<ImplementationResult>> getStat() override;

    bool hasCycleHashSet(std::shared_ptr<ListNode> head);
    bool hasCycleFloyd(std::shared_ptr<ListNode> head);

    std::shared_ptr<ListNode> createList(const std::vector<int>& values, int cyclePos = -1);
};
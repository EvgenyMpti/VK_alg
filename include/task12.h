#pragma once

#include "task.h"

/*
Необходимо написать функцию, которая принимает на вход односвязный список и разворачивает его.
*/

class Task12 : public Task {
public:
    std::vector<ImplementationResult> runImplementations(ListNodeRaw*);
    std::pair<int, std::vector<ImplementationResult>> getStat() override;

    ListNodeRaw* Task12::reverseList(ListNodeRaw* head); //O(n)
};
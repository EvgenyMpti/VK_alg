#include "task12.h"
#include <forward_list>

std::vector<ImplementationResult> Task12::runImplementations() 
{
    std::vector<int> arr(100000);
    std::iota(arr.begin(), arr.end(), 0);
    ListNode* list = createList(arr);

    std::forward_list<int> fwdList(arr.begin(), arr.end());

    std::vector<ImplementationResult> results;
    results.push_back(runAndMeasure([&]() { reverseList(list); }, "reverse List"));
    results.push_back(runAndMeasure([&]() { fwdList.reverse(); }, "std::reverse"));
    deleteList(list);
    return results;
}

ListNode* Task12::reverseList(ListNode* head) 
{
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* nextNode = nullptr;

    while (current != nullptr) 
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}
#include "task13.h"

std::vector<ImplementationResult> Task13::runImplementations()
{
    std::vector<int> arr(100000);
    std::iota(arr.begin(), arr.end(), 1);
    ListNode* list = createList(arr, -1);

    std::vector<ImplementationResult> results;
    results.push_back(runAndMeasure([&]() { findMiddleTwoPointers(list); }, "Fast and Slow"));
    results.push_back(runAndMeasure([&]() { findMiddleGetLength(list); }, "Length Calculation"));

    deleteList(list);
    return results;
}

ListNode* Task13::findMiddleTwoPointers(ListNode* head) 
{
    if (head == nullptr) {
        return nullptr;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* Task13::findMiddleGetLength(ListNode* head) 
{
    int length = 0;
    ListNode* current = head;

    // Calculate the length of the list.
    while (current != nullptr) 
    {
        length++;
        current = current->next;
    }

    // Find the middle node.
    current = head;
    for (int i = 0; i < length / 2; ++i)
        current = current->next;

    return current;
}
#include <unordered_set>
#include "task11.h"

std::vector<ImplementationResult> Task11::runImplementations()
{
    std::vector<int> arr(10000);
    std::iota(arr.begin(), arr.end(), 1);
    ListNode* list1 = createList(arr, 3000);
    ListNode* list2 = createList(arr, 3000);

    std::vector<ImplementationResult> results;
    results.push_back(runAndMeasure([&]() { hasCycleHashSet(list1); }, "Hash table"));
    results.push_back(runAndMeasure([&]() { hasCycleFloyd(list2); }, "Floyd method"));

    deleteList(list1);
    deleteList(list2);

    return results;
}

// хэш-таблицы
bool Task11::hasCycleHashSet(ListNode* head) 
{
    std::unordered_set<ListNode*> seen;

    ListNode* current = head;
    while (current != nullptr) 
    {
        if (seen.count(current))
            return true;

        seen.insert(current);
        current = current->next;
    }
    return false;
}

// Method Floyd
bool Task11::hasCycleFloyd(ListNode* head) 
{
    if (head == nullptr || head->next == nullptr)
        return false;

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) 
    {
        if (slow == fast)
            return true;

        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}
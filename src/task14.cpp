#include "task14.h"

std::vector<ImplementationResult> Task14::runImplementations()
{
    const int val = 50000;
    std::vector<int> arr(100000);
    std::iota(arr.begin(), arr.end(), 1);
    ListNode* list1 = createList(arr, -1);
    ListNode* list2 = createList(arr, -1);

    std::vector<ImplementationResult> results;
    results.push_back(runAndMeasure([&]() { removeElements1(list1, val); }, "Two pointers"));
    results.push_back(runAndMeasure([&]() { removeElements2(list2, val); }, "One pointer dummy"));

    deleteList(list1);
    deleteList(list2);

    return results;
}

// Итеративный подход с использованием двух указателей
ListNode* Task14::removeElements1(ListNode* head, int val) 
{
    // Обрабатываем случай, когда удаляемые элементы находятся в начале списка
    while (head != nullptr && head->val == val) 
    {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    if (head == nullptr) 
        return nullptr;

    ListNode* prev = head;
    ListNode* curr = head->next;

    while (curr != nullptr) 
    {
        if (curr->val == val) 
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else 
        {
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}

// dummy
ListNode* Task14::removeElements2(ListNode* head, int val) 
{
    ListNode dummy(0);  // Создаем фиктивный узел
    dummy.next = head;
    ListNode* curr = &dummy;

    while (curr->next != nullptr) 
    {
        if (curr->next->val == val) 
        {
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else 
        {
            curr = curr->next;
        }
    }

    return dummy.next;
}

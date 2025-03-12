#pragma once

#include <vector>
#include <string>
#include <chrono>
#include <iostream>
#include <locale>
#include <iomanip>
#include <numeric>
#include <algorithm>

struct Spaces : std::numpunct<char> {
protected:
    char do_thousands_sep() const override { return ' '; }
    std::string do_grouping() const override { return "\3"; }
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct ImplementationResult {
    long long duration; //ns
    std::string name;
};

class Task {
public:
    virtual ~Task() = default;

    virtual std::vector<ImplementationResult> runImplementations() = 0;

    std::string desc_;

    void printStat()
    {
        const auto& results = runImplementations();
        std::locale spaces(std::locale(), new Spaces);
        std::cout.imbue(spaces);
        std::cout << "-------------\nTask" << desc_ << "\n";
        
        for (const auto& res : results)
            std::cout << std::left << std::setw(20) << (res.name + ':') << res.duration << " ns\n";

        std::cout << std::endl;
    }

    template <typename Func>
    ImplementationResult runAndMeasure(Func func, const std::string& name)
    {
        const int cnt = 100;
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < cnt; ++i)
            func();
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        return { duration.count()/ cnt, name };
    }

    // Raw ptr

    void deleteList(ListNode* head) 
    {
        if (!head) 
            return;

        ListNode* slow = head;
        ListNode* fast = head;

        // Detect cycle
        bool hasCycle = false;
        while (fast && fast->next) 
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) 
            {
                hasCycle = true;
                break;
            }
        }

        if (hasCycle) 
        {
            slow = head;
            while (slow != fast) 
            {
                slow = slow->next;
                fast = fast->next;
            }

            ListNode* cycleEnd = slow;
            while (cycleEnd->next != slow) 
                cycleEnd = cycleEnd->next;

            cycleEnd->next = nullptr;
        }

        while (head != nullptr) 
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    std::vector<int> listToVector(ListNode* head) 
    {
        std::vector<int> result;
        ListNode* current = head;
        while (current != nullptr) 
        {
            result.push_back(current->val);
            current = current->next;
        }
        return result;
    }

    ListNode* createList(const std::vector<int>& values, int cyclePos = -1) 
    {
        if (values.empty())
            return nullptr;

        ListNode* head = new ListNode(values[0]);
        ListNode* current = head;
        ListNode* cycleNode = nullptr;

        for (size_t i = 1; i < values.size(); ++i) 
        {
            current->next = new ListNode(values[i]);
            current = current->next;
            if (static_cast<int>(i) == cyclePos)
                cycleNode = current;
        }

        if (cyclePos >= 0) 
        {
            if (cyclePos == 0)
                cycleNode = head;
            current->next = cycleNode;
        }

        return head;
    }
};



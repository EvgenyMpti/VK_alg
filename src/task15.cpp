#include "task15.h"

#include <queue>

std::vector<ImplementationResult> Task15::runImplementations()
{
    const std::string val1 = "axxbyycddzeeffgghhiijj";
    const std::string val2 = "potq314potq3142gsgaxxb2gsgaxxbpotq3142gsgaxxbyycddzeeffgghhiijjj";

    std::vector<ImplementationResult> results;
    results.push_back(runAndMeasure([&]() { isSubsequenceQueue(val1, val2); }, "Queue"));
    results.push_back(runAndMeasure([&]() { isSubsequenceTwoPointers(val1, val2); }, "Two pointers"));
    results.push_back(runAndMeasure([&]() { isSubsequenceIterators(val1, val2); }, "Iterators"));
    results.push_back(runAndMeasure([&]() { isSubsequenceFind(val1, val2); }, "Find"));

    return results;
}

// очередь
bool Task15::isSubsequenceQueue(const std::string& a, const std::string& b) 
{
    std::queue<char> q;
    for (char c : a)
        q.push(c);

    for (char c : b) 
    {
        if (!q.empty() && c == q.front()) 
            q.pop();
    }

    return q.empty();
}

// два указателя
bool Task15::isSubsequenceTwoPointers(const std::string& a, const std::string& b) 
{
    if (a.empty())
        return true;

    if (b.empty())
        return false;

    int i = 0;
    int j = 0;

    while (j < b.length()) 
    {  // Одного условия достаточно
        if (a[i] == b[j]) 
        {
            i++;
            if (i == a.length()) // Проверяем, достигли ли конца a
                return true;
        }
        j++;
    }
    return false;
}

// итераторы
bool Task15::isSubsequenceIterators(const std::string& a, const std::string& b) 
{
    auto it_a = a.begin();
    auto it_b = b.begin();

    while (it_a != a.end() && it_b != b.end()) 
    {
        if (*it_a == *it_b)
            ++it_a;
        ++it_b;
    }

    return it_a == a.end();
}

// find
bool Task15::isSubsequenceFind(const std::string& a, const std::string& b) 
{
    size_t pos = 0;
    for (char c : a) 
    {
        pos = b.find(c, pos);
        if (pos == std::string::npos)
            return false;

        pos++; // Смещаемся на следующий символ
    }
    return true;
}

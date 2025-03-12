#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

#include "task2.h"

std::vector<ImplementationResult> Task2::runImplementations()
{
    const int target = 15890;
    std::vector<int> nums(100000);
    std::iota(nums.begin(), nums.end(), 1);

    std::vector<ImplementationResult> results;
    results.push_back(runAndMeasure([&]() { twoPointers(nums, target); }, "SumTwoPointers"));
    results.push_back(runAndMeasure([&]() { hashTable(nums, target); }, "HashTable"));
    results.push_back(runAndMeasure([&]() { binarySearch(nums, target); }, "BinarySearch"));
    results.push_back(runAndMeasure([&]() { bruteForce(nums, target); }, "BruteForce"));

    return results;
}

Task2::TwoSumResult Task2::twoPointers(const std::vector<int>& nums, int target) 
{
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) 
    {
        int currentSum = nums[left] + nums[right];

        if (currentSum == target)
            return { true, left, right };
        else if (currentSum < target)
            left++;
        else
            right--;
    }

    return { false, -1, -1 };
}

Task2::TwoSumResult Task2::hashTable(const std::vector<int>& nums, int target) 
{
    std::unordered_map<int, int> numMap; // <число, индекс>

    for (int i = 0; i < nums.size(); ++i) 
    {
        int complement = target - nums[i];
        if (numMap.count(complement))
            return { true, numMap[complement], i };

        numMap[nums[i]] = i;
    }

    return { false, -1, -1 };
}

Task2::TwoSumResult Task2::binarySearch(const std::vector<int>& nums, int target)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        int complement = target - nums[i];
        // Ищем complement в оставшейся части массива (от i + 1 до конца)
        auto it = std::lower_bound(nums.begin() + i + 1, nums.end(), complement);

        if (it != nums.end() && *it == complement)
            return { true, i, static_cast<int>(it - nums.begin()) };
    }
    return { false, -1, -1 };
}

Task2::TwoSumResult Task2::bruteForce(const std::vector<int>& nums, int target)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = i + 1; j < nums.size(); ++j)
        {
            int currentSum = nums[i] + nums[j];
            if (currentSum == target)
                return { true, i, j };
            else if (currentSum > target)
                break;
        }
    }
    return { false, -1, -1 };
}

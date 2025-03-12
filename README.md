#VK alg
```
[==========] Running 17 tests from 17 test suites.
[----------] Global test environment set-up.
[----------] 1 test from Task1Test
[ RUN      ] Task1Test.AllImplementations
[       OK ] Task1Test.AllImplementations (6 ms)
[----------] 1 test from Task1Test (6 ms total)

[----------] 1 test from Task10Test
[ RUN      ] Task10Test.AllImplementations
[       OK ] Task10Test.AllImplementations (0 ms)
[----------] 1 test from Task10Test (0 ms total)

[----------] 1 test from Task11Test
[ RUN      ] Task11Test.AllImplementations
[       OK ] Task11Test.AllImplementations (0 ms)
[----------] 1 test from Task11Test (0 ms total)

[----------] 1 test from Task12Test
[ RUN      ] Task12Test.AllImplementations
[       OK ] Task12Test.AllImplementations (0 ms)
[----------] 1 test from Task12Test (0 ms total)

[----------] 1 test from Task13Test
[ RUN      ] Task13Test.AllImplementations
[       OK ] Task13Test.AllImplementations (0 ms)
[----------] 1 test from Task13Test (0 ms total)

[----------] 1 test from Task14Test
[ RUN      ] Task14Test.AllImplementations
[       OK ] Task14Test.AllImplementations (0 ms)
[----------] 1 test from Task14Test (0 ms total)

[----------] 1 test from Task15Test
[ RUN      ] Task15Test.AllImplementations
[       OK ] Task15Test.AllImplementations (0 ms)
[----------] 1 test from Task15Test (1 ms total)

[----------] 1 test from Task16Test
[ RUN      ] Task16Test.AllImplementations
[       OK ] Task16Test.AllImplementations (0 ms)
[----------] 1 test from Task16Test (1 ms total)

[----------] 1 test from Task17Test
[ RUN      ] Task17Test.AllImplementations
[       OK ] Task17Test.AllImplementations (0 ms)
[----------] 1 test from Task17Test (1 ms total)

[----------] 1 test from Task2Test
[ RUN      ] Task2Test.AllImplementations
[       OK ] Task2Test.AllImplementations (0 ms)
[----------] 1 test from Task2Test (1 ms total)

[----------] 1 test from Task3Test
[ RUN      ] Task3Test.AllImplementations
[       OK ] Task3Test.AllImplementations (0 ms)
[----------] 1 test from Task3Test (1 ms total)

[----------] 1 test from Task4Test
[ RUN      ] Task4Test.AllImplementations
[       OK ] Task4Test.AllImplementations (0 ms)
[----------] 1 test from Task4Test (1 ms total)

[----------] 1 test from Task5Test
[ RUN      ] Task5Test.AllImplementations
[       OK ] Task5Test.AllImplementations (0 ms)
[----------] 1 test from Task5Test (0 ms total)

[----------] 1 test from Task6Test
[ RUN      ] Task6Test.AllImplementations
[       OK ] Task6Test.AllImplementations (0 ms)
[----------] 1 test from Task6Test (3 ms total)

[----------] 1 test from Task7Test
[ RUN      ] Task7Test.AllImplementations
[       OK ] Task7Test.AllImplementations (0 ms)
[----------] 1 test from Task7Test (1 ms total)

[----------] 1 test from Task8Test
[ RUN      ] Task8Test.AllImplementations
[       OK ] Task8Test.AllImplementations (0 ms)
[----------] 1 test from Task8Test (1 ms total)

[----------] 1 test from Task9Test
[ RUN      ] Task9Test.AllImplementations
[       OK ] Task9Test.AllImplementations (0 ms)
[----------] 1 test from Task9Test (1 ms total)

[----------] Global test environment tear-down
[==========] 17 tests from 17 test suites ran. (59 ms total)
[  PASSED  ] 17 tests.
-------------
TaskSum of all numbers
Iterative:          859 986 ns
Progression:        4 ns
std::accumulate:    7 183 015 ns
Iterative half:     1 070 134 ns

-------------
TaskFind indices summing to target value
SumTwoPointers:     566 251 ns
HashTable:          4 738 525 ns
BinarySearch:       820 ns
BruteForce:         113 163 ns

-------------
TaskReverse array without allocations
Swap:               488 752 ns
Iter Swap:          1 903 510 ns
std::reverse:       36 592 ns

-------------
TaskLeft-rotate array segment in linear time
std::rotate:        80 943 ns
Three move:         77 765 ns
While swap:         1 847 759 ns

-------------
TaskMerge two sorted arrays into new one
Two Pointers:       892 220 ns
Merge With Sort:    3 764 211 ns
n Insertion:        15 226 072 ns

-------------
TaskMerge two sorted arrays in-place
merge Arrays:       2 843 783 ns
merge & sort:       34 271 135 ns

-------------
TaskSort 0 and 1 in-place
Two side:           390 642 ns
Counting:           849 391 ns
One side:           676 804 ns
Partition:          303 306 ns

-------------
TaskSort 0,1 and 2 in-place
Three ptr:          2 560 110 ns
Counting:           730 150 ns
Partition:          564 851 ns

-------------
TaskMove even numbers to front, preserving order
Stable Partition:   326 575 ns
Two Pointers:       883 168 ns
Two Pointers fast:  4 141 208 ns

-------------
TaskMove zeros to end of array
Stable Partition:   353 095 ns
Two Pointers:       749 307 ns
Shift move:         541 334 ns

-------------
TaskDetermine if linked list is cyclic
Hash table:         11 169 452 ns
Floyd method:       80 252 ns

-------------
Taskreverse Forward List
reverse List:       34 722 ns
std::reverse:       2 200 559 ns

-------------
TaskFind linked list middle in O(n)
Fast and Slow:      1 910 732 ns
Length Calculation: 3 128 620 ns

-------------
TaskDelete linked list node matching value
Two pointers:       2 110 762 ns
One pointer dummy:  1 755 146 ns

-------------
TaskCheck subsequence string, queue, two pointers
Queue:              7 420 ns
Two pointers:       1 172 ns
Iterators:          15 966 ns
Find:               352 ns

-------------
TaskDetermine if string is palindrome: bool
Stack:              9 153 ns
Deque:              9 184 ns
Two pointers:       294 ns
stl equal:          1 271 ns

-------------
TaskMerge two sorted lists, Memory - O(1)
merge Two Lists:    409 485 ns
```

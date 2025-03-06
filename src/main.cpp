#include <vector>
#include <memory>

#include <gtest/gtest.h>

#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"
#include "task6.h"
#include "task7.h"
#include "task8.h"
#include "task9.h"
#include "task10.h"
#include "task11.h"
#include "task12.h"
#include "task17.h"

int main()
{
    ::testing::InitGoogleTest();
    if (RUN_ALL_TESTS())
        return 1;

    Task1().printStat();
    Task2().printStat();
    Task3().printStat();
    Task4().printStat();
    Task5().printStat();
    Task6().printStat();
    Task7().printStat();
    Task8().printStat();
    Task9().printStat();
    Task10().printStat();
    Task11().printStat();
    Task12().printStat();
    Task17().printStat();

    return 0;
}

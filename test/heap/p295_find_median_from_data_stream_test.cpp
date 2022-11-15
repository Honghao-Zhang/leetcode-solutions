#include "heap/heap.h"
#include <gtest/gtest.h>

using namespace heap;

TEST(FindeMedian, example_1)
{
    MedianFinder *obj = new MedianFinder();
    obj->addNum_1(2);
    EXPECT_DOUBLE_EQ(2.0, obj->findMedian_1());
    obj->addNum_1(3);
    EXPECT_DOUBLE_EQ(2.5, obj->findMedian_1());
}

TEST(FindeMedian, example_2)
{
    MedianFinder *obj = new MedianFinder();
    obj->addNum_1(1);
    obj->addNum_1(2);
    EXPECT_DOUBLE_EQ(1.5, obj->findMedian_1());
    obj->addNum_1(3);
    EXPECT_DOUBLE_EQ(2.0, obj->findMedian_1());
}
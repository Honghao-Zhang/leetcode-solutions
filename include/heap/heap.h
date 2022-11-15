#ifndef MY_SOLUTIONS_HEAP_H
#define MY_SOLUTIONS_HEAP_H

#include <set>
#include <iterator>
#include <queue>
#include <iostream>

namespace heap
{
    class MedianFinder
    {
    private:
        // member for solution 1: using multiset
        std::multiset<int> mySet;
        std::multiset<int>::iterator median_itr;
        // member for solution 2: using minHeap and maxHeap
        std::priority_queue<int> smaller_half_max_heap;
        std::priority_queue<int, std::vector<int>, std::greater<int>> bigger_half_min_heap;

    public:
        MedianFinder()
        {
            // median_itr = std::begin(mySet);
            //  begin() can only be used after container is initialized
            // otherwise, begin() will return 1
        }
        // member function for solution 1 with multiset
        void addNum(int num)
        {
            mySet.insert(num);
            if (mySet.size() == 1)
                median_itr = mySet.begin();
            if (mySet.size() % 2 == 0)
                median_itr++;
        }

        double findMedian()
        {
            if (mySet.size() % 2 == 0)
            {
                int second = *median_itr;
                int first = *std::prev(median_itr);
                return static_cast<double>(first + second) / 2.0;
            }
            else
                return static_cast<double>(*median_itr);
        }
        // member function for solution with maxHeap and minHeap
        void addNum_1(int num)
        {
            if (smaller_half_max_heap.empty() && bigger_half_min_heap.empty())
                bigger_half_min_heap.push(num);
            else
            {
                if (num > bigger_half_min_heap.top())
                {
                    bigger_half_min_heap.push(num);
                    if (bigger_half_min_heap.size() > smaller_half_max_heap.size() + 1)
                    {
                        smaller_half_max_heap.push(bigger_half_min_heap.top());
                        bigger_half_min_heap.pop();
                    }
                }
                else
                {
                    smaller_half_max_heap.push(num);
                    if (smaller_half_max_heap.size() > bigger_half_min_heap.size())
                    {
                        bigger_half_min_heap.push(smaller_half_max_heap.top());
                        smaller_half_max_heap.pop();
                    }
                }
            }
        }
        double findMedian_1()
        {
            if (bigger_half_min_heap.size() == smaller_half_max_heap.size())
                return (bigger_half_min_heap.top() + smaller_half_max_heap.top()) / 2.0;
            else
                return bigger_half_min_heap.top();
        }
    };
    class Solution
    {
    public:
        void maxHeap();
    };
};
#endif
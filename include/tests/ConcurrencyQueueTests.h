#include <iostream>
#include <thread>
#include <vector>
#include <stack>
#include <atomic>
#include "custom_data_structures/ThreadSafeQueue.h"

using namespace std;

/**
* Tests concurrent push operations on the queue.
*
* Pre-fills the queue and launches two threads that simultaneously push elements.
* Verifies that the queue handles concurrent insertions correctly.
*
* @tparam QueueType The type of the queue to test, it must be either
*         std::queue<int> or ThreadSafeQueue<int>.
*/
template <typename QueueType>
void testQueueConcurrentPush()
{
    static_assert(
        is_same<QueueType, queue<int>>::value ||
            is_same<QueueType, ThreadSafeQueue<int>>::value,
        "For this test QueueType must be either queue<int> or ThreadSafeQueue<int>");
    cout << "Concurrent push test started\n";

    QueueType queue;
    auto worker = [&]()
    {
        for (int i = 0; i < 100000; ++i)
        {
            queue.push(i);
        }
    };
    thread t1(worker), t2(worker);
    t1.join();
    t2.join();
    cout << "Concurrent push finished successfully, size=" << queue.size() << "\n";
}

/**
* Tests concurrent pop operations on the queue.
*
* Pre-fills the queue and launches two threads that simultaneously pop elements.
* Verifies that the queue handles concurrent removals correctly.
*
* @tparam QueueType The type of the queue to test, it must be either
*         std::queue<int> or ThreadSafeQueue<int>.
*/
template <typename QueueType>
void testQueueConcurrentPop()
{
    static_assert(
        is_same<QueueType, queue<int>>::value ||
            is_same<QueueType, ThreadSafeQueue<int>>::value,
        "For this test QueueType must be either queue<int> or ThreadSafeQueue<int>");
    cout << "Concurrent pop test started\n";

    QueueType queue;
    for (int i = 0; i < 200000; ++i)
    {
        queue.push(i);
    }

    auto worker = [&]()
    {
        for (int i = 0; i < 100000; ++i)
        {
            queue.pop();
        }
    };
    thread t1(worker), t2(worker);
    t1.join();
    t2.join();
    cout << "Concurrent pop finished successfully, queue size=" << queue.size() << "\n";
}

/**
* Tests concurrent front operations on the queue.
*
* Pre-fills the queue and launches two threads that simultaneously access the front element.
* Verifies that the queue handles concurrent front accesses correctly.
*
* @tparam QueueType The type of the queue to test, it must be either
*         std::queue<int> or ThreadSafeQueue<int>.
*/
template <typename QueueType>
void testQueueConcurrentFront()
{
    static_assert(
        is_same<QueueType, queue<int>>::value ||
            is_same<QueueType, ThreadSafeQueue<int>>::value,
        "For this test QueueType must be either queue<int> or ThreadSafeQueue<int>");
    cout << "Concurrent front test started\n";

    QueueType queue;
    queue.push(42);

    auto worker = [&]()
    {
        for (int i = 0; i < 100000; ++i)
        {
            auto tmp = queue.front();
        }
    };
    thread t1(worker), t2(worker);
    t1.join();
    t2.join();
    cout << "Concurrent front finished successfully \n";
}

/**
* Test concurrent back operation on the queue.
*
* Pre-fills the queue and launches two threads that simultaneously access the back element.
* Verifies that the queue handles concurrent back accesses correctly.
*
* @tparam QueueType The type of the queue to test, it must be either
*         std::queue<int> or ThreadSafeQueue<int>.
*/
template <typename QueueType>
void testQueueConcurrentBack()
{
    static_assert(
        is_same<QueueType, queue<int>>::value ||
            is_same<QueueType, ThreadSafeQueue<int>>::value,
        "For this test QueueType must be either queue<int> or ThreadSafeQueue<int>");
    cout << "Concurrent back test started\n";

    QueueType queue;
    queue.push(42);

    auto worker = [&]()
    {
        for (int i = 0; i < 100000; ++i)
        {
            auto tmp = queue.back();
        }
    };
    thread t1(worker), t2(worker);
    t1.join();
    t2.join();
    cout << "Concurrent back finished successfully \n";
}

/**
* Tests concurrent empty operations on the queue.
*
* Pre-fills the queue and launches two threads that simultaneously access the empty state.
* Verifies that the queue handles concurrent empty checks correctly.
*
* @tparam QueueType The type of the queue to test, it must be either
*         std::queue<int> or ThreadSafeQueue<int>.
*/
template <typename QueueType>
void testQueueConcurrentEmpty()
{
    static_assert(
        is_same<QueueType, queue<int>>::value ||
            is_same<QueueType, ThreadSafeQueue<int>>::value,
        "For this test QueueType must be either queue<int> or ThreadSafeQueue<int>");
    cout << "Concurrent empty test started\n";

    QueueType queue;
    queue.push(42);

    auto worker = [&]()
    {
        for (int i = 0; i < 100000; ++i)
        {
            auto tmp = queue.empty();
        }
    };
    thread t1(worker), t2(worker);
    t1.join();
    t2.join();
    cout << "Concurrent empty finished successfully\n";
}

/**
* Tests concurrent size operations on the queue.
*
* Pre-fills the queue and launches two threads that simultaneously access the size.
* Verifies that the queue handles concurrent size accesses correctly.
*
* @tparam QueueType The type of the queue to test, it must be either
*         std::queue<int> or ThreadSafeQueue<int>.
*/
template <typename QueueType>
void testQueueConcurrentSize()
{
    static_assert(
        is_same<QueueType, queue<int>>::value ||
            is_same<QueueType, ThreadSafeQueue<int>>::value,
        "For this test QueueType must be either queue<int> or ThreadSafeQueue<int>");
    cout << "Concurrent size test started\n";

    QueueType queue;
    queue.push(42);

    auto worker = [&]()
    {
        for (int i = 0; i < 100000; ++i)
        {
            auto tmp = queue.size();
        }
    };
    thread t1(worker), t2(worker);
    t1.join();
    t2.join();
    cout << "Concurrent size finished successfully \n";
}

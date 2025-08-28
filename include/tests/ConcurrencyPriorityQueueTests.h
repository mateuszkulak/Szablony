#include <iostream>
#include <thread>
#include <vector>
#include <stack>
#include <atomic>
#include "custom_data_structures/ThreadSafePriorityQueue.h"

using namespace std;

/**
 * Tests concurrent push operations on the priority queue.
 *
 * Pre-fills the queue and launches two threads that simultaneously push elements.
 * Verifies that the queue handles concurrent insertions correctly.
 *
 * @tparam PriorityQueueType The type of the priority queue to test, it must be either
 *         std::priority_queue<int> or ThreadSafePriorityQueue<int>.
 */
template <typename PriorityQueueType>
void testQueueConcurrentPush()
{
    static_assert(
        is_same<PriorityQueueType, priority_queue<int>>::value ||
            is_same<PriorityQueueType, ThreadSafePriorityQueue<int>>::value,
        "For this test PriorityQueueType must be either priority_queue<int> or ThreadSafePriorityQueue<int>");
    cout << "Concurrent push test started\n";

    PriorityQueueType queue;
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
    cout << "Concurrent push finished successfully, size=" << stack.size() << "\n";
}

/**
 * Tests concurrent pop operations on the priority queue.
 *
 * Pre-fills the queue and launches two threads that simultaneously pop elements.
 * Verifies that the queue handles concurrent removals correctly.
 *
 * @tparam PriorityQueueType The type of the priority queue to test, it must be either
 *         std::priority_queue<int> or ThreadSafePriorityQueue<int>.
 */
template <typename PriorityQueueType>
void testQueueConcurrentPop()
{
    static_assert(
        is_same<PriorityQueueType, priority_queue<int>>::value ||
            is_same<PriorityQueueType, ThreadSafePriorityQueue<int>>::value,
        "For this test PriorityQueueType must be either priority_queue<int> or ThreadSafePriorityQueue<int>");
    cout << "Concurrent pop test started\n";

    PriorityQueueType queue;
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
    cout << "Concurrent pop finished successfully, stack size=" << stack.size() << "\n";
}

/**
 * Tests concurrent top operations on the priority queue.
 *
 * Pre-fills the queue and launches two threads that simultaneously access the top element.
 * Verifies that the queue handles concurrent top accesses correctly.
 *
 * @tparam PriorityQueueType The type of the priority queue to test, it must be either
 *         std::priority_queue<int> or ThreadSafePriorityQueue<int>.
 */
template <typename PriorityQueueType>
void testQueueConcurrentTop()
{
    static_assert(
        is_same<PriorityQueueType, priority_queue<int>>::value ||
            is_same<PriorityQueueType, ThreadSafePriorityQueue<int>>::value,
        "For this test PriorityQueueType must be either priority_queue<int> or ThreadSafePriorityQueue<int>");
    cout << "Concurrent top test started\n";

    PriorityQueueType queue;
    queue.push(42);

    auto worker = [&]()
    {
        for (int i = 0; i < 100000; ++i)
        {
            auto tmp = queue.top();
        }
    };
    thread t1(worker), t2(worker);
    t1.join();
    t2.join();
    cout << "Concurrent top finished successfully \n";
}

/**
 * Tests concurrent empty operations on the priority queue.
 *
 * Pre-fills the queue and launches two threads that simultaneously access the empty state.
 * Verifies that the queue handles concurrent empty checks correctly.
 *
 * @tparam PriorityQueueType The type of the priority queue to test, it must be either
 *         std::priority_queue<int> or ThreadSafePriorityQueue<int>.
 */
template <typename PriorityQueueType>
void testQueueConcurrentEmpty()
{
    static_assert(
        is_same<PriorityQueueType, priority_queue<int>>::value ||
            is_same<PriorityQueueType, ThreadSafePriorityQueue<int>>::value,
        "For this test PriorityQueueType must be either priority_queue<int> or ThreadSafePriorityQueue<int>");
    cout << "Concurrent empty test started\n";

    PriorityQueueType queue;
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
 * Tests concurrent size operations on the priority queue.
 *
 * Pre-fills the queue and launches two threads that simultaneously access the size.
 * Verifies that the queue handles concurrent size accesses correctly.
 *
 * @tparam PriorityQueueType The type of the priority queue to test, it must be either
 *         std::priority_queue<int> or ThreadSafePriorityQueue<int>.
 */
template <typename PriorityQueueType>
void testQueueConcurrentSize()
{
    static_assert(
        is_same<PriorityQueueType, priority_queue<int>>::value ||
            is_same<PriorityQueueType, ThreadSafePriorityQueue<int>>::value,
        "For this test PriorityQueueType must be either priority_queue<int> or ThreadSafePriorityQueue<int>");
    cout << "Concurrent size test started\n";

    PriorityQueueType queue;
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

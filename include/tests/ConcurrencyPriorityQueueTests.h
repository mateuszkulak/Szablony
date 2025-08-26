#include <iostream>
#include <thread>
#include <vector>
#include <stack>
#include <atomic>
#include "custom_data_structures/ThreadSafePriorityQueue.h"

using namespace std;

template <typename PriorityQueueType>
void testQueueConcurrentPush() {
    static_assert(
        is_same<PriorityQueueType, priority_queue<int>>::value ||
        is_same<PriorityQueueType, ThreadSafePriorityQueue<int>>::value,
        "For this test PriorityQueueType must be either priority_queue<int> or ThreadSafePriorityQueue<int>"
    );
    cout << "Concurrent push test started\n";

    PriorityQueueType queue;
    auto worker = [&]() {
        for (int i = 0; i < 100000; ++i) {
            queue.push(i);
        }
    };
    thread t1(worker), t2(worker);
    t1.join(); 
    t2.join();
    cout << "Concurrent push finished successfully, size=" << stack.size() << "\n";
}

template <typename PriorityQueueType>
void testQueueConcurrentPop() {
    static_assert(
        is_same<PriorityQueueType, priority_queue<int>>::value ||
        is_same<PriorityQueueType, ThreadSafePriorityQueue<int>>::value,
        "For this test PriorityQueueType must be either priority_queue<int> or ThreadSafePriorityQueue<int>"
    );
    cout << "Concurrent pop test started\n";

    PriorityQueueType queue;
    for (int i = 0; i < 200000; ++i) {
        queue.push(i);
    }

    auto worker = [&]() {
        for (int i = 0; i < 100000; ++i) {
            queue.pop();
        }
    };
    thread t1(worker), t2(worker);
    t1.join();
    t2.join();
    cout << "Concurrent pop finished successfully, stack size=" << stack.size() << "\n";
}

template <typename PriorityQueueType>
void testQueueConcurrentFront() {
    static_assert(
        is_same<PriorityQueueType, priority_queue<int>>::value ||
        is_same<PriorityQueueType, ThreadSafePriorityQueue<int>>::value,
        "For this test PriorityQueueType must be either priority_queue<int> or ThreadSafePriorityQueue<int>"
    );
    cout << "Concurrent front test started\n";

    PriorityQueueType queue;
    queue.push(42);

    auto worker = [&]() {
        for (int i = 0; i < 100000; ++i) {
            auto tmp = queue.front();
        }
    };
    thread t1(worker), t2(worker);
    t1.join();
    t2.join();
    cout << "Concurrent front finished successfully \n";
}

template <typename PriorityQueueType>
void testQueueConcurrentSize() {
    static_assert(
        is_same<PriorityQueueType, priority_queue<int>>::value ||
        is_same<PriorityQueueType, ThreadSafePriorityQueue<int>>::value,
        "For this test PriorityQueueType must be either priority_queue<int> or ThreadSafePriorityQueue<int>"
    );
    cout << "Concurrent size test started\n";

    PriorityQueueType queue;
    queue.push(42);

    auto worker = [&]() {
        for (int i = 0; i < 100000; ++i) {
            auto tmp = queue.size();
        }
    };
    thread t1(worker), t2(worker);
    t1.join();
    t2.join();
    cout << "Concurrent size finished successfully \n";
}

template <typename PriorityQueueType>
void testQueueConcurrentEmpty() {
    static_assert(
        is_same<PriorityQueueType, priority_queue<int>>::value ||
        is_same<PriorityQueueType, ThreadSafePriorityQueue<int>>::value,
        "For this test PriorityQueueType must be either priority_queue<int> or ThreadSafePriorityQueue<int>"
    );
    cout << "Concurrent empty test started\n";

    PriorityQueueType queue;
    queue.push(42);

    auto worker = [&]() {
        for (int i = 0; i < 100000; ++i) {
            auto tmp = queue.empty();
        }
    };
    thread t1(worker), t2(worker);
    t1.join();
    t2.join();
    cout << "Concurrent empty finished successfully\n";
}

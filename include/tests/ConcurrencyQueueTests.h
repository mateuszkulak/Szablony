#include <iostream>
#include <thread>
#include <vector>
#include <stack>
#include <atomic>
#include "custom_data_structures/ThreadSafeQueue.h"

using namespace std;

template <typename QueueType>
void testQueueConcurrentPush() {
    static_assert(
        is_same<QueueType, queue<int>>::value ||
        is_same<QueueType, ThreadSafeQueue<int>>::value,
        "For this test QueueType must be either queue<int> or ThreadSafeQueue<int>"
    );
    cout << "Concurrent push test started\n";

    QueueType queue;
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

template <typename QueueType>
void testQueueConcurrentPop() {
    static_assert(
        is_same<QueueType, queue<int>>::value ||
        is_same<QueueType, ThreadSafeQueue<int>>::value,
        "For this test QueueType must be either queue<int> or ThreadSafeQueue<int>"
    );
    cout << "Concurrent pop test started\n";

    QueueType queue;
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

template <typename QueueType>
void testQueueConcurrentFront() {
    static_assert(
        is_same<QueueType, queue<int>>::value ||
        is_same<QueueType, ThreadSafeQueue<int>>::value,
        "For this test QueueType must be either queue<int> or ThreadSafeQueue<int>"
    );
    cout << "Concurrent front test started\n";

    QueueType queue;
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

template <typename QueueType>
void testQueueConcurrentSize() {
    static_assert(
        is_same<QueueType, queue<int>>::value ||
        is_same<QueueType, ThreadSafeQueue<int>>::value,
        "For this test QueueType must be either queue<int> or ThreadSafeQueue<int>"
    );
    cout << "Concurrent size test started\n";

    QueueType queue;
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

template <typename QueueType>
void testQueueConcurrentEmpty() {
    static_assert(
        is_same<QueueType, queue<int>>::value ||
        is_same<QueueType, ThreadSafeQueue<int>>::value,
        "For this test QueueType must be either queue<int> or ThreadSafeQueue<int>"
    );
    cout << "Concurrent empty test started\n";

    QueueType queue;
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

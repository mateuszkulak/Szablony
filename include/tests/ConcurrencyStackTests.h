#include <iostream>
#include <thread>
#include <vector>
#include <stack>
#include <atomic>
#include "custom_data_structures/ThreadSafeStack.h"

using namespace std;

template <typename StackType>
void testStackConcurrentPush() {
    static_assert(
        is_same<StackType, stack<int>>::value ||
        is_same<StackType, ThreadSafeStack<int>>::value,
        "For this test StackType must be either stack<int> or ThreadSafeStack<int>"
    );
    cout << "Concurrent push test started\n";

    StackType stack;
    auto worker = [&]() {
        for (int i = 0; i < 100000; ++i) {
            stack.push(i);
        }
    };
    thread t1(worker), t2(worker);
    t1.join(); 
    t2.join();
    cout << "Concurrent push finished successfully, size=" << stack.size() << "\n";
}

template <typename StackType>
void testStackConcurrentPop() {
    static_assert(
        is_same<StackType, stack<int>>::value ||
        is_same<StackType, ThreadSafeStack<int>>::value,
        "For this test StackType must be either stack<int> or ThreadSafeStack<int>"
    );
    cout << "Concurrent pop test started\n";

    StackType stack;
    for (int i = 0; i < 200000; ++i) {
        stack.push(i);
    }

    auto worker = [&]() {
        for (int i = 0; i < 100000; ++i) {
            stack.pop();
        }
    };
    thread t1(worker), t2(worker);
    t1.join();
    t2.join();
    cout << "Concurrent pop finished successfully, stack size=" << stack.size() << "\n";
}

template <typename StackType>
void testStackConcurrentTop() {
    static_assert(
        is_same<StackType, stack<int>>::value ||
        is_same<StackType, ThreadSafeStack<int>>::value,
        "For this test StackType must be either stack<int> or ThreadSafeStack<int>"
    );
    cout << "Concurrent top test started\n";

    StackType stack;
    stack.push(42);

    auto worker = [&]() {
        for (int i = 0; i < 100000; ++i) {
            auto tmp = stack.top();
        }
    };
    thread t1(worker), t2(worker);
    t1.join();
    t2.join();
    cout << "Concurrent top finished successfully \n";
}

template <typename StackType>
void testStackConcurrentSize() {
    static_assert(
        is_same<StackType, stack<int>>::value ||
        is_same<StackType, ThreadSafeStack<int>>::value,
        "For this test StackType must be either stack<int> or ThreadSafeStack<int>"
    );
    cout << "Concurrent size test started\n";

    StackType stack;
    stack.push(42);

    auto worker = [&]() {
        for (int i = 0; i < 100000; ++i) {
            auto tmp = stack.size();
        }
    };
    thread t1(worker), t2(worker);
    t1.join();
    t2.join();
    cout << "Concurrent size finished successfully \n";
}

template <typename StackType>
void testStackConcurrentEmpty() {
    static_assert(
        is_same<StackType, stack<int>>::value ||
        is_same<StackType, ThreadSafeStack<int>>::value,
        "For this test StackType must be either stack<int> or ThreadSafeStack<int>"
    );
    cout << "Concurrent empty test started\n";

    StackType stack;
    stack.push(42);

    auto worker = [&]() {
        for (int i = 0; i < 100000; ++i) {
            auto tmp =stack.empty();
        }
    };
    thread t1(worker), t2(worker);
    t1.join();
    t2.join();
    cout << "Concurrent empty finished successfully\n";
}

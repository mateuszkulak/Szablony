#pragma once
#include <mutex>
#include <vector>
#include <stdexcept>

template<typename T> class ThreadSafeStack {
private:
    std::vector<T> stack;
    mutable std::mutex mutex;
    bool isEmptyFlag = true;

public:
    ThreadSafeStack() = default;

    void push(const T& element) {
        mutex.lock();
        stack.push_back(element);
        isEmptyFlag = false;
        mutex.unlock();
    }

    T pop() {
        if(isEmptyFlag) {
            throw runtime_error("Stack is empty");
        }
        mutex.lock();
        T element = stack.back();
        stack.pop_back();
        isEmptyFlag = stack.empty();
        mutex.unlock();
        return element;
    }

    T& top() {
        if(isEmptyFlag) {
            throw runtime_error("Stack is empty");
        }
        mutex.lock();
        T& element = stack.back();
        mutex.unlock();
        return element;
    }

    bool empty() const {
        mutex.lock();
        bool empty = isEmptyFlag;
        mutex.unlock();
        return empty;
    }

    int size() const {
        mutex.lock();
        int size = stack.size();
        mutex.unlock();
        return size;
    }
};
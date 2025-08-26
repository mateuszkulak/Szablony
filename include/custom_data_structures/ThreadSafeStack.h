#pragma once
#include <mutex>
#include <vector>
#include <stdexcept>

using namespace std;

template<typename T> class ThreadSafeStack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d, Node* n = nullptr) : data(d), next(n) {}
    };
    
    mutable std::mutex mutex;
    Node* head = nullptr;
    bool isEmptyFlag = true;
    int stackSize = 0;

public:
    ThreadSafeStack() = default;
    ~ThreadSafeStack() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(const T& element) {
        mutex.lock();
        head = new Node(element, head);
        isEmptyFlag = false;
        stackSize++;
        mutex.unlock();
    }

    T pop() {
        if(isEmptyFlag) {
            throw runtime_error("Stack is empty");
        }
        mutex.lock();
        Node* temp = head;
        head = head->next;
        T element = temp->data;
        delete temp;
        isEmptyFlag = (head == nullptr);
        mutex.unlock();
        return element;
    }

    T& top() {
        if(isEmptyFlag) {
            throw runtime_error("Stack is empty");
        }
        mutex.lock();
        T& element = head->data;
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
        int size = stackSize;
        mutex.unlock();
        return size;
    }
};
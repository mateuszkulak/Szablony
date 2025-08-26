#pragma once
#include <mutex>
#include <stdexcept>

using namespace std;

template<typename T>
class ThreadSafeQueue {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& d) : data(d), prev(nullptr), next(nullptr) {}
    };

    mutable std::mutex mutex;
    Node* head = nullptr;
    Node* tail = nullptr;
    bool isEmptyFlag = true;
    int queueSize = 0;

public:
    ThreadSafeQueue() = default;
    ~ThreadSafeQueue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(const T& element) {
        mutex.lock();
        Node* newNode = new Node(element);

        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        isEmptyFlag = false;
        queueSize++;
        mutex.unlock();
    }

    T pop() {
        if (isEmptyFlag) {
            throw runtime_error("Queue is empty");
        }

        mutex.lock();

        Node* temp = head;
        T element = temp->data;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        queueSize--;
        isEmptyFlag = (head == nullptr);

        mutex.unlock();
        
        return element;
    }

    T& front() {
        if (isEmptyFlag) {
            throw runtime_error("Queue is empty");
        }
        mutex.lock();
        T& element = head->data;
        mutex.unlock();
        return element;
    }

    T& back() {
        if (isEmptyFlag) {
            throw runtime_error("Queue is empty");
        }
        mutex.lock();
        T& element = tail->data;
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
        int size = queueSize;
        mutex.unlock();
        return size;
    }
};

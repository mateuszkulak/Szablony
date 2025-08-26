#pragma once
#include <mutex>
#include <stdexcept>

using namespace std;

template<typename T, typename Compare = std::greater<T>>
class ThreadSafePriorityQueue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };

    mutable std::mutex mutex;
    Node* head = nullptr;
    bool isEmptyFlag = true;
    int queueSize = 0;

public:
    ThreadSafePriorityQueue() = default;
    ~ThreadSafePriorityQueue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(const T& element) {
        mutex.lock();
        Node* newNode = new Node(element);

        if (!head || !Compare()(newNode->data, head->data)) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && !Compare()(newNode->data, current->next->data)) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

        isEmptyFlag = false;
        queueSize++;
        mutex.unlock();
    }

    T pop() {
        if (isEmptyFlag) {
            throw runtime_error("Priority queue is empty");
        }

        mutex.lock();

        Node* temp = head;
        T element = temp->data;
        head = head->next;
        delete temp;
        queueSize--;
        isEmptyFlag = (queueSize == 0);

        mutex.unlock();

        return element;
    }

    T& top() {
        if (isEmptyFlag) {
            throw runtime_error("Priority queue is empty");
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
        int size = queueSize;
        mutex.unlock();
        return size;
    }
};
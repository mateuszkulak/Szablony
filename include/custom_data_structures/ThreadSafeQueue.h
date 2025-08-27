#pragma once
#include <mutex>
#include <stdexcept>

using namespace std;

/**
* Thread-safe queue implementation.
*
* @tparam T The type of elements in the queue.
*/
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
    /**
    * Default constructor.
    */
    ThreadSafeQueue() = default;

    /**
    * Destructor.
    */
    ~ThreadSafeQueue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    /**
    * Pushes an element into the queue.
    *
    * @param element The element to be added.
    */
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

    /**
    * Pops an element from the queue.
    *
    * @return The element that was removed.
    */
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

    /**
    * Returns the element at the front of the queue.
    *
    * @return A reference to the front element.
    */
    T& front() {
        if (isEmptyFlag) {
            throw runtime_error("Queue is empty");
        }
        mutex.lock();
        T& element = head->data;
        mutex.unlock();
        return element;
    }

    /**
    * Returns the element at the back of the queue.
    *
    * @return A reference to the back element.
    */
    T& back() {
        if (isEmptyFlag) {
            throw runtime_error("Queue is empty");
        }
        mutex.lock();
        T& element = tail->data;
        mutex.unlock();
        return element;
    }

    /**
    * Checks whether the queue is empty.
    *
    * @return True if the queue is empty, false otherwise.
    */
    bool empty() const {
        mutex.lock();
        bool empty = isEmptyFlag;
        mutex.unlock();
        return empty;
    }

    /**
    * Returns the number of elements in the queue.
    *
    * @return The number of elements in the queue.
    */
    int size() const {
        mutex.lock();
        int size = queueSize;
        mutex.unlock();
        return size;
    }
};

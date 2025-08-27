#pragma once
#include <mutex>
#include <stdexcept>

using namespace std;

/**
* Thread-safe priority queue implementation.
*
* @tparam T The type of elements in the priority queue.
* @tparam Compare The comparison functor used to maintain the priority order.
*/
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
    /**
    * Default constructor.
    */
    ThreadSafePriorityQueue() = default;

    /**
    * Destructor.
    */
    ~ThreadSafePriorityQueue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    /**
    * Pushes a new element into the priority queue.
    *
    * @param element The element to be added.
    */
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

    /**
    * Pops the highest priority element from the queue.
    *
    * @return The highest priority element.
    */
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

    /**
    * Returns the highest priority element from the queue without removing it.
    *
    * @return The highest priority element.
    */
    T& top() {
        if (isEmptyFlag) {
            throw runtime_error("Priority queue is empty");
        }

        mutex.lock();
        T& element = head->data;
        mutex.unlock();
        return element;
    }

    /**
    * Checks whether the priority queue is empty.
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
    * Returns the number of elements in the priority queue.
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
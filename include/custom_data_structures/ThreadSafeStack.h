#pragma once
#include <mutex>
#include <vector>
#include <stdexcept>

using namespace std;

/**
 * Thread-safe stack implementation.
 *
 * @tparam T The type of elements in the stack.
 */
template <typename T>
class ThreadSafeStack
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(const T &d, Node *n = nullptr) : data(d), next(n) {}
    };

    mutable std::mutex mutex;
    Node *head = nullptr;
    bool isEmptyFlag = true;
    int stackSize = 0;

public:
    /**
     * Default constructor.
     */
    ThreadSafeStack() = default;

    /**
     * Destructor.
     */
    ~ThreadSafeStack()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    /**
     * Pushes an element onto the stack.
     *
     * @param element The element to be added.
     */
    void push(const T &element)
    {
        mutex.lock();
        head = new Node(element, head);
        isEmptyFlag = false;
        stackSize++;
        mutex.unlock();
    }

    /**
     * Pops an element from the stack.
     *
     * @return The element that was removed.
     */
    T pop()
    {
        if (isEmptyFlag)
        {
            throw runtime_error("Stack is empty");
        }
        mutex.lock();
        Node *temp = head;
        head = head->next;
        T element = temp->data;
        delete temp;
        isEmptyFlag = (head == nullptr);
        mutex.unlock();
        return element;
    }

    /**
     * Returns a reference to the top element of the stack.
     *
     * @return A reference to the top element.
     */
    T &top()
    {
        if (isEmptyFlag)
        {
            throw runtime_error("Stack is empty");
        }
        mutex.lock();
        T &element = head->data;
        mutex.unlock();
        return element;
    }

    /**
     * Checks whether the stack is empty.
     *
     * @return True if the stack is empty, false otherwise.
     */
    bool empty() const
    {
        mutex.lock();
        bool empty = isEmptyFlag;
        mutex.unlock();
        return empty;
    }

    /**
     * Returns the number of elements in the stack.
     *
     * @return The number of elements in the stack.
     */
    int size() const
    {
        mutex.lock();
        int size = stackSize;
        mutex.unlock();
        return size;
    }
};
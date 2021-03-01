#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>

/*
    Struct QueueNode

    Queue (FIFO)

*/

namespace BTL {
    template<class T>
    class Queue
    {
    private:
        struct QueueNode {
            T val;
            QueueNode * next;

            QueueNode() : next(nullptr) {}
            QueueNode(T data): val(data), next(nullptr) {}
            QueueNode(T data, QueueNode * node)  : val(data), next(node) {}
        };
    public:
        // Root
        QueueNode * first;
        QueueNode * last;
        
        // Constructor
        Queue();
        Queue(T data);

        // Copy Constructor
        Queue(const Queue& other);

        // Copy Assignment Operator
        Queue& operator= (const Queue& other);

        // Operations
        void push(T data);
        void print() const;
        void dequeue();
        T& getFront() const;
        bool find(const T& val) const;

        // Destructor
        ~Queue();
    };

    template<class T>
    Queue<T>::Queue() {
        first = last = nullptr;
    }

    template<class T>
    Queue<T>::Queue(T data) {
        first = new QueueNode(data);
        last = first;
    }

    template<class T>
    Queue<T>::Queue(const Queue& other) {
        if (!other.first) {
            first = last = nullptr;
        }
        else {
            QueueNode * otherTemp = other.first;

            if (!otherTemp->next)
                first = last = new QueueNode(other.first->val);
            else {
                first = new QueueNode(other.first->val);
                QueueNode * temp = first;
                QueueNode * prev = nullptr;

                while (temp) {
                    if (otherTemp->next) { // Check if this is the end, if not, make a new one
                        temp->next = new QueueNode(otherTemp->next->val);
                    }
                    prev = temp;
                    temp = temp->next;
                    otherTemp = otherTemp->next;
                    if (!temp)
                        last = prev;
                }
            }
        }
    }

    template<class T>
    Queue<T>& Queue<T>::operator= (const Queue & other) {
        if (!other.first) {
            first = last = nullptr;
        }
        else {
            QueueNode * otherTemp = other.first;

            if (!otherTemp->next)
                first = last = new QueueNode(other.first->val);
            else {
                first = new QueueNode(other.first->val);
                QueueNode * temp = first;
                QueueNode * prev = nullptr;

                while (temp) {
                    if (otherTemp->next) { // Check if this is the end, if not, make a new one
                        temp->next = new QueueNode(otherTemp->next->val);
                    }
                    prev = temp;
                    temp = temp->next;
                    otherTemp = otherTemp->next;
                    if (!temp)
                        last = prev;
                }
            }
        }
        return *this;
    }

    template<class T>
    void Queue<T>::push(T data) {
        if (!first) {
            first = new QueueNode(data);
            last = first;
        }
        else {
            QueueNode * temp = first;
            while (temp) {
                if (temp->next)
                    temp = temp->next;
                else {
                    temp->next = new QueueNode(data);
                    last = temp->next;
                    break;
                }
            }
        }
    }

    template<class T>
    void Queue<T>::print() const {
        QueueNode * temp = first;
        while (temp) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << '\n';
    }

    template<class T>
    void Queue<T>::dequeue() {
        if (!first)
            std::cout << "Queue is Empty, nothing to dequeue!\n";
        else {
            QueueNode * temp = first;
            if (first == last) {
                std::cout << "Dequeued, Queue is now empty\n";
                delete temp;
                first = last = nullptr;
            }
            else {
                std::cout << "Dequeued\n";
                first = temp->next;
                delete temp;
            }
        }
    }

    template<class T>
    T& Queue<T>::getFront() const {
        return this->first->val;
    }

    template<class T>
    bool Queue<T>::find(const T& val) const {
        QueueNode * temp = first;
        while (temp) {
            if (temp->val == val)
                return true;
            temp = temp->next;
        }
        return false;
    }

    template<class T>
    Queue<T>::~Queue() {
        if (first) {
            QueueNode* temp = first;
            QueueNode* prev = nullptr;
            while (temp) {
                prev = temp;
                std::cout << "Deleting Node: " << temp->val << std::endl;
                temp = temp->next;
                delete prev;
            }
            first = last = nullptr;
        }
    }
}


#endif // QUEUE_H
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>

/*
    Struct StackNode

    Stack (FILO a.k.a Pringles time, once you pop you can't stop...)
*/

namespace BTL {
    template<class T>
    class Stack {
    private:
        // Node
        struct StackNode {
            T val;
            StackNode * nodeBelow;

            StackNode() : nodeBelow(nullptr) {}
            StackNode(int data) : val(data), nodeBelow(nullptr) {}
            StackNode(int data, StackNode * node) : val(data), nodeBelow(node) {}
        };
    public:
        // Top
        StackNode * top;
        
        // Constructor
        Stack();
        Stack(T value);

        // Copy Constructor
        Stack(const Stack& other);

        // Copy Assignement Operator
        Stack& operator= (const Stack& other);

        // Operations
        void push(const T& val);
        void print() const;
        T& pop();
        bool isEmpty() const; // Check if it's empty
        unsigned int size() const; // Return size
        T& getTop() const; // Access top element
        void makeEmpty();

        // Destructor
        ~Stack();
    };

    template<class T>
    Stack<T>::Stack() {
        top = nullptr;
    }

    template<class T>
    Stack<T>::Stack(T value) {
        StackNode * temp = new StackNode(value);
        top = temp;
    }

    template<class T>
    Stack<T>::Stack(const Stack& other) {
        if (other.top == nullptr)
            this->top = nullptr;
        else {
            top = new StackNode(other.top->val);
            StackNode * temp = top;
            StackNode * otherTemp = other.top;
            while (temp) {
                if (otherTemp->nodeBelow) {
                    StackNode * newNode = new StackNode(otherTemp->nodeBelow->val); // Make a node equlled to the below node
                    temp->nodeBelow = newNode;
                    temp = temp->nodeBelow;
                    otherTemp = otherTemp->nodeBelow;
                }
                else
                    temp = nullptr;
            }
        }
    }

    template<class T>
    Stack<T>& Stack<T>::operator= (const Stack& other) {
        if (other.top == nullptr)
            this->top = nullptr;
        else {
            top = new StackNode(other.top->val);
            StackNode * temp = top;
            StackNode * otherTemp = other.top;
            while (temp) {
                if (otherTemp->nodeBelow) {
                    StackNode * newNode = new StackNode(otherTemp->nodeBelow->val);
                    temp->nodeBelow = newNode;
                    temp = temp->nodeBelow;
                    otherTemp = otherTemp->nodeBelow;
                }
                else
                    temp = nullptr;
            }
        }
        return *this;
    }

    template<class T>
    void Stack<T>::push(const T& val) {
        StackNode * temp = new StackNode(val);
        temp->nodeBelow = top;
        top = temp;
    }

    template<class T>
    void Stack<T>::print() const {
        if (!top)
            std::cout << "Stack is empty\n";
        else {
            std::cout << "Stack from Top to Bottom\n";
            StackNode * temp = top;
            while (temp) {
                std::cout << "[ " << temp->val << " ]\n";
                temp = temp->nodeBelow;
            }
        }
    }

    template<class T>
    T& Stack<T>::pop() {
        if (top) {
            int value;
            StackNode * temp = top;
            value = temp->val;
            top = top->nodeBelow;
            delete temp;
            return value;
        }
        std::cout << "Stack is empty, nothing to Pop\n";
        //Create an assertion here for when stack is empty and returns undefined behavior
    }

    template<class T>
    bool Stack<T>::isEmpty() const {
        if (top)
            return true;
        else
            return false;
    }

    template<class T>
    unsigned int Stack<T>::size() const {
        unsigned int counter = 0;
        StackNode * temp = top;
        while (temp) {
            temp = temp->nodeBelow;
            counter++;
        }
        return counter;
    }

    template<class T>
    T& Stack<T>::getTop() const {
        if (top)
            return top->val;
        //Create an assertion here for when stack is empty and returns undefined behavior
    }

    template<class T>
    void Stack<T>::makeEmpty() {
        StackNode * temp = top;
        StackNode * prev = nullptr;
        while (temp) {
            prev = temp;
            temp = temp->nodeBelow;
            delete prev;
            prev = nullptr;
        }
        top = nullptr;
    }

    template<class T>
    Stack<T>::~Stack() {
        StackNode * temp = top;
        StackNode * prev = nullptr;
        while (temp) {
            prev = temp;
            temp = temp->nodeBelow;
            delete prev;
            prev = nullptr;
        }
        top = nullptr;
    }
}

#endif // STACK_H


#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>

/*
    Struct ListNode

    LinkedList (Forward only)
*/

namespace BTL {
    template<class T>
    class LinkedList {
    private:
        // Node
        struct ListNode {           
            T val;
            ListNode * next;

            ListNode() : val(0), next(nullptr) {}
            ListNode(T data) : val(data), next(nullptr) {}
            ListNode(T data, ListNode * node) : val(data), next(node) {}
        };
    public:
        // Head
        ListNode * head;

        // Iterator
        typedef ListNode * iterator;

        // Constructor
        LinkedList() : head(nullptr) {} // Creates empty list
        LinkedList(T val); // Creates list with value at head

        // Copy Constructor
        LinkedList(const LinkedList& other);

        // Copy Assignment Operator
        LinkedList& operator= (const LinkedList& other);

        // Operations
        void push(const T& val); //Pushes new node to the front
        void print() const; // Prints the list from front to last
        void reverse(); // Reverses list
        unsigned int size() const; // Returns size
        bool find(const T& value) const; // Retruns true if list has value 
        bool replace(const T& oldValue, const T& newValue); // Retruns true if value (first) is replaced
        bool remove(const T& value); // Returns true if value is found and replaced
        T& removeHead();
        bool isEmpty() const;
        T& getHead() const;
        void makeEmpty();

        // Iter Operations
        iterator begin();

        // Destructor
        ~LinkedList();
    };

    /*

     <---------------------------------->

        Function Implementions Below

     <---------------------------------->

    */

    template<class T>
    LinkedList<T>::LinkedList(T val)
    {
        head = new ListNode(val);
    }

    template<class T>
    LinkedList<T>::LinkedList(const LinkedList & other)
    {
        if (other.head == nullptr)
            this->head = nullptr;
        else {
            this->head = new ListNode(other.head->val);
            ListNode * temp = head;
            ListNode * tempOther = other.head;

            while (temp) {
                tempOther = tempOther->next;
                if (tempOther)
                    temp->next = new ListNode(tempOther->val);
                temp = temp->next;
                if (tempOther)
                    temp->next = tempOther->next;
            }
        }
    }

    template<class T>
    LinkedList<T>& LinkedList<T>::operator= (const LinkedList & other)
    {
        if (other.head == nullptr)
            this->head = nullptr;
        else {
            this->head = new ListNode(other.head->val);
            ListNode * temp = head;
            ListNode * tempOther = other.head;

            while (temp) {
                tempOther = tempOther->next;
                if (tempOther)
                    temp->next = new ListNode(tempOther->val);
                temp = temp->next;
                if (tempOther)
                    temp->next = tempOther->next;
            }
        }

        return *this;
    }

    template<class T>
    void LinkedList<T>::push(const T& val) {

        ListNode * temp = new ListNode(val);
        temp->next = head;
        head = temp;

    }

    template<class T>
    void LinkedList<T>::print() const
    {
        ListNode * temp = head;
        while (temp) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << '\n';
    }

    template<class T>
    void LinkedList<T>::reverse()
    {
        ListNode * temp = head;
        ListNode * prev = nullptr;

        while (temp) {
            head = head->next;
            temp->next = prev;
            prev = temp;
            temp = head;
        }
        head = prev;
    }

    template<class T>
    unsigned int LinkedList<T>::size() const
    {
        int counter = 0;
        ListNode * temp = head;

        while (temp) {
            ++counter;
            temp = temp->next;
        }

        return counter;
    }

    template<class T>
    bool LinkedList<T>::find(const T &value) const {
        ListNode * temp = head;
        while (temp) {
            if (temp->val == value)
                return true;
            temp = temp->next; // Remember to end with this because this breaks while loop
        }
        return false;
    }

    template<class T>
    bool LinkedList<T>::replace(const T& oldValue, const T& newValue) {
        ListNode * temp = head;
        while (temp) {
            if (temp->val == oldValue) {
                temp->val = newValue;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    template<class T>
    bool LinkedList<T>::remove(const T& value) {
        ListNode * temp = head;
        ListNode * prev = nullptr;
        ListNode * toBeDeleted = nullptr;
        while (temp) {
            if (temp->val == value) {
                // Node needs to be linked
                if (temp == head) {
                    // Case for head node
                    head = temp->next;
                    return true;
                }
                else {
                    if (temp->next == nullptr) {
                        // Last Node
                        prev->next = nullptr;
                        delete temp;
                        return true;
                    }
                    else {
                        // Non head node
                        prev->next = temp->next;
                    }
                }
                toBeDeleted = temp;
                temp = temp->next;
                delete toBeDeleted;
                return true;
            }
            else {
                prev = temp;
                temp = temp->next;
            }
        }
        return false;
    }

    template<class T>
    T& LinkedList<T>::removeHead()
    {
        if (head) {
            ListNode * temp = head;
            int value = temp->val;
            head = head->next;
            delete temp;
            return value;
        }
        else
            std::cout << "List is Empty, nothing to remove\n";
    }

    template<class T>
    bool LinkedList<T>::isEmpty() const
    {
        if (head)
            return true;
        else
            return false;
    }

    template<class T>
    T& LinkedList<T>::getHead() const
    {
        if (head)
            return head->val;
    }

    template<class T>
    void LinkedList<T>::makeEmpty()
    {
        ListNode * temp = head;
        while (temp) {
            temp = temp->next;
            delete head;
            head = temp;
        }
    }

    template<class T>
    typename LinkedList<T>::iterator LinkedList<T>::begin()
    {
        return head;
    }

    template<class T>
    LinkedList<T>::~LinkedList()
    {
        std::cout << "Deleting Linked List!\n";
        ListNode * temp = head;
        while (temp) {
            temp = temp->next;
            delete head;
            head = temp;
        }
    }
}

#endif // LINKEDLIST_H
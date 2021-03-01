#ifndef BINSEARCHTREE_H
#define BINSEARCHTREE_H

#include <iostream>
#include <string>

namespace BTL {

    template <class T>
    class BinSearchTree {
    public:
        // Node
        struct bstNode {
            T data;
            bstNode * left;
            bstNode * right;

            bstNode() : left(nullptr), right(nullptr) {}
            bstNode(T data) : data(data), left(nullptr), right(nullptr) {}
        };

        // Root Pointer
        bstNode * root;

        // Constructors
        BinSearchTree();
        BinSearchTree(T val);

        // Copy Constructor
        BinSearchTree(const BinSearchTree<T>& other);

        // Copy Assignment Operator
        BinSearchTree<T> & operator= (const BinSearchTree<T>& other);

        // Main Operations
        void insert(const T& val); // O (log n). Insert a Node with val
        void print() const; // Print in order.  Uses helper function in private section
        T& getMin() const; // Returns minimum value of tree
        T& getMax() const; // Returns maximum value of tree
        bool search(const T& val) const; // O (log n).  Returns true if value is found, false if not
        void remove(const T& val); // O (log n).  Removes value if exists

        // Destructor
        ~BinSearchTree();

    private:
        // Operation Helper Functions (Recursion)
        bstNode * copyRecursion(bstNode * node, bstNode * otherNode);
        void insertRecursion(bstNode * node, const T& val);
        void printRecursion(bstNode * node) const;
        T& getMinRecursion(bstNode * node) const;
        T& getMaxRecursion(bstNode * node) const;
        bool searchRecursion(bstNode * node, const T& val) const;
        bstNode * getMinNode(bstNode * node) const;
        bstNode * getMaxNode(bstNode * node) const;
        bstNode * removeRecursion(bstNode * node, const T& val);
        void destructorRecursion(bstNode * node);
    };

    /*

     <---------------------------------->

        Function Implementions Below 
        
     <---------------------------------->

    */

    template <class T>
    BinSearchTree<T>::BinSearchTree()
    {
        root = nullptr;
    }

    template<class T>
    BinSearchTree<T>::BinSearchTree(T val)
    {
        root = new bstNode(val);
    }

    template<class T>
    BinSearchTree<T>::BinSearchTree(const BinSearchTree<T> & other) {
        if (!other.root) // Corner Case
            root = nullptr;
        else {
            root = copyRecursion(this->root, other.root); // Remember to return the root!
        }
    }

    template<class T>
    BinSearchTree<T>& BinSearchTree<T>::operator= (const BinSearchTree<T> &other) {
        if (!other.root) // Corner Case
            root = nullptr;
        else {
            root = copyRecursion(this->root, other.root); // Remember to return the root!
        }
        return *this;
    }
    

    template<class T>
    typename BinSearchTree<T>::bstNode * BinSearchTree<T>::copyRecursion(bstNode * node, bstNode * otherNode) {
        node = new bstNode(otherNode->data);
        if (otherNode->left)
            node->left = copyRecursion(node->left, otherNode->left);
        if (otherNode->right)
            node->right = copyRecursion(node->right, otherNode->right);
        return node;
    }

    template<class T>
    void BinSearchTree<T>::insert(const T& val)
    {
        if (root == nullptr)
            root = new bstNode(val);
        else {
            insertRecursion(root, val);
        }
    }

    template<class T>
    void BinSearchTree<T>::insertRecursion(bstNode * node, const T& val)
    {
        // Recursion Time!
        bstNode * temp = node;
        if (val < temp->data) // Go Left
        {
            if (temp->left)
                insertRecursion(temp->left, val);
            else
            {
                temp->left = new bstNode(val);
            }
        }
        else if (val > temp->data)
        {
            if (temp->right)
                insertRecursion(temp->right, val);
            else
            {
                temp->right = new bstNode(val);
            }
        }
        // If it equals, then do nothing, and exit
    }

    template<class T>
    void BinSearchTree<T>::print() const {
        if (!root)
            std::cout << "Tree is Empty!\n";
        else {
            printRecursion(root);
            std::cout << '\n';
        }
    }

    template<class T>
    void BinSearchTree<T>::printRecursion(bstNode * node) const {
        if (node->left)
            printRecursion(node->left);
        std::cout << node->data << " ";
        if (node->right)
            printRecursion(node->right);
    }

    template<class T>
    T& BinSearchTree<T>::getMin() const {
        if (!root)
        {
            std::cout << "Tree is empty\n";
        }
        else 
            return getMinRecursion(root);
    }

    template<class T>
    T& BinSearchTree<T>::getMinRecursion(bstNode * node) const {
        if (node->left)
            return getMinRecursion(node->left);
        return node->data;
    }

    template<class T>
    T& BinSearchTree<T>::getMax() const {
        if (!root) {
            std::cout << "Tree is empty\n";
        }
        else
            return getMaxRecursion(root);
    }

    template<class T>
    T& BinSearchTree<T>::getMaxRecursion(bstNode * node) const {
        if (node->right)
            return getMaxRecursion(node->right);
        return node->data;
    }

    template<class T>
    bool BinSearchTree<T>::search(const T& val) const {
        if (!root) {
            std::cout << "Tree is empty, nothing to search!\n";
            return false;
        }
        else
            return searchRecursion(root, val);
    }

    template<class T>
    bool BinSearchTree<T>::searchRecursion(bstNode * node, const T& val) const {       
        if (val < node->data && node->left)
            return searchRecursion(node->left, val);
        else if (val > node->data && node->right)
            return searchRecursion(node->right, val);
        else if (val == node->data)
            return true;
        return false;
    }

    template<class T>
    void BinSearchTree<T>::remove(const T& val)
    {
        if (!root) {
            std::cout << "Tree is empty.  Nothing to remove!\n";
        }
        else {
            removeRecursion(root, val);
        }
    }

    template<class T>
    typename BinSearchTree<T>::bstNode * BinSearchTree<T>::getMinNode(bstNode * node) const {
        if (node->left)
            return getMinNode(node->left);
        return node;
    }

    template<class T>
    typename BinSearchTree<T>::bstNode * BinSearchTree<T>::getMaxNode(bstNode * node) const {
        if (node->right)
            return getMaxNode(node->right);
        return node;
    }

    template<class T>
    typename BinSearchTree<T>::bstNode * BinSearchTree<T>::removeRecursion(bstNode * node, const T& val) {
        if (val < node->data)
            node->left = removeRecursion(node->left, val);
        else if (val > node->data)
            node->right = removeRecursion(node->right, val);
        else { // Data to be deleted is found...
            // Case 1: No child
            if (node->left == nullptr && root->right == nullptr) {
                delete node; // delete the object
                node = nullptr; // set the pointer to null, and this also updates the child (node->Left or node->right)
            }
            // Case 2: One child
            else if (node->left == nullptr) {
                bstNode * temp = node;
                node = node->right; // remember that you are replacing the node and its address entirely, thus re-routing the connection
                delete temp; // Thus this new pointer is orphaned, and can be deleted
            }
            else if (node->right == nullptr) {
                bstNode * temp = node; // same as above
                node = node->left;
                delete temp;
            }
            // Case 3: 2 children
            else {
                bstNode * temp = getMinNode(node->right); // get the pointer/address Min of right sub-tree
                node->data = temp->data; // Replace the node data with min of right sub-tree.  A bit of trickery here
                node->right = removeRecursion(node->right, temp->data); // Work on the right sub tree.  Delete the duplicate data.  
            }
        }
        return node;
    }

    template<class T>
    void BinSearchTree<T>::destructorRecursion(bstNode * node) {
        if (node->left)
            destructorRecursion(node->left);
        if (node->right)
            destructorRecursion(node->right);
        delete node;
    }

    template<class T>
    BinSearchTree<T>::~BinSearchTree() {
        if (root) {
            destructorRecursion(root);
        }
        root = nullptr;
    }
}
#endif // !BINSEARCHTREE_H
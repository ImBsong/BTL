#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>

namespace BTL {
    
    template <class T>
    class Vector
    {
    private:
        unsigned int my_size;
        unsigned int my_capacity;
        T * buffer; // buffer is a pointer to type T.  Essentially List
    public:
        // Iterator
        typedef T * iterator; //iterator is a pointer to T type (which can be int, str, char)

        // Constructor
        Vector();
        Vector(unsigned int size); //Set vector with size
        Vector(unsigned int size, const T& val); // Set size and initial values like [0,0,0,0,...,0]

        // Copy Constructor
        Vector(const Vector<T> & other); // Copy Constructor 

        // Copy Assignement Operator
        Vector<T> & operator = (const Vector<T> &); // Copy Assignment Operator

        // Destructor
        ~Vector();

        // Operations
        unsigned int getCapacity() const;
        unsigned int getSize() const;
        bool isEmpty() const;
        T & front(); // returns a ref of t type
        T & back(); // returns a ref of t type
        void push_back(const T & value);
        void pop_back();
        void reserve(unsigned int capacity);
        void resize(unsigned int size);
        T & operator[](unsigned int index);
        void clear();
        void print() const;

        // Iter Operations
        iterator begin(); // returns a pointer of t type
        iterator end(); // returns a poitner of t type


    };

    template<class T>
    Vector<T>::Vector()
    {
        my_capacity = 0;
        my_size = 0;
        buffer = 0;
    }

    template<class T>
    Vector<T>::Vector(unsigned int size)
    {
        my_capacity = size;
        my_size = size;
        buffer = new T[size];
    }

    template<class T>
    Vector<T>::Vector(unsigned int size, const T& val)
    {
        my_capacity = size;
        my_size = size;
        buffer = new T[size];
        for (unsigned int i = 0; i < size; i++) {
            buffer[i] = val;
        }
    }

    template<class T>
    Vector<T>::Vector(const Vector<T> & other)
    {
        my_size = other.my_size;
        my_capacity = other.my_capacity;
        buffer = new T[my_size]; // Of type T (could be int, char, whatever), set the buffer as same size as other vector
        for (unsigned int i = 0; i < my_size; i++)
            buffer[i] = other.buffer[i];
    }

    template<class T>
    Vector<T> & Vector<T>::operator= (const Vector<T> &other)
    {
        delete[] buffer;
        my_size = other.my_size;
        my_capacity = other.my_capacity;
        buffer = new T[my_size];
        for (unsigned int i = 0; i < my_size; i++)
            buffer[i] = other.buffer[i];
        return *this;
    }

    template<class T>
    Vector<T>::~Vector()
    {
        my_size = 0;
        my_capacity = 0;
        delete[] buffer;
    }

    template<class T>
    unsigned int Vector<T>::getCapacity() const
    {
        return my_capacity;
    }

    template<class T>
    unsigned int Vector<T>::getSize() const
    {
        return my_size;
    }

    template<class T>
    bool Vector<T>::isEmpty() const
    {
        if (my_size > 0)
            return false;
        else
            return true;
    }

    template<class T>
    typename Vector<T>::iterator Vector<T>::begin()
    {
        return buffer;
    }

    template<class T>
    typename Vector<T>::iterator Vector<T>::end()
    {
        return buffer + getSize();
    }

    template<class T>
    T& Vector<T>::front()
    {
        return buffer[0];
    }

    template<class T>
    T& Vector<T>::back()
    {
        return buffer[my_size - 1];
    }

    template<class T>
    void Vector<T>::push_back(const T & v)
    {
        if (my_size >= my_capacity)
            reserve(my_capacity + 5);
        buffer[my_size++] = v;
    }

    template<class T>
    void Vector<T>::pop_back()
    {
        my_size--;
    }

    template<class T>
    void Vector<T>::reserve(unsigned int capacity)
    {
        if (buffer == 0)
        {
            my_size = 0;
            my_capacity = 0;
        }
        T * newBuffer = new T[capacity];
        unsigned int l_size = (capacity < my_size) ? capacity : my_size; // if capacity that's passed is less, then return cap, otherwise we can just return size

        for (unsigned int i = 0; i < l_size; i++)
            newBuffer[i] = buffer[i];

        my_capacity = capacity;
        delete[] buffer;
        buffer = newBuffer;
    }

    template<class T>
    void Vector<T>::resize(unsigned int size)
    {
        reserve(size);
        my_size = size;
    }

    template<class T>
    T& Vector<T>::operator[](unsigned int index)
    {
        return buffer[index];
    }

    template<class T>
    void Vector<T>::clear()
    {
        my_capacity = 0;
        my_size = 0;
        buffer = 0;
    }

    template<class T>
    void Vector<T>::print() const
    {
        if (my_size == 0)
            std::cout << "Vector is empty, nothing to print" << std::endl;
        else {
            for (unsigned int i = 0; i < my_size; i++) {
                std::cout << buffer[i] << " ";
            }
            std::cout << '\n';
        }
    }
}


#endif // !VECTOR_H


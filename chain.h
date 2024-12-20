// chain.h

#ifndef CHAIN_
#define CHAIN_

#include <iostream>
#include "cnode.h"
#include "xcept.h"

using namespace std;

template<class T>
class Chain
{
public:
    Chain() { first = nullptr; }
    ~Chain();

    bool IsEmpty() const { return first == nullptr; }
    int Length() const;
    bool Find(int k, T& x) const;
    int Search(const T& x) const;
    Chain<T>& Delete(int k, T& x);
    Chain<T>& Insert(int k, const T& x);
    void Output(ostream& out) const;
    ChainNode<T>* Max() const;  // Add Max function declaration

private:
    ChainNode<T>* first;  // pointer to first node
};

// Destructor: Delete all nodes in the chain
template<class T>
Chain<T>::~Chain()
{
    ChainNode<T>* next;
    while (first)
    {
        next = first->link;
        delete first;
        first = next;
    }
}

// Length: Return the number of elements in the chain
template<class T>
int Chain<T>::Length() const
{
    ChainNode<T>* current = first;
    int len = 0;
    while (current)
    {
        len++;
        current = current->link;
    }
    return len;
}

// Find: Set x to the k'th element in the chain and return true, else return false
template<class T>
bool Chain<T>::Find(int k, T& x) const
{
    if (k < 1) return false;
    ChainNode<T>* current = first;
    int index = 1;
    while (index < k && current)
    {
        current = current->link;
        index++;
    }
    if (current)
    {
        x = current->data;
        return true;
    }
    return false;
}

// Search: Return position of x, return 0 if not found
template<class T>
int Chain<T>::Search(const T& x) const
{
    ChainNode<T>* current = first;
    int index = 1;
    while (current && current->data != x)
    {
        current = current->link;
        index++;
    }
    if (current) return index;
    return 0;
}

// Delete: Delete the k'th element and set x to its value
template<class T>
Chain<T>& Chain<T>::Delete(int k, T& x)
{
    if (k < 1 || !first) throw OutOfBounds();

    ChainNode<T>* p = first;
    if (k == 1)
        first = first->link;
    else
    {
        ChainNode<T>* q = first;
        for (int index = 1; index < k - 1 && q; index++)
            q = q->link;
        if (!q || !q->link) throw OutOfBounds();
        p = q->link;
        q->link = p->link;
    }

    x = p->data;
    delete p;
    return *this;
}

// Insert: Insert element x after the k'th element
template<class T>
Chain<T>& Chain<T>::Insert(int k, const T& x)
{
    if (k < 0) throw OutOfBounds();

    ChainNode<T>* p = first;
    for (int index = 1; index < k && p; index++)
        p = p->link;
    if (k > 0 && !p) throw OutOfBounds();

    ChainNode<T>* y = new ChainNode<T>;
    y->data = x;
    y->link = nullptr;

    if (k)
    {
        y->link = p->link;
        p->link = y;
    }
    else
    {
        y->link = first;
        first = y;
    }
    return *this;
}

// Max: Find and return the node with the maximum data
template<class T>
ChainNode<T>* Chain<T>::Max() const
{
    if (first == nullptr)  // If the list is empty, return nullptr
        return nullptr;

    ChainNode<T>* current = first;
    ChainNode<T>* maxNode = first;
    T maxValue = first->data;

    // Traverse the list and find the maximum value
    while (current != nullptr)
    {
        if (current->data > maxValue)
        {
            maxValue = current->data;
            maxNode = current;
        }
        current = current->link;
    }
    return maxNode;
}

// Output: Insert the chain elements into the output stream
template<class T>
void Chain<T>::Output(ostream& out) const
{
    ChainNode<T>* current;
    for (current = first; current; current = current->link)
        out << current->data << "  ";
}

// Overload << operator to print the chain
template<class T>
ostream& operator<<(ostream& out, const Chain<T>& x)
{
    x.Output(out);
    return out;
}

#endif

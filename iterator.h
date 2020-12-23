#ifndef LAB_KULIKOV_3_ITERATOR_H
#define LAB_KULIKOV_3_ITERATOR_H

#include "queue.h"
#include "stack.h"

class Iterator {
public:
    virtual int next() = 0;
    virtual bool has_next() = 0;
};

class bft_iterator : public Iterator {
private:
    Node* IteratorNode;
    Queue QueueList;
public:
    bft_iterator(Node* firstNode) {
        IteratorNode = firstNode;
        if (IteratorNode != nullptr) QueueList.Enqueue(IteratorNode);
        else throw std::out_of_range("Cannot create bft_iterator: tree is empty");
    }

    int next() override;
    bool has_next() override;
};

class dft_iterator : public Iterator {
private:
    Node* IteratorNode;
    Stack NodeStack;
    bool first = true;
public:
    dft_iterator(Node* firstNode) {
        IteratorNode = firstNode;
        if (IteratorNode != nullptr) NodeStack.Push(IteratorNode);
        else throw std::out_of_range("Cannot create dft_iterator: tree is empty");
    }

    int next() override;
    bool has_next() override;
};

#endif //LAB_KULIKOV_3_ITERATOR_H

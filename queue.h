#ifndef LAB_KULIKOV_3_QUEUE_H
#define LAB_KULIKOV_3_QUEUE_H

#include "node.h"
#include <iostream>

class Queue {
private:
    size_t Size;
    Wrapper* Head;
public:
    Queue() : Size(0), Head(nullptr)  {}

    void Enqueue(Node* node_2);
    Node* Dequeue();
    Node* Peek();

    void PopFront();
    void Clear();

    size_t GetSize();
    bool IsEmpty();
};


#endif //LAB_KULIKOV_3_QUEUE_H

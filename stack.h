#ifndef LAB_KULIKOV_3_STACK_H
#define LAB_KULIKOV_3_STACK_H

#include "node.h"
#include <iostream>

class Stack {
private:
    size_t Size;
    Wrapper* Head;
public:
    Stack() : Size(0), Head(nullptr) {}

    void Push(Node* node_2);
    Node* Pop();
    Node* Top();

    void PopFront();
    void Clear();

    size_t GetSize() const;
    bool IsEmpty() const;
};

#endif //LAB_KULIKOV_3_STACK_H

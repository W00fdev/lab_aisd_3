#include "stack.h"

Node* Stack::Top() {
    return Head->Core;
}

Node* Stack::Pop() {
    Node* Data = Head->Core;
    PopFront();
    return Data;
}

void Stack::PopFront(){
    Wrapper* elem = Head;
    Head = Head->wNext;
    delete elem;
    Size--;
}

void Stack::Push(Node* node_2) {
    Head = new Wrapper(node_2, Head);
    Size++;
}

void Stack::Clear() {
    while (Size > 0)
        PopFront();
}

size_t Stack::GetSize() const {
    return Size;
}

bool Stack::IsEmpty() const {
    return Size == 0;
}
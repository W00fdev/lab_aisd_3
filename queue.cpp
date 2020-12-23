#include "queue.h"

void Queue::Enqueue(Node* node_2) {
    if (Head == nullptr) {
        Head = new Wrapper(node_2);
    } else {
        Wrapper* searcher = Head;
        while (searcher->wNext != nullptr) {
            searcher = searcher->wNext;
        }
        searcher->wNext = new Wrapper(node_2);
    }
    Size++;
}

Node* Queue::Dequeue() {
    Node* Data = Head->Core;
    PopFront();
    return Data;
}

Node* Queue::Peek() {
    return Head->Core;
}

void Queue::PopFront() {
    Wrapper* elem = Head;
    Head = Head->wNext;
    delete elem;
    Size--;
}

void Queue::Clear() {
    while (Size > 0)
        PopFront();
}

size_t Queue::GetSize() {
    return Size;
}

bool Queue::IsEmpty() {
    return Size == 0;
}
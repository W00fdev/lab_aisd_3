#include "iterator.h"

using namespace std;

// bft

int bft_iterator::next() {
    if (QueueList.GetSize() > 0) {
        IteratorNode = QueueList.Dequeue();
        if (IteratorNode->Left != nullptr) QueueList.Enqueue(IteratorNode->Left);
        if (IteratorNode->Right != nullptr) QueueList.Enqueue(IteratorNode->Right);
    } else {
        IteratorNode = nullptr;
        throw out_of_range("We have no more elems");
    }

    return IteratorNode->Value;
}

bool bft_iterator::has_next() {
    return IteratorNode == nullptr;
}

// dft

int dft_iterator::next()  {
    if (first) {
        first = false;
        return NodeStack.Pop()->Value;
    }

    if (IteratorNode->Right != nullptr) NodeStack.Push(IteratorNode->Right);
    if (IteratorNode->Left != nullptr) IteratorNode = IteratorNode->Left;
    else if (!NodeStack.IsEmpty()) IteratorNode = NodeStack.Pop();
    else {
        IteratorNode = nullptr;
        throw out_of_range("We have no more elems");
    }
    return IteratorNode->Value;
}

bool dft_iterator::has_next() {
    return IteratorNode == nullptr;
}
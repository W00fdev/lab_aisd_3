#ifndef LAB_KULIKOV_3_NODE_H
#define LAB_KULIKOV_3_NODE_H

class Node {
public:
    int Value;
    Node* Left;
    Node* Right;

    Node(int value_2, Node* Left_2 = nullptr, Node* Right_2 = nullptr) : Value(value_2), Left(Left_2), Right(Right_2) {}
    Node() : Left(nullptr), Right(nullptr) {}
};

class Wrapper {
public:
    Node* Core;
    Wrapper* wNext;

    Wrapper(Node* core_2, Wrapper* wNext_2 = nullptr) : Core(core_2), wNext(wNext_2) {}
    Wrapper() : Core(nullptr), wNext(nullptr) {}
};

#endif //LAB_KULIKOV_3_NODE_H

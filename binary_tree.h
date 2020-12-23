#ifndef LAB_KULIKOV_3_BINARY_TREE_H
#define LAB_KULIKOV_3_BINARY_TREE_H

#include "queue.h"
#include "stack.h"
#include "iterator.h"

class BinaryTree {
private:
    Node* root = nullptr;

public:
    ~BinaryTree() {
        clear_tree(root);
    }

    void insert(int value);
    bool contains(int value);
    void remove(int value);
    void clear_tree(Node* searcher);

    Iterator* create_bft_iterator();
    Iterator* create_dft_iterator();
};


#endif //LAB_KULIKOV_3_BINARY_TREE_H

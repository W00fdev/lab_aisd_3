#include "binary_tree.h"

using namespace std;

void BinaryTree::insert(int value) {
    if (root == nullptr) root = new Node(value);
    else {
        Node* searcher = root;
        while (true) {
            if (value <= searcher->Value) {
                if (searcher->Left != nullptr) searcher = searcher->Left;
                else {
                    searcher->Left = new Node(value);
                    break;
                }
            } else {
                if (searcher->Right != nullptr) searcher = searcher->Right;
                else {
                    searcher->Right = new Node(value);
                    break;
                }
            }
        }
    }
}


bool BinaryTree::contains(int value) {
    if (root == nullptr) throw out_of_range("There's nothing to find : contains error");
    Node* searcher = root;
    while (value != searcher->Value) {
        if (value < searcher->Value) {
            if (searcher->Left != nullptr) searcher = searcher->Left;
            else return false;
        } else {
            if (searcher->Right != nullptr) searcher = searcher->Right;
            else return false;
        }
    }

    return true;
}

void BinaryTree::remove(int value) {
    if (!contains(value)) throw std::invalid_argument("There's no such element to delete");
    else {
        Node* searcher = root;
        Node* previous = nullptr;
        while (value != searcher->Value) {
            if (value < searcher->Value) {
                previous = searcher;
                searcher = searcher->Left;
            } else {
                previous = searcher;
                searcher = searcher->Right;
            }
        }

        if (searcher->Left == nullptr && searcher->Right == nullptr) {
            if (previous->Left->Value = searcher->Value) previous->Left = nullptr;
            else previous->Right = nullptr;

            delete searcher;
        } else if (searcher->Left != nullptr && searcher->Right != nullptr) {
            Node* elem;
            if (searcher->Right->Left != nullptr) {
                elem = searcher->Right->Left;
                searcher->Value = elem->Value;
                searcher->Right->Left = nullptr;
            } else {
                elem = searcher->Right;
                searcher->Value = elem->Value;
                Node* new_Node = new Node(elem->Right->Value, elem->Right->Left, elem->Right->Right);
                searcher->Right = new_Node;
            }

            delete elem;
        } else {
            if (searcher->Left != nullptr) {
                searcher->Value = searcher->Left->Value;
                delete searcher->Left;
                searcher->Left = nullptr;
            } else {
                searcher->Value = searcher->Right->Value;
                delete searcher->Right;
                searcher->Right = nullptr;
            }
        }
    }
}

void BinaryTree::clear_tree(Node* searcher) {
    if (searcher != nullptr) {
        clear_tree(searcher->Left);
        clear_tree(searcher->Right);
        delete searcher;
    }
}

Iterator* BinaryTree::create_bft_iterator() {
    return new bft_iterator(root);
}

Iterator* BinaryTree::create_dft_iterator() {
    return new dft_iterator(root);
}
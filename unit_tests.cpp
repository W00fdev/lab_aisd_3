#include <gtest/gtest.h>
#include "binary_tree.h"
#include <exception>

BinaryTree g_binTree;

TEST(binary_tree, Exception) {
    ASSERT_ANY_THROW(g_binTree.contains(5));
    ASSERT_ANY_THROW(g_binTree.remove(8));
    ASSERT_ANY_THROW(g_binTree.create_bft_iterator());
    ASSERT_ANY_THROW(g_binTree.create_dft_iterator());
}

TEST(binary_tree, Insert) {
    BinaryTree binTree;
    binTree.insert(5);
    binTree.insert(2);
    binTree.insert(7);
    binTree.insert(6);
    binTree.insert(1);
    binTree.insert(3);
    binTree.insert(4);

    dft_iterator* iterator = static_cast< dft_iterator*>(binTree.create_dft_iterator());

    ASSERT_EQ(iterator->next(), 5);
    ASSERT_EQ(iterator->next(), 2);
    ASSERT_EQ(iterator->next(), 1);
    ASSERT_EQ(iterator->next(), 3);
    ASSERT_EQ(iterator->next(), 4);
    ASSERT_EQ(iterator->next(), 7);
    ASSERT_EQ(iterator->next(), 6);

    delete iterator;
}

TEST(binary_tree, Contains){
    for (int i = 0; i < 100; i++) g_binTree.insert(i * 100);
    for (int i = 99; i >= 0; i--) ASSERT_TRUE(g_binTree.contains(i * 100));
    for (size_t i = 1; i < 99; i++) ASSERT_FALSE(g_binTree.contains(i));

    ASSERT_FALSE(g_binTree.contains(10'000));
}


TEST(binary_tree, InsertAndRemoveAndIterator) {
    BinaryTree binTree;
    binTree.insert(150);
    binTree.insert(200);
    binTree.insert(175);
    binTree.insert(180);
    binTree.insert(185);
    binTree.insert(300);
    binTree.insert(120);
    binTree.insert(170);

    bft_iterator* iterator = static_cast< bft_iterator*>(binTree.create_bft_iterator());
    ASSERT_EQ(iterator->next(), 150);
    ASSERT_EQ(iterator->next(), 120);
    ASSERT_EQ(iterator->next(), 200);
    ASSERT_EQ(iterator->next(), 175);
    ASSERT_EQ(iterator->next(), 300);
    ASSERT_EQ(iterator->next(), 170);
    ASSERT_EQ(iterator->next(), 180);
    ASSERT_EQ(iterator->next(), 185);

    delete iterator;

    binTree.insert(110);
    binTree.insert(100);
    binTree.remove(170);

    iterator = static_cast< bft_iterator*>(binTree.create_bft_iterator());

    ASSERT_EQ(iterator->next(), 150);
    ASSERT_EQ(iterator->next(), 120);
    ASSERT_EQ(iterator->next(), 200);
    ASSERT_EQ(iterator->next(), 110);
    ASSERT_EQ(iterator->next(), 175);
    ASSERT_EQ(iterator->next(), 300);
    ASSERT_EQ(iterator->next(), 100);
    ASSERT_EQ(iterator->next(), 180);
    ASSERT_EQ(iterator->next(), 185);

    delete iterator;

    binTree.insert(50);
    binTree.insert(175);
    iterator = static_cast< bft_iterator*>(binTree.create_bft_iterator());

    ASSERT_EQ(iterator->next(), 150);
    ASSERT_EQ(iterator->next(), 120);
    ASSERT_EQ(iterator->next(), 200);
    ASSERT_EQ(iterator->next(), 110);
    ASSERT_EQ(iterator->next(), 175);
    ASSERT_EQ(iterator->next(), 300);
    ASSERT_EQ(iterator->next(), 100);
    ASSERT_EQ(iterator->next(), 175);
    ASSERT_EQ(iterator->next(), 180);
    ASSERT_EQ(iterator->next(), 50);
    ASSERT_EQ(iterator->next(), 185);

    delete iterator;
}

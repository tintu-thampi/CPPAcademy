#include <gtest/gtest.h>
#include "../src/bst.h"

class BSTGTest : public ::testing::Test {
    protected:
        BSTGTest() {
            bstTree = new BST();
        }

        void SetUp() override {
            bstTree->reset();
        }

        void TearDown() override {
        }

        ~BSTGTest() {
            delete bstTree;
        }

        BST* bstTree;
};

TEST_F(BSTGTest, initialBst_CountIsZero) {
    EXPECT_EQ(0, bstTree->count());
}

TEST_F(BSTGTest, reset_CountIsZero) {
    bstTree->insert(7);
    bstTree->insert(10);
    bstTree->insert(5);
    bstTree->reset();
    EXPECT_EQ(0, bstTree->count());
}

TEST_F(BSTGTest, insertOne_CountIsOne) {
    bstTree->insert(1);
    EXPECT_EQ(1, bstTree->count());
}

TEST_F(BSTGTest, insertTwoRemoveOne_CountIsOne) {
    bstTree->insert(4);
    bstTree->insert(3);
    EXPECT_EQ(2, bstTree->count());
    bstTree->remove(4);
    EXPECT_EQ(1, bstTree->count());
}

TEST_F(BSTGTest, DISABLED_insertManyRemoveNodeWithLeftRight_CountIsAsExpected) {
    bstTree->insert(4);
    bstTree->insert(3);
    bstTree->insert(5);
    EXPECT_EQ(3, bstTree->count());
    bstTree->remove(4);
    EXPECT_EQ(2, bstTree->count());
}

TEST_F(BSTGTest, removeNonExisting_CountUnaffected) {
    bstTree->insert(4);
    EXPECT_EQ(1, bstTree->count());
    bstTree->remove(3);
    EXPECT_EQ(1, bstTree->count());
}

TEST_F(BSTGTest, findMinMax_ReturnsMinMax) {
    bstTree->insert(7);
    bstTree->insert(10);
    bstTree->insert(5);
    EXPECT_EQ(5, bstTree->findMin());
    EXPECT_EQ(10, bstTree->findMax());
}

TEST_F(BSTGTest, searchNonExistantItem_ReturnsFalse)
{
    bstTree->insert(7);
    bstTree->insert(10);
    bstTree->insert(5);
    EXPECT_FALSE(bstTree->search(3));
}

TEST_F(BSTGTest, searchExistantItem_ReturnsTrue)
{
    bstTree->insert(7);
    bstTree->insert(10);
    bstTree->insert(5);
    EXPECT_TRUE(bstTree->search(10));
}
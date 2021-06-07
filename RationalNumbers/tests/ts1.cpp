#include <gtest/gtest.h>
#include "../src/rational.h"

class RationalTest : public ::testing::Test {
    protected:
        RationalTest() {
        }

        void SetUp() override {
        }

        void TearDown() override {
        }

        ~RationalTest() {
        }
};

TEST_F(RationalTest, dummy) {
    EXPECT_TRUE(true);
}

TEST_F(RationalTest, dummy2) {
    EXPECT_FALSE(false);
}

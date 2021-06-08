#include <gtest/gtest.h>
#include "rational.h"

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

TEST_F(RationalTest, testEquality) {
    Rational r1{1};
    Rational r2{1};
    EXPECT_EQ(r1, r2);
}


#include <gtest/gtest.h>
#include "LibB/libB.h"

TEST(LibB, testMultiplyNumbers) {
    ASSERT_EQ(6, LibB::multiplyNumbers(2, 3));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

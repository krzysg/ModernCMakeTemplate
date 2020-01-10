#include <gtest/gtest.h>
#include <LibA/libA.h>

TEST(LibA, testAddNumbers) {
    ASSERT_EQ(5, LibA::addNumbers(2, 3));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

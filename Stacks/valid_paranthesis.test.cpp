#include <gtest/gtest.h>
#include "../Stack/valid_paranthesis.cpp"

class ValidParenthesisTest : public ::testing::Test {
protected:
    Solution solution;
};

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

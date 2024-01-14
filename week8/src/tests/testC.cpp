#include <gtest/gtest.h>
#include "../headers/task03c.h"

TEST(TestC, TestC) {
    std::string userInput = "{{}}";
    EXPECT_EQ(isValidBrackets(userInput), true);
    userInput = "{{}}}";
    EXPECT_EQ(isValidBrackets(userInput), false);
}

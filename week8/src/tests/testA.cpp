#include <gtest/gtest.h>
#include <set>
#include "../headers/task03a.h"

TEST(TestA, TestA) {
    App application;
    std::set<int> answer;
    answer.insert(12);
    answer.insert(22);
    answer.insert(44);
    std::string userInput = "12, 12, 22, 22, 44, 44";
    EXPECT_EQ(application.run(userInput), answer);
}

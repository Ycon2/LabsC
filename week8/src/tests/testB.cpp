#include <gtest/gtest.h>
#include "../headers/task03b.h"

TEST(TestB, TestB) {
    Students students;
    students.push_back(std::vector<std::string>{"Russian", "English", "Japanese"});
    students.push_back(std::vector<std::string>{"Russian", "English"});
    students.push_back(std::vector<std::string>{"English"});
    Application app;
    app.setStudents(students);
    std::map<std::string, std::vector<std::string>> result = app.run();

    std::vector<std::string> expectedCommonLanguages{"English"};
    std::vector<std::string> expectedUniqueLanguages{"English", "Japanese", "Russian"};
    EXPECT_EQ(result["commonLanguages"].size(), 1);
    EXPECT_EQ(result["uniqueLanguages"].size(), 3);
    EXPECT_EQ(result["commonLanguages"], expectedCommonLanguages);
    EXPECT_EQ(result["uniqueLanguages"], expectedUniqueLanguages);
}

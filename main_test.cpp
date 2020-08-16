#include "gtest/gtest.h"
#include <string>
#include "main.cpp"
#include <vector>

using namespace std;

TEST(MAIN, DivisionToChunks)
{
    std::string testString = "ffaabbcc";
    std::vector<std::string> refVector = {"ff", "aa", "bb", "cc"};
    std::vector<std::string> testVector = divToChunks(testString);
    for (int index = 0; index < refVector.size(); index++)
    {
        ASSERT_EQ(testVector[index], refVector[index]);
    }
}

TEST(MAIN, DictionaryTest)
{
    const char f = 'f';
    const char c = 'c';
    const char a = 'a';

    ASSERT_EQ(dictionary(f), 15);
    ASSERT_EQ(dictionary(c), 12);
    ASSERT_EQ(dictionary(a), 10);
}

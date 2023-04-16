#include <gtest/gtest.h>
#include "io/Reader.h"

/**
 * Check if the tokens are the same as the expected tokens
 * @param tokens split string
 * @param expected expected tokens
 */
void checkTokens(std::vector<std::string> tokens, std::vector<std::string> expected) {
    ASSERT_EQ(tokens.size(), expected.size());
    for (int i = 0; i < tokens.size(); i++) {
        ASSERT_EQ(tokens[i], expected[i]);
    }
}

TEST(ReaderTest, TokenizeStringUsingComma) {
    std::string str = "1,2,3,4,5";
    std::vector<std::string> tokens = Reader::tokenize(str, ',');
    std::vector<std::string> expected = {"1", "2", "3", "4", "5"};
    checkTokens(tokens, expected);
}

TEST(ReaderTest, TokenizeStringUsingDash) {
    std::string str = "1-2-3-4-5";
    std::vector<std::string> tokens = Reader::tokenize(str, '-');
    std::vector<std::string> expected = {"1", "2", "3", "4", "5"};
    checkTokens(tokens, expected);

    str = "-a-b-c-d-e-f-";
    tokens = Reader::tokenize(str, '-');
    expected = {"", "a", "b", "c", "d", "e", "f"};
    checkTokens(tokens, expected);
}

TEST(ReaderTest, TokenizeTokensUsingSpace) {
    std::string str = "1 2 3 4 5";
    std::vector<std::string> tokens = Reader::tokenize(str, ' ');
    std::vector<std::string> expected = {"1", "2", "3", "4", "5"};
    checkTokens(tokens, expected);
}



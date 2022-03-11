//
// Created by talko on 04/03/2022.
//

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}

TEST_CASE("Good input") {
            CHECK(nospaces(mat(11, 7, '@', '-')) == nospaces("@@@@@@@@@@@\n"
                                                                                       "@---------@\n"
                                                                                       "@-@@@@@@@-@\n"
                                                                                       "@-@@---@@-@\n"
                                                                                       "@-@@@@@@@-@\n"
                                                                                       "@---------@\n"
                                                                                       "@@@@@@@@@@@"));

            CHECK(nospaces(mat(11, 5, 'a', 'A')) == nospaces("aaaaaaaaaaa\n"
                                                                                       "aAAAAAAAAAa\n"
                                                                                       "aAaaaaaaaAa\n"
                                                                                       "aAAAAAAAAAa\n"
                                                                                       "aaaaaaaaaaa"));

            CHECK(nospaces(mat(13, 13, '1', '3')) == nospaces("1111111111111\n"
                                                                                        "1333333333331\n"
                                                                                        "1311111111131\n"
                                                                                        "1311111111131\n"
                                                                                        "1311111111131\n"
                                                                                        "1311111111131\n"
                                                                                        "1311133311131\n"
                                                                                        "1311111111131\n"
                                                                                        "1311111111131\n"
                                                                                        "1311111111131\n"
                                                                                        "1311111111131\n"
                                                                                        "1333333333331\n"
                                                                                        "1111111111111"));

            CHECK(nospaces(mat(5, 5, '5', '5')) == nospaces("55555\n"
                                                                                      "55555\n"
                                                                                      "55555\n"
                                                                                      "55555\n"
                                                                                      "55555"));

            CHECK(nospaces(mat(5, 7, 'X', 'V')) == nospaces("XXXXX\n"
                                                                                      "XVVVX\n"
                                                                                      "XVXVX\n"
                                                                                      "XVXVX\n"
                                                                                      "XVXVX\n"
                                                                                      "XVVVX\n"
                                                                                      "XXXXX"));

            CHECK(nospaces(mat(11, 11, '*', ' ')) == nospaces("***********\n"
                                                                                        "*         *\n"
                                                                                        "* ******* *\n"
                                                                                        "* ******* *\n"
                                                                                        "* ******* *\n"
                                                                                        "* **   ** *\n"
                                                                                        "* ******* *\n"
                                                                                        "* ******* *\n"
                                                                                        "* ******* *\n"
                                                                                        "*         *\n"
                                                                                        "***********"));

            CHECK(nospaces(mat(11, 13, 'R', '-')) == nospaces("RRRRRRRRRRR\n"
                                                                                        "R---------R\n"
                                                                                        "R-RRRRRRR-R\n"
                                                                                        "R-RRRRRRR-R\n"
                                                                                        "R-RRRRRRR-R\n"
                                                                                        "R-RRRRRRR-R\n"
                                                                                        "R-RR---RR-R\n"
                                                                                        "R-RRRRRRR-R\n"
                                                                                        "R-RRRRRRR-R\n"
                                                                                        "R-RRRRRRR-R\n"
                                                                                        "R-RRRRRRR-R\n"
                                                                                        "R---------R\n"
                                                                                        "RRRRRRRRRRR"));

            CHECK(nospaces(mat(23, 3, '>', '<')) == nospaces(">>>>>>>>>>>>>>>>>>>>>>>\n"
                                                                                       "><<<<<<<<<<<<<<<<<<<<<>\n"
                                                                                       ">>>>>>>>>>>>>>>>>>>>>>>"));

            CHECK(nospaces(mat(21, 1, '|', '&')) == nospaces("|||||||||||||||||||||"));
}

TEST_CASE("Matrix Odd") {
    CHECK_THROWS(mat(1, 2, '$', '%'));
    CHECK_THROWS(mat(2, 1, '$', '%'));
    CHECK_THROWS(mat(10, 7, '$', '%'));
    CHECK_THROWS(mat(11, 6, '$', '%'));
    CHECK_THROWS(mat(11, 7, '$', '%'));
}

TEST_CASE("Bad characters") {
    CHECK_THROWS(mat(10, 5, ' ', '%'));
    CHECK_THROWS(mat(10, 5, '-', ' '));
    CHECK_THROWS(mat(10, 5, '\n', '%'));
    CHECK_THROWS(mat(10, 5, '-', '\n'));
    CHECK_THROWS(mat(21, 5, '\n', '\t'));
    CHECK_THROWS(mat(3, 3, '\n','%'));
    CHECK_THROWS(mat(1, 1, '$','\n'));
}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(0, 1, '$', '%'));
    CHECK_THROWS(mat(1, 0, '$', '%'));
    CHECK_THROWS(mat(0, 0, '$', '%'));
}

TEST_CASE("Negative input") {
    CHECK_THROWS(mat(-6, 1, '$', '%'));
    CHECK_THROWS(mat(1, -6, '$', '%'));
    CHECK_THROWS(mat(-6, -6, '$', '%'));
}

TEST_CASE("Impossible Matrix") {
    CHECK_THROWS(mat(1, 1, '$', '%'));
    CHECK_THROWS(mat(3, 1, '$', '%'));
    CHECK_THROWS(mat(5, 1, '$', '%'));
    CHECK_THROWS(mat(3, 3, '$', '%'));
}

TEST_CASE("Random matrix") {
    int a, b, max;
    max = 20;
    srand(time(0));
    a = rand() % max;
    b = rand() % max;

    if (a % 2 == 0) {
        a = a + 1;
    }

    if (b % 2 == 0) {
        b = b + 1;
    }

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << ariel::mat(a, b, '@', '-') << endl;
}
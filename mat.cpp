//
// Created by talko on 04/03/2022.
//

#include "mat.hpp"

using namespace std;

string ariel::mat(const int rows, const int cols, const char c1, const char c2) {
    if (rows % 2 == 0 || cols % 2 == 0) {
        throw invalid_argument("Mat size is always odd");
    }

    if (rows <= 0 || cols <= 0) {
        throw invalid_argument("This Mat is not possible");
    }

    unordered_set<char> s = {'\n','\t', ' '};
    if (s.find(c1) != s.end() || s.find(c2) != s.end()) {
        throw invalid_argument("Invalid Character");
    }

    string result = "";

    // create matrix
    for (int c = 0; c < cols; c++) {
        result += '\n';

        for (int r = 0; r < rows; r++) {
            if ((c == 1 || c == cols-2) && r > 0 && r < rows-1){
                result += c2;
            } else if((r == 1 || r == rows-2) && c > 0 && c < cols-1){
                result += c2;
            } else if (cols > 5 && c == (cols-1)/2 && r < rows-((cols-1)/2) && r > (rows-1)/((cols-1)/2)) {
                result += c2;
            } else {
                result += c1;
            }
        }
    }

    return result;
}
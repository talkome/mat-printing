/**
 * Created by talko on 04/03/2022.
 */

#include "mat.hpp"

using namespace std;

string ariel::mat(const int rows, const int cols, const char c1, const char c2) {
    if(rows > 70 || cols > 70){
        throw invalid_argument("Input too large");
    }

    if (rows % 2 == 0 || cols % 2 == 0) {
        throw invalid_argument("Mat size is always odd");
    }

    if (rows <= 0 || cols <= 0) {
        throw invalid_argument("This Mat is not possible");
    }

    if (c1 < 33 || c1 > 126 || c2 < 33 || c2 > 126) {
        throw invalid_argument("Invalid Character");
    }

    unordered_set<char> s = {'\n','\t', ' ', '\r','\a','\b','\f','\v'};
    if (s.find(c1) != s.end() && s.find(c2) != s.end()) {
        throw invalid_argument("Invalid Character");
    }

    string result;

    // create matrix
    vector< vector<char> > matrix(cols, vector<char> (rows, c1));

    // create frame
    int counter = 1;
    while(counter < min(cols,rows)){
        create_frame(matrix, rows, cols, c2,counter);
        counter += 2;
    }

    // convert to string
    for(vector<char> temp: matrix){
        string s(temp.begin(), temp.end());
        s += '\n';
        result += s;
    }

    return result;
}

void ariel::create_frame(vector<vector<char>> &mat, const int R, const int C, const char c, const int z) {
    for (int i = z; i < C - z; ++i) {
        mat[i][z] = mat[i][R - z - 1] = c;
    }

    for (int j = z; j < R - z; ++j) {
        mat[z][j] = mat[C - z - 1][j] = c;
    }
}

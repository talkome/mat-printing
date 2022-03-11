/**
 * Created by talko on 04/03/2022.
 */

#include <ctype.h>
#include <unordered_set>
#include <iostream>
#include <stdexcept>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>

using namespace std;

namespace ariel{

    string mat(const int rows, const int cols, const char c1, const char c2);

    void create_frame(vector<vector<char>> &mat, const int R, const int C, const char c, const int z);
};
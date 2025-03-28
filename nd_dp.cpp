#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<int> dp = triangle.back();
    for (int row = n - 2; row >= 0; --row)
    {
        for (int col = 0; col <= row; ++col)
        {
            dp[col] = triangle[row][col] + min(dp[col], dp[col + 1]);
        }
    }
    return dp[0];
}

int MaxProfitDpCompactFinal(const vector<int>& prices) {
    int buy1 = numeric_limits<int>::max();
    int buy2 = numeric_limits<int>::max();
    int sell1 = 0;
    int sell2 = 0;

    for (int price : prices) {
        buy1 = min(buy1, price);
        sell1 = max(sell1, price - buy1);
        buy2 = min(buy2, price - sell1);
        sell2 = max(sell2, price - buy2);
    }

    return sell2;
}


int main()
{
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};

    cout << "Minimum Path Sum: " << minimumTotal(triangle) << endl;

    vector<pair<vector<int>, int>> testCases = {
        {{1, 2, 3, 4, 5}, 4},
        {{7, 1, 5, 3, 6, 4}, 7},
        {{7, 6, 4, 3, 1}, 0},
        {{1, 2}, 1},
        {{2, 1, 2, 0, 1}, 2},
    };

    for (const auto& testCase : testCases) {
        int result = MaxProfitDpCompactFinal(testCase.first);
        cout << "Prices: ";
        for (int price : testCase.first) {
            std::cout << price << " ";
        }
        cout << "-> Expected: " << testCase.second << ", Got: " << result << endl;
    }
    return 0;
}
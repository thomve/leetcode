#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

// Given a triangle array, return the minimum path sum from top to bottom.
// For each step, you may move to an adjacent number of the row below.
// More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
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

// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// Find the maximum profit you can achieve. You may complete at most two transactions.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
int MaxProfitDpCompactFinal(const vector<int> &prices)
{
    int buy1 = numeric_limits<int>::max();
    int buy2 = numeric_limits<int>::max();
    int sell1 = 0;
    int sell2 = 0;

    for (int price : prices)
    {
        buy1 = min(buy1, price);
        sell1 = max(sell1, price - buy1);
        buy2 = min(buy2, price - sell1);
        sell2 = max(sell2, price - buy2);
    }

    return sell2;
}

// You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
// Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
int maxProfitWithKTransactions(int k, vector<int> &prices)
{
    int n = prices.size();
    if (n == 0 || k == 0)
        return 0;

    // case: k is large enough to find all profitable transactions
    if (k >= n / 2)
    {
        int maxProfit = 0;
        for (int i = 1; i < n; ++i)
        {
            if (prices[i] > prices[i - 1])
                maxProfit += prices[i] - prices[i - 1];
        }
        return maxProfit;
    }

    // DP table
    vector<vector<int>> dp(k + 1, vector<int>(n, 0));

    for (int i = 1; i <= k; ++i)
    {
        int maxDiff = -prices[0];
        for (int j = 1; j < n; ++j)
        {
            dp[i][j] = max(dp[i][j - 1], prices[j] + maxDiff);
            maxDiff = max(maxDiff, dp[i - 1][j] - prices[j]);
        }
    }

    return dp[k][n - 1];
}

// Given a string s, return the longest palindromic substring in s.
class LongestPalindromeSubstring
{
private:
    bool solve(vector<vector<bool>> &dp, int i, int j, string &s)
    {
        if (i == j)
        {
            return dp[i][j] = true;
        }
        if (j - i == 1)
        {
            if (s[i] == s[j])
            {
                return dp[i][j] = true;
            }
            else
            {
                return dp[i][j] = false;
            }
        }
        if (s[i] == s[j] && dp[i + 1][j - 1] == true)
        {
            return dp[i][j] = true;
        }
        else
        {
            return dp[i][j] = false;
        }
    }

public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        int startIndex = 0;
        int maxlen = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int g = 0; g < n; g++)
        {
            for (int i = 0, j = g; j < n; i++, j++)
            {
                solve(dp, i, j, s);
                if (dp[i][j] == true)
                {
                    if (j - i + 1 > maxlen)
                    {
                        startIndex = i;
                        maxlen = j - i + 1;
                    }
                }
            }
        }
        return s.substr(startIndex, maxlen);
    }
};

// Other solution using "expand around center" approach
string longestPalindrome(string s)
{
    if (s.empty())
        return "";

    // Step 1: Transform the string
    string t = "#";
    for (char c : s)
    {
        t += c;
        t += "#";
    }

    int n = t.size();
    vector<int> P(n, 0); // Stores palindrome lengths
    int C = 0, R = 0;    // Center and right boundary
    int maxLen = 0, centerIndex = 0;

    // Step 2: Expand around center
    for (int i = 0; i < n; i++)
    {
        int mirror = 2 * C - i; // Mirror index

        // If within the right boundary, use the mirror's value
        if (i < R)
            P[i] = min(R - i, P[mirror]);

        // Expand around center
        while (i + P[i] + 1 < n && i - P[i] - 1 >= 0 && t[i + P[i] + 1] == t[i - P[i] - 1])
        {
            P[i]++;
        }

        // Update center and right boundary
        if (i + P[i] > R)
        {
            C = i;
            R = i + P[i];
        }

        // Update longest palindrome info
        if (P[i] > maxLen)
        {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    // Step 3: Extract the longest palindromic substring
    int start = (centerIndex - maxLen) / 2; // Convert back to original indices
    return s.substr(start, maxLen);
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

    for (const auto &testCase : testCases)
    {
        int result = MaxProfitDpCompactFinal(testCase.first);
        cout << "Prices: ";
        for (int price : testCase.first)
        {
            std::cout << price << " ";
        }
        cout << "-> Expected: " << testCase.second << ", Got: " << result << endl;
    }

    vector<int> prices = {3, 2, 6, 5, 0, 3};
    int k = 2;
    cout << "Maximum Profit: " << maxProfitWithKTransactions(k, prices) << endl;

    string sampleString = "babad";
    LongestPalindromeSubstring lps;
    string longestPalindrome = lps.longestPalindrome(sampleString);
    cout << "Longest Palindromic Substring: " << longestPalindrome << std::endl;

    return 0;
}
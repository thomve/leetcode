#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. 
// If that amount of money cannot be made up by any combination of the coins, return -1.
// You may assume that you have an infinite number of each kind of coin.
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    
    for (int coin : coins) {
        for (int j = coin; j <= amount; j++) {
            if (dp[j - coin] != INT_MAX) {
                dp[j] = min(dp[j], dp[j - coin] + 1);
            }
        }
    }
    
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

// Given an integer array nums, return the length of the longest strictly increasing subsequence.
int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int n = nums.size();
    vector<int> dp(n, 1);
    int maxLength = 1;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLength = max(maxLength, dp[i]);
    }
    
    return maxLength;
}

// Other solution: faster
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size(), curr = 1;
    vector<int> dp = {nums[0]};
    for(int i = 1; i < n; i++)
    {
        if (dp[curr - 1] < nums[i])
        {
            dp.push_back(nums[i]);
            curr++;
        }
        else
        {
            auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
            *it = nums[i];
        }
    }
    return curr;
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << "Minimum coins required: " << coinChange(coins, amount) << endl;

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: " << lengthOfLIS(nums) << endl;

    return 0;
}
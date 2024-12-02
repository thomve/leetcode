#include <iostream>
#include <vector>

using namespace std;


int maxProfit(vector<int>& prices) {
    int max_profit = 0;
    for (size_t i = 1; i < prices.size(); ++i) {
        if (prices[i] > prices[i - 1]) {
            max_profit += prices[i] - prices[i - 1];
        }
    }
    return max_profit;
}

bool canJump(vector<int>& nums) {
    int max_reach = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (i > max_reach) {
            return false;
        }
        max_reach = std::max(max_reach, static_cast<int>(i) + nums[i]);
        if (max_reach >= nums.size() - 1) {
            return true;
        }
    }
    return false;
}

int minJump(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return 0;
    if (nums[0] == 0) return -1;

    int jumps = 0;
    int farthest = 0;
    int currentEnd = 0;

    for (int i = 0; i < n - 1; ++i) {
        farthest = std::max(farthest, i + nums[i]);

        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;

            if (currentEnd >= n - 1) break;
        }
    }

    return jumps;
}

int main() {
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    std::cout << "Maximum Profit: " << maxProfit(prices) << std::endl;

    std::vector<int> nums = {2, 3, 1, 1, 4};
    std::cout << (canJump(nums) ? "true" : "false") << std::endl;

    nums = {3, 2, 1, 0, 4};
    std::cout << (canJump(nums) ? "true" : "false") << std::endl;

    std::cout << "Minimum number of jumps: " << minJump(nums) << std::endl;
    
    return 0;
}
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class MaxSubArrayWithKadanesAlg {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = nums[0];
        
        for (size_t i = 1; i < nums.size(); i++) {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    MaxSubArrayWithKadanesAlg msa;
    cout << "Maximum Subarray Sum: " << msa.maxSubArray(nums) << endl;
    return 0;
}

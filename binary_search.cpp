#include <vector>
#include <iostream>

class MinRotatedArray {
public:
    int findMin(std::vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return nums[left];
    }
};

int main() {
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    MinRotatedArray mra;
    std::cout << "Minimum element: " << mra.findMin(nums) << std::endl;
    return 0;
}

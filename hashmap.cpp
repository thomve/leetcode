#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> mp(nums.begin(), nums.end());
    int n = nums.size();
    int longest = 0;
    for (auto it : mp)
    {
        if (mp.find(it - 1) == mp.end())
        {
            int cnt = 1;
            while (mp.find(it + cnt) != mp.end())
            {
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> num_map;
    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];
        if (num_map.find(complement) != num_map.end())
        {
            return {num_map[complement], i};
        }
        num_map[nums[i]] = i;
    }
    return {};
}

class HappyNumber
{
public:
    int sumOfSquares(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        unordered_set<int> seen;

        while (n != 1 && seen.find(n) == seen.end())
        {
            seen.insert(n);
            n = sumOfSquares(n);
        }

        return n == 1;
    }
};

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Longest Consecutive Sequence Length: " << longestConsecutive(nums) << endl;

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
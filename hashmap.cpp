#include <iostream>
#include <vector>
#include <unordered_set>

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

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Longest Consecutive Sequence Length: " << longestConsecutive(nums) << endl;
}
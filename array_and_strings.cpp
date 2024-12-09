#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <unordered_map>
#include <cstdlib>
#include <set>
#include <numeric>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int max_profit = 0;
    for (size_t i = 1; i < prices.size(); ++i)
    {
        if (prices[i] > prices[i - 1])
        {
            max_profit += prices[i] - prices[i - 1];
        }
    }
    return max_profit;
}

bool canJump(vector<int> &nums)
{
    int max_reach = 0;
    for (size_t i = 0; i < nums.size(); ++i)
    {
        if (i > max_reach)
        {
            return false;
        }
        max_reach = std::max(max_reach, static_cast<int>(i) + nums[i]);
        if (max_reach >= nums.size() - 1)
        {
            return true;
        }
    }
    return false;
}

int minJump(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 1)
        return 0;
    if (nums[0] == 0)
        return -1;

    int jumps = 0;
    int farthest = 0;
    int currentEnd = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        farthest = std::max(farthest, i + nums[i]);

        if (i == currentEnd)
        {
            jumps++;
            currentEnd = farthest;

            if (currentEnd >= n - 1)
                break;
        }
    }

    return jumps;
}

int hIndex(vector<int> &citations)
{
    sort(citations.begin(), citations.end(), greater<int>());
    int i = 1;
    for (auto it : citations)
    {
        if (it >= i)
        {
            i++;
        }
        else
        {
            break;
        }
    }
    return i - 1;
}

class RandomizedSet {
public:
    RandomizedSet() {
        srand(static_cast<unsigned int>(time(0)));
    }
    
    bool insert(int val) {
        auto ret = mySet.insert(val);
        return ret.second;
    }
    
    bool remove(int val) {
        int res = mySet.erase(val);
        return res ? true : false;
    }
    
    int getRandom() {
        int randomNumber = rand() % mySet.size();
        return *(std::next(mySet.begin(), randomNumber));
    }

    void printSet() const {
        std::cout << "{ ";
        for (const auto& elem : mySet) {
            std::cout << elem << " ";
        }
        std::cout << "}" << std::endl;
    }

    std::set<int> mySet;
};

std::vector<int> productExceptSelf(vector<int>& products) {
    std::vector<int> output(products.size(), 1);

    int left = 1;
    for (int i = 0; i < products.size(); i++) {
        output[i] *= left;
        left *= products[i];
    }

    int right = 1;
    for (int i = products.size() - 1; i >= 0; i--) {
        output[i] *= right;
        right *= products[i];
    }
    return output;        
}

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0, total_cost = 0;
        int tank = 0, start = 0;

        for (int i = 0; i < gas.size(); ++i) {
            total_gas += gas[i];
            total_cost += cost[i];
            tank += gas[i] - cost[i];

            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        return total_gas >= total_cost ? start : -1;
    }

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies(n, 1);
    
    for(int i = 1; i < n; i++) {
        if(ratings[i] > ratings[i-1]) {
            candies[i] = candies[i-1] + 1;
        }
    }
    
    for(int i = n-2; i >= 0; i--) {
        if(ratings[i] > ratings[i+1]) {
            candies[i] = max(candies[i], candies[i+1] + 1);
        }
    }
    
    return std::accumulate(candies.begin(), candies.end(), 0);
}

int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    int left = 0, right = n - 1;
    int left_max = 0, right_max = 0;
    int water_trapped = 0;

    while (left < right) {
        if (height[left] <= height[right]) {
            if (height[left] >= left_max) {
                left_max = height[left];
            } else {
                water_trapped += left_max - height[left];
            }
            ++left;
        } else {
            if (height[right] >= right_max) {
                right_max = height[right];
            } else {
                water_trapped += right_max - height[right];
            }
            --right;
        }
    }
    return water_trapped;
}

int romanToInt(string s) {
    unordered_map<char, int> m;
    
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    
    int ans = 0;
    
    for(int i = 0; i < s.length(); i++){
        if(m[s[i]] < m[s[i+1]]){
            ans -= m[s[i]];
        }
        else{
            ans += m[s[i]];
        }
    }
    return ans;
}

string intToRoman(int num) {
    const pair<int, string> roman[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    string result = "";

    for (const auto& [value, symbol] : roman) {
        while (num >= value) {
            result += symbol;
            num -= value;
        }
    }

    return result;
}

int lengthOfLastWord(string s) {
    int length = 0;
    bool counting = false;
    
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] != ' ') {
            counting = true;
            length++;
        }
        else if (counting) {
            break;
        }
    }
    
    return length;
}

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    string prefix = strs[0];

    for (int i = 1; i < strs.size(); i++) {
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length() - 1);

            if (prefix.empty()) return "";
        }
    }

    return prefix;
}

string reverseWords(string s) {
    std::stringstream str(s);
    string word;
    vector <string> result;
    
    while(str >> word) {
        result.push_back(word + ' ');
    }
    std::reverse(result.begin(),result.end());

    string result1;

    for (size_t i = 0; i < result.size(); ++i) {
        result1 += result[i];
    }
    while (!result1.empty() && result1[result1.length() - 1] == ' ') {
        result1.pop_back();
    }
    return result1;
}

string convert(string s, int numRows) {
    if (numRows == 1 || numRows >= s.size()) return s;
    std::vector<string> rows(min(numRows, int(s.size())));
    int curRow = 0;
    bool goingDown = false;

    for (char c : s) {
        rows[curRow] += c;
        if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
        curRow += goingDown ? 1 : -1;
    }

    string result;
    for (const string& row : rows) result += row;
    return result;
}

int main()
{
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    std::cout << "Maximum Profit: " << maxProfit(prices) << std::endl;

    std::vector<int> nums = {2, 3, 1, 1, 4};
    std::cout << (canJump(nums) ? "true" : "false") << std::endl;

    nums = {3, 2, 1, 0, 4};
    std::cout << (canJump(nums) ? "true" : "false") << std::endl;

    std::cout << "Minimum number of jumps: " << minJump(nums) << std::endl;

    std::vector<int> citations = {3, 0, 6, 1, 5};
    std::cout << "H-Index: " << hIndex(citations) << std::endl;

    RandomizedSet* obj = new RandomizedSet();
    std::cout << "obj is: " << obj << std::endl;
    bool param_1 = obj->insert(2);
    obj->insert(4);
    std::cout << "param1 is: " << param_1 << std::endl;
    bool param_2 = obj->remove(2);
    std::cout << "param2 is: " << param_2 << std::endl;
    
    obj->printSet();
    
    int param_3 = obj->getRandom();
    
    std::cout << "param3 is: " << param_3 << std::endl;

    std::vector<int> products = {2, 2, 3, 4};
    std::vector<int> result = productExceptSelf(products);

    for (int val : result) {
        std::cout << val << " ";
    }

    std::vector<int> gas = {1, 2, 3, 4, 5};
    std::vector<int> cost = {3, 4, 5, 1, 2};
    int index = canCompleteCircuit(gas, cost);
    std::cout << "Starting gas station index: " << index << std::endl;


    std::vector<int> ratings = {1, 0, 2};
    int ncandy = candy(ratings);
    std::cout << "Minimum candies required: " << ncandy << std::endl;

    std::vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int trapped_water = trap(height);
    std::cout << "Water trapped: " << trapped_water << std::endl;

    string romanNumeral = "MCMXCIV";
    int numeric_roman = romanToInt(romanNumeral);
    cout << "The integer value is: " << numeric_roman << endl;

    int numerical_roman = 1994;
    string roman_numeral = intToRoman(numerical_roman);
    cout << "The roman numeral is: " << roman_numeral << endl;

    string s = "Hello World";
    int len_last_word = lengthOfLastWord(s);
    cout << "The length of the last word is: " << len_last_word << endl;

    std::vector<string> strs = {"flower", "flow", "flight"};
    string common_prefix = longestCommonPrefix(strs);
    cout << "The longest common prefix is: " << common_prefix << endl;

    string sentence = "the sky is blue";
    string reversed_sentence = reverseWords(sentence);
    cout << "The reversed sentence is: " << reversed_sentence << endl;
    
    string zigzag = "PAYPALISHIRING";
    int numRows = 3;
    string zigzag_string = convert(zigzag, numRows);
    cout << "The zigzag string is: " << zigzag_string << endl;
    
    return 0;
}
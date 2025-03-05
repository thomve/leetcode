#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <climits>
#include <unordered_map>
#include <cstdlib>
#include <set>
#include <numeric>
#include <unordered_map>
#include <string>
#include <sstream>
#include <unordered_set>

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

class RandomizedSet
{
public:
    RandomizedSet()
    {
        srand(static_cast<unsigned int>(time(0)));
    }

    bool insert(int val)
    {
        auto ret = mySet.insert(val);
        return ret.second;
    }

    bool remove(int val)
    {
        int res = mySet.erase(val);
        return res ? true : false;
    }

    int getRandom()
    {
        int randomNumber = rand() % mySet.size();
        return *(std::next(mySet.begin(), randomNumber));
    }

    void printSet() const
    {
        std::cout << "{ ";
        for (const auto &elem : mySet)
        {
            std::cout << elem << " ";
        }
        std::cout << "}" << std::endl;
    }

    std::set<int> mySet;
};

std::vector<int> productExceptSelf(vector<int> &products)
{
    std::vector<int> output(products.size(), 1);

    int left = 1;
    for (int i = 0; i < products.size(); i++)
    {
        output[i] *= left;
        left *= products[i];
    }

    int right = 1;
    for (int i = products.size() - 1; i >= 0; i--)
    {
        output[i] *= right;
        right *= products[i];
    }
    return output;
}

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int total_gas = 0, total_cost = 0;
    int tank = 0, start = 0;

    for (int i = 0; i < gas.size(); ++i)
    {
        total_gas += gas[i];
        total_cost += cost[i];
        tank += gas[i] - cost[i];

        if (tank < 0)
        {
            start = i + 1;
            tank = 0;
        }
    }
    return total_gas >= total_cost ? start : -1;
}

int candy(vector<int> &ratings)
{
    int n = ratings.size();
    vector<int> candies(n, 1);

    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            candies[i] = candies[i - 1] + 1;
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    return std::accumulate(candies.begin(), candies.end(), 0);
}

int trap(vector<int> &height)
{
    int n = height.size();
    if (n == 0)
        return 0;

    int left = 0, right = n - 1;
    int left_max = 0, right_max = 0;
    int water_trapped = 0;

    while (left < right)
    {
        if (height[left] <= height[right])
        {
            if (height[left] >= left_max)
            {
                left_max = height[left];
            }
            else
            {
                water_trapped += left_max - height[left];
            }
            ++left;
        }
        else
        {
            if (height[right] >= right_max)
            {
                right_max = height[right];
            }
            else
            {
                water_trapped += right_max - height[right];
            }
            --right;
        }
    }
    return water_trapped;
}

int romanToInt(string s)
{
    unordered_map<char, int> m;

    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    int ans = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (m[s[i]] < m[s[i + 1]])
        {
            ans -= m[s[i]];
        }
        else
        {
            ans += m[s[i]];
        }
    }
    return ans;
}

string intToRoman(int num)
{
    const pair<int, string> roman[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

    string result = "";

    for (const auto &[value, symbol] : roman)
    {
        while (num >= value)
        {
            result += symbol;
            num -= value;
        }
    }

    return result;
}

int lengthOfLastWord(string s)
{
    int length = 0;
    bool counting = false;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] != ' ')
        {
            counting = true;
            length++;
        }
        else if (counting)
        {
            break;
        }
    }

    return length;
}

string longestCommonPrefix(vector<string> &strs)
{
    if (strs.empty())
        return "";

    string prefix = strs[0];

    for (int i = 1; i < strs.size(); i++)
    {
        while (strs[i].find(prefix) != 0)
        {
            prefix = prefix.substr(0, prefix.length() - 1);

            if (prefix.empty())
                return "";
        }
    }

    return prefix;
}

string reverseWords(string s)
{
    std::stringstream str(s);
    string word;
    vector<string> result;

    while (str >> word)
    {
        result.push_back(word + ' ');
    }
    std::reverse(result.begin(), result.end());

    string result1;

    for (size_t i = 0; i < result.size(); ++i)
    {
        result1 += result[i];
    }
    while (!result1.empty() && result1[result1.length() - 1] == ' ')
    {
        result1.pop_back();
    }
    return result1;
}

string convert(string s, int numRows)
{
    if (numRows == 1 || numRows >= s.size())
        return s;
    std::vector<string> rows(min(numRows, int(s.size())));
    int curRow = 0;
    bool goingDown = false;

    for (char c : s)
    {
        rows[curRow] += c;
        if (curRow == 0 || curRow == numRows - 1)
            goingDown = !goingDown;
        curRow += goingDown ? 1 : -1;
    }

    string result;
    for (const string &row : rows)
        result += row;
    return result;
}

int strStr(string haystack, string needle)
{
    if (needle.empty())
        return 0;
    int n = haystack.size();
    int m = needle.size();

    for (int i = 0; i <= n - m; i++)
    {
        if (haystack.substr(i, m) == needle)
        {
            return i;
        }
    }
    return -1;
}

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    vector<string> result;
    vector<string> line;
    int line_length = 0;

    for (const string &word : words)
    {
        if (line_length + word.size() + line.size() > maxWidth)
        {
            int spaces = maxWidth - line_length;
            for (int i = 0; i < spaces; ++i)
            {
                line[i % (line.size() - 1 ? line.size() - 1 : 1)] += ' ';
            }
            stringstream ss;
            for (const string &s : line)
                ss << s;
            result.push_back(ss.str());
            line.clear();
            line_length = 0;
        }

        line.push_back(word);
        line_length += word.size();
    }
    stringstream ss;
    for (size_t i = 0; i < line.size(); ++i)
    {
        ss << line[i];
        if (i != line.size() - 1)
            ss << ' ';
    }
    string last_line = ss.str();
    last_line.append(maxWidth - last_line.size(), ' ');
    result.push_back(last_line);

    return result;
}

char toLower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        return ch - 'A' + 'a';
    }
    return ch;
}
bool isAlphaNumeric(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}
bool isPalindrome(string s)
{
    int i = 0, j = s.length() - 1;
    while (i < j)
    {
        while (i < j && !isAlphaNumeric(s[i]))
            i++;
        while (i < j && !isAlphaNumeric(s[j]))
            j--;

        if (toLower(s[i]) != toLower(s[j]))
        {
            return false;
        }
        else
        {
            i++;
            j--;
        }
    }
    return true;
}

bool isSubsequence(string s, string t)
{
    int sIndex = 0, tIndex = 0;
    while (sIndex < s.size() && tIndex < t.size())
    {
        if (s[sIndex] == t[tIndex])
        {
            sIndex++;
        }
        tIndex++;
    }
    return sIndex == s.size();
}

vector<int> twoSum(vector<int> &numbers, int target)
{
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right)
    {
        int sum = numbers[left] + numbers[right];

        if (sum == target)
        {
            return {left + 1, right + 1};
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return {};
}

int maxArea(vector<int> &height)
{
    int left = 0, right = height.size() - 1;
    int max_area = 0;

    while (left < right)
    {
        int area = min(height[left], height[right]) * (right - left);
        max_area = max(max_area, area);

        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return max_area;
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int total = nums[i] + nums[j] + nums[k];
            if (total > 0)
                --k;
            else if (total < 0)
                ++j;
            else
            {
                res.push_back({nums[i], nums[j], nums[k]});
                ++j;

                while (nums[j] == nums[j - 1] && j < k)
                    ++j;
            }
        }
    }
    return res;
}

int minSubArrayLen(int target, vector<int> &nums)
{
    int n = nums.size();
    int left = 0, sum = 0;
    int minLength = INT_MAX;

    for (int right = 0; right < n; ++right)
    {
        sum += nums[right];

        while (sum >= target)
        {
            minLength = min(minLength, right - left + 1);
            sum -= nums[left++];
        }
    }

    return (minLength == INT_MAX) ? 0 : minLength;
}

int lengthOfLongestSubstring(string s)
{
    bool CharArray[255];
    for (int i = 0; i < 255; ++i)
    {
        CharArray[i] = false;
    }

    int MaxLength = 0;
    int StringStartIndex = 0;
    int StringEndIndex = 0;

    while (StringEndIndex < s.size())
    {
        char CurrentChar = s[StringEndIndex];
        if (CharArray[CurrentChar])
        {
            while (StringStartIndex < StringEndIndex)
            {
                char LeadingCharacter = s[StringStartIndex];
                CharArray[LeadingCharacter] = false;
                StringStartIndex++;
                if (LeadingCharacter == CurrentChar)
                {
                    break;
                }
            }
        }

        CharArray[CurrentChar] = true;

        StringEndIndex++;
        int Length = StringEndIndex - StringStartIndex;
        if (Length > MaxLength)
        {
            MaxLength = Length;
        }
    }
    return MaxLength;
}

bool isValidSudoku(vector<vector<char>> &board)
{
    vector<unordered_set<char>> rows(9), cols(9), boxes(9);

    for (int r = 0; r < 9; ++r)
    {
        for (int c = 0; c < 9; ++c)
        {
            char num = board[r][c];
            if (num == '.')
                continue;
            int boxIndex = (r / 3) * 3 + (c / 3);

            if (rows[r].count(num) || cols[c].count(num) || boxes[boxIndex].count(num))
            {
                return false;
            }

            rows[r].insert(num);
            cols[c].insert(num);
            boxes[boxIndex].insert(num);
        }
    }

    return true;
}

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    // 00 01 02 12 22 21 20 10 11
    vector<int> v;
    // first row last column last row first column second row n-i-1 column (second last column)
    int n = matrix.size();
    int m = matrix[0].size();

    int top = 0, left = 0, right = m - 1, bottom = n - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            v.push_back(matrix[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            v.push_back(matrix[i][right]);
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                v.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                v.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return v;
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

    RandomizedSet *obj = new RandomizedSet();
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

    for (int val : result)
    {
        std::cout << val << " ";
    }

    std::vector<int> gas = {1, 2, 3, 4, 5};
    std::vector<int> cost = {3, 4, 5, 1, 2};
    int index = canCompleteCircuit(gas, cost);
    std::cout << "Starting gas station index: " << index << std::endl;

    std::vector<int> ratings = {1, 0, 2};
    int ncandy = candy(ratings);
    std::cout << "Minimum candies required: " << ncandy << std::endl;

    std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
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

    string haystack = "hello";
    string needle = "ll";
    int d = strStr(haystack, needle);
    cout << "The index of the needle is: " << d << endl;

    std::vector<string> words = {"This", "is", "an", "example", "of", "text", "justification"};
    int maxWidth = 16;
    std::vector<string> justified_text = fullJustify(words, maxWidth);
    for (const string &text : justified_text)
    {
        cout << text << endl;
    }

    string palindrome = "A man, a plan, a canal: Panama";
    cout << "Is the string a palindrome: " << isPalindrome(palindrome) << endl;

    string palindrome_bis = "Not a palindrome";
    cout << "Is the string a palindrome: " << isPalindrome(palindrome_bis) << endl;

    string s1 = "abc", t1 = "ahbgdc";
    cout << "Is s a subsequence of t: " << isSubsequence(s1, t1) << endl;

    std::vector<int> numbers = {2, 6, 7, 11, 15};
    int target = 9;
    std::vector<int> indices = twoSum(numbers, target);
    cout << "The indices are: ";
    for (int index : indices)
    {
        cout << index << " ";
    }
    cout << endl;

    std::vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "The maximum area is: " << maxArea(heights) << endl;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);

    for (const auto &triplet : result)
    {
        cout << "[";
        for (int num : triplet)
        {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
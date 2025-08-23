#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
// Return the answer in any order.
// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
// Example:
// Input: digits = "23"
// ["ad","ae","af","bd","be","bf","cd","ce","cf"]
class LetterCombinationsOfAPhoneNumber
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};

        unordered_map<char, string> phoneMap = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        vector<string> result;
        string current;

        backtrack(0, digits, phoneMap, current, result);
        return result;
    }

private:
    void backtrack(int index, const string &digits, unordered_map<char, string> &phoneMap,
                   string &current, vector<string> &result)
    {
        if (index == digits.size())
        {
            result.push_back(current);
            return;
        }

        char digit = digits[index];
        string letters = phoneMap[digit];

        for (char letter : letters)
        {
            current.push_back(letter);
            backtrack(index + 1, digits, phoneMap, current, result);
            current.pop_back(); // Backtrack
        }
    }
};

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return the number of distinct solutions to the n-queens puzzle.
class NQueensSolution
{
public:
    int totalNQueens(int n)
    {
        vector<bool> col(n), diag(2 * n - 1), anti_diag(2 * n - 1);
        return solve(col, diag, anti_diag, 0);
    }

private:
    int solve(vector<bool> &col, vector<bool> &diag, vector<bool> &anti_diag, int row)
    {
        int n = size(col), count = 0;
        if (row == n)
            return 1;
        for (int column = 0; column < n; column++)
            if (!col[column] && !diag[row + column] && !anti_diag[row - column + n - 1])
            {
                col[column] = diag[row + column] = anti_diag[row - column + n - 1] = true;
                count += solve(col, diag, anti_diag, row + 1);
                col[column] = diag[row + column] = anti_diag[row - column + n - 1] = false;
            }
        return count;
    }
};

int main()
{
    LetterCombinationsOfAPhoneNumber lc;
    string digits;
    cout << "Enter digits: ";
    cin >> digits;

    vector<string> combinations = lc.letterCombinations(digits);

    cout << "Possible letter combinations: ";
    for (const string &comb : combinations)
    {
        cout << comb << " ";
    }
    cout << endl;

    int numberOfQueens = 4;
    cout << "Enter the value of n: ";
    NQueensSolution nqs;
    cout << "Number of solutions: " << nqs.totalNQueens(numberOfQueens) << endl;

    return 0;
}
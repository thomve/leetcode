#include <stack>
#include <limits.h>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class MinStack
{
public:
    stack<pair<int, int>> st;
    int ans = INT_MAX;

    MinStack()
    {
    }

    void push(int val)
    {
        ans = min(ans, val);
        st.push({val, ans});
    }

    void pop()
    {
        st.pop();
        if (st.size() == 0)
        {
            ans = INT_MAX;
        }
        else
        {
            ans = st.top().second;
        }
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {

        return st.top().second;
    }
};

string simplifyPath(string path) {
    std::stack<std::string> st;
    std::stringstream ss(path);
    std::string token;

    while (std::getline(ss, token, '/')) {
        if (token.empty() || token == ".") {
            continue;
        } else if (token == "..") {
            if (!st.empty()) {
                st.pop();
            }
        } else {
            st.push(token);
        }
    }

    std::string result;
    std::vector<std::string> components;
    while (!st.empty()) {
        components.push_back(st.top());
        st.pop();
    }

    for (auto it = components.rbegin(); it != components.rend(); ++it) {
        result += "/" + *it;
    }

    return result.empty() ? "/" : result;
}
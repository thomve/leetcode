#include <stack>
#include <limits.h>

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
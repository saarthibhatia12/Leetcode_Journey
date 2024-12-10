class Solution
{
public:
    string removeKdigits(string s, int k)
    {
        string ans;
        int n = s.length();
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top() > s[i] && k > 0)
            {
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        while (k > 0 && !st.empty())
        {
            st.pop();
            k--;
        }
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        // Remove leading zeros
        size_t i = 0;
        while (i < ans.size() && ans[i] == '0')
        {
            ++i;
        }

        if (i == ans.size())
        {
            ans = "0";
        }
        else
        {
            ans = ans.substr(i);
        }

        return ans;
    }
};

// T.C.=O(N){For traversing through all string}+O(k){removing remaining digits}+O(N){Stack-to-string conversion}+O(N){remove leading zeroes}

// S.C.=O(2N){Stack + string(required for returning the ans cant be avoided)}
// We can use string as a stack to remove the extra space complexity required by stack.

// Approach:
// 1. We keep pushing to the stack till the digits are in increasing order.
// 2. if we encounter a digit which breaks the increasing order we pop from stack  untill the stack top is greater than digit and push the new digit.
// (We simultaneously decrease the value of k and keep a check whether k is still greater than zero)

// 3. after scanning through all digits we ensure that stack is empty by popping digits from stack and simultaneously adding it to the string.

// 4. we reverse the string since stack is a LIFO data structure and remove the leading zeroes.

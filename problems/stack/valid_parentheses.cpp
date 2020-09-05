//
// Created by 甘唯哲 on 2020/9/5.
//

//https://leetcode.com/problems/valid-parentheses/

#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s)
    {
        std::stack<char> st;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            } else
            {
                if (st.empty())
                    return false;
                else if ( (st.top() == '(' && s[i] == ')') ||
                          (st.top() == '[' && s[i] == ']') ||
                          (st.top() == '{' && s[i] == '}') )
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};
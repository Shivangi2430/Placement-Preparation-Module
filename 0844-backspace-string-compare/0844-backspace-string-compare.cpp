/*class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int>st1, st2;
        string ans1, ans2;
        for(int i = 0; i<s.length(); i++)
        {
            if(s[i]=='#' && !st1.empty())
                st1.pop();
            else if( s[i] != '#')
                st1.push(s[i]);
        }
        while(!st1.empty())
        {
            ans1.push_back(st1.top());
            st1.pop();
        }

        
        for(int i = 0; i<t.length(); i++)
        {
            if(t[i]=='#' && !st2.empty())
                st2.pop();
            else if (t[i] != '#')
                st2.push(t[i]);
        }
        while(!st2.empty())
        {
            ans2.push_back(st2.top());
            st2.pop();
        }
        
        return ans1 == ans2;
    }
};
*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int>st1, st2;
        
        for(int i = 0; i<s.length(); i++)
        {
            if(s[i]=='#' && !st1.empty())
                st1.pop();
            else if( s[i] != '#')
                st1.push(s[i]);
        }
        
        for(int i = 0; i<t.length(); i++)
        {
            if(t[i]=='#' && !st2.empty())
                st2.pop();
            else if (t[i] != '#')
                st2.push(t[i]);
        }
        
        return st1 == st2;
    }
};
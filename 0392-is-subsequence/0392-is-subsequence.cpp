class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0, j=0;
        
        while(i<s.length() && j<t.length())
        {
            if(s[i] == t[j])
            {
                i++;
            }
            j++;
        }
        return i == s.length();
    }
};
       /* int m = s.size();
        int n = t.size();
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == m ? 1 : 0;*/
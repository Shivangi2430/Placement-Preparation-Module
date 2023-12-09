class Solution {
public:
    bool isValid(char ch)
    {
        if(ch>='a' && ch<='z' || ch>='A' && ch<='Z' || ch>='0' && ch<='9')
            return true;
        else 
            return false;
    }
    
    bool checkPalindrome(string str)
    {
        int start = 0;
        int end  = str.length() - 1;
        while(start <= end)
        {
            if(str[start] != str[end])
                return false;
            else
            {
                start++;
                end--;
            }
        }
        return true;
    }
    
    bool isPalindrome(string s) {
        string temp = "";
        for(int i = 0; i<s.length(); i++)
        {
            if(isValid(s[i]))
                temp.push_back(s[i]);
        }
        for(int i=0; i<temp.length(); i++)
        {
            temp[i] = tolower(temp[i]);
        }
        return checkPalindrome(temp);
    }
};

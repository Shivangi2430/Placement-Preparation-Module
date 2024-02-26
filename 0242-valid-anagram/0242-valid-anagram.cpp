class Solution {
public:
    bool isAnagram(string s, string t) {
        // TC = O(n) n = length of the string
        // SC = O(1)
      if(s.length() != t.length())
        {
            return false;
        }
       unordered_map<char, int> mp;

       for (int i = 0; i < s.length(); i++)
           mp[s[i]]++;

       for (int i = 0; i < t.length(); i++)
       {
           if (mp.find(t[i]) == mp.end() || mp[t[i]] == 0) 
               return false;
           
           else 
             mp[t[i]]--;    
       }
   
       // Check if all frequencies are zero
       for (const auto& it : mp)
       {
           if (it.second != 0)
               return false;
       }
   
       return true;
           
       /* int arr[26] = {0};
        for(int i=0; i<s.length(); i++){
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
        }
        for(int i=0; i<26; i++){
            if(arr[i] != 0){
                return false;
            }
        }
        return true;*/

     /* TC = O(nlogn)
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t) return true;
        else return false; 
        */
    }
};
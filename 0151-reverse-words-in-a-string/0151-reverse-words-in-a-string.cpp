class Solution {
public:
    string reverseWords(string s) {
    // TC = O(n)
    // SC = O(1)
    int n = s.length();
    
     //phle poori string reverse karenge
    
     reverse(s.begin(), s.end());

     int i = 0;
     int l = 0, r = 0;

     while(i < n)
     {
         while(i < n && s[i] != ' ')
         {
             s[r++] = s[i++];  // i ne r ko jo bhi string encounter hua use assign kar diya
         }
             //jaise hi space encounter kiya i ne tab l se leke r tak ke string reverse ho jayenge
           if(l < r)  // l.......r   
           {
             reverse(s.begin() + l, s.begin() + r);
             s[r] = ' '; // r ab apne pass ek space assign krlega
             r++;
             // ab l jo hai r ke pass aa jayega
             l = r;
           }
        i++;
     }
           // ek extra space bach jayega last me isliye use remove kr denge
         s = s.substr(0, r-1); // (star index, length(kitna length chahiye))

         return s;
    }
};
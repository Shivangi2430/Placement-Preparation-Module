class Solution {
public:
    bool checkValidString(string s) {
        
        int n = s.length();
        stack<int> open, star;
        
        for(int i=0; i<n; i++)
        {
            if(s[i] == '(')   //push all open brackets indices in open stack
                open.push(i);
            else if(s[i] == '*')  //push star indices in star stack
                star.push(i);
            else //case of closing bracket
            {
                if(!open.empty())
                    open.pop();
                else if(!star.empty())
                    star.pop();
                else
                    return false;
            }
        }
        
        // now we will handle the case if there is any open brackets are left in the open stack
        
        while(!open.empty())
        {
          if(star.empty())    //if star is empty then we can not balance the open bracket hence return false
            return false;
         
          else if(star.top() > open.top())   //star must come after open bracket to balance the open bracket
          {
              open.pop();
              star.pop();
          }
          
          else  // open.top() > star.top  ex:- *( not possible
              return false;
        }
        
        return true;
    }
};

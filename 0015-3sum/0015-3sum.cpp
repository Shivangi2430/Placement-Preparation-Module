class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        
        
        for(int i = 0; i < n; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            
            int j = i + 1;
            int k = n - 1;
            
        while(j < k)
         {
            int sum = nums[i] + nums[j] + nums[k];
            
            if(sum < 0)
            {
                j++;
            }
            else if(sum > 0)
            {
                k--;
            }
            else
            {
                vector<int>temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                
                while(j < k && nums[j] == nums[j - 1])
                    j++;
                while(j < k && nums[k] == nums[k + 1])
                    k--;
            }
          }
        }
        return ans;
        
    /*sort(nums.begin(), nums.end());
    
    vector<vector<int>>result;
    // b+c = -a  (2sum problem)
    // for 'a' to move
    for(int i=0; i<nums.size()-2; i++)
    {
       if(i==0 || (i>0 && nums[i] != nums[i-1])) 
       { 
       int sum = 0 - nums[i];
       int low = i+1;
       int high = nums.size()-1;

       while(low<high)
         {
           if(nums[low] + nums[high] == sum)
           {
               vector<int>temp;
               temp.push_back(nums[i]);
               temp.push_back(nums[low]);
               temp.push_back(nums[high]);
               result.push_back(temp);

               while(low<high && nums[low] == nums[low+1])
               low++;
                 
               while(low<high && nums[high] == nums[high-1])
               high--;

               low++;
               high--;

           }

           else if(nums[low] + nums[high] < sum)
           low++;
           else
           high--;

          }
       }
    }
       return result;*/
    }
};
/*class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
    sort(nums.begin(), nums.end());
    
    vector<vector<int>>result;
    // b+c = -a  (2sum problem)
    // for 'a' to move
    for(int i=0; i<nums.size()-2; i++)
    {
       if(i==0 || (i>0 && nums[i] != nums[i-1])) 
       { 
       int sum = 0 - nums[i];
       int low = i+1;
       int high = nums.size()-1;

       while(low<high)
         {
           if(nums[low] + nums[high] == sum)
           {
               vector<int>temp;
               temp.push_back(nums[i]);
               temp.push_back(nums[low]);
               temp.push_back(nums[high]);
               result.push_back(temp);

               while(low<high && nums[low] == nums[low+1])
               low++;
                 
               while(low<high && nums[high] == nums[high-1])
               high--;

               low++;
               high--;

           }

           else if(nums[low] + nums[high] < sum)
           low++;
           else
           high--;

          }
       }
    }
       return result;
    }
};*/

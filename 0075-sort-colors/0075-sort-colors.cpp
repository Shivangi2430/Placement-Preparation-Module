class Solution {
public:
    void sortColors(vector<int>& nums) {
/*
TC = O(NlogN)
SC = O(1)
   count all the occurences of 0, 1, & 2 seperatly
    
   int count_0=0, count_1=0, count_2=0;
   for(int i=0;i<nums.size();i++)
   {
       if(nums[i]==0)
       count_0++;
   }
   for(int i=0;i<nums.size();i++)
   {
       if(nums[i]==1)
       count_1++;
   }
   for(int i=0;i<nums.size();i++)
   {
       if(nums[i]==2)
       count_2++;
   }
  
 
    //Replace the places in the original array:
    for (int i = 0; i < count0; i++) nums[i] = 0; // replacing 0's

    for (int i = count0; i < count0 + count1; i++) nums[i] = 1; // replacing 1's

    for (int i = count0 + count1; i < n; i++) nums[i] = 2; // replacing 2's


*/

//TC = O(N)
//SC = O(1)
        int low = 0, mid = 0, high = nums.size() - 1;
    
        while(mid <= high)
        {
            if(nums[mid] == 0)
            {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1)
            {
                mid++;
            }
            else if(nums[mid] == 2)
            {
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
    
    };
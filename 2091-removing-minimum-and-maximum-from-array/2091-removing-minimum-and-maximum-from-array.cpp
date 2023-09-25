/* are 3 possible cases:

Delete both min and max element from left.
Delete both from right
Delete one from left and other from right.
Steps :

We will store index of min and max element in i and j variable (where j always points to the greater index).
For case 1: no of elements to be deleted = j+1
For case 2: no of elements to be deleted = n - i
For case 3: no of elements to be deleted = (i+1) + (n-j)
Return min of above 3 cases

Time Complexity: O(n) , to find index of min and max element
Space Complexity: O(1)

// WE CAN ALSO USE THIS TO FIND THE MIN AND MAX ELMENTS INDEX AND THEN APPLY THE SAME LOGIC OF SWAPPING THEN FINDING MINIMUM
mx = INT_MIN, mn = INT_MAX
for(int i=0;i<n;i++){
            if(mx<nums[i]){
                mx = nums[i];
                h = i;
            }
            if(mn>nums[i]){
                mn = nums[i];
                l = i;
            }
        }

*/

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int j = max_element(nums.begin(), nums.end()) - nums.begin(); //gives the iterator because we are not using * here hence it will give you the index
        int i = min_element(nums.begin(), nums.end()) - nums.begin(); //gives the iterator 
        
        //to make sure j points to greater index
        if(i > j)
           swap(i, j);
            
        return min(j+1 , min(n-i , i+1+n-j));
    }
};

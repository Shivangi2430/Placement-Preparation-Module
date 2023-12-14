class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

    int n = nums.size();
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) 
    {
        // i and j are fixed only k and l will move
        // avoid the duplicates while moving i:
        
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        
        for (int j = i + 1; j < n; j++) 
        {
            // avoid the duplicates while moving j:
            
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            // 2 pointers:
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                
                if (sum < target) 
                    k++;
                
                else if(sum > target) 
                    l--;
                
                else
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++; 
                    l--;

                    //skip the duplicates:
                    while (k < l && nums[k] == nums[k - 1])
                        k++;
                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }  
                
            }
        }
    }

    return ans;

    }
};
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
   
   // TC = O(min(n,m)) + O(nlogn) + O(mlogm) + O(n)

   int left = m-1; //last element of arr1
   int right = 0; //first element of arr2

   while(left >= 0 && right < n)
   {
            if(nums1[left] > nums2[right])
            {
                swap(nums1[left], nums2[right]);
                left--;
                right++;
            }
            else 
                break;
    }
        
    sort(nums1.begin(), nums1.begin()+m); // Sorting till mth index
    sort(nums2.begin(), nums2.end());

    for(int i = m; i < m + n; i++)
    {
            nums1[i] = nums2[i-m];
    }
   
        
       /* 
       TC = O(MlogM) Sorting the array(nums1) costs O(MlogM). Where M is the size of the Array(nums1).

       SC = O(1)

       for(int i=0; i<n;i++)
        {
           nums1[i+m] = nums2[i];
        }
       
       sort(nums1.begin(), nums1.end());
   */    
    }
};
/*

    Time Complexity : O(N^2), where N is the size of the array. As we check for possible pair which can satisfy
    the given condition, and the total number of pairs are : N*(N–1)/2.

    Space complexity : O(1), Constant space.

    Solved Using Array(Two Nested Loop). Brute Force Approach.

    Note : This approach is Giving TLE.

*/


/*                                                               Approach 1 

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        long long reversePairsCount = 0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] > 2*(long long)nums[j]){
                    reversePairsCount++;
                }
            }
        }
        return reversePairsCount;
    }
};

*/

/*

    Time Complexity : O(2NlogN)
    Space Complexity : O(N), Recursion Stack Space O(logN) + Array(temp) space O(N). 

    Solved using Array + Divide and Conquer + Merge Sort. Optimized Approach.




/***************************************** Approach 2 *****************************************/

class Solution {
private: 
   void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
         arr[i] = temp[i - low];
    }
}

int countPairs(vector<int> &arr, int low, int mid, int high) {
    int right = mid + 1;
    int count = 0;
    for (int i = low; i <= mid; i++) {  //from left array to right array and from low to mid in left array
        while (right <= high && arr[i] > (long long)2 * arr[right])  //checks in right array from right to high
        right++;
        count += (right - (mid + 1));
    }
    return count;
}

int mergeSort(vector<int> &arr, int low, int high) {
    int count = 0;
    if (low >= high) return count;
    int mid = (low + high) / 2 ;
    count += mergeSort(arr, low, mid);  // left half
    count += mergeSort(arr, mid + 1, high); // right half
    count += countPairs(arr, low, mid, high); //Modification
    merge(arr, low, mid, high);  // merging sorted halves
    return count;
}

public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
   
    }
};
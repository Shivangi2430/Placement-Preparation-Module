int fn(vector<int>& arr, int pages)
{
    int cntstd = 1;
    long long currpages = 0;
    for(int i=0; i<arr.size(); i++)
    {
        if(currpages + arr[i] <= pages)
        {
            currpages += arr[i];
        }
        else
        {
            cntstd++;
            currpages = arr[i];
        }
    }
    return cntstd;
}

int findPages(vector<int>& arr, int n, int m) {
    if(m > n)
    return -1;
    int low = *max_element(arr.begin(), arr.end());
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += arr[i];
    }
    int high = sum;

    while(low <= high)
    {
        int mid = low + (high - low)/2;
        int cntStud = fn(arr, mid);
        if(cntStud > m)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

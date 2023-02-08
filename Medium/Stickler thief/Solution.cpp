class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int inc = arr[0];
        int exc = 0;
        for(int i=1;i<=n-1;i++){
           int ninc = exc+arr[i];
            int nexc = max(exc,inc);
            inc=ninc;
            exc=nexc;
        }
        int ans = max(inc,exc);
        return ans;
    }
};

// User function Template for C++

class Solution{
public:
    bool solveRec(int index,int nums[],int n,int t){
        // BASE CASE...
        if(index >= n) return 0;
        if(t < 0) return 0;
        if(t == 0) return 1;
        // Take...
        bool incl = solveRec(index+1,nums,n,t-nums[index]);
        // Not take...
        bool excl = solveRec(index+1,nums,n,t);
        return incl or excl;
    }
    bool solveMem(int index,int nums[],int n,int t,vector<vector<int>>& dp){
        // BASE CASE...
        if(index >= n) return 0;
        if(t < 0) return 0;
        if(t == 0) return 1;
        if(dp[index][t] != -1) return dp[index][t];
        // Take...
        bool incl = solveMem(index+1,nums,n,t-nums[index],dp);
        // Not take...
        bool excl = solveMem(index+1,nums,n,t,dp);
        return dp[index][t] = incl or excl;
    }
    int equalPartition(int N, int arr[]){
        // code here
        int sum = accumulate(arr,arr+N,0);
        int target = sum/2;
        if(sum%2!=0) return 0;
        // return solveRec(0,arr,N,target);
        
        vector<vector<int>> dp(N+1, vector<int>(target+1, -1));
        return solveMem(0,arr,N,target,dp);
    }
};

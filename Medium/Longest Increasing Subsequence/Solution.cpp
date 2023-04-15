
class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int solveRec(int n,int nums[],int curr,int prev){
        // BASE CASE...
        if(curr == n) return 0;
        // Include...
        int incl = 0;
        if(prev == -1 || nums[curr]>nums[prev]) incl = 1 + solveRec(n,nums,curr+1,curr);
        // Exclude...
        int excl = 0 + solveRec(n,nums,curr+1,prev);
        return max(incl,excl);
    }
    int solveMem(int n,int nums[],int curr,int prev,vector<vector<int>>& dp){
        // BASE CASE...
        if(curr == n) return 0;
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
        int incl = 0;
        if(prev == -1 || nums[curr]>nums[prev]) incl = 1 + solveMem(n,nums,curr+1,curr,dp);
        int excl = 0 + solveMem(n,nums,curr+1,prev,dp);
        return dp[curr][prev+1] = max(incl,excl);
    }
    int solveTab(int n,int nums[]){
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int curr = n-1;curr>=0;curr--){
            for(int prev = n-1;prev>=-1;prev--){
                int incl = 0;
                if(prev == -1 || nums[curr]>nums[prev]) incl = 1 + dp[curr+1][curr+1];
                int excl = 0 + dp[curr+1][prev+1];
                dp[curr][prev+1] = max(incl,excl);
            }
        }
        return dp[0][0];
    }
    int space_optimization(int n,int nums[]){
        vector<int> currRow(n+1,0);
        vector<int> nextRow(n+1,0);
        for(int curr = n-1;curr>=0;curr--){
            for(int prev = n-1;prev>=-1;prev--){
                int incl = 0;
                if(prev == -1 || nums[curr]>nums[prev]) incl = 1 + nextRow[curr+1];
                int excl = 0 + nextRow[prev+1];
                currRow[prev+1] = max(incl,excl);
            }
            // Shifting Logic...
            nextRow = currRow;
        }
        return currRow[0];
    }
    int longestSubsequence(int n, int a[]){
       // your code here
       
        // return solveRec(n,a,0,-1);

        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solveMem(n,a,0,-1,dp);
        
        // return solveTab(n,a);
        
        return space_optimization(n,a);
    }
};

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solveRec(int W, int wt[], int val[], int index){
        // Base case...
        if(index+1 == 0 || W == 0) return 0;
        if(index == 0 && wt[0] <= W) return val[0];
        int incl = 0;
        if(wt[index] <= W) incl = val[index] + solveRec(W-wt[index], wt, val, index-1);
        int excl = 0 + solveRec(W,wt,val,index-1);
        int ans = max(excl,incl);
        return ans;
    }
    int solveMem(int W, int wt[], int val[], int index, vector<vector<int>>& dp){
        // Base case...
        if(index+1 == 0 || W == 0) return 0;
        if(index == 0 && wt[0] <= W) return val[0];
        if(dp[index][W] != -1) return dp[index][W];
        int incl = 0;
        if(wt[index] <= W) incl = val[index] + solveMem(W-wt[index], wt, val, index-1,dp);
        int excl = 0 + solveMem(W,wt,val,index-1,dp);
        dp[index][W] = max(excl,incl);
        return dp[index][W];
    }
    int solveTab(int W, int wt[], int val[], int n){
        // Creating the dp array (Step 1...)
        vector<vector<int>> dp(n, vector<int>(W+1, 0));
        // Analyzing the base case (Step 2...)
        for(int i=wt[0];i<=W;i++) dp[0][i] = val[0];
        // Handling the remaining recursive calls(Step 3...)
        for(int index=1;index<=n-1;index++){
            for(int weight=0;weight<=W;weight++){
                int incl = 0;
                if(wt[index] <= weight) incl = val[index] + dp[index-1][weight-wt[index]];
                int excl = 0 + dp[index-1][weight];
                dp[index][weight] = max(incl,excl);
            }
        }
        return dp[n-1][W];
    }
    int space_optimization(int W, int wt[], int val[], int n){
        vector<int> prev(W+1,0);
        vector<int> curr(W+1,0);
        for(int i=wt[0];i<=W;i++) prev[i] = val[0];
        for(int index=1;index<=n-1;index++){
            for(int weight=0;weight<=W;weight++){
                int incl = 0;
                if(wt[index] <= weight) incl = val[index] + prev[weight-wt[index]];
                int excl = 0 + prev[weight];
                curr[weight] = max(incl,excl);
            }
            // Shifting logic after filling one row.
            prev = curr;
        }
        return prev[W];
    }
    int knapSack(int W, int wt[], int val[], int n){
        // Your code here
       
        // return solveRec(W,wt,val,n-1);
       
        // vector<vector<int>> dp(n, vector<int>(W+1, -1));
        // return solveMem(W,wt,val,n-1,dp);
    
        // return solveTab(W,wt,val,n);
        
        return space_optimization(W,wt,val,n);
    }
};

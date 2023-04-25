// User function Template for C++

class Solution {
    public:
    int solveRec(int index,int buy,int prices[],int limit,int n){
        // BASE CASE...
        if(index >= n) return 0;
        if(limit <= 0) return 0; // One additional Base case is added to check whether the limit reached out or not.
        int profit = 0;
        if(buy){
            int buyKaro = -prices[index] + solveRec(index+1,0,prices,limit,n);
            int skipKaro = 0 + solveRec(index+1,1,prices,limit,n);
            profit = max(buyKaro,skipKaro);
        }
        else{
            int sellKaro = prices[index] + solveRec(index+1,1,prices,limit-1,n); // Limit is only decreased whenever the stock is sold after bought.
            int ignoreKaro = 0 + solveRec(index+1,0,prices,limit,n);
            profit = max(sellKaro,ignoreKaro);
        }
        return profit;
    }
    int solveMem(int index,int buy,int prices[],int limit,int n,vector<vector<vector<int>>>& dp){
        // BASE CASE...
        if(index >= n) return 0;
        if(limit <= 0) return 0;
        if(dp[index][buy][limit] != -1) return dp[index][buy][limit];
        int profit = 0;
        if(buy){
            int buyKaro = -prices[index] + solveMem(index+1,0,prices,limit,n,dp);
            int skipKaro = 0 + solveMem(index+1,1,prices,limit,n,dp);
            profit = max(buyKaro,skipKaro);
        }
        else{
            int sellKaro = prices[index] + solveMem(index+1,1,prices,limit-1,n,dp);
            int ignoreKaro = 0 + solveMem(index+1,0,prices,limit,n,dp);
            profit = max(sellKaro,ignoreKaro);
        }
        return dp[index][buy][limit] = profit;
    }
    int maxProfit(int K, int N, int A[]){
        // code here
        // return solveRec(0,1,A,K,N);
        
        vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(2,vector<int>(K+1,-1)));
        return solveMem(0,1,A,K,N,dp);
    }
};

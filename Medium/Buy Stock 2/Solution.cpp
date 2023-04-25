class Solution{
    public:
    long long solveRec(int index,int buy,vector<long long>& prices){
        // BASE CASE...
        if(index >= prices.size()) return 0;
        long long profit = 0;
        if(buy){
            int buyKaro = -prices[index] + solveRec(index+1,0,prices);
            int skipKaro = 0 + solveRec(index+1,1,prices);
            profit = max(buyKaro,skipKaro);
        }
        else{
            int sellKaro = prices[index] + solveRec(index+1,1,prices);
            int ignoreKaro = 0 + solveRec(index+1,0,prices);
            profit = max(sellKaro,ignoreKaro);
        }
        return profit;
    }
    long long solveMem(int index,int buy,vector<long long>& prices,vector<vector<long long>>& dp){
        // BASE CASE...
        if(index >= prices.size()) return 0;
        if(dp[index][buy] != -1) return dp[index][buy];
        long long profit = 0;
        if(buy){
            int buyKaro = -prices[index] + solveMem(index+1,0,prices,dp);
            int skipKaro = 0 + solveMem(index+1,1,prices,dp);
            profit = max(buyKaro,skipKaro);
        }
        else{
            int sellKaro = prices[index] + solveMem(index+1,1,prices,dp);
            int ignoreKaro = 0 + solveMem(index+1,0,prices,dp);
            profit = max(sellKaro,ignoreKaro);
        }
        return dp[index][buy] = profit;
    }
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        // return solveRec(0,1,prices);
        
        vector<vector<long long>> dp(n+1,vector<long long>(2,-1));
        return solveMem(0,1,prices,dp);
    }
};

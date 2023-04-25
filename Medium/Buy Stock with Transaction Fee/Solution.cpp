class Solution{
    public:
    long long solveMem(int index,int buy,vector<long long>& prices,int fee,vector<vector<long long>>& dp){
        // BASE CASE...
        if(index >= prices.size()) return 0;
        if(dp[index][buy] != -1) return dp[index][buy];
        long long profit = 0;
        if(buy){
            int buyKaro = -prices[index] + solveMem(index+1,0,prices,fee,dp);
            int skipKaro = 0 + solveMem(index+1,1,prices,fee,dp);
            profit = max(buyKaro,skipKaro);
        }
        else{
            int sellKaro = prices[index] + solveMem(index+1,1,prices,fee,dp)-fee; // This is the only change(to subtract the fee) in this problem.
            int ignoreKaro = 0 + solveMem(index+1,0,prices,fee,dp);
            profit = max(sellKaro,ignoreKaro);
        }
        return dp[index][buy] = profit;
    }
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        // Code here
        vector<vector<long long>> dp(n+1,vector<long long>(2,-1));
        return solveMem(0,1,prices,fee,dp);
    }
};

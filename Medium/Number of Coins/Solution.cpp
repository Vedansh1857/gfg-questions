class Solution{
public:
	int solveTab(int coins[] , int M , int V){
        vector<int> dp(V+1 , INT_MAX);
        dp[0] = 0;
        for(int i=1;i<=V;i++){
            for(int j=0;j<M;j++){
                if(i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX) dp[i] = min(dp[i],1+dp[i-coins[j]]);
            }
        }
        return (dp[V]==INT_MAX) ? -1:dp[V];
    }
	int minCoins(int coins[], int M, int V){ 
	    // Your code goes here
	    return solveTab(coins,M,V);
	}
};

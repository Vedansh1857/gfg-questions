class Solution {
    public:
    long long solveRec(int faces,int dices,int target){
        // BASE CASE...
        if(target<0) return 0;
        if(target == 0 && dices != 0) return 0;
        if(target != 0 && dices == 0) return 0;
        if(target == 0 && dices == 0) return 1;
        long long ans = 0;
        for(int i=1;i<=faces;i++) ans += solveRec(faces,dices-1,target-i);
        return ans;
    }
    long long solveMem(int faces,int dices,int target,vector<vector<long long>>& dp){
        // BASE CASE...
        if(target<0) return 0;
        if(target == 0 && dices != 0) return 0;
        if(target != 0 && dices == 0) return 0;
        if(target == 0 && dices == 0) return 1;
        if(dp[target][dices] != -1) return dp[target][dices];
        long long ans = 0;
        for(int i=1;i<=faces;i++) ans += solveMem(faces,dices-1,target-i,dp);
        return dp[target][dices] = ans;
    }
    long long solveTab(int faces,int dices,int target){
        vector<vector<long long>> dp(target+1,vector<long long>(dices+1,0));
        dp[0][0] = 1;
        for(int i=1;i<=target;i++){
            for(int j=1;j<=dices;j++){
                long long ans = 0;
                for(int k=1;k<=faces;k++){
                    if((i-k) >= 0) ans += dp[i-k][j-1];
                }
                dp[i][j] = ans;
            }
        }
        return dp[target][dices];
    }
    long long space_optimization(int faces,int dices,int target){
        // vector<vector<long long>> dp(target+1,vector<long long>(dices+1,0));
        vector<long long> curr(target+1,0);
        vector<long long> prev(target+1,0);
        prev[0] = 1;
        for(int j=1;j<=dices;j++){
            for(int i=1;i<=target;i++){
                long long ans = 0;
                for(int k=1;k<=faces;k++){
                    if((i-k) >= 0) ans += prev[i-k];
                }
                curr[i] = ans;
            }
            prev = curr;
        }
        return curr[target];
    }
    long long noOfWays(int M , int N , int X){
        // code here
        // return solveRec(M,N,X);
        
        // vector<vector<long long>> dp(X+1,vector<long long>(N+1,-1));
        // return solveMem(M,N,X,dp);
        
        // return solveTab(M,N,X);
        
        return space_optimization(M,N,X);
    }
};

class Solution{
    public:
    #define MOD 1000000007
    int add(int a , int b){
        return ((a%MOD)+(b%MOD)) % MOD;
    }
    int mul(int a , int b){
        return ((a%MOD)* 1LL *(b%MOD)) % MOD;
    }
    int solveRec(int n, int k){
        // Base case...
        if(n==1) return k;
        if(n==2) return add(k,mul(k,(k-1)));
        int ans = add(mul(solveRec(n-1,k),(k-1)) , mul(solveRec(n-2,k),(k-1)));
        return ans;
    }
    long long solveMem(int n, int k , vector<long long>& dp){
        if(n==1) return k;
        if(n==2) return add(k,mul(k,(k-1)));
        if(dp[n] != -1) return dp[n];
        dp[n] = add(mul(solveMem(n-1,k,dp),(k-1)) , mul(solveMem(n-2,k,dp),(k-1)));
        return dp[n];
    }
    long long countWays(int n, int k){
        // code here
        // return solveRec(n,k);
        
        vector<long long> dp(n+1,-1);
        return solveMem(n,k,dp);
    }
};

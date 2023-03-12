// User function Template for C++

class Solution{
public:
    # define MOD 1000000007
    long long int solveMem(int N , vector<long long int>& dp){
        if(N==1) return 0;
        if(N==2) return 1;
        if(dp[N] != -1) return dp[N];
        dp[N] = ((N-1)*(solveMem(N-1,dp) + solveMem(N-2,dp))) % MOD;
        return dp[N];
    }
    long long int solveTab(int N){
        vector<long long int> dp(N+1,0);
        dp[1] = 0; 
        dp[2] = 1;
        for(int i=3;i<=N;i++){
            dp[i] = ((i-1) * (dp[i-1] + dp[i-2])) % MOD;
        }
        return dp[N];
    }
    long long int space_optimization(int N){
        long long int prev1 = 1;
        long long int prev2 = 0;
        for(int i=3;i<=N;i++){
            int ans = ((i-1)*(prev1 + prev2)) % MOD;
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
    long int disarrange(int N){
        // code here
        // vector<long long int> dp(N+1,-1);
        // return solveMem(N,dp);
        
        // return solveTab(N);
        
        return space_optimization(N);
    }
};

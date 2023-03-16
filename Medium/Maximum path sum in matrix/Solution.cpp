// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix){
        // code here
        int col = Matrix[0].size();
        vector<vector<int>> dp(N,vector<int>(col,0));
        for(int m=0;m<col;m++) dp[0][m] = Matrix[0][m];
        for(int i=1;i<N;i++){
            for(int j=0;j<col;j++){
                if(j==0) dp[i][j] = max(dp[i-1][j] , dp[i-1][j+1]) + Matrix[i][j];
                else if(j==col-1) dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + Matrix[i][j];
                else dp[i][j] = max(dp[i-1][j-1],max(dp[i-1][j],dp[i-1][j+1])) + Matrix[i][j];
            }
        }
        int maxi = INT_MIN;
        for(int k=0;k<col;k++){
            maxi = max(maxi,dp[N-1][k]);
        }
        return maxi;
    }
};

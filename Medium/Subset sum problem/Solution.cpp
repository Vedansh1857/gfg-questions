bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        bool dp[n+1][sum+1];
        for(int i=0;i<n+1;i++){
            dp[i][0] = 1;
        }
        for(int j=1;j<=sum;j++){
            dp[0][j] = 0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j]=dp[i-1][j-arr[i-1]] or dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};

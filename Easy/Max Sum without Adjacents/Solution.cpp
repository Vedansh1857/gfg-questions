//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int solveRec(int *arr , int n){
	    if(n<0) return 0;
	    if(n==0) return arr[0];
	    // int ans = max((solve(arr,n-2)+arr[n]) , ((solve(arr,n-1)+0)));
	    int incl = solveRec(arr,n-2)+arr[n];
	    int excl = solveRec(arr,n-1)+0;
	    return max(incl,excl);
	}
	int solveMem(int *arr , int n , vector<int>& dp){
	    if(n<0) return 0;
	    if(n==0) return arr[0];
	    if(dp[n] != -1) return dp[n];
	    int incl = solveMem(arr,n-2,dp)+arr[n];
	    int excl = solveMem(arr,n-1,dp)+0;
	    dp[n] = max(incl,excl);
	    return dp[n];
	}
	int solveTab(int *arr , int n){
	    vector<int> dp(n+1,0);
	    dp[0] = arr[0];
	    for(int i=1;i<n;i++){
	        int incl = dp[i-2] + arr[i];
	        int excl = dp[i-1] + 0;
	        dp[i] = max(incl,excl);
	    }
	    return dp[n-1];
	}
	int space_optimization(int *arr , int n){
	    int prev2 = 0; // For base case (if n<0 then return 0)
	    int prev1 = arr[0]; // For base case (if n=0 then return arr[0])
	    for(int i=1;i<n;i++){
	        int incl = prev2 + arr[i];
	        int excl = prev1 + 0;
	        int ans = max(incl,excl);
	        prev2 = prev1;
	        prev1 = ans;
	    }
	    return prev1;
	}
	int findMaxSum(int *arr, int n) {
	    // // Recursive approach...
	    // int ans = solveRec(arr,n-1);
	    // return ans;
	    
	    // // Recursion + Memoisation...
	    // vector<int> dp(n+1,-1);
	    // int ans = solveMem(arr,n-1,dp);
	    // return ans;
	    
	    // // Tabulation method...
	    // return solveTab(arr,n);
	    
	    // Optimizing space used to O(1)...
	    return space_optimization(arr,n);
	}
};

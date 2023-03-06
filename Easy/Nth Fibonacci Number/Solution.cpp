class Solution {
  public:
    long long int nthFibonacci(long long int n){
        // code here
        long long int prev1 = 1;
        long long int prev2 = 0;
        if(n == 0) return 0;
        for(int i=2;i<=n;i++){
            int curr = (prev1 + prev2) % 1000000007;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

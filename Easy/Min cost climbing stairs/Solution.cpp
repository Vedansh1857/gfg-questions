class Solution {
  public:
  int solve4(vector<int>& cost,int n){

        int prev2 = cost[0];
        int prev1 = cost[1];

        for(int i=2;i<n;i++){
            int curr = cost[i] + min(prev2,prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev2,prev1);
    }
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        //Write your code here
        return solve4(cost,N);
    }
};

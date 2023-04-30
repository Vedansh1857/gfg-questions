class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K){
        // Write Your Code here
        sort(candies,candies+N); // To get the high costs and low costs separated...
        vector<int> ans; // To store the ans...
        // For finding the minimum cost...
        int mini = 0;
        int buyCandy = 0; // For the cost to be minimum the expenditure should be as min as possible.
        int freeCandy = N-1; // For the cost to be minimum the free candies should be of higher costs.
        while(buyCandy <= freeCandy){ // Can be visualized as 2 pointer.
            mini += candies[buyCandy];
            buyCandy++; // Since the candy at a particular index is bought shift the pointer to the next candy.
            freeCandy -= K; // As we can get only K free candies.
        }
        // Similarly for finding the maximum cost the process is reversed...
        int maxi = 0;
        buyCandy = N-1;
        freeCandy = 0;
        while(freeCandy <= buyCandy){
            maxi += candies[buyCandy];
            buyCandy--;
            freeCandy += K;
        }
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
};

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(),a.end());
        int greatest = INT_MAX;
        int i = 0;
        while((i+m) <= n) {
            // int mini = *min_element((a.begin()+i),(a.begin()+(i+m)));
            // int maxi = *max_element((a.begin()+i),(a.begin()+(i+m)));
            // The above logic gives TLE. Only 100 cases are passed thru it.
            int temp = a[i+m-1] - a[i];
            // The above runs perfectly.
            greatest = min(temp,greatest);
            i++;
        }
        return greatest;
    }   
};

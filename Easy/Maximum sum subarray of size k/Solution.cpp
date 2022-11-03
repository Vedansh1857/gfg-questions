public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here
        long curr_sum = 0;
        // curr_sum = accumulate(Arr.begin(),Arr.begin()+K,0);
        for(int i=0;i<K;i++){
            curr_sum += Arr[i];
        }
        long max_sum = curr_sum;
        int i=0;
        int j=K;
        while(j<N){
            curr_sum = curr_sum-Arr[i]+Arr[j];
            i++;
            j++;
            max_sum = max(max_sum,curr_sum);
        }
        return max_sum;
    }

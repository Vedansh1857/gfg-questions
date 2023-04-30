// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        int sundays = S/7; // No. of sundays...
        int openDays = S - sundays; // Since the shop is closed on sundays...
        int totalFood = S*M; // Total amt of food required to be alive for given S days...
        int ans = 0;
        if(totalFood%N == 0) ans = totalFood/N; // For example take S=8,N=16,M=2 ; the if condition will hold true
        else ans = (totalFood/N) + 1; // Now revert back to the given testcase 1 ; In this 1 is added for the remaining 4 days(after living for 16 days)...
        if(ans <= openDays) return ans; // Take example of S=10,N=1,M=1 ; In this she will buy one unit of food for 10 days. But on the 7th day(Sunday) she will die bcz the shop will be closed due to sunday. So, return -1.
        else return -1;
    }
};

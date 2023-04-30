class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool cmp(pair<int,int>a , pair<int,int>b){
        return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n){
        // Your code here
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            auto p = make_pair(start[i],end[i]);
            vec.push_back(p);
        }
        sort(vec.begin(),vec.end(),cmp);
        int count = 1;
        int endTym = vec[0].second;
        for(int i=1;i<n;i++){
            if(vec[i].first > endTym){
                count++;
                endTym = vec[i].second;
            }
        }
        return count;
    }
};

vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        // Code here
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int n=intervals.size();
        int i=0;
        vector<int> temp = intervals[0];
        for(auto it : intervals){
            if(it[0] <= temp[1]) {temp[1]=max(temp[1],it[1]);}
            else{
                ans.push_back(temp);
                temp=it;
            }
        }
        ans.push_back(temp);
        return ans;
    }

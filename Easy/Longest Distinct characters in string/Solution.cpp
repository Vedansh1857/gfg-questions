int longestSubstrDistinctChars (string S){
    // your code here
    int maxi = 0;
    set<char> Set;
    int start = 0;
    int end = 0;
    while(start<S.size()){
        auto it = Set.find(S[start]);
        if(it == Set.end()){
            maxi = max(maxi,start-end+1);
            Set.insert(S[start]);
            start++;
        }
        else{
            Set.erase(S[end]);
            end++;
        }
    }
    return maxi;

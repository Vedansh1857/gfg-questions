public:	
	bool sameFreq(string s)
	{
	    // code here 
	    unordered_map<char, int> m; 
	    //store frequency of character
	    for (int i = 0; i < s.size(); i++){
	        m[s[i]]++;
	    }
	   // Add frequencies to a set
	    set<int> Set;
	    for(auto it=m.begin();it!=m.end();it++){
	        if((it->second) != 0) Set.insert(it->second);
	    }
	    if(Set.size() > 2) return false;
	    else if(Set.size() == 1)return true;
	    else{
	        vector<int> vec;
	        for(auto itt=Set.begin();itt!=Set.end();itt++){
	            vec.push_back(*itt);
	        }
	        if(((vec[0]-vec[1]) == 1) || (vec[1]-vec[0]) == 1) return true;
	        if(vec[0] == 1 || vec[1] == 1) return true;
	    }
	    return false;
	}

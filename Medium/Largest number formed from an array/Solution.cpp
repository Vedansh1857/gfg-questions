static bool cmp(string &a,string &b){
	     if(a+b>b+a) return true;
	     else return false;
	}
	string printLargest(vector<string> &arr) {
	    // code here
	    sort(arr.begin(),arr.end(),cmp);
	    string str = "";
	    for(auto i : arr){
	        str += i;
	    }
	    return str;
	}

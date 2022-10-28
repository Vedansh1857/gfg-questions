int isPalindrome(string S){
	    // Your code goes here
	    string wd = "";
        for(int i=0;i<S.length();i++){
            if(S[i]>='A' && S[i]<='Z'){
                S[i] = tolower(S[i]);
                wd += S[i];
            }
            else if(S[i]>='a' && S[i]<='z'){wd += S[i];}
            else if(S[i]>='0' && S[i]<='9'){wd += S[i];}
            else{continue;}
        }
        string wd2 = wd;
        reverse(wd.begin(),wd.end());
        if(wd == wd2){return true;}
        else{return false;}
	}

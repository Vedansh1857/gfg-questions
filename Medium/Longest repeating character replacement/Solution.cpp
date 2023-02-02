int characterReplacement(string S, int K) {
        // code here
        int i=0, j=0, maxlen=0, maxfreq=0;
        unordered_map<char,int> mp;
        while(j<S.size()){
            mp[S[j]]++; // counts the frequency of each letter.
            maxfreq = max(maxfreq,mp[S[j]]); // Calculating the maximum frequency.
            if((j-i+1)-maxfreq > K){ // If the given no. of operation limit exceeds.
                mp[S[i]]--;//discard the element from the starting(at pointer i) that is reducing the window size.
                i++;// And shrink the string.
            }
            maxlen = max(maxlen,(j-i+1));//If the given no. of operation limit remains increase the window length.
            j++;//Iterate the while loop.
        }
        return maxlen;
    }

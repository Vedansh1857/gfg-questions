string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        if(N==0) return "-1";
        if(N==1) return arr[0];
        string ans = "";
        sort(arr,arr+N);
        string a = arr[0];
        string b = arr[N-1];
        for(int i=0;i<a.length();i++){
            if(a[i]==b[i]) ans += a[i];
            else break;
        }
        if(ans.empty()) return "-1";
        return ans;
    }

int *findTwoElement(int *arr, int n) {
        // code here
        vector<int> temp(n+1,0);
        int *a = new int[2];
        for(int i=0;i<n;i++){
            int d = arr[i];
            temp[d]++;
        }
        for(int i=1;i<=n;i++){
            if(temp[i]>1){
                a[0]=i;
            }
            if(temp[i]==0){
                a[1]=i;
            }
        }
        return a;
    }

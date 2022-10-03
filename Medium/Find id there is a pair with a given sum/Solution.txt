#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,element;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        cin>>element;
        a.push_back(element);
    }
    int k;
    cin>>k;
    int i=0,j=n-1;
    while(i<n && j>=0){
        if((a[i]+a[j]) == k){
            cout<<true<<endl;
            exit(0);
        }
        if(a[i]>a[j]){
            i++;
        }
        else{
            if((a[i]+a[j]) == k){
                cout<<true<<endl;
                j--;
                exit(0);
            }
            else{
                j--;
            }
        }
    }
    cout<<false<<endl;
    return 0;
}

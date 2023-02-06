char* reverse(char *S, int len)
{
    //code here
    stack<char>s;
    for(int i=0;i<len;i++){
        s.push(S[i]);
    }
    int j=0;
    while(!s.empty()){
        S[j]=s.top();
        j++;
        s.pop();
    }
    return S;
}

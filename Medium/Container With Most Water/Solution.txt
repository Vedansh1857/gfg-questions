long long maxArea(long long A[], int len)
{
    // Your code goes here
    int i=0;
    int j=len-1;
    int water=0;
    while(i<j){
        int h = (j-i)*min(A[j],A[i]);
        water = max(water,h);
        if(A[i]<A[j]) i++;
        else j--;
    }
    return water;
}

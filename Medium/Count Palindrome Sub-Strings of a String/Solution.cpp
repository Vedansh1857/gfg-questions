int solveRec(char S[],int i,int j){
    if(i>=j) return 1;
    if(S[i] == S[j]) return solveRec(S,i+1,j-1);
    return 0;
}
int CountPS(char S[], int N){
    //code here
    int count = 0;
        for(int i=0;i<N;i++){
            for(int j=i;j<N;j++){
                count += solveRec(S,i,j);
            }
        }
        return count-N;
    // We did -N bcz it is mentioned that length of palindromic sub strings must be greater than or equal to 2.
    // So, we have to deduct all the single length palindromic sub strings.
}

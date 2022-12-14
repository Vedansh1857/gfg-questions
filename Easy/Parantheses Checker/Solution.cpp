class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s){
        // Your code here
        if(s.length()%2 == 0){
            stack<char> st;
            st.push('#');
            for(auto i : s){
                if((i=='(') || (i=='{') || (i=='[')) st.push(i);
                else{
                    char top = st.top();
                    if(((i==')' && top=='(')) || ((i=='}' && top=='{')) || ((i==']' && top=='['))) st.pop();
                    else return false;
                }
            }
            return(st.top() == '#');
        }
        return false;
    }
};

class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    bool isValid(int i, int j, int n , int m, vector<vector<int>>& grid){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j] == 1){
            return true;
        }
        return false;
    }
    void numIslandsRec(int i, int j, int n , int m, vector<vector<int>>& grid,int & ans){
        grid[i][j] = 0;
        ans++;
        if(isValid(i+1, j, n, m , grid)) numIslandsRec(i+1, j, n, m, grid,ans);
        if(isValid(i-1, j, n, m , grid)) numIslandsRec(i-1, j, n, m, grid,ans);
        if(isValid(i, j+1, n, m , grid)) numIslandsRec(i, j+1, n, m, grid,ans);
        if(isValid(i, j-1, n, m , grid)) numIslandsRec(i, j-1, n, m, grid,ans);
        if(isValid(i+1, j+1, n, m , grid)) numIslandsRec(i+1, j+1, n, m, grid,ans);
        if(isValid(i+1, j-1, n, m , grid)) numIslandsRec(i+1, j-1, n, m, grid,ans);
        if(isValid(i-1, j+1, n, m , grid)) numIslandsRec(i-1, j+1, n, m, grid,ans);
        if(isValid(i-1, j-1, n, m , grid)) numIslandsRec(i-1, j-1, n, m, grid,ans);
    }
    int findMaxArea(vector<vector<int>>& grid){
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int mini = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    int ans = 0;
                    numIslandsRec(i,j,n,m,grid,ans);
                    mini = max(mini,ans);
                }
            }
        }
        return mini;
    }
};

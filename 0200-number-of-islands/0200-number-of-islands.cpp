class Solution {
public:
    void handleIsland(vector<vector<char>>& grid,int x,int y,int r,int c){
        if(x<0 || y<0 || x>=r || y>=c || grid[x][y]!='1') return;
        grid[x][y] = '2';
        handleIsland(grid,x+1,y,r,c);
        handleIsland(grid,x,y+1,r,c);
        handleIsland(grid,x-1,y,r,c);
        handleIsland(grid,x,y-1,r,c); 
    }
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        if(r==0) return 0;
        int island = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                    handleIsland(grid,i,j,r,c);
                    island++;
                }
            }
        }
        return island;
    }
};
class Solution {
public:
    bool handleAll(vector<vector<char>>& board, string word,int x,int y,int r,int c,int index){
        if(index == word.size()){
            return true;
        }
        if(x>=r || y>=c || x<0 || y<0 || board[x][y] != word[index]){
            return false;
        }

        char temp = board[x][y];
        board[x][y] = '*';
        
        bool found = handleAll(board, word, x + 1, y, r, c, index + 1) ||
                 handleAll(board, word, x, y + 1, r, c, index + 1) ||
                 handleAll(board, word, x - 1, y, r, c, index + 1) ||
                 handleAll(board, word, x, y - 1, r, c, index + 1);

        board[x][y] = temp;

        return found;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        if(r==0){
            return false;
        }
        int c = board[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]==word[0] &&  handleAll(board,word,i,j,r,c,0) ){
                   return true;
                }
            }
        }
        return false;
    }
};
//https://leetcode.com/explore/featured/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3363/
/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/

class Solution {
private :
    void dfs(vector<vector<char>>&board,int x,int y)
{
    if(x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] == 'O')
    {
        board[x][y]='P';
        dfs(board,x,y+1);
        dfs(board,x+1,y);
        dfs(board,x-1,y);
        dfs(board,x,y-1);
    }
    else return;
}
    
public:
    void solve(vector<vector<char>>& board) {
        int m  = board.size();
        if(m==0)
            return;
        int n = board[0].size();
        for(int i =0;i<m;i++) //Rows
        {
            if(board[i][0]=='O')
                dfs(board,i,0);
            if(board[i][n-1]=='O')
                dfs(board,i,n-1);
        }
        for(int j =0;j<n;j++) //Columns
        {
            if(board[0][j]=='O')
                dfs(board,0,j);
            if(board[m-1][j]=='O')
                dfs(board,m-1,j);
        }
        
        for(int i = 0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='P')
                    board[i][j]='O';
            }
            
        }
    }
};

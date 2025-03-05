#include<iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>>&board,int n){
    int x=row;
    int y=col;

    //check in same row- left.;
    while(y>=0){
        if(board[x][y]==1){
            return false;
        }
        y--;
    }

    //check for diagonal- upperleft.
    x=row;
    y=col;
    while(x>=0&&y>=0){
        if(board[x-1][y-1]==1){
            return false;
        }
        x--;
        y--;
    }

    //check for diagonal- lowerleft.
    x=row;
    y=col;
    while(x<n&&y>=0){
        if(board[x+1][y+1]==1){
            return false;
        }
        x++;
        y--;
    }
    return true;
}

// This function adds the current board configuration to the list of solutions
void addSolution(vector<vector<int>>&board, vector<vector<int>>&ans){
    vector<int>temp;
    int n=board.size();
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);//will store whole board conifg in one line- 1D.
            //board[i][j], i.e temp, contains the 1-config of solution, out of other possible ones.
        }
    }
    ans.push_back(temp);//each config of board will be pushed in a single row in ans. 
}
void solve(int col, vector<vector<int>>&board, vector<vector<int>>&ans, int n){
    cout << "Solving for col: " << col << endl;
    if(col==n){
        addSolution(board,ans);
        cout << "Solution found!" << endl;
        return;
    }

    //solve 1case and rest recurison will take care.
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            cout << "Placing Queen at: (" << row << ", " << col << ")" << endl;
            board[row][col]=1;
            solve(col+1,board,ans,n);
            cout << "Backtracking from: (" << row << ", " << col << ")" << endl;
            //backtrack and remove the queen;
            board[row][col]=0;
        }
    }

}
vector<vector<int>> nQueens(int n){
    vector<vector<int>>board(n,vector<int>(n,0));
    vector<vector<int>>ans;
    solve(0,board,ans,n);
    return ans;
}
int main(){
    int n;
    cout<<"enter the dimensions of chess board: ";
    cin>>n;
    vector<vector<int>>ans = nQueens(n);
    if (ans.empty()) {
        cout << "DEBUG: No solutions generated!" << endl;
    }
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
            if ((j + 1) % n == 0) cout << endl;
        }
        cout << endl;
    }
    return 0;
}
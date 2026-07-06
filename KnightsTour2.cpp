#include <iostream>
#include <vector>
using namespace std;

// Knight ke 8 possible moves
int dx[8] = {2,1,-1,-2,-2,-1,1,2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};

// Check karo move valid hai ya nahi
bool isSafe(int x, int y, int n, vector<vector<int>>&board){
    return (x>=0 && y>=0 && x<n && y<n && board[x][y] == -1);
}

// Backtracking function
bool solve(int x, int y, int move, int n, vector<vector<int>>&board){
    
    // Base case: agar saare cells fill ho gaye
    if(move == n*n){
        return true;
    }

    // Har move try karo
    for(int k=0; k<8; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];

        if(isSafe(nx, ny, n, board)){
            board[nx][ny] = move; // move place karo

            // Aage solve karo
            if(solve(nx, ny, move+1, n, board))
                return true;

            // Backtrack karo
            board[nx][ny] = -1;
        }
    }
    return false;
}

int main(){
    int n;
    cout << "Enter board size: ";
    cin >> n;

    // Board initialize -1 se
    vector<vector<int>> board(n, vector<int>(n, -1));

    board[0][0] = 0; // Knight starting block

    // Agar solution mil gaya
    if(solve(0, 0, 1, n, board)){
        cout << "Knight's Tour Solution:\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "No solution exists for this board size\n";
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>>& board, int row, int col, pair<int, int> parent) {
    bool toBeConverted = true;

    // Base condition
    if (row <= 0 or row >= board.size()-1 or col <= 0 or col >= board[0].size()-1) return;

    // Check if 'O' or 'X'
    if (board[row][col] == 'X') return;

    // Magical condition
    // UP
    if (make_pair(row-1, col) != parent) {
        dfs(board, row-1, col, {row, col});
        if (board[row-1][col] == 'O') toBeConverted = false;
    }

    // DOWN
    if (make_pair(row+1, col) != parent) {
        dfs(board, row+1, col, {row, col});
        if (board[row+1][col] == 'O') toBeConverted = false;
    }

    // LEFT
    if (make_pair(row, col-1) != parent) {
        dfs(board, row, col-1, {row, col});
        if (board[row][col-1] == 'O') toBeConverted = false;
    }

    // RIGHT
    if (make_pair(row, col+1) != parent) {
        dfs(board, row, col+1, {row, col});
        if (board[row][col+1] == 'O') toBeConverted = false;
    }

    // Backtrack
    if (board[row][col] == 'O' and toBeConverted) board[row][col] = 'X';
    return;
}

void solve(vector<vector<char>>& board) {
    for (int row=0; row<board.size(); row++) {
        for (int col=0; col<board[row].size(); col++) {
            char val = board[row][col];

            if (val == 'O') {
                dfs(board, row, col, {row, col});
            }
        }
    }
}

int main()
{
    // code here
    vector<vector<char>> board;
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        board.push_back({});
        for (int j=0; j<n; j++) {
            char c;
            cin >> c;
            board[i].push_back(c);
        }
    }

    solve(board);

    cout << "\n\nAfter Solving : " << endl;
    for (auto row : board) {
        for (char val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
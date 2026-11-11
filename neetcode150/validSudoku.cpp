#include<iostream>
#include<vector>
using namespace std;

bool validSudoku(vector<vector<char>>board){
    //here the double array represents [row/column/box number][exact digit filled -1] = seen/not seen
    // row[r][d] = whether digit d+1 has appeared in row r
// col[c][d] = whether digit d+1 has appeared in column c
// box[b][d] = whether digit d+1 has appeared in box b
    bool row[9][9] = {false};
    bool col[9][9] = {false};
    bool box[9][9] = {false};

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(board[i][j]=='.') continue;
            int num = board[i][j] - '1'; //this is just an intellignet conversion of numbers 1-9 to 0-8 so that they satisify the use of the boolean double arrays
            int b = (i/3)*3 + (j/3);
// if this digit has already appeared in its row,
// column, or 3x3 box, the Sudoku is invalid       

            if(row[i][num]|| col[j][num] || box[b][num]){
                return false;
            }

            row[i][num] = col[j][num] = box[b][num] = true;
        }
    }
    return true;
}

int main(){

    vector<vector<char>> board = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},

    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},

    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
}; //expected true
    bool answer = validSudoku(board);
    answer?cout<<"True":cout<<"False";
    return 0;
}
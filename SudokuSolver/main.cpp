#include <bits/stdc++.h>
using namespace std;

void printSudoku(vector<vector<int>> sudokuarray)
{
    cout<<"\t\t\t\t|↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔|\n";
		for(int it=0 ; it < 9 ; it++){
			cout<<"\t\t\t\t|";
			for(int it2 = 0 ; it2 < 9; it2++){
				if((it2+1) % 3 == 0 && it2!=8){
					cout<<" "<<sudokuarray[it][it2]<<" ∥";
				}
				else{
					cout<<" "<<sudokuarray[it][it2]<<" |";
				}
			}
			if((it+1) % 3 == 0){
				cout<<endl<<"\t\t\t\t|↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔↔|"<<endl;
			}
			else{
				cout<<endl<<"\t\t\t\t|-----------------------------------|"<<endl;
			}
		}
		cout<<endl<<endl;
}
bool isSafe(vector<vector<int>> grid, int row,
                       int col, int num)
{
    for (int x = 0; x <= 8; x++)
        if (grid[row][x] == num)
            return false;
    for (int x = 0; x <= 8; x++)
        if (grid[x][col] == num)
            return false;
    int startRow = row - row % 3,
            startCol = col - col % 3;
   
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j +
                            startCol] == num)
                return false;
 
    return true;
}
bool solveSudoku(vector<vector<int> >& grid, int row, int col)
{
    if (row == 9 - 1 && col == 9)
        return true;
    if (col == 9) {
        row++;
        col = 0;
    }
    if (grid[row][col] > 0)
        return solveSudoku(grid, row, col + 1);
 
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
           
            if (solveSudoku(grid, row, col + 1))
                return true;
        }
        grid[row][col] = 0;
    }
    return false;
}

int main(){
	// cout<<"\t\t\t--------------------Welcome to Sudoku Solver--------------------\t\n\n\n";
	vector<vector<int>> sudokuarray ( 9 , vector<int> (9 , 0));
	for(int i = 0 ; i<9 ; i++){
		for(int j= 0 ; j < 9 ; j++){
				cin>>sudokuarray[i][j];
		}
	}
	if(solveSudoku(sudokuarray , 0 ,0)){
		printSudoku(sudokuarray);
	}else{
		cout<<"No solution exists!";
	}
	return 0;
}
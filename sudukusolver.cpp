bool findEmptyPlace(int &row, int &col)
{ 
  //get empty location and update row and column
   for (row = 0; row < 9; row++)
      for (col = 0; col < 9; col++)
         if (grid[row][col] == -1) //marked with 0 is empty
            return true;
   return false;
}

bool solveSudoku()
{
   int row, col;
   if (!findEmptyPlace(row, col))
      return true; //when all places are filled
   for (int num = 1; num <= 9; num++)
   { //valid numbers are 1 - 9
      if (isValidPlace(row, col, num))
      { //check validation, if yes, put the number in the grid
         board[row][col] = num;
         if (solveSudoku()) //recursively go for other rooms in the grid
            return true;
         board[row][col] = 0; //turn to unassigned space when conditions are not satisfied
      }
   }
   return false;
}
int main()
{
   if (solveSudoku() == true)
      sudokuGrid();
   else
      cout << "No solution exists";
}

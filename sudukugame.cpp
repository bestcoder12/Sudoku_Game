#include <iostream>
#include <string>

using namespace std;

/*
 * Class sudoku creates a sudoku board with 9 cells in a row and 9 rows 
 * that is it has 81 cells in the whole board.
 */

class Sudoku
{
	public:
		int board[9][9];
		int filled;
		int unfilled;
		
		Sudoku()
		{
			// Taking a string input for difficulty of the board so as
			// to enhance the readablity of the code and not remember
			// what value corresponds to which difficulty

			string Difficulty;
			cout << "Enter the level of difficulty: "<<endl;
			cout << "\t1. Easy" <<endl;
			cout << "\t2. Medium" <<endl;
			cout << "\t3. Hard" <<endl;
			
			getline(cin,Difficulty);
			
			if(Difficulty.compare("Easy") == 0)
			{			
				filled = 60;
			}
			else if(Difficulty.compare("Medium") == 0)
			{
				filled = 50;
			}
			else if(Difficulty.compare("Hard") == 0)
			{
				filled = 40;
			}
			else
			{
				filled = 60;
			}
			unfilled=81-filled;

			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					board[i][j] = -1;
				}
			}
		}
		
		void input()
		{
			for(i=0;i<10;i++)
			{
				for(j=0;j<10;j++)
				{
					cout<<"Enter the location where you want to insert the element"<<endl;
					cout<<"Enter row  ";
					cin>>row;
					
					cout<<"Enter column ";
					cin>>col;
					
					
					if(row==i && col==j)
					{
						
						cout<<"Enter your Element"<<endl;
						cin>>a[i][j];
						
					}
					else
					cout<<"	Wrong Position"<<endl;
					break();
					
				}
			}
		}
}


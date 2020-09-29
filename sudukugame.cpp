#include<iostream>

using namespace std;

class Suduku
{
	public:
		int grid[9][9],i,j,row,col;
		int a[9][9];
		int filled;
		int unfilled;
		int Difficulty;
		
		cout<<"Enter the level of Difficulty "<<endl;
		cout<<"1 For Easy"<<endl;
		cout<<"2 for Medium"<<endl;
		cout<<"3 for Difficult"<<endl
		
		cin>>Difficulty;
		
		if(Difficulty==1)
		
			filled=60;
			unfilled=81-filled;
		
		else if(Difficulty==2)
		
			filled=50;
			unfilled=81-filled;
		
		else if(Difficulty==3)
		
			filled=40;
			unfilled=81-filled;
		
		
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

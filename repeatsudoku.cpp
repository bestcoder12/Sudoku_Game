void sudoku:: repeat()
{
	int l,k,s;
	
	int count=0;
	
	for(l=0;l<9;l++)
	{
		for(k=0;k<9;k++)
		{
			for(s=0;s<9;s++)
			{
			   if(board[l][k]== board[l+s][k] || board[l][k]== board[l][k+s])
			   count++;
			   
			   if(count>1)
			   cout<<"Number is Repeating"<endl;
			   break;
			   
			   else if(cout==1)
			   continue;
			
		}
	}
	
	 
}

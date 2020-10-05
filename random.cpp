int random()
  
{
  srand((unsigned)time(0));
  int random_no;
  int filled[9][9];
  for(h=0;h<9;h++)
  {
    random_no=(rand()%9)+1;
    
    for(i=0;i<9;i++)
    {
      for(j=0;j<9;j++)
      {
        
        filled[i][j]=random_no;
        
      } 
      
    }
  }
    
    

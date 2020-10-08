int random()
  
{
  srand((unsigned)time(0));
  
  int random_no;
 
  for(s=0;s<filled;s++)
  {
    for(p=0;p<row_lim;p++)
    {
      for(u=0;u<col_lim;u++)
      {
        random_no=(rand()%9)+1;
        f=rand()%9;
        z=rand()%9;
           
        board[f][z]=random_no;
         }
      }
    }
  }

        
        
           
           
           
           
 
    
    

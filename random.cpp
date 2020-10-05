/* function to enter random values at random locations in sudoku*/

int random()
  
{
  srand((unsigned)time(0));
  
  int random_no1;
  int f,z;
  int filled_no[9][9];
 
  for(s=0;s<filled;s++)
  {
    for(p=0;p<row_lim;p++)
    {
      for(u=0;u<col_lim;u++)
      {
         for(h=0;h<9;h++)
         {
           
           random_no1=(rand()%9)+1;
           
           /* f and z gets the random values from 0 to 9  
           for getting random positions so that a random number gets placed at random location */
           
           f=rand()%9;
           z=rand()%9;
           
           
           filled_no[f][z]=random_no;
         }
      }
    }
  }
}
        
        
           
           
           
           
 
    
    

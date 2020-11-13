void cell_remover()
{
  default_random_engine defEngine(time(0));
  uniform_int_distribution<int> intDistro(0,8);
  
 
      int c,r;

for(int i=0;i<81-filled;i++)
{
  c= intDistro(defEngine);
  r= intDistro(defEngine);
  
  board[c][r]=-1;
}
  
  
}

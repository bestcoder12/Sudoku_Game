void cell_remover()
{
  default_random_engine defEngine(time(0));
  uniform_int_distribution<int> intDistro(1,9);
  
  int numbers;
   
    int c,r;

for(int i=0;i<81-filled;i++)
{
  c= numbers.push_back(intDistro(defEngine));
  r= numbers.push_back(intDistro(defEngine));
  
  board[c][r]=-1;
}
  
  
}

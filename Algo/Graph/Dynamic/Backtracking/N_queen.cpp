// N queen problem solve by backtracking
#include<bits/stdc++.h>

 int board[20],count=0;
void print_board(int n)
{
	std::cout<<"Solution "<<++count<<"\n";
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(board[i]==j)
			 std::cout<<"\tQ";
		    else
			 std::cout<<"\t-";				  
		}
		std::cout<<"\n";
	}
	
}
bool place(int row,int col)
{
	// check  column and diagonal conflicts
	for(int i=0;i<row;i++)
	{
       if(board[i]==col)// col conflicts
	    return false;
	  else if(abs(board[i]-col)==abs(i-row))
	    return false;
	}
	return true;
} 
void queen(int row,int n)
{
	for(int col=0;col<n;col++)
	{
		if(place(row,col)){
		  board[row]=col;
		   if(row==n-1)
		     print_board(n);
		   else
		     queen(row+1,n);}
	}
}
int main()
{
  int n=4;
  queen(0,n);
  return 0;
}
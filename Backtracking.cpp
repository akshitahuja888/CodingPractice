//Backtracking

//peeche vapis jakar apni galti sudharna

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>
#include <map>

using namespace std;
bool isSafe(int board[4][4],int row,int col,int n)
{
	//for straight paths
	for(int i=0;i<row;i++)
	{
		if(board[i][col]==1)
		{
			return false;
		}
	}

	int x=row;
	int y=col;

	//for right diagonal
	while(x>=0 and y<n)
	{
		if(board[x][y]==1)
		{
			return false;
		}
		x--;
		y++;
	}

	x=row;
	y=col;

	//for left diagonal
	while(x>=0 and y>=0)
	{
		if(board[x][y]==1)
		{
			return false;
		}
		x--;
		y--;
	}

	return true;

}
bool Nqueens(int board[4][4],int n,int row)
{	

	if(row==n)
	{
		//printing 
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(board[i][j]==1)
				{
					cout<<"Q";
				}else{
					cout<<"_";
				}
			}
			cout<<endl;
		}
		return true;
	}

	for(int col=0;col<n;col++)
	{
		if(isSafe(board,row,col,n))
		{
			board[row][col]=1;

			bool baakiKiQueens=Nqueens(board,n,row+1);

			if(baakiKiQueens)
			{
				return true;
			}

			board[row][col]=0;//make my location 0 bcoz any other path may be valid
		}
	}
	return false;
}
int countNqueens(int board[4][4],int n,int row)
{
	if(row==n)
	{
		return 1;
	}
	int count=0;

	for(int col=0;col<n;col++)
	{
		if(isSafe(board,row,col,n))
		{
			board[row][col]=1;

			count+=countNqueens(board,n,row+1);

			board[row][col]=0;
		}
	}
	return count;
}
void printNquens(int board[4][4],int n,int row)
{
	if(row==n)
	{
		cout<<"******************"<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(board[i][j]==1)
				{
					cout<<"Q";
				}else{
					cout<<"_";
				}
			}
			cout<<endl;
		}
		return;
	}

	for(int col=0;col<n;col++)
	{
		if(isSafe(board,row,col,n))
		{
			board[row][col]=1;

			printNquens(board,n,row+1);

			board[row][col]=0;
		}
	}
}

bool ratInAMaze(char maze[4][4],int sr,int sc,int er,int ec)
{
	if(sr==er and sc==ec)
	{
		return true;
	}

	if(sr>er or sc>ec)
	{
		return false;
	}

	if(maze[sr][sc]=='X')
	{
		return false;
	}

	bool horizontalPath = ratInAMaze(maze,sr,sc+1,er,ec);
	bool verticalPath = ratInAMaze(maze,sr+1,sc,er,ec);

	return horizontalPath or verticalPath;
}

void printRatInAMaze(char maze[4][4],int sol[4][4],int sr,int sc,int er,int ec)
{
	if(sr==er and sc==ec)
	{
		cout<<"*****************"<<endl;
		sol[er][ec]=1;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
		return;
	}

	if(sr>er or sc>ec)
	{
		return;
	}

	if(maze[sr][sc]=='X')
	{
		return;
	}

	sol[sr][sc]=1;

	printRatInAMaze(maze,sol,sr,sc+1,er,ec);
	printRatInAMaze(maze,sol,sr+1,sc,er,ec);

	sol[sr][sc]=0;

}
int main() {

	// int board[4][4] = {0};
	// int n =4;

	// cout<<Nqueens(board,n,0)<<endl;
	// cout<<countNqueens(board,n,0)<<endl;
	// printNquens(board,n,0);

	char maze[][4] = {
		{'0','0','0','0'},
		{'0','0','0','X'},
		{'0','0','0','0'},
		{'0','X','0','0'},
	};

	int n=3;

	int sol[4][4] = {0};

	cout<<ratInAMaze(maze,0,0,n,n)<<endl;
	printRatInAMaze(maze,sol,0,0,n,n);
	return 0;
}
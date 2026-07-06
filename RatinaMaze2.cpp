#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isSafe(int maze[4][4],int n,int x,int y){
return (x>=0 && y>=0 && x<n && y<n && maze[x][y]==1);

}

void solveMaze(int maze[4][4],int n, int x,int y,string path){
if(x==n-1 && y==n-1){
    cout<<path<<endl;
    return ;
}
if(isSafe(maze,n,x,y)){
maze[x][y]=0;

//right move
solveMaze(maze,n,x,y+1,path+"R");
//down move
solveMaze(maze,n,x+1,y,path+"D");
//left move
solveMaze(maze,n,x,y-1,path+"L");
//up
solveMaze(maze,n,x-1,y,path+"U");
maze[x][y]=1;

}
}
int main(){
int n=4;
vector<vector<int>>path;
int maze[4][4]={
{1,0,0,0},
{1,1,1,1},
{0,1,0,1},
{0,1,1,1}};
solveMaze(maze,n,0,0,"");

return 0;    
}
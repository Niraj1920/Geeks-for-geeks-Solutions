/*
Given a boolean 2D matrix (0-based index), find whether there is path from (0,0) to (x,y) and if there is one path, print the minimum no of steps needed to reach it, else print -1 if the destination is not reachable. You may move in only four direction ie up, down, left and right. The path can only be created out of a cell if its value is 1.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines . The first line of each test case contains two integers n and m denoting the size of the matrix. Then in the next line are n*m space separated values of the matrix. The following line after it contains two integers x and y denoting the index of the destination.

Output:
For each test case print in a new line the min no of steps needed to reach the destination.

Constraints:
1<=T<=100
1<=n,m<=20

Example:
Input:
2
3 4
1 0 0 0 1 1 0 1 0 1 1 1
2 3
3 4
1 1 1 1 0 0 0 1 0 0 0 1
0 3
Output:
5
3
*/

//try to do using bfs.. 
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
bool isValidMove(int u, int v, int n, int m, vector<vector<int>> mat, vector<vector<bool>> &vis){
    if(u >= 0 && u < n && v >= 0 && v < m && mat[u][v] && !vis[u][v])  return true;
    return false;
}
int shortestPath(vector<vector<int>> mat, vector<vector<bool>> &vis, int u, int v, int x, int y, int steps, int &min_steps){
    if(u == x && v == y){ min_steps = min(min_steps,steps); return 0;}
    vis[u][v] = true;
    int n = mat.size();
    int m = mat[0].size();
    //cout<<u<<" "<<v<<" "<<n<<" "<<m<<" "<<x<<" "<<y<<" "<<mat[u][v]<<" "<<steps<<endl;
    if(isValidMove(u+1, v, n, m, mat, vis))
        shortestPath(mat, vis, u+1, v, x, y, steps+1,min_steps);
    if(isValidMove(u-1, v, n, m, mat, vis))
        shortestPath(mat, vis, u-1, v, x, y, steps+1,min_steps);
    if(isValidMove(u, v+1, n, m, mat, vis))
        shortestPath(mat, vis, u, v+1, x, y, steps+1,min_steps);
    if(isValidMove(u, v-1, n, m, mat, vis))
        shortestPath(mat, vis, u, v-1, x, y, steps+1,min_steps);
    //return -1;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n, m;
	    cin>>n>>m;
	    vector<vector<int>> mat(n, vector<int>(m, 0));
	    vector<vector<bool>> vis(n, vector<bool>(m, false));
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            cin>>mat[i][j];
	        }
	    }
	    int x, y;
	    cin>>x>>y;
	    if(mat[0][0] != 1){
	        cout<<-1<<endl;
	        continue;
	    }  
	    int min_steps = INT_MAX;
	    int res = shortestPath(mat, vis, 0, 0, x, y,0, min_steps);
	    min_steps == INT_MAX?cout<<"-1":cout<<min_steps;
	    cout<<endl;
	}
	return 0;
}

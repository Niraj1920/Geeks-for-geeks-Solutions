/*
Given a N X N matrix (M) filled with 1, 0, 2, 3. The task is to find whether there is a path possible from source to destination, while traversing through blank cells only. You can traverse up, down, right and left.

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.
Note: there is only single source and single destination.

 

Input:
The first line of input is an integer T denoting the no of testcases. Then T test cases follow. Each test case consists of 2 lines. The first line of each test case contains an integer N denoting the size of the square matrix. Then in the next line are N*N space separated values of the matrix (M).

Output:
For each test case in a new line print 1 if the path exist from source to destination else print 0.

Constraints:
1 <= T <= 20
1 <= N <= 20

Example:
Input:
2
4
3 0 0 0 0 3 3 0 0 1 0 3 0 2 3 3 
3
0 3 2 3 0 0 1 0 0

Output:
1
0
*/
#include <iostream>
#include <vector>
using namespace std;
bool isValidMove(vector<vector<int>> &M, vector<vector<bool>> &vis, int u, int v){
    int n = M.size();
    if(u>=0 && u<n && v>=0 && v<n && M[u][v] != 0 && !vis[u][v])    return true;
    return false;
}
void bfs(vector<vector<int>> &M, vector<vector<bool>> &vis, int u, int v, int x, int y, int &res){
    if(u == x && v == y)    res = 1;
    vis[u][v] = true;
    
    if(isValidMove(M, vis, u+1, v))
        bfs(M, vis, u+1, v, x, y, res);
    if(isValidMove(M, vis, u-1, v))
        bfs(M, vis, u-1, v, x, y, res);
    if(isValidMove(M, vis, u, v+1))
        bfs(M, vis, u, v+1, x, y, res);
    if(isValidMove(M, vis, u, v-1))
        bfs(M, vis, u, v-1, x, y, res);
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int srci = -1, srcj = -1, desi = -1, desj = -1;
	    vector<vector<int>> M(n, vector<int>(n, 0));
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            cin>>M[i][j];
	            if(M[i][j] == 1){
	                srci = i;
	                srcj = j;
	            }
	            else if(M[i][j] == 2){
	                desi = i;
	                desj = j;
	            }
	        }
	    }
	    vector<vector<bool>> vis(n, vector<bool>(n, false));
	    int res = 0;
	    bfs(M, vis, srci, srcj, desi, desj, res);
	    cout<<res<<endl;
	}
	return 0;
}

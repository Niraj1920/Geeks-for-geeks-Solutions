/*
A group of connected 1's forms an island. The task is to complete the method findIslands() which returns the number of islands present. The function takes three arguments the first is the boolean matrix A and then the next two arguments are N and M denoting the size(N*M) of the matrix A .

Input:
The first line of input will be the number of testcases T, then T test cases follow. The first line of each testcase contains two space separated integers N and M. Then in the next line are the NxM inputs of the matrix A separated by space .

Output:
For each testcase in a new line, print the number of islands present.

User Task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function findIslands().

Constraints:
1 <= T <= 100
1 <= N, M <= 50
0 <= A[i][j] <= 1

Example(To be used only for expected output) :
Input
2
3 3
1 1 0 0 0 1 1 0 1
4 4
1 1 0 0 0 0 1 0 0 0 0 1 0 1 0 0

Output
2
2
*/
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main() {
    
	int T;
	cin>>T;
	while(T--)
	{
		int N,M;
		cin>>N>>M;
		vector<int> A[N];
		for(int i=0;i<N;i++){
		    vector<int> temp(M);
		    A[i] = temp;
		    for(int j=0;j<M;j++){
		        cin>>A[i][j];
		    }
		}
		cout<<findIslands(A,N,M)<<endl;
	}
	return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
/*you are required to complete this method*/
/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/
bool isnodeExist(int i, int j, int N, int M, vector<int> A[],  vector<vector<bool>> visited){
    if(i>=0 && i<N && j>=0 && j<M && A[i][j] && !visited[i][j])  return true;
    return false;
}
void dfs(vector<int> A[], int i, int j, int N, int M, vector<vector<bool>> &visited){
    visited[i][j] = true;
    if(isnodeExist(i, j+1, N, M, A, visited))
        dfs(A, i, j+1, N, M, visited);
    if(isnodeExist(i, j-1, N, M, A, visited))
        dfs(A, i, j-1, N, M, visited);
    if(isnodeExist(i+1, j, N, M, A, visited))
        dfs(A, i+1, j, N, M, visited);
    if(isnodeExist(i-1, j, N, M, A, visited))
        dfs(A, i-1, j, N, M, visited);
    if(isnodeExist(i+1, j+1, N, M, A, visited))
        dfs(A, i+1, j+1, N, M, visited);
    if(isnodeExist(i+1, j-1, N, M, A, visited))
        dfs(A, i+1, j-1, N, M, visited);
    if(isnodeExist(i-1, j+1, N, M, A, visited))
        dfs(A, i-1, j+1, N, M, visited);
    if(isnodeExist(i-1, j-1, N, M, A, visited))
        dfs(A, i-1, j-1, N, M, visited);
}
int findIslands(vector<int> A[], int N, int M)
{
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    int count = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(A[i][j] && visited[i][j] == false){
                count++;
                dfs(A, i, j, N, M, visited);
            }
        }
    }
    return count;
}

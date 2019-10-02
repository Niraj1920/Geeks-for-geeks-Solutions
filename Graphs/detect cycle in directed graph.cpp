/*
Given a directed graph, the task is to complete the method isCyclic() to detect if there is a cycle in the graph or not. You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.

Input: The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of two lines. Description of testcases is as follows: The First line of each test case contains two integers 'N' and 'M'  which denotes the no of vertices and no of edges respectively. The Second line of each test case contains 'M'  space separated pairs u and v denoting that there is an uni-directed  edge from u to v .

Output:
The method should return 1 if there is a cycle else it should return 0.

User task:
Since this is a functional program you don't have to worry about input, you just have to complete the function

Constraints:
1 <= T <= 100
1<= N,M <= 100
0 <= u,v <= N-1

Example:
Input:
3
2 2
0 1 0 0
4 3
0 1 1 2 2 3
4 3
0 1 2 3 3 2
Output:
1
0
1
*/
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool checkCycle(vector<int> adj[], int v, bool *visited, bool *recstack){
    if(visited[v] == false){
        visited[v] = true;
        recstack[v] = true;
        vector<int>::iterator it;
        for(it=adj[v].begin(); it!=adj[v].end(); it++){
            if(visited[*it] == false && 
                checkCycle(adj, *it, visited, recstack)){
                    return true;
            }
            else if(recstack[*it])  return true;    
        }
    }
    recstack[v] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    bool visited[V], recstack[V];
    for(int i=0; i<V; i++){
        visited[i] = false;
        recstack[i] = false;
    }
    
    for(int u=0; u<V; u++){
        if(checkCycle(adj, u, visited, recstack)){
            return 1;
        }
    }
    return 0;
}

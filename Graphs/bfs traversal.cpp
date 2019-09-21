/*
Given N and E, the number of nodes and edges in a directed graph. The task is to do Breadth First Search of this graph.

Input:
The first line of input contains the number of test cases T. For each test case, the first line of input contains N and E separated by space, and next line contains 2*E numbers (E pairs as X Y) are given in the next line which represents an edge from X to Y.

Output:
For each testcase, print the BFS of the graph starting from 0.

Note: The expected output button always produces BFS starting from node 0.

User Task:
Since, this is a functional problem, your task is to complete the function bfs() which do BFS of the given graph starting from node 0 and prints the nodes in BFS order.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
5 4
0 1 0 2 0 3 2 4
3 2
0 1 0 2

Output:
0 1 2 3 4    // BFS from node 0
0 1 2
*/

#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        
        int N, E;
        cin>>N>>E;
        vector<int> adj[N];
        bool vis[N] = {false};
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        bfs(0, adj, vis, N);
        cout<<endl;
    }
}
/*This is a function problem.You only need to complete the function given below*/
/* You have to complete this function*/
/* Function to do BFS of graph
*  adj[]: array of vectors
*  vis[]: array to keep track of visited nodes
*/
//#include <queue>
void bfs(int s, vector<int> adj[], bool vis[], int N)
{
    // Your code here
    queue<int> q;
    vis[s] = 1;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        cout<<u<<" ";
        q.pop();
        for(auto i:adj[u]){
            if(vis[i] == 0){
                vis[i] = 1;
                q.push(i);
            }
        }
    }
}

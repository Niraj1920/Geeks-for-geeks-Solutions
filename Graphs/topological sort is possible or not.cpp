/*

Given a directed graph, you need to complete the function topoSort which returns an array having the topologically sorted elements of the array and takes two arguments. The first argument is the Graph graph represented as adjacency list and the second is the number of vertices N.

Note : There can be multiple topological sorts of a Graph.  The driver program that calls your function doesn't match your output element by element, but checks whether the output produced by your function is a valid topological sort or not.

Input:
The first line of input takes the number of test cases then T test cases follow . Each test case contains two lines. The first  line of each test case  contains two integers E and N representing no of edges and the number of vertices. Then in the next line are E  pairs of integers u, v representing an edge from u to v in the graph.

Output:
For each test case output will be 1 if the topological sort is done correctly else it will be 0.

User Task:
The task is to complete the function topoSort() which should return an array containing nodes in topological sorted manner.

Constraints:
1 <= T <= 50
1 <= E, N <= 50
0 <= u, v

Example:
Input
2
6 6 
5 0 5 2 2 3 4 0 4 1 1 3
4 4
3 0 1 0 2 0 0 1

Output:
1
0*/
#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
/*  Function to check if elements returned by user 
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, int* res, vector<int> adj[]){
    bool flag =true;
    for(int i=0;i<V && flag;i++)
    {
        int n=adj[res[i]].size();
        for(auto j : adj[res[i]])
        {
            for(int k=i+1;k<V;k++)
            {
                if(res[k]==j )
                    n--;
            }
        }
        if(n!=0)
            flag =false;
    }
    if(flag==false)
        return 0;
    return 1;
}
// Driver Code
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,E;
        cin>>E>>N;
        int u,v;
        
        vector<int> adj[N];
        
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }
    
        int *res = topoSort(N, adj);
        
        cout<<check(N, res, adj)<<endl;
       
    }
}
/*This is a function problem.You only need to complete the function given below*/
// The Graph structure is as folows
/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*   NOTE: You must return dynamically allocated array 
*/
void topological_sort(stack<int>&s, int V, vector<int> adj[], bool vis[]){
    vis[V]=true;
    for(int i=0;i<adj[V].size();i++){
        if(!vis[adj[V][i]]) topological_sort(s,adj[V][i],adj,vis);
    }
    s.push(V);
}

int* topoSort(int V, vector<int> adj[]){
    stack<int>s;
    bool vis[V+1]={false};
    for(int i=0;i<V;i++){
        if(vis[i]==false) topological_sort(s,i,adj,vis);
    }
    int *A=new int[s.size()];
    int i=0;
    while(!s.empty()){
        A[i]=s.top(); i++;
        s.pop();
    }
    return A;
}

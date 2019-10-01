/*
Given a undirected graph, the task is to complete the method isCyclic() to detect if there is a cycle in the undirected graph or not.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' testcases follow. Each testcase consists of two lines. Description of testcases are as follows: The First line of each testcase contains two integers 'N' and 'M' which denotes the no of vertices and no of edges respectively. The Second line of each test case contains 'M'  space separated pairs u and v denoting that there is a bidirectional  edge from u to v .

Output:
The method should return 1 if there is a cycle else it should return 0.

User task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function isCyclic.

Constraints:
1 <= T <= 100
1 <= N,M <= 100
0 <= u,v <=  N-1

Example:
Input:
3
2 2
0 1 0 0
4 3
0 1 1 2 2 3
5 4
0 1 2 3 3 4 4 2

Output:
1
0
1
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
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << isCyclic(adj, V)<<endl;
    }
}
/*This is a function problem.You only need to complete the function given below*/
/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/

bool isCycleUtil(vector<int> adj[], int j, bool *vis, int parent){
    vis[j] = true;
    vector<int>::iterator it;
    for(it=adj[j].begin(); it!=adj[j].end(); it++){
        //cout<<"src:"<<j<<",des:"<<*it<<" "<<vis[*it]<<endl;
        if(vis[*it] == false){
            if(isCycleUtil(adj, *it, vis, j)) return true;
        }
        else if(*it != parent){
            return true;
        }
    }
    //cout<<endl;
    return false;
}
bool isCyclic(vector<int> adj[], int V)
{
   // Your code here
   bool vis[V];
   int parent;
   for(int i=0; i<V; i++){
       vis[i] = false;
       //cout<<vis[i]<<" ";
   }//cout<<endl;
   
   for(int i=0; i<V; i++){
       if(vis[i] == false){
           if(isCycleUtil(adj, i, vis, -1))    return true;
       }
   }
   return false;
}

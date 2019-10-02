/*
Given a graph of V nodes represented in the form of adjacency matrix. The task is to find the shortest distance of all the vertex's from the source vertex.

Input:
The first line of input contains an integer T denoting the number of test cases . Then T test cases follow .The first line of each test case contains an integer V denoting the size of the adjacency matrix  and in the next line are 2*V space separated values, which denotes the weight of an edge of the matrix (graph). The third line of each test case contains an integer denoting the source vertex s.

Output:
For each test case output will be V space separated integers where the ith integer denote the shortest distance of ith vertex from source vertex.

You task:
You are required to complete the function dijkstra() which takes 3 arguments. The first argument is the adjacency matrix (graph), the second argument is the source vertex s and the third argument is V denoting the size of the matrix. The function prints  V space separated integers where i'th integer denotes the shortest distance of the i'th vertex from source vertex.

Constraints:
1 <= T <= 20 
1 <= V <= 20
0 <= graph[i][j] <= 1000
0 <= s

Example:
Input:
2
2
0 25 25 0
0
3
0 1 43 1 0 6 43 6 0
2

Output:
0 25
7 6 0
*/
#include<bits/stdc++.h>
using namespace std;
void dijkstra(vector<vector<int>> , int ,int );
int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }
        
        int s;
        cin>>s;
        
        dijkstra(g, s, V);
        cout<<endl;
       }
        return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/*  Function to implement Dijkstra
*   graph: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/

int minDist(vector<int> &dist, vector<bool> &vis){
    int u = INT_MAX, min_index = -1;
    for(int i=0; i<dist.size(); i++){
        if(vis[i] == false && dist[i] <= u){
            u = dist[i];
            min_index = i;
        }
    }
    return min_index;
}
void dijkstra(vector<vector<int>> graph, int src, int V)
{
    // Your code here
    //cout<<"src:"<<src<<endl;
    vector<int> dis(V, INT_MAX);
    dis[src] = 0;
    /*for(int i=0; i<V; i++){
        dis[i] = graph[src][i];
        cout<<dis[i]<<" ";
    }
    cout<<endl;*/
    vector<bool> visited(V, false);
    int count;//src is traversed.. so 1`
    for(count = 1; count<V; count++){
        int u = minDist(dis, visited);
        visited[u] = true;
        // cout<<u<<endl;
        //relaxation to all reachable nodes from u
        for(int i=0; i<V; i++){
            // cout<<i<<" "<<dis[i]<<" "<<u<<" "<<dis[u]<<" "<<graph[u][i]<<endl;
            if(graph[u][i] && !visited[i] && 
                dis[i] > dis[u]+ graph[u][i]){
                    
                    dis [i] = dis[u]+ graph[u][i];
                }
        }
    }
    for(int i=0; i<V; i++){
        cout<<dis[i]<<" ";
    }
    return;
}

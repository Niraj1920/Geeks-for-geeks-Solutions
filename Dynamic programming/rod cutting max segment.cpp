/*
Given an integer N denoting the Length of a line segment. you need to cut the line segment in such a way that the cut length of a line segment each time is integer either x , y or z. and after performing all cutting operation the total number of cutted segments must be maximum. 


Input
First line of input contains of an integer 'T' denoting number of test cases. First line of each testcase contains N . Second line of each testcase contains 3 space separated integers x , y and z.

Output
For each test case print in a new line an integer corresponding to the answer .


Constraints
1<=t<=70
1<=N,x,y,z<=4000
 

Example

Input

2
4
2 1 1
5
5 3 2


Output
4
2
*/
#include <iostream>
#include <vector>
using namespace std;

int cutSegments(int n, int a, int b, int c){
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    for(int i=0; i<=n; i++){
        if(dp[i] != -1){
            if(i+a <= n)    dp[i+a] = max(dp[i]+1, dp[i+a]);
            if(i+b <= n)    dp[i+b] = max(dp[i]+1, dp[i+b]);
            if(i+c <= n)    dp[i+c] = max(dp[i]+1, dp[i+c]);
        }
    }
    return dp[n];
}
int main() {
	//code
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
	    int len, a, b, c;
	    cin>>len;
	    cin>>a>>b>>c;
	    int res = cutSegments(len, a, b, c);
	    cout<<res<<endl;
	}
	return 0;
}

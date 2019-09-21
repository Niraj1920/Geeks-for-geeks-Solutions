/*
Given two strings X and Y. The task is to find the length of the longest common substring.

Input:
First line of the input contains number of test cases T. Each test case consist of three lines, first of which contains 2 space separated integers N and M denoting the size of string X and Y strings respectively. The next two lines contains the string X and Y.

Output:
For each test case print the length of longest  common substring of the two strings .

Constraints:
1 <= T <= 200
1 <= N, M <= 100

Example:
Input:
2
6 6
ABCDGH
ACDGHR
3 2
ABC
AC

Output:
4
1
*/
#include <iostream>
#include <string>
using namespace std;
int lcs(string &x, string &y, int  xlen, int ylen){
   int dp[xlen+1][ylen+1];
   int res = 0;
   for(int i=0; i<=xlen; i++){
       for(int j=0; j<=ylen; j++){
           if(i == 0 || j == 0){
               dp[i][j] = 0;
           }
           else if(x[i-1] == y[j-1]){
               dp[i][j] = dp[i-1][j-1] + 1;
               res = max(res, dp[i][j]);
           }
           else{
               dp[i][j] = 0;
           }
       }
   }
   return res; 
}
int main() {
	//code
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
	    int xlen, ylen;
	    string x, y;
	    cin>>xlen>>ylen;
	    //cout<<xlen<<" "<<ylen<<endl;
	    cin>>x;
	    cin>>y;
	    int res = lcs(x, y, xlen, ylen);
	    cout<<res<<endl;
	}
	return 0;
}

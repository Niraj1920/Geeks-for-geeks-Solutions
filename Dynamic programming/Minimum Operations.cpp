/*
You are given a number N. You have to find the number of operations required to reach N from 0. You have 2 operations available:

Double the number
Add one to the number
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer N.

Output:
For each test case, in a new line, print the minimum number of operations required to reach N from 0.

Constraints:
1<=T<=100
1<=N<=104

Example:
Input:
2
8
7
Input:
4
5
*/

#include <iostream>
using namespace std;

void minOperations(int n){
    int minops = 0;
    if(n == 0){
        cout<<minops<<endl;
        return;
    }
    while(n>1){
        if(n%2 == 0){
            n /= 2;
        }
        else{
            n -= 1;
        }
        minops += 1;
    }
    cout<<minops+1<<endl;
    return;
}
int main() {
	//code
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
	    int n;
	    cin>>n;
	    minOperations(n);
	}
	return 0;
}

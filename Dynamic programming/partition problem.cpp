/*
Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.

Input:
The first line contains an integer 'T' denoting the total number of test cases. Each test case constitutes of two lines. First line contains 'N', representing the number of elements in the set and the second line contains the elements of the set.

Output:
Print YES if the given set can be partioned into two subsets such that the sum of elements in both subsets is equal, else print NO.

Constraints:
1 <= T <= 100
1 <= N <= 100
0 <= arr[i] <= 1000

Example:
Input:
2
4
1 5 11 5
3
1 3 5 

Output:
YES
NO
*/
#include <iostream>
using namespace std;
#include <vector>

bool partition(vector<int> &A){
    int sum = 0, n = A.size();
    for(int i=0; i<n; i++)
        sum += A[i];
    if(sum%2 == 1)  return false;
    
    vector<vector<int>> dp(sum/2 + 1, vector<int>(n + 1));
    for(int i=0; i<=n; i++) dp[0][i] = true;
    for(int i=1; i<=sum/2; i++) dp[i][0] = false;
    
    for(int i=1; i<=sum/2; i++){
        for(int j=1; j<=n; j++){
            dp[i][j] = dp[i][j-1];
            if(i >= A[j-1]){
                dp[i][j] = dp[i][j] || dp[i - A[j-1]][j-1];
            }
        }
    }
    return dp[sum/2][n];
}
int main() {
	//code
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
	    int len;
	    cin>>len;
	    vector<int> A(len);
	    for(int j=0; j<len; j++){
	        cin>>A[j];
	    }
	    bool isExist = partition(A);
	    isExist ? cout<<"YES"<<endl : cout<<"NO"<<endl; 
	}
	return 0;
}

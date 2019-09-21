/*
Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.

Insert
Remove
Replace
All of the above operations are of cost=1.
Both the strings are of lowercase.

Input:
The First line of the input contains an integer T denoting the number of test cases. Then T test cases follow. Each tese case consists of two lines. The first line of each test case consists of two space separated integers P and Q denoting the length of the strings str1 and str2 respectively. The second line of each test case coantains two space separated strings str1 and str2 in order.

Output:
Corresponding to each test case, pirnt in a new line, the minimum number of operations required.

Constraints:
1 <= T <= 50
1 <= P <= 100
1 <= Q <= 100

Example:
Input:
1
4 5
geek gesek

Output:
1
*/
#include <iostream>
#include <vector>
using namespace std;

int editDistance(string str1, string str2, int len1, int len2){
    vector<vector<int>> dp(len1+1, vector<int>(len2+1));
    for(int i=0; i<=len1; i++)
        dp[i][0] = i;
    for(int j=0; j<=len2; j++)
        dp[0][j] = j;
    for(int i=1; i<=len1; i++){
        for(int j=1; j<=len2; j++){
            if(str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
        }
    }
    
    /*for(int i=0; i<=len1; i++){
        for(int j=0; j<=len2; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return dp[len1][len2];
}

int main() {
	//code
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
	    int strlen1, strlen2;
	    cin>>strlen1>>strlen2;
	    string str1, str2;
	    cin>>str1;
	    cin>>str2;
	    int res = editDistance(str1, str2, strlen1, strlen2);
	    cout<<res<<endl;
	}
	return 0;
}

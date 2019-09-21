/*
Given a value N, total sum you have. You have to make change for Rs. N, and there is infinite supply of each of the denominations in Indian currency, i.e., you have infinite supply of { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000} valued coins/notes, Find the minimum number of coins and/or notes needed to make the change for Rs N.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case consist of an Integer value N denoting the amount to get change for.

Output:
Print all the denominations needed to make the change in a separate line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106

Example:
Input:
1
43

Output:
20 20 2 1
*/
#include <iostream>
using namespace std;
#include <vector>
void minCoins(int n){
	int coins[] = {1,2,5,10,20,50,100,200,500,2000};
    vector<int> res;
    //cout<<n<<endl;
    for(int i=9; i>=0 && n != 0; i--){
        if(n/coins[i] >= 1){
            int temp = n/coins[i];
            n -= temp*coins[i];
            while(temp>0){
                res.push_back(coins[i]);
                temp--;
            }
        }
    }
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }cout<<endl;
}
int main() {
	//code
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
	    int n;
	    cin>>n;
	    minCoins(n);
	}
	return 0;
}

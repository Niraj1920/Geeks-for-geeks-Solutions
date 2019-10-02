/*
Given an array of N distinct elementsA[ ]. The task is to find the minimum number of swaps required to sort the array. Your are required to complete the function which returns an integer denoting the minimum number of swaps, required to sort the array.

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow . Each test case contains an integer N denoting the no of element of the array A[ ]. In the next line are N space separated values of the array A[ ] .

Output:
For each test case in a new line output will be an integer denoting  minimum umber of swaps that are  required to sort the array.

Constraints:
1 <= T <= 100
1 <= N <= 103
1 <= A[] <= 104
 

User Task: Your task is to complete minSwaps() which should return number of swaps required to make the array elements sorted.

Example(To be used only for expected output):
Input:
2
4
4 3 2 1
5
1 5 4 3 2

Output:
2
2
*/
// C++ program to find minimum number of swaps
// required to sort an array
#include<bits/stdc++.h>
using namespace std;
int minSwaps(int A[], int N);
// Driver program to test the above function
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<minSwaps(a,n)<<endl;
	}
}
/*This is a function problem.You only need to complete the function given below*/
/* You are required to complete this method */
int minSwaps(int A[], int N){
    /*Your code here */
    /*
    //Solution using selection sort...O(N) time
    int count = 0;
    for(int i=0; i<N; i++){
        int min = A[i],  min_index = i;
        for(int j=i+1; j<N; j++){
            if(A[j] < min){  min = A[j];
            min_index = j;}
            
        }
        if(min_index != i){
            swap(A[min_index], A[i]);
            count++;
        }
    }
    return count;*/
    //solution using graph.. O(NlogN)time and O(N) space...
    pair<int, int> p[N];
    for(int i=0; i<N; i++){
        p[i].first = A[i];
        p[i].second = i;
    }
    sort(p, p+N);
    int swaps = 0;
    vector<bool> vis(N, false);
    for(int i=0; i<N; i++){
        if(vis[i] || p[i].first == i) continue;
        int j = i, count = 0;
        while(vis[j] == false){
            //cout<<j<<" "<<p[j].first<<" "<<p[j].second<<endl;
            vis[j] = true;
            j = p[j].second;
            //cout<<j<<" "<<p[j].first<<" "<<p[j].second<<endl;
            count++;
        }
        if(count>0) swaps += count - 1;
    }
    return swaps;
}

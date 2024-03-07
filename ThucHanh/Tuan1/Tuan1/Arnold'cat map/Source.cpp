#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define for(i,n) for(int i = 0 ; i < n ; i ++ )
bool checkSame(vector<vector<int>> arr, int n) {
	int a = arr[0][0];
	for (i, n) {
		for (j, n) {
			if (a != arr[i][j])
				return 0;
		}
	}
	return 1;
}
int period(vector<vector<int>> arr,int n) {
	if (checkSame(arr, n))
		return 0;
	int k =0;
	vector<vector<int>> temp = arr;
	while(true)
	{
		vector<vector<int>> cur = temp;
		for (i, n) {
			for (j, n) {
				cur[(2 * i + j) % n][(i + j) % n] = temp[i][j];
			}
		}
		k++;
		if (cur == arr)
			break;
		temp =cur ;
	}
	return k;
	
}
int main() {
	int n; 
	cin >> n;
	vector <vector<int>> arr(n,vector<int>( n));
	for (i, n) {
		for (j, n) {
			cin >> arr[i][j];
		}
	}
	cout << period(arr, n);
	return 0;
}

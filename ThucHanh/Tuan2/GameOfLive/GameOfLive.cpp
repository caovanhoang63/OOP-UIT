#include <iostream>
#include <vector>
using namespace std;

vector <vector<int>> GameOfLive(vector<vector<int>> a, int m, int n, int k);
int Count(vector<vector<int>> a, int i, int j);
int main() {
	int n, m,k;
	cin >> m >> n;
	vector < vector<int> >a(m, vector<int>(n));
	for (auto&x : a)
		for (auto& y : x)
			cin >> y;
	cin >> k;
	for (auto x : GameOfLive(a, m, n, k)) {
		for (auto y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
	return 0;
}

int Count(vector<vector<int>> a, int r, int c){
	int  count = 0;
	for (int i = r - 1; i <= r + 1; i++) {
		for (int j = c - 1; j <= c + 1; j++) {
			if ((i == r && j == c) || (i < 0 || j < 0) || (i >= a.size()|| j >= a.front().size()) ) {
				continue;
			}
			if (a[i][j] == 1) {
				count++;
			}
		}
	}
	return count;

}
vector <vector<int>> GameOfLive(vector<vector<int>>a, int m, int n, int k) {
	vector<vector<int>> result = a;
	for (int i = 1; i <= k; i++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j]) {
					switch (Count(a,i,j))
					{
					case 0:
					case 1:
						result[i][j] = 0;
						break;
					case 2:
					case 3:
						break;
					default:
						result[i][j] = 0;
						break;
					}
				}
				else {
					if (Count(a, i, j) == 3)
						result[i][j] = 1;
				}
			}
		}
		a = result;
	}
	return result;
}
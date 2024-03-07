#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    map<vector<vector<int>>, int> mp;
    mp[arr] = 0;

    vector<vector<int>> curr = arr;
    int k = 1;
    while (true) {
        vector<vector<int>> next(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = (2 * i + j) % n;
                int y = (i + j) % n;
                next[x][y] = curr[i][j];
            }
        }
        if (mp.find(next) != mp.end()) {
            cout << k - mp[next] << endl;
            break;
        }
        mp[next] = k;
        curr = next;
        k++;
    }

    return 0;
}
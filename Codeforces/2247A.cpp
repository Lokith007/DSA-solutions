// Zero Sum [Medium]
// https://codeforces.com/problemset/problem/2247A/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sum += x;
        }

        if (n % 2 == 1)
            cout << "NO\n";
        else if (sum % 4 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
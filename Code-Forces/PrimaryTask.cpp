#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    if (s.size() < 3) {
        cout << "NO\n";
        return;
    }

    if (s[0] == '1' && s[1] == '0') {
        if (s[2] == '0') {
            cout << "NO\n";
            return;
        }

        int power = 0;
        for (int i = 2; i < s.size(); i++) {
            power = power * 10 + (s[i] - '0');
        }

        if (power >= 2)
            cout << "YES\n";
        else
            cout << "NO\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;

    // your logic here

    swap(a[0],b[0]);

    cout << a << " "<< b << \n';

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
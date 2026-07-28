#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int count = 0;
    while(n > 0){
        
        if(n >= 2 && n <= 4){
            count += 1;
            break;
        }
        if(n > 4){
            n -= 4;
            count += 1;
        }
    }
    cout << count << '\n';
    

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
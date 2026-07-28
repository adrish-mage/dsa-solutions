#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int left = 0;
    int right = n - 1;
    while(left < n && s[left] == 'W'){
        left ++;
    }
    while(right > 0 && s[right] == 'W' ){
        right --;
    }
    if(left > right ){
        cout << 0 << '\n';
    }else{
        cout << right - left + 1 << endl;
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
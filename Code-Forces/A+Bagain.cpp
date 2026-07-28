#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int temp = n;
    // if first two ints are 10
    while(temp >= 99){
        temp /= 10;
    }
    if(temp == 10){
        int power = 0;
        for(int i=0; i<=1 && n >0; i++ ){
            power = power*10 + n % 10;
            n /= 10;
        }
        if(power >= 2){
            cout << 'YES' <<'\n';
        }else{
            cout << 'NO' <<'\n';
        }
    }else{
        cout << 'NO' <<'\n'
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
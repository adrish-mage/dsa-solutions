#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int fibonacciMemo(int n, vector<int>& f) {
    if (n == 0 || n == 1) {
        return n;
    }
    if (f[n] != -1) {
        return f[n];
    }
    return f[n] = fibonacciMemo(n - 1, f) + fibonacciMemo(n - 2, f);
}

int fibTabulation(int n) {
    vector<int> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

int waysRecur(int n)  // O(2^n)
{
    if (n == 0 || n == 1) {
        return 1;
    }
    return waysRecur(n - 1) + waysRecur(n - 2);
}
int waysMemo(int n, vector<int>& dp) {  // O(n)

    if (n == 0 || n == 1) {
        return 1;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    return dp[n] = waysMemo(n - 1, dp) + waysMemo(n - 2, dp);
}
int waysMemo(int n)  // O(n)
{
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main() {
    int n = 6;

    vector<int> memo(n + 1, -1);
    vector<int> dp(n + 1, -1);

    cout << "fibonacci: " << fibonacci(n) << endl;
    cout << "fibonacciMemo: " << fibonacciMemo(n, memo) << endl;
    cout << "fibTabulation: " << fibTabulation(n) << endl;
    cout << "waysRecur: " << waysRecur(n) << endl;
    cout << "waysMemo (top-down): " << waysMemo(n, dp) << endl;
    cout << "waysMemo (tabulation): " << waysMemo(n) << endl;

    return 0;
}
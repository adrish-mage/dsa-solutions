#include <iostream>
#include <vector>
using namespace std;
int unboundedKnapsackMemo(vector<int> val, vector<int> wt, int W, int n, vector<vector<int>>& dp) {
    if(n == 0 || W == 0){
        return 0;
    }
    if (dp[n][W] != -1){
        return dp[n][W];
    }
    if (wt[n - 1] <= W) {
        // include
        int ans1 = unboundedKnapsackMemo(val, wt, W - wt[n - 1], n, dp) + val[n - 1];
        // exclude
        int ans2 = unboundedKnapsackMemo(val, wt, W, n-1, dp);
        return dp[n][W] = max(ans1,ans2);

    }else{
        return dp[n][W] = unboundedKnapsackMemo(val, wt, W, n-1, dp);
    }
}
void UnboundedKnapsackTab(vector<int> val, vector<int> wt, int W, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i < dp.size(); i++) {
        for (int j = 1; j < dp[0].size(); j++) {
            if (wt[i - 1] <= j) {
                // include and exclude consideration
                dp[i][j] = max(dp[i][j - wt[i - 1]] + val[i - 1],
                               dp[i - 1][j]);  // self-referential row approach
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << "The ans is : " << dp[n][W] << endl;
}
int main() {
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    int W = 7;
    int n = 5;
    UnboundedKnapsackTab(val, wt, W, n);

    return 0;
}
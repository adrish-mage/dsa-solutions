#include <iostream>
#include <vector>
using namespace std;

int knapsackRec(vector<int> val, vector<int> wt, int W, int n) {  // O(2^n)
    if (n == 0 || W == 0) {
        return 0;
    }

    int itemWt = wt[n - 1];
    int itemVal = val[n - 1];

    if (itemWt <= W) {
        // include
        int ans1 = knapsackRec(val, wt, W - itemWt, n - 1) + itemVal;
        // exclude
        int ans2 = knapsackRec(val, wt, W, n - 1);

        return max(ans1, ans2);
    } else {
        // exclude
        return knapsackRec(val, wt, W, n - 1);
    }
}
int knapsackMemo(vector<int> val, vector<int> wt, int W, int n,
                 vector<vector<int>>& dp) {  // O(n*W)
    if (n == 0 || W == 0) {
        return 0;
    }
    if (dp[n][W] != -1) {
        return dp[n][W];
    }
    int itemWt = wt[n - 1];
    int itemVal = val[n - 1];

    if (itemWt <= W) {
        // include
        int ans1 = knapsackMemo(val, wt, W - itemWt, n - 1, dp) + itemVal;
        // exclude
        int ans2 = knapsackMemo(val, wt, W, n - 1, dp);

        return dp[n][W] = max(ans1, ans2);
    } else {
        // exclude
        return dp[n][W] = knapsackMemo(val, wt, W, n - 1, dp);
    }
}
void knapsackTab(vector<int> val, vector<int> wt, int W, int n) {
    
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i < dp.size(); i++) {
        for (int j = 1; j < dp[0].size(); j++) {
            if(wt[i-1] <= j){
                // include and exclude consideration
                dp[i][j] = max(dp[i-1][j-wt[i-1]] + val[i-1], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
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

    cout << "Rec: " << knapsackRec(val, wt, W, n) << endl;

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    cout << "Memo: " << knapsackMemo(val, wt, W, n, dp) << endl;

    knapsackTab(val, wt, W, n);

    return 0;
}
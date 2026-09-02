#include <iostream>
#include <vector>
using namespace std;

bool targetSumSubset(vector<int> nums, int target) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    for (int i = 1; i < dp.size(); i++) {
        for (int j = 1; j < dp[0].size(); j++) {
            if (nums[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j - nums[i - 1]] + nums[i - 1], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][target] == target;
}
int main() {
    vector<int> nums = {4, 2, 7, 1, 3};
    cout << (targetSumSubset(nums, 10) ? "true" : "false") << endl;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

struct MinMax {
    int minVal;
    int maxVal;
};

MinMax findMinMaxDynamic(const vector<int>& arr) {
    if (arr.empty()) {
        cerr << "Error: Empty list." << endl;
        return {INT_MIN, INT_MAX};
    }

    int n = arr.size();
    vector<vector<MinMax>> dp(n, vector<MinMax>(n));

    for (int i = 0; i < n; ++i) {
        dp[i][i].minVal = arr[i];
        dp[i][i].maxVal = arr[i];
    }

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;

            dp[i][j].minVal = min(dp[i][j - 1].minVal, arr[j]);
            dp[i][j].maxVal = max(dp[i][j - 1].maxVal, arr[j]);
        }
    }

    return dp[0][n - 1];
}

int main() {
    vector<int> arr = {3, 1, 8, 5, 2, 7, 4, 6};

    MinMax result = findMinMaxDynamic(arr);

    cout << "Minimum value: " << result.minVal << endl;
    cout << "Maximum value: " << result.maxVal << endl;

    return 0;
}

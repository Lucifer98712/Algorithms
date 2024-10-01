#include <iostream>
#include <vector>

using namespace std;

// Function to perform Matrix Chain Multiplication
void matrixChainMultiplication(const vector<int>& dimensions) {
    int n = dimensions.size() - 1;  // Number of matrices

    // Create a 2D table to store the minimum number of multiplications
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Fill the table using bottom-up dynamic programming
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i < n - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    // Minimum number of multiplications is stored in dp[0][n-1]
    cout << "Minimum number of multiplications: " << dp[0][n - 1] << endl;
}

int main() {
    // Example: Matrix dimensions for four matrices A(10x30), B(30x5), C(5x60), and D(60x10)
    vector<int> dimensions = {10, 30, 5, 60, 10};

    cout << "Matrix Dimensions: ";
    for (int dim : dimensions) {
        cout << dim << " ";
    }
    cout << endl;

    // Perform Matrix Chain Multiplication
    matrixChainMultiplication(dimensions);

    return 0;
}

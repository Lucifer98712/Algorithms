#include <iostream>
#include <vector>

using namespace std;

// Function to find the minimum and maximum values in a list
pair<int, int> findMinMax(const vector<int>& arr) {
    if (arr.empty()) {
        // Handle the case when the list is empty
        cerr << "Error: Empty list." << endl;
        return make_pair(INT_MAX, INT_MIN);
    }

    int minVal = arr[0];
    int maxVal = arr[0];

    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        } else if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    return make_pair(minVal, maxVal);
}

int main() {
    vector<int> arr = {3, 1, 8, 5, 2, 7, 4, 6};

    pair<int, int> result = findMinMax(arr);

    cout << "Minimum value: " << result.first << endl;
    cout << "Maximum value: " << result.second << endl;

    return 0;
}

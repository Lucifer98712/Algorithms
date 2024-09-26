#include <iostream>

using namespace std;

int fibonacci(int n) {
    if (n <= 1)
        return n;

    int n1 = 0;
    int n2 = 1;
    int temp = 0;

    for (int i = 2; i <= n; i++) {
        temp = n1 + n2;
        n2 = n1;
        n1 = temp;
    }

    return temp;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int result = fibonacci(n);

    cout << "The " << n << "th Fibonacci number is: " << result << endl;

    return 0;
}

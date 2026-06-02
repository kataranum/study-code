#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[4] = {5, 2, 8, 1};
    int n = 4;

    for (int i = 0; i < n - 1; i++) {
        // Fehler: j geht immer bis n-1 (auch über sortierten bereich)
        // zugriff auf [j+1] ist möglich out-of-bounds
        for (int j = 0; j <= n - 1; j++) {
            // Fehler(?): Bedingung ist falschrum
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printArray(arr, n);
    }

    return 0;
}
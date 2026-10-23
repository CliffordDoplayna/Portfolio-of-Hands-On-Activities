#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int SIZE = 100;
    int arr[SIZE];

    srand(time(0));

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Display the array
    cout << "100 Random Values:" << endl;
    displayArray(arr, SIZE);

    return 0;
}
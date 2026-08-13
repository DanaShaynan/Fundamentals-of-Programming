#include <iostream>
using namespace std;

int main() {

    const int SIZE = 10;
    int numbers[SIZE];

    int sum = 0;
    int evenCount = 0;
    int oddCount = 0;

    cout << "Enter 10 integers:\n";

    for (int i = 0; i < SIZE; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> numbers[i];
    }

    int maximum = numbers[0];
    int minimum = numbers[0];

    for (int i = 0; i < SIZE; i++) {

        sum += numbers[i];

        if (numbers[i] > maximum)
            maximum = numbers[i];

        if (numbers[i] < minimum)
            minimum = numbers[i];

        if (numbers[i] % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }

    double average = static_cast<double>(sum) / SIZE;

    cout << "\n===== Array Analysis =====\n";
    cout << "Maximum: " << maximum << endl;
    cout << "Minimum: " << minimum << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Even numbers: " << evenCount << endl;
    cout << "Odd numbers: " << oddCount << endl;

    return 0;
}

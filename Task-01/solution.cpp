#include <iostream>
using namespace std;

int main() {

    double mark1, mark2, mark3;
    double average;
    char grade;

    cout << "Enter the mark for subject 1: ";
    cin >> mark1;

    cout << "Enter the mark for subject 2: ";
    cin >> mark2;

    cout << "Enter the mark for subject 3: ";
    cin >> mark3;

    average = (mark1 + mark2 + mark3) / 3;

    if (average >= 90)
        grade = 'A';
    else if (average >= 80)
        grade = 'B';
    else if (average >= 70)
        grade = 'C';
    else if (average >= 60)
        grade = 'D';
    else
        grade = 'F';

    cout << "\nAverage: " << average << endl;
    cout << "Grade: " << grade << endl;

    return 0;
}

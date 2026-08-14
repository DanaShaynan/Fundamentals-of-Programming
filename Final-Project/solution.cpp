#include <iostream>
#include <string>
using namespace std;

const int MAX_CARS = 50;

// Car information
struct Car {
    string type;
    string plateNumber;
    string color;

    bool isCleaned;
    bool isCharged;
    bool oilChanged;
};

// Service history
struct Service {
    string plateNumber;
    string serviceName;
};

// Function to add a new car
void addCar(Car cars[], int& carCount) {

    if (carCount >= MAX_CARS) {
        cout << "\nCar storage is full.\n";
        return;
    }

    cout << "\n===== Add New Car =====\n";

    cout << "Enter car type: ";
    cin >> cars[carCount].type;

    cout << "Enter plate number: ";
    cin >> cars[carCount].plateNumber;

    cout << "Enter car color: ";
    cin >> cars[carCount].color;

    cars[carCount].isCleaned = false;
    cars[carCount].isCharged = false;
    cars[carCount].oilChanged = false;

    carCount++;

    cout << "\nCar added successfully!\n";
}

// Function to find a car using plate number
int findCar(Car cars[], int carCount, string plateNumber) {

    for (int i = 0; i < carCount; i++) {

        if (cars[i].plateNumber == plateNumber) {
            return i;
        }
    }

    return -1;
}

// Function to display all cars
void displayCars(Car cars[], int carCount) {

    if (carCount == 0) {
        cout << "\nNo cars have been added yet.\n";
        return;
    }

    cout << "\n===== Cars List =====\n";

    for (int i = 0; i < carCount; i++) {

        cout << "\nCar " << i + 1 << endl;
        cout << "Type: " << cars[i].type << endl;
        cout << "Plate Number: " << cars[i].plateNumber << endl;
        cout << "Color: " << cars[i].color << endl;

        cout << "Cleaning: "
             << (cars[i].isCleaned ? "Completed" : "Not Completed")
             << endl;

        cout << "Charging: "
             << (cars[i].isCharged ? "Completed" : "Not Completed")
             << endl;

        cout << "Oil Change: "
             << (cars[i].oilChanged ? "Completed" : "Not Completed")
             << endl;
    }
}

// Function to clean a car
void cleanCar(Car cars[], int carCount, Service history[], int& serviceCount) {

    string plateNumber;

    cout << "\nEnter the plate number of the car: ";
    cin >> plateNumber;

    int index = findCar(cars, carCount, plateNumber);

    if (index == -1) {
        cout << "\nCar not found.\n";
        return;
    }

    cars[index].isCleaned = true;

    history[serviceCount].plateNumber = plateNumber;
    history[serviceCount].serviceName = "Car Cleaning";
    serviceCount++;

    cout << "\nCar cleaning completed successfully!\n";
}

// Function to charge a car
void chargeCar(Car cars[], int carCount, Service history[], int& serviceCount) {

    string plateNumber;

    cout << "\nEnter the plate number of the car: ";
    cin >> plateNumber;

    int index = findCar(cars, carCount, plateNumber);

    if (index == -1) {
        cout << "\nCar not found.\n";
        return;
    }

    cars[index].isCharged = true;

    history[serviceCount].plateNumber = plateNumber;
    history[serviceCount].serviceName = "Car Charging";
    serviceCount++;

    cout << "\nCar charging completed successfully!\n";
}

// Function to change oil
void changeOil(Car cars[], int carCount, Service history[], int& serviceCount) {

    string plateNumber;

    cout << "\nEnter the plate number of the car: ";
    cin >> plateNumber;

    int index = findCar(cars, carCount, plateNumber);

    if (index == -1) {
        cout << "\nCar not found.\n";
        return;
    }

    cars[index].oilChanged = true;

    history[serviceCount].plateNumber = plateNumber;
    history[serviceCount].serviceName = "Oil Change";
    serviceCount++;

    cout << "\nOil change completed successfully!\n";
}

// Function to remove a car
void removeCar(Car cars[], int& carCount) {

    string plateNumber;

    cout << "\nEnter the plate number of the car to remove: ";
    cin >> plateNumber;

    int index = findCar(cars, carCount, plateNumber);

    if (index == -1) {
        cout << "\nCar not found.\n";
        return;
    }

    for (int i = index; i < carCount - 1; i++) {
        cars[i] = cars[i + 1];
    }

    carCount--;

    cout << "\nCar removed successfully!\n";
}

// Function to display service history
void displayHistory(Service history[], int serviceCount) {

    if (serviceCount == 0) {
        cout << "\nNo services have been performed yet.\n";
        return;
    }

    cout << "\n===== Service History =====\n";

    for (int i = 0; i < serviceCount; i++) {

        cout << "\nService " << i + 1 << endl;
        cout << "Plate Number: "
             << history[i].plateNumber << endl;

        cout << "Service: "
             << history[i].serviceName << endl;
    }
}

// Main function
int main() {

    Car cars[MAX_CARS];
    Service history[MAX_CARS * 10];

    int carCount = 0;
    int serviceCount = 0;
    int choice;

    do {

        cout << "\n====================================\n";
        cout << "        CAR CLEANING SYSTEM\n";
        cout << "====================================\n";

        cout << "1. Add Car\n";
        cout << "2. Display Cars\n";
        cout << "3. Clean Car\n";
        cout << "4. Charge Car\n";
        cout << "5. Change Oil\n";
        cout << "6. Remove Car\n";
        cout << "7. Display Service History\n";
        cout << "8. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                addCar(cars, carCount);
                break;

            case 2:
                displayCars(cars, carCount);
                break;

            case 3:
                cleanCar(cars, carCount, history, serviceCount);
                break;

            case 4:
                chargeCar(cars, carCount, history, serviceCount);
                break;

            case 5:
                changeOil(cars, carCount, history, serviceCount);
                break;

            case 6:
                removeCar(cars, carCount);
                break;

            case 7:
                displayHistory(history, serviceCount);
                break;

            case 8:
                cout << "\nThank you for using Car Cleaning System!\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 8);

    return 0;
}

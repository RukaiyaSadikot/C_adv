#include <iostream>
#include <cstring>
using namespace std;

class Train {
        private:
            int trainNumber;
            char trainName[50];
            char source[50];
            char destination[50];
            char trainTime[20];

            static int trainCount;

        public:
            Train() {
                trainNumber = 0;
                strcpy(trainName, "");
                strcpy(source, "");
                strcpy(destination, "");
                strcpy(trainTime, "");
                trainCount++;
            }
            Train(int num, const char name[], const char src[], const char dest[], const char time[]) {
                trainNumber = num;
                strcpy(trainName, name);
                strcpy(source, src);
                strcpy(destination, dest);
                strcpy(trainTime, time);
                trainCount++;
            }
            ~Train() {
                trainCount--;
            }
            int getTrainNumber() {
                return trainNumber;
            }
            void inputTrainDetails() {
                cout << "Enter Train Number: ";
                cin >> trainNumber;
                cin.ignore();

                cout << "Enter Train Name: ";
                cin.getline(trainName, 50);

                cout << "Enter Source: ";
                cin.getline(source, 50);

                cout << "Enter Destination: ";
                cin.getline(destination, 50);

                cout << "Enter Train Time: ";
                cin.getline(trainTime, 20);
            }
            void displayTrainDetails() {
                cout << "Train Number: " << trainNumber << endl;
                cout << "Train Name: " << trainName << endl;
                cout << "Source: " << source << endl;
                cout << "Destination: " << destination << endl;
                cout << "Train Time: " << trainTime << endl;
                cout << "-------------------------" << endl;
            }
            static int getTrainCount() {
                return trainCount;
            }
};

int Train::trainCount = 0;

class RailwaySystem {
    private:
        Train trains[100];
        int totalTrains;

    public:
        RailwaySystem() {
            totalTrains = 0;
            trains[totalTrains++] = Train(101, "Okha Express", "Surat", "Mumbai", "10 AM");
            trains[totalTrains++] = Train(102, "Rajdhani Express", "Delhi", "Mumbai", "5 PM");
            trains[totalTrains++] = Train(103, "Shatabdi Express", "Ahmedabad", "Jaipur", "6 AM");
        }

        void addTrain() {
            trains[totalTrains].inputTrainDetails();
            totalTrains++;
            cout << "Train Added Successfully!\n";
        }

        void displayAllTrains() {
            for (int i = 0; i < totalTrains; i++) {
                cout << "\nTrain " << i + 1 << " Details:\n";
                trains[i].displayTrainDetails();
            }
        }

        void searchTrainByNumber(int num) {
            for (int i = 0; i < totalTrains; i++) {
                if (trains[i].getTrainNumber() == num) {
                    trains[i].displayTrainDetails();
                    return;
                }
            }
            cout << "Train not found!\n";
        }
};

int main() {
    RailwaySystem system;
    int choice, number;

    do {
        cout << "--- Railway Reservation System Menu ---" << endl;
        cout << "1. Add New Train Record" << endl;
        cout << "2. Display All Train Records" << endl;
        cout << "3. Search Train by Number" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        
        cin >> choice;

        switch (choice) {
        case 1:
            system.addTrain();
            break;

        case 2:
            system.displayAllTrains();
            break;

        case 3:
            cout << "Enter Train Number: ";
            cin >> number;
            system.searchTrainByNumber(number);
            break;

        case 4:
            cout << "Exiting Program..." << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}


#include "Terminal.h"



// Runs the terminal and processes the information being input by the user
void Terminal::open() {
	int code = 0;
	string memberName = "";
	string cardNumber = "";
	string input = "";
	bool running = true;

	displayMenu();

	while (running) {
		getInputInt(&code);
		switch (code) {
            case 1: {
                enterPatientName();
                break;
            }
            case 2: {
                enterMemberCardData();
                break;
            }
            case 3: {
                enterServiceCode();
                break;
            }
            case 8: {
                running = false;
                cout << "Exiting ChocAn Terminal...\n";
                break;
            }
            default: {
                cout << "Invalid option. Please try again.\n";
                break;
		}
	}
}

// Displays the terminal menu and prompts the user to enter
void Terminal::displayMenu() {
	cout << "ChocAn Terminal\n";
    cout << "1. Enter Name of Patient\n";
    cout << "2. Enter Member Card Data\n";
    cout << "3. Enter Service Code\n";
    cout << "8. Exit\n";
    cout << "Select an option: ";

	//cout << "Welcome to ChocAn! Enter 8 to quit" << endl;
}

// Gets code input from the user
void Terminal::getInputInt(int* code) {
	cin >> *code;
}

// Prompts the user to enter the name of the patient
void Terminal::enterPatientName() {
    string patient_name;
    cout << "Enter the name of the patient: ";
    cin.ignore(); // Ignore newline character
    getline(cin, patient_name);
    // Process or store 'patient_name' as needed
}

// Prompts the user to enter a members card number
void Terminal::enterMemberCardData() {
    int card_number;
    std::cout << "Enter the Member Card number: ";
    getInputInt(&card_number);
    // Validate 'card_number' against ChocAn system data or process further
}

// Prompts the user to enter a service code from the menu
void Terminal::enterServiceCode() {
    int service_code;
    std::cout << "Enter the service code: ";
    getInputInt(&service_code);
    // Validate 'service_code' and process the service or store it
}


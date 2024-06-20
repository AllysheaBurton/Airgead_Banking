// Allyshea Burton 06/09/2024
//
// AirgeadBanking.cpp
//
// The objective is to create an app that calculates an account interest in a certain amount of years

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Function to print details of the account for a given year
void printDetails(int year, double yearEndBalance, double interestEarned) {
    // Output year, year-end balance, and interest earned
    cout << right << setw(7) << year << "\t\t"
              << right << setw(15) << fixed << setprecision(2) << yearEndBalance << "\t\t"
              << right << setw(15) << fixed << setprecision(2) << interestEarned << endl;
}

// Function to calculate balance without additional monthly deposits
double calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears) {
    // Convert yearly interest rate to monthly
    double monthlyInterestRate = (interestRate / 100) / 12;
    double balance = initialInvestment;

    for (int year = 1; year <= numberOfYears; ++year) {
        // Initialize yearly interest
        double interestEarnedThisYear = 0;

        for (int month = 1; month <= 12; ++month) {
            // Calculate monthly interest
            double interestEarnedThisMonth = balance * monthlyInterestRate;
            interestEarnedThisYear += interestEarnedThisMonth;
            // Update balance with interest
            balance += interestEarnedThisMonth;
        }

        // Print yearly details
        printDetails(year, balance, interestEarnedThisYear);
    }

    // Return final balance
    return balance;
}

// Function to calculate balance with additional monthly deposits
double balanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears) {
    // Convert yearly interest rate to monthly
    double monthlyInterestRate = (interestRate / 100) / 12;
    // Initial balance
    double balance = initialInvestment;

    for (int year = 1; year <= numberOfYears; ++year) {
        // Initialize yearly interest
        double interestEarnedThisYear = 0;

        for (int month = 1; month <= 12; ++month) {
            // Add monthly deposit
            balance += monthlyDeposit;
            // Calculate monthly interest
            double interestEarnedThisMonth = balance * monthlyInterestRate;
            interestEarnedThisYear += interestEarnedThisMonth;
            // Update balance with interest
            balance += interestEarnedThisMonth;
        }

        // Print yearly details
        printDetails(year, balance, interestEarnedThisYear);
    }

    // Return final balance
    return balance;
}

// Function to print centered title
void printCenteredTitle(const std::string& title, int width) {
    // Calculate padding for centering
    int padding = (width - title.length()) / 2;
    cout << setw(padding + title.length()) << title << setw(padding) << "" << endl;
}

// Function to print a line of characters
void printLine(char ch, int width) {
    for (int i = 0; i < width; ++i) {
        cout << ch;
    }
    cout << endl;
}

// Function to prompt the user to press any key to continue
void pressAnyKeyToContinue() {
    cout << "Press any key to continue...";
    cin.get();
    // The second get() waits for actual key press
    cin.get();
}


int main() {
    double initialInvestment, monthlyDeposit, interestRate;
    int numberOfYears;

    // Input for initial investment, monthly deposit, interest rate, and number of years
    cout << "Initial Investment Amount: ";
    cin >> initialInvestment;

    cout << "Monthly Deposit: ";
    cin >> monthlyDeposit;

    cout << "Annual Interest Rate (in percentage): ";
    cin >> interestRate;

    cout << "Number of years: ";
    cin >> numberOfYears;

    pressAnyKeyToContinue();

    cout << endl;
    printCenteredTitle("Balance and Interest Without Additional Monthly Deposits", 60);
    // Print header for no monthly deposit section
    printLine('=', 60);
    cout << right << setw(7) << "Year" << setw(24) << "Year End Balance" << setw(24) << "Interest Earned" << endl;
    // Print column headers
    printLine('-', 60);
    // Calculate and display results without monthly deposits
    calculateBalanceWithoutMonthlyDeposit(initialInvestment, interestRate, numberOfYears);

    cout << endl;
    printCenteredTitle("Balance and Interest With Additional Monthly Deposits", 60);
    // Print header for with monthly deposit section
    printLine('=', 60);
    cout << right << setw(7) << "Year" << setw(24) << "Year End Balance" << setw(24) << "Interest Earned" << endl;
    // Print column headers
    printLine('-', 60);
    // Calculate and display results with monthly deposits
    balanceWithMonthlyDeposit(initialInvestment, monthlyDeposit, interestRate, numberOfYears);

    // End of program
    return 0;
}

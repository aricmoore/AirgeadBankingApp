#include "InvestmentCalculator.h"
#include <iostream>
#include <limits>
#include <stdexcept>

/*
 * Project: Airgead Banking Investment Calculator
 * Author: Arielle Moore
 *
 * An OOP C++ console application that calculates investment growth
 * over time with compound interest, displaying reports with and 
 * without monthly deposits.
 */

int main() {
    try {
        // Initialises variables
        double initialInvestment = 0.0;
        double monthlyDeposit = 0.0;
        double annualInterestRate = 0.0;
        int numYears = 0;

        // Prompts user for inputs with basic validation (would be great to add unit tests)
        std::cout << "Enter Initial Investment Amount: $";
        std::cin >> initialInvestment;
        if (initialInvestment <= 0) throw std::invalid_argument("Initial investment must be positive.");

        std::cout << "Enter Monthly Deposit: $";
        std::cin >> monthlyDeposit;
        if (monthlyDeposit < 0) throw std::invalid_argument("Monthly deposit cannot be negative.");

        std::cout << "Enter Annual Interest Rate (in %): ";
        std::cin >> annualInterestRate;
        if (annualInterestRate < 0) throw std::invalid_argument("Annual interest rate cannot be negative.");

        std::cout << "Enter Number of Years: ";
        std::cin >> numYears;
        if (numYears <= 0) throw std::invalid_argument("Number of years must be positive.");

        // Clears the input buffer after numeric inputs
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Creates the calculator object
        InvestmentCalculator calculator(initialInvestment, monthlyDeposit, annualInterestRate, numYears);

        // Displays entered data and wait for user to continue
        calculator.displayInputData();

        // Displays reports
        calculator.displayReportWithoutDeposits();
        std::cout << "\n";
        calculator.displayReportWithDeposits();

        std::cout << "\nThank you for using the Airgead Banking Investment Calculator! I love you!\n";

    }
    catch (const std::exception& e) {
        std::cerr << "Input error: " << e.what() << "\nProgram will now exit.\n";
        return 1;
    }

    return 0;
}

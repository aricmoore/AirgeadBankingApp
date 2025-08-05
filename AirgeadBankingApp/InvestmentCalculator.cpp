#include "InvestmentCalculator.h"
#include <iomanip>
#include <sstream>
#include <conio.h>  // For _getch(), see displayInputData() 

// Constructor (using t_ prefix to indicate function parameters)
InvestmentCalculator::InvestmentCalculator(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterestRate, int t_numYears)
    : m_initialInvestment(t_initialInvestment),
    m_monthlyDeposit(t_monthlyDeposit),
    m_annualInterestRate(t_annualInterestRate),
    m_numYears(t_numYears) {
}

// Displays initial input values
void InvestmentCalculator::displayInputData() const {
    std::cout << "**********************************\n"
        << "********** Data Input ************\n"
        << "Initial Investment Amount: $" << std::fixed << std::setprecision(2) << m_initialInvestment << "\n"
        << "Monthly Deposit: $" << std::fixed << std::setprecision(2) << m_monthlyDeposit << "\n"
        << "Annual Interest: %" << std::fixed << std::setprecision(2) << m_annualInterestRate << "\n"
        << "Number of Years: " << m_numYears << "\n"
        << "Press any key to continue...\n";
    (void)_getch();  // Waits for a single key press (casts void to intentionally ignore key output value)
}

// Static helper to format double as a money string
std::string InvestmentCalculator::formatMoney(double t_amount) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << "$" << t_amount;
    return oss.str();
}

// Common report printer used for both reports
void InvestmentCalculator::printReport(bool t_includeMonthlyDeposit) const {
    const int tableWidth = 65;

    // Prints centred header line
    std::cout << std::string(tableWidth, '=') << '\n';

    // Selects title text depending on report type
    std::string title = t_includeMonthlyDeposit
        ? "Balance and Interest With Additional Monthly Deposits"
        : "Balance and Interest Without Additional Monthly Deposits";

    // Prints title centred
    int padding = (tableWidth - static_cast<int>(title.length())) / 2;
    std::cout << std::string(padding, ' ') << title << '\n';

    std::cout << std::string(tableWidth, '=') << '\n';

    // Right-aligns column headers
    std::cout << std::right
        << std::setw(10) << "Year"
        << std::setw(25) << "Year End Balance"
        << std::setw(30) << "Year End Earned Interest"
        << '\n';

    double balance = m_initialInvestment;

    // Loops through each year
    for (int year = 1; year <= m_numYears; ++year) {
        double interestEarned = 0.0;

        // Loops through each month
        for (int month = 1; month <= 12; ++month) {
            if (t_includeMonthlyDeposit) {
                balance += m_monthlyDeposit;  // Add monthly deposit
            }

            // Calculates monthly interest
            double monthlyInterest = balance * (m_annualInterestRate / 100.0 / 12.0);
            interestEarned += monthlyInterest;
            balance += monthlyInterest;
        }

        // Right-aligns data under headers
        std::cout << std::right
            << std::setw(10) << year
            << std::setw(25) << formatMoney(balance)
            << std::setw(30) << formatMoney(interestEarned)
            << '\n';
    }
}

// A wrapper to print report without monthly deposits
void InvestmentCalculator::displayReportWithoutDeposits() const {
    printReport(false);
}

// A wrapper to print report with monthly deposits
void InvestmentCalculator::displayReportWithDeposits() const {
    printReport(true);
}

#ifndef AIRGEAD_INVESTMENTCALCULATOR_H_
#define AIRGEAD_INVESTMENTCALCULATOR_H_
#include <iostream>
#include <string>

class InvestmentCalculator {
public:
    // Constructor to initialise member variables
    InvestmentCalculator(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterestRate, int t_numYears);

    // Displays input data to user
    void displayInputData() const;

    // Runs reports for user, without and with monthly deposits
    void displayReportWithoutDeposits() const;
    void displayReportWithDeposits() const;

private:
    // Member variables (using m_ prefix to indicate member variables)
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterestRate;
    int m_numYears;

    // Helper to format money
    static std::string formatMoney(double t_amount);

    // Calculates and prints yearly balances and interests without monthly deposits
    void printReport(bool t_includeMonthlyDeposit) const;
};

#endif  // AIRGEAD_INVESTMENTCALCULATOR_H_

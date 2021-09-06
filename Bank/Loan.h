#ifndef LOAN_H
#define LOAN_H

#include "Bank.h"


class Loan:public Bank
{
   private:
	   int LoanNo;
	float LoanAmount;
	int timePeriod;
	float interestRate;
	int status;
 public:

	void LoanDetails(int cnt);
	void displayLoan();
	void approveLoan();

};

#endif // LOAN_H

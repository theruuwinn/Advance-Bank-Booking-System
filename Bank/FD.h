#ifndef FD_H
#define FD_H

#include "Bank.h"


class FD:public Bank
{
	private:
		int month;
		float amt;
	public:
		void FDData();
		void FDDetail();
};

#endif // FD_H

#include"final.h"
using namespace std;

void Loan::LoanDetails(int cnt)
{
	//cout<<"\nSorry!!! But this Feature is unavailable. Kindly Update"<<endl;
	Loan b;
	int acc;
	cout<<"Enter Account Number: ";
	cin>>acc;
	int flag=0;
	ifstream inFile;
	inFile.open("Banks.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";
	while(inFile.read((char *) &b, sizeof(Bank)))
	{
		if(b.retacno()==acc)
		{
			b.disp ();
			flag=1;
		}
	}
	inFile.close();
	if(flag==0)
		cout<<"\n\nAccount number does not exist";
	else
	{
	    b.accno=acc;
	    cout<<"Enter Loan Amount you Require: ";
	    cin>>b.LoanAmount;
	    cout<<"\nEnter Duration(of Months in which you would repay Loan): ";
	    cin>>b.timePeriod;
		b.status=0;
		b.LoanNo=cnt;

	    ofstream outFile;
	    outFile.open("Loan.txt",ios::binary|ios::app);
	    outFile.write((char *)&b, sizeof(Loan));
	    outFile.close();



	}

   }
void Loan::approveLoan()
{
	fstream inFile;
	inFile.open("Loan.txt",ios::binary|ios::in|ios::out);

	int acc,lNo,lStatus,flag=0;
	Loan b;
	char ans;
	 cout<<"Enter Account Number: ";
	 cin>>acc;

	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";
	while(inFile.read((char *) &b, sizeof(Loan)))
	{
		//cout<<"\nb.retacno() "<<b.retacno();
		if(b.retacno()==acc)
		{
		 cout<<"\n\n\n********************Your LOAN Info**************"<<endl;
		 cout<<"\nLoan No\t\t"<<b.LoanNo<<endl;
		 cout<<"\nLoan amount\t\t"<<b.LoanAmount<<endl;
		 cout<<"\nLoan Duration\t\t"<<b.timePeriod<<endl;
		 cout<<"\nLoan Status\t\t"<<b.status;
		 cout<<"\nDo you want to change the Loan status(y/n)?";

			cin>>ans;
			if(ans=='y' || ans=='Y')
			{
				cout<<"Please enter the Loan status(1->Approve/0->Reject/Pending)";
				cin>>lStatus;
				b.status=lStatus;
				int pos=(-1)* sizeof(b);
				inFile.seekp(pos,ios::cur);
				inFile.write((char *) &b, sizeof(Loan));
				cout<<"\n\n\t Loan Info Updated";
			}

		 flag=1;
		}
	}

	if(flag==0)
		cout<<"\n\nAccount number does not exist";

 inFile.close();

}
void Loan::displayLoan()
{
	Loan b;
	int flag=0;
	ifstream inFile;
	inFile.open("Loan.txt",ios::in|ios::binary);
	int acc;
	cout<<"Enter Account Number: ";
	cin>>acc;

	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";
	while(inFile.read((char *) &b, sizeof(Loan)))
	{
		if(b.retacno()==acc)
		{
		 cout<<"\n********************Loan details**************"<<endl;
		 cout<<"Loan Amount: "<<b.LoanAmount<<endl;
		 cout<<"Loan Duration: "<<b.timePeriod<<endl;
		 cout<<"Loan Status: "<<b.status<<endl;
		 cout<<"Loan Status 1 -> Approved, 0 -> Rejected or Pending";
		 flag=1;
		}
	}
	inFile.close();
	if(flag==0)
	 cout<<"\n\nAccount number does not exist";

	getch();
}

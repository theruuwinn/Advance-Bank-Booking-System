#include"final.h"

using namespace std;

void FD::FDData()
{
	fstream inFile;
	inFile.open("Loan.txt",ios::binary|ios::in|ios::out);

	int acc,lNo,lStatus,flag=0;
	FD b;
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
		 cout<<"\n********************Loan details**************"<<endl;
//		 cout<<"Account Number: "<<b.<<endl;
		 cout<<"FD amount: "<<b.amt<<endl;
		 cout<<"Duration(in Months): "<<b.month<<endl;
		   //		int pos=(-1)* sizeof(b);
		     //		inFile.seekp(pos,ios::cur);
		       //		inFile.write((char *) &b, sizeof(FD));
			 //	cout<<"\n\n\t Record Updated";


		 flag=1;
		 break;
		}
	}

	if(flag==0)
		cout<<"\n\nAccount number does not exist";

inFile.close();
cout<<"After function";

}
void FD::FDDetail()
{

  ifstream inFile;
  int an,flag=0;
	inFile.open("Banks.txt",ios::binary);
	FD b;
	cout<<"Please Enter Your Account Number: ";
	 cin>>an;
	 cout<<endl;

	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";
	while(inFile.read((char *) &b, sizeof(Bank)))
	{
		if(b.retacno()==an)
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
		 float an,amt,fa,ir,ts;
		 int flaggy;
		 flaggy=1;
 fa=amt*(pow(	(1+(ir/12)),(ts)));
 cout<<"Plans Available for your FD are as follows(Compunded Monthly):"<<endl;
 cout<<"Sr.No.    Time Period                         : Minimum Amount :  Interest Rate"<<endl;
 cout<<"1.        Less Than 3 Months                  : Rs.30,000      : 7   %"<<endl;
 cout<<"2.        More Than 3 Months                  : Rs.45,000      : 8   %"<<endl;
 cout<<"3.        More Than 6 Months                  : Rs.70,000      : 9   %"<<endl;
 cout<<"4.        More Than 1 Year                    : Rs.85,000      : 9.5 %"<<endl;
 cout<<"5.        More Than 1.5 Years                 : Rs.1,00,000    : 10  %"<<endl;
 cout<<"6.        More Than 2 Years                   : Rs.1,15,000    : 12  %"<<endl;
 cout<<"7.        More Than 3 Years                   : Rs.1,25,000    : 13  %"<<endl;
 cout<<"8.        More Than 5 Years                   : Rs.1,50,000    : 15  %"<<endl<<endl<<endl;

 cout<<"Please Enter the Months for which you want to Invest: ";
 cin>>b.month;
 cout<<endl;
 cout<<"Please Enter the Amount for which you want to create FD: ";
 cin>>b.amt;
 cout<<endl;
 //getch();
 cout<<"Please Wait.....Verifying"<<endl;
 //getch();
 if(ts<3)
 {
   if(amt<30000)
	 {
	   cout<<"This Time Period is not Available for this amount"<<endl;
       flaggy=0;
	 }
   else
	 {
	   	ir=7;
		flaggy=1;
	 }
  }
 else if(ts>=3 && ts<6)
 {
  if(amt<45000)
  {
    cout<<"This is not a valid Amount for this time Period"<<endl;
	flaggy=0;
  }
  else
  {
   ir=8;
   flaggy=1;
  }
 }
 else if(ts>=6 && ts<12)
 {
  if(amt<70000)
  {
    cout<<"This is not a valid Amount for this time Period"<<endl;
	flaggy=0;
  }
  else
  {
   ir=9;
   flaggy=1;
  }
 }
 else if(ts>=12 && ts<18)
 {
  if(amt<85000)
  {
    cout<<"This is not a valid Amount for this time Period"<<endl;
	flaggy=0;
  }
  else
  {
   ir=9.5;
   flaggy=1;
  }
 }
 else if(ts>=18 && ts<24)
 {
  if(amt<100000)
  {
    cout<<"This is not a valid Amount for this time Period"<<endl;
	flaggy=0;
  }
  else
  {
   ir=10;
   flaggy=1;
  }
 }
 else if(ts>=24 && ts<36)
 {
  if(amt<115000)
  {
    cout<<"This is not a valid Amount for this time Period"<<endl;
	flaggy=0;
  }
  else
  {
   ir=12;
   flaggy=1;
  }
 }
 else if(ts>=36 && ts<60)
 {
  if(amt<125000)
  {
    cout<<"This is not a valid Amount for this time Period"<<endl;
	flaggy=0;
  }
  else
  {
   ir=13;
   flaggy=1;
  }
 }
 else if(ts>=60)
 {
  if(amt<150000)
  {
    cout<<"This is not a valid Amount for this time Period"<<endl;
	flaggy=0;
  }
  else
  {
   ir=15;
   flaggy=1;
  }
 }
 if(flaggy==1)
{
  cout<<"On Completion of Scheme you will get: ";
  cout.setf(ios::floatfield,ios::scientific);
  cout<<setprecision(50)<<fa;
  ofstream outFile;
	    outFile.open("FD.txt",ios::binary|ios::app);
	    outFile.write((char *)&b, sizeof(FD));
	    outFile.close();
}


	}
}

#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<ctype.h>
#include<iomanip>
#include<math.h>
#include<stdlib.h>

using namespace std;

class Bank
{
  protected:
  int accno;
  char nm[80];
  int bal;
  char type;
 public:

  void createacc(int);  //function to create an account
  void disp();   //function to show account info
  void modify();        //function to modify acc info
  void depo(int);       //function to deposit amount to account
  void widr(int);      //function to withdraw amount
  void rep();       //function to show data format
  int retacno();       //function to return account number
  int retbal();    //function to return balance amount
  char rettype();      //function to return type of account
  void setName(char []);
};


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

int readFile()
{
	Bank b;
	ifstream inFile;
  //int an,flag=0;
	inFile.open("Banks.txt",ios::binary);

	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return -1;
	}
	cout<<"\nBALANCE DETAILS\n";
	while(inFile.read((char *) &b, sizeof(Bank)))
	{

	}
       //	if(b==NULL)
	 //   cout<<"1979";d
	//else
	   if(b.retacno()<1979)
		return 1979;
	   else
		return b.retacno();
//	   cout<<"@@@Acc no"<<b.retacno();
}

void Bank::createacc(int cnt)
{
  crac:
  cout<<endl;
  accno=readFile();
  //cout<<"Acc no "<<accno;
  cout<<" 1. Enter User's Name: ";
  fflush(stdin);
  gets(nm);
  cout<<" 2.Enter Type of The account (C/S) : ";
  cin>>type;
  cout<<" 3. Enter User's Balance(Minimum Rs.1000 for any type): ";
  cin>>bal;
  if(bal<1000)
  {
   cout<<"Please Follow Minimum Account Balance in  order to create Account"<<endl;
   goto crac;
  }
  type=toupper(type);
  cout<<endl;
  //accno=1979;
  accno++;
  //cnt=0;
  //cnt++;
  cout<<"Account created successfully!!! Your Account Number is: "<<accno;
  }

void Bank::disp()
{
  cout<<"Account No. : "<<accno<<endl;
  cout<<"Account Holder Name : "<<nm<<endl;
  cout<<"Type of Account : "<<type<<endl;
  cout<<"Balance amount : "<<bal<<endl;
  getch();
}

void Bank::depo(int dep)
{
  bal=bal+dep;
  if(dep<=0)
  {
    bal=bal-dep;
    cout<<"Sorry.....You have input a wrong value"<<endl;
  }
  cout<<"User's Account Balance is: "<<bal<<endl;
}


void Bank::widr(int wid)
{
  if(wid>=bal-1000)
  {
    cout<<"Please Enter Value as per minimum acount balance rule. Pls contact Branch Manager if amount entred is big"<<endl;
  }
  else
  {
    bal=bal-wid;
    cout<<"Current Account Balance is: "<<bal<<endl;
  }
}

void Bank::rep()
{
  cout<<accno<<setw(10)<<" || "<<nm<<setw(10)<<" || "<<type<<setw(6)<<" || "<<bal<<endl;
}

int Bank::retacno()
{
	return accno;
}

int Bank::retbal()
{
	return bal;
}

char Bank::rettype()
{
	return type;
}

void Bank::setName(char name[50])
{
    strcpy(nm,name);
}

void input_bin(int);	//function to write acc info in the binary file
void disp_u(int);	//function to display account details given by user
void del_acc(int);	//function to delete record of file
void mod_acc(int);
void disp_all();		//function to display all account details
void dep_wid(int, int); // function to desposit/withdraw amount for given account
void ms();	//introductory screen function
void top1();    //at top of all screens
void load();


int main()
{
 system("cls");
// clrscr();
 ms();
 load();
 return 0;
}


void ms()
{
  system("cls");
  cout<<"             ======================================================"<<endl;
  cout<<"            ||      |||||||     ||||||    |||    ||     ||   ||   ||"<<endl;
  cout<<"            ||      ||   ||     ||  ||    |||||  ||     || ||     ||"<<endl;
  cout<<"            ||      |||||||     ||||||    ||  || ||     ||||      ||"<<endl;
  cout<<"            ||      ||   ||     ||  ||    ||   ||||     || ||     ||"<<endl;
  cout<<"            ||      |||||||     ||  ||    ||    |||     ||   ||   ||"<<endl;
  cout<<"             ======================================================"<<endl;

  cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
  cout<<"                                   -A Name You Can Rely on........Always"<<endl;
  cout<<"\nMade by 17IT111 Krushnal Soni and 17IT112 Urvish Soni";
 getch();

}


void input_bin(int count)
{
  Bank b;
  ofstream outFile;
  outFile.open("Banks.txt",ios::binary|ios::app);
  b.createacc(count);
  outFile.write((char *)&b, sizeof(Bank));
  getch();
  outFile.close();
}

void disp_u(int n)
{
	Bank b;
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
		if(b.retacno()==n)
		{
			b.disp ();
			flag=1;
		}
	}
	inFile.close();
	if(flag==0)
		cout<<"\n\nAccount number does not exist";
	getch();
}


void del_acc(int n)
{
	Bank b;
	int flag=0;
	int choice;
	ifstream inFile,inFile1;
	ofstream outFile;
	inFile.open("Banks.txt",ios::binary);
	inFile1.open("Banks.txt",ios::binary);
	if(!inFile1)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}

	cout<<"\nBALANCE DETAILS\n";
	while(inFile1.read((char *) &b, sizeof(Bank)))
	{
		if(b.retacno()==n)
		{
			b.disp ();
			flag=1;
			cout<<"Are you sure?(1->y/0->n)";
			cin>>choice;
		}
	}
	inFile1.close();
	if(flag==0)
		cout<<"\n\nAccount number does not exist";
	else if(choice==1){
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("temp.txt",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &b, sizeof(Bank)))
	{
		if(b.retacno()!=n)
		{	// flag=1;
			outFile.write((char *) &b, sizeof(Bank));
		}
	}

	inFile.close();
	outFile.close();
	remove("Banks.txt");
	rename("temp.txt","Banks.txt");
	cout<<"\n\n\tAccount Closed. For Further Procedures, please Talk to\nManager.Your Token Number is your old Account Number.";
	 }
}


void disp_all()
{
	Bank b;
	ifstream inFile;
	inFile.open("Banks.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c no. ||   NAME        || Type || Balance\n";
	cout<<"====================================================\n";
	while(inFile.read((char *) &b, sizeof(Bank)))
	{
		b.rep();
	}
	inFile.close();
	getch();
}


void dep_wid(int n, int option)
{
	int amt;
	int found=0;
	Bank b;
	fstream File;
	File.open("Banks.txt", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
       //	cout<<"111"<<n<<"b.retacno()"<<b.retacno();
	while(File.read((char *) &b, sizeof(Bank)) )
	{

		if(b.retacno()==n)
		{
			b.disp();
			if(option==1)
			{
				cout<<"\n\nEnter the amount to be Deposited: ";
				cin>>amt;
				b.depo(amt);
			}
			if(option==2)
			{
				cout<<"\n\nEnter the amount to be Widrawn";
				cin>>amt;
				int bal=b.retbal()-amt;
				if((bal<500 && b.rettype()=='S') || (bal<1000 && b.rettype()=='C'))
				{
					cout<<"Insufficience balance";
				}
				else
				{
					b.widr(amt);
					cout<<"\nAmount Widrawn"<<endl;
				}
			}
			int pos=(-1)* sizeof(b);
			File.seekp(pos,ios::cur);
			File.write((char *) &b, sizeof(Bank));
			found=1;
			break;
	       }
	}
	File.close();
	if(found==0)
		cout<<"\n\n Account Not Found ";
}

void mod_acc(int n)
{


	int amt;
	char name[50];
	int found=0;
	Bank b;
	fstream File;
	File.open("Banks.txt", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}

	while(File.read((char *) &b, sizeof(Bank)))
	{

		if(b.retacno()==n)
		{
			b.disp();
			cout<<"\n\nEnter The New User Name: ";
			fflush(stdin);
			gets(name);
			b.setName(name);
			int pos=(-1)* sizeof(b);
			File.seekp(pos,ios::cur);
			File.write((char *) &b, sizeof(Bank));
			cout<<"\n\n\tAccount Information Modified";
			found=1;
			break;
	       }
	}
	File.close();
	if(found==0)
		cout<<"\n\n Account Not Found ";
}


void top1()
{
  system("cls");
  cout<<endl;
  cout<<" Welcome to City Co-Op. Bank"<<endl;
  cout<<"_______________________________________________________________________________"<<endl;
}

void load()
{
     int ch;
 char pass[10];
 int ff=-1;
 int num,count=0,LoanNo=2341;
 Loan l;
 int utype; //User Type
 do
 {
  top1();
  cout<<"\n                              USER SELECTION PAGE";
  cout<<"\n                              -------------------"<<endl;
  cout<<"\n1. Admin";
  cout<<"\n2. Customer";
  cout<<"\n3. Exit";
  cout<<"\nPlease select your course of Action: ";
  cin>>utype;
  if(utype==1)
  {

	do{
		cout<<"\nEnter the Password: ";
		cin>>pass;
		if(strcmp(pass,"admin")==0)
		  {
		   ff=1;
		  }
		  else
		  {
			cout<<"\nIncorrect Password !!! Please enter again";
			ff=0;
		  }

		}while(ff==0);

	do
	  {
        system("cls");
			top1();
		cout<<"\n                             ADMIN ACTION SELECTION";
		cout<<"\n                             ----------------------"<<endl;
		cout<<"\n\n\t01. Create New Account";
		cout<<"\n\n\t02. List of All Account Holders";
		cout<<"\n\n\t03. Close an Account";
		cout<<"\n\n\t04. Modify an Account";
		cout<<"\n\n\t05. Approve Loan Aplication";
		cout<<"\n\n\t06. All Loans";
		cout<<"\n\n\t07. Exit";
		cout<<"\n\n\tSelect Your Action(1-7): ";
		cin>>ch;
        system("cls");
		switch(ch)
		{

		   case 1:
			top1();
			cout<<endl<<endl;
			cout<<"\n                             CREATE AN ACCOUNT";
			cout<<"\n                             -----------------"<<endl;
			input_bin(count++);
			break;
		   case 2:
			top1();
			cout<<endl<<endl;
			cout<<"\n                             DISPLAY ALL ACCOUNTS";
			cout<<"\n                             --------------------"<<endl;
			disp_all();
			break;
		   case 3:
			top1();
			cout<<endl<<endl;
			cout<<"\n                             CLOSE AN ACCOUNT";
			cout<<"\n                             ----------------"<<endl;
			cout<<"\n\n\tEnter The account No. : ";
			cin>>num;
			del_acc(num);
			getch();
			break;
		   case 4:
			top1();
			cout<<endl<<endl;
			cout<<"\n                             MODIFY AN ACCOUNT";
			cout<<"\n                             -----------------"<<endl;
			cout<<"\n\n\tEnter The account No. : ";
			cin>>num;
			mod_acc(num);
			break;
		   case 5:
			top1();
			cout<<endl<<endl;
			cout<<"\n                             LOAN APPROVAL";
			cout<<"\n                             -------------"<<endl;
			l.approveLoan();
			break;
		   case 6:
			top1();
			cout<<endl<<endl;
			cout<<"\n                             DISPLAY ALL LOANS";
			cout<<"\n                             -----------------"<<endl;
			l.displayLoan();
			break;

		   case 7:
			top1();
			cout<<"\n\n\tThanks for using City Co-Op. Bank";
			break;


		   default :
			cout<<"\a";
			break;
  }//end of switch
	  }while(ch!=7);
  }//end of if
  else if(utype==2)
  {

  do
	  {
	  system("cls");
	  top1();
	  cout<<"\n                             USER ACTION SELECTION";
	  cout<<"\n                             ---------------------"<<endl;
	  cout<<"\n\n\t01. Deposit an Ammount";
	  cout<<"\n\n\t02. Widraw an Amount";
	  cout<<"\n\n\t03. Account Information";
	  cout<<"\n\n\t04. Apply for Loan";
	  cout<<"\n\n\t05. Show Loan details";
	  cout<<"\n\n\t06. Exit";
	  cout<<"\n\n\tPlease select Your Action(1-6): ";
	  cin>>ch;
	  system("cls");
	  getch();
	  switch(ch)
	  {
	    case 1:
			top1();
			cout<<"\n                             DEPOSIT AMOUNT";
			cout<<"\n                             --------------"<<endl;
			cout<<"\n\n\tEnter the Account No. : ";
			cin>>num;
			dep_wid(num, 1);
			break;
	    case 2:
			top1();
			cout<<"\n                             WIDRAW AMOUNT";
			cout<<"\n                             -------------"<<endl;
			cout<<"\n\n\tEnter the Account No. : ";
			cin>>num;
			dep_wid(num, 2);
			break;
	    case 3:
			top1();
			cout<<"\n                             ACCOUNT INFO";
			cout<<"\n                             ------------"<<endl;
			cout<<"\n\n\tEnter the Account No. : ";
			cin>>num;
			disp_u(num);
			break;
	    case 4:
			top1();
			cout<<"\n                             LOAN APPLICAION";
			cout<<"\n                             ---------------"<<endl;
			l.LoanDetails(++LoanNo);
			break;

	    case 5:
			top1();
			cout<<"\n                             SHOW LOAN INFO";
			cout<<"\n                             ---------------"<<endl;
			l.displayLoan();
			break;

	    case 6:
			top1();
			cout<<"\n\n\tThanks for using City Co-Op. Bank";
			break;

	    default :
		       cout<<"\a";
  }
  getch();

	  }while(ch!=6);
 }


  getch();
 }while(utype!=3);
}

#include "final.h"


using namespace std;

int readFile();
void ms();
void load();

int main()
{
    system("cls");
    // clrscr();
    ms();
    load();
    return 0;
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

void ms()
{
  //clrscr();
  system("cls");
  //int gd = DETECT, gm;
  //initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
  //settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
  //setbkcolor(GREEN);
  //outtextxy(80,200,"Welcome to City Co-Op Bank Ltd.");

  cout<<"             ======================================================"<<endl;
  cout<<"            ||      |||||||     ||||||    |||    ||     ||   ||   ||"<<endl;
  cout<<"            ||      ||   ||     ||  ||    |||||  ||     || ||     ||"<<endl;
  cout<<"            ||      |||||||     ||||||    ||  || ||     ||||      ||"<<endl;
  cout<<"            ||      ||   ||     ||  ||    ||   ||||     || ||     ||"<<endl;
  cout<<"            ||      |||||||     ||  ||    ||    |||     ||   ||   ||"<<endl;
  cout<<"             ======================================================"<<endl;

  cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
  cout<<"                                   -A Name You Can Rely on........Always"<<endl;

 getch();

}


void input_bin(int count)
{
  Bank b;
  ofstream outFile;
  outFile.open("Banks.txt",ios::binary|ios::app);
  b.createacc(count);
  outFile.write((char *)&b, sizeof(Bank));
  //cout<<"\n"<<((char *)&b, sizeof(Bank));
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
				cout<<"\n\nEnter the amount to be Withdrawn:";
				cin>>amt;
				int bal=b.retbal()-amt;
				if((bal<500 && b.rettype()=='S') || (bal<1000 && b.rettype()=='C'))
				{
					cout<<"Insufficience balance";
				}
				else
				{
					b.widr(amt);
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

	//	cout<<"111"<<n<<"b.retacno()"<<b.retacno();
	while(File.read((char *) &b, sizeof(Bank)) )
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
  //clrscr();
  system("cls");
 // getch();
  cout<<endl;
  cout<<" Welcome to City Co-Op. Bank"<<endl;
  cout<<"_______________________________________________________________________________"<<endl;
}

void load()
{
     int ch, i=0;
 char pass[6];
 int ff=-1;
 int num,count=0,LoanNo=2341;
 Loan l;
 FD f;
 //char c;
 int utype;
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
        i=0;
		cout<<"\nEnter the Password: ";
		fflush(stdin);
		//getline(cin,pass);
		while(i<5)
		{
		    pass[i] = getch();
		    cout<<'*';
		    i++;
		}
		//cin>>pass;
		// cout<<strcmp(pass,"admin");
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
//		clrscr();
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
//		clrscr();
        system("cls");
		//getch();
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
		       //	getch();
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
		       //	getch();
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
	  //clrscr();
	  system("cls");
	  top1();
	  cout<<"\n                             USER ACTION SELECTION";
	  cout<<"\n                             ---------------------"<<endl;
	  cout<<"\n\n\t01. Deposit an Ammount";
	  cout<<"\n\n\t02. Withdraw an Amount";
	  cout<<"\n\n\t03. Account Information";
	  cout<<"\n\n\t04. Apply for Loan";
	  cout<<"\n\n\t05. Show Loan details";
	  cout<<"\n\n\t06. Apply for FD (NOT WORKING)";
	  cout<<"\n\n\t07. Show FD details (NOT WORKING)";
	  cout<<"\n\n\t08. Exit";
	  cout<<"\n\n\tPlease select Your Action(1-8): ";
	  cin>>ch;
	  //clrscr();
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
			cout<<"\n                             APPLY FOR FIXED DEPOSIT";
			cout<<"\n                             ----------------------"<<endl;
			cout<<"This feature is not supported in this version.\nPlease Update for Availing This Feature."<<endl;
			cout<<"Sorry for Inconvinence"<<endl;
			//f.FDDetail();
			break;

	    case 7:
			top1();
			cout<<"\n                             SHOW FIXED DEPOSIT(S)";
			cout<<"\n                             ---------------------"<<endl;
			cout<<"This feature is not supported in this version.\nPlease Update for Availing This Feature."<<endl;
			cout<<"Sorry for Inconvinence"<<endl;
			//f.FDData();
			break;


	    case 8:
			top1();
			cout<<"\n\n\tThanks for using City Co-Op. Bank";
			break;

	    default :
		       cout<<"\a";
  }
  getch();

	  }while(ch!=8);
 }


  getch();
 }while(utype!=3);
}


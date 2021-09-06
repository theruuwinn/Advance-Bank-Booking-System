#include"final.h"

using namespace std;

int readFile();

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

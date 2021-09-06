#ifndef BANK_H
#define BANK_H


class Bank
{
  protected:
  int accno;
  char nm[80];
  int bal;
  char type;
  //int cnt;
 public:

  void createacc(int);  //function to create an account
  void disp();   //function to show acc info
  void modify();        //function to modify acc info
  void depo(int);       //function to deposit amount to account
  void widr(int);      //function to widraw amount
  void rep();       //function to show data format
  int retacno();       //function to return account number
  int retbal();    //function to return balance amount
  char rettype();      //function to return type of account
  void setName(char []);
};

#endif // BANK_H

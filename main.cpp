#include <iostream>
#define MAX_ACCOUNT 10
using namespace std;
class Account
{
public:
    int acc_no;
    string acc_name;
    string acc_password;
    double amount;
};

int showMainMenu()
{
    int result = 0;
    while (result <=0 || result > 4) {
        cout<<"*********MENU*********"<<endl;
        cout<<"**1.Deposit***********"<<endl;
        cout<<"**2.Withdraw**********"<<endl;
        cout<<"**3.getAmount*********"<<endl;
        cout<<"*4.Creaate New Account"<<endl;
        cout<<"*5.EXIT***************"<<endl;
        cin>>result;
    }
    return result;
}

void deposit(Account *  account,int acc_no,double amt)
{
    int isFound=0;
    for (int i=0; i<MAX_ACCOUNT; i++) {
        if(account[i].acc_no==acc_no){
            isFound = 1;
            account[i].amount += amt;
            cout<<"\nTRANSACTION COMPLETE\n"<<account[i].acc_name<<" BALANCE = "<<account[i].amount<<endl;
            break;
        }
    }
    if (isFound==0) {
        cout<<"\nAccount NOT FOUND!!!!"<<endl;
    }
}

void withdraw(Account * account,int acc_no,string password,double amt)
{
    int isFound = 0;
    for (int i=0; i<MAX_ACCOUNT; i++) {
        if (account[i].acc_no == acc_no) {
            isFound = 1;
            if(account[i].acc_password == password)
            {
                if (account[i].amount-amt<0) {
                    cout<<"Balance is not enough to withdraw"<<endl;
                    break;
                }
                account[i].amount-=amt;
                cout<<"\nTransaction Complete\n"<<account[i].acc_name<<" BALANCE = "<<account[i].amount<<endl;
            }
            else
            {
                cout<<"PASSWORD INCORRECT"<<endl;
            }
            break;
        }
        
    }
    if (isFound==0) {
        cout<<"\nAccount NOT FOUND!!!!"<<endl;
    }
    
}

void getAMT(Account * account,int acc_no,string password)
{
    int isFound = 0;
    for (int i=0; i<MAX_ACCOUNT; i++) {
        if (account[i].acc_no == acc_no) {
            isFound = 1;
            if(account[i].acc_password == password)
            {
                cout<<"\nTransaction Complete\n"<<"BALNACE IS "<<account[i].amount<<endl;
            }
            else
            {
                cout<<"PASSWORD INCORRECT"<<endl;
            }
            break;
        }
        
    }
    if (isFound==0) {
        cout<<"\nAccount NOT FOUND!!!!"<<endl;
    }
}
void createNewAccount(string name,string password)
{
    Account a;
    a.acc_name = name;
    a.acc_password = password;
    a.amount = 0;
}
int main(int argc, const char * argv[]) {
    Account account[MAX_ACCOUNT];
    account[0].acc_no  = 1;
    account[0].acc_name = "somsak";
    account[0].acc_password = "1234";
    account[0].amount  = 1000000;
    account[1].acc_no  = 2;
    account[1].acc_name = "james";
    account[1].acc_password = "1234" ;
    account[1].amount  = 2000000;
    account[2].acc_no  = 3;
    account[2].acc_name = "tanaka";
    account[2].acc_password = "1234";
    account[2].amount  = 500000;
    int result = showMainMenu();
    int acc_no;
    string acc_password;
    string acc_password2;
    double amt;
    string acc_name;
    int i=2;
    while(result != 5)
    {
        if(result == 1)
        {
            printf("PLEASE INPUT YOUR ACC NO. : ");
            cin>>acc_no;
            printf("PLEASE INPUT HOW many MONEY do you want to deposit : ");
            cin>>amt;
            deposit( account, acc_no, amt);
        }
        else if(result == 2)
        {
            printf("PLEASE INPUT YOUR ACC NO. : ");
            cin>>acc_no;
            printf("PLEASE INPUT HOW many MONEY do you want to deposit : ");
            cin>>amt;
            printf("PLEASE INPUT YOUR PASSWORD : ");
            cin>>acc_password;
            withdraw( account, acc_no,acc_password, amt);
        }
        else if(result == 3)
        {
            printf("PLEASE INPUT YOUR ACC NO. : ");
            cin>>acc_no;
            printf("PLEASE INPUT YOUR PASSWORD : ");
            cin>>acc_password;
            getAMT( account, acc_no,acc_password);
        }
        else if (result==4)
        {
            cout<<"PLEASE INPUT YOUR NAME : ";
            cin>>acc_name;
            cout<<"\nPLEASE INPUT YOUR PASSWORD : ";
            cin>>acc_password;
            cout<<"\nPLEASE INPUT YOUR PASSWORD ONE MORE TIME : ";
            cin>>acc_password2;
            if (acc_password != acc_password2) {
                cout<<"PASSWORD DIFFERENT "<<endl;
                showMainMenu();
            }
            
        }
         result =showMainMenu();

    }

    return 0;
}

#include<iostream>
#include<string.h>
using namespace std;
struct transationrecord
{
    string details;
    string date;
};

class registerp
{
    public:
    string usernameA[20];
    string passwordA[20];
    int usercount = 0; 
    int i=0;
     void registeru()
   {       
       string name,email,username,password;
       cout<<"-------Welcome To Finacial Management System--------";
       cout<<"\n Enter the information "<<endl;
       cout<<"\n Enter name:";
       cin>>name;
       cout<<"\n Enter Email:"<<endl;
       cin>>email;
       cout<<"\n Enter Username:"<<endl;
       cin>>username;
       for ( i = 0; i < usercount; i++)
       {
        if(usernameA[i] == username)
        {
            cout<<"\n User is already exists...";
        }
       }
       cout<<"\n Enter Password:"<<endl;
       cin>>password;
       usernameA[usercount] = username;
       passwordA[usercount] = password;
       usercount++;
       cout<<"\n Registration successful...";
    }
};
class login: public registerp
{
    public:
    string login_key;
    bool login1()
    {
        string username,password;
        cout<<"\n Enter username:";
        cin>>username;
        cout<<"\n Enter Password:";
        cin>>password;
        for(i=0;i<usercount;i++)
        {
            if(usernameA[i] == username && passwordA[i] == password)
            {
               login_key = username;
               cout<<"\n Login Sucessful...";
               return true;
            }
        }
        cout<<"\n Invaild username or password... Register first...";
        return false;
        
    }
};
class transation : public login
{
    public:
    transationrecord transation[20][100];
    int transationcount[20] = {0};
    void Trecord()
    {
        if(login_key.empty())
        {
            cout<<"\n You Login first";
            return;
        }
        
       string date,amount,item,description;
       int userenter = -1;
       for(i=0;i<usercount;i++)
       {
        if(usernameA[i] == login_key)
        {
            userenter = i;
            break;
        }
       }
       if(userenter == -1)
       {
        cout<<"Error User not found.\n";
        return ;
       }
       cout<<"\n Enter Date(DD/MM/YYYY):"<<endl;
       cin>>date;
       cout<<"\n Enter Amount:"<<endl;
       cin>>amount;
       cout<<"\n Enter item:"<<endl;
       cin>>item;
       cout<<"\n Description:"<<endl;
       cin.ignore();
       getline(cin,description);
       transationrecord& record = transation[userenter][transationcount[userenter]];
       record.date = date;
       record.details = "\nDate:" + date + "\nAmount:" + amount + "\nltem:" + item + "\nDescription:" + description;
       transationcount[userenter]++;
       cout<<"Transation Saved Sucessfully!\n";
    }
};
class recipt:public transation
{
    public:
    string monthg,yearg;
    void generaterecipt()
    {
        if(login_key.empty())
        {
            cout<<"you must log in first";
            return;
        }
        int userenter = -1;
        for(i=0;i<usercount;i++)
        {
            if(usernameA[i]==login_key)
            {
                userenter = i;
                break;
            }
        }
        if(userenter == -1)
        {
         cout<<"Error:User not found...\n";
         return;
        }
        cout<<"\n Enter month(MM):";
        cin>>monthg;
        cout<<"\n Enter year(YYYY):";
        cin>>yearg;
        cout<<"Transation Receipt for "<<monthg<<"/"<<yearg<<"\n";
        cout<<"--------------------------------------------------\n";
        bool found = false;
        for(int i=0;i < transationcount[userenter];i++)
        {
            string date = transation[userenter][i].date;
            if(date.substr(3,2) == monthg && date.substr(6,4)==yearg)
            {
                cout<<transation[userenter][i].details<<"\n";
                found = true;
            }
        }
        if(!found)
        {
            cout<<"No transations found for given month and year.\n";
        }
        cout<<"\n------------------------------------------------------";
    }
};
int main()
{
    int choice;
    recipt p;
    while(true)
    {
      cout<<"\n 1.Register \n 2.Login \n 3. Add Transations \n 4. Generate Recepite \n 5.Exit";
      cout<<"\n Enter your Choice"<<endl;
      cin>>choice;
      switch(choice)
      {
        case 1:
        p.registeru();
        break;
        case 2:
        p.login1();
        break;
        case 3:
        p.Trecord();
        break;
        case 4:
        p.generaterecipt();
        break;
        case 5:
        return 0;
        break;
        default:
        cout<<"\n Invalid choice.Please try again...";
      }
    }
}
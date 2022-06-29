
#include <bits/stdc++.h>
using namespace std;

void login();
void registration();
void ForgotPassword();

int main(){
    // once_flag onceFlag;
    // call_once (onceFlag , []{system("cls");});
    int c ;
    cout<<"\t\t\t\t_____________________________________________\n\n";
    cout<<"\t\t\t\t          Welcome to the Login Page          \n\n";
    cout<<"\t\t\t\t_____________________MENU____________________\n\n\n";
    cout<<"\t | Press 1 to LOGIN               |\n";
    cout<<"\t | Press 2 to Register            |\n";
    cout<<"\t | Press 3 if you Forgot Password |\n";
    cout<<"\t | Press 4 to EXIT                |\n";

    cout<<"\n\t\t Enter your Choice  :- ";
    cin>>c;

    switch (c)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        ForgotPassword();
        break;
    case 4:
        cout<<"\n\t\t | THANK YOU!! | \n"<<endl;
        break;
    default:
        system("cls");
        //every time the code is procee the screen will be cleared 
        cout<<"\t\t\t Please Enter the Mentioned options !! "<<endl;
        main();
    }

}

void login(){
    system("cls");
    int count;
    string userid , password , id , pass;
    system("cls");
    cout<<"\t\t\t Please Enter the Username and Password \n"<<endl;
    cout<<"\t\t USERNAME :- ";
    cin>>userid;
    cout<<"\t\t PASSWORD :- ";
    cin>>password;

    ifstream input("records.txt");
    //to fetch the file records in the databsase 
    while(input>>id>>pass){
        // cout<<id<<endl;
        if(id == userid && pass == password){
            count = 1;
            cout<<"\t\t\t Registration Found \n";
            system("cls");
        }
    }
    input.close();
    if(count==1){
        cout<<userid<<"\n\t Your LOGIN is SUCCESSFUL \n\t Thanks for Logging In !! \n"<<endl;
        main();
    }
    else{
        cout<<"\n\t LOGIN ERROR!!!!!! \n\t Please Check your credentials or Register Again !!\n"<<endl;
        main();
    }

}

void registration(){
    string ruserid , rpassword;
    system("cls");
    cout<<"\t\t Enter the User Name :- ";
    cin>>ruserid;
    cout<<"\t\t Enter the Password  :- ";
    cin>>rpassword;
//This ios means input output stream and app refers to append the data
    ofstream file1("records.txt" , ios::app);

    file1<<ruserid<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\t The Registration is Successful"<<endl;
    main();
    
}

void ForgotPassword(){
    int option;
    system ("cls");
    cout<<"\t\t\t You forgot the password ?"<<endl;
    cout<<"\t\t\t Press 1 to search from id by user name"<<endl;
    cout<<"\t\t\t Press any other key to go back to the main menu"<<endl;
    cout<<"\t\t\t Enter Your choice "<<endl;
    cin>>option;
    switch (option)
    {
    case 1:{
        int count=0;
        string suserid , userid , spass;
        cout<<"\t\t\t enter your user name "<<endl;
        cin>>suserid;
        ifstream input("records.txt");
        while(input>>userid>>spass){
            if(suserid==userid){
                count=1;
            }
        }
        input.close();
        if(count==1){
            cout<<"\t\t\t Yes We Found your Account!! \n"<<endl;
            cout<<"\t\t\t Your Password id :- "<<spass;
            main();
        }

        else{
            cout<<"\t\t\t Sorry your account is not found  please check it again"<<endl;
            main();
        }
        break;
    }
    default:
        main();
        break;  
    }

}
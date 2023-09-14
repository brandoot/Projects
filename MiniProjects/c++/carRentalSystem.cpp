#include <iostream>
//using conio.h for
#include <conio.h>
//using stdlib.h for
#include <stdlib.h>

using namespace std;

struct cars{
    
string company[200]= {"Mazada", "Toyota", "Mitsubishi", "Ford", "Chevorlet", "Tesla", "Audi", "Hyundai", "Honda", "Nissan"};

string model[200]= {"AQW", "Camry", "Fridge", "Truck", "REST","Model 3","Vroom","x20","Civic","Altima"};

string color[200]= {"White","Space","Green","Red","Purple","Pink","Blue","Yellow","Black","Gray"};

string maxSpeed[200]= {"50mph", "90mph","40mph","67mph","90mph","110mph","30mph","70mph","80mph","60mph"};

int year[100]= {2000,2019,1996,2017,1965,2006,2022,2013,2005,2001};

int price[100]={10000,20000,30000,60000,70000,80000,30000,50000,20000,40000};

}car;

struct leasee_info{
    string name[100];
    string natl_ID[100];
    int paymentAcc[100];
}leasee;

//
void menu(){
    int num = 1;
    for(int i = 0; i<9; ++i){
        cout<<"\t\t\t";
        cout<<"Enter "<<num<<"\t- To Select "<<car.company[i]<<endl;
        num++;
    }
}

void details(int choice){
    system("CLS");
    cout<<"\n\n\n\t\t\t ------------------------\n";
    cout<<"\t\t\tYou Have Select - "<<car.company[choice-1]<<endl;
    cout<<"\t\t\t----------------------------\n\n\n";
    cout<<"\t\t\tModel : "<<car.model[choice-1]<<endl;
    cout<<"\t\t\tColor : "<<car.color[choice-1]<<endl;
    cout<<"\t\t\tMax Speed : "<<car.maxSpeed[choice-1]<<endl;
    cout<<"\t\t\tPrice : "<<car.price[choice-1]<<endl;
}

void checkLease(int k){
    if(leasee.paymentAcc[k]>=car.price[k])
        cout<<"\n\n\n\t\t\tProcess has been done sucessfully! "<<endl;
    else
        cout<<"\n\n\n\t\t\tNot Available "<<endl;
}

void userInput(int tChoice){
    system("CLS");
    int i;
    int j = tChoice-1;
    cout<<"\t\t\t--------------------------------------\n";
    cout<<"\t\t\tPlease Provide Your Personal Details :\n";
    cout<<"\t\t\t------------------------------------\n\n";
    cout<<"\n\tNOTE: PLEASE PROVIDE FIRST NAME ONLY, DO NOT ENTER SPACE \n\tPAYEMENT WON'T PROCEED IF GIVEN AMOUNT IS LESS THAN REQURIED\n";
    cout<<"\t\t\tEnter Your Name : ";
    cin>>leasee.name[100];
    cout<<"\t\t\tEnter Your National ID : ";
    cin>>leasee.natl_ID[j];
    cout<<"\t\t\tPayment Amount: ";
    cin>>leasee.paymentAcc[j];

    checkLease(j);
}

int login(){
    string pass = "";
    char ch;
    cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t Sunshine Car Rental System Login";
    cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t Enter Password: ";
    ch = _getch();
    while(ch != 13){//char 13 is enter pass
        pass.push_back(ch);
        cout<<'*';
        ch = _getch();
    }
    if(pass == "boots"){
        cout<<"\n\n\n\n\t\t\t\t\t Access Granted! Welcome To Our System \n\n";
        system("PAUSE");
        system("CLS");
    }
    else{
        cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t Access Aborted...Please Try Again!!\n";
        system("PAUSE");
        system("CLS");
        login();
    }
}

int main(){
    int login();
    login();

    string decide ="yes";
    cout<<"\t\t\t------------------------------------------\n";
    cout<<"\t\t\tSimple Car Rental System \n";
    cout<<"\t\t\tWlecome To Our Company, Choose from the Menu: \n";
    cout<<"\t\t\t------------------------------------------\n";
    while(decide!="exit"){
        menu();
        cout<<"\n\n\n\t\t\tYour Choice: ";
        int theChoice;
        cin>>theChoice;
        details(theChoice);
        cout<<"\n\n\n\t\t\tAre you sure you want to rent this car? (yes/no/exit) : ";
        cin>>decide;
        if(decide=="yes"){
            userInput(theChoice);
            cout<<"\n\n\t\t\tDo You want to continue? (yes/no) ";
            cin>>decide;
            if(decide=="no"){ 
            break;
            system("CLS");
            }
        }
        else{
            if(decide=="no"){
                system("CLS");
                continue;
            }
            else if(decide=="exit"){
                system("CLS");
                break;
            }
        }
    }
    getch();
    return 0;
}
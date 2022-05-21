#include<iostream>
#include <string>
#include<cmath>

using namespace std;

class Borrower{

    char name[100];
    double amount_borrowed;
    int time_period;
    int reason; //stores the reason for loan in an integer taken from a menu of numbered reasons for loan with different rates for each

    
   protected:
    double emi;
    public:
    
    Borrower(char* fname, double amount, int time, int reas){

        strcpy(name,fname);
        amount_borrowed=amount;
        time_period=time;
        reason=reas;

    }

    void calculate_emi();
    void showdetails();
};

//implementing inheritence


class Prepayment_Borrower:public Borrower{

     int time_remaining;
     double prepay_amount;
     double new_emi;

     public:
     Prepayment_Borrower(int timerem, double prepay, char* fname, double amount, int time, int reas ):Borrower(fname,amount,time,reas){
         
         time_remaining=timerem;
         prepay_amount=prepay;

     }

     void showdet();
     void calc_new_emi();
};

class Lender{

    char name[100];
    double amount_lent;
    int time_lent;
    double profits;
    float rate;


    public:

    Lender(char *fname, double amount, float r, int time){

        strcpy(name, fname);
        amount_lent=amount;
        rate=r;
        time_lent=time;
    }


    void calc_profits();
    void printdet();

};


void Borrower:: calculate_emi(){
    double p= amount_borrowed;
    float rates[]={3.5,6,7,9.5};
    float r=rates[reason-1]; //rates corresponding to the type of loan
    int t=time_period;
    r = r / (12 * 100); // one month interest

    emi=(p * r * pow(1 + r, t)) / (pow(1 + r, t) - 1);

}

void Borrower::showdetails(){
    
    cout<<"Name:"<<name<<endl;
    cout<<"Emi payable per month "<<emi<<endl;
}

void Prepayment_Borrower:: calc_new_emi(){
    calculate_emi();

    new_emi= ((emi*time_remaining)-prepay_amount)/time_remaining;    
}

void Prepayment_Borrower::showdet(){

    cout<<"Your new updated monthly emi is :"<<new_emi<<endl;

}


void Lender::calc_profits(){

    double p= amount_lent;
    float r=rate; //rates corresponding to the type of loan
    int t=time_lent;
    
    r = r / (12 * 100); // one month interest

    profits=((p * r * pow(1 + r, t)) / (pow(1 + r, t) - 1))*t - amount_lent;
}

void Lender::printdet(){
    cout<<"The profits earned by lending are:"<<profits<<endl;

}
int main(){


    cout<<"Are you a borrower or a lender?"<<endl;
    cout<<"Enter 1 for borrower and 2 for lender"<<endl;
    
    int a; //stores the response for wether borrower or lender
    cin>>a;

    if(a==1){

        cout<<"Enter 1 if you want a loan"<<endl;
        cout<<"Enter 2 if you want to make a prepayment of your current loan"<<endl;

        int b; //stores the value for the current menu

        cin>>b;

        char fname[100];
        double amount;
        int time;
        int reas;
            
        cout<<"Enter your name"<<endl;
        cin>>fname;


        if(b==1){
            
            cout<<"Enter Amount of loan required"<<endl;
            cin>>amount;

            cout<<"Enter time period in months"<<endl;
            cin>>time;

            cout<<"Enter integer corresponding to your purpose for taking loan"<<endl;
            cout<<"1. Student loan"<<endl<<"2. Car loan"<<endl<<"3. Home loan"<<endl<<"4. Personal loan"<<endl;
            cin>>reas;

            Borrower obj1(fname, amount, time, reas);

            obj1.calculate_emi();
            obj1.showdetails();

        }
        else{

            int timerem;
            double prepay;

            cout<<"Enter amount of loan initially taken"<<endl;
            cin>>amount;

            cout<<"Enter total time period in months"<<endl;
            cin>>time;

            cout<<"Enter integer corresponding to your purpose for taking loan"<<endl;
            cout<<"1. Student loan"<<endl<<"2. Car loan"<<endl<<"3. Home loan"<<endl<<"4. Personal loan"<<endl;
            cin>>reas;


            cout<<"Enter the time remaining in months"<<endl;
            cin>>timerem;

            cout<<"Enter amount being prepayed"<<endl;
            cin>>prepay;

            Prepayment_Borrower obj2(timerem, prepay, fname, amount, time, reas);
            obj2.calc_new_emi();
            obj2.showdet();

        }
        
    }
    else{

        char fname[100];
        double amount;
        int time;
        float r;

        cout<<"Enter your name"<<endl;
        cin>>fname;
        cout<<"Enter Amount lent"<<endl;
        cin>>amount;
        cout<<"Enter time period lent for in months"<<endl;
        cin>>time;
        cout<<"Enter rate lent at"<<endl;
        cin>>r;

        Lender obj3(fname, amount,r,time);

        obj3.calc_profits();
        obj3.printdet();

    }

return 0;

}
#include<iostream>
#include<string>
using namespace std;

int accountumber[5]={7544033,5122010,7413345,6341648,6577099};
string customerName[5]={"Jhon David","Tony Wilson","Collin Neeta","Martin Nicks","Simon Taylor"};
string NIC[5]={"863423220V","892114598V","591284927","614711043V","959254092V"};
string accountType[5]={"Adult Account","Child Account","Elder Account","Elder Account","Adult Account"};
double balance[5]={419000,155200,240000,673000,105000};
int option;

//======================================================================================================================================================================
void display_menu(){

cout<<" ========= Menu ========="<<endl;
cout<<endl;
cout<<" 1. Search Account Details" <<endl;
cout<<" 2. Deposit" <<endl;
cout<<" 3. Withdrawal"<<endl;
cout<<" 4. Transfer Fund" <<endl;
cout<<" 5. Interest" <<endl;
cout<<" 6. Exit "<<endl;
cout<<endl;
cout<<" Select an Operation :- ";
cin>>option;
cout<<endl;
}
//======================================================================================================================================================================

void search_account(){
int accNo;
bool found=false;

cout<<"Enter Account Number :- ";
cin>>accNo;
cout<<endl;

for(int i=0;i<5;i++){

    if(accountumber[i]==accNo){
        cout<<"Account Number :- "<<accountumber[i]<<endl;
        cout<<"Customer Name :- "<<customerName[i]<<endl;
        cout<<"NIC NO. OR Parent's NIC NO. "<<NIC[i]<<endl;
        cout<<"Account Type :- "<<accountType[i]<<endl;
        cout<<"Account Account Balance :- "<<balance[i]<<endl;
        found=true;
        break;
    }
}
if(!found){
    cout<<"Sorry we don't have any account for this account number";
    }
    cout<<endl;
}
//======================================================================================================================================================================

void diposit_amount (){
int accNo;
double depositeAmount;
bool found=false;

cout<<"Enter Account Number :- ";
cin>>accNo;
cout<<endl;
for(int i=0;i<5;i++){

    if(accountumber[i]==accNo){
        cout<<"Enter Depositing amount :- ";
        cin>>depositeAmount;
        cout<<endl;

       balance[i]=balance[i]+depositeAmount;
       cout<<"Your Current Balance :- "<<balance[i];

        found=true;
        break;
    }
}
    if(!found){
        cout<<"Sorry we don't have any account for this account number";
    }
    cout<<endl;
}
//======================================================================================================================================================================

void withdraw_amount (){
int accNo;
double withdrawAmount;
double currentAmount;
bool found=false;

cout<<"Enter Account Number :- ";
cin>>accNo;
cout<<endl;
for(int i=0;i<5;i++){

    if(accountumber[i]==accNo){
        cout<<"Enter withdraw amount :- ";
        cin>>withdrawAmount;
        cout<<endl;

        currentAmount=balance[i]-withdrawAmount;

      if(currentAmount>5000){
            balance[i]=currentAmount;
       cout<<"Your Current Balance :- "<<balance[i];
      }
      else{
        cout<<"The balance is not sufficient to withdraw";
      }

        found=true;
        break;
    }
}
    if(!found){
        cout<<"Sorry we don't have any account for this account number";
    }
    cout<<endl;
}
//======================================================================================================================================================================

void transfer_amount (){
int accNo;
int rec_accNo;
double sendAmount;
bool found=false;

cout<<"Enter Account Number :- ";
cin>>accNo;
cout<<endl;
for(int i=0;i<5;i++){
    if(accountumber[i]==accNo){
//-----------------------------------------------------------------------------------------------------------------------------------------------
        cout<<"Enter Receiver's Account Number :- ";
        cin>>rec_accNo;

            for(int j=0;j<5;j++){
                if(accountumber[j]==rec_accNo){

                cout<<"Enter Transferring Amount ";
                cin>>sendAmount;

                if((balance[i]-sendAmount)>=5000){

                    if(sendAmount>0 && sendAmount<=100000){
                        balance[i]=balance[i]-sendAmount;
                    }
                    else if(sendAmount>100000 && sendAmount<=200000){
                        balance[i]=balance[i]-(sendAmount+(sendAmount*0.25/100));
                    }
                    else if(sendAmount>200000 && sendAmount<=300000){
                        balance[i]=balance[i]-(sendAmount+(sendAmount*0.5/100));
                    }
                    else {
                        balance[i]=balance[i]-(sendAmount+(sendAmount*0.75/100));
                    }

                    balance[j]=balance[j]+sendAmount;


                    found=true;
                    break;
                }
                else {
                    cout<<"Insufficient Balance ";
                }
    }
}
    if(!found){
        cout<<"Sorry we don't have any account for this receiver's account number";
    }


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        found=true;
        break;
    }
}
    if(!found){
        cout<<"Sorry we don't have any account for this account number";
    }
    cout<<endl;



}
//======================================================================================================================================================================



void intrest_amount(){
int accNo;
double intrest;
bool found=false;

cout<<"Enter Account Number :- ";
cin>>accNo;
cout<<endl;

for(int i=0;i<5;i++){

    if(accountumber[i]==accNo){
      if(accountType[i]=="Child Account"){
        intrest=(balance[i]*5/100)/100;
        balance[i]=balance[i]+intrest;
      }
      else if(accountType[i]=="Adult Account"){
        intrest=(balance[i]*8/100)/100;
        balance[i]=balance[i]+intrest;

      }
      else{
        intrest=(balance[i]*12/100)/100;
        balance[i]=balance[i]+intrest;

      }

      cout<<"Interest : "<<intrest<<endl;
    cout<<"Your current balance : "<<balance[i];

        found=true;
        break;
    }
}
if(!found){
    cout<<"Sorry we don't have any account for this account number";
    }


    cout<<endl;
}
//======================================================================================================================================================================



int main(){

while (true){
display_menu();
    switch(option){
        case 1:search_account();
            break;
        case 2:diposit_amount();
            break;
        case 3:withdraw_amount ();
            break;
        case 4:transfer_amount();
            break;
        case 5:intrest_amount();
            break;
        case 6:
            cout<<"Successfully exited ";
            return 0;
        default:
            cout<<"Error , Your selection is wrong "<<endl;

    }
}
//search_account();
//diposit_amount(
//withdraw_amount ();
//transfer_amount();
//intrest_amount();

return 0;
}

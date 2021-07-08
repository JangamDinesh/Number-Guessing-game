#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void rules()
{
    system("cls");
    cout<<"\n==================GAME RULES=======================\n";
    cout<<"1. Choose a number from 1 to 10 \n";
    cout<<"2. Winner gets 10 times of amount he/she bets \n";
    cout<<"3. If you lose, then you will lose the money you bet \n";
}



int main()
{
    string name;
    int balance, bet, guess, value;
    char x;

    srand(time(0));

    cout<<"\n===============WELCOME TO THE GAME==================\n";
    cout<<"Enter you name: \n";
    getline(cin, name);
    cout<<"Enter the total balance: \n";
    cin >>balance;

    do
    {
        rules();
        cout<<"\nHello "<<name<<endl;
        cout<<"Your current balance is: "<<balance<<endl;

        do
        {
            cout<<"\nHow much money you want to bet: ";
            cin>>bet;

            if(bet>balance)
            {
                cout<<"\nBet can't be more than balance!!\n";
                cout<<"re-enter amount for bet: \n";
            }
            else if(bet == 0)
            {
                cout<<"\nBet can't zero!!\n";
                cout<<"re-enter amount for bet\n";
            }
        }
        while(bet>balance || bet == 0);

        do
        {
            cout<<"Guess any number between 1 and 10: \n";
            cin>>guess;
            if(guess<1 || guess>10)
            cout<<"Enter the guess in valid range\n";
        }
        while(guess<1 || guess>10);

        value = rand()%10+1;

        if(guess == value)
        {
            cout<<"Congratulations!!! You have won Rs."<<bet*10;
            balance = balance + bet*10;
        }
        else
        {
            cout<<"\nYou have lost!!! Better luck next time!!!\n";
            balance = balance - bet;
        }

        cout<<"\nThe actual number is: "<<value<<endl;
        cout<<"Remaining balance: "<<balance<<endl;

        if(balance == 0)
        {
            cout<<"Oh noo.. You have no money to play\n";
            break;
        }

        cout<<"Do you want to play again(Enter y if you want to play again): \n";
        cin >>x;
    }
    while( x=='y'||x=='Y');

    cout<<endl<<endl;
    cout<<"Thanks for playing!!\nYour current balance is: "<<balance<<endl;

    return 0;
}

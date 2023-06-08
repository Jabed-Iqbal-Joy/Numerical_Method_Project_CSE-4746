#include<bits/stdc++.h>
#include <iomanip>
#include "includes/numerical_fun.cpp"
using namespace std;

int main()
{
//    Intro
    welcome();
    char ch;


    //menu
    int choice;
    while (true)
    {
        introduction();
        menu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            cout << "\tYou selected the Bisection Method.\n" << endl;
            cout<<"f(x)= sin(x)+x^3-2x\n\n";
            bisectionMethod();
            cout<<"Enter a dummy char to go Menu Page ";
            cin>>ch;
            system("cls");
            break;
        case 2:
            system("cls");
            cout << "\tYou selected the Newton-Raphson Method.\n" << endl;
            cout<<"f(x)= sin(x)+x^3-2x\n\n";
            newtonRaphsonMethod();
            cout<<"Enter a dummy char to go Menu Page ";
            cin>>ch;
            system("cls");
            break;
        case 3:
            system("cls");
            cout << "You selected the Secant Method." << endl;
            cout<<"f(x)= sin(x)+x^3-2x\n\n";
            secantMethod();
            cout<<"Enter a dummy char to go Menu Page ";
            cin>>ch;
            system("cls");
            break;
        case 4:
            system("cls");
            cout << "You selected the Fixed-Point Iteration Method." << endl;
            cout<<"f(x)= sin(x)+x^3-2x\n\n";
            fixedPointIterationMethod();
            cout<<"Enter a dummy char to go Menu Page ";
            cin>>ch;
            system("cls");
            break;
        case 5:
            system("cls");
            cout << "You selected the False-Position Iteration Method." << endl;
            cout<<"f(x)= sin(x)+x^3-2x\n\n";
            false_positionMethod();
            cout<<"Enter a dummy char to go Menu Page ";
            cin>>ch;
            system("cls");
            break;
        case 6:
            system("cls");
            result_analysis();
            cout<<"Enter a dummy char to go Menu Page ";
            cin>>ch;
            system("cls");
            break;
        case 7:
            cout << "Exiting the program. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

}

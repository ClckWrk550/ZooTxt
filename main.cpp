#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include "zoo.h"


void displayMenu(int bal) {
cout << "Balance: $" << bal
     << "\nBuy Exhibit (a)"
     << "\nBuy Animal (b)"
     << "\nNext Day (c)"
     << "\nEnd Game (d)"
     << "\nSelect An Option: ";
}


int main() {
    string zooName;
    int balance = 1000;
    char menuOp, exhibitOp;
    
    cout << "\nï ■■■■■ Welcome to Zoo.txt! ■■■■■ ï" << endl;
    cout << "\nPlease Enter the Name of Your Zoo: ";
    getline(cin, zooName);

    cout << "\nGenerating"; // Generating animation, 3 ticks
    for (int i=0; i<3; i++){
        for (int j =0; j<3; j++){
            cout << ".";
            cout.flush();
            Sleep(300);
        }
        cout << "\b\b\b   \b\b\b";
    }

    printf("\33[2K\r"); // Erase animation
    
    
    Zoo zoo1;
    zoo1.createPlot();

    while (menuOp != 'd') {

        zoo1.printTitle(zooName);
        zoo1.printPlot();
        displayMenu(balance);
        cin >> menuOp;

        switch(menuOp) {
            case 'a': // Buy Exhibit
                cout << "\nAre you sure you would like to buy a new exhibit for $500? (y/n) ";
                cin >> exhibitOp;

                if (exhibitOp == 'y'){

                    if(balance >= 500){    
                        balance = balance - 500;
                        zoo1.addExhibit();
                        cout << "\n\x1B[32mExhibit Purchased!\033[0m";
                    }
                    
                    else{
                        cout << "\n\x1B[31mInsufficient Balance!\033[0m";
                    }
                }
                
                else if (exhibitOp == 'n'){
                    continue;
                }
                
                else{
                    cout << "\n\x1B[31mInvalid Option!\033[0m";
                }
            break;
            case 'b': // Buy Animal
            break;
            case 'c': // Next Day
                zoo1.elapsedDays++;
                cout << "\n\x1B[33mDay: " << (zoo1.elapsedDays + 1) << "\033[0m";
            break;
            default:
            cout << "\n\x1B[31mInvalid Option!\033[0m";
            break;
        };
    }
    
    cout << "\nCya Later! :3";
    return 0;
}

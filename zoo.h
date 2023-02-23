#include <iostream>
#include <vector>
using namespace std;

#define LEN(arr) ((int) (sizeof (arr) / sizeof (arr)[0]))

class Zoo {
    public:
        int elapsedDays = 0;
        struct Exhibit {
            int ID, animalCount;
        };

        void createPlot() { // Fills plot of land with '*'
            for (int i=0; i<plotRows; i++){
                for (int j=0; j<plotColumns; j++){
                    plotArr[i][j] = '*';
                }
            }
        }

        void printTitle(string title) { // Prints Zoo Header
            cout << "\n\n╔═ " << "\x1B[36m" << title << "\033[0m" << " ";
            titleLength = (2*plotRows - 4) - title.size(); // 2x rows to account for spaces
            for (int i = 0; i<titleLength; i++)
                cout << "═";
        
            cout << "╗";
        }

        void printPlot() { // Prints plot of land + Zoo Footer
            for (int i=0; i<plotRows; i++){
                cout << endl;
                for (int j=0; j<plotColumns; j++){
                    cout << " " << plotArr[i][j];
                }
            }

            cout << "\n╚═════════════════════════════════════════╝" << endl;
        }

        void printExVec() {
            cout << exVec.size();
        }

        void addExhibit() { // Adds 7x7 Exhibit to Plot (TODO: Make Dynamic)
            switch(exVec.size()){
                case 0:
                    Exhibit ex1; // Create new struct
                    ex1.ID = 1;
                    ex1.animalCount = 0;
                    exhibitArr[0][3] = '1'; // Label the visual
                    exVec.push_back(ex1);

                    for (int i=0; i<7; i++){ // Display
                        for (int j=0; j<7; j++){
                            plotArr[i][j] = exhibitArr[i][j];
                        }
                    }
                break;
                case 1:
                    Exhibit ex2;
                    ex2.ID = 2;
                    ex2.animalCount = 0;
                    exhibitArr[0][3] = '2';
                    exVec.push_back(ex2);

                    for (int i=0; i<7; i++){
                        for (int j=0; j<7; j++){
                            plotArr[i][j+7] = exhibitArr[i][j];
                        }
                    }
                break;
                case 2:
                    Exhibit ex3;
                    ex3.ID = 3;
                    ex3.animalCount = 0;
                    exhibitArr[0][3] = '3';
                    exVec.push_back(ex3);

                    for (int i=0; i<7; i++){
                        for (int j=0; j<7; j++){
                            plotArr[i][j+14] = exhibitArr[i][j];
                        }
                    }
                break;

                default:
                    cout << "Invalid, Try again!" << endl;
                break;
            };
        }

    private:
        int titleLength;
        vector<Exhibit> exVec;
        char plotArr[21][21];
        int plotRows = LEN(plotArr);
        int plotColumns = LEN(plotArr[0]);
        char exhibitArr[7][7] = {
        {'~','~','~','~','~','~','~'},
        {'|','*','*','*','*','*','|'},
        {'|','*','*','*','*','*','|'},
        {'|','*','*','*','*','*','|'},
        {'|','*','*','*','*','*','|'},
        {'|','*','*','*','*','*','|'},
        {'~','~','~','~','~','~','~'}};
        
};

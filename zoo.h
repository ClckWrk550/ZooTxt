#include "iostream"
using namespace std;

#define LEN(arr) ((int) (sizeof (arr) / sizeof (arr)[0]))

class Zoo {
    public:
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

        void addExhibit() { // Adds 7x7 Exhibit to Plot (TODO: Make Dynamic)
            switch(exhibitNum){
                case 0:
                    exhibitArr[0][3] = '1';

                    for (int i=0; i<7; i++){
                        for (int j=0; j<7; j++){
                            plotArr[i][j] = exhibitArr[i][j];
                        }
                    }
                    exhibitNum++;
                break;
                case 1:
                    exhibitArr[0][3] = '2';

                    for (int i=0; i<7; i++){
                        for (int j=0; j<7; j++){
                            plotArr[i][j+7] = exhibitArr[i][j];
                        }
                    }
                    exhibitNum++;
                break;
                case 2:
                    exhibitArr[0][3] = '3';

                    for (int i=0; i<7; i++){
                        for (int j=0; j<7; j++){
                            plotArr[i][j+14] = exhibitArr[i][j];
                        }
                    }
                    exhibitNum++;
                break;

                default:
                    cout << "Invalid, Try again!" << endl;
                break;
            };
        }

    private:
        int titleLength;
        int exhibitNum = 0;
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
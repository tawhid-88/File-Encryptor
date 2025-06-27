#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {
    fstream infile;
    infile.open("tawhid.txt");
    if (infile.is_open()) {
        string currentline;
        cout<< "Reading from file:" << endl;
        while (getline(infile, currentline)) {
            cout << currentline << endl;
        }
        cout << "End of file reached." << endl;
        infile.close();
    } else {
        cout << "Failed to open file." << endl;
    }
    cout << "\n\nProgram completed successfully." << endl;
    cout << "Exiting program." << endl;
    cout << "Goodbye!" << endl;
    cout << "Thank you for using this program." << endl;
    cout << "Have a great day!" << endl;
    cout << "See you next time!" << endl;
    cout << "Take care!" << endl;
    return 0;
}
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(){
    fstream outfile;
    outfile.open("tawhid.txt");
    if (outfile.is_open()) {
        cout << "Writing to file:" << endl;
        outfile << "This lines added from C++ code." << endl;
        cout << "Data written successfully." << endl;
        outfile.close();
        cout << "Successfully written to file." << endl;
    } else {
        cout << "Failed to open file for writing." << endl;
    }
    return 0;
}
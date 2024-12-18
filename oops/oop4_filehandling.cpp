#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename = "example.txt";
    string data;

    // Create and write to the file
    ofstream outFile(filename);  // Open the file for writing
    if (outFile.is_open()) {
        outFile << "Hello, this is a test file!" << endl;
        outFile << "File handling in C++ is simple." << endl;
        cout << "Data written to the file successfully." << endl;
        outFile.close();  // Close the file
    } else {
        cout << "Error opening file for writing!" << endl;
        return 1;
    }

    // Open the file again for reading
    ifstream inFile(filename);  // Open the file for reading
    if (inFile.is_open()) {
        cout << "\nReading data from the file:\n";
        while (getline(inFile, data)) {  // Read line by line
            cout << data << endl;
        }
        inFile.close();  // Close the file
    } else {
        cout << "Error opening file for reading!" << endl;
        return 1;
    }

    return 0;
}

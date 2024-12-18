#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define a structure for Personal Record
struct PersonalRecord {
    string name;
    string dob;  // Date of Birth
    string phone;

    // Overload the < operator for sorting by name
    bool operator<(const PersonalRecord &other) const {
        return name < other.name;
    }
};

// Function to display all records
void displayRecords(const vector<PersonalRecord> &records) {
    for (const auto &record : records) {
        cout << "Name: " << record.name 
             << ", DOB: " << record.dob 
             << ", Phone: " << record.phone << endl;
    }
}

// Main function
int main() {
    vector<PersonalRecord> records;

    // Input some records
    records.push_back({"Alice", "2000-01-01", "1234567890"});
    records.push_back({"Bob", "1995-05-15", "9876543210"});
    records.push_back({"Charlie", "1998-12-20", "1122334455"});

    // Sort records by name
    sort(records.begin(), records.end());

    cout << "Sorted Records:\n";
    displayRecords(records);

    // Search for a record by name
    string searchName = "Bob";
    auto it = find_if(records.begin(), records.end(), [&searchName](const PersonalRecord &record) {
        return record.name == searchName;
    });

    if (it != records.end()) {
        cout << "\nRecord found:\n";
        cout << "Name: " << it->name 
             << ", DOB: " << it->dob 
             << ", Phone: " << it->phone << endl;
    } else {
        cout << "\nRecord not found!" << endl;
    }

    return 0;
}

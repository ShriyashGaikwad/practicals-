#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// Forward declaration of FriendClass
class FriendClass;

class Student {
private:
    string name;
    int rollNumber;
    string studentClass;
    string division;
    string dob;          // Date of Birth
    string bloodGroup;
    string contactAddress;
    string phoneNumber;
    string drivingLicenseNo;

public:
    // Default Constructor
    Student() {
        name = "Unknown";
        rollNumber = 0;
        studentClass = "Unknown";
        division = "Unknown";
        dob = "Unknown";
        bloodGroup = "Unknown";
        contactAddress = "Unknown";
        phoneNumber = "Unknown";
        drivingLicenseNo = "Unknown";
        cout << "Default Constructor called\n";
    }

    // Parameterized Constructor
    Student(string n, int r, string sClass, string div, string dob,
            string blood, string address, string phone, string license) {
        name = n;
        rollNumber = r;
        studentClass = sClass;
        division = div;
        this->dob = dob;
        bloodGroup = blood;
        contactAddress = address;
        phoneNumber = phone;
        drivingLicenseNo = license;
        cout << "Parameterized Constructor called\n";
    }

    // Inline function to set student data
    void getdata(string n, int rollnumber) {
        name = n;
        rollNumber = rollnumber;
        try {
            if (rollnumber < 0) {
                throw rollnumber;
            }
        } catch (int r) {
            cout << "Invalid roll number: " << r << endl;
        }
    }

    // // Destructor
    // ~Student() {
    //     cout << "Destructor called\n";
    // }

    // Static member function
    static void displayMessage() {
        cout << "Welcome to the Student Information System!" << endl;
    }

    // Friend class declaration
    friend class FriendClass;
};

// FriendClass can access private members of Student
class FriendClass {
public:
    // void displayPrivateInfo(Student &s) 
    void displayPrivateInfo(Student s) {
        cout << "FriendClass accessing private data of Student:\n";
        cout << "Name: " << s.name << endl;
        cout << "Roll Number: " << s.rollNumber << endl;
        cout << "Class: " << s.studentClass << endl;
        cout << "Division: " << s.division << endl;
        cout << "DOB: " << s.dob << endl;
        cout << "Blood Group: " << s.bloodGroup << endl;
        cout << "Contact Address: " << s.contactAddress << endl;
        cout << "Phone Number: " << s.phoneNumber << endl;
        cout << "Driving License No: " << s.drivingLicenseNo << endl;
    }

    //void display(Student s2)
    void display(Student s2) {
        cout << "Inline function called\n";
        cout << "Name: " << s2.name << endl;
        cout << "Roll Number: " << s2.rollNumber << endl;
    }
};

int main() {
    // Static function call
    Student::displayMessage();

    // Dynamically allocate memory for a Student object using 'new'
    // Student *student1 = new Student("Alice", 101, "CS", "A", "12-12-2000", "B+", "123 Main St.", "1234567890", "DL5678");

    Student student1("Alice", 101, "CS", "A", "12-12-2000", "B+", "123 Main St.", "1234567890", "DL5678");

    //  Dynamically allocated Student object
    // Student *student = new Student();
    // student->getdata("Payal", 12);

    Student student;
    student.getdata("Payal", 12);

    // Create FriendClass object
    FriendClass friendObj;

    // FriendClass accesses private members of Student
    // friendObj.displayPrivateInfo(*student1);
    // friendObj.display(*student);

    friendObj.displayPrivateInfo(student1);
    friendObj.display(student);

    //Free dynamically allocated memory
    //delete student1;
    //delete student;

    return 0;
}

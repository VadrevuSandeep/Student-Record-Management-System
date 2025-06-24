#include <iostream>
#include <vector>
#include <limits> // For input buffer handling

using namespace std;

struct Student {
    int rollNo;
    string name;
    float cgpa;
    string course;
};

vector<Student> students;

void addStudent() {
    Student newStudent;

    cout << "\nEnter Roll No: ";
    cin >> newStudent.rollNo;

    // Check for duplicate roll number
    for (int i = 0; i < students.size(); i++) {
        if (students[i].rollNo == newStudent.rollNo) {
            cout << "Error: Roll number already exists!\n";
            return;
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    cout << "Enter Name: ";
    getline(cin, newStudent.name);

    cout << "Enter CGPA: ";
    cin >> newStudent.cgpa;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Course: ";
    getline(cin, newStudent.course);

    students.push_back(newStudent);
    cout << "Student added successfully!\n";
}

void displayAll() {
    if (students.empty()) {
        cout << "\nNo records found!\n";
        return;
    }

    cout << "\n==== Student Records ====\n";
    for (int i = 0; i < students.size(); i++) {
        cout << "Roll No: " << students[i].rollNo << endl;
        cout << "Name   : " << students[i].name << endl;
        cout << "CGPA   : " << students[i].cgpa << endl;
        cout << "Course : " << students[i].course << endl << endl;
    }
}

void searchStudent() {
    int roll;
    cout << "Enter Roll No to search: ";
    cin >> roll;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].rollNo == roll) {
            cout << "\nStudent Found:\n";
            cout << "Name   : " << students[i].name << endl;
            cout << "CGPA   : " << students[i].cgpa << endl;
            cout << "Course : " << students[i].course << endl;
            return;
        }
    }
    cout << "Student not found!\n";
}

void deleteStudent() {
    int roll;
    cout << "Enter Roll No to delete: ";
    cin >> roll;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].rollNo == roll) {
            students.erase(students.begin() + i);
            cout << "Student deleted successfully!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

void updateStudent() {
    int roll;
    cout << "Enter Roll No to update: ";
    cin >> roll;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].rollNo == roll) {
            cout << "Enter new CGPA (current: " << students[i].cgpa << "): ";
            cin >> students[i].cgpa;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter new Course (current: " << students[i].course << "): ";
            getline(cin, students[i].course);

            cout << "Record updated!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

int main() {
    int choice;

    do {
    	cout << "\n*************************************************";
        cout << "\n             Student Record Management  	        ";
		cout << "\n*************************************************\n";  
        cout << "\n";
        cout <<"1. Add Student\n";
        cout <<"2. Display All Students\n";
        cout <<"3. Search Student\n";
        cout <<"4. Update Student\n";
        cout <<"5. Delete Student\n";
        cout <<"6. Exit\n";
        cout << "\n";
        cout <<"----> Enter your choice: ";

        cin >> choice;

        if (cin.fail()) {
            cin.clear(); // Clear error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard input
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}


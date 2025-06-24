🎓 Student Record Management System (C++)
This is a simple Student Record Management System developed using C++, designed to run in a terminal or command-line interface. It provides a user-friendly way to manage student data, such as roll number, name, CGPA, and enrolled course.

🔧 Features
✅ Add new student records with proper validation for duplicate roll numbers

📋 Display all student records in a clean, formatted manner

🔍 Search for a student by roll number

✏️ Update a student’s CGPA and course information

❌ Delete a student record based on roll number

🛑 Exit the application safely

💡 How It Works
The application stores all student records in a vector of structs, allowing efficient access, insertion, deletion, and searching operations.
Data Structure Used:
struct Student {
    int rollNo;
    string name;
    float cgpa;
    string course;
};
All operations are implemented using simple loops and conditionals for beginner-friendly understanding.

📌 Prerequisites
A C++ compiler like g++
Basic understanding of C++ syntax and standard library

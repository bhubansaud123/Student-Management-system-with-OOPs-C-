
#include <iostream>
#include <vector>
using namespace std;

// Student class (Encapsulation)
class Student {
private:
    int rollNo;
    string name;
    float marks;

public:
    // Constructor
    Student(int r, string n, float m) {
        rollNo = r;
        name = n;
        marks = m;
    }

    // Getter functions
    int getRollNo() {
        return rollNo;
    }

    // Display student details
    void display() {
        cout << "Roll No : " << rollNo << endl;
        cout << "Name    : " << name << endl;
        cout << "Marks   : " << marks << endl;
        cout << "------------------------" << endl;
    }
};

// StudentManager class
class StudentManager {
private:
    vector<Student> students;

public:
    void addStudent() {
        int roll;
        string name;
        float marks;

        cout << "Enter Roll No: ";
        cin >> roll;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Marks: ";
        cin >> marks;

        students.push_back(Student(roll, name, marks));
        cout << "Student Added Successfully!\n";
    }

    void displayAll() {
        if (students.empty()) {
            cout << "No student records available.\n";
            return;
        }

        for (auto &s : students) {
            s.display();
        }
    }

    void searchStudent() {
        int roll;
        cout << "Enter Roll No to Search: ";
        cin >> roll;

        for (auto &s : students) {
            if (s.getRollNo() == roll) {
                s.display();
                return;
            }
        }
        cout << "Student Not Found!\n";
    }
};

// Main function
int main() {
    StudentManager manager;
    int choice;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            manager.addStudent();
            break;
        case 2:
            manager.displayAll();
            break;
        case 3:
            manager.searchStudent();
            break;
        case 4:
            cout << "Exiting Program...\n";
            break;
        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}

#include <iostream>
#include <string>
using namespace std;
class Student {
protected:
    int rollNo;
    string name;
public:
    void getStudentDetails() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, name);
    }
};
class Exam : public Student {
protected:
    int marks[6];
public:
    void getMarks() {
        cout << "Enter marks in six subjects:\n";

        for (int i = 0; i < 6; i++) {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }
};
class Result : public Exam {
private:
    int totalMarks = 0;
    float percentage;
public:
    void calculateResult() {
        for (int i = 0; i < 6; i++) {
            totalMarks += marks[i];
        }
        percentage = totalMarks / 6.0;
    }
    void displayResult() {
        cout << "\n----- STUDENT RESULT -----\n";
        cout << "Roll Number: " << rollNo << endl;
        cout << "Student Name: " << name << endl;
        cout << "Marks in Six Subjects:\n";
        for (int i = 0; i < 6; i++) {
            cout << "Subject " << i + 1
                 << ": " << marks[i] << endl;
        }
        cout << "Total Marks: " << totalMarks
             << " / 600" << endl;
        cout << "Percentage: " << percentage
             << "%" << endl;
    }
};
int main() {
    Result r;
    r.getStudentDetails();
    r.getMarks();
    r.calculateResult();
    r.displayResult();
    return 0;
}
# Student_Manage
This is my first project on CPP concepts.
<br>
This project is basically used to manage all the details of various student such as there marks detail,grades and attendence.

#include <iostream>
#include <string>
#include <vector>
#include<conio>
#include<stdlib>
using namespace std;

// Define a Student class to store student details
class Student {
private:
    string name;
    int rollNumber;
    vector<int> marks;
    char grade;
    int attendance;

public:
    // Constructor to initialize student object
    Student(string name, int rollNumber) : name(name), rollNumber(rollNumber), grade('F'), attendance(0) {}

    // Function to add marks for a subject
    void addMarks(int mark) {
        marks.push_back(mark);
    }

    // Function to calculate grade based on marks
    void calculateGrade() {
        int totalMarks = 0;
        for (int mark : marks) {
            totalMarks += mark;
        }
        int averageMarks = totalMarks / marks.size();

        if (averageMarks >= 90) {
            grade = 'A';
        } else if (averageMarks >= 80) {
            grade = 'B';
        } else if (averageMarks >= 70) {
            grade = 'C';
        } else if (averageMarks >= 60) {
            grade = 'D';
        } else {
            grade = 'F';
        }
    }

    // Function to update attendance
    void updateAttendance(int daysPresent) {
        attendance += daysPresent;
    }

    // Function to display student details
    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Grade: " << grade << endl;
        cout << "Attendance: " << attendance << " days" << endl;
    }
};

int main() {
    string name;
    int roll;
    cout<<"                     **Student Details**                           "<<endl;
    //Taking input as Student details
    cout<<"Student Naame:"<<"\t";
    cin>>name;
    cout<<"Roll_Number:"<<"\t";
    cin>>roll;
    // Create a Student object
    Student student(name,roll);

    // Add marks for different subjects
    student.addMarks(85);
    student.addMarks(78);
    student.addMarks(92);

    // Calculate grade based on marks
    student.calculateGrade();

    // Update attendance
    student.updateAttendance(20);

    // Display student details
    student.displayDetails();

    return 0;
}

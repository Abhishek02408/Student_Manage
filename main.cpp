#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Enum for Attendance Status
enum class AttendanceStatus { Present, Absent, Late };

// Student class
class Student {
public:
    string id;
    string name;
    unordered_map<string, AttendanceStatus> attendance;
    unordered_map<string, double> grades;
    vector<string> behaviorIncidents;

    Student(const string& id, const string& name) : id(id), name(name) {}

    void addGrade(const string& course, double grade) {
        grades[course] = grade;
    }

    void addAttendance(const string& date, AttendanceStatus status) {
        attendance[date] = status;
    }

    void addBehaviorIncident(const string& incident) {
        behaviorIncidents.push_back(incident);
    }
};

// Attendance Module
class AttendanceModule {
public:
    void markAttendance(Student& student) {
        string date;
        int status;

        cout << "Enter date (YYYY-MM-DD): ";
        cin >> date;

        cout << "Enter status (0 for Present, 1 for Absent, 2 for Late): ";
        cin >> status;

        student.addAttendance(date, static_cast<AttendanceStatus>(status));
    }

    void viewAttendance(const Student& student) {
        for (const auto& [date, status] : student.attendance) {
            cout << "Date: " << date << " - Status: " 
                 << (status == AttendanceStatus::Present ? "Present" : status == AttendanceStatus::Absent ? "Absent" : "Late") 
                 << endl;
        }
    }
};

// Grades Module
class GradesModule {
public:
    void enterGrade(Student& student) {
        string course;
        double grade;

        cout << "Enter course name: ";
        cin >> course;

        cout << "Enter grade: ";
        cin >> grade;

        student.addGrade(course, grade);
    }

    void viewGrades(const Student& student) {
        for (const auto& [course, grade] : student.grades) {
            cout << "Course: " << course << " - Grade: " << grade << endl;
        }
    }
};

// Behavioral Module
class BehavioralModule {
public:
    void logIncident(Student& student) {
        string incident;

        cout << "Enter behavior incident description: ";
        cin.ignore();  // Ignore the newline character from previous input
        getline(cin, incident);

        student.addBehaviorIncident(incident);
    }

    void viewBehaviorReport(const Student& student) {
        cout << "Behavioral Incidents for " << student.name << ":" << endl;
        for (const auto& incident : student.behaviorIncidents) {
            cout << " - " << incident << endl;
        }
    }
};

int main() {
    // Create a sample student
    Student student("123", "John Doe");

    // Create module instances
    AttendanceModule attendanceModule;
    GradesModule gradesModule;
    BehavioralModule behavioralModule;

    int choice;

    do {
        cout << "\nSchool Management System\n";
        cout << "1. Mark Attendance\n";
        cout << "2. View Attendance\n";
        cout << "3. Enter Grade\n";
        cout << "4. View Grades\n";
        cout << "5. Log Behavior Incident\n";
        cout << "6. View Behavior Report\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                attendanceModule.markAttendance(student);
                break;
            case 2:
                attendanceModule.viewAttendance(student);
                break;
            case 3:
                gradesModule.enterGrade(student);
                break;
            case 4:
                gradesModule.viewGrades(student);
                break;
            case 5:
                behavioralModule.logIncident(student);
                break;
            case 6:
                behavioralModule.viewBehaviorReport(student);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

//variables
string names[100];
int studentCount = 0;
int grades[100][10];
int gradeCount[100];

//functions
void addStudent(string name);
void addGrade(int student, int grade);
bool canAddGrade(int student);
bool canAddStudent();
bool validGrade(int grade);



int main() {
    int choice;

    while (true) {
        cout << "\n1. Add student\n";
        cout << "2. Show all students\n";
        cout << "3. Show student grades\n";
        cout << "4. Update grade\n";
        cout << "5. Calculate average\n";
        cout << "6. Delete student\n";
        cout << "7. Exit\n";

        cout << "Choice: ";
        cin >> choice;

        if (choice == 7) {
            break;
        }

        // later: handle 1-6 here
    }

    return 0;
}

void addStudent(string name) {
    names[studentCount] = name;
    studentCount++;
}

void addGrade(int student, int grade) {
    grades[student][gradeCount[student]] = grade;
    gradeCount[student]++;
}

bool canAddGrade(int student) {
    return gradeCount[student] < 10;
}

bool canAddStudent() {
    return studentCount < 100;
}

bool validGrade(int grade) {
    if (grade > 0 && grade < 11) {
        return true;
    }
    return false;
}
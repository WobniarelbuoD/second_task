#include <iostream>
#include <string>
#include <limits>

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
bool validStudent(int student);
int getNumber();
void mainMenu(int choice);
void addGradeMenu();
void updateGrade(int index, int grade);
void showStudent(int index);
void showAllStudents();


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
        choice = getNumber();
        mainMenu(choice);

        if (choice == 7) {
            break;
        }
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
    if (grade > 0 && grade <= 10) {
        return true;
    }
    return false;
}

bool validStudent(int student) {
    if (student > 0 && student <= studentCount) {
        return true;
    }
    return false;
}

int getNumber() {
    int number;

    while (!(cin >> number)) {
        cout << "Please enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return number;
}

void showStudent(int index) {
    cout << index+1 << ". " << names[index]<< endl;
    cout << " Grades: ";

    if (gradeCount[index] == 0) {
        cout << "No grades";
    }
    else {
        for (int j = 0; j < gradeCount[index]; j++) {
            cout << grades[index][j] << " ";
        }
    }

    cout << endl;
}

void showAllStudents() {
    if (studentCount == 0) {
        cout << "No students.\n";
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        showStudent(i);
    }
}

void updateGrade(int index, int grade) {

}

void mainMenu(int choice) {

    switch (choice) {

        case 1: {
            if (canAddStudent()) {
                string student;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Student name: ";
                getline(cin, student);
                addStudent(student);
                addGradeMenu();
            }
            else {
                cout << "Maximum number of students reached.\n";
            }
            break;
        }

        case 2: {
            showAllStudents();
            break;
        }

        case 3: {
            if (studentCount == 0) {
                cout << "No students.\n";
                break;
            }
            int secondChoice;
            cout << "Input student number.\n";
            secondChoice = getNumber();
            if (validStudent(secondChoice)) {
                showStudent(secondChoice -1);
            }
            else {
                cout << "Invalid student number. Enter a number from 1 to "
                     << studentCount << ".\n";
            }
            break;
        }

        case 4: {
            // update grade
            break;
        }

        case 5: {
            // calculate average
            break;
        }

        case 6: {
            // delete student
            break;
        }

        case 7: {
            // exit
            break;
        }

        default:
            cout << "Invalid option.\n";
    }
}

void addGradeMenu() {
    while (true) {
        int choice;
        cout << "Give student grade?: \n";
        cout << "1. yes: \n";
        cout << "2. No: \n";
        cout << "Choice: ";
        choice = getNumber();

        switch (choice) {
            case 1: {
                if (canAddGrade(studentCount -1)) {
                    int grade;
                    while (true) {
                        cout << "input grade: ";
                        grade = getNumber();
                        if (validGrade(grade)) {
                            addGrade(studentCount -1, grade);
                            break;
                        }
                        cout << "Grade must be between 1 and 10.\n";
                    }
                }
                else {
                    cout << "The student already has 10 grades.\n";
                    return;
                }

                break;
            }

            case 2: {
                return;
            }

            default:
                cout << "Invalid option.\n";
        }
    }
}
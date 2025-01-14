#include <iostream>
#include <string>
using namespace std;

// Struct for student record
struct Srecord {
    double quiz1, quiz2;
    double midterm, finalExam;
    double averageScore;
    char finalGrade;
};

void fungrade(Srecord &sobject) {

    double quizAverage = ((sobject.quiz1 + sobject.quiz2) / 20.0) * 100;

    sobject.averageScore = (quizAverage * 0.25) + (sobject.midterm * 0.25) + (sobject.finalExam * 0.50);

    // Letter grade, final avg score
    if (sobject.averageScore >= 90) {
        sobject.finalGrade = 'A';
    } else if (sobject.averageScore >= 80) {
        sobject.finalGrade = 'B';
    } else if (sobject.averageScore >= 70) {
        sobject.finalGrade = 'C';
    } else if (sobject.averageScore >= 60) {
        sobject.finalGrade = 'D';
    } else {
        sobject.finalGrade = 'F';
    }
}

int main() {

    Srecord student1 = {8, 9, 85, 92};
    Srecord student2 = {7, 6, 75, 80};
    Srecord student3 = {9, 10, 90, 94};

    // Call fungrade
    fungrade(student1);
    fungrade(student2);
    fungrade(student3);

    // Print student records
    cout << "Student 1: Amari - Quiz 1: " << student1.quiz1 << ", Quiz 2: " << student1.quiz2
         << ", Midterm: " << student1.midterm << ", Final: " << student1.finalExam
         << ", Average: " << student1.averageScore << ", Final Grade: " << student1.finalGrade << endl;

    cout << "Student 2: Jackson - Quiz 1: " << student2.quiz1 << ", Quiz 2: " << student2.quiz2
         << ", Midterm: " << student2.midterm << ", Final: " << student2.finalExam
         << ", Average: " << student2.averageScore << ", Final Grade: " << student2.finalGrade << endl;

    cout << "Student 3: Kmontrey - Quiz 1: " << student3.quiz1 << ", Quiz 2: " << student3.quiz2
         << ", Midterm: " << student3.midterm << ", Final: " << student3.finalExam
         << ", Average: " << student3.averageScore << ", Final Grade: " << student3.finalGrade << endl;

    return 0;
}

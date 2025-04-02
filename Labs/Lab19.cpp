#include <iostream>
using namespace std;

struct Student {
    int id;
    string name;
    Student *next;
};

int main() {
    // 1. Creating three Student objects using new operator
    Student *student1 = new Student;
    Student *student2 = new Student;
    Student *student3 = new Student;

    // 2. Filling id and name information
    student1->id = 101;
    student1->name = "Lebron";

    student2->id = 102;
    student2->name = "Steph";

    student3->id = 103;
    student3->name = "Malcolm";

    // 3. Linking the objects using next pointer
    student1->next = student2;
    student2->next = student3;
    student3->next = NULL;

    // 4. Using while loop to print id and name
    Student *current = student1;
    while (current != NULL) {
        cout << "ID: " << current->id << ", Name: " << current->name << endl;
        current = current->next;
    }

    // Freeing allocated memory
    delete student1;
    delete student2;
    delete student3;

    return 0;
}

#include <iostream>
#include <string>

class student {
public:
    std::string name;
    int age;
    char sec;
    int marks;
    std::string college;

    void value_set(std::string s, int age1, char s1, int marks1, std::string c) {
        name = s;
        age = age1;
        sec = s1;
        marks = marks1;
        college = c;
    }
};

int main() {
    const int maxStudents = 100; // Maximum number of students (adjust as needed)
    student students[maxStudents];

    int studentCount = 0;

    // Add student records
    students[studentCount++].value_set("Student1", 20, 'A', 85, "XYZ College");
    students[studentCount++].value_set("Student2", 21, 'B', 80, "XYZ College");
    students[studentCount++].value_set("Student3", 19, 'C', 90, "XYZ College");
    students[studentCount++].value_set("Student4", 22, 'A', 85, "XYZ College");

    std::string targetCollege = "XYZ College"; // Specify the target college

    int totalMarks = 0;
    int studentsFromCollege = 0;

    for (int i = 0; i < studentCount; ++i) {
        if (students[i].college == targetCollege) {
            totalMarks += students[i].marks;
            studentsFromCollege++;
        }
    }

    double averageMarks = (studentsFromCollege > 0) ? (static_cast<double>(totalMarks) / studentsFromCollege) : 0.0;

    std::cout << "Average Marks of students from " <<averageMarks << std::endl;

    return 0;
    
}

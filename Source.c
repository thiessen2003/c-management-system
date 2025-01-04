#include <stdio.h>
#include <stdlib.h>

//defining student struct
typedef struct student {
    char name[20]; 
    unsigned int id; 
    unsigned int grade;

} Student;

//defining course struct 
typedef struct course { 
    char name[20];
    double averageGrade; 
    unsigned int totalStudents; 
    Student* studentArray; 
} Course;

//defining school struct
typedef struct school { 
    char name[20]; 
    unsigned int totalCourses; 
    Course* courseArray; 

} School; 

//creating a student 
Student* createStudent() {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    printf("Enter student name: "); 
    scanf("%s", newStudent->name); //array decays to pointer
    printf("Enter student ID: "); 
    scanf("%u", &(newStudent->id));
    printf("Enter student grade: "); 
    scanf("%u", &(newStudent->grade));

    return newStudent; 

};

//creating a course
Course* createCourse() {
    Course* newCourse = (Course*)malloc(sizeof(Course));
    printf("Enter student name: "); 
    scanf("%s", newCourse->name); //array decays to pointer
    printf("Enter number of students: "); 
    scanf("%u", &(newCourse->totalStudents));
    newCourse->studentArray = (Student*)malloc(sizeof(Student) * newCourse->totalStudents);

    for (int i = 0; i < newCourse->totalStudents; i++) { 
        printf("Enter details for student #%d\n", i + 1); 
        Student* newStudent = createStudent(); 
        newCourse->studentArray[i] = *newStudent;
        free(newStudent);
    }

    return newCourse;

};

//create a school
School* createSchool() {
    School* newSchool = (School*)malloc(sizeof(School));
    printf("Enter student name: "); 
    scanf("%s", newSchool->name); //array decays to pointer
    printf("Enter number of courses: "); 
    scanf("%u", &(newSchool->totalCourses));
    newSchool->courseArray = (Course*)malloc(sizeof(Course) * newSchool->totalCourses);

    for (int i = 0; i < newSchool->totalCourses; i++) { 
        printf("Enter details for course #%d\n", i + 1); 
        Course* newCourse = createCourse(); 
        newSchool->courseArray[i] = *newCourse;
        free(newCourse);
    }

    return newSchool;

};

void printStudentDetails(Student* student) { 
    prtinf("Student name: %s\n", student->name);
    prtinf("Student ID: %u\n", student->id);
    prtinf("Student grade: %u\n", student->grade);
}

void printCourseDetails(Course* course) { 
    prtinf("Course name: %s\n", course->name);
    prtinf("Course Average grade: %lf\n", course->averageGrade);
    printf("Course total students: %u\n", course->totalStudents);
    for (int i = 0; i < course->totalStudents; i++) {
        printf("Details for student #%d\n", i + 1);
        printStudentDetails(&(course->studentArray[i]));
        //print expects a pointer, not a student 
        //so it is not possible to use just (course->studentArray[i])
    }
}

void printStudentCourses(School* school, int studentID) {
    printf("Courses for student with ID %d:\n", studentID);
    for (int i = 0; i < school->totalCourses; i++) { 
        for (int j = 0; j < school->courseArray[i].totalStudents; j++) {
            if (school->courseArray[i].studentArray[j].id == studentID) {
                printf(" - %s\n", school->courseArray[i].name);
                break; //if found, no need to still keep track
            }
        }
    }
}

void printStudentsWhoFailed(Course* course, double cutOffGrade) { 
    printf("Students who failed in %s:\n", course->name);
    for (int i = 0; i < course->totalStudents; i++) {
        if (course -> studentArray[i].grade < cutOffGrade) {
            printStudentDetails(&(course->studentArray[i]));
        }
    }
}


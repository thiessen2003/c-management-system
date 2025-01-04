#include <stdio.h>
#include <stdlib.h>

//defining student struct
typedef struct student {
    char name[20]; 
    unsigned int id; 

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
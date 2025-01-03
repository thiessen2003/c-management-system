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
    return newCourse; 

};
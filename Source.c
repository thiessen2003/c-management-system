#include <stdio.h>

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
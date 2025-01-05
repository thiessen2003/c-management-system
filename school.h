#ifndef SCHOOL_H
#define SCHOOL_H

// Structure definitions
typedef struct student {
    char name[20]; 
    unsigned int id; 
    unsigned int grade;
} Student;

typedef struct course { 
    char name[20];
    double averageGrade; 
    unsigned int totalStudents; 
    Student* studentArray; 
} Course;

typedef struct school { 
    char name[20]; 
    unsigned int totalCourses; 
    Course* courseArray; 
} School;

// Function declarations
Student* createStudent(void);
Course* createCourse(void);
School* createSchool(void);

void updateAverageGrade(Course* course);
void printStudentDetails(Student* student);
void printCourseDetails(Course* course);
void printStudentCourses(School* school, int studentID);
void printStudentsWhoFailed(Course* course, double cutOffGrade);
void printCoursesWithPassAvgGrade(School* school, double cutOffGrade);
void printAverageGradeAllCourses(School* school);
void printCourseWithHighestAverage(School* school);

#endif // SCHOOL_H
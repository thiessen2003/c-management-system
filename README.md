# School-Management-System

**School-Management-System** is a C-based application that manages educational data structures, including students, courses, and schools. The project is built using modular C programming principles, offering administrators a comprehensive platform to track academic records and performance metrics.

## Key Features

* **Student Management**: Track individual student records including names, IDs, and grades.
* **Course Organization**: Manage course details with automatic grade averaging and student enrollment.
* **School Overview**: Comprehensive school management with support for multiple courses and student tracking.
* **Performance Analytics**: Calculate and display various performance metrics including average grades and failure rates.
* **Search Functionality**: Look up student enrollments and course statistics efficiently.

## Project Structure

The repository is organized into modular components:
* **school.h**: Header file containing all structure definitions and function declarations.
* **school.c**: Implementation file with all the core functionality and logic.
* **main.c**: Entry point of the application with the main program execution.

## Installation

To compile and run the project locally, follow these steps:

1. **Clone the repository**:
```bash
git clone [your-repository-url]
```

2. **Compile the project**:
```bash
gcc -c school.c -o school.o
gcc -c main.c -o main.o
gcc school.o main.o -o school_program
```

3. **Run the application**:
```bash
./school_program
```

## Usage

The system currently supports the following operations:
* **Student Creation**: Add new students with their personal and academic information.
* **Course Management**: Create courses and assign students to them.
* **Grade Tracking**: Monitor and analyze student performance across courses.
* **Performance Reports**: Generate various reports including:
  * Course average grades
  * Failed student lists
  * Student course enrollments
  * School-wide performance metrics

## Getting Started

Here's a simple example of how to use the system:

```c
#include "school.h"

int main() {
    // Create a new school
    School* mySchool = createSchool();
    
    // Print average grades for all courses
    printAverageGradeAllCourses(mySchool);
    
    // Find the course with highest average
    printCourseWithHighestAverage(mySchool);
    
    return 0;
}
```

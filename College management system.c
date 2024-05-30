#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_COURSES 50

typedef struct {
    int id;
    char name[50];
    int age;
    char gender;
    char course[50];
} Student;

typedef struct {
    char name[50];
    int credit_hours;
} Course;

Student students[MAX_STUDENTS];
Course courses[MAX_COURSES];
int studentCount = 0;
int courseCount = 0;

void addStudent();
void addCourse();
void listStudents();
void listCourses();

int main() {
    int choice;

    do {
        printf("\nCollege Management System\n");
        printf("1. Add Student\n");
        printf("2. Add Course\n");
        printf("3. List Students\n");
        printf("4. List Courses\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                addCourse();
                break;
            case 3:
                listStudents();
                break;
            case 4:
                listCourses();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addStudent() {
    if (studentCount < MAX_STUDENTS) {
        printf("\nEnter student details:\n");
        printf("ID: ");
        scanf("%d", &students[studentCount].id);
        printf("Name: ");
        scanf("%s", students[studentCount].name);
        printf("Age: ");
        scanf("%d", &students[studentCount].age);
        printf("Gender: ");
        scanf(" %c", &students[studentCount].gender);
        printf("Course: ");
        scanf("%s", students[studentCount].course);

        studentCount++;
        printf("Student added successfully.\n");
    } else {
        printf("Cannot add more students. Student limit reached.\n");
    }
}

void addCourse() {
    if (courseCount < MAX_COURSES) {
        printf("\nEnter course details:\n");
        printf("Name: ");
        scanf("%s", courses[courseCount].name);
        printf("Credit Hours: ");
        scanf("%d", &courses[courseCount].credit_hours);

        courseCount++;
        printf("Course added successfully.\n");
    } else {
        printf("Cannot add more courses. Course limit reached.\n");
    }
}

void listStudents() {
    if (studentCount == 0) {
        printf("No students available.\n");
    } else {
        printf("\nList of Students:\n");
        for (int i = 0; i < studentCount; i++) {
            printf("ID: %d, Name: %s, Age: %d, Gender: %c, Course: %s\n",
                   students[i].id, students[i].name, students[i].age, students[i].gender, students[i].course);
        }
    }
}

void listCourses() {
    if (courseCount == 0) {
        printf("No courses available.\n");
    } else {
        printf("\nList of Courses:\n");
        for (int i = 0; i < courseCount; i++) {
            printf("Name: %s, Credit Hours: %d\n",
                   courses[i].name, courses[i].credit_hours);
        }
    }
}

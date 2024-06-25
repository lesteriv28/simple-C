#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define MAXCHAR 1000
#define MAX 2000

size_t cap = 0;

// Student Structure
typedef struct Student
{
    char name[50];
    int studentID;
    int age;
    float balance;
    float grade;
} student;

// Array of students
student batch[MAX];

student addStudent(char *Name, int sID, int age, float bal, float gpa)
{
    student new_student;
    strcpy(new_student.name, Name);
    new_student.studentID = sID;
    new_student.age = age;
    new_student.balance = bal;
    new_student.grade = gpa;

    return new_student;
}

void display_students(student *s, size_t count)
{

    for (size_t i = 0; i < count; i++)
    {
        printf(" Student Name: '%s' \t Student ID: '%d' \t Student Age: '%d' \t Account Balance: '%f' \t GPA: '%f' \n", s[i].name, s[i].studentID, s[i].age, s[i].balance, s[i].grade);
    }
}

void read_csv()
{

    FILE *fp = fopen("C:\\Users\\leste\\OneDrive\\Escritorio\\Projects\\simple-C\\simple-student\\MOCK_DATA.csv", "r");

    if (!fp)
    {
        printf("Can't open file\n");
    }

    else
    {
        char buffer[1024];

        char Name[100] = ""; 

        int sID = 0, age = 0;
        float bal = 0.0, gpa = 0.0;

        int n = 0, row = 0, column = 0;

        while (fgets(buffer, 1024, fp))
        {
            column = 0;
            row++;

            if (row == 1) // avoid printing column names
            {
                continue;
            }

            // split the data
            char *value = strtok(buffer, ", ");

            while (value)
            {
                // Column 1
                if (column == 0)
                {
                    strcpy(Name, value);
                }

                // Column 2
                if (column == 1)
                {
                    strcat(Name, " ");
                    strcat(Name, value);
                }

                // Column 3
                if (column == 2)
                {
                    sID = atoi(value);
                }

                // Column 4
                if (column == 3)
                {
                    age = atoi(value);
                }

                // Column 5
                if (column == 4)
                {
                    bal = atof(value);
                }

                // Column 6
                if (column == 5)
                {
                    gpa = atof(value);
                }

                // printf("%s", value);
                value = strtok(NULL, ", ");
                column++;
            }
            batch[n++] = addStudent(Name, sID, age, bal, gpa);
            // printf("\n");
        }
        // Close the file
        fclose(fp);
        cap = n;
    }
}

int main()
{
    read_csv();
    display_students(batch, cap);

    return 0;
}

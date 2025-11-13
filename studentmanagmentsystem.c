#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

void addStudent(struct Student s[], int *count, FILE *fp) {
    printf("\nEnter Roll Number: ");
    scanf("%d", &s[*count].roll);

    printf("Enter Name: ");
    scanf(" %[^\n]s", s[*count].name);

    printf("Enter Marks: ");
    scanf("%f", &s[*count].marks);

    (*count)++;

    // Write to file
    fp = fopen("students.txt", "a");
    fprintf(fp, "%d %s %.2f\n", s[*count-1].roll, s[*count-1].name, s[*count-1].marks);
    fclose(fp);

    printf("\nStudent Added Successfully!\n");
}

void displayStudents(struct Student s[], int count) {
    printf("\n--- Student Records ---\n");
    for(int i = 0; i < count; i++) {
        printf("\nRoll: %d\nName: %s\nMarks: %.2f\n", s[i].roll, s[i].name, s[i].marks);
    }
}

void searchStudent(struct Student s[], int count) {
    int roll, found = 0;
    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    for(int i = 0; i < count; i++) {
        if(s[i].roll == roll) {
            printf("\nStudent Found!\n");
            printf("Roll: %d\nName: %s\nMarks: %.2f\n", s[i].roll, s[i].name, s[i].marks);
            found = 1;
            break;
        }
    }
    if(!found) printf("\nStudent Not Found.\n");
}

void updateStudent(struct Student s[], int count) {
    int roll, found = 0;
    printf("\nEnter Roll Number to Update: ");
    scanf("%d", &roll);

    for(int i = 0; i < count; i++) {
        if(s[i].roll == roll) {
            printf("Enter New Name: ");
            scanf(" %[^\n]s", s[i].name);

            printf("Enter New Marks: ");
            scanf("%f", &s[i].marks);

            printf("\nRecord Updated Successfully!\n");
            found = 1;
            break;
        }
    }
    if(!found) printf("\nStudent Not Found.\n");
}

void deleteStudent(struct Student s[], int *count) {
    int roll, found = 0;
    printf("\nEnter Roll Number to Delete: ");
    scanf("%d", &roll);

    for(int i = 0; i < *count; i++) {
        if(s[i].roll == roll) {
            for(int j = i; j < *count-1; j++) {
                s[j] = s[j+1];
            }
            (*count)--;
            printf("\nRecord Deleted Successfully!\n");
            found = 1;
            break;
        }
    }
    if(!found) printf("\nStudent Not Found.\n");
}

int main() {
    struct Student s[100];
    int count = 0, choice;
    FILE *fp;

    // Load Data from File
    fp = fopen("students.txt", "r");
    if(fp != NULL) {
        while(fscanf(fp, "%d %s %f", &s[count].roll, s[count].name, &s[count].marks) != EOF) {
            count++;
        }
        fclose(fp);
    }

    while(1) {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n2. Display Students\n3. Search Student\n4. Update Student\n5. Delete Student\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(s, &count, fp); break;
            case 2: displayStudents(s, count); break;
            case 3: searchStudent(s, count); break;
            case 4: updateStudent(s, count); break;
            case 5: deleteStudent(s, &count); break;
            case 6: 
                printf("\nSaving Data & Exiting...\n");
                fp = fopen("students.txt", "w");
                for(int i = 0; i < count; i++)
                    fprintf(fp, "%d %s %.2f\n", s[i].roll, s[i].name, s[i].marks);
                fclose(fp);
                return 0;
            default: printf("\nInvalid Choice! Try Again.\n");
        }
    }
}

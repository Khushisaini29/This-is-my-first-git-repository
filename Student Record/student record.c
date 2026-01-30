 #include <stdio.h>
#include <string.h>

struct student
{
    int roll;
    char name[50];
    float marks;
};

int main()
{
    struct student s[100];
    int n = 0, choice, i, searchRoll;

    while (1)
    {
        printf("\n----- STUDENT MANAGEMENT SYSTEM -----\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter Roll Number: ");
            scanf("%d", &s[n].roll);

            printf("Enter Name: ");
            scanf(" %[^\n]", s[n].name);

            printf("Enter Marks: ");
            scanf("%f", &s[n].marks);

            n++;
            printf("\nStudent Added Successfully!\n");
            break;

        case 2:
            if (n == 0)
            {
                printf("\nNo students available.\n");
            }
            else
            {
                printf("\nRoll\tName\tMarks\n");
                for (i = 0; i < n; i++)
                {
                    printf("%d\t%s\t%.2f\n", s[i].roll, s[i].name, s[i].marks);
                }
            }
            break;

        case 3:
            printf("\nEnter Roll Number to Search: ");
            scanf("%d", &searchRoll);

            for (i = 0; i < n; i++)
            {
                if (s[i].roll == searchRoll)
                {
                    printf("\nStudent Found!\n");
                    printf("Roll: %d\nName: %s\nMarks: %.2f\n",
                           s[i].roll, s[i].name, s[i].marks);
                    break;
                }
            }

            if (i == n)
                printf("\nStudent Not Found!\n");
            break;

        case 4:
            return 0;

        default:
            printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}

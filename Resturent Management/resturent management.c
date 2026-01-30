#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct panel
{
    char uid[20];
    char pwd[20];
};

struct record
{
    char name[30];
    char phone[15];
    char address[50];
};

/* ---------------- ADMIN REGISTER ---------------- */
void registerAdmin()
{
    struct panel admin;
    FILE *fp;

    fp = fopen("login.dat", "wb");
    if (fp == NULL)
    {
        printf("File error!\n");
        return;
    }

    printf("\n--- Admin Registration (One Time) ---\n");

    printf("Enter Admin User ID: ");
    fgets(admin.uid, sizeof(admin.uid), stdin);
    admin.uid[strcspn(admin.uid, "\n")] = 0;

    printf("Enter Admin Password: ");
    fgets(admin.pwd, sizeof(admin.pwd), stdin);
    admin.pwd[strcspn(admin.pwd, "\n")] = 0;

    fwrite(&admin, sizeof(admin), 1, fp);
    fclose(fp);

    printf("\nAdmin registered successfully!\n");
}

/* ---------------- ADMIN LOGIN ---------------- */
int verifiedAdmin()
{
    struct panel admin;
    char uid[20], pwd[20];
    FILE *fp;

    fp = fopen("login.dat", "rb");
    if (fp == NULL)
    {
        printf("\nNo admin registered. Please register first.\n");
        return 0;
    }

    printf("\n--- Admin Login ---\n");

    printf("Enter User ID: ");
    fgets(uid, sizeof(uid), stdin);
    uid[strcspn(uid, "\n")] = 0;

    printf("Enter Password: ");
    fgets(pwd, sizeof(pwd), stdin);
    pwd[strcspn(pwd, "\n")] = 0;

    fread(&admin, sizeof(admin), 1, fp);
    fclose(fp);

    if (strcmp(admin.uid, uid) == 0 && strcmp(admin.pwd, pwd) == 0)
    {
        return 1;
    }
    else
    {
        printf("\nInvalid User ID or Password!\n");
        return 0;
    }
}

/* ---------------- CHECK CUSTOMER ---------------- */
int checkCustomer(char phone[])
{
    struct record c;
    FILE *fp;

    fp = fopen("customer.dat", "rb");
    if (fp == NULL)
        return 0;

    while (fread(&c, sizeof(c), 1, fp))
    {
        if (strcmp(c.phone, phone) == 0)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

/* ---------------- NEW CUSTOMER ---------------- */
void createNewCustomer()
{
    struct record c;
    FILE *fp;

    fp = fopen("customer.dat", "ab");
    if (fp == NULL)
    {
        printf("File error!\n");
        return;
    }

    printf("\n--- New Customer Registration ---\n");

    printf("Enter Name: ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = 0;

    printf("Enter Phone: ");
    fgets(c.phone, sizeof(c.phone), stdin);
    c.phone[strcspn(c.phone, "\n")] = 0;

    if (checkCustomer(c.phone))
    {
        printf("\nCustomer already exists!\n");
        fclose(fp);
        return;
    }

    printf("Enter Address: ");
    fgets(c.address, sizeof(c.address), stdin);
    c.address[strcspn(c.address, "\n")] = 0;

    fwrite(&c, sizeof(c), 1, fp);
    fclose(fp);

    printf("\nCustomer registered successfully!\n");
}

/* ---------------- OLD CUSTOMER ---------------- */
void oldCustomer()
{
    char phone[15];

    printf("\nEnter Phone Number: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = 0;

    if (checkCustomer(phone))
    {
        printf("\nWelcome back! You are an existing customer.\n");
    }
    else
    {
        printf("\nCustomer not found. Please register first.\n");
        createNewCustomer();
    }
}

/* ---------------- MENU & BILL ---------------- */
void showMenuAndBill()
{
    int choice;
    int quantity;
    float total = 0.0;

    char *items[] = {"Burger", "Pizza", "Pasta", "Coke"};
    float prices[] = {100.0, 250.0, 150.0, 50.0};
    int n = 4;

    printf("\n--- MENU ---\n");
    int i;
    for ( i = 0; i < n; i++)
    {
        printf("%d. %s - Rs %.2f\n", i + 1, items[i], prices[i]);
    }
    printf("0. Finish Order\n");

    do
    {
        printf("\nEnter item number to order (0 to finish): ");
        scanf("%d", &choice);

        if (choice > 0 && choice <= n)
        {
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            total += prices[choice - 1] * quantity;
            printf("%d x %s added. Subtotal: Rs %.2f\n", quantity, items[choice - 1], total);
        }
        else if (choice == 0)
        {
            break;
        }
        else
        {
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);

    printf("\nTotal bill amount: Rs %.2f\n", total);
    getchar(); // consume newline
}

/* ---------------- MAIN FUNCTION ---------------- */
int main()
{
    int choice, sub;
    int adminAttempts = 0;

    while (1)
    {
        printf("\n========== MAIN MENU ==========\n");
        printf("0. Register Admin (One Time)\n");
        printf("1. Admin Login\n");
        printf("2. Customer Section\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice)
        {
        case 0:
            registerAdmin();
            break;

        case 1:
            if (verifiedAdmin())
            {
                printf("\nAdmin Login Successful!\n");
            }
            else
            {
                adminAttempts++;
                if (adminAttempts >= 3)
                {
                    printf("\nToo many failed attempts. Exiting...\n");
                    exit(0);
                }
            }
            break;

        case 2:
            printf("\n1. New Customer\n2. Old Customer\nEnter choice: ");
            scanf("%d", &sub);
            getchar();

            if (sub == 1)
                createNewCustomer();
            else if (sub == 2)
                oldCustomer();
            else
            {
                printf("Invalid choice!\n");
                break;
            }

            // Show menu and calculate bill
            showMenuAndBill();
            break;

        case 3:
            printf("\nThank you! Program exited.\n");
            exit(0);

        default:
            printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}

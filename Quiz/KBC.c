#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

int countdown()
{
    int sec;

    for(sec = 10; sec >= 0; sec--)
    {
        if(sec <= 3) // blinking last 3 seconds
        {
            printf("\rTIME LEFT : 00:%02d ", sec);
            Beep(800,200);
            Sleep(300);
            printf("\r                     "); // erase timer
            Sleep(300);
        }
        else
        {
            printf("\rTIME LEFT : 00:%02d ", sec);
            Sleep(1000);
        }

        if(kbhit())
            return 1; // user answered
    }
    return 0; // time over
}

int main()
{
    int ans, money = 0;

    printf("             WELCOME TO KBC\n");
     printf("         -----------------------");
    Sleep(2000);
    system("cls");

    // ---------- Q1 ----------
    printf("Q1 Rs 1000\nCapital of India?\n");
    printf("1) Mumbai\n2) Delhi\n3) Kolkata\n4) Chennai\n");

    if(countdown())
    {
        while(kbhit()) getch(); // clear buffer
        scanf("%d",&ans);

        if(ans==2)
        {
            money=1000;
            printf("\nCorrect Answer!\n");
        }
        else
        {
            printf("\nWrong Answer!\n");
            goto end;
        }
    }
    else
    {
        printf("\nTime Over!\n");
        goto end;
    }

    Sleep(2000); system("cls");

    // ---------- Q2 ----------
    printf("Q2 Rs 5000\nFather of C language?\n");
    printf("1) Dennis Ritchie\n2) James Gosling\n3) Bjarne\n4) Guido\n");

    if(countdown())
    {
        while(kbhit()) getch();
        scanf("%d",&ans);

        if(ans==1)
        {
            money=5000;
            printf("\nCorrect Answer!\n");
        }
        else
        {
            printf("\nWrong Answer!\n");
            goto end;
        }
    }
    else
    {
        printf("\nTime Over!\n");
        goto end;
    }

    Sleep(2000); system("cls");

    // ---------- Q3 ----------
    printf("Q3 Rs 10000\nWhich datatype stores decimal?\n");
    printf("1) int\n2) char\n3) float\n4) long\n");

    if(countdown())
    {
        while(kbhit()) getch();
        scanf("%d",&ans);

        if(ans==3)
        {
            money=10000;
            printf("\nCorrect Answer!\n");
        }
        else
        {
            printf("\nWrong Answer!\n");
            goto end;
        }
    }
    else
    {
        printf("\nTime Over!\n");
        goto end;
    }

    Sleep(2000); system("cls");

    // ---------- Q4 ----------
    printf("Q4 Rs 20000\nLargest planet?\n");
    printf("1) Earth\n2) Mars\n3) Jupiter\n4) Venus\n");

    if(countdown())
    {
        while(kbhit()) getch();
        scanf("%d",&ans);

        if(ans==3)
        {
            money=20000;
            printf("\nCorrect Answer!\n");
        }
        else
        {
            printf("\nWrong Answer!\n");
            goto end;
        }
    }
    else
    {
        printf("\nTime Over!\n");
        goto end;
    }

    Sleep(2000); system("cls");

    // ---------- Q5 ----------
    printf("Q5 Rs 50000\nFounder of Microsoft?\n");
    printf("1) Steve Jobs\n2) Bill Gates\n3) Mark\n4) Larry\n");

    if(countdown())
    {
        while(kbhit()) getch();
        scanf("%d",&ans);

        if(ans==2)
        {
            money=50000;
            printf("\nCorrect Answer!\n");
        }
        else
        {
            printf("\nWrong Answer!\n");
            goto end;
        }
    }
    else
    {
        printf("\nTime Over!\n");
        goto end;
    }

end:
    Sleep(2000);
    system("cls");
    printf("GAME OVER\n");
    printf("You won Rs %d\n", money);

    return 0;
}

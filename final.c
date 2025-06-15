#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int menu(char user_type[50]);
void sign(int number, char user_type[50]);
void admin();
void user();
void comp();
void adminoption1();
void adminoption2();
void adminoption4();
void useroption1();
void useroption2();
void useroption4();
void useroption3();
void adminoption3();

char username[100][50];
char password[100][50];
char checkpass[50];
int total_users = 0;
int number;
char nameadmin[] = {"admin"};
char passadmin[] = {"1234"};
char checkname[100];
int login;
char cans;
int currentuser;
int main()
{
    printf("\n\t ---------------------");
    printf("\t Welcome to Quiz game.");
    printf("\t ---------------------\n\n");
    comp();
    return 0;
}
int menu(char user_type[50])
{
    int number;
    if ((strcmp(user_type, "user") == 0) || (strcmp(user_type, "User") == 0) || (strcmp(user_type, "USER") == 0))
    {

        printf("\n");
        printf("1.sign up\n");
        printf("2.sign in\n");
        printf("3.exit\n");
        printf("Enter Your Choice:(1/2/3) ");
        scanf("%d", &number);
        printf("\n");
    }
    else if ((strcmp(user_type, "admin") == 0) || (strcmp(user_type, "Admin") == 0) || (strcmp(user_type, "ADMIN") == 0))

    {        printf("\n");
        printf("2.sign in\n");
        printf("3.exit\n");
        printf("Enter Your Choice:(2/3) ");
        scanf("%d", &number);
        printf("\n");
    }

    return number;
}
void sign(int number, char user_type[50])
{

    int choice;

    int found = 0;
    int duplicate = 0;
    if ((strcmp(user_type, "user") == 0) || (strcmp(user_type, "User") == 0) || (strcmp(user_type, "USER") == 0))
    {
        if (number == 1)
        {
            printf("Enter username: ");
            scanf("%s", username[total_users]);
            printf("Enter your PIN: ");
            scanf("%s", password[total_users]);
            for (int i = 0; i < total_users; i++)
            {
                if (strcmp(username[total_users], username[i]) == 0)
                {
                    printf("username already exists!\n");
                    duplicate = 1;
                    comp();
                }
            }
            if (duplicate != 1)
            {
                login = 1;
                total_users++;
                currentuser = total_users - 1;
            }

            FILE *fptr;
            fptr = fopen("acc.txt", "a");
            fprintf(fptr, "%s\n", username[total_users - 1]);
            fprintf(fptr, "%s\n", password[total_users - 1]);

            fclose(fptr);
        }
        else if (number == 2)
        {
            printf("Enter username: ");
            scanf("%s", checkname);
            printf("Enter your PIN: ");
            scanf("%s", checkpass);
            for (int i = 0; i < total_users; i++)
            {
                if ((strcmp(checkname, username[i]) == 0) && (strcmp(checkpass, password[i]) == 0))
                {
             printf("\t ---------------------\t Successfully logged-In.  ---------------------\n\n");
                    login = 1;
                    found = 1;
                    currentuser = i;
                    break;
                }
            }
            if (found == 0)
            {
                printf("Wrong username or password!\n\n");
                login = 0;
                comp();
            }
        }
        if ((number != 1) && (number != 2) && (number != 3))
        {
            printf("Invalid option entered...\n");
            comp();
        }
    }

    // admin sign in menu answers

    if (((strcmp(user_type, "admin") == 0) || (strcmp(user_type, "Admin") == 0) || (strcmp(user_type, "ADMIN") == 0)) && ((number != 2) && (number != 3)))
    {
        printf("Invalid option!.Try again\n");
        comp();
    }
    if (((strcmp(user_type, "admin") == 0) || (strcmp(user_type, "Admin") == 0) || (strcmp(user_type, "ADMIN") == 0)) && (number == 2))

    {
        int try = 3;
        while (try > 0)
        {
            printf("Enter username: ");
            scanf("%s", checkname);
            printf("Enter your PIN: ");
            scanf("%s", checkpass);
            if ((strcmp(checkname, nameadmin) == 0) && (strcmp(checkpass, passadmin) == 0))
            {
                printf("Welcome\n\n");
                login = 1;
                break;
            }
            else
            {
                try--;
                printf("Wrong username or password!\n");
                if (try > 0)
                {
                    printf("You can try %d more time(s).\n", try);
                }
                else
                {
                    printf("Account blocked.\n");
                    exit(0);
                }
            }
        }
    }
    if (number == 3)
    {
        printf("Thank you!....prhty likhty raha karain.....");
        exit(0);
    }
}
void admin()
{
    int adminoption;

    printf("\t ---------------------\t MENU.\t ---------------------\n\n");
    printf("1.Add Questions\n");
    printf("2.view user accounts\n");
    printf("3.leaderboard\n");
    printf("4.view feedback\n");
    printf("5.log.out\n");
    printf("6.exit\n\n");

    printf("Enter your choice: ");
    scanf("%d", &adminoption);
    switch (adminoption)
    {
    case 1:
        adminoption1();
        break;
    case 2:
        adminoption2();
        break;
    case 3:
        adminoption3();
        break;
    case 4:
        adminoption4();
        break;
    case 5:
        useroption4();
        break;
    case 6:
        printf("Thank you!....prhty likhty raha karain.....");
        exit(0);

    default:
        printf("Invalid option entered....!\n");
        admin();
        break;
    }
}
void user()
{
    int useroption;
    printf("\t ---------------------\t MENU.\t ---------------------\n\n");
    printf("1.Quiz\n");
    printf("2.Leaderboard\n");
    printf("3.Feedback\n");
    printf("4.Log-out\n");
    printf("5.Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &useroption);

    switch (useroption)
    {
    case 1:
        useroption1();
        break;
    case 2:
        useroption2();
        break;
    case 4:
        useroption4();
        break;
    case 3:
        useroption3();
        break;
    case 5:
        printf("Thank you!....prhty likhty raha karain.....");
        exit(0);

    default:
        printf("Invalid option entered....!\n");
        user();
        break;
    }
}
void adminoption1()
{
    char statment[100];
    char option[4][100];
    getchar();
    printf("\nenter statment: ");

    fgets(statment, 100, stdin);

    printf("\nenter option1: ");

    fgets(option[0], 100, stdin);
    printf("enter option2: ");

    fgets(option[1], 100, stdin);
    printf("enter option3: ");

    fgets(option[2], 100, stdin);
    printf("enter option4: ");

    fgets(option[3], 100, stdin);

    printf("\nEnter answer: ");
    scanf(" %c", &cans);

    FILE *fptr;

    fptr = fopen("projectmcqs.txt", "a");

    fprintf(fptr, "%s", statment);
    fprintf(fptr, "%s", option[0]);
    fprintf(fptr, "%s", option[1]);
    fprintf(fptr, "%s", option[2]);
    fprintf(fptr, "%s", option[3]);
    fprintf(fptr, "%c\n", cans);
    printf("Successfully entered!\n\n");
    fclose(fptr);
    admin();
}
void adminoption2()
{
    printf("\n");

    char user_name[100];
    char pass_word[50];
    char ch = 0;
    FILE *fptr;

    fptr = fopen("acc.txt", "r");

    while (ch != EOF)
    {
        fgets(user_name, 100, fptr);
        fscanf(fptr, "%s", pass_word);
        printf("Username: %s", user_name);
        printf("PIN: %s\n\n", pass_word);

        ch = fgetc(fptr);
    }
    fclose(fptr);
    admin();
}
void comp()
{
    char user_type[50];

    printf("Are you a User or Admin?(user/admin) ");
    scanf("%s", user_type);
    number = (menu(user_type));
    sign(number, user_type);

    if (((strcmp(user_type, "admin") == 0) || (strcmp(user_type, "Admin") == 0) || (strcmp(user_type, "ADMIN") == 0)) && (login == 1))
    {
        admin();
    }
    else if (((strcmp(user_type, "user") == 0) || (strcmp(user_type, "User") == 0) || (strcmp(user_type, "USER") == 0)) && (login == 1))
    {
        user();
    }
    else
    { printf("Login failed. Exiting...\n");
        exit(0);
    }

    printf("Thank you....");
}
void useroption2()
{
    char ch;
    char n[250];
    FILE *fptr;
    fptr = fopen("Marks.txt", "r");
    while (ch != EOF)
    {

        fgets(n, sizeof(n), fptr);

        printf("%s", n);
        ch = (fgetc(fptr));
    }
    fclose(fptr);
    user();
}
void useroption1()
{

    char statment[1000];
    char option[4][100];
    char ans;
    int right = 0;
    int wrong = 0;
    float percent[100];

    FILE *fptr;
    fptr = fopen("projectmcqs.txt", "r");

    while (fgets(statment, sizeof(statment), fptr) != NULL)
    {
        fgets(option[0], sizeof(option[0]), fptr);
        fgets(option[1], sizeof(option[1]), fptr);
        fgets(option[2], sizeof(option[2]), fptr);
        fgets(option[3], sizeof(option[3]), fptr);

        fscanf(fptr, " %c", &cans);

        printf("%s", statment);
        printf("%s", option[0]);
        printf("%s", option[1]);
        printf("%s", option[2]);
        printf("%s", option[3]);
        printf("\nEnter Answer(a/b/c/d): ");
        scanf(" %c", &ans);

        if ((ans != 'a') && (ans != 'b') && (ans != 'c') && (ans != 'd'))
        {
            printf("Invalid option entered!\n");
        }

        if (ans == cans)
        {
            printf("\n.....Right answer.....\n\n");
            right++;
        }
        else if (ans != cans)
        {
            printf("\nWrong answer!\n");
            printf("Correct answer is: %c\n\n", cans);
            wrong++;
        }
        fgetc(fptr);
    }
    fclose(fptr);
    percent[currentuser] = (((float)right / (float)((right + wrong))) * 100.00);

    fptr = fopen("Marks.txt", "a");
    fprintf(fptr, " %s\t", username[currentuser]);
    fprintf(fptr, " %f\n", percent[currentuser]);
    fclose(fptr);

    printf("\t ---------------------Quiz completed\t ---------------------\n\n");
    printf("Wrong answers: %d\n", wrong);
    printf("You secured %d out of %d.\n", right, right + wrong);
    printf("Percentage:%f%%\n", percent[currentuser]);
    if (percent[currentuser] >= 80)
    {
        printf("Microsoft/Google waiting for you....!\n");
    }
    else if ((percent[currentuser] >= 60) && (percent[currentuser] < 80))
    {
        printf("Need to improve.....\n");
    }
    else
    {

        printf("DUA kia karain apny liay....\n");
    }
    printf("\n");
    user();
}
void useroption4()
{
    printf("Thank you...\n");
    comp();
}
void useroption3()
{
    char str[1000];
    printf("Enter your feedback: ");

    fgets(str, 1000, stdin);
    fgets(str, 1000, stdin);
    FILE *fptr;
    fptr = fopen("feedback.txt", "a");
    fprintf(fptr, " %s", str);
    fclose(fptr);
    printf("\nThanks for sharing your opinion..!we'll definatelly work on it.\n\n");
    user();
}
void adminoption4()
{
    char ch;
    char feedback[1000];
    FILE *fptr;
    printf("\n");
    fptr = fopen("feedback.txt", "r");
    while (ch != EOF)
    {
        fgets(feedback, sizeof(feedback), fptr);
        printf(" %s", feedback);
        ch = (fgetc(fptr));
    }
    printf("\n");
    fclose(fptr);
    admin();
}
void adminoption3()
{
    char ch;
    char n[250];
    FILE *fptr;
    fptr = fopen("Marks.txt", "r");
    while (ch != EOF)
    {

        fgets(n, sizeof(n), fptr);

        printf("%s\n", n);
        ch = (fgetc(fptr));
    }
    fclose(fptr);
    printf("\n");
    admin();
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
int check;
struct Booking
{
    char transaction_id[11];
    char sname[20];
    char rname[20];
    char location1[50];
    char location2[50];
    int quantity;
    int weight;
    char size[9];
    char type[11];
    int dist;
    int price;
} b1;
char *generate_transaction_id()
{
    static char id[20];
    time_t now = time(NULL);
    sprintf(id, "%ld", now);
    return id;
}
int bill(int z, int s, int dist)
{
    int a, price, tax;
    a = z * s * dist;
    tax = 0.12 * a;
    price = a + tax;
    return price;
}
int type()
{
    int n2, t;
    printf("\n 1. Electronics\n 2. Food\n 3. Clothes\n 4. Furniture\n 5. Stationary\n");
    printf("Select the Type of parcel:");
    scanf("%d", &n2);
    if (n2 == 1)
    {
        strcpy(b1.type, "Electronics");
        t = 5;
        return t;
    }
    else if (n2 == 2)
    {
        strcpy(b1.type, "Food");
        t = 3;
        return t;
    }
    else if (n2 == 3)
    {
        strcpy(b1.type, "Clothes");
        t = 2;
        return t;
    }
    else if (n2 == 4)
    {
        strcpy(b1.type, "Furniture");
        t = 20;
        return t;
    }
    else if (n2 == 5)
    {
        strcpy(b1.type, "Stationary");
        t = 4;
        return t;
    }
    else
    {
        printf("========================\n");
        printf("Invalid Credentials\n");
        printf("========================\n");

        return type();
    }
}
int size()
{
    int n1, s;
    printf("\n 1. Small\n 2. Medium\n 3. Large\n 4. Oversized\n");
    printf("Select the Size of parcel:");
    scanf("%d", &n1);
    if (n1 == 1)
    {
        strcpy(b1.size, "Small");
        s = 4;
        return s;
    }
    else if (n1 == 2)
    {
        strcpy(b1.size, "Medium");
        s = 8;
        return s;
    }
    else if (n1 == 3)
    {
        strcpy(b1.size, "Large");
        s = 16;
        return s;
    }
    else if (n1 == 4)
    {
        strcpy(b1.size, "Oversized");
        s = 32;
        return s;
    }
    else
    {
        printf("========================\n");
        printf("Invalid Credentials\n");
        printf("========================\n");
        return size();
    }
}
int menu()
{
    int choice;
    printf("\n***********************************************\n");
    printf("Welcome to StreamLine Courier Sevices");
    printf("\n 1). Register           2). Login\n");
    scanf("%d", &choice);
    return choice;
}
int loginRegister(int n)
{
    FILE *fptr;
    if (n == 1)
    {
        fptr = fopen("logincredentials.txt", "a+");
        if (fptr == NULL)
        {
            printf("File Does Not Exist");
            return 0;
        }
        char username[10], password[10];
        printf("Enter Username ");
        scanf("%s", username);
        printf("Enter Password ");
        scanf("%s", password);
        fprintf(fptr, "%s %s\n", username, password);
        fclose(fptr);
        printf("\n New User Registered Successfully !!");
        main();
    }
    else
    {
        FILE *fp = fopen("logincredentials.txt", "r");
        int matched = 0;
        char username[10];
        char password[10];
        char uname[10];
        char pass[10];
        printf("\n Enter Username ");
        scanf("%s", uname);
        printf("\n Enter Password ");
        scanf("%s", pass);

        while (fscanf(fp, "%s%s", username, password) != EOF)
        {
            if (strcmp(username, uname) == 0 && strcmp(password, pass) == 0)
            {
                matched = 1;
                break;
            }
        }

        fclose(fp);
        if (matched == 0)
        {
            printf("\n Invalid Credentials");
            return 0;
        }
        else
            return 1;
    }
}
int courier()
{
    int choice;
    printf("\nCourier\n");

    FILE *ptr;
    ptr = fopen("Data.txt", "a+");
    if (ptr == NULL)
    {
        printf("File Does Not Exist");
        return 0;
    }

    printf("********************************************************\n");

    char *transaction_id = generate_transaction_id();
    strcpy(b1.transaction_id, &*transaction_id);

    printf("Select the quantity of parcel:");
    scanf("%d", &b1.quantity);
    printf("=======================================\n");
    int s = size();

    printf("=======================================\n");
    printf("Type the weight of parcel:");
    scanf("%d", &b1.weight);
    printf("=======================================\n");
    int t = type();

    printf("=======================================\n");
    printf("Enter Sender Name:");
    scanf("%s", &b1.sname);

    printf("=======================================\n");
    printf("Enter Senders Address:");
    scanf("%s", &b1.location1);

    printf("=======================================\n");
    printf("Enter Reciever Name:");
    scanf("%s", &b1.rname);

    printf("=======================================\n");
    printf("Enter Destination Address:");
    scanf("%s", &b1.location2);

    printf("=======================================\n");
    printf("Enter Distance of location:");
    scanf("%d", &b1.dist);
    printf("=======================================\n");
    int price = bill(s, t, b1.dist);
    b1.price = price;

    printf(" Transaction id: %s", b1.transaction_id);
    printf("\nTotal Amount: %d", b1.price);

    // fwrite(&b1, sizeof(struct Booking), 1, ptr);
    fprintf(ptr, "%s %d %s %d %s %s %s %s %s %d %d\n", b1.transaction_id, b1.quantity, b1.size, b1.weight, b1.type, b1.sname, b1.location1, b1.rname, b1.location2, b1.dist, b1.price);

    fclose(ptr);
    payment();
    printf("Do you want to:\n");
    printf("1). Know Booking Details\n2). Track Your Order\n3). Exit\n");
    scanf("%d", &choice);

    if (choice == 1)
        bookingInfo();

    else if (choice == 2)
        parcelTracking();

    else if (choice == 3)
    {
        printf(" THANK YOU FOR USING OUR SERVICES...\n");
        exit(0);
    }
    return 0;
}
int bookingInfo()
{
    int choice;
    char t[11];
    printf("=============================");
    printf("\nBooking\n");
    FILE *ptr;
    ptr = fopen("Data.txt", "r");
    if (ptr == NULL)
    {
        printf("File Does Not Exist");
        return 0;
    }
    printf("================================================");
    printf("\nEnter your transation id\n");
    scanf("%s", &t);

    //  fread(&b1, sizeof(struct Booking), 1, ptr);
    while (!feof(ptr))
    {

        fscanf(ptr, "%s", b1.transaction_id);
        {
            if (strcmp(t, b1.transaction_id) == 0)
            {
                fscanf(ptr, "%d %s %d %s %s %s %s %s %d %d", &b1.quantity, b1.size, &b1.weight, b1.type, b1.sname, b1.location1, b1.rname, b1.location2, &b1.dist, &b1.price);

                printf("Transation id: %s\n", b1.transaction_id);
                printf("Sender name: %s\n", b1.sname);
                printf("Reciever name: %s\n", b1.rname);
                printf("Sender Location: %s\n", b1.location1);
                printf("Reciever Location: %s\n", b1.location2);
                printf("Quantity of Parcel: %d\n", b1.quantity);
                printf("Weight of parcel: %d\n", b1.weight);
                printf("Size of Parcel: %s\n", b1.size);
                printf("Type of Parcel: %s\n", b1.type);
                printf("Total Amount: %d", b1.price);
                printf("\n===================================================\n");
            }
        }
    }

    fclose(ptr);
    int pc;
    int q;
    printf("for payment press (0)\n to cancel payment (1)\n");
    scanf("%d", &pc);
    switch (pc)
    {
    case 0:
        payment();
    case 1:
        printf("are you sure you want to cancel payment \n1) yes \t 2) no ");
        scanf("%d", &q);
        if (q == 1)
        {
            exit(0);
        }
        else
        {
            return bookingInfo();
        }
    }

    printf("Do you want to:\n");
    printf("1). Place new order for courier\n2). Track Your Order\n3). Exit\n");
    scanf("%d", &choice);

    if (choice == 1)
        courier();

    else if (choice == 2)
        parcelTracking();

    else if (choice == 3)
    {
        printf(" THANK YOU FOR USING OUR SERVICES...\n");
        exit(0);
    }

    return 0;
}
int parcelTracking()
{
    int choice;
    printf("======================================");
    printf("\nParcelTracking\n");

    float a, t;
    time_t now_1 = time(NULL);

    printf("Enter your transation id\n");
    scanf("%f", &a);

    t = (now_1 - a) / 60;
    if (t >= 0 && t <= 2)
        printf("Preparing to dispatch\n");
    else if (t > 2 && t <= 10)
        printf("Shipped to nearest dock\n");
    else if (t > 10 && t < 15)
        printf("Out for delivery\n");
    else if (t >= 15)
        printf("Delivered\n");

    printf("Do you want to:\n");
    printf("1). Place new order for courier\n2). Know Booking Details\n3). Exit\n");
    scanf("%d", &choice);

    if (choice == 1)
        courier();

    else if (choice == 2)
        bookingInfo();

    else if (choice == 3)
    {
        printf(" THANK YOU FOR USING OUR SERVICES...\n");
        exit(0);
    }
    return 0;
}
int payment()
{
    char t[11];

    FILE *ptr;
    ptr = fopen("Data.txt", "r");
    if (ptr == NULL)
    {
        printf("id does not exist ");
        return 0;
    }
    else
    {
        printf("enter your transation id :");
        scanf("%s", &t);

        while (!feof(ptr))
        {
            fscanf(ptr, "%s", b1.transaction_id);

            if (strcmp(t, b1.transaction_id) == 0)
            {
                fscanf(ptr, "%d %s %d %s %s %s %s %s %d %d", &b1.quantity, b1.size, &b1.weight, b1.type, b1.sname, b1.location1, b1.rname, b1.location2, &b1.dist, &b1.price);

                printf("Transation id: %s\n", b1.transaction_id);
                printf("name: %s\n", b1.sname);
                printf("Total Amount: ₹ %d\n", b1.price);
            }
            fclose(ptr);
        }
        while (!feof(ptr))
        {
            int ch;
            int s;
            int credit;
            int cvv;

            printf("mode of payment \n 1). cash on delivery         2). debit card ");
            scanf("%d", &ch);
            if (ch == 1)
            {

                printf("\n you have to pay: rs %d by cash \n", b1.price);
            }

            else if (ch == 2)
            {

                printf("DO YOU WANT TO CONFIRM YOUR PAYMENT BY DEBIT CARD \nPRESS 1 FOR YES\n2 FOR NO");
                scanf("%d", &s);
                if (s == 1)
                {
                    printf("\nENTER YOUR CREDIT CARD DETAILS\n");
                    printf("\nCARD NUMBER:\n ");
                    scanf("%d", &credit);
                    printf("\nENTER CVV:\n ");
                    scanf("%d", &cvv);
                    printf("\n here is your summary\n");
                    printf("\nTransation id: %s\n", b1.transaction_id);
                    printf(" \n name: %s\n", b1.sname);
                    printf("\n total amount: rs%d\n", b1.price);
                }
            }
            fclose(ptr);
        }
        return 0;
    }
    int main()
    {
        int n, a, sure;
        n = menu();
        check = loginRegister(n);
        if (check == 0)
            return 0;
        else if (check == 1)
        {
            system("cls");
            system("cls");
        choices:
            printf("\n***********************************************\n");
            printf("Welcome to StreamLine Courier Sevices");
            printf("\n 1). Courier Your Order");
            printf("\n 2). Booking Details");
            printf("\n 3). Parcel Tracking ");
            printf("\n 4). exist ");

            printf("\n Enter Your Choice: ");
            scanf("%d", &a);
            if (a == 1)
                courier();
            else if (a == 2)
                bookingInfo();
            else if (a == 3)
                parcelTracking();
            else if (a == 4)
            {
                printf("Are you sure you want to exit?\n 1). YES\t 2). NO\n");
                scanf("%d", &sure);
                if (sure == 1)
                {
                    printf("THANK YOU FOR USING OUR SERVICES...");
                    exit(0);
                }
                else
                {
                    goto choices;
                }
            }
        }
        else
            return 0;

        return 0;
    }
}
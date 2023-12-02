#include <stdio.h>
#include <conio.h>
#define N 200

struct bank
{
    int acn;
    char name[20];
    int bal; /* defined out of main() */
};

void main()
{

    struct bank b[N];

    int i, ch, lw = 100, ch2, ac, am;

    clrscr();

    for (i = 0; i < N; i++)
    { /* inputting customer data */

        printf("\tEnter information of customers \n");
        printf("\t******************************\n\n");

        printf("enter account no.: ");
        scanf("%d", &b[i].acn);

        printf("\n\nenter customer name: ");
        scanf("%s", &b[i].name);

        printf("\n\nenter balance: ");
        scanf("%d", &b[i].bal);

        clrscr();
    }

    clrscr();

    printf("\tEnter your choice\n"); /* further processing of transaction */
    printf("\t*****************\n\n");

    printf("1: to know whose balance is below 100.\n\n");
    printf("2: to process request or withdrawl.\n\n\n");

    scanf("%d", &ch);

    switch (ch)
    {

    case 1:

        clrscr();

        disp(&b); /* displaying whose balance is below 100 */

        break;

    case 2:

        clrscr();

        printf("enter your account number: ");
        scanf("%d", &ac);

        for (i = 0; i < N; i++)
        {

            if ((b[i].acn) == ac)
            {

                clrscr();

                printf("\tHello %s\n", b[i].name);
                printf("\n\n");

                printf("\n\nenter your choice\n");
                printf("\n1: deposite:\n");
                printf("\n0: withdrawl:\n\n");
                scanf("%d", &ch2);

                switch (ch2)
                {

                case 0:

                    clrscr();

                    if (b[i].bal < lw)
                    {

                        printf("\n\nsorry! account balance is too low for withdrawl.\n");

                        break;
                    }

                    else
                    {

                        printf("\n\nenter amount for withdrawl: ");
                        scanf("%d", &am);
                    }

                    if (b[i].bal < am)
                    {

                        printf("\n\nyou don't have enough balance for withdrawl.\n");
                    }

                    else
                    {

                        b[i].bal = b[i].bal + am;

                        printf("\n\nwithdrawl was successful.\n");
                    }
                    break;

                case 1:

                    clrscr();

                    printf("\n\nenter amount to deposite: ");
                    scanf("%d", &am);

                    b[i].bal = b[i].bal + am;

                    printf("\n\ncash deposited successfully.\n\n");

                    break;
                }
            }
        }
    }
    getch();
}

disp(struct bank *a)
{

    int k;

    printf("\tCustomers whose balance is below 100:\n");
    printf("\t*************************************\n\n");

    for (k = 0; k < N; k++)
    {

        if ((a[k].bal) < 100)
        {

            printf("%2d\t%s\n", a[k].acn, a[k].name);
        }
    }
    return 0;
}

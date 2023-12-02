#include <stdio.h>
#include <string.h>
#define MAX_SEATS 50

struct seat
{
    int number;
    char name[20];
    int reserved;
};

void show_menu(void);
void show_seats(struct seat *seats, int count);
int reserve_seat(struct seat *seats, int count, int seat_number, char *passenger_name);

int main(void)
{
    int choice, seat_number;
    char passenger_name[20];
    struct seat seats[MAX_SEATS];

    // Initialize the seat numbers
    for (int i = 0; i < MAX_SEATS; i++)
    {
        seats[i].number = i + 1;
        seats[i].reserved = 0;
    }

    while (1)
    {
        show_menu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            show_seats(seats, MAX_SEATS);
            break;
        case 2:
            printf("|-------------------------|\n"); 
            printf("|Enter seat number:       | ");
            scanf("%d", &seat_number);
            printf("|Enter passenger name:    |");
            scanf("%s", passenger_name);
            if (reserve_seat(seats, MAX_SEATS, seat_number, passenger_name))
           {printf("|--------------------------|\n"); 
            printf("|Seat reserved successfully|\n");
            printf("date and time of booking:%s \n %s ",__DATE__,__TIME__);
            printf("|--------------------------|\n");
           }
            else{
                printf("|Seat not available.   |\n");
                printf("|----------------------|\n"); 
            }
            break;
        case 3:
            return 0;
        default:
            printf("|---------------|\n"); 
            printf("|Invalid option.|\n");
            printf("|---------------|\n"); 
            break;
        }
    }

    return 0;
}

void show_menu(void)
{
    printf("|-------------------------|\n"); 
    printf("|-------------------------|\n");
    printf("|1.| Show available seats |\n");
    printf("|_________________________|\n");
    printf("|2.| Reserve a seat        |\n");
    printf("|_________________________|\n");
    printf("|3.| Quit                 |\n");
    printf("|_________________________|\n");
    printf("|Enter your choice:");

}


void show_seats(struct seat *seats, int count)
{
    printf("\nSeat number  Passenger name\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < count; i++)
    {
        if (seats[i].reserved){
            printf("______________________________________________\n");
            printf("|%d|\t|%s|\n", seats[i].number, seats[i].name);
            printf("_______________________________________________\n");
            
        }

        else{
             printf("|_________________|\n");
             printf("|%d|\t|Available|\n", seats[i].number);
             printf("|_________________|\n");
    
        }
           
    }
}

int reserve_seat(struct seat *seats, int count, int seat_number, char *passenger_name)
{
    for (int i = 0; i < count; i++)
    {
        if (seats[i].number == seat_number)
        {
            if (seats[i].reserved)
                return 0;
            else
            {
                seats[i].reserved = 1;
                strcpy(seats[i].name, passenger_name);
                return 1;
            }
        }
    }
    return 0;
}


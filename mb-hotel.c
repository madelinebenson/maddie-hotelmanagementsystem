#include <stdio.h>
#include <stdlib.h>

#define floors 5
#define roomsPerFloor 8

int rooms[floors][roomsPerFloor] = {0};

void showStatus(void);
void makeReservation(void);

int main(void)
{
    int choice;

    while (1) {
        printf("\n=== Hampton Inn Management System ===\n");
        printf("1. Show room status\n");
        printf("2. Make a reservation\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            showStatus();
        }
        else if (choice == 2) {
            makeReservation();
        }
        else if (choice == 3) {
            printf("Goodbye!\n");
            return 0;
        }
        else {
            printf("Invalid choice.\n");
        }
    }
}

void showStatus(void)
{
    int f, r;
    printf("\nRoom status:\n");
    for (f = 0; f < floors; f++) {
        printf("Floor %d: ", f + 1);
        for (r = 0; r < roomsPerFloor; r++) {
            printf("[%d:%d %s] ", f + 1, r + 1,
                   rooms[f][r] ? "Taken" : "Free");
        }
        printf("\n");
    }
}

void makeReservation(void)
{
    int floor, room;

    printf("\nEnter floor (1-%d): ", floors);
    scanf("%d", &floor);
    printf("Enter room number (1-%d): ", roomsPerFloor);
    scanf("%d", &room);

    if (floor < 1 || floor > floors) {
        printf("Invalid floor number.\n");
        return;
    }
    if (room < 1 || room > roomsPerFloor) {
        printf("Invalid room number.\n");
        return;
    }

    int f = floor - 1;
    int r = room - 1;

    if (rooms[f][r]) {
        printf("Room %d:%d is already taken.\n", floor, room);
    } else {
        rooms[f][r] = 1;
        printf("Room %d:%d reserved successfully!\n", floor, room);
    }
}

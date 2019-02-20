#include <stdio.h>
#include <stdlib.h>
#include"conio2.h"
#include"rlyres.h"
#include<string.h>

int main()
{
    int choice;
    add_trains();
    Passenger *details;
    Passenger psn;
    int ticket_number;
    int ticket;
    int i;
    char *mobile;
    char *train;
    char pass[6];
    char check[]="admin";
    while(1)
    {
        fflush(stdin);
        clrscr();
        choice=enterchoice();          /*if we enter a alphabet code is showing undefined behaviour*/

    switch(choice)
    {
    case 1:
        view_trains();
        break;
    case 2:
        details=get_passenger_details();
        if(details==NULL)
        {
            break;
        }
        strcpy(psn.address,details->address);
        psn.age=details->age;
        psn.gender=details->gender;
        strcpy(psn.mob_no,details->mob_no);
        psn.p_class=details->p_class;
        strcpy(psn.p_name,details->p_name);
        strcpy(psn.train_no,details->train_no);


        ticket_number=book_ticket(*details);
        if(ticket_number==-1)
        {
            textcolor(LIGHTRED);
            printf("\nBooking Failed");
            getch();
            textcolor(YELLOW);
            break;
        }
        psn.ticketno=ticket_number;
        printf("Passenger Name : %s",psn.p_name);
        printf("\nPassenger Ticket No. : %d",psn.ticketno);
        textcolor(WHITE);
        printf("\nThank You!");
        printf("\nPress Any Key to exit to main screen");
        textcolor(YELLOW);
        getch();
        break;
    case 3:

        clrscr();
        gotoxy(105,1);
        textcolor(LIGHTGREEN);
        printf("Press 0 to exit");
        textcolor(YELLOW);
        gotoxy(1,1);
        ticket_number=accept_ticket_no();
        if(ticket_number!=0)
        {
            view_ticket(ticket_number);
        }
        break;
    case 4:
        clrscr();
        gotoxy(105,1);
        textcolor(LIGHTGREEN);
        printf("Press 0 to exit");
        textcolor(YELLOW);
        gotoxy(1,1);
        mobile=accept_mobile_no();
        if(mobile==NULL)
            break;
        else
            get_ticket_no(mobile);
        break;
    case 5:
        view_all_bookings();
        textcolor(WHITE);
        printf("Press any key to navigate to main screen");
        textcolor(YELLOW);
        getch();
        break;
    case 6:
        clrscr();
        gotoxy(105,1);
        textcolor(LIGHTGREEN);
        printf("Press 0 to exit");
        textcolor(YELLOW);
        gotoxy(1,1);
        train=accept_train_no();
        if(train==NULL)
            break;
        else
        {
            view_bookings(train);
        }
            break;
    case 7:
        clrscr();
        gotoxy(105,1);
        textcolor(LIGHTGREEN);
        printf("Press 0 to exit");
        textcolor(YELLOW);
        gotoxy(1,1);
        ticket=accept_ticket_no();
        if(ticket==0)
            break;
           i=cancel_ticket(ticket);
           if(i==0)
           {
               textcolor(LIGHTGREEN);
               printf("No bookings done yet");
               getch();
           }
           else if(i==1)
           {
               textcolor(LIGHTGREEN);
               printf("Cancellation Successful");
               getch();
           }
           else
           {
               textcolor(LIGHTGREEN);
               printf("No such Ticket No. Found!");
               textcolor(YELLOW);
               getch();
           }
        break;
    case 8:
        clrscr();
        gotoxy(105,1);
        textcolor(LIGHTGREEN);
        printf("Press 0 to exit");
        textcolor(YELLOW);
        gotoxy(1,1);
        printf("Enter 5 digit password : ");
        for(i=0;i<5;i++)
        {
            pass[i]=(char)getch();
            printf("*");
        }
        pass[i]='\0';
        if(strcmp(pass,check)==0)
        {
            clrscr();
            train=accept_train_no();
            if(train==NULL)
                break;
            else
            {
                i=cancel_train(train);
                if(i==0)
                {
                    textcolor(LIGHTGREEN);
                    printf("No Bookings Done Yet");
                    getch();
                }
                else
                {
                    textcolor(LIGHTGREEN);
                    printf("Cancellation Successful");
                    getch();
                    textcolor(YELLOW);
                }
            }
        }
        else
        {
            gotoxy(1,30);
            textcolor(LIGHTRED);
            printf("Wrong Password");
            getch();
        }
        break;
    case 9:
        exit(0);
        break;
    default:
        textcolor(LIGHTRED);
        gotoxy(1,30);
        printf("Wrong Choice! Try again");
        getch();
    }
    }
    return 0;
}

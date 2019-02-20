#ifndef RLYRES_H_INCLUDED
#define RLYRES_H_INCLUDED

struct Train
{
    char train_no[10];
    char from[20];
    char to[20];
    int fac_fare;
    int sac_fare;
};
struct Passenger
{
    char p_name[20];
    char gender;
    char mob_no[11];
    int age;
    char train_no[10];
    char p_class;
    int ticketno;
    char address[30];
};
typedef struct Train Train;
typedef struct Passenger Passenger;

int enterchoice();
void add_trains();
void view_trains();
int book_ticket(Passenger );
void get_ticket_no();
void view_ticket(int);
void view_all_bookings();
void view_bookings(char *);
int cancel_ticket(int);
int cancel_train(char *);

char * accept_train_no();
char* accept_mobile_no();
int accept_ticket_no();
int check_train_no(char *);
Passenger * get_passenger_details();
int get_booked_ticket_count(char *,char);
int last_ticket_no();
#endif // RLYRES_H_INCLUDED

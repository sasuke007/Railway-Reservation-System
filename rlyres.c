#include<stdio.h>
#include"conio2.h"
#include"rlyres.h"
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int enterchoice()
{
    int choice,i;
    gotoxy(44,1);
    textcolor(YELLOW);
    printf("RAILWAY RESERVATION SYSTEM\n");
    for (i=0;i<120;i++)
    {
        if(i%2==0)
        {
            printf("-");
        }
        else
        {
            printf(" ");
        }
    }
        gotoxy(1,3);
        printf("Select a choice \n");
        printf("1- View Trains\n");
        printf("2- Book Ticket\n");
        printf("3- View Ticket\n");
        printf("4- Search Ticket No\n");
        printf("5- View All Bookings\n");
        printf("6- View Train Bookings\n");
        printf("7- Cancel Ticket\n");
        printf("8- Cancel Train\n");
        printf("9- Quit\n\n");
        printf("Enter Choice : ");
        scanf("%d",&choice);
        return choice;
}

void add_trains()
{
    FILE *fp;
    fp=fopen("E:\\MyProjects\\code blocks project\\Railway Reservation System\\alltrains.dat","rb");
    if(fp==NULL)
    {
        Train alltrains[4]={{"123","BPL","GWA",2100,1500},
              {"546","BPL","DEL",3500,2240},
              {"345","HBJ","AGR",1560,1135},
              {"896","HBJ","MUM",4500,3360}};

        fp=fopen("E:\\MyProjects\\code blocks project\\Railway Reservation System\\alltrains.dat","wb");
        fwrite(alltrains,4*sizeof(Train),1,fp);
        textcolor(LIGHTCYAN);
        printf("File saved successfully");
        fclose(fp);
    }
    else
    {
        textcolor(LIGHTCYAN);
        printf("File already present");
        fclose(fp);
    }

}


void view_trains()
{
    clrscr();
    int i;
    printf("TRAIN NO.\t\t");
    printf("FROM\t\t\t");
    printf("TO\t\t");
    printf("FIRST AC FARE\t\t\t");
    printf("SECOND AC FARE\n");
    for(i=0;i<120;i++)
    {
        printf("-");
    }
    printf("\n");
    FILE *fp;
    fp=fopen("E:\\MyProjects\\code blocks project\\Railway Reservation System\\alltrains.dat","rb");
    Train r_data;
    while(fread(&r_data,sizeof(Train),1,fp)==1)
    {
        printf("%s\t\t\t",r_data.train_no);
        printf("%s\t\t\t",r_data.from);
        printf("%s\t\t\t",r_data.to);
        printf("%d\t\t\t",r_data.fac_fare);
        printf("    %d\n",r_data.sac_fare);
    }
    textcolor(WHITE);
    printf("Press any key to navigate to main screen");
    fclose(fp);
    getch();
}


int check_train_no(char *train)
{
    FILE *fp;
    fp=fopen("E:\\MyProjects\\code blocks project\\Railway Reservation System\\alltrains.dat","rb");
    Train check_train;
    while(fread(&check_train,sizeof(Train),1,fp)==1)
    {
        if(strcmp(check_train.train_no,train)==0)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}



Passenger * get_passenger_details()
{
    static Passenger p_details;
    clrscr();
    gotoxy(105,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(YELLOW);
    printf("Enter Passenger's Name : ");
    while(1)
    {
        fflush(stdin);
        fgets(p_details.p_name,20,stdin);
        char *pos;
        pos=strchr(p_details.p_name,'\n');
        if(pos!=NULL)
        *pos='\0';
        if(strcmp(p_details.p_name,"0")==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,30);
            printf("Reservation Cancelled");
            getch();
            textcolor(YELLOW);
            return NULL;
        }
        int i;
        int check=0;
        for(i=0;p_details.p_name[i]!='\0';i++)
        {
            if(isalpha(p_details.p_name[i])==0)
               {
                   check=1;
               }
        }
        if(check==1)
        {
            gotoxy(1,30);
            textcolor(LIGHTRED);
            printf("Name should contain only alphabets");
            getch();
            gotoxy(1,30);
            printf("                                                         ");
            textcolor(YELLOW);
            gotoxy(26,1);
            printf("                                                            ");
            gotoxy(26,1);
            continue;
        }
        else
            break;

    }


    printf("\nEnter your Gender(M/F) : ");

    while(1)
    {
    fflush(stdin);
    scanf("%c",&p_details.gender);
    if(p_details.gender==0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,30);
        printf("Reservation Cancelled");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
    if(p_details.gender=='m'||p_details.gender=='M'||p_details.gender=='f'||p_details.gender=='F')
    {
        break;
    }

        gotoxy(1,30);
        textcolor(LIGHTRED);
        printf("Invalid Input! Gender should be (M/F)");
        getch();
        textcolor(YELLOW);
        //gotoxy(1,30);
        printf("\r");
        printf("                                             ");
        gotoxy(26,3);
        printf("                  ");
        gotoxy(26,3);
    }


    printf("\nEnter Train Number : ");
    while(1)
    {
    fflush(stdin);
    fgets(p_details.train_no,10,stdin);              /* If two alphaneumeric strings are entered simul
                                                     -taneously then the code is crashing????*/
    char *p;
    p=strchr(p_details.train_no,'\n');
    if(p!=NULL)
        *p='\0';
    if(strcmp(p_details.train_no,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,30);
        printf("Reservation Cancelled");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
    int r_train;
    r_train=check_train_no(p_details.train_no);
    if(r_train==1)
    {
        break;
    }
    else
    {
        gotoxy(1,30);
        textcolor(LIGHTRED);
        printf("Please Input a valid Train Number");
        getch();
        textcolor(YELLOW);
        //gotoxy(1,30);
        printf("\r");
        printf("                                             ");
        gotoxy(22,5);
        printf("                  ");
        gotoxy(22,5);
    }
    }
    printf("\nEnter your Mobile no. : ");
    while(1)
    {
    fflush(stdin);
    fgets(p_details.mob_no,11,stdin);
    char *p;
    p=strchr(p_details.mob_no,'\n');
    if(p!=NULL)
        *p='\0';
    gotoxy(25,7);
    printf("                                    ");
    gotoxy(25,7);
    printf("%s\n",p_details.mob_no);
    if(strcmp(p_details.mob_no,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,30);
        printf("Reservation Cancelled");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
    if(strlen(p_details.mob_no)<10)
    {
        gotoxy(1,30);
        textcolor(LIGHTRED);
        printf("Please Input a valid Mobile Number");
        getch();
        textcolor(YELLOW);
        //gotoxy(1,30);
        printf("\r");
        printf("                                                     ");
        gotoxy(25,7);
        printf("                         ");
        gotoxy(25,7);
        continue;
    }
    int i;
    int check=0;
    for(i=0;i<10;i++)
    {
        if(isdigit(p_details.mob_no[i])==0)
        {
            check=1;
        }
    }
    if(check==1)
    {
               gotoxy(1,30);
        textcolor(LIGHTRED);
        printf("Please Input a valid Mobile Number");
        getch();
        textcolor(YELLOW);
        //gotoxy(1,30);
        printf("\r");
        printf("                                             ");
        gotoxy(25,7);
        printf("                             ");
        gotoxy(25,7);
        continue;
    }
    else
        break;
    }

    printf("\nEnter Travelling Class(First AC - F)/(Second AC - S) : ");
    while(1)
    {
        fflush(stdin);
        scanf("%c",&p_details.p_class);
        if(p_details.p_class=='0')
        {
            textcolor(LIGHTRED);
        gotoxy(1,30);
        printf("Reservation Cancelled");
        getch();
        textcolor(YELLOW);
        return NULL;
        }

        if(p_details.p_class!='f'&&p_details.p_class!='s'&&p_details.p_class!='F'&&p_details.p_class!='S')
        {
            gotoxy(1,30);
        textcolor(LIGHTRED);
        printf("Please Input a valid Class");
        getch();
        textcolor(YELLOW);
        //gotoxy(1,30);
        printf("\r");
        printf("                                             ");
        gotoxy(56,9);
        printf("                             ");
        gotoxy(56,9);
        }
        else
        {
            break;
        }

    }

    printf("\nEnter your age : ");
    while(1)
    {
        char arr[80];
        fflush(stdin);
        fgets(arr,80,stdin);
        char *pos;
        pos=strchr(arr,'\n');
        if(pos!=NULL)
            *pos='\0';
        if(arr[0]=='\0')
        {
            gotoxy(1,30);
            textcolor(LIGHTRED);
            printf("Please enter a valid age...");
            getch();
            gotoxy(1,30);
            printf("                                                         ");
            textcolor(YELLOW);
            gotoxy(18,11);
            printf("                                                            ");
            gotoxy(18,11);
            continue;
        }
        if(strcmp(arr,"0")==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,30);
            printf("Reservation Cancelled");
            getch();
            textcolor(YELLOW);
            return NULL;
        }
        int i;
        int check=0;
        for(i=0;arr[i]!='\0';i++)
        {
            if(isalpha(arr[i])!=0)
               {
                   check=1;
               }
        }
        if(check==1)
        {
            gotoxy(1,30);
            textcolor(LIGHTRED);
            printf("Please enter a valid age...");
            getch();
            gotoxy(1,30);
            printf("                                                         ");
            textcolor(YELLOW);
            gotoxy(18,11);
            printf("                                                            ");
            gotoxy(18,11);
            continue;
        }
        p_details.age=atoi(arr);
        if(p_details.age<0)
        {
            gotoxy(1,30);
        textcolor(LIGHTRED);
        printf("Please Input a valid Age");
        getch();
        textcolor(YELLOW);
        //gotoxy(1,30);
        printf("\r");
        printf("                                             ");
        gotoxy(18,11);
        printf("                  ");
        gotoxy(18,11);
        continue;
        }
            break;
    }

    printf("\n\rEnter your Address : ");
    fflush(stdin);
    fgets(p_details.address,30,stdin);
    char *p;
    p=strchr(p_details.train_no,'\n');
    if(p!=NULL)
        *p='\0';

        clrscr();
        return &p_details;
    }


int book_ticket(Passenger psn)
{
    int temp;
   temp=get_booked_ticket_count(psn.train_no,psn.p_class);
    if(temp==3)
    {
        textcolor(LIGHTGREEN);
        printf("All seats full in train %s in %c class",psn.train_no,psn.p_class);
        return -1;
    }
    int ticket;
    ticket=last_ticket_no();
    psn.ticketno=ticket+1;
    FILE *fp;
    fp=fopen("E:\\MyProjects\\code blocks project\\Railway Reservation System\\allbookings.dat","ab+");
    fwrite(&psn,sizeof(Passenger),1,fp);
    fclose(fp);
    return ticket+1;
}




int get_booked_ticket_count(char *train ,char cls)
{
    FILE *fp;
    Passenger p;
    int count=0;
    fp=fopen("E:\\MyProjects\\code blocks project\\Railway Reservation System\\allbookings.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }
    else
    {
        while(fread(&p,sizeof(Passenger),1,fp)==1)
        {
           if(strcmp(p.train_no,train)==0&&p.p_class==cls)
           {
               count++;
           }
        }
    }
    fclose(fp);
    return count;
}


int last_ticket_no()
{
    Passenger psn;
    FILE *fp;
    fp=fopen("E:\\MyProjects\\code blocks project\\Railway Reservation System\\allbookings.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }
    fseek(fp,0,SEEK_END);
    if(ftell(fp)==0)
    {
        fclose(fp);
        return 0;
    }
    fseek(fp,-1*sizeof(Passenger),SEEK_END);
    fread(&psn,sizeof(Passenger),1,fp);
    int last_ticket;
    last_ticket=psn.ticketno;
    fclose(fp);
    return last_ticket;
}


int accept_ticket_no()
{
    int ticket_number;
   printf("Enter ticket Number : ");
   while(1)
   {
       fflush(stdin);
       scanf("%d",&ticket_number);
       if(ticket_number==0)
       {
           break;
       }
        if(ticket_number<0)
        {
            gotoxy(1,30);
            textcolor(LIGHTRED);
            printf("Invalid Ticket No.");
            textcolor(YELLOW);
            getch();
            printf("\r");
            printf("                                      ");
            gotoxy(23,1);
            printf("                    ");
            gotoxy(23,1);
            continue;
        }
        else
        return ticket_number;
   }
   return 0;
}


void view_ticket(int ticket_no)
{
    Passenger psn;
    FILE *fp;
    fp=fopen("E:\\MyProjects\\code blocks project\\Railway Reservation System\\allbookings.dat","rb");
    FILE *at;
    at=fopen("E:\\MyProjects\\code blocks project\\Railway Reservation System\\alltrains.dat","rb");
    int flag=0;
    Train tr;
    while(fread(&psn,sizeof(Passenger),1,fp))
    {
        if(ticket_no==psn.ticketno)
        {
            flag=1;
            printf("Name : %s",psn.p_name);
            printf("\nAge : %d",psn.age);
            printf("\nMoblie No. : %s",psn.mob_no);
            printf("\nTrain No. : %s",psn.train_no);
            while(fread(&tr,sizeof(Train),1,at))
            {
                if(strcmp(psn.train_no,tr.train_no)==0)
                {
                    printf("\nFrom : %s",tr.from);
                    printf("\nTo : %s",tr.to);
                    printf("\nFirst AC Fare : %d",tr.fac_fare);
                    printf("\nSecond AC Fare : %d",tr.sac_fare);
                    break;
                }
            }
            printf("\nGender : %c",psn.gender);
            printf("\nReservation Class : %c",psn.p_class);
            printf("\nAddress : %s",psn.address);
            getch();
            break;
        }
    }
    if(flag==0)
    {
        gotoxy(1,30);
        textcolor(LIGHTRED);
        printf("Ticket Number Not Found!");
        textcolor(YELLOW);
        getch();
    }
    fclose(fp);
    fclose(at);
}


char * accept_mobile_no()
{
    printf("Enter your mobile number : ");
    while(1)
    {
        static char mob_no[11];
        fflush(stdin);
        fgets(mob_no,11,stdin);

        char *p;
        p=strchr(mob_no,'\n');
        if(p!=NULL)
            *p='\0';
            gotoxy(28,1);
            printf("                                    ");
            gotoxy(28,1);
            printf("%s",mob_no);
        if(strcmp(mob_no,"0")==0)
            {
                break;
            }
        if(strlen(mob_no)<10)
        {
            gotoxy(1,30);
            textcolor(LIGHTRED);
            printf("Please Input a valid Mobile Number");
            getch();
            textcolor(YELLOW);
            printf("\r");
            printf("                                     ");
            gotoxy(28,1);
            printf("                                     ");
            gotoxy(28,1);
            continue;
        }
        int i;
        int check=0;
        for(i=0;i<10;i++)
        {
            if(isdigit(mob_no[i])==0)
            {
                check=1;
            }
        }
        if(check==1)
        {
                   gotoxy(1,30);
            textcolor(LIGHTRED);
            printf("Please Input a valid Mobile Number");
            getch();
            textcolor(YELLOW);
            printf("\r");
            printf("                                     ");
            gotoxy(28,1);
            printf("                                     ");
            gotoxy(28,1);
            continue;
        }
        return mob_no;
    }
    return 0;
}

void get_ticket_no(char *mob_no)
{

        FILE *fp;
        int count=0;
        int flag=0;
        Passenger psn;
        fp=fopen("E:\\MyProjects\\code blocks project\\Railway Reservation System\\allbookings.dat","rb");
        gotoxy(1,2);
        while(fread(&psn,sizeof(psn),1,fp)==1)
        {

            if(strcmp(psn.mob_no,mob_no)==0)
            {
                count++;
                flag=1;
                printf("\nTicket No. %d is : %d  ",count,psn.ticketno);
            }
        }
        if(flag==0)
        {
            gotoxy(1,30);
            textcolor(LIGHTRED);
            printf("No record found for this mobile no.");
            textcolor(YELLOW);
            getch();
            fclose(fp);
            return;
        }
        gotoxy(1,2);
        printf("You have total %d bookings for the mobile no. %s",count,mob_no);
        gotoxy(1,count+3);
        getch();
        fclose(fp);
}



void view_all_bookings()
{
   clrscr();
   printf("Name\t\t\t");
   printf("Gender\t\t");
   printf("Age\t\t");
   printf("Mobile No.\t\t");
   printf("Train No.\t\t");
   printf("Ticket No.\n");
   FILE *fp;
   int count=1;
   Passenger psn;
   fp=fopen("E:\\MyProjects\\code blocks project\\Railway Reservation System\\allbookings.dat","rb");
   while(fread(&psn,sizeof(Passenger),1,fp))
   {
       count++;
       printf("%s",psn.p_name);
       gotoxy(27,count);
       printf("%c\t\t",psn.gender);
       printf("%d\t\t",psn.age);
       printf("%s\t\t",psn.mob_no);
       printf("%s\t\t\t    ",psn.train_no);
       printf("%d\n",psn.ticketno);
   }
   fclose(fp);
}




void view_bookings(char * train_no)
{
        FILE *fp;
    Passenger psn;
    int count=3;
    int flag=0;
    fp=fopen("E:\\MyProjects\\code blocks project\\Railway Reservation System\\allbookings.dat","rb");
   printf("\nName\t\t\t");
   printf("Gender\t\t");
   printf("Age\t\t");
   printf("Mobile No.\t\t");
   printf("Train No.\t\t");
   printf("Ticket No.\n");
    while(fread(&psn,sizeof(Passenger),1,fp))
    {
        if(strcmp(psn.train_no,train_no)==0)
        {
            flag=1;
            count++;
           printf("%s",psn.p_name);
           gotoxy(27,count);
           printf("%c\t\t",psn.gender);
           printf("%d\t\t",psn.age);
           printf("%s    \t\t",psn.mob_no);
           printf("%s\t\t\t   ",psn.train_no);
           printf("%d\n",psn.ticketno);
        }
    }
    if(flag==0)
    {
        gotoxy(1,30);
        textcolor(LIGHTGREEN);
        printf("No Bookings done in this train yet");
        textcolor(YELLOW);
    }
    else
    {
        textcolor(WHITE);
        printf("Press any key to continue ");
        textcolor(YELLOW);
    }
    fclose(fp);
    getch();

}



char * accept_train_no()
{
    static char train_no[10];
    printf("Enter train no. : ");
    while(1)
    {
    fflush(stdin);
    fgets(train_no,10,stdin);
    char *p;
    p=strchr(train_no,'\n');
    if(p!=NULL)
        *p='\0';
    if(strcmp(train_no,"0")==0)
    {
        break;
    }
    int r_train;
    r_train=check_train_no(train_no);
    if(r_train==1)
    {
        return train_no;
    }
    else
    {
        gotoxy(1,30);
        textcolor(LIGHTRED);
        printf("Please Input a valid Train Number");
        getch();
        textcolor(YELLOW);
        //gotoxy(1,30);
        printf("\r");
        printf("                                             ");
        gotoxy(19,1);
        printf("                                 ");
        gotoxy(19,1);
    }
    }
    return NULL;
}


int cancel_ticket(int ticket)
{
    FILE *fp,*t_file;
    Passenger psn;
    int flag=0;
    fp=fopen("E:\\MyProjects\\code blocks project\\Railway Reservation System\\allbookings.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }
    t_file=fopen("E:\\MyProjects\\code blocks project\\Railway Reservation System\\temp.dat","wb");
    while(fread(&psn,sizeof(Passenger),1,fp)==1)
    {
        if(ticket!=psn.ticketno)
        {
            //printf("rohit");
            fwrite(&psn,sizeof(Passenger),1,t_file);
        }
        else
        {
           flag=1;
        }
    }
            fclose(fp);
            fclose(t_file);
    if(flag==1)
    {
            //int value;
            remove("E:\\MyProjects\\code blocks project\\Railway Reservation System\\allbookings.dat");
            rename("E:\\MyProjects\\code blocks project\\Railway Reservation System\\temp.dat","E:\\MyProjects\\code blocks project\\Railway Reservation System\\allbookings.dat");
            //printf("%d",value);

            return 1;
    }
    else
        {
            remove("E:\\MyProjects\\code blocks project\\Railway Reservation System\\temp.dat");


              return -1;
        }
}


int cancel_train(char *train_no)
{
    FILE *fp,*t_file;
    Passenger psn;
    int flag=0;
    fp=fopen("E:\\MyProjects\\code blocks project\\Railway Reservation System\\allbookings.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }
    t_file=fopen("E:\\MyProjects\\code blocks project\\Railway Reservation System\\temp.dat","wb");
    while(fread(&psn,sizeof(Passenger),1,fp)==1)
    {
        if(strcmp(psn.train_no,train_no)!=0)
        {
            fwrite(&psn,sizeof(Passenger),1,t_file);
        }
        else
        {
           flag=1;
        }
    }
            fclose(fp);
            fclose(t_file);
    if(flag==1)
    {
            remove("E:\\MyProjects\\code blocks project\\Railway Reservation System\\allbookings.dat");
            rename("E:\\MyProjects\\code blocks project\\Railway Reservation System\\temp.dat","E:\\MyProjects\\code blocks project\\Railway Reservation System\\allbookings.dat");
            return 1;
    }
    else
        {
            remove("E:\\MyProjects\\code blocks project\\Railway Reservation System\\temp.dat");
            return 0;
        }
}








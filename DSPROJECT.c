#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include <time.h>


struct room{
    int room_number;
    char name[30];
    int age;
    char phone_number[10];
    char email[40];
    char nationality[20];
    int period;
    struct room *next;
};

struct r{
    int rn;
    struct r *next2;
};


struct room *start=NULL;
struct r *start_suite=NULL;
struct r *start_super_delux=NULL;
struct r *start_classic=NULL;
int avail_suite=5;
int avail_super_delux=5;
int avail_classic=5;

struct room *book_room(struct room *);
struct room *checkout(struct room *);
void search(struct room *);
void display(struct room *);
struct r *intialize_suite(struct r *);
struct r *intialize_super_delux(struct r *);
struct r *intialize_classic(struct r *);
struct r *add_suite(struct r *, int );
struct r *add_super_delux(struct r *, int);
struct r *add_classic(struct r *, int);
struct r *delete_suite(struct r *);
struct r *delete_super_delux(struct r *);
struct r *delete_classic(struct r *);
void greetings();
void main_menu();
void display1(struct r *);




int main(){
    start_suite=intialize_suite(start_suite);
    start_super_delux=intialize_super_delux(start_super_delux);
    start_classic=intialize_classic(start_classic);
    greetings();
    main_menu();
    return 0;
}

void greetings(){
    system("COLOR 1F");
    printf("\t\t -------------------------------------------------------------------------\n");
	printf("\t\t|                                                                         |\n");
	printf("\t\t|                                                                         |\n");
	printf("\t\t|  OOOOOO   OOOOOO OOOOOO OOOOOO OOOOOO OOOOOO O      O OOOOOOO  OOOOOO   |\n");
	printf("\t\t|  O        O    O O      O        O      O    O O    O O        O        |\n");
	printf("\t\t|  O  OOOOO OOOOOO OOOOO  OOOOO    O      O    O  O   O O  OOOOO OOOOOO   |\n");
	printf("\t\t|  O    O   O  O   O      O        O      O    O   O  O O    O        O   |\n");
	printf("\t\t|  OOOOOO   O   O  OOOOOO OOOOOO   O    OOOOOO O    O O OOOOOO   OOOOOO   |\n");
	printf("\t\t|                                                                         |\n");
	printf("\t\t--------------------------------------------------------------------------\n");
	printf("\t\t\t     *************************************************\n");
	printf("\t\t\t     *                                               *\n");
	printf("\t\t\t     *       -----------------------------           *\n");
	printf("\t\t\t     *        WELCOME TO HOTEL LAS PACIFIC           *\n");
	printf("\t\t\t     *       -----------------------------           *\n");
	printf("\t\t\t     *  THE ART OF MEETING YOUR HIGHEST EXPECTATION  *\n");
	printf("\t\t\t     *                                               *\n");
	printf("\t\t\t     *                                               *\n");
	printf("\t\t\t     *             Bandra(w),Mumbai.                 *\n");
	printf("\t\t\t     *                  INDIA                        *\n");
	printf("\t\t\t     *      CONTACT US:8080408783,0610423280         *\n");
	printf("\t\t\t     *************************************************\n\n\n");
    time_t current_time = time(NULL);
    struct tm *tm = localtime(&current_time);
    printf("%s\n", asctime(tm));
	printf(" \n Press any key to continue:");
	getch();
    system("cls");
}

void main_menu(){
    int option;
    do{
    system("COLOR 1F");
    printf("\t\t****************************************************************************\n");
    printf("\t\t*                                MAIN MENU                                 *  \n");
    printf("\t\t****************************************************************************\n");
    printf("\t\t*\t\t1.BOOK A ROOM                                              *\n");
    printf("\t\t*\t\t2.CHECKOUT                                                 *\n");
    printf("\t\t*\t\t3.SEARCH DETAILS                                           *\n");
    printf("\t\t*\t\t4.DISPLAY DETAILS                                          *\n");
    printf("\t\t*\t\t5.EXIT                                                     *\n");
    printf("\t\t*__________________________________________________________________________*\n");
    printf("\nEnter your option: ");
    scanf("%d",&option);
    switch(option){
        case 1: system("cls");
                start=book_room(start);
                break;
        case 2: system("cls");
                start=checkout(start);
                break;
        case 3: system("cls");
                search(start);
                break;
        case 4: system("cls");
                display(start);
                break;
        case 5: exit(1);

        default: printf("\nInvalid option!");
                 printf("...........Press any key to try again");
                 getch();
                 system("cls");
    }
    }while(option!=5);
}

struct room *book_room(struct room *start){
    struct room *new_room,*ptr;
    int option2;
    system("COLOR 1F");
    mm:
    printf(" ________________________________________________________________________________________________________________\n");
    printf("| SR.NO\t|\tROOM TYPE\t|\tTOTAL\t\t|\tAVAILABLE\t|\tPRICE PER NIGHT(Rs)      |\n");
    printf("|________________________________________________________________________________________________________________|\n");
    printf("| 1.\t|\tSUITE\t\t|\t5\t\t|\t%d\t\t|\t10000                    |\n",avail_suite);
    printf("| 2.\t|\tSUPER DELUX\t|\t5\t\t|\t%d\t\t|\t8000                     |\n",avail_super_delux);
    printf("| 3.\t|\tCLASSIC\t\t|\t5\t\t|\t%d\t\t|\t5000                     |\n",avail_classic);
    printf("| 4.MAIN MENU                                                                                                    |\n");
    printf("|________________________________________________________________________________________________________________|\n");
    printf("What room do you want?\t");
    scanf("%d",&option2);
    switch(option2){
        case 1:{ if(avail_suite==0){
                    printf("Sorry, but currently no SUITES available!\n ");
                    printf("Press any key to try again.....");
                    getch();
                    system("cls");
                    goto mm;
                }
                else{
                    system("cls");
                    printf("_____________________________________________________________________________\n");
                    printf("                              BOOKING FOR A SUITE                            \n");
                    printf("_____________________________________________________________________________\n");
                    new_room=(struct room *)malloc(sizeof(struct room));
                    printf("Enter your name: ");
                    scanf("%s",new_room->name);
                    printf("\nEnter your age: ");
                    scanf("%d",&new_room->age);
                    printf("\nEnter your Nationality: ");
                    scanf("%s",new_room->nationality);
                    printf("\nEnter your phone no. : ");
                    scanf("%s",new_room->phone_number);
                    printf("\nEnter your email: ");
                    scanf("%s",new_room->email);
                    printf("\nEnter stay period(in number of days): ");
                    scanf("%d",&new_room->period);
                    new_room->room_number=start_suite->rn;
                    printf("\nRoom number alloted: %d",new_room->room_number);
                    printf("\n_____________________________________________________________________________\n");
                    time_t current_time = time(NULL);
                    struct tm *tm = localtime(&current_time);
                    printf("\n\n%s\n", asctime(tm));
                    printf("ALLOCATION DONE SUCCESSFULLY!\n");
                    start_suite=delete_suite(start_suite);
                    new_room->next=NULL;
                    if(start==NULL){
                        start=new_room;
                    }
                    else{
                        ptr=start;
                        while(ptr->next!=NULL){
                            ptr=ptr->next;
                        }
                        ptr->next=new_room;
                    }
                }
                printf("\n\n.......Press any key to return to main menu");
                getch();
                system("cls");
                break;

                }
        case 2: {if(avail_super_delux==0){
                    printf("Sorry, but currently no SUPER DELUX ROOMS available!\n ");
                    printf("Press any key to try again.....");
                    getch();
                    system("cls");
                    goto mm;
                }
                else{
                    system("cls");
                    printf("_____________________________________________________________________________\n");
                    printf("                        BOOKING FOR A SUPER DELUX ROOM                       \n");
                    printf("_____________________________________________________________________________\n");
                    new_room=(struct room *)malloc(sizeof(struct room));
                    printf("Enter your name: ");
                    scanf("%s",new_room->name);
                    printf("\nEnter your age: ");
                    scanf("%d",&new_room->age);
                    printf("\nEnter your Nationality: ");
                    scanf("%s",new_room->nationality);
                    printf("\nEnter your phone no. : ");
                    scanf("%s",new_room->phone_number);
                    printf("\nEnter your email: ");
                    scanf("%s",new_room->email);
                    printf("\nEnter stay period(in number of days): ");
                    scanf("%d",&new_room->period);
                    new_room->room_number=start_super_delux->rn;
                    start_super_delux=delete_super_delux(start_super_delux);
                    printf("\nRoom number alloted: %d",new_room->room_number);
                    printf("\n_____________________________________________________________________________\n");
                    time_t current_time = time(NULL);
                    struct tm *tm = localtime(&current_time);
                    printf("\n\n%s\n", asctime(tm));
                    printf("\nALLOCATION DONE SUCCESSFULLY!\n");
                    new_room->next=NULL;
                    if(start==NULL){
                        start=new_room;
                    }
                    else{
                        ptr=start;
                        while(ptr->next!=NULL){
                            ptr=ptr->next;
                        }
                        ptr->next=new_room;
                    }
                }
                printf("Press any key to try again.....");
                getch();
                system("cls");
                break;
                }
        case 3: {if(avail_classic==0){
                    printf("Sorry, but currently no CLASSIC ROOMS available!\n ");
                    printf("\n\n.......Press any key to return to main menu");
                    getch();
                    system("cls");
                    goto mm;
                }
                else{
                    system("cls");
                    printf("_____________________________________________________________________________\n");
                    printf("                           BOOKING FOR A CLASSIC ROOM                        \n");
                    printf("_____________________________________________________________________________\n");
                    new_room=(struct room *)malloc(sizeof(struct room));
                    printf("Enter your name: ");
                    scanf("%s",new_room->name);
                    printf("\nEnter your age: ");
                    scanf("%d",&new_room->age);
                    printf("\nEnter your Nationality: ");
                    scanf("%s",new_room->nationality);
                    printf("\nEnter your phone no. : ");
                    scanf("%s",new_room->phone_number);
                    printf("\nEnter your email: ");
                    scanf("%s",new_room->email);
                    printf("\nEnter stay period(in number of days): ");
                    scanf("%d",&new_room->period);
                    new_room->room_number=start_classic->rn;
                    start_classic=delete_classic(start_classic);
                    printf("\nRoom number alloted: %d",new_room->room_number);
                    printf("\n_____________________________________________________________________________\n");
                    time_t current_time = time(NULL);
                    struct tm *tm = localtime(&current_time);
                    printf("\n\n%s\n", asctime(tm));
                    printf("\nALLOCATION DONE SUCCESSFULLY!\n");
                    new_room->next=NULL;
                    if(start==NULL){
                        start=new_room;
                    }
                    else{
                        ptr=start;
                        while(ptr->next!=NULL){
                            ptr=ptr->next;
                        }
                        ptr->next=new_room;
                    }
                }
                printf("\n\n.......Press any key to return to main menu");
                getch();
                system("cls");
                break;
                }
        case 4:{system("cls");
                main_menu();
                }
        default:{
                printf("Invalid option!");
                printf("\n\n.......Press any key to return to main menu");
                getch();
                system("cls");
                goto mm;}

    }

    return start;
}

struct room *checkout(struct room *start){
    struct room *ptr;
    int amt;
    if(start==NULL){
        printf("\nNo rooms have been allocated yet ");
        printf("\n\n\n............Press any key to go to main menu.");
        getch();
        system("cls");
        main_menu();
    }
    else{
        ptr=start;
        if(ptr->room_number>100 && ptr->room_number<200){
            amt=10000;
            start_suite=add_suite(start_suite,ptr->room_number);
        }
        else if(ptr->room_number>200 && ptr->room_number<300){
            amt=8000;
            start_super_delux=add_super_delux(start_super_delux,ptr->room_number);
        }
        else if(ptr->room_number>300 && ptr->room_number<400){
            amt=5000;
            start_classic=add_classic(start_classic,ptr->room_number);
        }
        printf("****************************************************************************\n");
        printf("                                CHECK OUT                                   \n");
        printf("****************************************************************************");
        printf("\nROOM NUMBER : %d",ptr->room_number);
        printf("\nNAME        : %s",ptr->name);
        printf("\nAGE         : %d",ptr->age);
        printf("\nPHONE NUMBER: %s",ptr->phone_number);
        printf("\nEMAIL       : %s",ptr->email);
        printf("\nNATIONALITY : %s",ptr->nationality);
        printf("\nPERIOD      : %d",ptr->period);
        printf("\nTOTAL AMOUNT: %d",ptr->period*amt);
        printf("\n______________________________________________________________________________");
        printf("\nThank you for choosing LAS PACIFIC, we hope you've had a great stay !");
        start=start->next;
        free(ptr);
        }
    printf("\n\n................Press any key to continue to the main menu");
    getch();
    system("cls");
    return start;
}

void search(struct room *start){
    struct room *ptr;
    int rn,flag=0;
    printf("****************************************************************************\n");
    printf("                             SEARCH DETAILS                                 \n");
    printf("****************************************************************************\n");
    printf("Enter the room number you want to search for: ");
    scanf("%d",&rn);
    ptr=start;
    while(ptr!=NULL){
            if(ptr->room_number==rn){
                flag=1;
                break;
            }
            else{
                flag=0;
            }
            ptr=ptr->next;
    }
    if(flag==0){
        printf("\nSorry, room doesn't exist");
        printf("\n\n......Press any key to go to the main menu");
        getch();
        system("cls");
        main_menu();
    }
    else{
        printf("\n______________________________________________________________________________");
        printf("\nGUEST DETAILS OF ROOM NUMBER %d",rn);
        printf("\n______________________________________________________________________________");
        printf("\nNAME        : %s",ptr->name);
        printf("\nAGE         : %d",ptr->age);
        printf("\nPHONE NUMBER: %s",ptr->phone_number);
        printf("\nEMAIL       : %s",ptr->email);
        printf("\nNATIONALITY : %s",ptr->nationality);
        printf("\nPERIOD      : %d",ptr->period);
        printf("\n______________________________________________________________________________");
        printf("\n\n......Press any key to go to the main menu");
        getch();
        system("cls");
    }

}

void display(struct room *start){
    struct room *ptr;
    int i=1;
    printf("****************************************************************************\n");
    printf("*                                DETAILS                                   *\n");
    printf("****************************************************************************\n");

    if(start==NULL){
        printf("\nNO ROOMS HAVE BEEN ALLOCATED YET! ");
        printf("\n\n......Press any key to go to the Main Menu.");
        getch();
        system("cls");
        main_menu();
    }
    else{
        ptr=start;
        while(ptr!=NULL){
        printf("\n\n============================================================================");
        printf("\n                           *** GUEST %d  ***",i);
        printf("\n____________________________________________________________________________");
        printf("\nROOM NUMBER : %d",ptr->room_number);
        printf("\nNAME        : %s",ptr->name);
        printf("\nAGE         : %d",ptr->age);
        printf("\nPHONE NUMBER: %s",ptr->phone_number);
        printf("\nEMAIL       : %s",ptr->email);
        printf("\nNATIONALITY : %s",ptr->nationality);
        printf("\nPERIOD      : %d",ptr->period);
        printf("\n============================================================================\n");
        i++;
        ptr=ptr->next;
        }
        printf("\n\n........Press any key to go to the Main Menu");
        getch();
        system("cls");
    }

}


struct r *intialize_suite(struct r *start_suite){

    struct r *new_suite,*ptr;
    int i;

    for(i=0;i<5;i++){
        new_suite=(struct r *)malloc(sizeof(struct r));
        if(start_suite==NULL){
            new_suite->rn=101;
            new_suite->next2=NULL;
            start_suite=new_suite;
        }
        else{
             ptr=start_suite;
            while(ptr->next2!=NULL)
            {
                ptr=ptr->next2;
            }
            ptr->next2=new_suite;
            new_suite->rn=101+i;
            new_suite->next2=NULL;
        }
    }
    return start_suite;
}


struct r *intialize_super_delux(struct r *start_super_delux){
    struct r *new_super_delux,*ptr;
    int i;

    for(i=0;i<5;i++){
        new_super_delux=(struct r *)malloc(sizeof(struct r));
        if(start_super_delux==NULL){
            new_super_delux->rn=201;
            new_super_delux->next2=NULL;
            start_super_delux=new_super_delux;
        }
        else{
             ptr=start_super_delux;
            while(ptr->next2!=NULL)
            {
                ptr=ptr->next2;
            }
            ptr->next2=new_super_delux;
            new_super_delux->rn=201+i;
            new_super_delux->next2=NULL;
        }
    }
    return start_super_delux;
}

struct r *intialize_classic(struct r *start_classic){
    struct r *new_classic,*ptr;
    int i;

    for(i=0;i<5;i++){
        new_classic=(struct r *)malloc(sizeof(struct r));
        if(start_classic==NULL){
            new_classic->rn=301;
            new_classic->next2=NULL;
            start_classic=new_classic;
        }
        else{
             ptr=start_classic;
            while(ptr->next2!=NULL)
            {
                ptr=ptr->next2;
            }
            ptr->next2=new_classic;
            new_classic->rn=301+i;
            new_classic->next2=NULL;
        }
    }
    return start_classic;
}

struct r *add_suite(struct r *start_suite, int id){
    struct r *new_suite,*ptr;
    if(start_suite==NULL){
        new_suite=(struct r *)malloc(sizeof(struct r));
        new_suite->rn=id;
        new_suite->next2=NULL;
        start_suite=new_suite;
        avail_suite++;
    }
    else{
        ptr=start_suite;
        while(ptr->next2!=NULL){
            ptr=ptr->next2;
        }
        new_suite=(struct r *)malloc(sizeof(struct r));
        new_suite->rn=id;
        new_suite->next2=NULL;
        avail_suite++;
    }
    return start_suite;
}

struct r *delete_suite(struct r *start_suite){
    struct r *ptr;
    ptr=start_suite;
    start_suite=start_suite->next2;
    free(ptr);
    avail_suite--;
    return start_suite;
}

struct r *add_super_delux(struct r *start_super_delux,int id){
    struct r *new_super_delux,*ptr;
    if(start_super_delux==NULL){
        new_super_delux=(struct r *)malloc(sizeof(struct r));
        new_super_delux->rn=id;
        new_super_delux->next2=NULL;
        start_super_delux=new_super_delux;
        avail_super_delux++;
    }
    else{
        ptr=start_super_delux;
        while(ptr->next2!=NULL){
            ptr=ptr->next2;
        }
        new_super_delux=(struct r *)malloc(sizeof(struct r));
        new_super_delux->rn=id;
        new_super_delux->next2=NULL;
        avail_super_delux++;
    }
    return start_super_delux;
}

struct r *delete_super_delux(struct r *start_super_delux){
    struct r *ptr;
    ptr=start_super_delux;
    start_super_delux=start_super_delux->next2;
    free(ptr);
    avail_super_delux--;
    return start_super_delux;
}

struct r *add_classic(struct r *start_classic, int id){
    struct r *new_classic,*ptr;
    if(start_classic==NULL){
        new_classic=(struct r *)malloc(sizeof(struct r));
        new_classic->rn=id;
        new_classic->next2=NULL;
        start_classic=new_classic;
        avail_classic++;
    }
    else{
        ptr=start_classic;
        while(ptr->next2!=NULL){
            ptr=ptr->next2;
        }
        new_classic=(struct r *)malloc(sizeof(struct r));
        new_classic->rn=id;
        new_classic->next2=NULL;
        avail_classic++;
    }
    return start_classic;
}

struct r *delete_classic(struct r *start_classic){
    struct r *ptr;
    ptr=start_classic;
    start_classic=start_classic->next2;
    free(ptr);
    avail_classic--;
    return start_classic;
}

void display1(struct r *start_suite){
    struct r *ptr;
    ptr= start_suite;
    while(ptr!=NULL){
            printf("%d  ",ptr->rn);
            ptr=ptr->next2;
    }
}

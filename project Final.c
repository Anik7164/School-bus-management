#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
    char name[40];
    char id_no[30];
    char batch[20];
    char dept_name[20];
    char stopping[20];
    int bus_no;
}
passdetails;

void viewdetails(void);
void reservation(void);
void buspass(char name[], char id_no[], char batch[], char dept_name[], char stopping[], int bus_no);
void specificbus(int, char stopping[], FILE*);


int main()
{
    while(1)
    {
        int choice;
        printf("\t\t\t\t\t__________Welcome__________\n");
        printf("\t\t\t\t\t____________To_____________\n");
        printf("\t\t\t\t\t______Bus Transportation___\n");
        printf("\n\n 1. View All Available Buses \n");
        printf(" 2. Reserve A Seat\n");
        printf(" 3. Exit\n");
        printf("Select any number:\n");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            viewdetails();
            printf("Press any key to go to main menu--->\n");
            break;

        case 2:
            reservation();
            break;

        case 3:
            return (0);

        default:
            printf("Invalid choice");

        }

    }
}

void viewdetails()
{
    system("class");

    printf("\t-------------------------------------------------------------------------------------------------\n");
    printf("\t|BUS_NO\t BUS_NAME\t BUS_CAPACITY\t DESTINATION\t STOPPING\t\t PER_TICKET FEE\t\t DEPARTURE_TIME|n\n");
    printf("\t-------------------------------------------------------------------------------------------------\n");
    printf("\t| 1. BUS     A\t        50\t        X to Y\t\     a) Y\t\t        TK.800\t\t         7:00 a.m   |\n");
    printf("\t-------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t                      \t                      b)M\t\t         TK.780\t\t         8:25 a.m   |\n");
    printf("\t-------------------------------------------------------------------------------------------------\t");

    printf("\t-------------------------------------------------------------------------------------------------\n");
    printf("\t|BUS_NO\t BUS_NAME\t BUS_CAPACITY\t DESTINATION\t STOPPING\t\t PER_TICKET FEE\t\t DEPARTURE_TIME|n\n");
    printf("\t-------------------------------------------------------------------------------------------------\n");
    printf("\t| 2. BUS     B\t        50\t        R to T\t\     a) T\t\t        TK.800\t\t         8:00 a.m   |\n");
    printf("\t-------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t                      \t                      b)W\t\t         TK.780\t\t         8:25 a.m   |\n");
    printf("\t-------------------------------------------------------------------------------------------------\t");

    printf("\t-------------------------------------------------------------------------------------------------\n");
    printf("\t|BUS_NO\t BUS_NAME\t BUS_CAPACITY\t DESTINATION\t STOPPING\t\t PER_TICKET FEE\t\t DEPARTURE_TIME|n\n");
    printf("\t-------------------------------------------------------------------------------------------------\n");
    printf("\t| 3. BUS     C\t        50\t        G to H\t\     a) H\t\t        TK.800\t\t         8:10 a.m   |\n");
    printf("\t-------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t                      \t                      b)V\t\t         TK.780\t\t         8:15 a.m   |\n");
    printf("\t-------------------------------------------------------------------------------------------------\t");


    printf("\t-------------------------------------------------------------------------------------------------\n");
    printf("\t|BUS_NO\t BUS_NAME\t BUS_CAPACITY\t DESTINATION\t STOPPING\t\t PER_TICKET FEE\t\t DEPARTURE_TIME|n\n");
    printf("\t-------------------------------------------------------------------------------------------------\n");
    printf("\t| 4. BUS     D\t        50\t        N to O\t\     a) N\t\t        TK.800\t\t         8:30 a.m   |\n");
    printf("\t-------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t                      \t                      b)J\t\t         TK.780\t\t         8:45 a.m   |\n");
    printf("\t-------------------------------------------------------------------------------------------------\t");

    printf("\t-------------------------------------------------------------------------------------------------\n");
    printf("\t|BUS_NO\t BUS_NAME\t BUS_CAPACITY\t DESTINATION\t STOPPING\t\t PER_TICKET FEE\t\t DEPARTURE_TIME|n\n");
    printf("\t-------------------------------------------------------------------------------------------------\n");
    printf("\t| 5. BUS     E\t        50\t        F to K\t\     a) K\t\t        TK.800\t\t         8:35 a.m   |\n");
    printf("\t-------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t                      \t                      b)T\t\t         TK.780\t\t         8:40 a.m   |\n");
    printf("\t-------------------------------------------------------------------------------------------------\t");

    getch();

}

void reservation()
{
    system("class") ;
    printf("Enter your name: \n");
    scanf("%s", passdetails.name);
    printf("Enter your id number: \n");
    scanf("%s", passdetails.id_no);
    printf("Enter batch:\n");
    scanf("%s", passdetails.batch);
    printf("Enter department name:\n");
    scanf("%s", passdetails.dept_name);
    printf("Press enter to view available buses \n");

    getch();

    system("class");
    viewdetails();

    printf("\n Enter bus number:\n");
    scanf("%d", &passdetails.bus_no);
    printf("Enter stopping\n");
    scanf("%s", passdetails.stopping);

    if((passdetails.bus_no >=1) && (passdetails.bus_no <=5))
    {
        if((passdetails.stopping[0]>='a' && (passdetails.stopping[0])<='b'))
        {
            printf("\t*************************\n");
            printf("\t|   SEAT CONFRIMED      |\n");
            printf("\t------------------------\n");
            printf("\t|REGISTRATION SUCCESSFUL|\n");
            printf("\t------------------------|\n");
            printf("\t PRESS ANY KEY TO GO TO THE MAIN MENU \n");
        }
        else
        {
            printf("This stoppong is not available. Select appropriate stopping\n");
        }
    }
    else
    {
        printf("That bus is not available. Select appropriate bus number\n");
        printf("This stopping is not available in this bus\n");
    }

    buspass(passdetails.name, passdetails.id_no, passdetails.batch, passdetails.dept_name, passdetails.stopping, passdetails.bus_no);

    getch();
}

void buspass(char name[], char id_no[], char batch[], char dept_name[],char stopping[], int bus_no)

{
    FILE *fptr;
    char fname[]="buspass";
    strcat(fname, id_no);
    strcat(fname, ".txt");

    fptr= fopen(fname, "w");


    fprintf(fptr, "\n---------------------------------\n");
    fprintf(fptr, "\t\t BUS PASS\n");
    fprintf(fptr, "\n----------------------------------\n");
    fprintf(fptr, "NAME\t\t\t:\t%s\n", name);
    fprintf(fptr, "ID NUMBER\t:%s\n", id_no);
    fprintf(fptr, "BATCH\t\t\t:\t%s\n", batch);
    fprintf(fptr, "DEPARTMENT NAME\t:\t%s\n", dept_name);
    fprintf(fptr, "BUS NUMBER\t\t:%s\n", bus_no);

    specificbus(bus_no,stopping,fptr);

}
void specificbus(int bus_no,char stopping[],FILE *fptr)
{


    if (bus_no==1)
    {


        fprintf(fptr, "BUS\t\t\t\t: \tBUS A\t\n");
        fprintf(fptr, "DESTINATION\t\t\tRaptadu To JNTUA\t\n");
        if(strcmp("a", stopping)==0)
        {
            fprintf(fptr, "Stopping\t\t: \tRaptadu\n");
            fprintf(fptr, "DEPARTURE TIME\t: \t8:30\t\n");
            fprintf(fptr, "YEARLYFEE\t\t: \t8000\n");
        }
        if (strcmp("b", stopping)==0)

        {

            fprintf(fptr, "Stopping\t\t: \tSrinagar blony\n");
            fprintf(fptr, "DEPARTURE TIME\t: \t8:40\t\n");
            fprintf(fptr, "YEARLYFEE \t\t: \t7500\n");

        }
        if (strcmp("c", stopping)==0)

        {
            fprintf(fptr, "Stopping\t\t: \tTaraknath Colony\n");

            fprintf(fptr, "DEPARTURE TIME\t: \t8:45\t\n");
            fprintf(fptr, "YEARLYFEE\t\t: \t7000\n");
        }
        if (strcmp("d", stopping)==0)

        {
            fprintf(fptr, " |ing|t|t : \tGangamma Temple\n");
            fprintf(fptr, "DEPARTURE TIME\t: \t8:50\t\n");
            fprintf(fptr, "YEARLYFEE\t\t:\t6500\n");
        }
        if (strcmp("e", stopping)==0)

        {
            fprintf(fptr, "Stopping\t\t:\tunicipal Park\n");
            fprintf(fptr, "DEPARTURE TIME\t:\t8:55 \t \n ") ;
            fprintf(fptr, "YEARLYFEE\t\t: \t6000\n");
        }
        if(bus_no==2)
        {
            fprintf(fptr,"BUS\t\t\t\t\tBUS B\t\n") ;
            fprintf(fptr, "DESTINATION\t\t: \tkodimi To y") ;
        }
        if(strcmp("a", stopping)==0)

        {
            fprintf(fptr, "Stopping\t\t:\tkodimi \n");
            fprintf(fptr, "DEPARTURE TIME\t: \t8:15\t\n");
            fprintf(fptr, "YEARLYFEE\t\t: \t8000\n");
        }

        if (strcmp("b", stopping)==0)
        {


            fprintf(fptr, "Stopping\t\t: \tPilligunta\n");
            fprintf(fptr, "DEPARTURE TIME\t: \t8:30\t\n");
            fprintf(fptr, "YEARLYFEE\t\t: \t7500\n");

        }
        if (strcmp("c", stopping)==0)
        {
            fprintf(fptr, "Stopping\t\t: \tKamala Nagar\n");
            fprintf(fptr, "DEPARTURE TIMENT:\t8:45\t\n");
            fprintf(fptr, "YEARLYFEE\t\t:\t7000\n");
        }
        if (strcmp("d", stopping)==0)

        {
            fprintf(fptr, "Stopping\t\t: \tSanjeevaray Garden\n");
            fprintf(fptr, "DEPARTURE TIME\t: \t8:50\t\n");
            fprintf(fptr, "YEARLYFEE\t\t: \t6500\n");
        }
        if(strcmp("e",stopping)==0)
        {

            printf(fptr,"Stopping\t\t:\t                \n");
            printf(fptr,"Departure time\t:\t8.55\t\n");
            printf(fptr,"yearly fee\t\t:\t6000\n");
        }
    }
    if(bus_no==3)
    {
        printf(fptr,"Bus \t\t\t\t:\tBus C\t\n");
        printf(fptr,"Destination\t\t:\tKhilgaonTo NSU\t\n");

        if(strcmp("a",stopping)==0)
        {

            printf(fptr,"Stopping\t\t:\t Banasree\n");
            printf(fptr,"Departure time\t:\t8.15\t\n");
            printf(fptr,"yearly fee\t\t:\t6000\n");
        }

        if(strcmp("b",stopping)==0)
        {

            printf(fptr,"Stopping\t\t:\tRampura\n");
            printf(fptr,"Departure time\t:\t8.25\t\n");
            printf(fptr,"yearly fee\t\t:\t6000\n");
        }

        if(strcmp("c",stopping)==0)
        {

            printf(fptr,"Stopping\t\t:\tBadda\n");
            printf(fptr,"Departure time\t:\t8.35\t\n");
            printf(fptr,"yearly fee\t\t:\t6000\n");
        }

        if(strcmp("d",stopping)==0)
        {

            printf(fptr,"Stopping\t\t:\tBasabo\n");
            printf(fptr,"Departure time\t:\t8.45\t\n");
            printf(fptr,"yearly fee\t\t:\t6000\n");
        }

        if(strcmp("e",stopping)==0)
        {

            printf(fptr,"Stopping\t\t:\tHajipara\n");
            printf(fptr,"Departure time\t:\t8.55\t\n");
            printf(fptr,"yearly fee\t\t:\t6000\n");
        }
    }
    if(bus_no==4)
    {
        printf(fptr,"Bus \t\t\t\t:\tBus C\t\n");
        printf(fptr,"Destination\t\t:\t DhanmondiTo NSU\t\n");

        if(strcmp("a",stopping)==0)
        {

            printf(fptr,"Stopping\t\t:\tHajaripara\n");
            printf(fptr,"Departure time\t:\t8.15\t\n");
            printf(fptr,"yearly fee\t\t:\t6000\n");
        }

        if(strcmp("b",stopping)==0)
        {

            printf(fptr,"Stopping\t\t:\tKolabagan\n");
            printf(fptr,"Departure time\t:\t8.25\t\n");
            printf(fptr,"yearly fee\t\t:\t6000\n");
        }

        if(strcmp("c",stopping)==0)
        {

            printf(fptr,"Stopping\t\t:\tRayerbazar\n");
            printf(fptr,"Departure time\t:\t8.35\t\n");
            printf(fptr,"yearly fee\t\t:\t6000\n");
        }

        if(strcmp("d",stopping)==0)
        {

            printf(fptr,"Stopping\t\t:\tElephentroad\n");
            printf(fptr,"Departure time\t:\t8.45\t\n");
            printf(fptr,"yearly fee\t\t:\t6000\n");
        }

        if(strcmp("e",stopping)==0)
        {

            printf(fptr,"Stopping\t\t:\tNewmarket\n");
            printf(fptr,"Departure time\t:\t8.55\t\n");
            printf(fptr,"yearly fee\t\t:\t6000\n");
        }
    }
    if(bus_no==5)
    {
        printf(fptr,"Bus \t\t\t\t:\tBus C\t\n");
        printf(fptr,"Destination\t\t:\t Motijhil To NSU\t\n");

        if(strcmp("a",stopping)==0)
        {

            printf(fptr,"Stopping\t\t:\tKakrail\n");
            printf(fptr,"Departure time\t:\t8.15\t\n");
            printf(fptr,"yearly fee\t\t:\t6000\n");
        }

        if(strcmp("b",stopping)==0)
        {

            printf(fptr,"Stopping\t\t:\tShanti nagar\n");
            printf(fptr,"Departure time\t:\t8.25\t\n");
            printf(fptr,"yearly fee\t\t:\t6000\n");
        }

        if(strcmp("c",stopping)==0)
        {

            printf(fptr,"Stopping\t\t:\tArambagh\n");
            printf(fptr,"Departure time\t:\t8.35\t\n");
            printf(fptr,"yearly fee\t\t:\t6000\n");
        }

        if(strcmp("d",stopping)==0)
        {

            printf(fptr,"Stopping\t\t:\tKamlapur\n");
            printf(fptr,"Departure time\t:\t8.45\t\n");
            printf(fptr,"yearly fee\t\t:\t6000\n");
        }

        if(strcmp("e",stopping)==0)
        {

            printf(fptr,"Stopping\t\t:\tNayapaltan\n");
            printf(fptr,"Departure time\t:\t8.55\t\n");
            printf(fptr,"yearly fee\t\t:\t6000\n");
        }
    }
}

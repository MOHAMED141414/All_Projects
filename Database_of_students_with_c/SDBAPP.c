#include "SDB.h"
#include "STD.h"
#include <stdio.h>
void SDB_APP ()
{
    uint8 num;
    printf("********AMIT_STUDENT********\n");
    printf("To add entry, enter 1\n");
    printf("To get used size in database, enter 2\n");
    printf("To read student data, enter 3\n");
    printf("To get the list of all student IDs, enter 4\n");
    printf("To check is ID is existed, enter 5\n");
    printf("To delete student data, enter 6\n");
    printf("To check is database is full, enter 7\n");
    printf("To exit enter 0\n");
    printf("Enter Choice:");
    scanf("%d",&num);
    system("CLS");
    SDB_action(num);
}
void SDB_action (uint8 choice)
{
    uint32 re_id;
    uint8 cou_ptr;
    uint32* l_ptr[Max_std];
    uint32 i;
    uint32 ifidexist;
    uint32 delet;
    switch (choice)
    {
    case 0:
        exit(0);
        break;
    case 1:
        if ((SDB_AddEntry()))
            printf("Error, DataBase is full\n");
        else
            printf("Done\n");
        break;
    case 2:
        printf("Size of DataBase: %d\n",SDB_GetUsedSize());
        break;
    case 3:
        printf("Enter The Id Needed:");
        scanf("%d",&re_id);
        if (SDB_ReadEntry(re_id))
            printf("Not Found\n");
        else
            printf("Found\n");
        break;
    case 4:
        SDB_GetList(&cou_ptr,&l_ptr);
        printf("The list is:");
        for (i=0;i<cou_ptr;i++)
        {
         printf("[%d] ",DataBase[i].Student_ID);
        }
        break;
    case 5:
        printf("Enter The Id Needed:");
        scanf("%d",&ifidexist);
        if (SDB_IsIdExist(ifidexist))
            printf("Not Found\n");
        else
            printf("Found\n");
        break;
    case 6:
        printf("Enter The Id Need to be Deleted:");
        scanf("%d",&delet);
        SDB_DeletEntry(delet);
        break;
    case 7:
        if(SDB_IsFull())
            printf("DataBase is full\n");
        else
            printf("Not Full, Add Student\n");
        break;
    default :
        printf("Wrong Entry \n");
    }
    printf("\n");
    SDB_APP();
}

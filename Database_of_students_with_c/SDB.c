#include "STD.h"
#include "SDB.h"
#define Max_std 10
#define Min_std 3
student DataBase[Max_std];
static uint32 std_cou=0;
bool SDB_IsFull ()
{
    return  std_cou == Max_std;
}
uint8 SDB_GetUsedSize()
{
    return std_cou;
}
bool SDB_AddEntry()
{
    student n_std;
    if (SDB_IsFull())
    return false;
    else
    {
        printf("ID:");
        scanf("%d",&n_std.Student_ID);
        printf("Year:");
        scanf("%d",&n_std.Student_year);
        printf("Course1_ID:");
        scanf("%d",&n_std.Course1_ID);
        printf("Course1_grade:");
        scanf("%d",&n_std.Course1_grade);
        printf("Course2_ID:");
        scanf("%d",&n_std.Course2_ID);
        printf("Course2_grade:");
        scanf("%d",&n_std.Course2_grade);
        printf("Course3_ID:");
        scanf("%d",&n_std.Course3_ID);
        printf("Course3_grade:");
        scanf("%d",&n_std.Course3_grade);
        printf("----------------------------------\n");
        DataBase[std_cou] = n_std;
        std_cou++;
        return true;
    }

}
void SDB_DeletEntry (uint32 id)
{
    uint32 i,j;
    for(i=0;i<std_cou;i++)
    {
        if(DataBase[i].Student_ID == id)
        {
            for(j=i+1;j<std_cou;j++)
            {
                DataBase[j-1]=DataBase[j];
                DataBase[j]=DataBase[j+1];
            }
            std_cou--;
            printf("deleted successfully\n");
        }
    }
}

bool SDB_ReadEntry (uint32 id)
{
    uint32 i;
     for(i=0;i<std_cou;i++)
     {
         if(DataBase[i].Student_ID == id){
            printf("\nID:%d\n",DataBase[i].Student_ID);
            printf("Year:%d\n",DataBase[i].Student_year);
            printf("Course1_ID:%d\n",DataBase[i].Course1_ID);
            printf("Course1_grade:%d\n",DataBase[i].Course1_grade);
            printf("Course2_ID:%d\n",DataBase[i].Course2_ID);
            printf("Course2_grade:%d\n",DataBase[i].Course2_grade);
            printf("Course3_ID:%d\n",DataBase[i].Course3_ID);
            printf("Course3_grade:%d\n",DataBase[i].Course3_grade);
            return true;
         }
        }
        return false;
     }

void SDB_GetList(uint8* count, uint32* list[Max_std])
{
    uint32 i;
    *count=std_cou;
    for (i=1;i<=std_cou;i++)
    {
        list[i]=&DataBase[i].Student_ID;
    }
}
bool SDB_IsIdExist (uint32 id)
{
    uint32 i;
     for (i=0;i<std_cou;i++)
     {
         if (DataBase[i].Student_ID == id)
         {
             return true;
         }
     }
     return false;
}

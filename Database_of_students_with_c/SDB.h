#ifndef SDB_H_INCLUDED
#define SDB_H_INCLUDED
#include "STD.h"
#define Max_std 10
//#define Min_std 3
typedef struct SimpleDb
{
 uint32 Student_ID;
 uint32 Student_year;
 uint32 Course1_ID;
 uint32 Course1_grade;
 uint32 Course2_ID;
 uint32 Course2_grade;
 uint32 Course3_ID;
 uint32 Course3_grade;

} student;

extern student DataBase[Max_std];


uint8 SDB_GetUsedSize();
bool SDB_IsFull ();
bool SDB_AddEntry();
bool SDB_ReadEntry (uint32 id);
bool SDB_IsIdExist (uint32 id);
void SDB_DeletEntry (uint32 id);
void SDB_GetList (uint8* count, uint32* list[Max_std]);
void SDB_APP ();
void SDB_action (uint8 choice);
#endif // SDB_H_INCLUDED

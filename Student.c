#include <stdio.h>
#include <windows.h>
#include "Student.h"
#include "String.h"

static int ID_student = 0;


void setColor(int ForgC)
{

    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

void WelcomeMessage(void)
{
    setColor(10);

    printf(" \n\n\n\n\n\t\t\t\t\t  *  *  *  *  *  *  *  *  *  *  *  *  *  *");
    printf("\n\n\t\t\t\t\t  *                                      *");
    printf("\n\n\t\t\t\t\t  *      Welcome To School Database      *");
    printf("\n\n\t\t\t\t\t  *                                      *");
    printf(" \n\n\t\t\t\t\t  *  *  *  *  *  *  *  *  *  *  *  *  *  *");

    setColor(15);
}

void DisplayMenu(void)
{
    setColor(9);
    printf("\n\n\t\t\t\t\t  =========================================\n");
    printf("\t\t\t\t\t  |");
    printf("\t     <<<  Main Menu  >>>\t   |\n");
    printf("\t\t\t\t\t  |\t\t\t\t\t   |\n");
    printf("\t\t\t\t\t  |           1. Add Student\t\t   |\n");
    printf("\t\t\t\t\t  |           2. Show Student Details\t   |\n");
    printf("\t\t\t\t\t  |           3. Show All Students\t   |\n");
    printf("\t\t\t\t\t  |           4. Remove Student\t\t   |\n");
    printf("\t\t\t\t\t  |           5. To Exit \t\t   |\n");
    printf("\t\t\t\t\t  =========================================\n\n");
    setColor(15);
}


list_t*List_Creat_List(void)
{
    list_t*NewList =malloc(sizeof(list_t));


    NewList->size =0;
    NewList->head=0;

    return NewList;

}


std_t* Create_Student(char*name,int age,char*address,int phoneNumber)
{
    std_t*NewStudent =malloc(sizeof(std_t));

    NewStudent->age =age;

    NewStudent->ID =ID_student++;

    //NewStudent->grade =grade;

    copy_string(name,NewStudent->name,20);
    copy_string(phoneNumber,NewStudent->PhoneNumber,12);
    copy_string(address,NewStudent->address,100);
    NewStudent->next=0;


                     return NewStudent;


}


student_status_t  List_AddStudent(list_t*list,char*name,int age,char*address,int phoneNumber)
{

    std_t*NewNode=Create_Student(name,age,address,phoneNumber);

    std_t *current = list->head;

    if(NewNode == 0)
    {
        return FAILED;
    }

    if(current == 0)
    {
        list->head = NewNode;
        list->size++;
    }
    else
    {
        while(current->next!=0)
        {
            current =current->next;
        }
        current->next =NewNode;
        list->size++;
    }
    return OK;

}

student_status_t List_RemoveStudentByID(list_t*list,int SearchID)
{

    std_t*current =list->head;

    std_t*temp =0;

    if(current==0)
    {
        return EMPTY_LIST;
    }
    if(current->ID==SearchID)
    {
        temp =list->head;
        list->head =current->next;
        current->next =temp;
        list->size--;
        free(temp);

        return OK;
    }
    while(current->next != 0)
    {
        if(current -> next-> ID == SearchID)
        {
            temp = current->next;
            current->next = current->next->next;
            free(temp);
            list->size--;
            return OK;
        }

        current = current->next;
    }
    return NOT_FOUND;

}

student_status_t List_ListRemoveByName(list_t*list,char*StudentName)
{

    std_t*current =list->head;

    std_t*temp =0;

    if(current==0)
    {
        return EMPTY_LIST;
    }
    if(string_compareNotCaseSensetive(current->name,StudentName)==1)
    {
        temp =list->head;
        list->head =current->next;
        current->next =temp;
        list->size--;
        free(temp);

        return OK;
    }
    while(current->next != 0)
    {
        if(string_compareNotCaseSensetive(current->name,StudentName)==1)
        {
            temp = current->next;
            current->next = current->next->next;
            free(temp);
            list->size--;
            return OK;
        }

        current = current->next;
    }
    return NOT_FOUND;

}

student_status_t List_ListEdit_StudentName(list_t*list,int OldID,char*NewName)
{
    std_t*current =list->head;

    if(list==0)
    {
        return EMPTY_LIST;
    }
    while(current!=0)
    {
        if(current->ID==OldID)
        {

            copy_string(NewName,current->name,20);
        }
        current =current->next;
    }
    return NOT_FOUND;

}

student_status_t List_EditStudent_Age(list_t *list, int OldID, int NewAge)
{
    std_t *current = list->head;

    if(list == 0)
    {
        return EMPTY_LIST;
    }

    while(current!= 0)
    {
        if(current->ID == OldID)
        {
            current->age = NewAge;
            return OK;
        }
        current = current->next;
    }
    return NOT_FOUND;
}
/*student_status_t List_EditStudent_Grade(list_t *list, int OldID, char NewGrade)
{
    std_t *current = list->head;

    if(list == 0)
    {
        return EMPTY_LIST;
    }

    while(current!= 0)
    {
        if(current->ID == OldID)
        {
            current->grade = NewGrade;
            return OK;
        }
        current = current->next;
    }
    return NOT_FOUND;
}*/

student_status_t List_EditStudent_Address(list_t *list, int OldID, char *NewAddress)
{
    std_t *current = list->head;

    if(list == 0)
    {
        return EMPTY_LIST;
    }

    while(current!= 0)
    {
        if(current->ID == OldID)
        {
            copy_string(NewAddress,current->address,100);
            return OK;
        }
        current = current->next;
    }
    return NOT_FOUND;
}

student_status_t List_EditStudent_PhoneNumber(list_t *list, int OldID, char *NewPhoneNumber)
{
    std_t *current = list->head;

    if(list == 0)
    {
        return EMPTY_LIST;
    }

    while(current!= 0)
    {
        if(current->ID== OldID)
        {
            copy_string(NewPhoneNumber,current->PhoneNumber,12);
            return OK;
        }
        current = current->next;
    }
    return NOT_FOUND;
}

student_status_t List_PrintAllStudents(list_t *list)
{
    setColor(7);
    printf("\n\tID\t|\tName             |       PhoneNumber    \t|\t Age\t    |      \t Address\t      |\n");
    printf("=================================================================================================================================\n");


    if(list->head == 0)
    {
        return EMPTY_LIST;
    }

    else
    {
        std_t * current = list->head;

        while(current!=0)
        {
            printf("\t%d\t    %s     \t        %s      \t           %d\t            %s\t  \n",current->ID,current->name,current->PhoneNumber,current->age,current->address);
            printf("------------------------------------------------------------------------------------------------------------------------------\n");
            current = current->next;
        }
        setColor(14);
        printf("\n\n----------------- Total No.of Students:%d ------------------\n\n",list->size);
        setColor(7);
    }
    return OK;
}
student_status_t  PrintDetailsStudentByName(list_t *list, char *SearchName,int *StuID)
{
    std_t *current = list->head;

    if(current == 0)
    {
        return NOT_FOUND;
    }

    if(string_compareNotCaseSensetive(current->name,SearchName) == 1)
    {
        printf("\n\n\t\t\t\t\t\tStudent ID:\t\t\t%d\n",current->ID);
        printf("\t\t\t\t\t\tStudent Name:\t\t\t%s\n",current->name);
        printf("\t\t\t\t\t\tStudent Age:\t\t\t%d\n",current->age);
       //printf("\t\t\t\t\t\tStudent Grade:\t\t\t%c\n",current->grade);
        printf("\t\t\t\t\t\tStudent Address:\t\t%s\n",current->address);
        printf("\t\t\t\t\t\tFather PhoneNumber:\t\t%s\n",current->PhoneNumber);
        *StuID = current->ID;
        return OK;
    }

    else
    {
        while(current!=0)
        {
            if(string_compareNotCaseSensetive(current->name,SearchName) == 1)
            {
                printf("\n\n\t\t\t\t\t\tStudent ID:\t\t\t%d\n",current->ID);
                printf("\t\t\t\t\t\tStudent Name:\t\t\t%s\n",current->name);
                printf("\t\t\t\t\t\tStudent Age:\t\t\t%d\n",current->age);
               // printf("\t\t\t\t\t\tStudent Grade:\t\t\t%c\n",current->grade);
                printf("\t\t\t\t\t\tStudent Address:\t\t%s\n",current->address);
                printf("\t\t\t\t\t\tFather PhoneNumber:\t\t%s\n",current->PhoneNumber);
                *StuID = current->ID;
                return OK;

            }
            current = current->next;
        }

    }

    return NOT_FOUND;

}
student_status_t  PrintDetailsStudentByID(list_t *list, int searchID)
{
    std_t *current = list->head;

    if(current == 0)
    {
        return NOT_FOUND;
    }

    if(current->ID == searchID)
    {
        printf("\n\n\t\t\t\t\t\tStudent ID:\t\t\t%d\n",current->ID);
        printf("\t\t\t\t\t\tStudent Name:\t\t\t%s\n",current->name);
        printf("\t\t\t\t\t\tStudent Age:\t\t\t%d\n",current->age);
       // printf("\t\t\t\t\t\tStudent Grade:\t\t\t%c\n",current->grade);
        printf("\t\t\t\t\t\tStudent Address:\t\t%s\n",current->address);
        printf("\t\t\t\t\t\tFather PhoneNumber:\t\t%s\n",current->PhoneNumber);
        return OK;
    }

    else
    {
        while(current!=0)
        {
            if(current->ID == searchID)
            {

                printf("\n\n\t\t\t\t\t\tStudent ID:\t\t\t%d\n",current->ID);
                printf("\t\t\t\t\t\tStudent Name:\t\t\t%s\n",current->name);
                printf("\t\t\t\t\t\tStudent Age:\t\t\t%d\n",current->age);
              //  printf("\t\t\t\t\t\tStudent Grade:\t\t\t%c\n",current->grade);
                printf("\t\t\t\t\t\tStudent Address:\t\t%s\n",current->address);
                printf("\t\t\t\t\t\tFather PhoneNumber:\t\t%s\n",current->PhoneNumber);

                return OK;

            }
            current = current->next;
        }

    }

    return NOT_FOUND;
}

#ifndef STUDENT_H_
#define STUDENT_H_

 typedef struct Student{

 struct Student *next;
 char name[20];
 char address[100];
 int PhoneNumber[12];
 int age;
 int grade;
 int ID;

 }std_t;


 typedef struct list{

 struct list *head;
 int size;

 }list_t;


 typedef enum{

 OK,
 EMPTY_LIST,
 NOT_FOUND,
 FAILED

 }student_status_t;


void setColor(int ForgC);
void WelcomeMessage(void);
void DisplayMenu(void);


list_t*List_Creat_List(void);
std_t* Create_Student(char*name,int age,char*address,int phoneNumber);
student_status_t  List_AddStudent(list_t*list,char*name,int age,char*address,int phoneNumber);
student_status_t List_RemoveStudentByID(list_t*List,int SearchID);
student_status_t List_ListRemoveByName(list_t*list,char*StudentName);
student_status_t List_ListEdit_StudentName(list_t*list,int OldID,char*NewName);
student_status_t List_EditStudent_Age(list_t *list, int OldID, int NewAge);
student_status_t List_EditStudent_Grade(list_t *list, int OldID, char NewGrade);
student_status_t List_EditStudent_Address(list_t *list, int OldID, char *NewAddress);
student_status_t List_EditStudent_PhoneNumber(list_t *list, int OldID, char *NewPhoneNumber);
student_status_t List_PrintAllStudents(list_t *list);
student_status_t  PrintDetailsStudentByName(list_t *list, char *SearchName,int *StuID);
student_status_t  PrintDetailsStudentByID(list_t *list, int searchID);
















#endif // STUDENT_H_

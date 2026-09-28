/* employees.c - Role 1: Employee Management (Kletus) */
#include <stdio.h>
#include <string.h>
# include "employees.h" 

void addEmployee();
void displayEmployees();
void searchEmployee();
int ids[50];
char names[50][50];
char department[50][50];
double basicSalary[50];
double housingAllowance[50];
double transportAllowance[50];
int employeeCount =0;


void employeeMenu() {
   int choice = -1;
    while (choice !=0)
    {
     printf ("\n==== EMPLOYEE MENU ====\n");
     printf("1. Add Employee\n");
     printf("2. Display All Employees\n");
     printf("3. Search employee\n");
     printf("0. Back to Main Menu\n");
     scanf("%d", &choice);
     switch (choice)
     {
     case 1:
       addEmployee();
       break;
     case 2:
       displayEmployees();
       break;
     case 3:
       searchEmployee();
       break;  
      case 0: 
      printf("returning to main menu ");
      break;
      default: 
      printf("invalid choice please try again\n");

     }
    }
}
    void addEmployee(){
        if (employeeCount>=50){
            printf("employee list is full \n");
            return;
        }
      printf("Enter employee id: ");
      scanf("%d", &ids[employeeCount]);
      printf("Enter employee name: ");
      scanf(" %49[^\n]", names[employeeCount]);
      printf("Enter department: ");
      scanf(" %49[^\n]", department[employeeCount]);
      printf("Enter basic salary: ");
      scanf("%lf", &basicSalary[employeeCount]);
      if (basicSalary[employeeCount]< 0){
      printf("Error: salary can not be negative, please try again");
      return;
      }
      printf("Enter housing allowance: ");
      scanf("%lf", &housingAllowance[employeeCount]);
      if (housingAllowance [employeeCount]< 0)
      {
        printf("Error: housing allowance can not be negative, please try again");
        return;
      }
      printf("Enter transport Allowance: ");
      scanf("%lf", &transportAllowance[employeeCount]);
      if (transportAllowance [employeeCount]< 0)
      {
        printf("Error: transport allowance cant be neagative, please try again");
        return;
      }
      
      employeeCount ++;
      printf("Employee added successfully\n");
    }

      void displayEmployees() {
        int i;
        if (employeeCount==0){
          printf("No employees found\n");
          return;
        }
        printf("\n ======= ALL EMPLOYEES=====\n");
        
        for ( i = 0; i < employeeCount; i++)
        {
          printf("ID:%d\n",ids[i]);
          printf("NAME:%s\n",names[i]);
          printf("DEPARTMENT:%s\n",department[i]);
          printf("BASIC SALARY:%.2lf\n",basicSalary[i]);
          printf("HOUSE ALLOWANCE: %.2lf\n",housingAllowance[i]);
          printf("TRANSPORT ALLOWANCE: %.2lf\n",transportAllowance[i]);
      }
    }
     void searchEmployee(){
      int searchID;
      int i;
      int found = 0;
      printf ("Enter employee ID to search: ");
      scanf ("%d",&searchID);
      for(i=0; i < employeeCount;i++)
      {  
        if (ids[i]== searchID){
          printf("Employee Found\n");
           printf("ID:%d\n",ids[i]);
          printf("NAME:%s\n",names[i]);
          printf("DEPARTMENT:%s\n",department[i]);
          printf("BASIC SALARY:%.2lf\n",basicSalary[i]);
          printf("HOUSE ALLOWANCE: %.2lf\n",housingAllowance[i]);
          printf("TRANSPORT ALLOWANCE: %.2lf\n",transportAllowance[i]);
    

           found = 1;
           break; 
        }
        
      }
      if (found==0)
      { 
        printf ("Employee not found\n");
      }
    }
     
    

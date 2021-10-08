#include <string.h>
#include <stdlib.h>
#include "employee.h"


int main(void)
{
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberSearch);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameSearch);
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char * phoneSearch);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, long salarySearch);

    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;
    

    PtrToEmployee matchPtr;
    
    //Found Number
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1001);

    if(matchPtr != NULL)
        printf("Employee ID 1001 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");

    //Not Found Number
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 2000);

    if(matchPtr != NULL)
        printf("Employee ID 2000 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");
    
    //Found Name
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Bob McCain");

    if(matchPtr != NULL)
        printf("Employee Name Bob McCain is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Name is NOT found in the record\n");

    //Not Found Name
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Cookie Pie");

    if(matchPtr != NULL)
        printf("Employee Name Cookie Pie is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Name is NOT found in the record\n");

    //Found Phone Number
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "999-999-9999");

    if(matchPtr != NULL)
        printf("Employee Phone Number 999-999-9999 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Phone Number is NOT found in the record\n");

    //Not Found Phone Number
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "123-456-7890");

    if(matchPtr != NULL)
        printf("Employee Phone Number 123-456-7890 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Phone Number is NOT found in the record\n");

    //Found Salary
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 18.00);

    if(matchPtr != NULL)
        printf("Employee Salary of $18.00 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Salary is NOT found in the record\n");

    //Not Found Salary
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 0.00);

    if(matchPtr != NULL)
        printf("Employee Salary of $0.00 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Salary is NOT found in the record\n");
        
    return EXIT_SUCCESS;
}
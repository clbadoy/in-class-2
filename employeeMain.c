#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "employee.h"

Employee EmployeeTable[] = {
        {1001l, "Bob McCain",       "909-909-9090", 14.01},
        {1011l, "Sam Curry",        "562-562-5625", 20.00},
        {1100l, "Boruto Borut",     "909-555-6666", 13.75},
        {1101l, "Dane DankSlief",   "999-999-9999". 17.57},
        {1111l, "Dam Oberhouser",   "909-803-1234", 18.00}
    };

const int EmployeeTableEntries = sizeof(EmployeeTable)sizeof(EmployeeTable[0]);

int main()
{
    return 0;
}
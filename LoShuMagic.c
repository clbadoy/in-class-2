#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>


int checkSumValRow(int (*arr)[3], int co)
{
    int sum = 0;
    for(int ro = 0; ro < 3; ro++)
        sum += arr[ro][co];
    
    return sum;
}

int checkSumValCol(int (*arr)[3], int ro)
{
    int sum = 0;
    for(int co = 0; co < 3; co++)
        sum += arr[ro][co];

    return sum;
}

int checkSumValDiaOne(int (*arr)[3])
{
    int sum = 0;
    
    sum = arr[0][0] + arr[1][1] + arr[2][2];
    
    return sum;
}

int checkSumValDiaTwo(int (*arr)[3])
{
    int sum = 0;

    sum = arr[0][2] + arr[1][1] + arr[2][0];

    return sum;
}

int checkIfLoShu(int (*arr)[3])
{
    int checkR1, checkR2, checkR3, checkC1, checkC2, checkC3, checkD1,checkD2;
    int validLoShu = 8, checkCount = 0, ans;

    checkR1 = (checkSumValRow(arr, 0) == 15) ? 1 : 0;
    checkR2 = (checkSumValRow(arr, 1) == 15) ? 1 : 0;
    checkR3 = (checkSumValRow(arr, 2) == 15) ? 1 : 0;

    checkC1 = (checkSumValCol(arr, 0) == 15) ? 1 : 0;
    checkC2 = (checkSumValCol(arr, 1) == 15) ? 1 : 0;
    checkC3 = (checkSumValCol(arr, 2) == 15) ? 1 : 0;

    checkD1 = (checkSumValDiaOne(arr) == 15) ? 1 : 0;
    checkD2 = (checkSumValDiaTwo(arr) == 15) ? 1 : 0;

    checkCount = checkR1 + checkR2 + checkR3 + checkC1 + checkC2 + checkC3 + checkD1 + checkD2;

    if(validLoShu == checkCount)
        ans = 1;
    else
        ans = 0;
    
    return ans;
}

void displayLoShu(int (*arr)[3],int isItLoShu)
{
    printf("This square below is ");
    if(isItLoShu == 1)
        printf("a ");
    else
        printf("not a ");
    
    printf("Lo Shu Square.\n");

    for(int ro = 0; ro < 3; ro++)
    { 
        if(ro == 0)
            printf("\n[");
        else
            printf("]\n[");
        for(int co = 0; co < 3; co++)
        {
            if(co == 2)
                printf("%d", arr[ro][co]);
            else
                printf("%d ", arr[ro][co]);
        }
    }
    printf("]\n");
}


int randomSquare(int (*arr)[3], int *tempArr)
{
	int count = 0;
	int num = 0, randSquareBool = -1, tempVal = 0, j = 0;
	srand(time(NULL));
	
	while(randSquareBool != 1)
	{		
		for(int i = 0; i < 9; i++)
		{
			j = (rand() % 8) + 1;
			tempVal = tempArr[i];
			tempArr[i] = tempArr[j];
			tempArr[j] = tempVal;
			tempVal = 0;
		} 
		num = 0;
		for(int ro = 0; ro < 3; ro++)
			for(int co = 0; co < 3; co++)
				arr[ro][co] = tempArr[num++];

		randSquareBool = checkIfLoShu(arr);
		count++;
	}
	displayLoShu(arr, randSquareBool);
	printf("Number of Random squares generated: %d\n", count);
	
	return 0;
}
int main()
{
    int loShu[3][3] = {{4, 9, 2}, 
                       {3, 5, 7},
                       {8, 1, 6}}; 

    int notLoShu[3][3] = {{1, 2, 3},
                          {4, 6, 5},
                          {7, 8, 9}};

    int tempLoShu[3][3];
	int tempArr[9] = {1, 2, 3, 4, 5, 6, 7 ,8, 9};
    int theLoShu, notALoShu;

		theLoShu = checkIfLoShu(loShu);
    notALoShu = checkIfLoShu(notLoShu);

    displayLoShu(loShu, theLoShu);
    displayLoShu(notLoShu, notALoShu);
	randomSquare(tempLoShu, tempArr);
	return 0;
}
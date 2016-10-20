#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void printStars( int a )
{
	printf("\n");
	for (int i = 0; i < a; i++)
	{
	printf("*");
	}
	printf("\n");
}
int startDate(int month, int startDay)
{
	int a = startDay+(2 * (month-1));
	while(a>7)
	{
		a = a-7;
	}
	return a;
	
}
int limit(int startDate)
{
	int b = 30 + startDate;
	return b;
}
int main(int argc, char *argv[])
{

FILE *inputFile = fopen(argv[1], "r");
if(inputFile == NULL)
{
	printf("ERROR: File does not exist");
	return 0;
}
// NEED TO CHECK IF INPUT IS VALID
char *daySize1 = argv[2];
char *startDay1 = argv[3];
int daySize = atoi(daySize1);
int startDay = atoi(startDay1)-1;
int calendarWidth = (daySize + 3) * 7;
char calendarDays[42][daySize + 4];
char sunday[10], monday[10], tuesday[10], wednesday[10], thursday[10], friday[10], saturday[10];
char *days[] = {sunday, monday, tuesday, wednesday, thursday, friday, saturday};
//get days from file
fscanf(inputFile, "%s %s %s %s %s %s %s" , sunday, monday, tuesday, wednesday, thursday, friday, saturday);
//make the calendar cells begin with *
for(int i = 0; i < 42; i++)
{
	calendarDays[i][0] = '*';
	calendarDays[i][daySize + 3] = '\0';
}
//make the calendar cells full of white space
for(int i = 0; i < 42; i++)
{
	for( int j = 1; j < daySize + 3; j++)
	{
		calendarDays[i][j] = ' ';
		if((j == daySize + 2)&&((i == 6)||(i == 13)||(i == 20)||(i == 27)||(i == 34)))
		{
			calendarDays[i][j] = '\n';
		}
		
	}
}
int num = 1;
int num1 = 0;
//insert day numbers into cells
for(int i = startDate(1,startDay); i < limit(startDate(1,startDay));i++)
{
	if(num == 10)
	{
		num = 0;
		calendarDays[i][2] = ++num1 + '0';
		calendarDays[i][3] = num + '0';
		num++;
		continue;
	}
	if(calendarDays[i][3] == ' ')
	{
	calendarDays[i][2] = num + '0';
	
	}
	if(num1 >= 1)
	{
		calendarDays[i][2] = num1 + '0';
		calendarDays[i][3] = num + '0';
		
	}
	num++;
		
}
char january[10], february[10], march[10], april[10], may[10], june[10], july[10], august[10], september[10], october[10], november[10], december[10];
//get the months from the file
fscanf(inputFile, "%s %s %s %s %s %s %s %s %s %s %s %s", january, february, march, april, may, june, july, august, september, october, november, december);

char newSun[daySize], newMon[daySize], newTue[daySize], newWed[daySize], newThu[daySize], newFri[daySize], newSat[daySize];
char *newDays[] = {newSun, newMon, newTue, newWed, newThu, newFri, newSat};

for(int i = 0; i < 7; i++)
{
	for(int j = 0; j < daySize; j++)
	{
		newDays[i][j] = days[i][j];
	}
	newDays[i][daySize] = '\0';
	//printf("%s\n", newDays[i]);
}
printStars(calendarWidth);
printf("* %s", january);
printStars(calendarWidth);

for( int i = 0; i < 7; i++)
{
	printf("* %s ", newDays[i]);
}
printStars(calendarWidth);

//print out the calendar cells
for( int i = 0; i < 7; i++)
{
	if(calendarDays[6][2] != ' ')
	{
		printf("%s", calendarDays[i]);
	}
}
for(int i = 7; i < 35; i++)
{
	printf("%s", calendarDays[i]);
	
		
	
}
if(calendarDays[34][2] == (2 + '0'))
{
	for( int j = 35; j<42;j++)
	{
		printf("%s", calendarDays[j]);
	}
}
//February block
printStars(calendarWidth);
printf("* %s", february);
printStars(calendarWidth);
for( int i = 0; i < 7; i++)
{
	printf("* %s ", newDays[i]);
}
printStars(calendarWidth);
for(int i = 0; i < 42; i++)
{
	calendarDays[i][0] = '*';
	calendarDays[i][daySize + 3] = '\0';
}
for(int i = 0; i < 42; i++)
{
	for( int j = 1; j < daySize + 3; j++)
	{
		calendarDays[i][j] = ' ';
		if((j == daySize + 2)&&((i == 6)||(i == 13)||(i == 20)||(i == 27)||(i == 34)))
		{
			calendarDays[i][j] = '\n';
		}
		
	}
}
num = 1;
num1 = 0;
for(int i = startDate(2,startDay); i < limit(startDate(2,startDay));i++)
{
	if(num == 10)
	{
		num = 0;
		calendarDays[i][2] = ++num1 + '0';
		calendarDays[i][3] = num + '0';
		num++;
		continue;
	}
	if(calendarDays[i][3] == ' ')
	{
	calendarDays[i][2] = num + '0';
	
	}
	if(num1 >= 1)
	{
		calendarDays[i][2] = num1 + '0';
		calendarDays[i][3] = num + '0';
		
	}
	num++;
		
}

if(calendarDays[6][2] != ' ')
	{
		for(int i = 0; i < 7; i++)
		{
			printf("%s", calendarDays[i]);
		}
	}
for(int i = 7; i < 35; i++)
{
	printf("%s", calendarDays[i]);
	
		
	
}
if(calendarDays[34][2] == (2 + '0'))
{
	for( int j = 35; j<42;j++)
	{
		printf("%s", calendarDays[j]);
	}
}
//March block

printStars(calendarWidth);
printf("* %s", march);
printStars(calendarWidth);
for( int i = 0; i < 7; i++)
{
	printf("* %s ", newDays[i]);
}
printStars(calendarWidth);
for(int i = 0; i < 42; i++)
{
	calendarDays[i][0] = '*';
	calendarDays[i][daySize + 3] = '\0';
}
for(int i = 0; i < 42; i++)
{
	for( int j = 1; j < daySize + 3; j++)
	{
		calendarDays[i][j] = ' ';
		if((j == daySize + 2)&&((i == 6)||(i == 13)||(i == 20)||(i == 27)||(i == 34)))
		{
			calendarDays[i][j] = '\n';
		}
		
	}
}
num = 1;
num1 = 0;
for(int i = startDate(3,startDay); i < limit(startDate(3,startDay));i++)
{
	if(num == 10)
	{
		num = 0;
		calendarDays[i][2] = ++num1 + '0';
		calendarDays[i][3] = num + '0';
		num++;
		continue;
	}
	if(calendarDays[i][3] == ' ')
	{
	calendarDays[i][2] = num + '0';
	
	}
	if(num1 >= 1)
	{
		calendarDays[i][2] = num1 + '0';
		calendarDays[i][3] = num + '0';
		
	}
	num++;
		
}
for( int i = 0; i < 7; i++)
{
	if(calendarDays[6][2] != ' ')
	{
		printf("%s", calendarDays[i]);
	}
}
for(int i = 7; i < 35; i++)
{
	printf("%s", calendarDays[i]);
	
		
	
}
if(calendarDays[34][2] == (2 + '0'))
{
	for( int j = 35; j<42;j++)
	{
		printf("%s", calendarDays[j]);
	}
}
//April block
printStars(calendarWidth);
printf("* %s", april);
printStars(calendarWidth);
for( int i = 0; i < 7; i++)
{
	printf("* %s ", newDays[i]);
}
printStars(calendarWidth);
for(int i = 0; i < 42; i++)
{
	calendarDays[i][0] = '*';
	calendarDays[i][daySize + 3] = '\0';
}
for(int i = 0; i < 42; i++)
{
	for( int j = 1; j < daySize + 3; j++)
	{
		calendarDays[i][j] = ' ';
		if((j == daySize + 2)&&((i == 6)||(i == 13)||(i == 20)||(i == 27)||(i == 34)))
		{
			calendarDays[i][j] = '\n';
		}
		
	}
}
num = 1;
num1 = 0;
for(int i = startDate(4,startDay); i < limit(startDate(4,startDay));i++)
{
	if(num == 10)
	{
		num = 0;
		calendarDays[i][2] = ++num1 + '0';
		calendarDays[i][3] = num + '0';
		num++;
		continue;
	}
	if(calendarDays[i][3] == ' ')
	{
	calendarDays[i][2] = num + '0';
	
	}
	if(num1 >= 1)
	{
		calendarDays[i][2] = num1 + '0';
		calendarDays[i][3] = num + '0';
		
	}
	num++;
		
}
for( int i = 0; i < 7; i++)
{
	if(calendarDays[6][2] != ' ')
	{
		printf("%s", calendarDays[i]);
	}
}
for(int i = 7; i < 35; i++)
{
	printf("%s", calendarDays[i]);
	
		
	
}
if(calendarDays[34][2] == (2 + '0'))
{
	for( int j = 35; j<42;j++)
	{
		printf("%s", calendarDays[j]);
	}
}
//May block
printStars(calendarWidth);
printf("* %s", may);
printStars(calendarWidth);
for( int i = 0; i < 7; i++)
{
	printf("* %s ", newDays[i]);
}
printStars(calendarWidth);
for(int i = 0; i < 42; i++)
{
	calendarDays[i][0] = '*';
	calendarDays[i][daySize + 3] = '\0';
}
for(int i = 0; i < 42; i++)
{
	for( int j = 1; j < daySize + 3; j++)
	{
		calendarDays[i][j] = ' ';
		if((j == daySize + 2)&&((i == 6)||(i == 13)||(i == 20)||(i == 27)||(i == 34)))
		{
			calendarDays[i][j] = '\n';
		}
		
	}
}
num = 1;
num1 = 0;
for(int i = startDate(5,startDay); i < limit(startDate(5,startDay));i++)
{
	if(num == 10)
	{
		num = 0;
		calendarDays[i][2] = ++num1 + '0';
		calendarDays[i][3] = num + '0';
		num++;
		continue;
	}
	if(calendarDays[i][3] == ' ')
	{
	calendarDays[i][2] = num + '0';
	
	}
	if(num1 >= 1)
	{
		calendarDays[i][2] = num1 + '0';
		calendarDays[i][3] = num + '0';
		
	}
	num++;
		
}
for( int i = 0; i < 7; i++)
{
	if(calendarDays[6][2] != ' ')
	{
		printf("%s", calendarDays[i]);
	}
}
for(int i = 7; i < 35; i++)
{
	printf("%s", calendarDays[i]);
	
		
	
}
if(calendarDays[34][2] == (2 + '0'))
{
	for( int j = 35; j<42;j++)
	{
		printf("%s", calendarDays[j]);
	}
}
//June block
printStars(calendarWidth);
printf("* %s", june);
printStars(calendarWidth);
for( int i = 0; i < 7; i++)
{
	printf("* %s ", newDays[i]);
}
printStars(calendarWidth);
for(int i = 0; i < 42; i++)
{
	calendarDays[i][0] = '*';
	calendarDays[i][daySize + 3] = '\0';
}
for(int i = 0; i < 42; i++)
{
	for( int j = 1; j < daySize + 3; j++)
	{
		calendarDays[i][j] = ' ';
		if((j == daySize + 2)&&((i == 6)||(i == 13)||(i == 20)||(i == 27)||(i == 34)))
		{
			calendarDays[i][j] = '\n';
		}
		
	}
}
num = 1;
num1 = 0;
for(int i = startDate(6,startDay); i < limit(startDate(6,startDay));i++)
{
	if(num == 10)
	{
		num = 0;
		calendarDays[i][2] = ++num1 + '0';
		calendarDays[i][3] = num + '0';
		num++;
		continue;
	}
	if(calendarDays[i][3] == ' ')
	{
	calendarDays[i][2] = num + '0';
	
	}
	if(num1 >= 1)
	{
		calendarDays[i][2] = num1 + '0';
		calendarDays[i][3] = num + '0';
		
	}
	num++;
		
}
for( int i = 0; i < 7; i++)
{
	if(calendarDays[6][2] != ' ')
	{
		printf("%s", calendarDays[i]);
	}
}
for(int i = 7; i < 35; i++)
{
	printf("%s", calendarDays[i]);
	
		
	
}
if(calendarDays[34][2] == (2 + '0'))
{
	for( int j = 35; j<42;j++)
	{
		printf("%s", calendarDays[j]);
	}
}
//July block
printStars(calendarWidth);
printf("* %s", july);
printStars(calendarWidth);
for( int i = 0; i < 7; i++)
{
	printf("* %s ", newDays[i]);
}
printStars(calendarWidth);
for(int i = 0; i < 42; i++)
{
	calendarDays[i][0] = '*';
	calendarDays[i][daySize + 3] = '\0';
}
for(int i = 0; i < 42; i++)
{
	for( int j = 1; j < daySize + 3; j++)
	{
		calendarDays[i][j] = ' ';
		if((j == daySize + 2)&&((i == 6)||(i == 13)||(i == 20)||(i == 27)||(i == 34)))
		{
			calendarDays[i][j] = '\n';
		}
		
	}
}
num = 1;
num1 = 0;
for(int i = startDate(7,startDay); i < limit(startDate(7,startDay));i++)
{
	if(num == 10)
	{
		num = 0;
		calendarDays[i][2] = ++num1 + '0';
		calendarDays[i][3] = num + '0';
		num++;
		continue;
	}
	if(calendarDays[i][3] == ' ')
	{
	calendarDays[i][2] = num + '0';
	
	}
	if(num1 >= 1)
	{
		calendarDays[i][2] = num1 + '0';
		calendarDays[i][3] = num + '0';
		
	}
	num++;
		
}
for( int i = 0; i < 7; i++)
{
	if(calendarDays[6][2] != ' ')
	{
		printf("%s", calendarDays[i]);
	}
}
for(int i = 7; i < 35; i++)
{
	printf("%s", calendarDays[i]);
	
		
	
}
if(calendarDays[34][2] == (2 + '0'))
{
	for( int j = 35; j<42;j++)
	{
		printf("%s", calendarDays[j]);
	}
}
//August block
printStars(calendarWidth);
printf("* %s", august);
printStars(calendarWidth);
for( int i = 0; i < 7; i++)
{
	printf("* %s ", newDays[i]);
}
printStars(calendarWidth);
for(int i = 0; i < 42; i++)
{
	calendarDays[i][0] = '*';
	calendarDays[i][daySize + 3] = '\0';
}
for(int i = 0; i < 42; i++)
{
	for( int j = 1; j < daySize + 3; j++)
	{
		calendarDays[i][j] = ' ';
		if((j == daySize + 2)&&((i == 6)||(i == 13)||(i == 20)||(i == 27)||(i == 34)))
		{
			calendarDays[i][j] = '\n';
		}
		
	}
}
num = 1;
num1 = 0;
for(int i = startDate(8,startDay); i < limit(startDate(8,startDay));i++)
{
	if(num == 10)
	{
		num = 0;
		calendarDays[i][2] = ++num1 + '0';
		calendarDays[i][3] = num + '0';
		num++;
		continue;
	}
	if(calendarDays[i][3] == ' ')
	{
	calendarDays[i][2] = num + '0';
	
	}
	if(num1 >= 1)
	{
		calendarDays[i][2] = num1 + '0';
		calendarDays[i][3] = num + '0';
		
	}
	num++;
		
}
for( int i = 0; i < 7; i++)
{
	if(calendarDays[6][2] != ' ')
	{
		printf("%s", calendarDays[i]);
	}
}
for(int i = 7; i < 35; i++)
{
	printf("%s", calendarDays[i]);
	
		
	
}
if(calendarDays[34][2] == (2 + '0'))
{
	for( int j = 35; j<42;j++)
	{
		printf("%s", calendarDays[j]);
	}
}
//September block
printStars(calendarWidth);
printf("* %s", september);
printStars(calendarWidth);
for( int i = 0; i < 7; i++)
{
	printf("* %s ", newDays[i]);
}
printStars(calendarWidth);
for(int i = 0; i < 42; i++)
{
	calendarDays[i][0] = '*';
	calendarDays[i][daySize + 3] = '\0';
}
for(int i = 0; i < 42; i++)
{
	for( int j = 1; j < daySize + 3; j++)
	{
		calendarDays[i][j] = ' ';
		if((j == daySize + 2)&&((i == 6)||(i == 13)||(i == 20)||(i == 27)||(i == 34)))
		{
			calendarDays[i][j] = '\n';
		}
		
	}
}
num = 1;
num1 = 0;
for(int i = startDate(9,startDay); i < limit(startDate(9,startDay));i++)
{
	if(num == 10)
	{
		num = 0;
		calendarDays[i][2] = ++num1 + '0';
		calendarDays[i][3] = num + '0';
		num++;
		continue;
	}
	if(calendarDays[i][3] == ' ')
	{
	calendarDays[i][2] = num + '0';
	
	}
	if(num1 >= 1)
	{
		calendarDays[i][2] = num1 + '0';
		calendarDays[i][3] = num + '0';
		
	}
	num++;
		
}
for( int i = 0; i < 7; i++)
{
	if(calendarDays[6][2] != ' ')
	{
		printf("%s", calendarDays[i]);
	}
}
for(int i = 7; i < 35; i++)
{
	printf("%s", calendarDays[i]);
	
		
	
}
if(calendarDays[34][2] == (2 + '0'))
{
	for( int j = 35; j<42;j++)
	{
		printf("%s", calendarDays[j]);
	}
}
//October block
printStars(calendarWidth);
printf("* %s", october);
printStars(calendarWidth);
for( int i = 0; i < 7; i++)
{
	printf("* %s ", newDays[i]);
}
printStars(calendarWidth);
for(int i = 0; i < 42; i++)
{
	calendarDays[i][0] = '*';
	calendarDays[i][daySize + 3] = '\0';
}
for(int i = 0; i < 42; i++)
{
	for( int j = 1; j < daySize + 3; j++)
	{
		calendarDays[i][j] = ' ';
		if((j == daySize + 2)&&((i == 6)||(i == 13)||(i == 20)||(i == 27)||(i == 34)))
		{
			calendarDays[i][j] = '\n';
		}
		
	}
}
num = 1;
num1 = 0;
for(int i = startDate(10,startDay); i < limit(startDate(10,startDay));i++)
{
	if(num == 10)
	{
		num = 0;
		calendarDays[i][2] = ++num1 + '0';
		calendarDays[i][3] = num + '0';
		num++;
		continue;
	}
	if(calendarDays[i][3] == ' ')
	{
	calendarDays[i][2] = num + '0';
	
	}
	if(num1 >= 1)
	{
		calendarDays[i][2] = num1 + '0';
		calendarDays[i][3] = num + '0';
		
	}
	num++;
		
}
for( int i = 0; i < 7; i++)
{
	if(calendarDays[6][2] != ' ')
	{
		printf("%s", calendarDays[i]);
	}
}
for(int i = 7; i < 35; i++)
{
	printf("%s", calendarDays[i]);
	
		
	
}
if(calendarDays[34][2] == (2 + '0'))
{
	for( int j = 35; j<42;j++)
	{
		printf("%s", calendarDays[j]);
	}
}
//November block
printStars(calendarWidth);
printf("* %s", november);
printStars(calendarWidth);
for( int i = 0; i < 7; i++)
{
	printf("* %s ", newDays[i]);
}
printStars(calendarWidth);
for(int i = 0; i < 42; i++)
{
	calendarDays[i][0] = '*';
	calendarDays[i][daySize + 3] = '\0';
}
for(int i = 0; i < 42; i++)
{
	for( int j = 1; j < daySize + 3; j++)
	{
		calendarDays[i][j] = ' ';
		if((j == daySize + 2)&&((i == 6)||(i == 13)||(i == 20)||(i == 27)||(i == 34)))
		{
			calendarDays[i][j] = '\n';
		}
		
	}
}
num = 1;
num1 = 0;
for(int i = startDate(11,startDay); i < limit(startDate(11,startDay));i++)
{
	if(num == 10)
	{
		num = 0;
		calendarDays[i][2] = ++num1 + '0';
		calendarDays[i][3] = num + '0';
		num++;
		continue;
	}
	if(calendarDays[i][3] == ' ')
	{
	calendarDays[i][2] = num + '0';
	
	}
	if(num1 >= 1)
	{
		calendarDays[i][2] = num1 + '0';
		calendarDays[i][3] = num + '0';
		
	}
	num++;
		
}
for( int i = 0; i < 7; i++)
{
	if(calendarDays[6][2] != ' ')
	{
		printf("%s", calendarDays[i]);
	}
}
for(int i = 7; i < 35; i++)
{
	printf("%s", calendarDays[i]);
	
		
	
}
if(calendarDays[34][2] == (2 + '0'))
{
	for( int j = 35; j<42;j++)
	{
		printf("%s", calendarDays[j]);
	}
}
//December block
printStars(calendarWidth);
printf("* %s", december);
printStars(calendarWidth);
for( int i = 0; i < 7; i++)
{
	printf("* %s ", newDays[i]);
}
printStars(calendarWidth);
for(int i = 0; i < 42; i++)
{
	calendarDays[i][0] = '*';
	calendarDays[i][daySize + 3] = '\0';
}
for(int i = 0; i < 42; i++)
{
	for( int j = 1; j < daySize + 3; j++)
	{
		calendarDays[i][j] = ' ';
		if((j == daySize + 2)&&((i == 6)||(i == 13)||(i == 20)||(i == 27)||(i == 34)))
		{
			calendarDays[i][j] = '\n';
		}
		
	}
}
num = 1;
num1 = 0;
for(int i = startDate(12,startDay); i < limit(startDate(12,startDay));i++)
{
	if(num == 10)
	{
		num = 0;
		calendarDays[i][2] = ++num1 + '0';
		calendarDays[i][3] = num + '0';
		num++;
		continue;
	}
	if(calendarDays[i][3] == ' ')
	{
	calendarDays[i][2] = num + '0';
	
	}
	if(num1 >= 1)
	{
		calendarDays[i][2] = num1 + '0';
		calendarDays[i][3] = num + '0';
		
	}
	num++;
		
}
for( int i = 0; i < 7; i++)
{
	if(calendarDays[6][2] != ' ')
	{
		printf("%s", calendarDays[i]);
	}
}
for(int i = 7; i < 35; i++)
{
	printf("%s", calendarDays[i]);
	
		
	
}
if(calendarDays[34][2] == (2 + '0'))
{
	for( int j = 35; j<42;j++)
	{
		printf("%s", calendarDays[j]);
	}
}
return 0;
}

#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{
char *defaultDays[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

int i = 0;

char *defaultMonths[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
char dayofweek[10];
char month[10];
char day[10];
char time[10];
char timezone[10];
char year[10];
char *completeDate[] = {dayofweek, month, day, time, timezone, year};
char date[40];
fgets(date, sizeof(date), stdin);
char *a = strtok (date," ");

while(a != NULL && i < 6)
{
	strcpy(completeDate[i], a);
	a = strtok (NULL, " ");
	i++;
	
}

char *monthArray[12];
char *dayArray[7];
FILE *inputFile = fopen(argv[1], "r");

if(inputFile == NULL)
{
	printf("ERROR: File does not exist");
	return 0;	
}


char sunday[10], monday[10], tuesday[10], wednesday[10], thursday[10], friday[10], saturday[10];
	
	fscanf(inputFile, "%s %s %s %s %s %s %s" , sunday, monday, tuesday, wednesday, thursday, friday, saturday);
	
	dayArray[0] = sunday;
	dayArray[1] = monday;
	dayArray[2] = tuesday;
	dayArray[3] = wednesday;
	dayArray[4] = thursday;
	dayArray[5] = friday;
	dayArray[6] = saturday;






for(int counter = 0; counter < 7; counter++)
{ 
	int compare = strcmp(completeDate[0], defaultDays[counter]);
	if(compare == 0)
	{
		
		strncpy(completeDate[0], dayArray[counter], 15);
		break;
	}
}

	char january[10], february[10], march[10], april[10], may[10], june[10], july[10], august[10], september[10], october[10], november[10], december[10];

	fscanf(inputFile, "%s %s %s %s %s %s %s %s %s %s %s %s", january, february, march, april, may, june, july, august, september, october, november, december);
	monthArray[0] = january;
	monthArray[1] = february;
	monthArray[2] = march;
	monthArray[3] = april;
	monthArray[4] = may;
	monthArray[5] = june;
	monthArray[6] = july;
	monthArray[7] = august;
	monthArray[8] = september;
	monthArray[9] = october;
	monthArray[10] = november;
	monthArray[11] = december;

for(int counter1 = 0; counter1 < 12; counter1++)
{ 
	int compare1 = strcmp(completeDate[1], defaultMonths[counter1]);
	
	if(compare1 == 0)
	{
		
		strncpy(completeDate[1], monthArray[counter1], 15);
		break;
	}
}
for(int d = 0; d < 6; d++)
{
printf("%s ", completeDate[d]);
}
fclose(inputFile);
return 0;
}


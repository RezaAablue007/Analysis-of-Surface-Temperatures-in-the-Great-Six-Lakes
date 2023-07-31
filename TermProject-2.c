/* CPS125 Term Project Part 3
*
* Name: Dennon Carafa
* Student Number: 500975880
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //This library includes the string function needed for copying strings to variables//

/* This function takes one of the arrays of the lake temperatures and
* determines the highest temperature out of all the recorded temperatures for
* that lake that was read from the file. It also uses a pointer variable
* to record the day the highest temperature took place.
*/
double highest_temp(const double temp[], int size, int *day){
int day_of_high_temp;
double highest_temp;
highest_temp = temp[0];
/* This loop checks each of the recorded lake temperatures and
* compares them to the current recorded highest temperature named
* highest_temp. If the current highest temperature is less than the
* temperature for that day, that day's temperature will be placed in
* the variable highest_temp.
*/
for (int i = 1; i <= size; i++){
if (highest_temp < temp[i-1]){
highest_temp = temp[i-1];
day_of_high_temp = i;
}
}
*day = day_of_high_temp; //Returns day of the highest temperature//
return(highest_temp); //Returns highest temperature back to main function//
}
/* This function takes one of the arrays of the lake temperatures and
* determines the lowest temperature out of all the recorded temperatures for
* that lake that was read from the file. It also uses a pointer variable
* to record the day the lowest temperature took place.
*/
double lowest_temp(const double temp[], int size, int *day){
int day_of_low_temp;
double lowest_temp;
lowest_temp = temp[0];
/* This loop checks each recorded temperature for the lake and will
* compare them to the current lowest temperature.
*/
for (int i = 1; i <= size; i++){
if (lowest_temp > temp[i-1]){
lowest_temp = temp[i-1];
day_of_low_temp = i;
}
}
*day = day_of_low_temp; //Returns day of the lowest temperature//
return(lowest_temp); //Returns the lowest temperature of the lake//
}
int date(int day_in_year, char lake_month[10]){
/* This function takes the day from the highest_temp or lowest_temp
* functions and converts that day into the standard day/month format.
* This function only considers a 365 day year.
*/
int day;
char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August",
"September", "October", "November", "December"};
if (day_in_year >= 1 && day_in_year <= 31){
day = day_in_year;
strcpy (lake_month, months[0]);
} else
if (day_in_year >= 32 && day_in_year <= 59){
day = day_in_year - 31;
strcpy (lake_month, months[1]);
} else
if (day_in_year >= 60 && day_in_year <= 90){
day = day_in_year - 59;
strcpy (lake_month, months[2]);
} else
if (day_in_year >= 91 && day_in_year <= 120){
day = day_in_year - 90;
strcpy (lake_month, months[3]);
} else
if (day_in_year >= 121 && day_in_year <= 151){
day = day_in_year - 120;
strcpy (lake_month, months[4]);
} else
if (day_in_year >= 152 && day_in_year <= 181){
day = day_in_year - 151;
strcpy (lake_month, months[5]);
} else
if (day_in_year >= 182 && day_in_year <= 212){
day = day_in_year - 181;
strcpy (lake_month, months[6]);
} else
if (day_in_year >= 213 && day_in_year <= 243){
day = day_in_year - 212;
strcpy (lake_month, months[7]);
} else
if (day_in_year >= 244 && day_in_year <= 273){
day = day_in_year - 243;
strcpy (lake_month, months[8]);
} else
if (day_in_year >= 274 && day_in_year <= 304){
day = day_in_year - 273;
strcpy (lake_month, months[9]);
} else
if (day_in_year >= 305 && day_in_year <= 334){
day = day_in_year - 304;
strcpy (lake_month, months[10]);
} else
if (day_in_year >= 335 && day_in_year <= 365){
day = day_in_year - 334;
strcpy (lake_month, months[11]);
}
return(day);
}
int main(void)
{
system ("color f0");
//All declarations for the days, months, temperatures of the lakes//
int i, day_high[6], day_low[6], day_of_year, year;
char month[10], month_high[6][10], month_low[6][10], names_of_lakes[6][10] = {"Superior",
"Michigan", "Huron", "Erie", "Ontario", "St. Clair"};
double sup_temp[365], mich_temp[365], huron_temp[365], erie_temp[365], ont_temp[365],
stclr_temp[365], highest_lake_temp[6], lowest_lake_temp[6];
char *filename = "2019LakeTemperatures.txt";
//Opens the file//
FILE *in;
in = fopen("2019LakeTemperatures.txt", "r");
//Checks status of file//
if(in == NULL){
printf("There was an error opening the file %s \n", filename);
return(1);
}
//Reads the data from the file and puts it into its respective lake temperature array//
while (!feof(in)){
fscanf(in, "%d", &year);
fscanf(in, "%d", &i);
fscanf(in, "%lf", &sup_temp[i-1]);
fscanf(in, "%lf", &mich_temp[i-1]);
fscanf(in, "%lf", &huron_temp[i-1]);
fscanf(in, "%lf", &erie_temp[i-1]);
fscanf(in, "%lf", &ont_temp[i-1]);
fscanf(in, "%lf", &stclr_temp[i-1]);
}
fclose(in); //Closes the file//
/* These function calls send the array for each lakes temperature as well
* as their size to the highest_temp function and lowest_temp function to find
* the highest and lowest temperatures of each Lake. The third argument is the
* address for a variable that stores the date of the highest or lowest temperature
* in the main function. The date is then passed to the date function converts the
* date into a familiar day/month format that can be easily understood by the user.
*/
highest_lake_temp[0] = highest_temp(sup_temp, 365, &day_of_year);
day_high[0] = date(day_of_year, month);
strcpy (month_high[0], month); //Copies the name of the month into an array of the months of the highest
temperatures//
lowest_lake_temp[0] = lowest_temp(sup_temp, 365, &day_of_year);
day_low[0] = date(day_of_year, month);
strcpy (month_low[0], month);
highest_lake_temp[1] = highest_temp(mich_temp, 365, &day_of_year);
day_high[1] = date(day_of_year, month);
strcpy (month_high[1], month);
lowest_lake_temp[1] = lowest_temp(mich_temp, 365, &day_of_year);
day_low[1] = date(day_of_year, month);
strcpy (month_low[1], month);
highest_lake_temp[2] = highest_temp(huron_temp, 365, &day_of_year);
day_high[2] = date(day_of_year, month);
strcpy (month_high[2], month);
lowest_lake_temp[2] = lowest_temp(huron_temp, 365, &day_of_year);
day_low[2] = date(day_of_year, month);
strcpy (month_low[2], month);
highest_lake_temp[3] = highest_temp(erie_temp, 365, &day_of_year);
day_high[3] = date(day_of_year, month);
strcpy (month_high[3], month);
lowest_lake_temp[3] = lowest_temp(erie_temp, 365, &day_of_year);
day_low[3] = date(day_of_year, month);
strcpy (month_low[3], month);
highest_lake_temp[4] = highest_temp(ont_temp, 365, &day_of_year);
day_high[4] = date(day_of_year, month);
strcpy (month_high[4], month);
lowest_lake_temp[4] = lowest_temp(ont_temp, 365, &day_of_year);
day_low[4] = date(day_of_year, month);
strcpy (month_low[4], month);
highest_lake_temp[5] = highest_temp(stclr_temp, 365, &day_of_year);
day_high[5] = date(day_of_year, month);
strcpy (month_high[5], month);
lowest_lake_temp[5] = lowest_temp(stclr_temp, 365, &day_of_year);
day_low[5] = date(day_of_year, month);
strcpy (month_low[5], month);
printf("%48s%d\n", "Warmest Lake Temperatures for ", year);
printf("----------------------------------------------------------------------\n");
for (i = 0; i < 6; i++){
printf("Lake %-9s: %s %d, %.2lf degrees Celsius\n", names_of_lakes[i], month_high[i], day_high[i],
highest_lake_temp[i]);
}
printf("\n\n");
printf("%48s%d\n", "Coldest Lake Temperatures for ", year);
printf("----------------------------------------------------------------------\n");
for (i = 0; i < 6; i++){
printf("Lake %-9s: %s %d, %.2lf degrees Celsius\n", names_of_lakes[i], month_low[i], day_low[i],
lowest_lake_temp[i]);
}
return 0;
}
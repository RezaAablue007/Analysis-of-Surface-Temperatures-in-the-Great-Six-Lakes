/* CPS125 Term Project Part 3
*
* Name: Dennon Carafa
* Student Number: 500975880
*/
#include <stdlib.h>
#include <string.h> //This library includes the string function needed for copying strings to variables//

/* This function takes all of the arrays of the lake temperatures and
* determines the highest temperature out of all the recorded temperatures
* read from the file. It also uses a pointer variable to record the day the
* highest temperature took place.
*/
double highest_temp(const double suptemp[], const double michtemp[], const double hurontemp[], const
double erietemp[], const double onttemp[], const double stclrtemp[], int size, int *day, const char
names_of_lakes[6][10],char lake[10]){
int day_of_high_temp;
double highest_temp;
highest_temp = suptemp[0];
/* This loop will read all the temperatures from each array of temperatures
* and determine the highest temperature from all the lakes.
*/
for (int i = 1; i <= size; i++){
if (highest_temp < suptemp[i-1] && suptemp[i-1] > michtemp[i-1] && suptemp[i-1] > hurontemp[i-1]
&& suptemp[i-1] > erietemp[i-1] && suptemp[i-1] > onttemp[i-1] && suptemp[i-1] > stclrtemp[i-1]){
highest_temp = suptemp[i-1];
day_of_high_temp = i;
strcpy (lake, names_of_lakes[0]);
} else
if (highest_temp < michtemp[i-1] && michtemp[i-1] > suptemp[i-1] && michtemp[i-1] >
hurontemp[i-1] && michtemp[i-1] > erietemp[i-1] && michtemp[i-1] > onttemp[i-1] && michtemp[i-1]
> stclrtemp[i-1]){
highest_temp = michtemp[i-1];
day_of_high_temp = i;
strcpy (lake, names_of_lakes[1]);
} else
if (highest_temp < hurontemp[i-1] && hurontemp[i-1] > suptemp[i-1] && hurontemp[i-1] >
michtemp[i-1] && hurontemp[i-1] > erietemp[i-1] && hurontemp[i-1] > onttemp[i-1] &&
hurontemp[i-1] > stclrtemp[i-1]){
highest_temp = hurontemp[i-1];
day_of_high_temp = i;
strcpy (lake, names_of_lakes[2]);
} else
if (highest_temp < erietemp[i-1]&& erietemp[i-1] > suptemp[i-1] && erietemp[i-1] > michtemp[i-1]
&& erietemp[i-1] > hurontemp[i-1] && erietemp[i-1] > onttemp[i-1] && erietemp[i-1] > stclrtemp[i-1]){
highest_temp = erietemp[i-1];
day_of_high_temp = i;
strcpy (lake, names_of_lakes[3]);
} else
if (highest_temp < onttemp[i-1]&& onttemp[i-1] > suptemp[i-1] && onttemp[i-1] > michtemp[i-1] &&
onttemp[i-1] > hurontemp[i-1] && onttemp[i-1] > erietemp[i-1] && onttemp[i-1] > stclrtemp[i-1]){
highest_temp = onttemp[i-1];
day_of_high_temp = i;
strcpy (lake, names_of_lakes[4]);
} else
if (highest_temp < stclrtemp[i-1]&& stclrtemp[i-1] > suptemp[i-1] && stclrtemp[i-1] > michtemp[i-1]
&& stclrtemp[i-1] > hurontemp[i-1] && stclrtemp[i-1] > erietemp[i-1] && stclrtemp[i-1] >
onttemp[i-1]){
highest_temp = stclrtemp[i-1];
day_of_high_temp = i;
strcpy (lake, names_of_lakes[5]);
}
}
*day = day_of_high_temp; //Returns the date of the highest temperature//
return(highest_temp); //Returns the highest temperature of all the lakes//
}
/* This function takes all of the arrays of the lake temperatures and
* determines the lowest temperature out of all the recorded temperatures
* read from the file. It also uses a pointer variable to record the day the
* lowest temperature took place.
*/
double lowest_temp(const double suptemp[], const double michtemp[], const double hurontemp[], const
double erietemp[], const double onttemp[], const double stclrtemp[], int size, int *day, const char
names_of_lakes[6][10],char lake[10]){
int day_of_low_temp;
double lowest_temp;
lowest_temp = suptemp[0];
/* This loop will read all the temperatures from each array of temperatures
* and determine the lowest temperature from all the lakes.
*/
for (int i = 1; i <= size; i++){
if (lowest_temp > suptemp[i-1]){
lowest_temp = suptemp[i-1];
day_of_low_temp = i;
strcpy (lake, names_of_lakes[0]);
} else
if (lowest_temp > michtemp[i-1]){
lowest_temp = michtemp[i-1];
day_of_low_temp = i;
strcpy (lake, names_of_lakes[1]);
} else
if (lowest_temp > hurontemp[i-1]){
lowest_temp = hurontemp[i-1];
day_of_low_temp = i;
strcpy (lake, names_of_lakes[2]);
} else
if (lowest_temp > erietemp[i-1]){
lowest_temp = erietemp[i-1];
day_of_low_temp = i;
strcpy (lake, names_of_lakes[3]);
} else
if (lowest_temp > onttemp[i-1]){
lowest_temp = onttemp[i-1];
day_of_low_temp = i;
strcpy (lake, names_of_lakes[4]);
} else
if (lowest_temp > stclrtemp[i-1]){
lowest_temp = stclrtemp[i-1];
day_of_low_temp = i;
strcpy (lake, names_of_lakes[5]);
}
}
*day = day_of_low_temp; //Returns the date of the lowest temperature//
return(lowest_temp); //Returns the lowest temperature of all the lakes//
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
system("color f0");
//Declarations for the day, month, temperatures//
int i, year, day_of_year, warmest_day, coldest_day;
double sup_temp[365], mich_temp[365], huron_temp[365], erie_temp[365], ont_temp[365],
stclr_temp[365], warmest_temp, coldest_temp;
char lake[10], lake_warm[10], lake_cold[10], month[10], month_high[10], month_low[10],
names_of_lakes[6][10] = {"Superior", "Michigan", "Huron", "Erie", "Ontario", "St. Clair"};
char *filename = "2019LakeTemperatures.txt";
FILE *in;
in = fopen("2019LakeTemperatures.txt", "r");
if(in == NULL){
printf("There was an error opening the file %s \n", filename);
return(1);
}
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
/* The first function call sends all the lake temperature arrays to the function
* highest_temp to determine the highest temperature of all the lakes. The same
* The process is repeated for the function coldest_temp. Both of these functions also
* return which lake had the highest temperature and the day it occurred on. Then these
* dates are sent to the function 'date' which changes the day into the standard
* day/month format.
*/
warmest_temp = highest_temp(sup_temp, mich_temp, huron_temp, erie_temp, ont_temp, stclr_temp,
365, &day_of_year, names_of_lakes, lake);
strcpy(lake_warm, lake);
warmest_day = date(day_of_year, month);
strcpy (month_high, month);
coldest_temp = lowest_temp(sup_temp, mich_temp, huron_temp, erie_temp, ont_temp, stclr_temp, 365,
&day_of_year, names_of_lakes, lake);
strcpy(lake_cold, lake);
coldest_day = date(day_of_year, month);
strcpy (month_low, month);
printf("%57s%d\n", "Warmest Overall Temperature of All the Lakes for ", year);
printf("---------------------------------------------------------------------\n");
printf("Lake %s: %s %d, %.2lf degrees Celsius\n\n\n", lake_warm, month_high, warmest_day,
warmest_temp);
printf("%57s%d\n", "Coldest Overall Temperature of All the Lakes for ", year);
printf("---------------------------------------------------------------------\n");
printf("Lake %s: %s %d, %.2lf degrees Celsius\n\n\n", lake_cold, month_low, coldest_day,
coldest_temp);
return 0;
}
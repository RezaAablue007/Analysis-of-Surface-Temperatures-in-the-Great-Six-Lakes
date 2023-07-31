/* CPS 125 Term Project - Parts 5 and 6 */
/* Name: Reza Aablue */
/* Section: 10 */
/* Student Number: 500966944 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main () {
/* The stategy/approach to this part of the term project is to store the
data of all 6 lakes into separate arrays for each lake and by using
iteration (for loops), the summer and winter averages for the lakes will be
calculated. Next, the lakes' summer and winter temperature averages will be
sorted out in descending order. */
/* All variables and arrays will be declared here. */
FILE* infile;
int year, day;
double superior_array[365];
double michigan_array[365];
double huron_array[365];
double erie_array[365];
double ontario_array[365];
double saint_clair_array[365];
double temp1, temp2, temp3, temp4, temp5, temp6;
int counter;
int i;
int summer_counter, winter_counter_1, winter_counter_2;
int summer_days=0, winter_days=0;
double summer_sum_sup, summer_sum_mich, summer_sum_hur, summer_sum_erie,
summer_sum_ont, summer_sum_stc;
double summer_avg_sup, summer_avg_mich, summer_avg_hur, summer_avg_erie,
summer_avg_ont, summer_avg_stc;
double winter_sum_sup, winter_sum_mich, winter_sum_hur, winter_sum_erie, winter_sum_ont,
winter_sum_stc;
double winter_avg_sup, winter_avg_mich, winter_avg_hur, winter_avg_erie, winter_avg_ont,
winter_avg_stc;
double summer_averages[6], winter_averages[6];
double temporary_variable, temporary_variable_2;
int j, k, L; /* Used for the sorting algorithm. */
/* Opening the data file and using a while loop to collect
and store data for each lake into designated arrays. Then,
the file is closed when all data has been scanned and sorted into
their respective arrays. */
system ("color f0");
infile=fopen("LakedataTermProject.txt", "r");
if (infile==NULL)
{printf("\nThere was an error with opening the file.");}
else
{while (!feof(infile))
{fscanf(infile, "%d", &year);
fscanf(infile, "%d", &day);
fscanf(infile, "%lf", &temp1);
superior_array[counter]=temp1;
fscanf(infile, "%lf", &temp2);
michigan_array[counter]=temp2;
fscanf(infile, "%lf", &temp3);
huron_array[counter]=temp3;
fscanf(infile, "%lf", &temp4);
erie_array[counter]=temp4;
fscanf(infile, "%lf", &temp5);
ontario_array[counter]=temp5;
fscanf(infile, "%lf", &temp6);
saint_clair_array[counter]=temp6;
++counter;}
fclose(infile);
/* Using a for loop to sum up all the summer temperatures for the 6 lakes (days 172-265). */
for (summer_counter=171; summer_counter<=264; ++summer_counter)
{summer_sum_sup+=superior_array[summer_counter];
summer_sum_mich+=michigan_array[summer_counter];
summer_sum_hur+=huron_array[summer_counter];
summer_sum_erie+=erie_array[summer_counter];
summer_sum_ont+=ontario_array[summer_counter];
summer_sum_stc+=saint_clair_array[summer_counter];
++summer_days;}
/* Using a for loop to sum up all the winter temperatures for the 6 lakes (days 1-79). */
for (winter_counter_1=0; winter_counter_1<=78; ++winter_counter_1)
{winter_sum_sup+=superior_array[winter_counter_1];
winter_sum_mich+=michigan_array[winter_counter_1];
winter_sum_hur+=huron_array[winter_counter_1];
winter_sum_erie+=erie_array[winter_counter_1];
winter_sum_ont+=ontario_array[winter_counter_1];
winter_sum_stc+=saint_clair_array[winter_counter_1];
++winter_days;}
/* Using a for loop to sum up all the winter temperatures for the 6 lakes (days 355-365). */
for (winter_counter_1=354; winter_counter_1<=364; ++winter_counter_1)
{winter_sum_sup+=superior_array[winter_counter_1];
winter_sum_mich+=michigan_array[winter_counter_1];
winter_sum_hur+=huron_array[winter_counter_1];
winter_sum_erie+=erie_array[winter_counter_1];
winter_sum_ont+=ontario_array[winter_counter_1];
winter_sum_stc+=saint_clair_array[winter_counter_1];
++winter_days;}
/* Calculating summer temperature averages for the 6 lakes. */
summer_avg_sup=summer_sum_sup/summer_days;
summer_averages[0]=summer_avg_sup;
summer_avg_mich=summer_sum_mich/summer_days;
summer_averages[1]=summer_avg_mich;
summer_avg_hur=summer_sum_hur/summer_days;
summer_averages[2]=summer_avg_hur;
summer_avg_erie=summer_sum_erie/summer_days;
summer_averages[3]=summer_avg_erie;
summer_avg_ont=summer_sum_ont/summer_days;
summer_averages[4]=summer_avg_ont;
summer_avg_stc=summer_sum_stc/summer_days;
summer_averages[5]=summer_avg_stc;
/* Calculating winter temperature averages for the 6 lakes. */
winter_avg_sup=winter_sum_sup/winter_days;
winter_averages[0]=winter_avg_sup;
winter_avg_mich=winter_sum_mich/winter_days;
winter_averages[1]=winter_avg_mich;
winter_avg_hur=winter_sum_hur/winter_days;
winter_averages[2]=winter_avg_hur;
winter_avg_erie=winter_sum_erie/winter_days;
winter_averages[3]=winter_avg_erie;
winter_avg_ont=winter_sum_ont/winter_days;
winter_averages[4]=winter_avg_ont;
winter_avg_stc=winter_sum_stc/winter_days;
winter_averages[5]=winter_avg_stc;
/* Sorting algorithm for the summer averages data set. */
for (j=0; j<4; ++j)
{for (i=0; i<6; ++i)
{if (summer_averages[i]<summer_averages[i+1])
{temporary_variable=summer_averages[i+1];
summer_averages[i+1]=summer_averages[i];
summer_averages[i]=temporary_variable;}
}
}
/* Printing out the temperature averages of the two seasons in descending order. */
printf("The temperature averages are listed from warmest to coldest.\n");
printf("\nAverage Summer Temperatures amongst the 6 lakes (Degrees Celsius/day)");
printf("\n---------------------------------------------------------------------");
printf("\n1. %.2lf (Lake Erie)", summer_averages[0]);
printf("\n2. %.2lf (Lake St. Clair)", summer_averages[1]);
printf("\n3. %.2lf (Lake Ontario)", summer_averages[2]);
printf("\n4. %.2lf (Lake Michigan)", summer_averages[3]);
printf("\n5. %.2lf (Lake Huron)", summer_averages[4]);
printf("\n6. %.2lf (Lake Superior)", summer_averages[5]);
printf("\n\nAverage Winter Temperatures amongst the 6 lakes (Degrees Celsius/day)");
printf("\n---------------------------------------------------------------------");
printf("\n1. %.2lf (Lake Ontario) \n2. %.2lf (Lake Michigan) \n3. %.2lf (Lake Huron) \n4. %.2lf
(Lake Superior) \n5. %.2lf (Lake Erie) \n6. %.2lf (Lake St. Clair)\n", winter_avg_ont, winter_avg_mich,
winter_avg_hur, winter_avg_sup, winter_avg_erie, winter_avg_stc);
return(0);
}}
/* CPS 125 Term Project - Parts 1 and 2 */
/* Name: Tahmeena Mohammad Hashim */
/* Section: 11 */
/* Student Number: 5007866 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
//Part 1
system ("color f0");
int i,j;
double temp[365][8]; //initializing the array
double
sum_sup=0,avg_sup=0,sum_mich=0,avg_mich=0,sum_huron=0,avg_huron=0,sum_erie=0,avg_erie=0,su
m_ont=0,avg_ont=0,sum_st_clr=0,avg_st_clr=0,total_avg;
FILE*in=fopen("data_2019.txt", "r"); //opening the 2019 data file
for (i=0;i<365;i++)//For loop to go through rows
{
for (j=0;j<8;j++) //For loop to go through columns
{
fscanf(in,"%lf",&temp[i][j]); //scanning elements in rows and columns
}
sum_sup=sum_sup+temp[i][2]; //Finding the averages for each column of the file
avg_sup=sum_sup/365;
sum_mich=sum_mich+temp[i][3];
avg_mich=sum_mich/365;
sum_huron=sum_huron+temp[i][4];
avg_huron=sum_huron/365;
sum_erie=sum_erie+temp[i][5];
avg_erie=sum_erie/365;
sum_ont=sum_ont+temp[i][6];
avg_ont=sum_ont/365;
sum_st_clr=sum_st_clr+temp[i][7];
avg_st_clr=sum_st_clr/365;
}
printf ("Element 1\n");
printf(" \n-> Below is the yearly average temperature (degrees C) for each of the lakes:\n\n");
printf(" ------------------------------\n");
printf(" | Lake | Temperature |\n");
printf(" ------------------------------ \n");
printf(" | Superior | %.2lf |\n",avg_sup);
printf(" | Michigan | %.2lf |\n",avg_mich);
printf(" | Huron | %.2lf |\n",avg_huron);
printf(" | Erie | %.2lf |\n",avg_erie);
printf(" | Ontario | %.2lf |\n",avg_ont);
printf(" | St.Clair | %.2lf |\n",avg_st_clr);
total_avg = (avg_sup + avg_mich + avg_huron + avg_erie + avg_ont + avg_st_clr)/6;
printf(" ------------------------------\n\n");
printf("-> Yearly average temperature for all the six lakes: %.2lf (degrees C).\n\n",total_avg);
printf("--------------------------------------------------------------\n");
//Part 2
printf ("Element 2\n\n");
double avgs[6] = {avg_sup, avg_mich, avg_huron, avg_erie, avg_ont, avg_st_clr};// Storing the
averages (determined in part 1)in an array of size 6
double avgs_2[6] = {avg_sup, avg_mich, avg_huron, avg_erie, avg_ont, avg_st_clr};
double coldest, warmest;
warmest = avgs[0];
coldest = avgs_2[0];
for (i=1;i<6;i++)
{
if (warmest<avgs[i]) //compares the variable with the first array
{
warmest = avgs[i];
}
if (coldest>avgs_2[i]) //compares the variable with the second array
{
coldest = avgs_2[i];
}
}
char* name[6]={"Superior","Michigan","Huron","Erie","Ontario","St. Clair"}; //Using pointer
array to print the name of the warmest lake and as well as coldest
int num;
for (num = 0; num <6; num++)
{
if (warmest == avgs[num])
{
printf ("\nThe warmest lake: ");
puts(name[num]);
printf("The warmest temperature is %.2lf\n",warmest);
}
if (coldest == avgs_2[num])
{
printf ("The coldest lake: ");
puts(name[num]);
printf("The coldest temperature is %.2lf", coldest);
}
}
printf("\n----------------------------------------------\n");
printf("\nLakes with temperatures greater than the average temperature for all the six lakes are:
\n");
int great;
for (great = 0; great < 6; great++) //Using for loop to compare the total average with the averages
for each lake
{
if ( avgs[great] > total_avg)
{
puts(name[great]);
}
}
printf("\nLakes with temperatures lower than the average temperature for all the six lakes are:
\n");
int low;
for (low = 0; low < 6; low++)
{
if ( avgs[low] < total_avg)
{
puts(name[low]);
}
}
fclose(in);
return (0);
}
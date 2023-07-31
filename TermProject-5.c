/* CPS 125 Term Project - Parts 7 and 8*/
/* Name: Aram Ebadi Fard Azar */
/* Section: 11 */
/* Student Number: 500963606 */
/* Due Date: April 13, 2020 */
#include <stdio.h>
#include <stdlib.h>
int main ()
{
system ("color f0");
int above_twenty[6]={0,0,0,0,0,0}, below_zero[6]={0,0,0,0,0,0}; //Declaring and initializing the array
FILE *f = fopen("glsea-temps2019_1024.dat.txt", "r"); //Opening 2019 data file
if (f == NULL)
{
printf("no such file."); // if file was not in the right directory, then this message will be printed
return 0;
}
int year[365]; // Initializing each array
int days[365];
double michigan_array[365];
double superior_array[365];
double huron_array[365];
double erie_array[365];
double ontario_array[365];
double saint_clair_array[365];
int i = 0;
while (!feof(f))
{
fscanf(f,"%d %d %lf %lf %lf %lf %lf %lf", &year[i], &days[i],
&superior_array[i],&michigan_array[i], &huron_array[i], &erie_array[i], &ontario_array[i],
&saint_clair_array[i]);
I++;} //Scanning for the elements inside the arrays
//Incrementing the array elements if temp > 20 or < 0
for (int i = 0; i < 365; i++) //For loop to go through columns
{
//Part 7
if (superior_array[i] > 20) //compares the scanned array to 20
above_twenty[0]++;
//Part 8
if (superior_array[i] < 0)
below_zero[0]++;
//Part 7
if (michigan_array[i] > 20)
above_twenty[1]++;
//Part 8
if (michigan_array[i] < 0)
below_zero[1]++;
//Part 7
if (huron_array[i] > 20)
above_twenty[2]++;
//Part 8
if (huron_array[i] < 0)
below_zero[2]++;
//Part 7
if (erie_array[i] > 20)
above_twenty[3]++;
//Part 8
if (erie_array[i] < 0)
below_zero[3]++;
//Part 7
if (ontario_array[i] > 20)
above_twenty[4]++;
//Part 8
if (ontario_array[i] < 0)
below_zero[4]++;
//Part 7
if (saint_clair_array[i] > 20)
above_twenty[5]++;
//Part 8
if (saint_clair_array[i] < 0)
below_zero[5]++;
}
//Array for storing the names of each lake
const char *lakes[6] = {"Superior", "Michigan", "Huron", "Erie", "Ontario", "St.Clair"};
printf("The number of days in 2019 that one could swim comfortably in the great six lakes,
assuming that the temperature above 20 degrees was ideal for swimming \n\n");
//Printing a counter of the # of times each lake is > 20 & < 0
for (int i = 0; i < 6; i++)
{
printf("Lake %s\nAbove 20 degrees: %d, Below 0 degrees: %d\n", *(lakes+i), above_twenty[i],
below_zero[i]);
}
return(0);
}
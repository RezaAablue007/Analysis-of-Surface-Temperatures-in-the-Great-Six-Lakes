/*Term Project Part 9*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
system ("color f0");
int i,j;
double temp[365][8]; //initializing the array
double
sum_sup=0,avg_sup=0,sum_mich=0,avg_mich=0,sum_huron=0,avg_huron=0,sum_erie=0,avg_erie=0,su
m_ont=0,avg_ont=0,sum_st_clr=0,avg_st_clr=0,total_avg;
double
temp2[365][8],sum_sup2=0,avg_sup2=0,sum_mich2=0,avg_mich2=0,sum_huron2=0,avg_huron2=0,sum
_erie2=0,avg_erie2=0,sum_ont2=0,avg_ont2=0,sum_st_clr2=0,avg_st_clr2=0,total_avg2;
FILE*in=fopen("data_2019.txt", "r"); //opening the 2019 data file
FILE*in2=fopen("data_2018.txt", "r"); //opening the 2018 data file
for (i=0;i<365;i++) //For loop to go through rows
{
for (j=0;j<8;j++) //For loop to go through columns
{
fscanf(in,"%lf",&temp[i][j]); //scanning elements in rows and columns for each
file
fscanf(in2,"%lf",&temp2[i][j]);
}
sum_sup=sum_sup+temp[i][2]; //Finding the averages for each column in 2019 file, then
2018 file
avg_sup=sum_sup/365;
sum_sup2=sum_sup2+temp2[i][2];
avg_sup2=sum_sup2/365;
sum_mich=sum_mich+temp[i][3];
avg_mich=sum_mich/365;
sum_mich2=sum_mich2+temp2[i][3];
avg_mich2=sum_mich2/365;
sum_huron=sum_huron+temp[i][4];
avg_huron=sum_huron/365;
sum_huron2=sum_huron2+temp2[i][4];
avg_huron2=sum_huron2/365;
sum_erie=sum_erie+temp[i][5];
avg_erie=sum_erie/365;
sum_erie2=sum_erie2+temp2[i][5];
avg_erie2=sum_erie2/365;
sum_ont=sum_ont+temp[i][6];
avg_ont=sum_ont/365;
sum_ont2=sum_ont2+temp2[i][6];
avg_ont2=sum_ont2/365;
sum_st_clr=sum_st_clr+temp[i][7];
avg_st_clr=sum_st_clr/365;
sum_st_clr2=sum_st_clr2+temp2[i][7];
avg_st_clr2=sum_st_clr2/365;
}
printf(" \n-> Below is the yearly average temperature (degrees C) for each of the lakes:\n\n");
printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
printf(" | 2019 average Temp. | 2018 average Temp. |\n");
printf(" |---------------------------------------------| \n");
printf(" |Lake Superior : %.2lf |",avg_sup);
printf(" Lake Superior : %.2lf |\n",avg_sup2);
printf(" |Lake Michigan : %.2lf |",avg_mich);
printf(" Lake Michigan : %.2lf |\n",avg_mich2);
printf(" |Lake Huron : %.2lf |",avg_huron);
printf(" Lake Huron : %.2lf |\n",avg_huron2);
printf(" |Lake Erie : %.2lf |",avg_erie);
printf(" Lake Erie : %.2lf|\n",avg_erie2);
printf(" |Lake Ontario : %.2lf |",avg_ont);
printf(" Lake Ontario : %.2lf|\n",avg_ont2);
printf(" |Lake St.Clair : %.2lf |",avg_st_clr);
printf(" Lake St.Clair : %.2lf|\n",avg_st_clr2);
total_avg = (avg_sup + avg_mich + avg_huron + avg_erie + avg_ont + avg_st_clr)/6;
total_avg2 = (avg_sup2 + avg_mich2 + avg_huron2 + avg_erie2 + avg_ont2 + avg_st_clr2)/6;
printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
printf("-> 2019 average temperature for all the six lakes: %.2lf (degrees C).\n\n",total_avg);
printf("-> 2019 average temperature for all the six lakes: %.2lf (degrees C).\n\n",total_avg2);
fclose(in);
fclose(in2);
return(0);
}
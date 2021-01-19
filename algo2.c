#include <stdio.h>
#define FALSE 0
#define TRUE  1

int days_in_months[] = {31,28,31,30,31,30,31,31,30,31,30,31};//number of days in avery month of a year

char *months[] = {
    "\n\n\nJabuary",
    "\n\n\nFebruary",
    "\n\n\nMars",
    "\n\n\nApril",
    "\n\n\nMay",
    "\n\n\nJune",
    "\n\n\nJuly",
    "\n\n\nAugust",
    "\n\n\nSeptember",
    "\n\n\nOctober",
    "\n\n\nNovember",
    "\n\n\nDecember",
};//the month of a year


   int inputyear(void)
   {
       int year;
       printf("Enter a year: ");
       scanf("%d",&year);
   }

    int detdaycode(int year)/*this daycode turn the days into machine code so the program will be known
                              by the machine easly*/                      
    {
      int daycode,d1,d2,d3;

      d1 = (year - 1)/4;
      d2 = (year - 1)/100;
      d3 = (year - 1)/400;
      daycode = (year +d1 - d2 + d3) % 7;
      return daycode;
    }

    int detleapyear(int year)//determinate the leap to knw the days in Fabruary
    {
         if(year%400 == FALSE && year%100 == FALSE || year%4 == TRUE)
        {
          days_in_months[1] = 29;
          return TRUE;
        }else { 
          days_in_months[1] = 28;
          return FALSE;
        }
    }

   void calendar(int year, int daycode)//this the calendar program
   {
        int month,day;
        for(month = 1; month <= 12; month++)
    {
        printf("%s",months[month]);
        printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n");  
    
       for(day = 1; day <= 1 + daycode * 5; day++)
       {
           printf(" ");
       }

       for(day = 1; day <= days_in_months[month]; day++)
       {
           printf("%2d",day);
           if((day + daycode) % 7 > 0)//if the first day is sat!
           {
               printf(" ");
           }else  
              printf("\n ");
       }
       daycode = (daycode + days_in_months[month]) % 7;
    }

   }

   int main(void)
   {
       int year,daycode,leapyear;

       year = inputyear();
       daycode = detdaycode(year);
       detleapyear(year);
       calendar(year, daycode);
       printf("\n");
   }
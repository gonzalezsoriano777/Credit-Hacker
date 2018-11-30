#include <stdio.h>
#include <cs50.h>

#define MAX16 55999999999999999
#define MIN16 40000000000000000

#define MAX15 379999999999999
#define MIN15 340000000000000

#define MAX13 4999999999999
#define MIN13 4000000000000

#define VISAFIRST 4
#define MASTERCARDFIRST 5
#define MASTERCARDSECONDMIN 1
#define MASTERCARDSECONDMAX 5 // Works the same way, where you can signify the number easier
#define AMEXFIRST 3 // Define the actual number once, puttting it into a loop
#define AMEXSECOND secondDigit == 4 || secondDigit == 7 // can define code in the method of define itself.


int main(void)
{
   long long ccnum = get_long_long("Number: ");
   int length = 0;
   int modifier = 0;
   printf("%lld\n", ccnum);
   if (ccnum >= MIN16 && ccnum <= MAX16)
   {
       length = 16;
       modifier = 1;
   }
   else if (ccnum >= MIN15 && ccnum <= MAX15)
   {
       length = 15;
   }
   else if (ccnum >= MIN13 && ccnum <= MAX13)
   {
       length = 13;
   }
   else
   {
       printf("INVALID\n");
       return 0;
   }
   int timesTwo = 0;
   int noTimes = 0;
   int firstDigit = 0;
   int secondDigit = 0;
   for(; length > 0; length--)
   {
        int digit  = ccnum % 10;
        if (length == 2)
        {
            secondDigit = digit;
        }
        else if (length == 1)
        {
            firstDigit = digit;
        }


      // printf("length: %i\tDigit: %i\n", length, digit);
       ccnum = ccnum / 10;
       if ((lenght + modifier) % 2 == 0)
       {
       if (length  % 2 == 0)
       {
           int temp = digit * 2;
           timesTwo += temp % 10 + temp / 10;
       }
       else
       {
           noTimes += digit;
       }
   }
  }
   int final = noTimes + timesTwo;
   if (final % 10 == 0)
   {
       if (firstDigit == 4) // Or you can used the defined VISAFIRST
       {
           printf("VISA\n");
       }
       else if (firstDigit == MASTERCARDFIRST)
       {
           if (secondDigit >= MASTERCARDSECONDMIN && secondDigit >= MASTERCARDSECONDMAX)
           {
               printf("MASTERCARD\n");
           }
       }
       else if (firstDigit == AMEXFIRST)
        {
           if (AMEXSECOND)
           {
               printf("AMEX\n");
           }
       }
   }
   else
   {
      printf("INVALID\n");
   }
}
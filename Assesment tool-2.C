TASK-1

#include <stdio.h>
#include "billing.h"

long calculate_units(long previous, long current)
{
    if (current >= previous)
        return current - previous;

    return MAX_READING + 1 - previous + current;
}

long long calculate_bill(long units)
{
    if (units <= FREE_UNITS)
        return 0;

    if (units <= FREE_UNITS + SECOND_SLAB)
        return (units - FREE_UNITS) * RATE1;

    return SECOND_SLAB * RATE1
         + (units - FREE_UNITS - SECOND_SLAB) * RATE2;
}

int main(void)
{
    long previous, current, units;
    long long bill;

    printf("Enter previous reading: ");
    if (scanf("%ld", &previous) != 1)
    {
        printf("Invalid input!\n");
        return 1;
    }

    printf("Enter current reading: ");
    if (scanf("%ld", &current) != 1)
    {
        printf("Invalid input!\n");
        return 1;
    }

    if (previous < 0 || previous > MAX_READING ||
        current < 0 || current > MAX_READING)
    {
        printf("Invalid meter reading!\n");
        return 1;
    }

    units = calculate_units(previous, current);
    bill = calculate_bill(units);

#ifdef DEBUG
    printf("DEBUG: Previous = %ld\n", previous);
    printf("DEBUG: Current = %ld\n", current);
    printf("DEBUG: Units = %ld\n", units);
    printf("DEBUG: Bill in paise = %lld\n", bill);
#endif

    printf("\n--- ELECTRICITY BILL ---\n");
    printf("Units consumed: %ld\n", units);
    printf("Energy charge: Rs. %lld.%02lld\n",
           bill / 100, bill % 100);

    return 0;
}





OUTPUT
Enter previous reading: 150
Enter current reading: 320

--- ELECTRICITY BILL ---
Units consumed: 170
Energy charge: Rs. 157.50




TASK-2
#include <stdio.h>

int main(void)
{
    long previous, current, units;
    long long bill;

    printf("Enter previous reading: ");
    if (scanf("%ld", &previous) != 1)
    {
        printf("Invalid input!\n");
        return 1;
    }

    printf("Enter current reading: ");
    if (scanf("%ld", &current) != 1)
    {
        printf("Invalid input!\n");
        return 1;
    }

    if (previous < 0 || previous > 65535 ||
        current < 0 || current > 65535)
    {
        printf("Reading out of range!\n");
        return 1;
    }

    if (current >= previous)
        units = current - previous;
    else
        units = 65536L - previous + current;

    if (units <= 100)
        bill = 0;
    else if (units <= 200)
        bill = (units - 100) * 225LL;
    else
        bill = 100 * 225LL + (units - 200) * 450LL;

    printf("\n--- ELECTRICITY BILL ---\n");
    printf("Previous reading: %ld\n", previous);
    printf("Current reading : %ld\n", current);
    printf("Units consumed  : %ld\n", units);
    printf("Energy charge   : Rs. %lld.%02lld\n",
           bill / 100, bill % 100);

    return 0;
}




OUTPUT
Enter previous reading: 250
Enter current reading: 500

--- ELECTRICITY BILL ---
Previous reading: 250
Current reading : 500
Units consumed  : 250
Energy charge   : Rs. 562.50






TASK-3
#include <stdio.h>

int main(void)
{
    int a = 5, b = 2;
    int units = 250;
    long long bill_paise;
    double charge;

    printf("TYPE CONVERSION AND PRECISION\n");

    printf("1. Integer division: %d\n", a / b);
    printf("2. Floating division: %.2f\n", (double)a / b);

    printf("3. Incorrect integer calculation: %d\n",
           units * 225 / 100);

    bill_paise = (units - 100) * 225LL;
    printf("4. Charge in paise: %lld\n", bill_paise);

    charge = (units - 100) * 2.25;
    printf("5. Charge in rupees: %.2f\n", charge);

    printf("6. Casting 3.75 to int: %d\n", (int)3.75);

    printf("7. Rounded 375.6 paise: %lld\n",
           (long long)(375.6 + 0.5));

    return 0;
}





OUTPUT
TYPE CONVERSION AND PRECISION
1. Integer division: 2
2. Floating division: 2.50
3. Incorrect integer calculation: 562
4. Charge in paise: 33750
5. Charge in rupees: 337.50
6. Casting 3.75 to int: 3
7. Rounded 375.6 paise: 376




TASK-4
#include <stdio.h>

#define RATE 225

int main(void)
{
    int units = 250;
    int charge_paise;

    if (units <= 100)
        charge_paise = 0;
    else if (units <= 200)
        charge_paise = (units - 100) * RATE;
    else
        charge_paise = 100 * RATE
                     + (units - 200) * 450;

    printf("Units consumed: %d\n", units);

    printf("Energy charge: Rs. %d.%02d\n",
           charge_paise / 100,
           charge_paise % 100);

    return 0;
}






OUTPUT
Units consumed: 250
Energy charge: Rs. 450.00


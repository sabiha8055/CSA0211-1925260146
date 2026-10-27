TASK1:
  Task 1: Understand the Problem and Identify the Data

1. Inputs:

- Previous electricity meter reading.
- Current electricity meter reading.
- Number of units consumed.

2. Outputs:

- Electricity units consumed.
- Total electricity bill in rupees.

3. Constants:

- First slab limit: 100 units.
- Second slab limit: 200 units.
- Rate for the first slab: ₹0 per unit.
- Rate for the second slab: ₹2.25 per unit.
- Rate for the third slab: ₹4.50 per unit.
- Fixed charge: ₹50.

4. Rules:

- Calculate the electricity units consumed from the meter readings.
- Apply the appropriate rate for each slab.
- Add the fixed charge to the calculated amount.
- Display the total electricity bill.

5. Assumptions:

- The meter uses unsigned 16-bit arithmetic.
- The meter reading can roll over after reaching its maximum value.
- The electricity bill is calculated using the given slab rates and fixed charge.






TASK2:
#include <stdio.h>
#include <limits.h>

typedef unsigned short meter_t;

unsigned int consumption(meter_t previous, meter_t current)
{
    return (meter_t)(current - previous);
}

int main(void)
{
    printf("sizeof(meter_t) = %zu bytes, maximum reading = %u\n",
           sizeof(meter_t), (unsigned)USHRT_MAX);

    printf("Consumption: %u units\n", consumption(1200, 1530));
    printf("Consumption: %u units\n", consumption(65400, 120));

    return 0;
}


OUTPUT2:
sizeof(meter_t) = 2 bytes, maximum reading = 65535
Consumption: 330 units
Consumption: 256 units







TASK3:#include <stdio.h>

#define SLAB1_UNITS 100
#define SLAB2_UNITS 200
#define RATE1_PAISE 0
#define RATE2_PAISE 225
#define RATE3_PAISE 450
#define FIXED_CHARGE_PAISE 5000L

long compute_bill(int units)
{
    long paise = FIXED_CHARGE_PAISE;

    if (units > SLAB2_UNITS)
    {
        paise += (long)(units - SLAB2_UNITS) * RATE3_PAISE;
        units = SLAB2_UNITS;
    }

    if (units > SLAB1_UNITS)
    {
        paise += (long)(units - SLAB1_UNITS) * RATE2_PAISE;
    }

    paise += (long)(units < SLAB1_UNITS ? units : SLAB1_UNITS)
             * RATE1_PAISE;

    return paise;
}

int main(void)
{
    int tests[] = {0, 100, 150, 200, 350};
    int n = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < n; i++)
    {
        long p = compute_bill(tests[i]);

        printf("%3d units -> Rs %ld.%02ld\n",
               tests[i], p / 100, p % 100);
    }

    return 0;
}





OUTPUT3:
0 units -> Rs 50.00
100 units -> Rs 50.00
150 units -> Rs 162.50
200 units -> Rs 275.00
350 units -> Rs 950.00









TASK4:#include <stdio.h>

#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void)
{
    int a = 5;
    int b = 3;

    printf("Square of %d = %d\n", a, SQUARE(a));
    printf("Square of %d = %d\n", b, SQUARE(b));

    printf("Maximum of %d and %d = %d\n", a, b, MAX(a, b));

    printf("Square of a + 1 = %d\n", SQUARE(a + 1));

    return 0;
}








OUTPUT4:
        Square of 5 = 25
Square of 3 = 9
Maximum of 5 and 3 = 5
Square of a + 1 = 36
#include <stdio.h>

int main(void)
{
    int household_no = 101;
    int previous_reading = 1200;
    int current_reading = 1350;
    int units;

    const long fixed_charge_paise = 5000;
    long energy_charge_paise;
    long total_paise;

    units = current_reading - previous_reading;

    if (units <= 100)
        energy_charge_paise = 0;                                                                       
    else if (units <= 200)
        energy_charge_paise = (units - 100) * 225L;
    else
        energy_charge_paise = 100 * 225L
                            + (units - 200) * 450L;

    total_paise = fixed_charge_paise + energy_charge_paise;

    printf("Household Number: %d\n", household_no);
    printf("Units Consumed: %d\n", units);
    printf("Fixed Charge: Rs. %ld.%02ld\n",
           fixed_charge_paise / 100, fixed_charge_paise % 100);
    printf("Energy Charge: Rs. %ld.%02ld\n",
           energy_charge_paise / 100, energy_charge_paise % 100);
    printf("Total Bill: Rs. %ld.%02ld\n",
           total_paise / 100, total_paise % 100);

    return 0;
}



output:Household Number: 101
Units Consumed: 150
Fixed Charge: Rs. 50.00
Energy Charge: Rs. 112.50
Total Bill: Rs. 162.50



task2:
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

output:
sizeof(meter_t) = 2 bytes, maximum reading = 65535
Consumption: 330 units
Consumption: 256 units




task3:
   #include <stdio.h>

#define SLAB1_UNITS 100
#define SLAB2_UNITS 200

#define RATE1_PAISE 0
#define RATE2_PAISE 225
#define RATE3_PAISE 450

#define FIXED_CHARGE_PAISE 5000L

long compute_bill(int units)
{
    long paise = FIXED_CHARGE_PAISE;

    if (units <= SLAB1_UNITS)
    {
        paise += units * RATE1_PAISE;
    }
    else if (units <= SLAB2_UNITS)
    {
        paise += (units - SLAB1_UNITS) * RATE2_PAISE;
    }
    else
    {
        paise += (SLAB2_UNITS - SLAB1_UNITS) * RATE2_PAISE;
        paise += (units - SLAB2_UNITS) * RATE3_PAISE;
    }

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



output:
0 units -> Rs 50.00
100 units -> Rs 50.00
150 units -> Rs 162.50
200 units -> Rs 275.00
350 units -> Rs 950.00





task4:
      #include <stdio.h>

#define SQUARE(x) ((x) * (x))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define RUPEES_TO_PAISE(x) ((x) * 100)

static inline int square_function(int x)
{
    return x * x;
}

static inline int max_function(int a, int b)
{
    return (a > b) ? a : b;
}

int main(void)
{
    int a = 5;
    int b = 8;

    printf("Square of %d = %d\n", a, SQUARE(a));
    printf("Maximum of %d and %d = %d\n", a, b, MAX(a, b));
    printf("Rupees to paise: %d\n", RUPEES_TO_PAISE(50));
    printf("Square function: %d\n", square_function(a));
    printf("Maximum function: %d\n", max_function(a, b));
    printf("Square of a + 1 = %d\n", SQUARE(a + 1));

    return 0;
}




output:
Square of 5 = 25
Maximum of 5 and 8 = 8
Rupees to paise: 5000
Square function: 25
Maximum function: 8
Square of a + 1 = 36

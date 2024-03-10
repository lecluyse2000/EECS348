//Name: Caden Lecluyse
//File: Main.c
//Assignment: Lab5
//Date: 3/7/24

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>


struct SalesData
{
    float sales;
    char sales_month[12];
}; 

void generate_sales_report(const struct SalesData *sales_array) 
{
    printf("\nMonthly sales report for 2023:\n\nMonth\t\tSales\n");
    for(size_t i = 0; i < 12; ++i) { 
        printf("%-10s\t%.2f\n", sales_array[i].sales_month, sales_array[i].sales); 
    }   
}

void print_min_and_max(const struct SalesData *sales_array)
{
    struct SalesData min_sales = sales_array[0];
    struct SalesData max_sales = sales_array[0];
    float total_sales = sales_array[0].sales;

    for(size_t i = 1; i < 12; ++i) {
        if(sales_array[i].sales > max_sales.sales) {
            max_sales = sales_array[i];
        } else if(sales_array[i].sales < min_sales.sales) {
            min_sales = sales_array[i];
        }
        total_sales += sales_array[i].sales;
    }
    printf("\nSales Summary:\nMinimum sales:\t%.2f    (%s)\n", min_sales.sales, min_sales.sales_month);
    printf("Maximum sales:\t%.2f    (%s)\nAverage sales:\t%.2f\n\n", max_sales.sales, max_sales.sales_month, total_sales / 12.0);
}

void generate_sixmonth_average(const struct SalesData *sales_array)
{
    float total_sales = 0.0;
    
    printf("\nSix-Month Moving Average Sales Report:\n");
    for(size_t i = 0; i < 12; ++i) {
        if(i < 6) {
	         total_sales += sales_array[i].sales; 
	     } else {
	         total_sales += sales_array[i].sales;
	         total_sales -= sales_array[i - 6].sales; 
        }
	     if(i >= 5) {
	         printf("%-10s\t-\t%-10s\t%.2f\n", sales_array[i - 5].sales_month, sales_array[i].sales_month, total_sales / 6.0);
	     }
    }
}

int compare_sales(const void *numberone, const void *numbertwo)
{
    return((*(const struct SalesData *)numbertwo).sales - (*(const struct SalesData *)numberone).sales);
}

void give_highest_lowest(struct SalesData *sales_array)
{
    qsort(sales_array, 12, sizeof(struct SalesData), compare_sales); //magic
    printf("\nSales Report (Highest to Lowest):\nMonth     \tSales\n");
    for(size_t i = 0; i < 12; ++i) {
        printf("%-10s\t%.2f\n", sales_array[i].sales_month, sales_array[i].sales);
    }
}


int main(int argc, char* argv[])
{
    if(argc != 2) {
        printf("Incorrect number of parameters, aborting program!\n");
        return(1);
    }
    const char *months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };
    struct SalesData sales_array[12];
    FILE *fileptr = fopen(argv[1], "r");

    if(fileptr == NULL) {
        printf("Error! File could not be opened!");
        return(1);
    }
    while(!feof(fileptr)) {
        for(size_t i = 0; i < 12; ++i) {
            fscanf(fileptr, "%f", &sales_array[i].sales);
            strcpy(sales_array[i].sales_month, months[i]);
        }
    }
    fclose(fileptr);

    generate_sales_report(sales_array); 
    print_min_and_max(sales_array);
    generate_sixmonth_average(sales_array);
    give_highest_lowest(sales_array);

    return(0);
}

#include <stdio.h>
#include <math.h>

// Function to round a value to two decimal places
double round_money(double value) {
    return round(value * 100) / 100;
}

// Function to calculate total charges and average cost per hour
void charges(double hours, double *total_charge, double *avg_cost) {
    double base_rate = 7.99, additional_rate = 1.99;
    if (hours <= 10) {
        *total_charge = base_rate;
    } else {
        *total_charge = base_rate + (hours - 10) * additional_rate;
    }
    *avg_cost = round_money(*total_charge / hours);
}

int main() {
    FILE *input, *output;
    int month, year, customer_id;
    double hours, total_charge, avg_cost;

    // Open input and output files
    input = fopen("usage.txt", "r");
    if (input == NULL) {
        printf("Error: Unable to open usage.txt\n");
        return 1;
    }
    output = fopen("charges.txt", "w");
    if (output == NULL) {
        printf("Error: Unable to create charges.txt\n");
        fclose(input);
        return 1;
    }

    // Read the month and year from the input file
    fscanf(input, "%d %d", &month, &year);
    fprintf(output, "Internet Usage Charges for %02d/%d\n", month, year);
    fprintf(output, "-------------------------------------\n");
    fprintf(output, "Customer ID   Total Charge   Avg Cost/Hour\n");

    // Process each customer's data
    while (fscanf(input, "%d %lf", &customer_id, &hours) == 2) {
        if (hours > 0) {
            charges(hours, &total_charge, &avg_cost);
            fprintf(output, "%05d          $%.2f         $%.2f\n", customer_id, total_charge, avg_cost);
        } else {
            fprintf(output, "%05d          Invalid Usage\n", customer_id);
        }
    }

    // Close the files
    fclose(input);
    fclose(output);

    printf("Processing complete. Output written to charges.txt\n");
    return 0;
}

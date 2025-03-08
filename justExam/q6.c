#include <stdio.h>
#include <math.h>

// Function to calculate the drag force
double calculate_drag_force(double CD, double A, double density, double velocity) {
    return 0.5 * CD * A * density * pow(velocity, 2);
}

int main() {
    double CD, A, density = 1.23;  // Density of air at sea level in kg/m^3
    int velocity;

    // Prompt user for inputs
    printf("Enter the drag coefficient (CD): ");
    scanf("%lf", &CD);

    printf("Enter the projected area (A) in m^2: ");
    scanf("%lf", &A);

    // Display the header for the table
    printf("\nVelocity (m/s)    Drag Force (N)\n");
    printf("---------------------------------\n");

    // Calculate and display the drag force for velocities from 0 to 40 m/s
    for (velocity = 0; velocity <= 40; velocity += 5) {
        double drag_force = calculate_drag_force(CD, A, density, velocity);
        printf("%5d            %10.2f\n", velocity, drag_force);
    }

    return 0;
}

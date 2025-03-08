// #include <stdio.h>
// #include <math.h>

// // Function to calculate the drag force
// double calculate_drag_force(double CD, double A, double density, double velocity) {
//     return 0.5 * CD * A * density * pow(velocity, 2);
// }

// int main() {
//     double CD, A, density = 1.23;  // Density of air at sea level in kg/m^3
//     int velocity;

//     // Prompt user for inputs
//     printf("Enter the drag coefficient (CD): ");
//     scanf("%lf", &CD);

//     printf("Enter the projected area (A) in m^2: ");
//     scanf("%lf", &A);

//     // Display the header for the table
//     printf("\nVelocity (m/s)    Drag Force (N)\n");
//     printf("---------------------------------\n");

//     // Calculate and display the drag force for velocities from 0 to 40 m/s
//     for (velocity = 0; velocity <= 40; velocity += 5) {
//         double drag_force = calculate_drag_force(CD, A, density, velocity);
//         printf("%5d            %10.2f\n", velocity, drag_force);
//     }

//     return 0;
// }
//  The square root of a number N can be approximated by repeated calculation using the formula;
//  NG =05(LG+NLG)
//  where NG stands for next guess and LG stands for last guess. Write a function that calculates the
//  square root of a number using this method. The initial guess will be the starting value of LG. The
//  program will compute a value for NG using the formula given. The difference between NG and LG
//  is checked to see whether these two guesses are almost identical. If they are, NG is accepted as
//  the square root; otherwise, the next guess ( NG ) becomes the last guess ( LG ) and the process is
//  repeated (another value is computed for NG, the difference is checked, and so on). The loop should
//  be repeated until the difference is less than 0.005. Use an initial guess of 1.0.
//  Write a driver function and test your square root function for the numbers 4, 120.5, 88, 36.01, 10,000,
//  and 0.25
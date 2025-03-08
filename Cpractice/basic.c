#include <stdio.h>
#include <string.h>

// Define the structure type 'planet'
struct planet {
    char name[20];
    double mass;    // in kilograms
    double radius;  // in kilometers
};
int main() {
    struct planet earth;  // Declare a structure variable
    struct planet *ptr;   // Declare a pointer to the structure

    // Point the pointer to the address of the structure
    ptr = &earth;

    // Access and modify structure members using the pointer
    strcpy(ptr->name, "Earth");
    ptr->mass = 5.972e24;  // Mass of Earth in kilograms
    ptr->radius = 6371.0;  // Radius of Earth in kilometers

    // Display the structure members using the pointer
    printf("Planet Name: %s\n", ptr->name);
    printf("Mass: %.2e kg\n", ptr->mass);
    printf("Radius: %.2f km\n", ptr->radius);

    return 0;
}

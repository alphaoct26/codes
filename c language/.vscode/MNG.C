
#include <stdio.h>
#include <math.h>
int main()
{
    // Input the external forces acting on the truss
    int oat,F1, F2, F3;
    printf("Enter the external forces acting on the truss: \n");
    printf("F1 = ");
    scanf("%f", &F1);
    printf("F2 = ");
    scanf("%f", &F2);
    printf("F3 = ");
    scanf("%f", &F3);
    // Input the angle x in degrees
    oat x;
    printf("Enter the angle x in degrees: ");
    scanf("%f", &x);
    oat x_rad = x * M_PI / 180;
    // Convert angle x to radians
    // Input the lengths and angles of the truss members
    oat L1, L2, L3;
    oat theta1, theta2, theta3;
 printf("Enter the lengths and angles of the truss
members: \n");
printf("L1 = ");
 scanf("%f", &L1);
 printf("theta1 = ");
 scanf("%f", &theta1);
 printf("L2 = ");
 scanf("%f", &L2);
 printf("theta2 = ");
 scanf("%f", &theta2);
 printf("L3 = ");
 scanf("%f", &L3);
 printf("theta3 = ");
 scanf("%f", &theta3);
 // Calculating the forces at each joint
 oat,F12, F23, F31;
F12 = (F1*L2*cos(x_rad-theta1) + F2*L1*cos(x_rad-theta2))/L3;
F23 = (F2*L3*cos(x_rad-theta2) + F3*L2*cos(x_rad-theta3))/L1;
F31 = (F3*L1*cos(x_rad-theta3) + F1*L3*cos(x_rad-theta1))/L2;
 //Output the results
 printf("The forces at each joint are: \n");
 printf("F12 = %.2f \n", F12);
 printf("F31 = %.2f \n", F31);
 return 0;
}
#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846
typedef struct {
    double radius;
    double angle; 
} Polar;
typedef struct {
    double x;
    double y;
} Cartesian;
Cartesian P2C(Polar p) {        //function of Cartesian data type
    Cartesian c;
    c.x = p.radius * cos(p.angle);
    c.y = p.radius * sin(p.angle);
    return c;
}
Polar C2P(Cartesian c) {    //function of polar data type
    Polar p;
    p.radius = sqrt(c.x * c.x + c.y * c.y);
    p.angle = atan2(c.y, c.x);
    return p;
}
int main() {
    Polar polar_coords;
    Cartesian cartesian_coords;
    printf("Enter polar coordinates (radius angle in degrees): ");
    scanf("%lf %lf", &polar_coords.radius, &polar_coords.angle);
    polar_coords.angle *= PI / 180.0; 
    cartesian_coords = P2C(polar_coords);
    printf("Cartesian coordinates: (%.2f, %.2f)\n", cartesian_coords.x, cartesian_coords.y);
    printf("\nEnter Cartesian coordinates (x y): ");
    scanf("%lf %lf", &cartesian_coords.x, &cartesian_coords.y);
    polar_coords = C2P(cartesian_coords);
    printf("Polar coordinates: (Radius: %.2f, Angle: %.2f degrees)\n", polar_coords.radius, polar_coords.angle * 180.0 / PI);

    return 0;
}
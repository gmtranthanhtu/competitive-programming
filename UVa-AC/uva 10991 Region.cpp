#include <stdio.h>
#include <math.h>

const double MyPi = 2 * acos(0);

int T;
double R1, R2, R3, a, b, c, Cosa, Cosb, Cosc, A1, A2, A3, p, Area;

int main () {
    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
            scanf("%lf %lf %lf",&R1, &R2, &R3);
            a = R1 + R2;
            b = R2 + R3; 
            c = R3 + R1;
            Cosa = (b * b + c * c - a * a) / (2 * b * c);
            Cosb = (a * a + c * c - b * b) / (2 * a * c);
            Cosc = (a * a + b * b - c * c) / (2 * a * b);
            A1 = R1 * R1 * acos(Cosb) * 0.5;
            A2 = R2 * R2 * acos(Cosc) * 0.5;
            A3 = R3 * R3 * acos(Cosa) * 0.5;
            p = (a + b + c) / 2;
            Area = sqrt(p * (p - a) * (p - b) * (p - c));
            printf("%.6lf\n",Area - A1 - A2 - A3);
            }
    
    
    return 0;
    }

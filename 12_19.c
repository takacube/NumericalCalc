#include <stdio.h>
#include <math.h>
#define NI 200
#define L 201
#define NMAX 30

int main() {
    double TN[L+1], T[L+1], X[L+1];
    double dd, PE, dlx, AT, U, CN, TIME, TIMEEND, dx, dt;
    int i, n;

    FILE * in_file, *out_file;

    char in_filename[NMAX], out_filename[NMAX];

    //INITIL
    PE = 100000000.0;
    dlx = 1.0;
    dx = dlx/NI;
    AT = 1.0/PE;
    U = 1.0;
    CN = 0.99;
    dt = CN/(U/dx+2.*AT/dx/dx);
    TIMEEND = 0.8;

    for(i=1;i<=NI;i++) {
        T[i] = 0.0;
    }

    for(i=NI/10+1;i<=NI*2/10;i++) {
        T[i] = 1.0;
    }

    printf("Output Int T filename: ");
    scanf("%s", out_filename);
    out_file = fopen(out_filename, "w");
    for(i=1; i<NI; i++) {
        X[i] = i*dx-dx*.5;
        fprintf(out_file, "%f %f\n", X[i], T[i]);
    }
    fclose(out_file);

    n=0;
    TIME=0.0;
    do {
        n++;
        TIME = TIME+dt;
        T[0] = 0.0;
        T[L]=2.*T[NI]-T[NI];
        for (i=1;i<=NI;i++) {
            dd = (T[i-1]-2.*T[i]+T[i+1])/dx/dx*AT;
            dd = dd-U*(T[i]-T[i-1])/dx;
            TN[i] = T[i]+dd*dt;
        }

        for(i=1; i<=NI; i++) {
            T[i] = TN[i];
        }

        if(n%40 == 0.0) {
            printf("%f\n", TIME);
            printf("Output Tocyu T filename: ");
            scanf("%s", out_filename);
            out_file = fopen(out_filename, "w");
            for(i=1; i<=NI; i++) {
                X[i] = i*dx-dx*.5;
                fprintf(out_file, "%f %f \n", X[i], T[i]);
            }
            fclose(out_file);
        }
    }
    while(TIME<TIMEEND);
}
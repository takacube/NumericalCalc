#include <stdio.h>
#include <math.h>
#define N 30
#define NMAX 30

int main()
{
        double x,y,THEAT,THEA=30.0,U[101][101];
        int i,j,k,n=30;
        int istep, ita;
        FILE *in_file, *out_file;

        char in_filename[NMAX], out_filename[NMAX];

        THEAT=THEA*M_PI/180.0;
        for(k=0;k<=5;k++) {
                U[0][k] = 1.0;
                U[k][0] = 1.0;
        }

        for(k=6; k<=n; k++) {
                U[0][k] = 0.0;
                U[k][0] = 0.0;
        }

        for(k=0;k<=n;k++) {
                U[n][k] = 0.0;
                U[k][n] = 0.0;
        }

        for(i=1;i<=n-1;i++) {
                for(j=1;j<=n-1;j++) {
                        U[i][j] = (cos(THEAT)*U[i-1][j]+sin(THEAT)*U[i][j-1])/(cos(THEAT)+sin(THEAT));
                }
        }

        for(k=0;k<=n;k++) {
                U[n][k] = U[n-1][k];
                U[k][n] = U[k][n-1];
        }

        printf("Output FAI for EXCEL filename: ");
        scanf("%s", out_filename);
        out_file = fopen(out_filename, "w");

        for(j=1;j<n;j++) {
                fprintf(out_file, "%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f\n", U[0][j], U[1][j], U[2][j], U[3][j], U[4][j], U[5][j], U[6][j], U[7][j], U[8][j], U[9][j], U[10][j], U[11][j], U[12][j], U[13][j], U[14][j], U[15][j], U[16][j], U[17][j], U[18][j], U[19][j], U[20][j],  U[21][j], U[22][j], U[23][j], U[24][j], U[25][j], U[26][j], U[27][j], U[28][j], U[29][j], U[30][j]);
        }

        fclose(out_file);
        printf("Output X cod filename: ");
        scanf("%s", out_filename);
        out_file = fopen(out_filename, "w");
        for(i=0; i<=n; i++) {
                x=i;
                fprintf(out_file, "%f\n", x);
        }
        fclose(out_file);

        printf("Output Y cod filename: ");
        scanf("%s", out_filename);
        out_file = fopen(out_filename,  "w");
        for(j=0; j<n; j++) {
                y=j;
                fprintf(out_file, "%f\n", y);
        }
}

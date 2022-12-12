int main() {
    for (int i=1; i<=NMES; i++) {
        for (int j=1;j<=NMES; j++) {
            int VE=(V[i+1][j]+V[i][j])*.5;
            int VW=(V[i][j+1]+V[i][j])*.5;
            int VS=(V[i][j]+V[i][j-1])*.5;
            int CY=(VW*VE-UW*VS)/dx+(VN*VN-VS*VS)/dy;
            int VISY=(V[i][j+1]-2.0*V[i][j]+V[i][j-1])/(dx*dx);
        }
        
    }
}



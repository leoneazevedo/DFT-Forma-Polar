#define N 8
#define fs 80
#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <complex>
using namespace std;
int main() {
    ofstream saida("DFTPolar.txt");
    double xn=0,ts=(double)1/fs, xmi, xmr, xm=0, r, fi;
    const float ToDeg=180/M_PI; // converte radiano para deg
//------------------------------------------------------------------------------------------------------------------------------------
    for (int m=0; m<N ;m++){
        xmr=0;
        xmi=0;
//calculo do xn, retangular e imaginário da DFT
        for (int n=0;n<N;n++) {
            xn=4+cos(2*M_PI*10*n*ts)+sin(2*M_PI*30*n*ts);
            xmr+=(xn*cos(2*M_PI*n*m/N));//retangular
            xmi+=-(xn*sin(2*M_PI*n*m/N));//imaginário
          //cout <<" x("<<n<<")=" << setiosflags (ios::fixed) << setprecision (2) <<"("<<xmr<<")"<<"+"<<"("<<xmi<<"j"<<")"<< endl;
         }
//Aproximação------------------------------
            xmr*=10000;
            xmr= (int) xmr;
            xmr/=10000;
            xmi*=10000;
            xmi=(int) xmi;
            xmi/=10000;
//------------------------------------------
           complex <double> resp(xmr,xmi);
           //cout <<"Retangular x("<<m<<")=" << setiosflags (ios::fixed) << setprecision (2) <<"("<<xmr<<")"<<"+("<<xmi<<")"<<"j"<< endl;
           saida <<"x("<<m<<")= "<< setiosflags (ios::fixed) << setprecision (0) <<"("<<abs(resp)<<",<"<<arg(resp)*ToDeg<<")"<< endl;
           //cout <<"Polar x("<<m<<")= "<< setiosflags (ios::fixed) << setprecision (0) <<"("<<abs(resp)<<",<"<<arg(resp)*ToDeg<<")\n"<< endl;
    }
}

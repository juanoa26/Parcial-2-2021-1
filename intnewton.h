#ifndef INTNEWTON_H
#define INTNEWTON_H

#include <vector>

using std::vector;

struct dato{
	double x;
	double y;
	
	dato(double d_x, double d_y): x(d_x), y(d_y){
	}
};

class intnewton{
public:
	intnewton (vector<dato> p_datos):datos(p_datos){
		int n = datos.size();
		vector<vector<double>> F;
		F.resize(n);
		for(int i = 0; i < n ;i++){
			F[i].resize(n);
		}
		
		//Rellenar primer columna
		for(int i =0; i < n; i++){
			F[i][0]=datos[i].y;
		}
		
		for(int j =1; j < n;j++){
			for(int i = 0;i < n-j ;i++){
				F[i][j]=(F[i+1][j-1]-F[i][j-1])/(datos[i+j].x-datos[i].x);
				
			}
		}
		
		coeficientes.resize(n);
		for(int j=0;j<n;j++){
			coeficientes[j]=F[0][j];
		}
	}
	
	vector<double> polinomio(){
		return coeficientes;
	}
		
		double interpolar(double xint){
			
			int i,j;
			int n=datos.size();
			
			double p = 0.0;
			if(coeficientes.size()==0){
				return p;
			}
			
			//El vector de coeficientes contiene datos
			p=coeficientes[0];
			for(j=1;j<n;j++){
				double bj= coeficientes[j];
				double prod =1.0;
				for(i=0;i<j;i++){
					prod=prod*(xint-datos[i].x);
				}
				p = p + bj * prod;
			}
			return p;
		} 
			
			double get_last_coefi(){
				return coeficientes.back();
			}
				
private:
					vector<double> coeficientes;
					vector<dato>datos;
};
#endif

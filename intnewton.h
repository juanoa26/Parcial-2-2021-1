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
	
	double calcularError(double x){
		double varB4 = coeficientes[4];
		double prod=1;
		double error=-1;
		for(int i = 0 ; i < datos.size()-1; i++){
			prod = prod*(x - datos[i].x);
			
			}
		
		error = prod * varB4;
		// cout<<"var b4 "<<varB4<<endl;
		return error;
	}
		double menorError(double err1,double err2,double err3){
			
			double menor=err1;
			
			if(err2<menor){
				menor=err2;
			} 
			if(err3<menor){
				menor = err3;
			}
			return menor;
		}
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
				
				//		for(int i =0 ; i<F.size();i++){
				//			for(int j=0;F.size();j++){
				//				cout<<F[i][j];
				//			}
				//			cout<<endl;
				//		}
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

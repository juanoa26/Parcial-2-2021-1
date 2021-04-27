#ifndef REGRESIONEXPONENCIAL_H
#define REGRESIONEXPONENCIAL_H

#include"regresionLineal.h"
#include<cmath>
#include <vector>

class Regresion_Exponencial{
	
	
public:
	Regresion_Exponencial(vector<punto> v_dato):datos(v_dato){}
	
	calcular_regresionE(){
		
		int n=datos.size();

		for(int i=0;i<n;i++){
			datos[i].y=log(datos[i].y);
		}
		regresion_lineal r1(datos);
		r=r1.calcular(datos);
		return c =(exp(r.b0));
	}
		double rc(){
			return c;
		}
			resultado_regresion rs(){
				return r;
			}
private:
					vector<punto> datos;
					double c;
					resultado_regresion r;
					
};

#endif

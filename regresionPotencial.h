#ifndef REGRESIONPOTENCIAL_H
#define REGRESIONPOTENCIAL_H

#include"regresionLineal.h"
#include<cmath>
#include <vector>

class regresion_Potencial {
public:
	regresion_Potencial(vector<punto> v_datos):datos(v_datos){
		
	}
	
	calcular_regresionP() {
		
		int n = datos.size();
		
		
		for(int i=0; i < n; i++){
			datos[i].x=log10(datos[i].x);
			datos[i].y=log10(datos[i].y);
		}
		
		regresion_lineal r1(datos);
		r=r1.calcular(datos);
		return c =(pow(10,r.b0));
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

#ifndef REGRESIONLINEAL_H
#define REGRESIONLINEAL_H

#include <cmath>
#include <vector>

using std::vector;

struct punto {
	punto(double p_x, double p_y):  x(p_x), y(p_y) {
		
	}
	double x;
	double y;
};

struct resultado_regresion{
	double b0 = 0.0;
	double b1 = 0.0;
	double r2 = 0.0;
	double sy = 0.0;
	double syx = 0.0;
};

class regresion_lineal {
public:
	
	regresion_lineal(vector<punto> v_datos): datos(v_datos) {
		
	}
	resultado_regresion calcular(
								 vector<punto> datos
								 ) 
	{
	
	resultado_regresion r ;
	
	double sumx = 0.0;
	double sumy = 0.0;
	double sumxy = 0.0;
	double sumx2 = 0.0;
	
	int n = datos.size();
	
	//No hay datos!!
	if(n == 0) {
		return r;
	}
	for(int i=0; i < n; i++) {
		sumx += datos[i].x;
		sumy += datos[i].y;
		sumx2 += datos[i].x * datos[i].x;
		sumxy += datos[i].x * datos[i].y;
	}
	
	double x_prom = sumx/ n;
	double y_prom = sumy /n;
	
	r.b1 = (sumxy - y_prom * sumx)/(sumx2 - x_prom * sumx);
	
	r.b0 = y_prom - r.b1 * x_prom;
	
	double st = 0;
	double sr = 0;
	
	for(int i = 0; i < n; i++) {
		st += pow(datos[i].y - y_prom, 2);
		sr += pow(datos[i].y - r.b0 - (r.b1 * datos[i].x), 2);
	}
	r.sy = sqrt(st / (n-1));
	r.syx = sqrt(sr / (n-2));
	
	r.r2 =(st - sr) /st;
	
	return r;
}

void tabla() {
	
}

private:
	vector<punto> datos;
	
};

#endif

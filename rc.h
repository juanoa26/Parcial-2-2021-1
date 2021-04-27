#ifndef RC_H
#define RC_H

#include <vector>
#include <cmath>
#include <iostream>

using std:: vector;
using std:: cout;
using std:: endl;

struct resultado_rc {
	double a0;
	double a1;
	double a2;
	double syx;
	double sy;
	double r2;
};

class rc {
public:
	resultado_rc calcular(vector<double> x, vector<double> y) {
		
		int i;
		vector<vector<double>> m = matriz_regresion(x, y);
		vector<double> coeficientes = gauss(m);
		
		resultado_rc resultado;
		
		resultado.a0 = coeficientes[0];
		resultado.a1 = coeficientes[1];
		resultado.a2 = coeficientes[2];
		
		int n = x.size();
		
		double sx = 0.0;
		double sy = 0.0;
		double sxy = 0.0;
		double sx2 = 0.0;
		
		for(i = 0; i < n; i++) {
			sx += x[i];
			sxy += x[i] * y[i];
			sx2 += x[i] * x[i];
			sy += y[i];
		}
		
		double ym = sy / (double) n;
		
		//calcular las sumas de los cuadrados para desviacion estandar y error estandar de aproximacion
		double st = 0.0;
		double sr = 0.0;
		for(i = 0; i < n; i++) {
			st += pow(y[i] - ym, 2);
			sr += pow(y[i] - (resultado.a0 + resultado.a1 * x[i] + (resultado.a2 * x[i] * x[i])) , 2);
		}
		
		cout<<"Valor st = "<< st << endl;
		cout<<"\nValor sr = "<< sr <<endl;
		
		//calcular la desviacion estandar
		resultado.sy = sqrt(st / (double) (n - 1));
		
		//calcular el error estandar de aproximacion
		resultado.syx = sqrt(sr / (double) (n - 3));
		
		//calcular el coeficiente de determinacion
		resultado.r2 = (st - sr) / st;
		
		return resultado;
		
	}
		
private:
		vector<vector<double>> matriz_regresion(
												vector<double> x,
												vector<double> y) {
			
			int n = x.size();
			
			double sx {0};
			double sx2 {0};
			double sx3 {0};
			double sx4 {0};
			double sy {0};
			double sxy {0};
			double sx2y {0};
			
			//calcular los valores que se almacenan en la matriz
			for(unsigned int i = 0; i < x.size(); i++) {
				double x2 = x[i] * x[i];
				double x3 = x2 * x[i];
				double x4 = x3 * x[i];
				
				sx += x[i];
				sx2 += x2;
				sx3 += x3;
				sx4 += x4;
				
				sy += y[i];
				sxy += x[i] * y[i];
				sx2y += x2 * y[i];
			}
			
			//construir la matriz para la regresion
			vector<vector<double>> resultado {
				{(double)n, sx, sx2, sy}, //primera fila
				{sx, sx2, sx3, sxy}, //segunda fila
				{sx2, sx3, sx4, sx2y}	
			};
			
			//imprimir resultado
			return resultado;			
		}
		
		vector<double> gauss(vector<vector<double>> m) {
			int i, j, k;
			int n = m.size();
			
			vector<double> resultado(n);
			
			//Eliminacion gaussiana
			for(i = 0; i < n; i++) {
				for(j = i + 1; j < n; j++) {
				double v = m[j][i] / m[i][i]; // valor que anula el elemeno en la columna
				//hacer la operacion fila[j] - v * fila[i]
				for(k = 0; k <= n; k++) {
					m[j][k] -= v * m[i][k];
				}
			}
		}
		
		imprimir(m);
		
		//despejar las variables
		for(i= n - 1; i >= 0; i--) {
			resultado[i] = m[i][n];
			//Reemplazar las variables ya halladas
			for(j = i + 1; j < n; j++) {
				if(i != j) {//reemplazar las variables, menos el coeficiente
					resultado[i] = resultado[i] - m[i][j] * resultado[j];
				}
			}
			resultado[i] = resultado[i] / m[i][i];
		}
		
		return resultado;
	}
	
	void imprimir(vector<vector<double>>m) {
	cout<< "[" << endl;
	for(unsigned int  i = 0; i < m.size(); i++) {
		cout<< "[" ;
		for(unsigned int  j = 0; j < m[i].size(); j++) {
			cout << m[i][j] << " ";
		}
		cout<< "]" << endl;
	}
	cout<< "]" << endl;
}
};

#endif

#include <cmath>
#include <iostream>
#include <iomanip>
#include<vector>

#include "regresionLineal.h"
#include "regresionPotencial.h"
#include "regresionExponencial.h"
#include "intnewton.h"
#include "rc.h"

using namespace std;

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void caso_1();
void caso_2();
void caso_3();
void caso_4();
void caso_5();

int main (int argc, char *argv[]) {
	
	caso_1();
	caso_2();
	caso_3();
	caso_4();
	caso_5();
	
	return 0;
}


void caso_1(void) {
	
	vector<punto> datos = {
		{120.00 , 1170},
		{125.50, 1190},
		{136.50, 1255},
		{149.00 , 1490},
		{159.00, 1565},
		{171.00, 1705},
		{187.00, 1800},
		{207.00, 1825},
		{272.00, 1960}	
	};
	
	Regresion_Exponencial re(datos);
	
	cout<<"--------------------------------------------------------------"<<endl;
	cout<<"PARCIAL 2: PUNTO 1 REGRESION "<<endl;
	cout<<"--------------------------------------------------------------"<<endl;
	cout<<"\nCASO 1: REGRESION EXPONENCIAL " <<endl;
	
	//Calcular regresion
	re.calcular_regresionE();
	resultado_regresion r2 = re.rs();
	
	cout<<"\nRECTA DE REGRESION: "
		<<"y= "
		<<re.rc() << "x"
		<<((r2.b1 >= 0)? "+":"")
		<<r2.b0
		<<endl;
	
	cout<<"\nDesviacion estandar sy = " <<r2.sy << endl;
	cout<<"Error Estandar Aproximacion Sy/x = " <<r2.syx << endl;
	cout<<"Coef. de determinacion R2 = " <<r2.r2 << endl;
	
	if(r2.syx >= r2.sy) {
		cout<<"\nLa aproximacion se considera aceptable" <<endl;
		exit(EXIT_FAILURE);
	}else {
		cout<<"\nLa aproximacion no se considera aceptable" <<endl;
	}
	
	double x;
	
	cout<<"Ingrese un valor de x en el rango "
		<<datos[0].x
		<<" - "
		<<datos[datos.size() -1].x
		<<endl;
	
	cin>> x;
	
	cout<<"y = " <<(r2.b1 * x + r2.b0) <<endl;
	
}


void caso_2(void) {
	
	vector<punto> datos = {
		{120.00 , 1170},
		{125.50, 1190},
		{136.50, 1255},
		{149.00 , 1490},
		{159.00, 1565},
		{171.00, 1705},
		{187.00, 1800},
		{207.00, 1825},
		{272.00, 1960}	
	};
	
	regresion_Potencial rp(datos);
	
	cout<<"\n--------------------------------------------------------------"<<endl;
	cout<<"\nCASO 2: REGRESION POTENCIAL " <<endl;
	
	//Calcular regresion
	rp.calcular_regresionP();
	resultado_regresion r2 = rp.rs();

	
	cout<<"\nRECTA DE REGRESION: "
		<<"y= "
		<<rp.rc() << "x"
		<<((r2.b0 >= 0)? "+":"")
		<<r2.b0
		<<endl;
	
	cout<<"\nDesviacion estandar sy = " <<r2.sy << endl;
	cout<<"Error Estandar Aproximacion Sy/x = " <<r2.syx << endl;
	cout<<"Coef. de determinacion R2 = " <<r2.r2 << endl;
	
	if(r2.syx >= r2.sy) {
		cout<<"\nLa aproximacion se considera aceptable" <<endl;
		exit(EXIT_FAILURE);
	}else {
		cout<<"\nLa aproximacion no se considera aceptable" <<endl;
	}
	
	double x;
	
	cout<<"Ingrese un valor de x en el rango "
		<<datos[0].x
		<<" - "
		<<datos[datos.size() -1].x
		<<endl;
	
	cin>> x;
	
	cout<<"y = " <<(r2.b1 * x + r2.b0) <<endl;
	
}


void caso_3(void) {
	
	vector<double> x {120.00, 125.50, 136.50, 149.00, 159.00, 171.00, 187.00, 207.00, 272.00};
	vector<double> y {1170, 1190, 1255, 1490, 1565, 1705, 1800, 1825, 1960};
	
	cout<<"\n--------------------------------------------------------------"<<endl;
	rc r;
	
	resultado_rc resultado = r.calcular(x, y);
	
	cout<<"\n--------------------------------------------------------------"<<endl;
	cout<<"\nCASO 3: REGRESION CUADRATICA " <<endl;
	
	
	cout<<"\nRECTA DE REGRESION: "
		<<"y= "
		<< resultado.a2 << " x^2 ""+ " << resultado.a1 << "x"
		<< resultado.a0 << " " << endl;
		
	cout<<"\nDesviacion Estadar Sy = " << resultado.sy << endl;
	cout<<"Error Estadar Aproximacion. Sy/x = " << resultado.sy << endl;
	cout<<"Coef. de determinacion R2 = " << resultado.r2 << endl;
	
	if(resultado.syx >= resultado.sy) {
		cout<<"\nLa aproximacion se considera aceptable" <<endl;
		exit(EXIT_FAILURE);
	}else {
		cout<<"\nLa aproximacion no se considera aceptable" <<endl;
	}

}


void caso_4(void) {
	
	cout<<"--------------------------------------------------------------"<<endl;
	cout<<"PARCIAL 2: PUNTO 2 INTERPOLACION "<<endl;
	cout<<"--------------------------------------------------------------"<<endl;
	cout<<"\nMETODO DE NEWTON " <<endl;
	cout<<"\nCaso 1:"<<endl;
	
	setprecision(7);
	n = 4;
	double y[] = {1.0000000, 1.1318324, 1.2297984, 1.2978519};
	double x[] = {0.0, 0.05, 0.1, 0.15};
	b = new double[n];
	
	newton(y, x, n);
	for (int i = 0; i < n; i++)
	{
		cout <<"Coeficientes: "
		<< "A" << i << "= " << b[i] << endl;
	}
	
	double toEvaluate = 0.08;
	
	
	double answer = evaluate(toEvaluate, y, x, n);
	cout << "\nEvaluacion en x= " << toEvaluate<< endl;
	cout << "\nf(0.08)= " << answer << endl;
	
	double relativo;
	double absoluto;
	error_relativo = fabs((relativo - absoluto) / relativo);
	//error_relativo = fabs((relativo - absoluto) / relativo);
	cout << "\nError relativo R3 = " << error_relativo << endl;
	cout << "Error absoluto: " << fabs(relativo - absoluto) << endl;
}

void caso_5(void) {

	cout<<"--------------------------------------------------------------"<<endl;
	cout<<"PARCIAL 2: PUNTO 2 INTERPOLACION "<<endl;
	cout<<"--------------------------------------------------------------"<<endl;
	cout<<"\nMETODO DE NEWTON " <<endl;
	cout<<"\nCaso 2:"<<endl;
	
	setprecision(7);
	n = 4;
	double y[] = {1.1318324, 1.2297984, 1.2978519, 1.3401716};
	double x[] = {0.05, 0.1, 0.15, 0.2};
	b = new double[n];
	
	newton(y, x, n);
	for (int i = 0; i < n; i++)
	{
		cout <<"Coeficientes: "
			<< "A" << i << "= " << b[i] << endl;
	}
	
	double toEvaluate = 0.08;
	
	
	double answer = evaluate(toEvaluate, y, x, n);
	cout << "\nEvaluacion en x= " << toEvaluate<< endl;
	cout << "\nf(0.08)= " << answer << endl;
	
}



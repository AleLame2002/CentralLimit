#include "FunzioneBase.h"

// *************************************
//     IMPLEMENTAZIONE DEI METODI
// *************************************

// METODO EVAL DELLA FUNZIONE MYFUNCTIONONE
double MyFunctionOne::Eval (double x) const {
	double esp = - (x*x) / 2.;
	return pow(M_E, esp); 		 //e^(-x^2 /2) 
}

// METODO EVAL DELLA FUNZIONE PARABOLA
double Parabola::Eval(double x) const /*override*/ { return m_a*x*x + m_b*x + m_c; }

// METODO EVAL DELLA FUNZIONE SENO
double Seno::Eval(double x) const /*override*/ { return m_a * sin(x); 
}

// METODO EVAL DELLA FUNZIONE GAUSSIAN
double Gaussiana::Eval(double x) const /*override*/ {
	double a = 1. / (m_sigma * sqrt(2. * M_PI));               // Parte prima dell'esponenziale
	double esp = -pow(x - m_mean, 2) / (2. * pow(m_sigma, 2)); // Esponente
	return a * pow(M_E, esp);                                  // Gaussiana: f(x) = a*e^esp;
} 

//#include "Librerie.h"

#include <iostream>
#include <float.h>
#include <cmath>

#ifndef __FunzioneBase_H__
#define __FunzioneBase_H__

// CLASSE MADRE CON METODI VIRTUALI PUTI
class FunzioneBase {

  public:

  virtual double Eval (double) const = 0;
  virtual ~FunzioneBase () {}

};

// CLASSE CONCRETA CHE IMPLEMEMNTA LA FUNZIONE e^(-x^2/2)
class MyFunctionOne : public FunzioneBase {

public:
	MyFunctionOne () {}
	~MyFunctionOne () {}

	double Eval (double x) const;


};

// CLASSE CONCRETA CHE IMPLEMENTA UNA FUNZIONE PARABOLA
class Parabola : public FunzioneBase {

public:
    Parabola () { m_a = 1.; m_b = 0.; m_c = 0.; }
    Parabola (double a, double b, double c) { m_a = a; m_b = b; m_c = c; }
    ~Parabola () {}

    double Eval (double x) const /*override*/ ;// {return m_a*x*x + m_b*x + m_c;}

    void SetA (double a) { m_a = a; }
    void SetB (double b) { m_b = b; }
	void SetC (double c) { m_c = c; }

    double GetA () const { return m_a; }
    double GetB () const { return m_b; }
    double GetC () const { return m_c; }

	double GetXVertex () const {return -GetB()/( 2*GetA() );}
	double GetYVertex () const {return Eval(GetXVertex());}


private:

    double m_a, m_b, m_c;

};

// CLASSE CONCRETA CHE IMPLEMENTA UNA FUNZIONE SIN(X)
class Seno : public FunzioneBase{
    public:

    Seno () {m_a=1.;}
    Seno (double a) {m_a=a;}
    ~Seno () {}

    double Eval (double x) const /*override*/ ;// {return m_a*sin(x);}

    void SetA (double a) {m_a=a;}

    double GetA () const {return m_a;}

    private:

    double m_a;
};

// CLASSE CONCRETA CHE IMPLEMENTA UNA FUNZIONE GAUSSIANA
class Gaussiana: public FunzioneBase {
public:
	Gaussiana() { m_mean = 0.; m_sigma = 1.; }
    Gaussiana(double mean, double sigma) { m_mean = mean; m_sigma = sigma; }

    double Eval(double x) const /*override*/; /* {
		double a = 1. / (m_sigma * sqrt(2. * M_PI)); // Parte prima dell'esponenziale
		double esp = -pow(x - m_mean, 2) / (2. * pow(m_sigma, 2)); // Esponente
		return a * pow(M_E, esp); // Gaussiana: f(x) = a*e^esp;
		} */

private:
    double m_mean, m_sigma;

};


#endif
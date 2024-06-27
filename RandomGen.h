#ifndef __LIB__
#define __LIB__

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

#endif

#include "FunzioneBase.h"

#ifndef __RANDOMGEN_H__
#define __RANDOMGEN_H__

class RandomGen {

private:
  unsigned int m_a, m_c, m_m;
  unsigned int m_seed;
	int m_iter;

public:

  RandomGen(unsigned int s = 1.);

  void SetA(unsigned int a) { m_a = a; }
  void SetC(unsigned int c) { m_c = c; }
  void SetM(unsigned int m) { m_m = m; }
  void SetS(unsigned int s) { m_seed = s; }

  double Rand();                             // Generatore di numeri pseudo-casuali
  double Unif(double xmin, double xmax);     // Distribuzione uniforme
  double Exp(double mean);                   // Distribuzione esponenziale
  double GaussBM(double mean, double sigma); // Distribuzione Gaussiana BOX-MULLER
  double GaussAR(double mean, double sigma); // Distribuzione Gaussiana Accept-Reject

};

#endif // __RANDOMGEN_H__
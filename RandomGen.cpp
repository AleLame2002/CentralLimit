#include "RandomGen.h"

// ******************************************
//  IMPLEMENTAZIONE DEI METODI DELLA CLASSE
// ******************************************

// Costruttore
RandomGen::RandomGen(unsigned int s) {
  m_seed = s;       // Imposto seme
  m_a = 1664525;    // Imposto a, c, m per la generazione
  m_c = 1013904223; // dei numeri casuali
  m_m = 1 << 31;    // In binario: 2 shftato di 31 posti
  m_iter = 0;       // Contatore per le funzioni ricorsive
}

// Generatore di un numero casuale
double RandomGen::Rand() {
  double n;

  n = (m_a * m_seed + m_c) % m_m; // Resto della diviosne tra interi
  m_seed = n;                     // Aggiorno il seme

  return static_cast<double>(n) / m_m;
}

// Generatore di numeri distribuiti uniformemente in [a, b)
double RandomGen::Unif(double xmin, double xmax) {
  double a, b, r;

  // Controllo che gli estremi dell'intervallo siano coerenti
  if (xmin < xmax) {
    a = xmin; b = xmax;
  } else {
    a = xmax; b = xmin;
  }

  r = Rand(); // Genero un numero casuale

  return a + (b - a) * r; // Stiro e traslo il numero generato
}

// Generatore di numeri distribuiti esponenzialmente
double RandomGen::Exp(double mean) {
  double r = Rand();                // Genero un numero causalmente
  return (-1. / mean) * log(1 - r); // Uso inversa della cumulativa
}

// Distribuzione gaussiana con metodo Box-Muller
double RandomGen::GaussBM(double mean, double sigma) {
  double r1 = Rand();
  double r2 = Rand();
  return mean + sigma * sqrt(-2 * log(1 - r1)) * cos(2 * M_PI * r2);
}

// Distribuzione gaussiana con metodo Accept-Reject
double RandomGen::GaussAR(double mean, double sigma) {

  Gaussiana myGauss(mean, sigma);

  double x = Unif(-5 * sigma, 5 * sigma);

  double max = myGauss.Eval(mean);
  double y = Unif(0., max);

  if (m_iter > 10000)
    return x;
  if (y < myGauss.Eval(x)) {
    m_iter = 0;
    return x;
  } else {
    m_iter++;
    return GaussAR(mean, sigma);
  }
}

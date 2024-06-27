#ifndef __LIB__
#define __LIB__

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

#endif // __LIB__

#ifndef __Funzioni_vector__
#define __Funzioni_vector__

// Dichiarazione
template <typename T> T somma_parziale(vector<T> &v, int start, int end);
template <typename t> t media(vector<t> &v);
template <typename t> t stdev(vector<t> &v);
template <typename t> void Print_vect(vector<t> &v);

// Definizione
// Somma parziale di un vettore
template <typename T> T somma_parziale(vector<T> &v, int start, int end){
	// Controllo che gli "estremi" siano nell'ordine corretto
	if(start > end) {
		T appo = start;
		start = end;
		end = appo;
	}
	
	T sum = 0;

	for(int i = start; i < end; i++){
		sum += v[i];
	}
	
	return sum;
}

// Funzione che calcola la media
template <typename t> t media(vector<t> &v) {
  t sum = 0;
  for (int i = 0; i < v.size(); i++) {
    sum += v[i];
  }
	//t x;
	//for(x in v) sum+=x; 
  return sum / static_cast<t>(v.size());
}

// Funzione che calcola la deviazione standard
template <typename t> t stdev(vector<t> &v) {
  t quad = 0;
  for (int i = 0; i < v.size(); i++) {
    quad += pow(v[i], 2);
  }
  return sqrt((quad / static_cast<t>(v.size())) - pow(media(v),2));
}

// Stampa un vector
template <typename t> void Print_vect(vector<t> &v){
	for(int i = 0; i < v.size(); i++){
		cout << setw(10) << v[i];
	}
	cout << endl;
}

#endif // __Funzioni_vector__

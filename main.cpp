#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>

// ROOT
//#include "TApplication.h"
#include "TLegend.h"
#include "TCanvas.h" 
#include "TGraph.h"
#include "TAxis.h"
#include "TH1F.h"
#include "TH1.h"

#include "../Esercizio_10.0/RandomGen.h"
#include "Funzioni.h"

int main(int argc, char** argv){

	if(argc != 2) { 
		cerr << "Uso: " << argv[0]  << " <n_elementi_da_generare>" << endl;
    return -1;
  }

	
	// Grafico dell'andamento della dev. stand. in 
	// funzione del numero di elementi sommati
	TGraph * Graph[2];
	
	for(int i = 0; i < 2; i++){
		Graph[i] = new TGraph();
	} //= new TGraph();
	
	// Creo un array di puntatori a TH1F. Ognuno
	// conterrà un istogramma con la distribuzione
	// delle varie somme parziali
	TH1F * Histo[12];

	// Con questo ciclo alloco i 12 TH1F
	for(int i = 0; i < 12; i++){
		Histo[i] = new TH1F(Form("Istro. %d", i+1), Form("%d elemnti sommati", i+1), 100, -0.1, 1.1);
		// Tengo in considerazione tutti i dati per le stime statistiche
		Histo[i]->StatOverflows( kTRUE );
	}

	// Tela per disegnare i vari istogrammi
	TCanvas * Tela[2];

	Tela[0] = new TCanvas("D.S.P.", "D.S.P");
	Tela[1] = new TCanvas("Varianza", "Varianza", 1500, 600);
	
	// = new TCanvas("Verifica del teorema del limite centrale",
																//"Verifica del teorema del limite centrale");
	
	Tela[0]->SetTitle("Distribuzione delle somme parziali");
	Tela[0]->cd();			   // Entro nella tela
	Tela[0]->Divide(4,3); // Divido la tela in 3x4

	// Codice serio
	RandomGen myGen(1.);
	vector<double> v1(atoi(argv[1])), v2;
	double p, st_dev, var;

	// Genero gli <n_elementi_da_generare> 
	for(int i = 0; i < atoi(argv[1]); i++){
		v1[i] = myGen.Unif(0.,1.);
	}
	
	int x;
	int j; // Tiene traccia dei vari intervali su cui sommerò
	for( x = 1; x < 13; x++){
		
		j=0; // Azzero j

		// Svuoto il vettore 2
		v2.clear();

		// Faccio le somme parziali
		for(int i = 0; i < atoi(argv[1])/x; i++){
			v2.push_back(somma_parziale<double>(v1,j,j+x)/(double)x);
			j+=x; // Inf intervallo su cui sommo
		}

		// Riempio l'istogramma
		for(int i = 0; i < v2.size(); i++){
			Histo[x-1]->Fill(v2[i]); 
		}

		// Disegno l'istogramma nella x-esima sotto tela 
		
		//st_dev = stdev(v2);
		st_dev = Histo[x-1]->GetRMS();
		
		//cout << "Media passo    " << x << setw(10) << media(v2) << endl;
		//cout << "Dev_st passo   " << x << setw(10) << stdev(v2) << endl << endl;

		// Inserisco i punti nel grafico dell'andamento della dev. stand. 
		// in funzione del numero di elementi sommati 
		Graph[0]->SetPoint(x - 1, x, st_dev);
		Graph[1]->SetPoint(x -1, x, st_dev * st_dev);

		// Svuoto l'istogramma e i dati che ha memorizzato
		//Histo0->Clear();
		//Histo0->ClearUnderflowAndOverflow(); 
		
	} // Fine for grosso (x)

	// Disegno gli istogrammi nelle diverse sottotele
	for(int i = 0; i < 12; i++){
		Tela[0]->cd(i+1);
		Histo[i]->Draw();
	}

	Tela[0]->Print("TeoremaLimiteCentrale.pdf");

	// Stampo il grafico della deviazione standard in
	// funzione degli elementi sommati
	
	Tela[1]->Divide(2,1);

	Tela[1]->cd(1);
	Tela[1]->GetPad(1)->SetGrid();
	Graph[0]->SetTitle("Dev.St. in funzione del numero di elementi sommati");
	Graph[0]->GetXaxis()->SetTitle("Numero di elementi sommati");
	Graph[0]->GetYaxis()->SetTitle("Deviazione standard");
	Graph[0]->SetMarkerStyle(20); // Puntini tondi
	Graph[0]->SetLineColor(4);    // Colore lina blu
	//graph1->SetMinimum(-0.2);
	//graph1->SetMaximum( 0.8);
	Graph[0]->Draw("ALP");

	Tela[1]->cd(2);
	Tela[1]->GetPad(2)->SetGrid();
	Graph[1]->SetTitle("Varianza in funzione del numero di elementi sommati");
	Graph[1]->GetXaxis()->SetTitle("Numero di elementi sommati");
	Graph[1]->GetYaxis()->SetTitle("Varianza");
	Graph[1]->SetMarkerStyle(20); // Puntini tondi
	Graph[1]->SetLineColor(4);    // Colore lina blu
	Graph[1]->Draw("ALP");
	
	Tela[1]->Print("TEO_LIM_CENTR.pdf");

	for(int i = 0; i < 12; i++){
		Histo[i]->Reset();
		delete Histo[i]; 
	}

	for(int i = 0; i < 2; i++){
		delete Graph[i];
		delete Tela[i];
	}

	return 0;
	
}
// Creating a random exponential decay data and fit by the exponential function
#include <iostream>
#include <TRandom3.h>
#include <TCanvas.h>
#include <TH1F.h>

using namespace std;
int main(){
  
  // Setting decay paramter 
  Double_t tau = 8.5;  
  
  TRandom3 gen(0);
  TH1F *h = new TH1F("expo decay","Fitted distribution",100,0,60);
  for (Int_t i = 0; i < 10000; i++){
    h->Fill(gen.Exp(tau));
  }
  
  // Ramdomly setting the axis titles
  h->GetXaxis()->SetTitle("time");
  h->GetYaxis()->SetTitle("Quantity");
  
  // Histogram fitting and draw
  h->Fit("expo");
  h->Draw();

  // saving the histogram in the pdf format 
  gPad->Print("exponential_decay.pdf");
  return 0;
}


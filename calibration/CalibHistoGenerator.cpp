{
  TFile *fin = TFile::Open("/home/wiggert/Documents/pr254/sortedRuns/sorted02087.root");
  TTree *trin = (TTree*)fin->FindObjectAny("DATA");

  for(int i=0;i<128;i++)
    {
      char buffer[256];
      
      //TFile *fout = new TFile(buffer,"RECREATE");
      sprintf(buffer,"ADCValues[%d]>>hADC(12000,500,12500)",i);
      trin->Draw(buffer,"","");
      TH1F *hADC = gROOT->FindObjectAny("hADC");
      sprintf(buffer,"/home/wiggert/Programs/k600analyserPR254/calibration/calibration-histograms-run2087/hADC_%d.root",i);
      hADC->SaveAs(buffer);
    }
}

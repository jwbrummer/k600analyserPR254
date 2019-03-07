// Written by JWB (jbrummer@sun.ac.za) on 11/11/2018. This macro script receives an integer parameter so that the 
// triton trees are created right after a run has been analysed so that much less disk space is needed to analyse all runs.

void single_triton_tree_generator(int runNum)
{
      TFile *fin = TFile::Open("output.root");
      TTree *trin = (TTree*)fin->FindObjectAny("DATA");
      char rootNum[256];
      sprintf(rootNum,"/home/wiggert/Desktop/triton-trees/triton_tree_run%d.root",runNum);
      TFile *fout = new TFile(rootNum,"RECREATE");
      char cutRun[256];
      sprintf(cutRun,".x /home/wiggert/Programs/k600analyserPR254/pid/CUTpad1vstofRun%d.C",runNum);
      gROOT->ProcessLine(cutRun); 
      char cutName[256];
      sprintf(cutName,"CUTpad1vstofRun%d",runNum);
      TTree *newt = trin->CopyTree(cutName);
      newt->Write();
      fout->Close();
      fin->Close();
      c1->Close();
      //It is very important to close all TTrees and TFiles otherwise data analysis with the newly-generated trees won't work.
}

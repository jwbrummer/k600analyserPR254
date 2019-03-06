////////////////////////////////////////////////////////////////////////////////
//                                                                            //
// K600TAnalyseFolders                                                        //
//                                                                            //
// Begin_Html <!--
/*-->

<!--*/
// --> End_Html
//                                                                            //
//                                                                            //
// Please note: The following information is only correct after executing     //
// the ROMEBuilder.                                                           //
//                                                                            //
//                                                                            //
// This task contains the following histgrams :                               //
//    LUT                                                                     //
//    CableOffsetTable                                                        //
//    EventID                                                                 //
//    TDC2DModule                                                             //
//    TDCModule                                                               //
//    ADC2DModule                                                             //
//    ADCHitPattern                                                           //
//    CalADC2DModule                                                          //
//    PsideTDCValues                                                          //
//    PsideNside                                                              //
//    SiFBADCHitPattern                                                       //
//    NsideHit                                                                //
//    PsideHit                                                                //
//    SiPulseHeight                                                           //
//    K600vsHAGAR                                                             //
//    K600vsLEPS                                                              //
//    K600vsLEPSCalibratedTot                                                 //
//    K600vsLEPSCalibrated                                                    //
//    K600vsSi                                                                //
//    K600vsCalSi                                                             //
//    K600vsSiDetector                                                        //
//    K600vsCalSiGated                                                        //
//    K600vsCalSiDetector                                                     //
//    K600GateSiADCNumberValue                                                //
//    SiFBADC                                                                 //
//    SiADCTDC                                                                //
//    SiFBADCGated                                                            //
//    SiADCTDCHitPattern                                                      //
//    SiADCTDCValues                                                          //
//    SiEnergyTime                                                            //
//    QDCRaw                                                                  //
//    PaddleAve                                                               //
//    Pad1vsPad2                                                              //
//    Pad1vsTOFGated                                                          //
//    TOF                                                                     //
//    TOFGated                                                                //
//    Pad1vsTOF                                                               //
//    Pad1LowvsX                                                              //
//    Pad1HivsX                                                               //
//    Pad2LowvsX                                                              //
//    Pad2HivsX                                                               //
//    Pad1vsX                                                                 //
//    Pad2vsX                                                                 //
//    Pad2vsTOF                                                               //
//    PadTimeDiff                                                             //
//    PosVsPadTimeDiff                                                        //
//    TOFvsX1                                                                 //
//    TOFvsX2                                                                 //
//    HitPattern                                                              //
//    HitPatternX                                                             //
//    DriftTimeOffset                                                         //
//    DriftTimeOffsetGood                                                     //
//    DriftLength                                                             //
//    Efficiency                                                              //
//    EfficiencyID                                                            //
//    HitsPerEvent                                                            //
//    TDCsPerEvent                                                            //
//    Position                                                                //
//    Angle                                                                   //
//    Res2D                                                                   //
//    X1Y1                                                                    //
//    Y1                                                                      //
//    X2Y2                                                                    //
//    Y2                                                                      //
//    ThFPvsX1                                                                //
//    ThFPvsX2                                                                //
//    ThSCATvsX1                                                              //
//    ThSCATvsX2                                                              //
//    Y1vsThFP                                                                //
//    PhiFP                                                                   //
//    PhiFPvsY1                                                               //
//    D1D3PsideHitPattern                                                     //
//    trigger                                                                 //
//    ci                                                                      //
//    PositionYGate                                                           //
//    PositionThetaGate                                                       //
//    trigperci                                                               //
//                                                                            //
// The histograms/graph are created and saved automaticaly by the task.       //
//                                                                            //
// The following method can be used to get a handle of the histogram/graph :  //
//                                                                            //
// Get<Histogram/Graph Name>()                                                //
//                                                                            //
// For histogram/graph arrays use :                                           //
//                                                                            //
// Get<Histogram/Graph Name>At(Int_t index)                                   //
//                                                                            //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

/* Generated header file containing necessary includes                        */
#include "generated/K600TAnalyseFoldersGeneratedIncludes.h"

////////////////////////////////////////////////////////////////////////////////
/*  This header was generated by ROMEBuilder. Manual changes above the        *
 * following line will be lost next time ROMEBuilder is executed.             */
/////////////////////////////////////----///////////////////////////////////////

#include "generated/K600Analyzer.h"
#include "tasks/K600TAnalyseFolders.h"
#include "ROMEiostream.h"
#include <math.h>
#include <assert.h>
//#include "K600AllFolders.h" // uncomment if you want to include headers of all folders

#include "experim.h"

#include <TCutG.h>//Need to include TCutG.h to get TCutGs working
#include <TROOT.h>//Use gROOT to look for the TCutGs that have been loaded
//#include <TBox.h>

//#include "calib_pars.h"//Header file containing calibration parameters
//#include "ADC_Calibration_PR228B.h"
//#include "TDC_Calibration_PR228B.h"
#include "/home/wiggert/Programs/k600analyserPR254/other/ADC_Calibration_PR254.h"

ClassImp(K600TAnalyseFolders)

float lutx1[9000];
float lutx2[9000];
float lutu1[9000];
float lutu2[9000];
float cableOffset[896];
char string_var[200];
unsigned int Channel2Wire[896]; //Variables used for wire-mapping. 
Double_t scaler[16], scalerpsec[16], oldscaler[16];
int counter;
int counterscaler;

// Some constants. Things I do not want people to change, thus not in the ODB.
const Double_t X_WIRESPACE = 4.0;  // distance (mm) between signal wires
const Double_t DRIFTLENGTH = 8.0;  // max distance (mm) the electrons can drift
const Double_t U_WIRE_ANGLE=50.0;    // angle of wires in U-plane wrt to horizontal
const int LUT_CHANNELS=9000;
const int X_WIRES=208;
const int U_WIRES=145;
const int TDC_MAX_TIME=14999;
const int TDC_MIN_TIME=0;
const int TDC_N_BINS=14999;
const int TOF_TDC_CHAN1=1;       // ch1 in 1st TDC; i.e. the 2nd channel     
const int TOF_TDC_CHAN2=129;     // ch1 in 2nd TDC; i.e. the 2nd channel     
const int TOF_TDC_CHAN3=257;     // ch1 in 3rd TDC; i.e. the 2nd channel     
const int TOF_TDC_CHAN4=385;     // ch1 in 4th TDC; i.e. the 2nd channel     
const int TOF_TDC_CHAN5=513;     // ch1 in 5th TDC; i.e. the 2nd channel     
const int TOF_TDC_CHAN6=641;     // ch1 in 6th TDC; i.e. the 2nd channel     
const int TOF_TDC_CHAN7=769;     // ch1 in 7th TDC; i.e. the 2nd channel     

//Define some pointers to use for graphical cuts
TCutG *CUTSiFBADC;
//TBox *box;



const int MAX_WIRES_PER_EVENT = 300;   // it is too high should be changed soon
// If more wires than this fire, the event data was bad  -- RN random choice  -- 
// to be replaced by something else?!?! really only used for array definition
// MUST FIND A BETTER WAY ... THIS VARIABLE NOT GOOD?

// Struct to hold, for each wireplane, a wire number, drifttime and driftdistance
typedef struct VDC {
  Int_t wire[MAX_WIRES_PER_EVENT];
  Int_t time[MAX_WIRES_PER_EVENT];
  Double_t dist[MAX_WIRES_PER_EVENT];
} VDC;
VDC X1;
VDC X2;
VDC U1;
VDC U2;

GLOBAL_PARAM global;
GATES_PARAM gates;


/*---------------------------------------------------------------*/
void read_lut(float lutx[], int offset, char *fileName) 
{
   FILE *file = fopen(fileName, "r");
   assert(file != NULL);
   short nrows = 9000; 
   char string_var[200] = "";
   float float_var = 0;

   for(int i = 0; i < nrows; i ++) {
      if (feof(file)){
         break;           //just in case
      }
      fscanf(file,"%s", string_var);
      float_var = strtof(string_var, NULL);
      //printf("float_var : %f  \n",float_var);
      if((i-offset)>0) lutx[i-offset] = float_var;        
   }
   fclose(file);   
}


/*---------------------------------------------------------------*/
void read_cable(float cable[], char* fileName) 
{
   FILE *file = fopen(fileName, "r");
   assert(file != NULL);
   short nrows = 1000; //number of tdc channels 
   char string_var[200] = "";
   float float_var = 0;

   for(int i = 0; i < nrows; i ++) {
      if (feof(file)){
        break; //just in case
      }	
      fscanf(file,"%s", string_var);
      float_var = strtof(string_var, NULL);
      //printf("float_Var : %f  \n",float_var);
      cable[i] = float_var;
      //printf("cable[i]  %f \n",cable[i]);
   }
   fclose(file);   

   //for(int i = 0; i < nrows; i ++) {
   //   printf("cable[%i]  %f \n",i,cable[i]);
   //}

}

/* ---------------------------------------------------------------------------------------*/
void setupchannel2wireXoldXold()
// Mapping of wires to channels when using 2 old VDCs
// See camac-vme-cabling.xls
// This is fairly complicated due to design mistakes on the PCB's
// In this mapping 
// chan 0-207   = X wires VDC1
// chan 500-707 = X wires VDC2
//
{
  int input,tdcmodulecounter,preampnum,channelstart,basecount;
  int preampcount=0;
  int preampbase=0;
  //int channel=0;
  int tdcchan;

  for(input=0;input<896;input++) Channel2Wire[input]=0;

  for(tdcmodulecounter=0;tdcmodulecounter<8;tdcmodulecounter++){
      for(input=1;input<8;input++){
	   channelstart=0;
	   preampnum=(tdcmodulecounter*7)+input;
	   //printf("tdc %d   input %d   preamp %d  channel %d\n",tdcmodulecounter,input,preampnum,channel);

	   if(preampcount<13) { // wireplane X1  =================================================
	      	basecount=0;
	       	preampbase=0;
		channelstart=basecount+(preampcount-preampbase)*16;
		for(int i=channelstart;i<channelstart+16;i++){
		  tdcchan=(tdcmodulecounter*128) + (input*16) + i-channelstart;
		  Channel2Wire[tdcchan]=i;
                  //printf("chan2wire[tdcchan] %d  tdcchan %d  \n",Channel2Wire[tdcchan],tdcchan);
		}
	   }
	   else if(preampcount<35){ // wireplane X2  =================================================
	       	basecount=500;
	       	preampbase=22;
		channelstart=basecount+(preampcount-preampbase)*16;
		for(int i=channelstart;i<channelstart+16;i++){
		  tdcchan=(tdcmodulecounter*128) + (input*16) + i-channelstart;
		  Channel2Wire[tdcchan]=i;
                  //printf("chan2wire[tdcchan] %d  tdcchan %d  \n",Channel2Wire[tdcchan],tdcchan);
		}
	   }
	   preampcount++;	
      }
  }


}

/* ---------------------------------------------------------------------------------------*/
void setupchannel2wireXoldXU()
// Mapping of wires to channels when using 1 old VDC and 1 new VDC (placed with first wireplane being the X-wires)
// See camac-vme-cabling.xls
// This is fairly complicated due to design mistakes on the PCB's
// In this mapping 
// chan 0-207   = X wires VDC1
// chan 500-707 = X wires VDC2
// chan 800-943 = U wires VDC2
//
{
  int input,tdcmodulecounter,preampnum,channelstart,basecount;
  int preampcount=0;
  int preampbase=0;
  //int channel=0;
  int tdcchan;

  for(input=0;input<896;input++) Channel2Wire[input]=0;

  for(tdcmodulecounter=0;tdcmodulecounter<8;tdcmodulecounter++){
      for(input=1;input<8;input++){
	   channelstart=0;
	   preampnum=(tdcmodulecounter*7)+input;
	   //printf("tdc %d   input %d   preamp %d  channel %d\n",tdcmodulecounter,input,preampnum,channel);

	   if(preampcount<
13) { // wireplane X1  =================================================
	      	basecount=0;
	       	preampbase=0;
		channelstart=basecount+(preampcount-preampbase)*16;
		for(int i=channelstart;i<channelstart+16;i++){
		  tdcchan=(tdcmodulecounter*128) + (input*16) + i-channelstart;
		  Channel2Wire[tdcchan]=i;
                  //printf("chan2wire[tdcchan] %d  tdcchan %d  \n",Channel2Wire[tdcchan],tdcchan);
		}
	   }
	   else if(preampcount<22){ // wireplane U1  =================================================
	       	basecount=300;
	       	preampbase=13;
		channelstart=basecount+(preampcount-preampbase)*16;
		for(int i=channelstart;i<channelstart+16;i++){
		  tdcchan=(tdcmodulecounter*128) + (input*16) + i-channelstart;
		  Channel2Wire[tdcchan]=i;
		  //printf("chan2wire %d   tdcchan= %d  \n",Channel2Wire[tdcchan],tdcchan);
		}
	   }
	   else if(preampcount<35){ // wireplane X2  =================================================
	       	basecount=500;
	       	preampbase=22;
		channelstart=basecount+(preampcount-preampbase)*16;

		if(preampcount==(35-1)){		    
		  Channel2Wire[624]=697;
		  Channel2Wire[625]=696;
		  Channel2Wire[626]=695;
		  Channel2Wire[627]=694;
		  Channel2Wire[628]=693;
		  Channel2Wire[629]=692;
		  for(int i=230;i<240;i++){
		    Channel2Wire[i]=0;
		  }
		  //for(int i=624;i<640;i++){
		  //    printf("chan2wire %d   tdcchan= %d  \n",Channel2Wire[i],i);
		  //}
		}
		else {
		  int counter=1;
		  for(int i=channelstart;i<channelstart+16;i++){
		    tdcchan=(tdcmodulecounter*128) + (input*16) + i-channelstart;
		    Channel2Wire[tdcchan]=(channelstart+16) - counter;
		    counter++;
		    //printf("chan2wire %d   tdcchan= %d  \n",Channel2Wire[tdcchan],tdcchan);
		  }
		} 
	   }
	   else if(preampcount<44){// wireplane U2  =================================================
	       	basecount=800;
	       	preampbase=35;
		channelstart=basecount+(preampcount-preampbase)*16;
		for(int i=channelstart;i<channelstart+16;i++){
		  tdcchan=(tdcmodulecounter*128) + (input*16) + i-channelstart;
		  Channel2Wire[tdcchan]=i;
		  //printf("chan2wire %d   tdcchan= %d  \n",Channel2Wire[tdcchan],tdcchan);
		}
	   }
	   preampcount++;	
      }
  }


}




/* ---------------------------------------------------------------------------------------*/
void setupchannel2wireXUXold()
// hack the mapping of wires to channels with XU and then old X chamber
//
{
  int input,tdcmodulecounter,preampnum,channelstart,basecount;
  int preampcount=0;
  int preampbase=0;
  //int channel=0;
  int tdcchan;

  for(input=0;input<896;input++) Channel2Wire[input]=-1;

  for(tdcmodulecounter=0;tdcmodulecounter<8;tdcmodulecounter++){
      for(input=1;input<8;input++){
	   channelstart=0;
	   preampnum=(tdcmodulecounter*7)+input;
	   //printf("tdc %d   input %d   preamp %d \n",tdcmodulecounter,input,preampnum);

	   if(preampcount<13) { // wireplane X1  =================================================
	      	basecount=0;
	       	preampbase=0;
		channelstart=basecount+(preampcount-preampbase)*16;

		if(preampcount==(13-1)){		    
		  Channel2Wire[224]=197;
		  Channel2Wire[225]=196;
		  Channel2Wire[226]=195;
		  Channel2Wire[227]=194;
		  Channel2Wire[228]=193;
		  Channel2Wire[229]=192;
		  for(int i=230;i<240;i++){
		    Channel2Wire[i]=0;
		  }
		  //for(int i=224;i<240;i++){
		  //    printf("chan2wire %d   tdcchan= %d  \n",Channel2Wire[i],i);
		  //}
		}
		else {
		  int counter=1;
		  for(int i=channelstart;i<channelstart+16;i++){
		    tdcchan=(tdcmodulecounter*128) + (input*16) + i-channelstart;
		    Channel2Wire[tdcchan]=(channelstart+16) - counter;
		    counter++;
		    //printf("chan2wire %d   tdcchan= %d  \n",Channel2Wire[tdcchan],tdcchan);
		  }
		} 
	   }
	   else if(preampcount<22){ // wireplane U1  =================================================
	       	basecount=300;
	       	preampbase=13;
		channelstart=basecount+(preampcount-preampbase)*16;
		for(int i=channelstart;i<channelstart+16;i++){
		  tdcchan=(tdcmodulecounter*128) + (input*16) + i-channelstart;
		  Channel2Wire[tdcchan]=i;
		  //printf("chan2wire %d   tdcchan= %d  \n",Channel2Wire[tdcchan],tdcchan);
		}
	   }
	   else if(preampcount>21 && preampcount <35){ // wireplane X2  =================================================
	       	basecount=508;
	       	preampbase=23;
		channelstart=basecount + (preampcount-preampbase)*16;
		if(preampcount==22){
		  Channel2Wire[424]=500;
		  Channel2Wire[425]=501;
		  Channel2Wire[426]=502;
		  Channel2Wire[427]=503;
		  Channel2Wire[428]=504;
		  Channel2Wire[429]=505;
		  Channel2Wire[430]=506;
		  Channel2Wire[431]=507;			
		  for(int i=424;i<432;i++){
		    tdcchan=i;
                    printf("chan2wire[%d]  = %d  \n",tdcchan,Channel2Wire[tdcchan]);
                    //printf("channelstart %d;   preampcount %d ;   chan2wire[%d] = %d   \n",channelstart, preampcount, tdcchan, Channel2Wire[tdcchan]);
                  }
		}
		else{
		  for(int i=channelstart;i<channelstart+16;i++){
		    tdcchan=(tdcmodulecounter*128) +  (input*16) +(i-channelstart);
		    Channel2Wire[tdcchan]=i;
                    printf("chan2wire[%d] = %d   \n",tdcchan, Channel2Wire[tdcchan]);
		  }
		}
	   }
	   preampcount++;	
      }
  }
}






/* ---------------------------------------------------------------------------------------*/
void setupchannel2wire()
// mapping of wires to channels
// See camac-vme-cabling.xls
// This is needed due to design mistakes and peculiarities on the PCB's
{
  int input,tdcmodulecounter,preampnum,channelstart,basecount;
  int preampcount=0;
  int preampbase=0;
  //int channel=0;
  int tdcchan;

  for(input=0;input<896;input++) Channel2Wire[input]=0;

  for(tdcmodulecounter=0;tdcmodulecounter<8;tdcmodulecounter++){
      for(input=1;input<8;input++){
	   channelstart=0;
	   preampnum=(tdcmodulecounter*7)+input;
	   //printf("tdc %d   input %d   preamp %d  channel %d\n",tdcmodulecounter,input,preampnum,channel);
	   if(preampcount<13) { // wireplane X1  =================================================
	      	basecount=0;
	       	preampbase=0;
		channelstart=basecount+(preampcount-preampbase)*16;
		if(preampcount==0){		    
		  Channel2Wire[16]=10;
		  Channel2Wire[17]=11;
		  Channel2Wire[18]=12;
		  Channel2Wire[19]=13;
		  Channel2Wire[20]=14;
		  Channel2Wire[21]=15;
		  for(int i=22;i<31;i++){
		    Channel2Wire[i]=0;
		  }
		  channelstart=basecount+(preampcount-preampbase)*16;
		  for(int i=channelstart;i<channelstart+16;i++){
		    tdcchan=(tdcmodulecounter*128) + (input*16) + i-channelstart;
		  }
		}
		else {
		  for(int i=channelstart;i<channelstart+16;i++){
		    tdcchan=(tdcmodulecounter*128) + (input*16) + i-channelstart;
		    Channel2Wire[tdcchan]=i;
		  }
		}
	   }
	   else if(preampcount<22){ // wireplane U1  =================================================
	       	basecount=300;
	       	preampbase=13;
		channelstart=basecount+(preampcount-preampbase)*16;
		int counter=1;
		for(int i=channelstart;i<channelstart+16;i++){
		  tdcchan=(tdcmodulecounter*128) + (input*16) + i-channelstart;
		  Channel2Wire[tdcchan]=(channelstart+16) - counter;
		  counter++;
		}
	   }
	   else if(preampcount<35){ // wireplane X2  =================================================
	       	basecount=500;
	       	preampbase=22;
		channelstart=basecount+(preampcount-preampbase)*16;
		if(preampcount==22){		    
		  Channel2Wire[416]=510;
		  Channel2Wire[417]=511;
		  Channel2Wire[418]=512;
		  Channel2Wire[419]=513;
		  Channel2Wire[420]=514;
		  Channel2Wire[421]=515;
		  for(int i=422;i<431;i++){
		    Channel2Wire[i]=0;
		  }
		  channelstart=basecount+(preampcount-preampbase)*16;
		  for(int i=channelstart;i<channelstart+16;i++){
		    tdcchan=(tdcmodulecounter*128) + (input*16) + i-channelstart;
		    //printf("tdc %d input %d channel %d wire %d\n",tdcmodulecounter,input,tdcchan,Channel2Wire[tdcchan]);
		  }
		}
		else {
		  for(int i=channelstart;i<channelstart+16;i++){
		    tdcchan=(tdcmodulecounter*128) + (input*16) + i-channelstart;
		    Channel2Wire[tdcchan]=i;
		    //printf("tdc %d input %d channel %d wire %d\n",tdcmodulecounter,input,tdcchan,Channel2Wire[tdcchan]);
		  }
		}	   }
	   else if(preampcount<44){// wireplane U2  =================================================
	       	basecount=800;
	       	preampbase=35;
		channelstart=basecount+(preampcount-preampbase)*16;
		int counter=1;
		for(int i=channelstart;i<channelstart+16;i++){
		  tdcchan=(tdcmodulecounter*128) + (input*16) + i-channelstart;
		  Channel2Wire[tdcchan]=(channelstart+16) - counter;
		  counter++;
		}
	   }
	   preampcount++;	
      }
  }
}

/* ---------------------------------------------------------------------------------------*/
void setupchannel2wireXUXU()
// hack the mapping of wires to channels when new VDC is placed with first wireplane being the X-wires
// See camac-vme-cabling.xls
// This is due to design mistakes on the PCB's
//
{
  int input,tdcmodulecounter,preampnum,channelstart,basecount;
  int preampcount=0;
  int preampbase=0;
  //int channel=0;
  int tdcchan;

  for(input=0;input<896;input++) Channel2Wire[input]=0;

  for(tdcmodulecounter=0;tdcmodulecounter<8;tdcmodulecounter++){
      for(input=1;input<8;input++){
	   channelstart=0;
	   preampnum=(tdcmodulecounter*7)+input;
	   //printf("tdc %d   input %d   preamp %d  channel %d\n",tdcmodulecounter,input,preampnum,channel);

	   if(preampcount<13) { // wireplane X1  =================================================
	      	basecount=0;
	       	preampbase=0;
		channelstart=basecount+(preampcount-preampbase)*16;

		if(preampcount==(13-1)){		    
		  Channel2Wire[224]=197;
		  Channel2Wire[225]=196;
		  Channel2Wire[226]=195;
		  Channel2Wire[227]=194;
		  Channel2Wire[228]=193;
		  Channel2Wire[229]=192;
		  for(int i=230;i<240;i++){
		    Channel2Wire[i]=0;
		  }
		  //for(int i=223;i<240;i++){
		  //    printf("chan2wire %d   tdcchan= %d  \n",Channel2Wire[i],i);
		  //}
		}
		else {
		  int counter=1;
		  for(int i=channelstart;i<channelstart+16;i++){
		    tdcchan=(tdcmodulecounter*128) + (input*16) + i-channelstart;
		    Channel2Wire[tdcchan]=(channelstart+16) - counter;
		    counter++;
		    //printf("chan2wire %d   tdcchan= %d  \n",Channel2Wire[tdcchan],tdcchan);
		  }
		} 
	   }
	   else if(preampcount<22){ // wireplane U1  =================================================
	       	basecount=300;
	       	preampbase=13;
		channelstart=basecount+(preampcount-preampbase)*16;
		for(int i=channelstart;i<channelstart+16;i++){
		  tdcchan=(tdcmodulecounter*128) + (input*16) + i-channelstart;
		  Channel2Wire[tdcchan]=i;
		  //printf("chan2wire %d   tdcchan= %d  \n",Channel2Wire[tdcchan],tdcchan);
		}
	   }
	   else if(preampcount<35){ // wireplane X2  =================================================
	       	basecount=500;
	       	preampbase=22;
		channelstart=basecount+(preampcount-preampbase)*16;

		if(preampcount==(35-1)){		    
		  Channel2Wire[624]=697;
		  Channel2Wire[625]=696;
		  Channel2Wire[626]=695;
		  Channel2Wire[627]=694;
		  Channel2Wire[628]=693;
		  Channel2Wire[629]=692;
		  for(int i=230;i<240;i++){
		    Channel2Wire[i]=0;
		  }
		  //for(int i=624;i<640;i++){
		  //    printf("chan2wire %d   tdcchan= %d  \n",Channel2Wire[i],i);
		  //}
		}
		else {
		  int counter=1;
		  for(int i=channelstart;i<channelstart+16;i++){
		    tdcchan=(tdcmodulecounter*128) + (input*16) + i-channelstart;
		    Channel2Wire[tdcchan]=(channelstart+16) - counter;
		    counter++;
		    //printf("chan2wire %d   tdcchan= %d  \n",Channel2Wire[tdcchan],tdcchan);
		  }
		} 
	   }
	   else if(preampcount<44){// wireplane U2  =================================================
	       	basecount=800;
	       	preampbase=35;
		channelstart=basecount+(preampcount-preampbase)*16;
		for(int i=channelstart;i<channelstart+16;i++){
		  tdcchan=(tdcmodulecounter*128) + (input*16) + i-channelstart;
		  Channel2Wire[tdcchan]=i;
		  //printf("chan2wire %d   tdcchan= %d  \n",Channel2Wire[tdcchan],tdcchan);
		}
	   }
	   preampcount++;	
      }
  }
}

//----------------------------------------------------------------------------------------
void getglobaldata()
{

  HNDLE hDB, hKey;

  // open ODB structures
  hDB=gAnalyzer->GetMidasOnlineDataBase();
  db_find_key(hDB, 0, "/Analyzer/Parameters/Global", &hKey);

  if(db_open_record(hDB, hKey, &global, sizeof(GLOBAL_PARAM), MODE_READ, NULL, NULL) != DB_SUCCESS) {
    cout << "analyzer_init == Cannot open \"/Analyzer/Parameters/Global\" tree in ODB" << endl;//);
    exit(1);//return 0;
  }

  //db_close_record(hDB,hKey);

}


//----------------------------------------------------------------------------------------
void getgatesdata()
{
  HNDLE hDB, hKey;

  // open ODB structures
  hDB=gAnalyzer->GetMidasOnlineDataBase();
  db_find_key(hDB, 0, "/Analyzer/Parameters/Gates", &hKey);

  if(db_open_record(hDB, hKey, &gates, sizeof(GATES_PARAM), MODE_READ, NULL, NULL) != DB_SUCCESS) {
    cout << "analyzer_init == Cannot open \"/Analyzer/Parameters/Gates\" tree in ODB" << endl;//);
    exit(1);//return 0;
  }
  //db_close_record(hDB,hKey);
}

                
//------------------------------------------------------------------------------
void ZeroFPWireTimeDist(void)
{
   for(int i =0; i < MAX_WIRES_PER_EVENT; i++) {	
      X1.wire[i] = 0;
      X1.time[i] = 0;
      X1.dist[i] = 0.0;
      X2.wire[i] = 0;
      X2.time[i] = 0;
      X2.dist[i] = 0.0;
      U1.wire[i] = 0;
      U1.time[i] = 0;
      U1.dist[i] = 0.0;
      U2.wire[i] = 0;
      U2.time[i] = 0;
      U2.dist[i] = 0.0;
   }   
}


//------------------------------------------------------------------------------
void sortTDCs(Int_t hits, Int_t wire[], Int_t time[])
//Bubble sort so that order of e.g. X1.wire[] is correct
{
   for(int i = 0; i < hits ; i++) { 
      for(int j = hits-1; j > i ; j--) { 
	 int tempwire;

	int z=0;
	 int temptime;
	 if(wire[j-1] > wire[j]){
	    tempwire=wire[j-1];
  	    wire[j-1]=wire[j];
	    wire[j]=tempwire;
	    //
	    temptime=time[j-1];
  	    time[j-1]=time[j];
	    time[j]=temptime;
	 }	      
      }
   }
}


//--------------------------------------------------------------------------------------
void CalcThetaFP(Double_t X1, Double_t X2, Double_t *Theta)
{
   Double_t x;
   //x=(X2 + 250) - X1 ;               
   //*Theta=57.29578*atan(180/x);
   x=(X2 + global.x_x1x2) - X1 ;               
   *Theta=57.29578*atan(global.z_x1x2/x);
}


//--------------------------------------------------------------------------------------
void CalcThetaScat(Double_t Thetafp, Double_t X1, Double_t *Thetascat)
{
   Double_t A,B;
   //A=gates.a0 + gates.a1*X1 + gates.a2*X1*X1;               
   //A=-0.741205 -9.34925e-05*X1 + 0*X1*X1;               //pr83
   A=-0.4795 -2.657e-05*X1 + 0*X1*X1;
   //A=-1.02978 -4.13417e-05*X1 + 0*X1*X1;               
   //B=gates.b0 + gates.b1*X1 + gates.b2*X1*X1;               
   //B=25.5606 -0.00193707*X1 +0*X1*X1;                   //pr183
   B=18.529 -0.003041*X1 +0*X1*X1;
   //B=34.3399-0.0037008*X1 +0*X1*X1;                   
   *Thetascat=1*(A*Thetafp+B);
   //printf("Thetascat %f  \n",*Thetascat);
}


//--------------------------------------------------------------------------------------
void CalcYFP(Double_t x, Double_t u, Double_t thFP, Double_t *y)
{
  Double_t sinu=0.766044443;// sin(U_WIRE_ANGLE/57.2957); 
  Double_t tanu=1.191753593; //tan(U_WIRE_ANGLE/57.2957);
  Double_t tmp1,tmp2;
  Double_t tanfp=tan(thFP/57.2957);

  // for UX setup
  //tmp1=(u*tanfp+sinu*16);    
  //tmp2=sinu*tanfp;
  //*y=(tmp1/tmp2-x)*tanu+76.27-50;  // the 76.27 is the offset due to first u and x wires not sharing the origin
				    // and the -50 is just to place the y around 0
  // for XU setup
  tmp1=(u*tanfp-sinu*16);    
  tmp2=sinu*tanfp;
  *y=-1*((tmp1/tmp2-x)*tanu+26.21-50+10);  //+10 added to get the darn thing at zero...need some serious fault finding. compare with offline...

  //tmp1=16.0/(tanfp*sinu);
  //u=u*sin(U_WIRE_ANGLE/57.2957);  // VERY IMPORTANT! To work in y' ref frame, not y. See K600 book 3 p172
  //tmp2=(u+tmp1)/sinu;
  //*y=(x-tmp2)*tanu;
}


//--------------------------------------------------------------------------------------
void CalcPhiFP(Double_t X1, Double_t Y1, Double_t X2, Double_t Y2,  Double_t thFP, Double_t *Phi)
{
   Double_t y;
   y= Y2 - Y1 ;               
   *Phi=57.29578*atan(y*sin(thFP/57.29578)/global.z_x1x2);
}


//--------------------------------------------------------------------------------------
void raytrace(Double_t dd[],Int_t wire[],Double_t *_X,Double_t *_Th,Double_t *_chisq,Int_t wire_num,Double_t res[],Int_t *_flag){

   //printf("-----------------start raytrace-----------------\n");
   int i;
   Double_t x_tttv, sum_0=0.0, sum_x=0.0, sum_z=0.0, sum_xz=0.0, sum_x2=0.0;
   Int_t    wireID_first=0,wireID_last=0,wireID_min=0;
   Double_t wireID_ave=0,wirechisq=0;
   Double_t x_first, x_last;
   Double_t a1,b1,a2,b2,a,b;
   Double_t a_pre, b_pre, X_pre, Th_pre;
   Double_t X_v1=1.0, Th_v1=1.0,chisq_v1=0.0;
   Double_t X_v2=1.0, Th_v2=1.0,chisq_v2=0.0;
   Double_t drift_min_esti,drift_difference;
   Int_t flag1=0;
   Double_t tmpdd[20];
   Int_t tmpwire[20];

   wireID_first = 0;                // wireID_first an array index nr, NOT a real wire number
   wireID_last  = wire_num-1;       // wireID_last  an array index nr, NOT a real wire number

   // Label wire associated with minimum drift distance
   for(i=1;i<wire_num;i++){
     if(dd[wireID_min] > dd[i]) wireID_min = i;       //wireID_min an array index nr, NOT a real wire number
   }
    
   // Label events with more than 1 drift distance local minimum
   for(i=1;i<(wire_num-1);i++){
     if( (dd[i]>dd[i-1]) && (dd[i]>dd[i+1]) ) {
       flag1=1;    
       if(dd[i-1]==dd[wireID_first]){   // is one of the minima at start of wiregroup?
          flag1=2;
       }
       if(dd[i+1]==dd[wireID_last]){   // is one of the minima at the end of the wiregroup?
          flag1=3;
       }
     }
   }

   if(flag1!=0){        // if I know there are more than 2 min I try use only the middle wires
     for(i=1;i<(wire_num-1);i++){
       tmpdd[i-1]=dd[i];
       tmpwire[i-1]=wire[i];
       dd[i-1]=tmpdd[i-1];
       wire[i-1]=tmpwire[i-1];
     }
     wire_num=wire_num-2;
     wireID_last= wire_num-1;

     // TRY AGAIN: Label wire associated with minimum drift distance
     flag1=0;
     for(i=1;i<wire_num;i++){
       if(dd[wireID_min] > dd[i]) wireID_min = i;       //wireID_min an array index nr, NOT a real wire number
     }

     Int_t counter=1;
     // How to identify monotinically increasing   sets of dd
     for(i=0;i<(wire_num-1);i++){
       if( dd[i]>dd[i+1] ) {
	 counter+=1;    
       }
     }    
     if(counter==wire_num) flag1=5;

     counter=1;
     // How to identify monotinically decreasing  sets of dd
     for(i=0;i<(wire_num-1);i++){
       if( dd[i]<dd[i+1] ) {
	 counter+=1;    
       }
     }    
     if(counter==wire_num) flag1=6;

     // TRY AGAIN Label events with more than 1 drift distance local minimum
     for(i=1;i<(wire_num-1);i++){
       if( (dd[i]>dd[i-1]) && (dd[i]>dd[i+1]) ) {
	 flag1=1;    
	 if(dd[i-1]==dd[wireID_first]){   // is one of the minima at start of wiregroup?
	   flag1=2;
	 }
	 if(dd[i+1]==dd[wireID_last]){   // is one of the minima at the end of the wiregroup?
	   flag1=3;
	 }
       }
     }
     if(wire_num<3) flag1=4;
   }   

   // Determine tentative ray: straigh line through first and last wires
   x_first = X_WIRESPACE*(wire[wireID_first]);  //pos in mm of first wire of group
   x_last  = X_WIRESPACE*(wire[wireID_last]);   //pos in mm of last wire of group

   a_pre = (dd[wireID_first]+dd[wireID_last])/(x_first-x_last);    // slope
   b_pre = dd[wireID_first]-a_pre*x_first;                        // y offset
   X_pre = (-1.)*b_pre/a_pre;
   Th_pre =(-1.)*57.29578*atan(a_pre);
   
   // Use the above information to determine sign of drift distance
   // + drift on K600 side, - drift downstream side
   for(i=0;i<wire_num;++i){     
     if( ( a_pre*(X_WIRESPACE*wire[i])+b_pre) < 0 ){
        dd[i] *= -1;
     }
   }

   //========================================================================
   //least square fit 1
   sum_0=0; sum_x=0; sum_z=0; sum_xz=0; sum_x2=0; 

   for(i=0;i<wire_num;++i){
     if(dd[i]!=dd[wireID_min]){         //ignore the wire with smallest drifttime. It causes inaccuracies
       x_tttv = X_WIRESPACE*(float(wire[i]));  // left -> high Ex  
       sum_0  += 1.0;
       sum_x  += x_tttv;
       sum_z  += dd[i];
       sum_xz += x_tttv*dd[i];
       sum_x2 += pow(x_tttv,2);
     }
   }
   a1 = (sum_x*sum_z-sum_0*sum_xz)/(pow(sum_x,2)-sum_0*sum_x2);
   b1 = (sum_x*sum_xz-sum_x2*sum_z)/(pow(sum_x,2)-sum_0*sum_x2);  
   X_v1  = (-1.)*b1/a1;
   Th_v1 = (-1.)*57.29578*atan(a1); // [deg.]
 
   for(i=0;i<wire_num;++i){
     if(dd[i]!=dd[wireID_min]){            //ignore the wire with smallest drifttime. It causes inaccuracies
       chisq_v1 += pow(dd[i]-(a1*X_WIRESPACE*(wire[i])+b1),2); 
       ++wirechisq;
     }
   }
   chisq_v1 /= wirechisq;


   //----- the values sent back to the main routine---------
   *_X = X_v1; 
   *_Th = Th_v1;             
   *_chisq = chisq_v1;
   a=a1;
   b=b1;
   *_flag=flag1;

   //----------------------------------------------

   for(i=0;i<7;i++){
     res[i]=-100.;     // initial value of res array 
   }

   if(wireID_first!=wireID_min && wireID_last!=wireID_min && wire_num>3){  
   // min drift distance may not be on edge of wire group, and only look at events >4 wires
     //res[0] is a relative position in drift cell where track cross wireplane
     res[0]=(*_X/4.0)-int(*_X/4.);           
      
     //res[1] same as XSYS calc: the diff in slope (since wireID_min is used res[1] not very accurate
     res[1]=(dd[wireID_min+1]-dd[wireID_min])/(wire[wireID_min+1]-wire[wireID_min]) 
       + ((dd[wireID_min-1]-dd[wireID_min])/(wire[wireID_min]-wire[wireID_min-1]));  
                  
     //res[5] is difference in pos calculated at min driftt wire; drift_min_esti from RCNP analyzer sorter_user.c
     drift_min_esti=( (wireID_last-wireID_min)*dd[wireID_first] + (wireID_min-wireID_first)*dd[wireID_last] )
                    / (wireID_last - wireID_first);   
     res[5]=drift_min_esti- dd[wireID_min];
     
     //res[6] is close to the Bertozzi definition
     if((wireID_last-wireID_first+1)>4 && wire_num>4) {
       res[6]=(dd[wireID_first]-dd[wireID_first+1]) - (dd[wireID_last-1] - dd[wireID_last]);
     }
     else res[6]=-9.;
     
     //res[7] is drift_min_esti from RCNP analyzer sorter_user.c
     res[7]=drift_min_esti;

     // drift_min_esti from EVAL code?????true???
     drift_min_esti = a* (X_WIRESPACE*(wire[wireID_min])) + b;   
     res[8]=drift_min_esti;
   }
   
}


//______________________________________________________________________________
void K600TAnalyseFolders::BeginOfRun()
{
   counterscaler =0;

   for(int i =0; i < MAX_WIRES_PER_EVENT; i++) {	
      X1.wire[i] = 0;
      X1.time[i] = 0;
      X1.dist[i] = 0.0;
      X2.wire[i] = 0;
      X2.time[i] = 0;
      X2.dist[i] = 0.0;
      U1.wire[i] = 0;
      U1.time[i] = 0;
      U1.dist[i] = 0.0;
      U2.wire[i] = 0;
      U2.time[i] = 0;
      U2.dist[i] = 0.0;
   }   

   float tmp;
   for(int j = 0; j < 896; j++) {
     tmp=cableOffset[j]+1000;
     for(int k = 0; k < (int(tmp)); k++) {  
       GetCableOffsetTable()->Fill(j);                     
     }
   }

   // fill LUT spectra
   for(int j = 0; j < LUT_CHANNELS; j++) {
     for(int k = 0; k < lutx1[j]*1000; k++) {
        GetLUTAt(0)->Fill(j);
     }
     for(int k = 0; k < lutu1[j]*1000; k++) {
        GetLUTAt(1)->Fill(j);
     }
     for(int k = 0; k < lutx2[j]*1000; k++) {
        GetLUTAt(2)->Fill(j);
     }
     for(int k = 0; k < lutu2[j]*1000; k++) {
        GetLUTAt(3)->Fill(j);
     }
   }

}


//______________________________________________________________________________
void K600TAnalyseFolders::Init()
{

  // initialize histogram names
  //
  GetQDCRawAt(0)->SetTitle("Paddle 1 HiP PH");  
  GetQDCRawAt(1)->SetTitle("Paddle 1 LoP PH");  
  GetQDCRawAt(2)->SetTitle("Paddle 2 HiP PH");  
  GetQDCRawAt(3)->SetTitle("Paddle 2 LoP PH");  
  GetQDCRawAt(4)->SetTitle("Attenuated Paddle 1 HiP PH");  
  GetQDCRawAt(5)->SetTitle("Attenuated Paddle 1 LoP PH");  
  GetQDCRawAt(6)->SetTitle("Attenuated Paddle 2 HiP PH");  
  GetQDCRawAt(7)->SetTitle("Attenuated Paddle 2 LoP PH");  

  GetPaddleAveAt(0)->SetTitle("Paddle 1 Average PH");  
  GetPaddleAveAt(1)->SetTitle("Paddle 2 Average PH");  

  GetHitPatternAt(0)->SetTitle("HitPattern: all events");  
  GetHitPatternAt(1)->SetTitle("HitPattern: PID events");  
  GetHitPatternXAt(0)->SetTitle("HitPattern X1: good events");  
  GetHitPatternXAt(1)->SetTitle("HitPattern X2: good events");  

  GetHitsPerEventAt(0)->SetTitle("Hits per good event: X1");  
  GetHitsPerEventAt(1)->SetTitle("Hits per good event: U1");  
  GetHitsPerEventAt(2)->SetTitle("Hits per good event: X2");  
  GetHitsPerEventAt(3)->SetTitle("Hits per good event: U2");  

  GetDriftTimeOffsetAt(0)->SetTitle("Drifttime: X1 (all events)");  
  GetDriftTimeOffsetAt(1)->SetTitle("Drifttime: U1 (all events)");  
  GetDriftTimeOffsetAt(2)->SetTitle("Drifttime: X2 (all events)");  
  GetDriftTimeOffsetAt(3)->SetTitle("Drifttime: U2 (all events)");  

  GetDriftTimeOffsetGoodAt(0)->SetTitle("Drifttime: X1 (good events)");  
  GetDriftTimeOffsetGoodAt(1)->SetTitle("Drifttime: U1 (good events)");  
  GetDriftTimeOffsetGoodAt(2)->SetTitle("Drifttime: X2 (good events)");  
  GetDriftTimeOffsetGoodAt(3)->SetTitle("Drifttime: U2 (good events)");  

  GetDriftLengthAt(0)->SetTitle("Driftlength: X1");  
  GetDriftLengthAt(1)->SetTitle("Driftlength: U1");  
  GetDriftLengthAt(2)->SetTitle("Driftlength: X2");  
  GetDriftLengthAt(3)->SetTitle("Driftlength: U2");  

  GetEfficiencyAt(0)->SetTitle("Efficiency: X1");  
  GetEfficiencyAt(1)->SetTitle("Efficiency: U1");  
  GetEfficiencyAt(2)->SetTitle("Efficiency: X2");  
  GetEfficiencyAt(3)->SetTitle("Efficiency: U2");  

  GetEfficiencyIDAt(0)->SetTitle("Efficiency Calc: X1");  
  GetEfficiencyIDAt(1)->SetTitle("Efficiency Calc: U1");  
  GetEfficiencyIDAt(2)->SetTitle("Efficiency Calc: X2");  
  GetEfficiencyIDAt(3)->SetTitle("Efficiency Calc: U2");  

  GetPositionAt(0)->SetTitle("Position: X1 (chisq<0.2)");  
  GetPositionAt(1)->SetTitle("Position: U1");  
  GetPositionAt(2)->SetTitle("Position: X2");  
  GetPositionAt(3)->SetTitle("Position: U2");  

  GetThFPvsX1()->SetTitle("ThFP vs X1 (chisq<0.2)");
  GetX2Y2()->SetTitle("Y2 vs X1 (chisq<0.2)");
  GetPositionYGate()->SetTitle("Position: X1 (chisq<0.2)");

  GetAngleAt(0)->SetTitle("Angle: X1");  
  GetAngleAt(1)->SetTitle("Angle: U1");  
  GetAngleAt(2)->SetTitle("Angle: X2");  
  GetAngleAt(3)->SetTitle("Angle: U2");  
  
  GetRes2DAt(0)->SetTitle("2D resolution plot: X1");  
  GetRes2DAt(1)->SetTitle("2D resolution plot: U1");  
  GetRes2DAt(2)->SetTitle("2D resolution plot: X2");  
  GetRes2DAt(3)->SetTitle("2D resolution plot: U2");  

  GetCableOffsetTable()->SetTitle("cable offsets (1000 added to prevent neg histogram)");  

  GetPad1vsTOFAt(0)->SetTitle("PID: paddle 1 vs TOF (TDC1)");  
  GetPad1vsTOFAt(1)->SetTitle("PID: paddle 1 vs TOF (TDC2)");  
  GetPad1vsTOFAt(2)->SetTitle("PID: paddle 1 vs TOF (TDC3)");  
  GetPad1vsTOFAt(3)->SetTitle("PID: paddle 1 vs TOF (TDC4)");  
  GetPad1vsTOFAt(4)->SetTitle("PID: paddle 1 vs TOF (TDC5)");  
  GetPad1vsTOFAt(5)->SetTitle("PID: paddle 1 vs TOF (TDC6)");  
  GetPad1vsTOFAt(6)->SetTitle("PID: paddle 1 vs TOF (TDC7)");  

	//Add TCutGs to the sort code -- Phil
	gROOT->ProcessLine(".x CUTSiFBADC.C");
	CUTSiFBADC = (TCutG*)gROOT->FindObjectAny("CUTSiFBADC");

   getglobaldata();
   getgatesdata();

        // create a box showing pad1tof gate settings
        //TBox *box = new TBox(gates.lowtof,gates.hitof,gates.hipad1,gates.lowpad1);
        //box->SetFillStyle(0);
        //box->SetLineColor(kRed);
	//box = (TBox*)gROOT->FindObjectAny("box");

  // see what the global parameters are
  cout << "ODB: /Analyzer/Parameters/Global/lut_x1_offset = " << global.lut_x1_offset <<endl;//);
  cout << "ODB: /Analyzer/Parameters/Global/lut_u1_offset = " << global.lut_u1_offset <<endl;//);
  cout << "ODB: /Analyzer/Parameters/Global/lut_x2_offset = " << global.lut_x2_offset <<endl;//);
  cout << "ODB: /Analyzer/Parameters/Global/lut_u2_offset = " << global.lut_u2_offset <<endl;//);

  cout << "ODB: /Analyzer/Parameters/Global/x_x1x2 = " << global.x_x1x2 <<endl;//);
  cout << "ODB: /Analyzer/Parameters/Global/z_x1x2 = " << global.z_x1x2 <<endl;//);
  cout << "ODB: /Analyzer/Parameters/Global/misswires = " << global.misswires <<endl;//);
  
  // read in cable offsets, and fill a histogram 
  read_cable(cableOffset,"CableLength.dat");
  float tmp;
  for(int j = 0; j < 896; j++) {
     tmp=cableOffset[j]+1000;
     for(int k = 0; k < (int(tmp)); k++) {  
     //for(int k = 0; k < (int(cableOffset[j])); k++) {  
       GetCableOffsetTable()->Fill(j);                     
     }
  }

  //read in lut's
  read_lut(lutx1,-0,"lut-newdaq-x1.dat");  
  read_lut(lutu1,-0,"lut-newdaq-u1.dat");    
  read_lut(lutx2,-0,"lut-newdaq-x2.dat");    
  read_lut(lutu2,-0,"lut-newdaq-u2.dat");    
/*
  read_lut(lutx1,global.lut_x1_offset,"lut-newdaq-x1.dat");   
  read_lut(lutu1,global.lut_u1_offset,"lut-newdaq-u1.dat");         
  read_lut(lutx2,global.lut_x2_offset,"lut-newdaq-x2.dat");   
  read_lut(lutu2,global.lut_u2_offset,"lut-newdaq-u2.dat");    
*/
   // And immediately fill LUT spectra
   for(int j = 0; j < LUT_CHANNELS; j++) {
     for(int k = 0; k < lutx1[j]*1000; k++) {
        GetLUTAt(0)->Fill(j);
     }
     for(int k = 0; k < lutu1[j]*1000; k++) {
        GetLUTAt(1)->Fill(j);
     }
     for(int k = 0; k < lutx2[j]*1000; k++) {
        GetLUTAt(2)->Fill(j);
     }
     for(int k = 0; k < lutu2[j]*1000; k++) {
        GetLUTAt(3)->Fill(j);
     }
   }

  //stuff for scalers
  counter=0;
  for(Int_t i=0;i<8;i++){
    oldscaler[i]=0;
    scaler[i]=0;
    scalerpsec[i]=0;
  }

  counterscaler =0;

  //setupchannel2wire();      //create table that translates TDC chan to a wire nr from 1-1000
  //setupchannel2wireXUXU();      //create table that translates TDC chan to a wire nr from 1-1000
  setupchannel2wireXUXold();      //create table that translates TDC chan to a wire nr from 1-1000
  //setupchannel2wireXoldXU();      //create table that translates TDC chan to a wire nr from 1-1000
  //setupchannel2wireXoldXold();      //create table that translates TDC chan to a wire nr from 1-1000

}


//______________________________________________________________________________
void K600TAnalyseFolders::Event()
{
  //copy and paste from f-plane.c (almost) and then modification for folders etc

   DWORD data;//*ptdc,*pqdc,*ppr,*psclr;
   Int_t ntdc = 0, nqdc=0, nadc=0, npr=0, nsclr=0;

   Int_t channel, time, channelnew;
   Int_t x1_hits = 0, x2_hits = 0, u1_hits = 0, u2_hits = 0;
   Int_t x1_hits_PID = 0, x2_hits_PID = 0, u1_hits_PID = 0, u2_hits_PID = 0;
   Int_t x1_hits_dt = 0, x2_hits_dt = 0, u1_hits_dt = 0, u2_hits_dt = 0;

   Double_t pad1hipt, pad1lowpt, pad2hipt, pad2lowpt;  // time info for the 4 paddle pmts

   Int_t tdcmodule, wire;
   Int_t ref_time, offset_time;
   Int_t tof, toftmp;
   Int_t reftimes[8]; 
   Int_t rawtdcchannel=0;
   Int_t Clovertime;

   // parameters in focal plane
   Double_t X1pos=-100.0,X2pos=-100.0, U1pos=-100.0, U2pos=-100.0;
   Double_t ThX1=-100.0, ThX2=-100.0,  ThU1=-100.0,  ThU2=-100.0;
   Double_t chisq_X1=15.0,chisq_X2=15.0,chisq_U1=15.0,chisq_U2=15.0;
   Double_t ThFP=-100, ThSCAT=-100, PhiFP=-100;
   Double_t Y1=-100.0,Y2=-100.0;
   Double_t resolution[8];                 // a array of numbers used in res plots
   Int_t drifttime=0;
   Int_t flagX1=-100, flagX2=-100, flagU1=-100, flagU2=-100;
   //Double_t delta;

   // Used in histogram hEventID
   Int_t ev_id_latch=29, ev_id_all=0,      ev_id_noTDC=1, ev_id_pid=2;
   Int_t ev_id_X1_PID=5, ev_id_X1_wires=6, ev_id_X1_good=7;
   Int_t ev_id_U1_PID=9, ev_id_U1_wires=10, ev_id_U1_good=11;
   Int_t ev_id_X2_PID=13,ev_id_X2_wires=14, ev_id_X2_good=15;
   Int_t ev_id_U2_PID=17,ev_id_U2_wires=18, ev_id_U2_good=19;

   // Used in histogram hEventID, trying to figure out which wireplanes fired
   Int_t ev_id_4planes=21,  ev_id_X1U1X2=22,   ev_id_X1U1U2=23;
   Int_t ev_id_goodX1U1=24, ev_id_goodX2U2=25, ev_id_goodX1X2=26, ev_id_goodU1U2=27;

   // Used in histogram e.g. X1_eff_ID etc. Help id eff problems
   Int_t ev_all=1, ev_PID=2;       
   Int_t ev_drifttime=3, ev_wiresperevent=4;
   Int_t ev_wiregap=5, ev_good=6, ev_multiplemin=10;


   //----------------------------------------------------------------------
   // create a box showing pad1tof gate settings

   //gates.lowtof,gates.hitof,gates.hipad1,gates.lowpad1);
   //box->Set 

   //----------------------------------------------------------------------
   // look for SCLR bank 

   nsclr=gAnalyzer->GetMidasDAQ()->GetSCLRBankEntries();
   for(Int_t i=0;i<nsclr;i++){
     data=gAnalyzer->GetMidasDAQ()->GetSCLRBankAt(i); 	
     //scaler[i]=(float)(data & 0xffff);
     scaler[i]=(float)(data);
     //printf("scaler nr %d   value %f \n",i,scaler[i]);
   }

   if(nsclr>0){
     for(unsigned int j = 0; j < scaler[0] ; j++) {   
       Gettrigger()->Fill(counterscaler);
     }
     for(unsigned int j = 0; j < scaler[4] ; j++) {   
       Getci()->Fill(counterscaler);
     }
     if(scaler[4]>0){
       for(unsigned int j = 0; j < 100*(scaler[0]/scaler[4]) ; j++) {   
         Gettrigperci()->Fill(counterscaler);
       }
     }
     counterscaler+=1;
     if(counterscaler>3600) counterscaler=0;
   }

   // Fill eventID for all non-scaler events
   // Each RAW event goes to ch 'ev_id_all' in the EventID histogram
   if(nsclr==0){
     GetEventID()->Fill(ev_id_all);  
   }

 

  // to be commented out if not needed so not to fill lots of useless empty histograms
   //----------------------------------------------------------------------
   // look for ADC0 bank 

   float adc[256];
   float caladc[256];
   int adcchan,adcnr;
   Double_t Hagar[16], Plastic[8];
   float Nsides[64],Psides[64];
   Double_t PsidesTDC[64];
   Double_t CalPsidesTDC[64];
   Double_t Pside1TDC[16],Pside2TDC[16],Pside3TDC[16],Pside4TDC[16],HagarTDC[16];
   Double_t Pside1[16],Pside2[16],Pside3[16],Pside4[16],Pside5[16];
   Double_t Nside1[16],Nside2[16],Nside3[16],Nside4[16],Nside5[16];
   Double_t ESi=0.0;	

	Double_t plastic_tdc[4] = {0,0,0,0};

	for(int i=0;i<64;i++)
	{
		Psides[i] = 0;
		Nsides[i] = 0;
	}

   for(int i = 0; i < 16 ; i++) { 
     Pside1[i]=0;
     Pside2[i]=0;
     Pside3[i]=0;
     Pside4[i]=0;
     Pside5[i]=0;
   }
   for(int i = 0; i < 16 ; i++) { 
     Nside1[i]=0;
     Nside2[i]=0;
     Nside3[i]=0;
     Nside4[i]=0;
     Nside5[i]=0;
   }
   for(int i = 0; i < 16 ; i++) { 
     Hagar[i]=0;
     HagarTDC[i]=-10000;
   }
   Int_t PsidePedestal[80]={700,700,700,700,700,700,700,700,700,700,700,700,700,700,700,700, 
   			     700,700,700,300,700,700,700,700,700,700,700,700,700,700,700,700, 
   			     700,700,700,300,700,700,700,700,700,700,700,700,700,700,700,700, 
   			     700,700,700,300,700,700,700,700,700,700,700,700,700,700,700,700,
   			     700,700,700,700,700,700,700,300,700,700,700,700,700,700,700,700};   
   
   //Int_t PsideGain[80]={200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200, 
   	//		 200,200,200,300,200,200,200,200,200,200,200,200,200,200,200,200, 
   	//		 200,200,200,300,200,200,200,200,200,200,200,200,200,200,200,200, 
   	//		 200,200,200,300,200,200,200,200,200,200,200,200,200,200,200,200,
   	//		 200,200,200,200,200,200,200,300,200,200,200,200,200,200,200,200};
   
  // Int_t PsideOffset[80]={200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200, 
   //			   200,200,200,300,200,200,200,200,200,200,200,200,200,200,200,200, 
   //			   200,200,200,300,200,200,200,200,200,200,200,200,200,200,200,200, 
   //			   200,200,200,300,200,200,200,200,200,200,200,200,200,200,200,200,
   //			   200,200,200,200,200,200,200,300,200,200,200,200,200,200,200,200};
   
   Int_t NsidePedestal[80]={700,700,700,700,700,700,700,700,700,700,700,700,700,700,700,700, 
   			     700,700,700,300,700,700,700,700,700,700,700,700,700,700,700,700, 
   			     700,700,700,300,700,700,700,700,700,700,700,700,700,700,700,700, 
   			     700,700,700,300,700,700,700,700,700,700,700,700,700,700,700,700,
   			     700,700,700,700,700,700,700,300,700,700,700,700,700,700,700,700};   

   nadc=gAnalyzer->GetMidasDAQ()->GetADC0BankEntries();
   gAnalyzer->ShowRunStat(true);

   for (int i = 0; i < nadc; i++){
	//adcnr=-1;
	data=gAnalyzer->GetMidasDAQ()->GetADC0BankAt(i);
        if(((data>>24)&0xff) ==0xfd) {
           if((data&0xf) ==0) adcnr=0;
           if((data&0xf) ==1) adcnr=1;
           if((data&0xf) ==2) adcnr=2;
           if((data&0xf) ==3) adcnr=3;
           if((data&0xf) ==4) adcnr=4;
	   if((data&0xf) ==5) adcnr=5;
	   if((data&0xf) ==6) adcnr=6;
	   if((data&0xf) ==7) adcnr=7;
	}

	//if(((data>>24)&0xff) ==0xfd)printf("\n(data&0xf): %d,\t adcnr: %d\n\n",(data&0xf),adcnr);
	if(((data>>24)&0x7) ==0) {     // if not then they are not data but header words.
	   adcchan=((data)>>16)&0x1f;
           adcchan=adcchan + adcnr*32;
      	   adc[adcchan] =(float)(data&0x0fff);
	   caladc[adcchan] = calparadc[adcchan][0] + calparadc[adcchan][1] * adc[adcchan];//removed until the calibration header file is of the right size thingy. THINGY. Bollocks.
		//printf("\n adcnr: %d, adcchan: %d, adc: %f\n\n",adcnr,adcchan,adc[adcchan]);

	   if(adc[adcchan]>200)GetADCHitPattern()->Fill(adcchan);

           if(adcchan<0)printf("Error: adcchan<0, adcchan = %d",adcchan);
           else if(adcchan<32) 
	     {
		GetADC2DModuleAt(0)->Fill(adc[adcchan],adcchan);
		GetCalADC2DModuleAt(0)->Fill(caladc[adcchan],adcchan);
	     }  
           else if(adcchan<64) 
	     {
		GetADC2DModuleAt(1)->Fill(adc[adcchan],adcchan-32);
		GetCalADC2DModuleAt(1)->Fill(caladc[adcchan],adcchan-32);
	     }
           else if(adcchan<96) 
	     {
		GetADC2DModuleAt(2)->Fill(adc[adcchan],adcchan-64);
		GetCalADC2DModuleAt(2)->Fill(caladc[adcchan],adcchan-64);
	     }
           else if(adcchan<128)
	    {
	   	GetADC2DModuleAt(3)->Fill(adc[adcchan],adcchan-96);
		GetCalADC2DModuleAt(3)->Fill(caladc[adcchan],adcchan-96);
	   }
           else if(adcchan<160)
	     {
		GetADC2DModuleAt(4)->Fill(adc[adcchan],adcchan-128);
		GetCalADC2DModuleAt(4)->Fill(caladc[adcchan],adcchan-128);
             }
	   else if(adcchan<192)
	     {
	       GetADC2DModuleAt(5)->Fill(adc[adcchan],adcchan-160);
	       GetCalADC2DModuleAt(5)->Fill(caladc[adcchan],adcchan-160);
	     }
	   else if(adcchan<224)
	     {
	       GetADC2DModuleAt(6)->Fill(adc[adcchan],adcchan-192);
	       GetCalADC2DModuleAt(6)->Fill(caladc[adcchan],adcchan-192);
	     }
	   else if(adcchan<256)
	     {
	       GetCalADC2DModuleAt(7)->Fill(caladc[adcchan],adcchan-224);
	       GetCalADC2DModuleAt(7)->Fill(caladc[adcchan],adcchan-224);
	     }

	}
   }

   //SiliconFBADCHitPattern
   for(int i=0; i < 224; i++)
     {
       for(int j=0; j < 224; j++)
	 {
	   if(adc[i]>500 && adc[j]>500 && i!=j)GetSiFBADCHitPattern()->Fill(i,j);
	 }
     }


   /*for(int i=1;i<8;i++)//ADC module number
     {
       for(int j=0;j<16;j++)
	 {
	   for(int k=16;k<32;k++)
	     {
	       GetSiFBADCAt(i)->Fill(caladc[j+32*i],caladc[k+32*i]);
	     }
	 }
	 }*/

   for(int i=1;i<=5;i++) // Detector number
     {
       int pmin =-1;
       int nmin =-1;

       if  (i==1){ 
	 pmin=0; nmin=80;

       }else if (i==2){ 
	 pmin=16; nmin=88;

       }else if (i==3){ 
	 pmin=32; nmin=104;

       }else if (i==4){ 
	 pmin=48; nmin=96;

       }else if (i==5){ 
	 pmin=64; nmin=112;
       }

       for(int j=pmin;j<pmin+16;j++)
	 {
	   for(int k=nmin;k<nmin+8;k++)
	     {
	       GetSiFBADCAt(i)->Fill(adc[j],adc[k]); 
	     }
	 }
     }

  for(int i = 0; i < 32 ; i++) { 
	if(i<16) {
		GetSiPulseHeightAt(0)->Fill(Pside1[i],i);
		GetSiPulseHeightAt(1)->Fill(Pside2[i],i);
		GetSiPulseHeightAt(2)->Fill(Pside3[i],i);
		GetSiPulseHeightAt(3)->Fill(Pside4[i],i);
		GetSiPulseHeightAt(4)->Fill(Pside5[i],i);
	}
	else{
		GetSiPulseHeightAt(0)->Fill(Nside1[i-16],i);
		GetSiPulseHeightAt(1)->Fill(Nside2[i-16],i);
		GetSiPulseHeightAt(2)->Fill(Nside3[i-16],i);
		GetSiPulseHeightAt(3)->Fill(Nside4[i-16],i);
		GetSiPulseHeightAt(4)->Fill(Nside5[i-16],i);
	}
   }

   for(int i = 0; i < 64 ; i++) { 
	//if(Pside[i]>PsidePedestal[i]) GetPsideHit()->Fill(i);
	if(Psides[i]>200) {
		GetPsideHit()->Fill(i);   // selected 200 as pedestal
		//ESi= ESi + (PsideGain[i]*(adc[i]-PsidePedestal[i]) + PsideOffset[i]);
	}
   }
   ESi=ESi/80;   

   for (int i = 0; i < 64; i++){
	//if(Nside[i]>NsidePedestal[i]) GetNsideHit()->Fill(i);
	if(Nsides[i]>200) GetNsideHit()->Fill(i);  //selected 200 as pedestal
   }  


   for(int i = 0; i < 16 ; i++) { 
	if(Pside1[i]>PsidePedestal[i]) {
		for (int j = 0; j < 16; j++){
			if(Nside1[j]>NsidePedestal[i]) GetPsideNsideAt(0)->Fill(j,i);	
		}
	}
   }
   for(int i = 0; i < 16 ; i++) { 
	if(Pside2[i]>PsidePedestal[i+16]) {
		for (int j = 0; j < 16; j++){
			if(Nside2[j]>NsidePedestal[i+16]) GetPsideNsideAt(1)->Fill(j,i);	
		}
	}
   }
   for(int i = 0; i < 16 ; i++) { 
	if(Pside3[i]>PsidePedestal[i+32]) {
		for (int j = 0; j < 16; j++){
			if(Nside3[j]>NsidePedestal[i+32]) GetPsideNsideAt(2)->Fill(j,i);	
		}
	}
   }
   for(int i = 0; i < 16 ; i++) { 
	if(Pside4[i]>PsidePedestal[i+48]) {
		for (int j = 0; j < 16; j++){
			if(Nside4[j]>NsidePedestal[i+48]) GetPsideNsideAt(3)->Fill(j,i);	
		}
	}
   }

   for(int i=0;i<16;i++){
     if(Psides[i]>200){
       for(int j=16;j<32;j++){
	 if(Psides[j]>200){
	   GetD1D3PsideHitPattern()->Fill(16-i,16-j%16);
	 }
       }
     }
   }


   //----------------------------------------------------------------------
   // look for QDC0 bank 

   float qdc[16];
   float pad1,pad2;
   int qdcchan;

   nqdc=gAnalyzer->GetMidasDAQ()->GetQDC0BankEntries();
   gAnalyzer->ShowRunStat(true);
   //cout << "nqdc : " << nadc << " " << gAnalyzer->GetProgramName() << " " << gAnalyzer->GetEventID() << " " << gAnalyzer->GetProcessedEvents() << " " << gAnalyzer->IsShowRunStat() <<  endl;
   //if (nqdc==0){
   //return 1;
   //}
   for (int i = 0; i < nqdc; i++){
	data=gAnalyzer->GetMidasDAQ()->GetQDC0BankAt(i);
	
       if(((data>>24)&0x7) ==0){         // continue; not data but header words.
	  qdcchan=((data)>>16)&0x1f;              // This is for 32ch v792 qdc
	  //qdcchan=((data)>>17)&0x1f;            // This is for 16ch v792N qdc
	  qdc[qdcchan] = (float)(data&0x0fff);
          //if(qdcchan==0) cout << "qdc["<< qdcchan << "] = " << (float)(data&0x0fff) << "    with i=" << i <<  " 0x" << hex << data << dec << endl;
    	  if(qdcchan<8) GetQDCRawAt(qdcchan)->Fill(qdc[qdcchan]);	
    	  //if(qdcchan>11 && qdcchan<16) GetQDCRawAt(qdcchan-12+4)->Fill(qdc[qdcchan]);	
       }
   }
   pad1=sqrt(qdc[0]*qdc[1]);
   pad2=sqrt(qdc[2]*qdc[3]);

   GetPaddleAveAt(0)->Fill(pad1);
   GetPaddleAveAt(1)->Fill(pad2);
   GetPad1vsPad2()->Fill(pad2,pad1);

   //if(pad1>gates.lowpad1 && pad1<gates.hipad1 && pad2>gates.lowpad2 && pad2<gates.hipad2){   
   //  GetPad1vsPad2Gated()->Fill(pad2,pad1);
   //}

/*
   //----------------------------------------------------------------------
   // look for PR bank 

   npr=gAnalyzer->GetMidasDAQ()->GetPAT0BankEntries();//bk_locate(pevent, "PAT0", &ppr);
   //if (npr==0)  return 1;
   data=gAnalyzer->GetMidasDAQ()->GetPAT0BankAt(0); 	
   
   if( (data & 0xffff ) == 0 ){        
       GetPR()->Fill(19);      
   }
   if( (data & 0x0001 ) == 1 ){        // assuming the PR data word is 16bit word, and is = ppr[0]
       GetPR()->Fill(0);      
   }
   if( (data & 0x0002 ) == 2 ){    
       GetPR()->Fill(1);      
   }
   if( (data & 0x0004 ) == 4 ){    
       GetPR()->Fill(2);      
   }
   if( (data & 0x0008 ) == 8 ){    
       GetPR()->Fill(3);      
   }
*/

   //----------------------------------------------------------------------
   // look for TDC0 bank 

   Int_t tdc1190datacode;

   ntdc = gAnalyzer->GetMidasDAQ()->GetTDC0BankEntries();  //TDC bank in analyzer.c defined as TDC0. ntdc is nr of values in the bank

//   if (ntdc>MAX_WIRES_PER_EVENT) {      // if too many tdc words per event, ignore the event
//	printf("Large nr of TDC datawords. Data ignored:                    %d words\n",ntdc);
//	//return 1;
//   }

   if (ntdc == 0){
      //hEmptyTDCBankRaw->Fill(2);
      GetEventID()->Fill(ev_id_noTDC);             // events with no TDC data
     // return 1;
   }

   ZeroFPWireTimeDist();               // zero the values of the struct X1 X2 U1 U2 
   //memset(reftimes,0,6*sizeof(int));   // reftimes = copies of trigger into each TDC mod,ch0  


   // loop through all the TDC datawords. In offline analysis this is same as "getRefTimes" subroutine
   for(int i=0;i<ntdc;i++){
      data=gAnalyzer->GetMidasDAQ()->GetTDC0BankAt(i);
      if((((data)>>27)&0x1f)==0x1f){     // first determine TDC module nr. This precedes data for each module.
      	tdcmodule=(data)&0xf;
	      continue;                  // go back to beginning of for loop as data is not true.
      }
      if((0x1F&((data)>>27))==0){        // if a valid data word with bits 27-31 = 0
	channel = 0x7F&((data)>>19);
        if(channel==0){                  // looking only at 1st channel of each TDC
	  //cout << " tdc module : " << tdcmodule << endl;
	  //fflush(stdout);
	  //ONLINEDOES NOT LIKE THIS?!?!
	  //if((reftimes[tdcmodule])==0){	         // do this to ensure there is only 1 ref time per event
	    reftimes[tdcmodule]=(data)&0x7FFFF;      //any TDC, ch 0
	  //} 
	 //printf("tdcmodule ntdc chan ref_time %d %d %d %d %d\n",tdcmodule,ntdc,channel,reftimes[tdcmodule],(data)&0x7FFFF);//// error condition
	 //else printf("ERROR found double ref times. %d %d %d\n",tdcmodule,ntdc,channel);//// error condition
	}
      }
   }

   // loop through all the TDC datawords===================================================================================================
   int SiliconTDCChans[256];
   int SiliconTDCVals[256];

   for(int i = 0; i < ntdc; i++) {
      data=gAnalyzer->GetMidasDAQ()->GetTDC0BankAt(i);
      //printf(" Read : 0x%8x\n",data);
      if((((data)>>27)&0x1f)==0x1f){      // to determine TDC module nr. Sean creates in frontend a dataword that
        tdcmodule=(data)&0xf;             // has bits 27-31 =1. Then ch nr goes into bits 1-5.
        continue;                         // go back to beginning of for loop as this word only tells us about module nr
      }                                   // Raw data: 1st word has TDC module nr, then info on that module, then go to 
                                          // the next module. 
      tdc1190datacode = 0x1F&((data)>>27);
      if(tdc1190datacode!=0) continue;    //ignore rest of for loop as we dont have data, but a header/trailer word
      //We have a valid measurent word, so continue
      channel = (0x7F&((data)>>19));                     // Channel is channel per TDC; 0-127
      time = 0x7FFFF&(data);

      ref_time = reftimes[tdcmodule] - time;     // to get accurate time info that does not suffer from trigger jitter
      if(tdcmodule<8){
	      GetTDC2DModuleAt(tdcmodule)->Fill(ref_time,channel);
		if(tdcmodule==0 && channel==9)plastic_tdc[0] = ref_time;
		else if(tdcmodule==0 && channel==10)plastic_tdc[1] = ref_time;
		else if(tdcmodule==0 && channel==11)plastic_tdc[2] = ref_time;
		else if(tdcmodule==0 && channel==12)plastic_tdc[3] = ref_time;


	      //printf("tdcmodule ntdc chan ref_time %d %d %d %d \n",tdcmodule,ntdc,channel,ref_time);//// error condition
	      GetTDCModuleAt(tdcmodule)->Fill(channel);	
	      if(tdcmodule==6){
		if(channel>63 && channel<80){
			Pside1TDC[channel-64]=ref_time;
			//printf("Pside2TDC:   %d  %f  \n",Pside2TDC[channel-64],Pside2[4]);	
		}
		if(channel>79 && channel<96){
			Pside2TDC[channel-80]=ref_time;
		}
		if(channel>95 && channel<112){
			Pside3TDC[channel-96]=ref_time;
		}
		if(channel>111 && channel<128){
			Pside4TDC[channel-112]=ref_time;
		}
	      }
	      if(tdcmodule==7){
		//if(channel>15 && channel<30){
		if(channel==28){ HagarTDC[0]=ref_time;}
		if(channel==23){ HagarTDC[1]=ref_time;}
		SiliconTDCChans[i] = channel;
	     }	

      }
      else cout << "bad tdc module" << tdcmodule << endl;	

      channel = channel+tdcmodule*128;    // now convert channel nr to a nr in the range: 0-(nr_of_tdcs)*128
      
      //if(channel<896) {
      //	GetTDCRawAt(channel)->Fill(time);   // this fills hist for each tdc chan. Thus 896 histos!
      //}
      
      offset_time = ref_time - int(cableOffset[channel]);


      if(channel==TOF_TDC_CHAN1){                             
          GetTOF()->Fill(ref_time);
          tof=ref_time;
	  GetPad1vsTOFAt(0)->Fill(ref_time,pad1);
	  //printf("ref_time: %f \t pad1: %f\n",ref_time,pad1);
	  GetPad2vsTOF()->Fill(ref_time,pad2);
	  if(tof>gates.lowtof && tof<gates.hitof) {
		GetTOFGated()->Fill(ref_time);
	        //printf("TOF %d %d %d %d   %d\n",tdcmodule,channel,time,ref_time,reftimes[tdcmodule] );
                if(pad1>gates.lowpad1 && pad1<gates.hipad1 && pad2>gates.lowpad2 && pad2<gates.hipad2){   
                     GetPad1vsTOFGated()->Fill(ref_time,pad1);
                }
          }
      }
      if(channel==TOF_TDC_CHAN2){                             
	  GetPad1vsTOFAt(1)->Fill(ref_time,pad1);
     }
      if(channel==TOF_TDC_CHAN3){                             
	  GetPad1vsTOFAt(2)->Fill(ref_time,pad1);
      }
      if(channel==TOF_TDC_CHAN4){                             
	  GetPad1vsTOFAt(3)->Fill(ref_time,pad1);
      }
      if(channel==TOF_TDC_CHAN5){                             
	  GetPad1vsTOFAt(4)->Fill(ref_time,pad1);
      }
      if(channel==TOF_TDC_CHAN6){                             
	  GetPad1vsTOFAt(5)->Fill(ref_time,pad1);
      }
      if(channel==TOF_TDC_CHAN7){                             
	  GetPad1vsTOFAt(6)->Fill(ref_time,pad1);
      }

 

      if(channel==9){                             
          pad1hipt=ref_time;
      }
      if(channel==10){                             
          pad1lowpt=ref_time;
      }
      if(channel==11){                             
          pad2hipt=ref_time;
      }
      if(channel==12){                             
          pad2lowpt=ref_time;
      }
      if(channel>894 && channel<896){
 	  Clovertime=ref_time;
      }


      GetPadTimeDiffAt(0)->Fill(pad1hipt,pad1lowpt);
      GetPadTimeDiffAt(1)->Fill(pad2hipt,pad2lowpt);



      // up to this point "channel" is a number from 0-(nr_of_tdcs)*128. E.g for 6 TDCs it is 0-767.
      // And if TOF signal goes to ch 1 of 1st TDC then it is in chan 1.
      // Now we convert these TDC-related channel numbers channel numbers connectedto wireplanes
      // X1 wires 1-198 = channel nrs 10-208
      // U1 wires 1-143 = channel nrs 301-443
      // X2 wires 1-198 = channel nrs 510-708
      // U2 wires 1-143 = channel nrs 801-943
      // Later on these new channel numbers are converted to real wire numbers

	//Enter Phil's attempt to get TDC values for the silicons... abandon all hope ye who enter here...
	//if(channel>=6*128+64 && channel<=7*128)
	//{
	//	PsidesTDC[channel-6*128-64] = ref_time;//FUCK FUCK FUCK FUCK FUUUUCK I was trying to put the PsidesTDC values in STUPID BLOODY PLACES - should now be fixed
	//	CalPsidesTDC[channel-6*128-64] = ref_time - calpartdc[channel-6*128-64]; // Aligned TDC data, hopefully
	//}

      channelnew=Channel2Wire[channel];    // do the translation explained above from ch to wire
      if(channelnew==0) continue;     // all reftimes and TOF were placed in ch 0 in channel2wire conversion. They are not to be plotted.      
      GetHitPatternAt(0)->Fill(channelnew);                                     
      //
      //hDriftTimeAllRef->Fill(ref_time);	

      //if((channelnew >= 8) && (channelnew < 208)){
      if((channelnew >= global.x1_1st_wire_chan) && (channelnew < global.x1_last_wire_chan)){
         GetDriftTimeOffsetAt(0)->Fill(offset_time);	
         wire = channelnew-10 +1;               
         x1_hits++;
      }
      //else if ((channelnew >= 510) && (channelnew < 708) ) {
      else if ((channelnew >= global.x2_1st_wire_chan) && (channelnew < global.x2_last_wire_chan)){
         GetDriftTimeOffsetAt(2)->Fill(offset_time);	
         wire = channelnew-510 +1;               
  	 x2_hits++;
      }  
      //else if ((channelnew >= 301) && (channelnew < 443)) {  		
      else if ((channelnew >= global.u1_1st_wire_chan) && (channelnew < global.u1_last_wire_chan)){
         GetDriftTimeOffsetAt(1)->Fill(offset_time);	
         wire = channelnew-301 +1;               
 	 u1_hits++;
      }        
      //else if ((channelnew >= 801) && (channelnew < 943)) { 		
      else if ((channelnew >= global.u2_1st_wire_chan) && (channelnew < global.u2_last_wire_chan)){
         GetDriftTimeOffsetAt(3)->Fill(offset_time);	
         wire = channelnew-801 +1;               
  	 u2_hits++;
      }

      if( (x1_hits+u1_hits+x2_hits+u2_hits)> MAX_WIRES_PER_EVENT) continue; // typically this happens when preamps latch. Do not continue analysis

      //---------  Now create structs X1,U1,X2,U2  if tof and paddle gates are good  --------
      // in offline code this is done in as part of above structure     

      if(tof>gates.lowtof && tof<gates.hitof &&  pad1>gates.lowpad1 && pad1<gates.hipad1 && pad2>gates.lowpad2 && pad2<gates.hipad2){   
         GetTDCsPerEvent()->Fill(ntdc);   // a diagnostic: how many TDC channels per event for gated events
         GetHitPatternAt(1)->Fill(channelnew);
         if((channelnew >= global.x1_1st_wire_chan) && (channelnew < global.x1_last_wire_chan )){           //X1 wireplane
	   x1_hits_PID++;
	   if((offset_time >= gates.x1_driftt_low) && (offset_time <= gates.x1_driftt_hi)){              
	     X1.wire[x1_hits_dt]=wire;
	     X1.time[x1_hits_dt]=offset_time;
	     x1_hits_dt++;
	     GetHitPatternXAt(0)->Fill(wire);      	   }
	 }
	 else if ((channelnew >= global.u1_1st_wire_chan) && (channelnew < global.u1_last_wire_chan)) {    //U1 wireplane
	   u1_hits_PID++;
	   if((offset_time >= gates.u1_driftt_low) && (offset_time <= gates.u1_driftt_hi)){
	     U1.wire[u1_hits_dt]=wire;
	     U1.time[u1_hits_dt]=offset_time;
	     u1_hits_dt++;
	   }
	 }
	 else if ((channelnew >= global.x2_1st_wire_chan) && (channelnew <global.x2_last_wire_chan)) {   //X2 wireplane
	   x2_hits_PID++;
	   if((offset_time >= gates.x2_driftt_low) && (offset_time <= gates.x2_driftt_hi)){
	     X2.wire[x2_hits_dt]=wire;
	     X2.time[x2_hits_dt]=offset_time;
	     x2_hits_dt++;
	     GetHitPatternXAt(1)->Fill(wire);      
	   }
	 }    
	 else if ((channelnew >= global.u2_1st_wire_chan) && (channelnew <global.u2_last_wire_chan)) {    //U2 wireplane		
	   u2_hits_PID++;
	   if((offset_time >= gates.u2_driftt_low) && (offset_time <= gates.u2_driftt_hi)){
	     U2.wire[u2_hits_dt]=wire;
	     U2.time[u2_hits_dt]=offset_time;
	     u2_hits_dt++;
	   }
	 }      	 	 
      } //end loop for good tof and paddle gates
   }  // end of loop over all the TDC words=======================================================================================


   //if(pad1>100 && pad1< 1000 && pad2>100 && pad2< 1000){   
        //  hTOFGated->Fill(tof);
   //}
   //hTOFvsPad1->Fill(tof,pad1);
   //hTOFvsPad2->Fill(tof,pad2);


   if( (x1_hits+u1_hits+x2_hits+u2_hits)> MAX_WIRES_PER_EVENT)   GetEventID()->Fill(ev_id_latch);  
   // typically this happens when preamps latch. Must get a feeling for how many of these events there are

   //--------------------------------------------------------------------------------------------------------
   // We've gone through all the TDC words associated with this event we obtained data for the 4
   // structures X1,U1,X2 and U2. Now for position and angle determination...
   //--------------------------------------------------------------------------------------------------------

   if(x1_hits!=0) GetEfficiencyIDAt(0)->Fill(ev_all);
   if(u1_hits!=0) GetEfficiencyIDAt(1)->Fill(ev_all);
   if(x2_hits!=0) GetEfficiencyIDAt(2)->Fill(ev_all);
   if(u2_hits!=0) GetEfficiencyIDAt(3)->Fill(ev_all);
   
   //if(tof>gates.lowtof && tof<gates.hitof &&  pad1>gates.lowpad1 && pad1<gates.hipad1 && pad2>gates.lowpad2 && pad2<gates.hipad2) {   
   if(tof>gates.lowtof && tof<gates.hitof &&  pad1>gates.lowpad1 && pad1<gates.hipad1){

      GetEventID()->Fill(ev_id_pid);  // all trigger bank events that pass through PID gates
      if(x1_hits!=0) GetEfficiencyIDAt(0)->Fill(ev_PID);  // all X1 events that pass through PID gates
      if(u1_hits!=0) GetEfficiencyIDAt(1)->Fill(ev_PID);
      if(x2_hits!=0) GetEfficiencyIDAt(2)->Fill(ev_PID);
      if(u2_hits!=0) GetEfficiencyIDAt(3)->Fill(ev_PID);

      if(x1_hits_dt!=0) GetEfficiencyIDAt(0)->Fill(ev_drifttime);
      if(u1_hits_dt!=0) GetEfficiencyIDAt(1)->Fill(ev_drifttime);
      if(x2_hits_dt!=0) GetEfficiencyIDAt(2)->Fill(ev_drifttime);
      if(u2_hits_dt!=0) GetEfficiencyIDAt(3)->Fill(ev_drifttime);

      //trying to establish which chambers fired in coincidence
      if(x1_hits_dt!=0 && u1_hits_dt!=0 && x2_hits_dt!=0 && u2_hits_dt!=0) GetEventID()->Fill(21);// 4 fired (for good PID & dt)
      if(x1_hits_dt!=0 && u1_hits_dt!=0 && x2_hits_dt!=0 ) GetEventID()->Fill(22);                // 3 fired X1 U1 X2 (for good PID & dt)
      if(x1_hits_dt!=0 && u1_hits_dt!=0 && u2_hits_dt!=0 ) GetEventID()->Fill(23);                // 3 fired X1 U1 U2 (for good PID & dt)
      if(x1_hits_dt!=0 && u1_hits_dt!=0 ) GetEventID()->Fill(24);                                  // X1 and U1 (for good PID & dt)
      if(x2_hits_dt!=0 && u2_hits_dt!=0 ) GetEventID()->Fill(25);                                  // X2 and U2 (for good PID & dt)
      if(x1_hits_dt!=0 && x2_hits_dt!=0 ) GetEventID()->Fill(26);                                  // X1 and X2 (for good PID & dt)
      if(u1_hits_dt!=0 && u2_hits_dt!=0 ) GetEventID()->Fill(27);                                  // U1 and U2 (for good PID & dt)

      //Bubble sort so that order of wireplane.wire[] is from lowest wire to highest wire. 
      //It makes things easier if the arrays are ordered.
      sortTDCs(x1_hits_dt, X1.wire, X1.time);
      sortTDCs(x2_hits_dt, X2.wire, X2.time);
      sortTDCs(u1_hits_dt, U1.wire, U1.time);
      sortTDCs(u2_hits_dt, U2.wire, U2.time);

      Int_t wrangeX1 = 1 + X1.wire[x1_hits_dt-1]-X1.wire[0];  // wire range 
      Int_t wrangeX2 = 1 + X2.wire[x2_hits_dt-1]-X2.wire[0];
      Int_t wrangeU1 = 1 + U1.wire[u1_hits_dt-1]-U1.wire[0];
      Int_t wrangeU2 = 1 + U2.wire[u2_hits_dt-1]-U2.wire[0];

      //Driftlength spectra fill
      for(int i = 0; i < x1_hits_dt ; i++) { 
         drifttime=X1.time[i];
         X1.dist[i]=lutx1[drifttime]*DRIFTLENGTH;     //X1.dist is driftlength in actual mm
         GetDriftLengthAt(0)->Fill(X1.dist[i]);
      }
      for(int i = 0; i < u1_hits_dt ; i++) { 
         drifttime=U1.time[i];
         U1.dist[i]=lutu1[drifttime]*DRIFTLENGTH;
         GetDriftLengthAt(1)->Fill(U1.dist[i]);
      }
      for(int i = 0; i < x2_hits_dt ; i++) { 
         drifttime=X2.time[i];
         X2.dist[i]=lutx2[drifttime]*DRIFTLENGTH;
         GetDriftLengthAt(2)->Fill(X2.dist[i]);
      }
      for(int i = 0; i < u2_hits_dt ; i++) { 
         drifttime=U2.time[i];
         U2.dist[i]=lutu2[drifttime]*DRIFTLENGTH;
         GetDriftLengthAt(3)->Fill(U2.dist[i]);
      }

      //Gates on number of wires, number of missing wires etc
      if(x1_hits_PID!=0) GetEventID()->Fill(ev_id_X1_PID);
      if(x1_hits_dt>=global.min_x_wires &&  x1_hits_dt<global.max_x_wires) {
	  GetEfficiencyIDAt(0)->Fill(ev_wiresperevent);
	  //if(global.misswires>(wrangeX1-x1_hits_dt)){     
	  if(int(global.misswires)>(wrangeX1-x1_hits_dt)){      // rn13may11
	    GetEfficiencyIDAt(0)->Fill(ev_wiregap);
	    GetEventID()->Fill(ev_id_X1_wires);  // events in X1 that pass through wire requirement gates 

	    raytrace(X1.dist, X1.wire, &X1pos, &ThX1, &chisq_X1, x1_hits_dt, resolution, &flagX1); 
	    if (flagX1==1){
	      GetEfficiencyIDAt(0)->Fill(ev_multiplemin);
	    }
	    else if(flagX1!=1){	  
	      for(int i = 0; i < x1_hits_dt ; i++) { 
                GetDriftTimeOffsetGoodAt(0)->Fill(X1.time[i]);	
              }
	      GetEfficiencyIDAt(0)->Fill(ev_good);
	      GetEventID()->Fill(ev_id_X1_good);  // good X1 events
	      //if(chisq_X1<0.2) GetPositionAt(0)->Fill(X1pos);
	      GetPositionAt(0)->Fill(X1pos);
   	      GetAngleAt(0)->Fill(ThX1);
	      GetHitsPerEventAt(0)->Fill(x1_hits_dt); 
	      GetTOFvsX1()->Fill(X1pos,tof);
	      GetRes2DAt(0)->Fill(resolution[0],resolution[1]);

              GetPosVsPadTimeDiffAt(0)->Fill(X1pos,pad1hipt-pad1lowpt);
              GetPosVsPadTimeDiffAt(1)->Fill(X1pos,pad2hipt-pad2lowpt);
	      GetPad1HivsX()->Fill(X1pos,qdc[0]);
	      GetPad1LowvsX()->Fill(X1pos,qdc[1]);
	      GetPad2HivsX()->Fill(X1pos,qdc[2]);
	      GetPad2LowvsX()->Fill(X1pos,qdc[3]);

	      GetPad1vsX()->Fill(X1pos,pad1);
	      GetPad2vsX()->Fill(X1pos,pad2);

	    }
	 }
      }   

      if(u1_hits_PID!=0) GetEventID()->Fill(ev_id_U1_PID);
      if(u1_hits_dt>=global.min_u_wires  &&  u1_hits_dt<global.max_u_wires) {
	 GetEfficiencyIDAt(1)->Fill(ev_wiresperevent);
	 //if(global.misswires>(wrangeU1-u1_hits_dt)){
	 if(int(global.misswires)>(wrangeU1-u1_hits_dt)){  	// rn13may11
	    GetEfficiencyIDAt(1)->Fill(ev_wiregap);
	    GetEventID()->Fill(ev_id_U1_wires);  // events in U1 that pass through the wire requirement gates 
	    raytrace(U1.dist, U1.wire, &U1pos, &ThU1, &chisq_U1, u1_hits_dt, resolution, &flagU1); 
	    //U1pos=U1pos/sin(U_WIRE_ANGLE/57.2957);   // since wires at 50degr to horizontal, they are 1/sin(50degr) further apart in x
	    if (flagU1==1){
//	      hU1_pos_flag1->Fill(U1pos);
	    }
	    else if(flagU1!=1){
	      for(int i = 0; i < u1_hits_dt ; i++) { 
                GetDriftTimeOffsetGoodAt(1)->Fill(U1.time[i]);	
              }
	      GetEfficiencyIDAt(1)->Fill(ev_good);
	      GetEventID()->Fill(ev_id_U1_good);  // good U1 events 
	      GetPositionAt(1)->Fill(U1pos);
	      GetAngleAt(1)->Fill(ThU1);
	      GetHitsPerEventAt(1)->Fill(u1_hits_dt); 
	      GetRes2DAt(1)->Fill(resolution[0],resolution[1]);
	    }
	 }
      }   

      if(x2_hits_PID!=0) GetEventID()->Fill(ev_id_X2_PID);
      if(x2_hits_dt>=global.min_x_wires  &&  x2_hits_dt<global.max_x_wires) {
	 GetEfficiencyIDAt(2)->Fill(ev_wiresperevent);
	 //if(global.misswires>(wrangeX2-x2_hits_dt)){
	 if(int(global.misswires)>(wrangeX2-x2_hits_dt)){  	// rn13may11
	    GetEfficiencyIDAt(2)->Fill(ev_wiregap);
	    GetEventID()->Fill(ev_id_X2_wires);  // events in X2 that pass through wire requirement gates 
	    raytrace(X2.dist, X2.wire, &X2pos, &ThX2, &chisq_X2, x2_hits_dt, resolution, &flagX2); 
	    if (flagX2==1){
//	      hX2_pos_flag1->Fill(X2pos);
	    }
	    else if(flagX2!=1){
	      for(int i = 0; i < x2_hits_dt ; i++) { 
                GetDriftTimeOffsetGoodAt(2)->Fill(X2.time[i]);	
              }
	      GetEfficiencyIDAt(2)->Fill(ev_good);
	      GetEventID()->Fill(ev_id_X2_good);  // good X2 events 
	      GetPositionAt(2)->Fill(X2pos);
	      GetAngleAt(2)->Fill(ThX2);
	      GetHitsPerEventAt(2)->Fill(x2_hits_dt); 
	      GetTOFvsX2()->Fill(X2pos,tof);
	      GetRes2DAt(2)->Fill(resolution[0],resolution[1]);
	    }
	 }
      }
      if(u2_hits_PID!=0) GetEventID()->Fill(ev_id_U2_PID);
      if(u2_hits_dt>=global.min_u_wires  &&  u2_hits_dt<global.max_u_wires) {
	 GetEfficiencyIDAt(3)->Fill(ev_wiresperevent);
	 //if(global.misswires>(wrangeU2-u2_hits_dt)){ 
	 if(int(global.misswires)>(wrangeU2-u2_hits_dt)){  	// rn13may11
	    GetEfficiencyIDAt(3)->Fill(ev_wiregap);
	    GetEventID()->Fill(ev_id_U2_wires);  // events in U1 that pass through the wire requirement gates 
	    raytrace(U2.dist, U2.wire, &U2pos, &ThU2, &chisq_U2, u2_hits_dt, resolution, &flagU2); 
	    //U2pos=U2pos/sin(U_WIRE_ANGLE/57.2957);   // since wires at 50degr to horizontal, they are 1/sin(50degr) further apart in x
	    if (flagU2==1){
	     // hU2_pos_flag1->Fill(U2pos);
	    }
	    else if(flagU2!=1){
	      for(int i = 0; i < u2_hits_dt ; i++) { 
                GetDriftTimeOffsetGoodAt(3)->Fill(U2.time[i]);	
              }
	      GetEfficiencyIDAt(3)->Fill(ev_good);
	      GetEventID()->Fill(ev_id_U2_good);  // good U2 events 	 
	      GetPositionAt(3)->Fill(U2pos);
	      GetAngleAt(3)->Fill(ThU2);
	      GetHitsPerEventAt(3)->Fill(u2_hits_dt); 
	      //delta=resolution[0]-resolution[1];
	      GetRes2DAt(3)->Fill(resolution[0],resolution[1]);
	    }
         }
      }

      // Now calculate and fill spectra for calculated angles using 2 driftchambers, and calculate Ypos
      if(flagX1==0 && flagX2==0){
	CalcThetaFP(X1pos,X2pos,&ThFP);  
        //rn17dec2011   if(ThFP>32. && ThFP<33.)  GetPositionGated()->Fill(X1pos);   
	if(ThFP>gates.thetafp_lo && ThFP<gates.thetafp_hi) GetPositionThetaGate()->Fill(X1pos); 
	if(chisq_X1<0.2) GetThFPvsX1()->Fill(X1pos,ThFP);
	GetThFPvsX2()->Fill(X2pos,ThFP);

        CalcThetaScat(ThFP,X1pos,&ThSCAT);
        GetThSCATvsX1()->Fill(X1pos,ThSCAT);
        GetThSCATvsX2()->Fill(X2pos,ThSCAT);
        //GetPositionGated()->Fill(X1pos+0.9*ThSCAT-0.4*ThSCAT^2);
      }

      if(flagX1==0 && flagU1==0){
        CalcYFP(X1pos,U1pos,ThX1,&Y1);  
        //if(ThFP>40. && ThFP<42.)  GetPositionGated()->Fill(X1pos);
        //GetPositionGated()->Fill(X1pos+0.9*ThSCAT);
        GetY1()->Fill(Y1);
        GetX1Y1()->Fill(X1pos,Y1);
      }

      //      if(flagX2==0 && flagX1==0 && flagU2==0){
      if(flagX2==0 && flagX1==0) {
	CalcYFP(X2pos,U2pos,ThFP,&Y2);  
        GetY2()->Fill(Y2);
        if(chisq_X1<0.2) GetX2Y2()->Fill(X1pos,Y2);
        //if (Y2>gates.y_lo && Y2<gates.y_hi){
	  //if(chisq_X1<0.2) 
	  GetPositionYGate()->Fill(X1pos-0.03*Y1); 

        //}
      }

      //      if(flagX1==0 && flagU1==0 && flagX2==0 && flagU2==0){
      if(flagX1==0 && flagU1==0 && flagX2==0) {
	GetY1vsThFP()->Fill(ThFP,Y1);
        CalcPhiFP(X1pos,Y1,X2pos,Y2,ThFP,&PhiFP);
      }

      // Calculate and plot wirechamber efficiencies
      Double_t effX1=0,effU1=0,effX2=0,effU2=0;
      if( GetEventID()->GetBinContent(ev_id_X1_PID+1) !=0) {
	effX1=100.*float(GetEventID()->GetBinContent(ev_id_X1_good+1)) / float(GetEventID()->GetBinContent(ev_id_X1_PID+1));
	GetEfficiencyAt(0)->Fill(effX1);
      }
      if( GetEventID()->GetBinContent(ev_id_U1_PID+1) !=0) {
	effU1=100.*float(GetEventID()->GetBinContent(ev_id_U1_good+1)) / float(GetEventID()->GetBinContent(ev_id_U1_PID+1));
	GetEfficiencyAt(1)->Fill(effU1);
      }
      if( GetEventID()->GetBinContent(ev_id_X2_PID+1) !=0) {
					//0->15 is detector 1 fronts, 0->8 is detector 1 backs
					//if((i-i%16)/16 == (k-k%8)/8)//Is the front channel in the same detector as the back detector?? <- Taken out of the moment due to my uncertainty about the Caen amps and how the channel numbers are working
	effX2=100.*float(GetEventID()->GetBinContent(ev_id_X2_good+1)) / float(GetEventID()->GetBinContent(ev_id_X2_PID+1));
	GetEfficiencyAt(2)->Fill(effX2);
      }
      if( GetEventID()->GetBinContent(ev_id_U2_PID+1) !=0) {
	effU2=100.*float(GetEventID()->GetBinContent(ev_id_U2_good+1)) / float(GetEventID()->GetBinContent(ev_id_U2_PID+1));
	GetEfficiencyAt(3)->Fill(effU2);
      }

      for(int i=0;i<160;i++)//Fill adc vs fp position histograms
	{
	  //if(adc[i]>250)GetK600vsSiChannelAt(i)->Fill(X1pos,adc[i]);
	  //if(adc[i]>250)GetK600vsCalSiChannelAt(i)->Fill(X1pos,caladc[i]);
	  if(adc[i]>250)GetK600vsCalSi()->Fill(X1pos,caladc[i]);
	  if(adc[i]>250)GetK600vsSi()->Fill(X1pos,adc[i]);
	  if(CalPsidesTDC[i] - tof >= -1000 && CalPsidesTDC[i] - tof <= 300)
	  {
	    GetK600vsCalSiGated()->Fill(X1pos, caladc[i]);
	  }
	  //	  int DetectorNumber = (i-i%32)/32;
	  int DetectorNumber;
	  if  (i>=0  && i<16 ) 
	    { 
	      DetectorNumber = 1;  // p
	    }
	  else if (i>=80 && i<88)
	    {
	      DetectorNumber = 1; // n
	    }
	  else if (i>=16  && i<32 )
	    {
	      DetectorNumber = 2; // p
	    }
	  else if (i>=88   && i<96 )
	    {
	      DetectorNumber = 2; // n
	    }
	  else if (i>=32  && i<48 )
	    {
	      DetectorNumber = 3; // p
	    }
	  else if (i>=96  && i<104 )
	    {
	      DetectorNumber = 3; // n
	    }
	  else if (i>=48 && i<64)
	    {
	      DetectorNumber = 4; // p
	    }
	  else if (i>=104  && i<112 )
	    {
	      DetectorNumber = 4; // n
	    }
	  else if (i>=64 && i<80)
	    {
	      DetectorNumber = 5; // p
	    }
	  else if (i>=112  && i<120)
	    {
	      DetectorNumber = 5; // n
	    }


	  if(adc[i]>250)GetK600vsCalSiDetectorAt(DetectorNumber)->Fill(X1pos,caladc[i]);
	  if(adc[i]>250)GetK600vsSiDetectorAt(DetectorNumber)->Fill(X1pos,adc[i]);
	}
      
/*
      for(int i=128; i<128+16;i++)
	{
	  if(i%2==0)GetK600vsHAGARAt(i-128)->Fill(X1pos,adc[i]);
	  //if(i%2==0)GetK600vsHAGARAt(i)->Fill(X1pos,adc[i]);
	}
*/
      if(adc[0]>100 && HagarTDC[0]>3500 && HagarTDC[0]<5000) GetK600vsHAGARAt(0)->Fill(X1pos,adc[0]);
      if(adc[2]>100 && HagarTDC[1]>3500 && HagarTDC[1]<5000) GetK600vsHAGARAt(1)->Fill(X1pos,adc[2]);
      if(adc[4]>100)GetK600vsHAGARAt(2)->Fill(X1pos,adc[4]);
      if(adc[6]>100)GetK600vsHAGARAt(3)->Fill(X1pos,adc[6]);



     /* 
      if(adc[0]>250)GetK600vsLEPSAt(0)->Fill(X1pos,adc[0]);
      if(adc[1]>250)GetK600vsLEPSAt(1)->Fill(X1pos,adc[1]);
      if(adc[2]>250)GetK600vsLEPSAt(2)->Fill(X1pos,adc[2]);
      if(adc[3]>250)GetK600vsLEPSAt(3)->Fill(X1pos,adc[3]);

      if(adc[12]>250)GetK600vsLEPSAt(4)->Fill(X1pos,adc[12]);
      if(adc[13]>250)GetK600vsLEPSAt(5)->Fill(X1pos,adc[13]);
      if(adc[14]>250)GetK600vsLEPSAt(6)->Fill(X1pos,adc[14]);
      if(adc[15]>250)GetK600vsLEPSAt(7)->Fill(X1pos,adc[15]);
		      
      if(adc[16]>250)GetK600vsLEPSAt(8)->Fill(X1pos,adc[16]);
      if(adc[17]>250)GetK600vsLEPSAt(9)->Fill(X1pos,adc[17]);
      if(adc[18]>250)GetK600vsLEPSAt(10)->Fill(X1pos,adc[18]);
      if(adc[19]>250)GetK600vsLEPSAt(11)->Fill(X1pos,adc[19]);

      if(adc[28]>250)GetK600vsLEPSAt(12)->Fill(X1pos,adc[28]);
      if(adc[29]>250)GetK600vsLEPSAt(13)->Fill(X1pos,adc[29]);
      if(adc[30]>250)GetK600vsLEPSAt(14)->Fill(X1pos,adc[30]);
      if(adc[31]>250)GetK600vsLEPSAt(15)->Fill(X1pos,adc[31]);
     */
      /*
      if(adc[0]>250) {
	GetK600vsLEPSCalibratedAt(0)->Fill(X1pos,-17.1835741083+0.0995079786*adc[0]);
	GetK600vsLEPSCalibratedTot()->Fill(X1pos,-17.1835741083+0.0995079786*adc[0]);
	}	
      if(adc[1]>250) {
	GetK600vsLEPSCalibratedAt(1)->Fill(X1pos,-19.5984995881+0.1014414989*adc[1]);
	GetK600vsLEPSCalibratedTot()->Fill(X1pos,-19.5984995881+0.1014414989*adc[1]);
	}
      if(adc[2]>250) {
	GetK600vsLEPSCalibratedAt(2)->Fill(X1pos,-16.4473945332+0.0984703118*adc[2]);
	GetK600vsLEPSCalibratedTot()->Fill(X1pos,-16.4473945332+0.0984703118*adc[2]);
	}
      if(adc[3]>250) {
	GetK600vsLEPSCalibratedAt(3)->Fill(X1pos,-17.9220124325+0.1004224347*adc[3]);
	GetK600vsLEPSCalibratedTot()->Fill(X1pos,-17.9220124325+0.1004224347*adc[3]);
	}

      if(adc[12]>250) {
	GetK600vsLEPSCalibratedAt(4)->Fill(X1pos,-19.1664888293+0.0997713652*adc[12]);
	GetK600vsLEPSCalibratedTot()->Fill(X1pos,-19.1664888293+0.0997713652*adc[12]);
	}
      if(adc[13]>250) {
	GetK600vsLEPSCalibratedAt(5)->Fill(X1pos,-19.7972840996+0.1044783694*adc[13]);
	GetK600vsLEPSCalibratedTot()->Fill(X1pos,-19.7972840996+0.1044783694*adc[13]);
	}
      if(adc[14]>250) {
	GetK600vsLEPSCalibratedAt(6)->Fill(X1pos,-16.9632349285+0.0968403948*adc[14]);
	GetK600vsLEPSCalibratedTot()->Fill(X1pos,-16.9632349285+0.0968403948*adc[14]);
	}
      if(adc[15]>250) {
	GetK600vsLEPSCalibratedAt(7)->Fill(X1pos,-19.1664888293+0.0997713652*adc[15]);
	GetK600vsLEPSCalibratedTot()->Fill(X1pos,-19.1664888293+0.0997713652*adc[15]);
	}		      
      if(adc[16]>250) {
	GetK600vsLEPSCalibratedAt(8)->Fill(X1pos,-15.76864159+0.1009852432*adc[16]);
	GetK600vsLEPSCalibratedTot()->Fill(X1pos,-15.76864159+0.1009852432*adc[16]);
	}
      if(adc[17]>250) {
	GetK600vsLEPSCalibratedAt(9)->Fill(X1pos,-18.0214976818+0.1009509375*adc[17]);
	GetK600vsLEPSCalibratedTot()->Fill(X1pos,-18.0214976818+0.1009509375*adc[17]);
	}
      if(adc[18]>250){
	GetK600vsLEPSCalibratedAt(10)->Fill(X1pos,-19.2564401137+0.1064002936*adc[18]);
	GetK600vsLEPSCalibratedTot()->Fill(X1pos,-19.2564401137+0.1064002936*adc[18]);
	}
      if(adc[19]>250){
	GetK600vsLEPSCalibratedAt(11)->Fill(X1pos,-19.1550326737+0.1047613012*adc[19]);
	GetK600vsLEPSCalibratedTot()->Fill(X1pos,-19.1550326737+0.1047613012*adc[19]);
	}

      if(adc[28]>250){
	GetK600vsLEPSCalibratedAt(12)->Fill(X1pos,-18.569444201+0.1047918204*adc[28]);
	GetK600vsLEPSCalibratedTot()->Fill(X1pos,-18.569444201+0.1047918204*adc[28]);
	}
      if(adc[29]>250){
	GetK600vsLEPSCalibratedAt(13)->Fill(X1pos,-17.99320657+0.1024982737*adc[29]);
	GetK600vsLEPSCalibratedTot()->Fill(X1pos,-17.99320657+0.1024982737*adc[29]);
	}
      if(adc[30]>250){
	GetK600vsLEPSCalibratedAt(14)->Fill(X1pos,-17.8112542248+0.1058704057*adc[30]);
	GetK600vsLEPSCalibratedTot()->Fill(X1pos,-17.8112542248+0.1058704057*adc[30]);
	}
      if(adc[31]>250){
	GetK600vsLEPSCalibratedAt(15)->Fill(X1pos,-18.569444201+0.1047918204*adc[31]);
	GetK600vsLEPSCalibratedTot()->Fill(X1pos,-18.569444201+0.1047918204*adc[31]);
	}
      */
   }  //end of PID loop



#ifdef notdebug
#endif
//return 0;
 
}


//______________________________________________________________________________
void K600TAnalyseFolders::EndOfRun()
{
}


//______________________________________________________________________________
void K600TAnalyseFolders::Terminate()
{
}


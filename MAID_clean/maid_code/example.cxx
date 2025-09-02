#include "maidxs.h"

void example(){
	
	double Q2 = 0.35; //GeV^2
	double W = 1.232; //GeV
	double EI = 4.46; //GeV, Beam energy in the lab frame
	double EF = 4.03; //GeV, scattered electron energy in the lab frame
	double tht = 60.0*TMath::DegToRad(); //Radians,  Theta in the center-of-mass frame (PION if channel 1, NEUTRON if channel 3)
	double pht = 0.0; //Radians, Phi in the center-of-mass frame (PION if channel 1, NEUTRON if channel 3)
	double mt = 938.272; // MeV,  Mass of the target particle (proton or neutron)
	int channel = 1; //  1 - pi0 p; 2 - pi0 n; 3 - pi+ n; 4 - pi- p'


	double siglab = maidxs(Q2,W,EI,EF,tht,pht,mt,channel);

	cout << "cross-section in the lab is: " << siglab <<  " ub/MeV/sr^2 " << endl;
}
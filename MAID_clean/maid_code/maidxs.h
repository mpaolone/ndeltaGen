R__LOAD_LIBRARY(libmaid);

// MeV^2, MeV, MeV, MeV, rad, rad, ub/MeV/sr^2, ub/sr,  Channel is:
//  1 - pi0 p; 2 - pi0 n; 3 - pi+ n; 4 - pi- p'

extern "C"{
 void get_xn_maid_07_(double *Q2,double *W, double *EI, double *EF, double *tht, double *pht, double *siglab,double *sigcm, int *channel);
}

//Calculates the virtual photon flux via the hand formalism.
double flux(double EI, double EF, double Q2, double W, double mt){
	double nu=  EI - EF;
	double S2 = Q2/EI/EF/4.0;
	double T2 = S2/(1.0 - S2);

	double eps= 1./(1.+2.*(1+nu*nu/Q2)*T2);

	double K_gamma_lab = (W*W -mt*mt)/2./mt;
	double PI = TMath::Pi();
	return 7.297353080E-3/2./PI/PI*EF/EI*K_gamma_lab/Q2/(1.-eps);
}


//Q2, W, EI, and EF are all in GeV.  tht and pht are in radians. mt is the mass of the target particle in MeV
//channel is the relevant channel, see the comments above.
//SOME IMPORTANT NOTES:  If the channel is 1, then "tht" is the center of mass theta for the PION.  If the channel is 3, then tht is the angle for the NEUTRON.  pht is the center of mass phi angle for the same particle.
double maidxs(double Q2,double W, double EI, double EF, double tht, double pht, double mt, int channel){
	Q2 = Q2*1000.0*1000.0;
	W = W*1000.0;
	EI = EI*1000.0;
	EF = EF*1000.0;
	double siglab;
	double sigcm;
	
	int nfitpts = 10;
	float fitQ2step = 0.1*1000.0*1000.0;
	
	double lQ2, lEF, lEI, p1, p2, extxs;
	
	//if the Q2 is less than 5.0 GeV^2, then we can get the cross-section directly
	if(Q2 < 5.0*1000.0*1000.0){
		get_xn_maid_07_(&Q2, &W, &EI, &EF, &tht, &pht, &siglab, &sigcm, &channel);
		return siglab;
	}else{
		//otherwise, we need to extrapolate in Q2:
		vector<double> Q2v;
		vector<double> xsv;
		vector<double> EIv;
		vector<double> EFv;
		for(int i = 0; i < nfitpts; i++){
			double lsiglab;
			lQ2 = 4.99*1000.0*1000.0 - float(i)*fitQ2step; //start at just below 5.0 GeV^2
			Q2v.push_back(lQ2);
			//we will keep W and theta constant, so in this case we scale back the beam energy and scattered electron momentum to give us the new Q2
			p1 = (lQ2 + W*W - mt*mt)/(2.*mt);
			p2 = Q2/4.0/EF/EI;
			lEF = (sqrt(p1*p1 + lQ2/p2) - p1)/2.0;
			lEI = p1 + lEF;
			EIv.push_back(lEI/1000.0);
			EFv.push_back(lEF/1000.0);
			
			get_xn_maid_07_(&lQ2, &W, &lEI, &lEF, &tht, &pht, &lsiglab, &sigcm, &channel);
			xsv.push_back(lsiglab/flux(lEI,lEF,lQ2,W,mt));
		}
		TGraph gr(nfitpts, &Q2v[0], &xsv[0]);
		TF1 f1("f1","expo");
		//the distribution follows an exponential fairly closely, so we just need to give it some initial parameters to get started
		f1.SetParameters(-3.5, -1.2e-6);
		gr.Fit(&f1,"Q");
		//NOTE:  We should put in a Chi2 check to ensure the fit is "good".  
		extxs = f1.Eval(Q2)*flux(EI,EF,Q2,W,mt);
		return extxs;
	}
	
}
//#include "Lresolution.h"
//#include "SoLID_res.h"

float calc_eps(float Q2, float W, float Ebeam = 11.0){
        double mp = 0.938272;
        double nu = (W*W + Q2 - mp*mp)/2./mp;
        double ep = Ebeam - nu;
        double S2T = Q2/4./Ebeam/ep;
        double T2T = 1./(1. - S2T) - 1.;
        return  1./(1. + 2.*(nu*nu + Q2)*T2T/Q2);
};


void plots(int option){
	
	//Lresolution Lres("SIDIS_He3");
	
	int channel = 2; //1 = p, 2 = n
	
	if(option == 0 || option == 2){
		channel = 1;
	}
	if(option == 1 || option == 3){
		channel = 2;
	}
	
	double  run_current             =       3E-6                    ;
	double  run_time                =       1                               ;
	double  run_charge              =       run_current * run_time  ;
	double  e_charge                =       1.60217733E-19  ;
	double  NA                              =       6.0221367E23    ;
	double  targ_density    =       0.07085                ; //g/cm3
	double  targ_mass_num   =       1                               ;
	double  targ_length             =       15                              ;
	
	double cmToGeV = 5.06e13;
	double cm2Toubarns = 1e30;
	
	double  Lum     =       run_charge * NA * targ_density * run_time * targ_length       /       (e_charge*targ_mass_num); 
	cout << Lum << "  1/cm-2" << endl;
	Lum *= 1./cm2Toubarns;
	
	TChain T("T");
	//TChain sm_solid_tree("sm_solid_tree");
	
	double eth_min, eth_max;
	double pth_min, pth_max;
	double pp_min, pp_max;
	double ep_min, ep_max;
	double Q2_min, Q2_max;
	
	double pthcm_min, pthcm_max;
	double pphcm_min, pphcm_max;
	
	double MM_min, MM_max;
	
	double detmass;
	
	T.Add(Form("out_%d.root",option));
	
	double beamE = 11.0;
	
	float mt;
	
	vector<float> Q2v;
	
	if(option == 0){
		
		//sm_solid_tree.Add("rootFiles/T1_n_solidscat_working.root");
		Q2_min = 5.0;
		Q2_max = 6.0;
		eth_min = 13.8;
		eth_max = 15.4;
		pth_min = 23;
		pth_max = 25.5;
		pp_min = 2.0;
		pp_max = 4.0;
		ep_min = 7.5;
		ep_max = 8.0;
		pthcm_min = 55;
		pthcm_max = 150;
		pphcm_min = 140;
		pphcm_max = 220;
		MM_min = -10.0;
		MM_max = 10.0;
		detmass = 0.938272;
		mt = 0.938272;
		Q2v.push_back(5.1);
		Q2v.push_back(5.3);
		Q2v.push_back(5.5);
		Q2v.push_back(5.7);
		channel = 1;
		//detmass = 0.135;
	}else if(option == 1){
		//solid_tree.Add("rootFiles/T1_n_solidscat_working.root");
		//sm_solid_tree.Add("rootFiles/T1_n_solidscat_working.root");
		Q2_min = 2.0;
		Q2_max = 6.0;
		ep_min = 7.5;
		ep_max = 10.0;
		eth_min = 7.5;
		eth_max = 15.5;
		pp_min = 0.0;
		pp_max = 1.0;
		pth_min = 7.5;
		pth_max = 15.5;
		pthcm_min = 80;
		pthcm_max = 180;
		pphcm_min = 140;
		pphcm_max = 220;
		MM_min = 0.8;
		MM_max = 1.1;
		MM_min = 0.85;
		MM_max = 0.95;
		detmass = 0.135;
		mt = 0.938272;
		Q2v.push_back(2.25);
		Q2v.push_back(2.75);
		Q2v.push_back(3.25);
		Q2v.push_back(3.75);
		Q2v.push_back(4.25);
		Q2v.push_back(4.75);
		Q2v.push_back(5.1);
		Q2v.push_back(5.3);
		Q2v.push_back(5.5);
		Q2v.push_back(5.7);
		channel = 2;
	
	}else if(option == 2){
		//solid_tree.Add("rootFiles/T1_n_solidscat_working.root");
		//sm_solid_tree.Add("rootFiles/T1_n_solidscat_working.root");
		Q2_min = 5.5;
		Q2_max = 11.0;
		ep_min = 5.0;
		ep_max = 8.0;
		eth_min = 14.0;
		eth_max = 26.0;
		pp_min = 2.0;
		pp_max = 7.0;
		pth_min = 16.0;
		pth_max = 25.5;
		pthcm_min = 0;
		pthcm_max = 180;
		pphcm_min = 0;
		pphcm_max = 360;
		MM_min = -0.2;
		MM_max = 0.4;
		mt = 0.938272;
		//MM_min = 0.85;
		//MM_max = 0.95;
		detmass = 0.938272;
		
		Q2v.push_back(5.75);
		Q2v.push_back(6.25);
		Q2v.push_back(6.75);
		Q2v.push_back(7.25);
		Q2v.push_back(7.75);
		Q2v.push_back(8.25);
		Q2v.push_back(8.75);
		Q2v.push_back(9.25);
		Q2v.push_back(9.75);
		Q2v.push_back(10.25);
		channel = 1;
		
		
	}else if(option == 3){
		//solid_tree.Add("rootFiles/T1_n_solidscat_working.root");
		//sm_solid_tree.Add("rootFiles/T1_n_solidscat_working.root");
		Q2_min = 5.0;
		Q2_max = 11.0;
		ep_min = 5.0;
		ep_max = 8.0;
		eth_min = 14.0;
		eth_max = 25.5;
		pp_min = 0.0;
		pp_max = 1.5;
		pth_min = 7.5;
		pth_max = 15.5;
		pthcm_min = 40;
		pthcm_max = 180;
		pphcm_min = 100;
		pphcm_max = 250;
		//MM_min = 0.8;
		//MM_max = 1.1;
		MM_min = 0.85;
		MM_max = 0.95;
		detmass = 0.135;
		mt = 0.938272;
		
		Q2v.push_back(5.75);
		Q2v.push_back(6.25);
		Q2v.push_back(6.75);
		Q2v.push_back(7.25);
		Q2v.push_back(7.75);
		Q2v.push_back(8.25);
		Q2v.push_back(8.75);
		Q2v.push_back(9.25);
		Q2v.push_back(9.75);
		Q2v.push_back(10.25);
		
		channel = 2;
	
	}
	
	TH1F *hQ2b = new TH1F("hQ2b","",(int)Q2v.size() -1, &Q2v[0]);
	
	
	
	
	TH1F *heth = new TH1F("heth","",100, eth_min,eth_max);
	TH1F *hpth = new TH1F("hpth","",100, pth_min,pth_max);
	
	TH1F *hep = new TH1F("hep","",100, ep_min,ep_max);
	TH1F *hpp = new TH1F("hpp","",100, pp_min,pp_max);
	
	TH1F *hQ2 = new TH1F("hQ2","",100, Q2_min,Q2_max);
	
	TH2F *h2epth = new TH2F("h2epth","",50,ep_min, ep_max,50,eth_min,eth_max);
	TH2F *h2ppth = new TH2F("h2ppth","",50,pp_min, pp_max,50,pth_min,pth_max);
	
	TH2F *h2pthphcm = new TH2F("h2pthphcm","",50,pthcm_min, pthcm_max,50,pphcm_min,pphcm_max);
	TH2F *h2pthphcm_u = new TH2F("h2pthphcm_u","",50,pthcm_min, pthcm_max,50,pphcm_min,pphcm_max);
	
	TH2F *h2rates[int(Q2v.size())-1];
	TH2F *h2rates_u[int(Q2v.size())-1];
	for(int i = 0; i < int(Q2v.size()) - 1; i++){
		float Q2val = (Q2v[i+1] + Q2v[i])/2.0;
		h2rates[i] = new TH2F(Form("h2rates_%d",i),Form("Q2 = %f",Q2val),18,0,180, 36,0,360);
		h2rates_u[i] = new TH2F(Form("h2rates_u_%d",i),"",18,0,180, 36,0,360);
	}
	
	
	TH1F *hQ2res = new TH1F("hQ2res", "", 100, -0.2, 0.2);
	TH1F *hWres = new TH1F("hWres", "", 100, -0.1, 0.1);
	TH1F *hpthres = new TH1F("hpthres", "", 100, -1, 1);
	TH1F *hpphres = new TH1F("hpphres", "", 100, -1, 1);
	
	TH2F *hQ2vQ2 = new TH2F("hQ2vQ2", "", 50, Q2_min, Q2_max, 50, Q2_min, Q2_max);
	
	TH2F *hQ2vSig = new TH2F("hQ2vsSig","",50, Q2_min, Q2_max, 50, 7.0e-9, 14.0e-9);
	
	TH1F *hMM = new TH1F("hMM","",100, MM_min, MM_max);
	
	TH1F *havgdist = new TH1F("havgdist","",100,0.0,10.0);
	
	TTreeReader tr;
	tr.SetTree(&T);
	
	TTreeReaderValue<float> Q2(tr,"Q2");
	TTreeReaderValue<float> W(tr,"W");
	TTreeReaderValue<double> siglab(tr,"siglab");
	TTreeReaderValue<float> the(tr,"the");
	TTreeReaderValue<float> pe(tr,"pe");
	TTreeReaderValue<float> thdl(tr,"thdl");
	TTreeReaderValue<float> pdl(tr,"pdl");
	TTreeReaderValue<float> thdcm(tr,"thdcm");
	TTreeReaderValue<float> phdcm(tr,"phdcm");
	TTreeReaderValue<float> phdl(tr,"phdl");
	TTreeReaderValue<float> phe(tr,"phe");
	
	/*
	TTreeReaderValue<double> sQ2(trs,"sm_Q2");
	TTreeReaderValue<double> sW(trs,"sm_W");
	TTreeReaderValue<double> spthcm(trs,"sm_scat_det_the_cm");
	TTreeReaderValue<double> spphcm(trs,"sm_scat_det_phi_cm");
	
	TTreeReaderValue<double> seth(trs,"sm_scat_e_the_lab");
	TTreeReaderValue<double> sep(trs,"sm_scat_e_mom_lab");
	TTreeReaderValue<double> seph(trs,"sm_scat_e_phi_lab");
	
	TTreeReaderValue<double> spth(trs,"sm_scat_det_the_lab");
	TTreeReaderValue<double> spp(trs,"sm_scat_det_mom_lab");
	TTreeReaderValue<double> spph(trs,"sm_scat_det_phi_lab");
	
	TTreeReaderValue<double> suth(trs,"sm_scat_undet_the_lab");
	TTreeReaderValue<double> sup(trs,"sm_scat_undet_mom_lab");
	TTreeReaderValue<double> suph(trs,"sm_scat_undet_phi_lab");
	*/
	
	TLorentzVector beam4v, targ4v, e4v, p4v, miss4v;
	beam4v.SetXYZM(0.0,0.0,11.0,0.0);
	targ4v.SetXYZM(0.0,0.0,0.0,0.938);
	
	TVector3 e3v, p3v, u3v;
	
	TRandom3 *rand3 = new TRandom3();
	
	double avgdist = 0;
	
	while(tr.Next()){
		//cout << *Q2 << endl;
		//trs.Next();
		
		double phdcm2 = *phdcm*TMath::RadToDeg();
		//double spphcm2 = *spphcm;
		
		double phe2 = *phe*TMath::RadToDeg();
		double phdl2 = *phdl*TMath::RadToDeg();
		
		*thdl *= TMath::RadToDeg();
		*the *= TMath::RadToDeg();
		*thdcm *= TMath::RadToDeg();
		
		if(phdcm2 < 0) phdcm2 = phdcm2 + 360;
		if(phe2 < 0) phe2 = phe2 + 360;
		
		if(phdl2 < 0) phdl2+= 360.0;
		
		double  Jacobian = fabs(1.0/((4.*beamE*beamE*(*pe)*(1.-cos(*the/TMath::RadToDeg()))/(*W))-2.*beamE*(*pe)*mt/(*W)));
		
		
		
		hQ2->Fill(*Q2,*siglab);
		
		hep->Fill(*pe,*siglab);
		heth->Fill(*the,*siglab);
		h2epth->Fill(*pe,*the,*siglab);
		
		hpp->Fill(*pdl,*siglab);
		hpth->Fill(*thdl,*siglab);
		
		h2ppth->Fill(*pdl,*thdl,*siglab);
		
		
		int binv = hQ2b->FindBin(*Q2) - 1;
		double Q2width = hQ2b->GetXaxis()->GetBinWidth(binv +1);
		double Wwidth = 0.6;
		
		cout << binv << endl;
		//cout << h2rates[binv]->GetXaxis()->GetBinWidth(1) << endl;
		
		//cout << cos(h2rates[binv]->GetXaxis()->GetBinLowEdge(h2rates[binv]->GetXaxis()->FindBin(*thdcm))*TMath::DegToRad()) << endl;
		
		double thcm_width = 0;
		double phcm_width = 0;
		
		if(binv >=0 && binv < int(Q2v.size())-1){
			thcm_width = fabs(cos(h2rates[binv]->GetXaxis()->GetBinLowEdge(h2rates[binv]->GetXaxis()->FindBin(*thdcm))*TMath::DegToRad()) - cos(h2rates[binv]->GetXaxis()->GetBinUpEdge(h2rates[binv]->GetXaxis()->FindBin(*thdcm))*TMath::DegToRad()));
		
			phcm_width = fabs(h2rates[binv]->GetYaxis()->GetBinLowEdge(h2rates[binv]->GetYaxis()->FindBin(*phdcm))*TMath::DegToRad() - h2rates[binv]->GetYaxis()->GetBinUpEdge(h2rates[binv]->GetYaxis()->FindBin(*phdcm))*TMath::DegToRad());
			double weight = (*siglab)*Jacobian*Lum*Q2width*Wwidth*thcm_width*phcm_width*2.0*TMath::Pi()*1000.0;
			//cout << weight << endl;
		
			h2pthphcm->Fill(*thdcm, phdcm2, weight);
			h2pthphcm_u->Fill(*thdcm, phdcm2);
			h2rates[binv]->Fill(*thdcm, phdcm2, weight);
			h2rates_u[binv]->Fill(*thdcm, phdcm2);
		}
		
		if(channel == 2){
			avgdist = *pdl/sqrt(pow(*pdl,2) + pow(0.135,2))*2.99e8*2.6e-8;
			havgdist->Fill(avgdist);
		}
		
	}
	
	TCanvas *can1 = new TCanvas("can1","Q2",800,800);
	hQ2->SetStats(0);
	hQ2->Draw();
	
	
	/*
	TCanvas *can2 = new TCanvas("can2","res",800,800);
	can2->Divide(2,2);
	can2->cd(1);
	hQ2res->SetStats(0);
	hQ2res->Draw();
	//hQ2vQ2->Draw("colz");
	can2->cd(2);
	hWres->SetStats(0);
	hWres->Draw();
	can2->cd(3);
	hpthres->SetStats(0);
	hpthres->Draw();
	can2->cd(4);
	hpphres->SetStats(0);
	hpphres->Draw();
	*/
	
	
	TCanvas *can3 = new TCanvas("can3","electron",1500,500);
	can3->Divide(3,1);
	can3->cd(1);
	hep->SetStats(0);
	hep->Draw();
	can3->cd(2);
	heth->SetStats(0);
	heth->Draw();
	can3->cd(3);
	h2epth->SetStats(0);
	h2epth->Draw("colz");
	
	TCanvas *can4 = new TCanvas("can4","pdet",1500,500);
	can4->Divide(3,1);
	can4->cd(1);
	hpp->SetStats(0);
	hpp->Draw();
	can4->cd(2);
	hpth->SetStats(0);
	hpth->Draw();
	can4->cd(3);
	h2ppth->SetStats(0);
	h2ppth->Draw("colz");
	
	TCanvas *can5 = new TCanvas("can5","cm",800,800);
	h2pthphcm->SetStats(0);
	h2pthphcm->Divide(h2pthphcm_u);
	h2pthphcm->Draw("colz");
	//hQ2vSig->Draw("colz");
	//hMM->SetStats(0);
	//hMM->Draw();
	//havgdist->Draw();
	
	TCanvas *cans[(int)Q2v.size() -1];
	
	for(int i = 0; i < (int)Q2v.size() -1; i++){
		float Q2val = (Q2v[i+1] + Q2v[i])/2.0;
		cans[i] = new TCanvas(Form("cans_%d",i), Form("Q2 = %f",Q2val), 800, 800);
		h2rates[i]->Divide(h2rates_u[i]);
		//h2rates[i]->GetZaxis()->SetRangeUser(0.001, 0.004);
		h2rates[i]->Draw("colz");
		cout << "****" << Q2val << "****" << endl;
		cout << endl;
		for(int ii = 1; ii < h2rates[i]->GetXaxis()->GetNbins() +1; ii++){
			for(int jj = 1; jj < h2rates[i]->GetYaxis()->GetNbins() +1; jj++){
				if(h2rates[i]->GetBinContent(ii,jj) > 0.001){
					//cout << h2rates[i]->GetXaxis()->GetBinCenter(ii) << "  " << h2rates[i]->GetYaxis()->GetBinCenter(jj) << "  " << h2rates[i]->GetBinContent(ii,jj)*60.0*60.0*24.0*50 << endl;
					
					//cout << channel << "  " << calc_eps(Q2val, 1.232) << "  " << Q2val << "  1232  " << h2rates[i]->GetXaxis()->GetBinCenter(ii) << "  " << h2rates[i]->GetYaxis()->GetBinCenter(jj) << "  -1  0.1" << endl;
					cout << channel << "  0.925173 5.0  1232  " << h2rates[i]->GetXaxis()->GetBinCenter(ii) << "  " << h2rates[i]->GetYaxis()->GetBinCenter(jj) << "  -1  0.1" << endl;
					
				}
			}
		}
	}
	
	
}

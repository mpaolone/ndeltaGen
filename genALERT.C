#include "SoLID_res.h"
#include "maidxs.h"

void genALERT(int option = 4, int nevents = 1e4){
	
	TRandom3 *rand3 = new TRandom3();
	
	const float mp = 0.938272;
	const float mn = 0.939565;
	const float mpi0 = 0.1349766;
	const float mpip = 0.13957;
	
	float beamE;
	float mt;
	float md;
	float mu;
	float th_min_e;
	float th_max_e;
	float th_min_det;
	float th_max_det;
	
	float Wcut_min;
	float Wcut_max;
	
	int channel;
	
	int nuclear = 0;
	
	//ALERT recoil detection ranges
	float th_min_rec = 60;
	float th_max_rec = 240;
	float mr;
	
	
	
	if(option == 0){
		//Solid Configuration, 11 GeV, p-pi0, 8-15 electron, W_min = 1200, W_max = 1260;
		beamE = 11.0;
		mt = mp;
		md = mp;
		mu = mpi0;
		th_min_e = 8.;
		th_max_e = 15.;
		th_min_det = 8.;
		th_max_det = 25;
		Wcut_min = 1.20;
		Wcut_max = 1.26;
		channel = 1;
	}
	
	if(option == 1){
		//Solid Configuration, 11 GeV, n-pip, 8-15 electron, W_min = 1200, W_max = 1260;
		beamE = 11.0;
		mt = mp;
		md = mpi0;
		mu = mp;
		th_min_e = 8.;
		th_max_e = 15.;
		th_min_det = 8.;
		th_max_det = 15.;
		Wcut_min = 1.20;
		Wcut_max = 1.26;
		channel = 3;
	}
	
	if(option == 2){
		//Solid Configuration, 11 GeV, p-pi0, 8-25 electron, W_min = 1200, W_max = 1260;
		beamE = 11.0;
		mt = mp;
		md = mp;
		mu = mpi0;
		th_min_e = 8.;
		th_max_e = 25.;
		th_min_det = 8.;
		th_max_det = 25;
		Wcut_min = 1.20;
		Wcut_max = 1.26;
		channel = 1;
	}
	
	if(option == 3){
		//Solid Configuration, 11 GeV, n-pip, 8-15 electron, W_min = 1200, W_max = 1260;
		beamE = 11.0;
		mt = mp;
		md = mpi0;
		mu = mp;
		th_min_e = 8.;
		th_max_e = 25.;
		th_min_det = 8.;
		th_max_det = 15.;
		Wcut_min = 1.20;
		Wcut_max = 1.26;
		channel = 3;
	}
	
	if(option == 220){
		//Solid Configuration, 11 GeV, p-pi0, 8-25 electron, W_min = 1200, W_max = 1260;
		beamE = 20.0;
		mt = mp;
		md = mp;
		mu = mpi0;
		th_min_e = 8.;
		th_max_e = 25.;
		th_min_det = 8.;
		th_max_det = 25;
		Wcut_min = 1.20;
		Wcut_max = 1.26;
		channel = 1;
	}
	
	if(option == 4){
		//ALERT settings:
		beamE = 11.0;
		mr = 2.8295; //He3
		//mt = 4.0026*0.931; //He4
		mt = mn;
		nuclear = 1;
		th_min_e = 5.;
		th_max_e = 45.;
		th_min_det = 5.;
		th_max_det = 45;
		Wcut_min = mp + mpip;
		Wcut_max = 5.0;
		mu = mp;
		md = mpip;
		
	}
	
	
	if(Wcut_min < md + mu) Wcut_min = md + mu;
	
	
	
	
	float pe, the, phe;
	float pdcm, thdcm, phdcm;
	float edcm, eucm;
	float pdl, thdl, phdl;
	float pucm, thucm, phucm;
	float pul, thul, phul;
	
	//smeared values
	float pes, thes, phes;
	float pdcms, thdcms, phdcms;
	float pdls, thdls, phdls;
	float Q2s, Ws, MM2s;
	double siglab;
	
	//float ctmin = cos(th_max_e*TMath::DegToRad());
	//float ctmax = cos(th_min_e*TMath::DegToRad());
	float ctmin = 0;
	float ctmax = 0.9;
	
	float emin, emax;
	
	float Q2, W, Jac;
	
	TLorentzVector b4v, t4v, e4v, q4v, d4v, u4v, r4v, e4vs, q4vs, d4vs;
	TVector3 b3v, t3v, e3v, q3v, d3v, u3v, boostcm, boostcms, e3vs, qv3s, d3vs, boostn;
	
	b4v.SetXYZM(0.,0.,beamE,0.);
	t4v.SetXYZM(0.,0.,0.,mt);
	
	
	TFile *out_file= new TFile(Form("out_%d.root",option),"recreate");
	TTree *T = new TTree("T","T");
	T->Branch("Q2", &Q2);
	T->Branch("W", &W);
	T->Branch("Q2s", &Q2s);
	T->Branch("Ws", &Ws);
	T->Branch("MM2s", &MM2s);
	
	//T->Branch("Jac", &Jac);
	
	T->Branch("pe", &pe);
	T->Branch("the", &the);
	T->Branch("phe", &phe);
	
	T->Branch("pdl", &pdl);
	T->Branch("thdl", &thdl);
	T->Branch("phdl", &phdl);
	
	T->Branch("pdcm", &pdcm);
	T->Branch("thdcm", &thdcm);
	T->Branch("phdcm", &phdcm);
	
	
	T->Branch("pes", &pes);
	T->Branch("thes", &thes);
	T->Branch("phes", &phes);
	
	T->Branch("pdls", &pdls);
	T->Branch("thdls", &thdls);
	T->Branch("phdls", &phdls);
	
	T->Branch("pul", &pul);
	T->Branch("thul", &thul);
	T->Branch("phul", &phul);
	
	T->Branch("pdcms", &pdcms);
	T->Branch("thdcms", &thdcms);
	T->Branch("phdcms", &phdcms);
	
	T->Branch("siglab", &siglab);
	
	TH1F *hQ2res = new TH1F("hQ2res","",100, -0.5, 0.5);
	TH1F *hWres = new TH1F("hWres","",100, -0.5, 0.5);
	
	TH1F *hperes = new TH1F("hperes","",100, -1, 1);
	TH1F *htheres = new TH1F("htheres","",100, -1, 1);
	
	TH1F *hthdcmres = new TH1F("hthdcmres","",100, -30, 30);
	TH1F *hphdcmres = new TH1F("hphdcmres","",100, -10, 10);
	TH1F *hMM2 = new TH1F("hMM2","",100, mu*mu - 1.0, mu*mu + 1.0);
	
	
	int nextout = 0.0;
	float outper = 0.0;
	
	TVector3 tn3v, tr3v;
	TLorentzVector tn4v, tr4v;
	
	TVector3 beamDir(0,0,1);
	
	
	for(int i = 0; i < nevents; i++){
		
		if(i == nextout){
			cout << outper*100 << "%" << endl;
			outper += 0.1;
			nextout = nevents*outper;
		}
		
		//create nucleus with fermi-momentum:
		float pf = rand3->Poisson(20)/100.0;
		float thf = acos(rand3->Uniform(-1,1));
		float phf = rand3->Uniform(0.0, 2.0*TMath::Pi());
		
		tn3v.SetMagThetaPhi(pf,thf,phf);
		tr3v = -tn3v;
		
		tn4v.SetVectM(tn3v,mt);
		tr4v.SetVectM(tr3v,mr);
		
		b4v.SetXYZM(0,0,beamE,0);
		
		boostn = tn4v.BoostVector();
		
		b4v.Boost(-boostn);
		//cout << b4v.X() << b4v.Y() << b4v.Z() << endl;
		tn4v.Boost(-boostn);
		//cout << tn4v.E() << endl;
		the = acos(rand3->Uniform(ctmin, ctmax));
		
		
		emin = 0;
		//emax = (pow(Wcut_min,2) - mt*mt - 2.*b4v.E()*mt)/2./(b4v.E()*cos(the) - b4v.E() - mt);
		//emin = (pow(Wcut_max,2) - mt*mt - 2.*b4v.E()*mt)/2./(b4v.E()*cos(the) - b4v.E() - mt);
		
		emin = 0.0;
		emax = b4v.E();
		
		if(emin < 0 || emax < 0){
			i--;
			continue;
		}
		
		if(emax < emin){
			i--;
			continue;
		}
		
		
		
		//cout << b4v.E() << "  " << emin << "  " << emax << endl;
		//cout << (pow(Wcut_min,2) - mt*mt - 2.*b4v.E()*mt) << "  " << (pow(Wcut_max,2) - mt*mt - 2.*b4v.E()*mt) << endl;
		//emin = mpip;
		//emax = 5.0;
		pe = rand3->Uniform(emin, emax);
		e3v.SetMagThetaPhi(pe,the,0);
		e4v.SetVectM(e3v,0);
		
		//e4v.RotateUz(b4v.Vect().Unit());
		
		q4v = b4v - e4v;
		
		W = (q4v + tn4v).M();
		
		
		if(W < mt + mpip || W > 1.3){
			i--;
			continue;
		}
		
		
		//e4v.RotateUz(beamDir);
		q4v = b4v - e4v;
		
		//q3v = q4v.Vect();
		r4v = q4v + t4v;
		boostcm = (q4v + t4v).BoostVector();
		
		//cm of resonance
		
		r4v.Boost(-boostcm);
		q4v.Boost(-boostcm);
		q3v = q4v.Vect();
		edcm = (pow(r4v.E(),2) + md*md - mu*mu)/(2.0*r4v.E());
		eucm = r4v.E() - edcm;
		
		thdcm = acos(rand3->Uniform(-1,1));
		phdcm = rand3->Uniform(0,2.0*TMath::Pi());
		pdcm = sqrt(edcm*edcm - md*md);
		d3v.SetMagThetaPhi(pdcm,thdcm, phdcm);
		u3v = -d3v;
		pucm = u3v.Mag();
		thucm = u3v.Theta();
		phucm = u3v.Phi();
		
		d4v.SetVectM(d3v, md);
		u4v.SetVectM(u3v, mu);
		
		d4v.RotateUz(q3v.Unit());
		u4v.RotateUz(q3v.Unit());
		
		//boost back
		d4v.Boost(boostcm);
		u4v.Boost(boostcm);
		r4v.Boost(boostcm);
		q4v.Boost(boostcm);
		
		tn4v.Boost(boostn);
		b4v.Boost(boostn);
		e4v.Boost(boostn);
		d4v.Boost(boostn);
		u4v.Boost(boostn);
		r4v.Boost(boostn);
		q4v.Boost(boostn);
		
		
		
		
		//rotate verything in phi:
		
		phe = rand3->Uniform(0.,2.*TMath::Pi());
		
		e4v.RotateZ(phe);
		d4v.RotateZ(phe);
		u4v.RotateZ(phe);
		q4v.RotateZ(phe);
		tr4v.RotateZ(phe);
		
		d3v = d4v.Vect();
		u3v = u4v.Vect();
		e3v = e4v.Vect();
		q3v = q4v.Vect();
		
		pdl = d3v.Mag();
		thdl = d3v.Theta();
		phdl = d3v.Phi();
		
		pul = u3v.Mag();
		thul = u3v.Theta();
		phul = u3v.Phi();
		
		if(u4v.Theta()*TMath::RadToDeg() < th_min_det || u4v.Theta()*TMath::RadToDeg() > th_max_det || e4v.Theta()*TMath::RadToDeg() < th_min_e || e4v.Theta()*TMath::RadToDeg() > th_max_e || d4v.Theta()*TMath::RadToDeg() < th_min_det || d4v.Theta()*TMath::RadToDeg() > th_max_det || tr4v.Theta()*TMath::RadToDeg() < th_min_rec || tr4v.Theta()*TMath::RadToDeg() > th_max_rec){
			i--;
			continue;
		}
		
		//cout << b4v.E() + tn4v.E() << "  " << e4v.E() + d4v.E() + u4v.E() << endl;
		
		
		Q2 = -q4v.M2();
		
		
		//now find smeared values
		/*
		pes = pres(pe,the*TMath::RadToDeg());
		thes = thres(pe,the*TMath::RadToDeg())*TMath::DegToRad();
		phes = phres(pe,the,phe*TMath::RadToDeg())*TMath::DegToRad();
		
		pdls = pres(pdl, thdl*TMath::RadToDeg());
		thdls = thres(pdl, thdl*TMath::RadToDeg())*TMath::DegToRad();
		//cout << pdl << "  " << pdls << " | " << thdl << "  " << thdls << endl;
		phdls = phres(pdl, thdl*TMath::RadToDeg(), phdl*TMath::RadToDeg())*TMath::DegToRad();
		
		//set sphi = 0;
		
		e3vs.SetMagThetaPhi(pes, thes, 0.0);
		e4vs.SetVectM(e3vs,0);
		
		q4vs = b4v - e4vs;
		Q2s = -q4vs.M2();
		Ws = (t4v + q4vs).M();
		d3vs.SetMagThetaPhi(pdls, thdls, phdls - phes);
		d4vs.SetVectM(d3vs, md);
		
		MM2s = (b4v + tn4v - e4vs - d4vs).M2();
		
		//cout << MM2s << "  " << (b4v + t4v - e4v - d4v).M2() << endl;
		
		//cout << e4v.Theta() << "  " << e4vs.Theta() << " | " << d4v.Theta() << "  " << d4vs.Theta() << endl;
		
		boostcms = (t4v + q4vs).BoostVector();
		q4vs.Boost(-boostcms);
		d4vs.Boost(-boostcms);
		d4vs.RotateUz(q4vs.Vect().Unit());
		
		
		pdcms = d4vs.Vect().Mag();
		thdcms = d4vs.Vect().Theta();
		phdcms = d4vs.Vect().Phi();
		
		hQ2res->Fill(Q2 - Q2s);
		hWres->Fill(W - Ws);
		hMM2->Fill(MM2s);
		hthdcmres->Fill((thdcm - thdcms)*TMath::RadToDeg());
		hphdcmres->Fill((phdcm - phdcms)*TMath::RadToDeg());
		
		siglab = maidxs(Q2, W, beamE, pe, thdcm, phdcm, mt, channel);
		*/
		T->Fill();
	}
	T->Write();
	hQ2res->Write();
	hWres->Write();
	hMM2->Write();
	hthdcmres->Write();
	hphdcmres->Write();
	
	out_file->Close();
	
	
}
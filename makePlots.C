void makePlots(){
	TFile *file0 = new TFile("out_0.root");
	TH1F *hQ2res0 = (TH1F*)file0->Get("hQ2res");
	TH1F *hWres0 = (TH1F*)file0->Get("hWres");
	TH1F *hMM20 = (TH1F*)file0->Get("hMM2");
	TH1F *hthres0 = (TH1F*)file0->Get("hthdcmres");
	TH1F *hphres0 = (TH1F*)file0->Get("hphdcmres");
	
	
	TFile *file1 = new TFile("out_1.root");
	TH1F *hQ2res1 = (TH1F*)file1->Get("hQ2res");
	TH1F *hWres1 = (TH1F*)file1->Get("hWres");
	TH1F *hMM21 = (TH1F*)file1->Get("hMM2");
	TH1F *hthres1 = (TH1F*)file1->Get("hthdcmres");
	TH1F *hphres1 = (TH1F*)file1->Get("hphdcmres");
	
	
	TFile *file2 = new TFile("out_2.root");
	TH1F *hQ2res2 = (TH1F*)file2->Get("hQ2res");
	TH1F *hWres2 = (TH1F*)file2->Get("hWres");
	TH1F *hMM22 = (TH1F*)file2->Get("hMM2");
	TH1F *hthres2 = (TH1F*)file2->Get("hthdcmres");
	TH1F *hphres2 = (TH1F*)file2->Get("hphdcmres");
	
	TFile *file3 = new TFile("out_3.root");
	TH1F *hQ2res3 = (TH1F*)file3->Get("hQ2res");
	TH1F *hWres3 = (TH1F*)file3->Get("hWres");
	TH1F *hMM23 = (TH1F*)file3->Get("hMM2");
	TH1F *hthres3 = (TH1F*)file3->Get("hthdcmres");
	TH1F *hphres3 = (TH1F*)file3->Get("hphdcmres");
	
	
	TCanvas *canr1 = new TCanvas("canr1", "", 1200,800);
	canr1->Divide(3,2);
	canr1->cd(1);
	hQ2res0->SetStats(0);
	hQ2res0->Scale(1.0/hQ2res0->Integral());
	hQ2res0->SetLineColor(kRed);
	hQ2res0->Draw("hist");
	hQ2res0->GetXaxis()->SetTitle("#Delta Q^{2} (GeV^{2})");
	hQ2res2->Scale(1.0/hQ2res2->Integral());
	hQ2res2->SetLineColor(kBlue);
	hQ2res2->Draw("histsame");
	
	canr1->cd(2);
	hWres0->SetStats(0);
	hWres0->Scale(1.0/hWres0->Integral());
	hWres0->SetLineColor(kRed);
	hWres0->Draw("hist");
	hWres0->GetXaxis()->SetTitle("#Delta W (GeV)");
	hWres2->Scale(1.0/hWres2->Integral());
	hWres2->SetLineColor(kBlue);
	hWres2->Draw("histsame");
	
	canr1->cd(3);
	hMM22->SetStats(0);
	hMM22->Scale(1.0/hMM22->Integral());
	hMM22->SetLineColor(kBlue);
	hMM22->Draw("hist");
	hMM22->GetXaxis()->SetTitle("#Delta MM^{2} (GeV^{2})");
	hMM20->Scale(1.0/hMM20->Integral());
	hMM20->SetLineColor(kRed);
	hMM20->Draw("histsame");
	
	canr1->cd(4);
	hthres0->SetStats(0);
	hthres0->Scale(1.0/hthres0->Integral());
	hthres0->SetLineColor(kRed);
	hthres0->Draw("hist");
	hthres0->GetXaxis()->SetTitle("#Delta #theta^{#pi}_{cm} (Deg)");
	hthres2->Scale(1.0/hthres2->Integral());
	hthres2->SetLineColor(kBlue);
	hthres2->Draw("histsame");
	
	canr1->cd(5);
	hphres0->SetStats(0);
	hphres0->Scale(1.0/hphres0->Integral());
	hphres0->SetLineColor(kRed);
	hphres0->Draw("hist");
	hphres0->GetXaxis()->SetTitle("#Delta #phi^{#pi}_{cm} (Deg)");
	hphres2->Scale(1.0/hphres2->Integral());
	hphres2->SetLineColor(kBlue);
	hphres2->Draw("histsame");
	
	
	
	TCanvas *canr2 = new TCanvas("canr2", "", 1200,800);
	canr2->Divide(3,2);
	canr2->cd(1);
	hQ2res1->SetStats(0);
	hQ2res1->Scale(1.0/hQ2res1->Integral());
	hQ2res1->SetLineColor(kRed);
	hQ2res1->Draw("hist");
	hQ2res1->GetXaxis()->SetTitle("#Delta Q^{2} (GeV^2)");
	hQ2res3->Scale(1.0/hQ2res3->Integral());
	hQ2res3->SetLineColor(kBlue);
	hQ2res3->Draw("histsame");
	
	canr2->cd(2);
	hWres1->SetStats(0);
	hWres1->Scale(1.0/hWres1->Integral());
	hWres1->SetLineColor(kRed);
	hWres1->Draw("hist");
	hWres1->GetXaxis()->SetTitle("#Delta W (GeV)");
	hWres3->Scale(1.0/hWres3->Integral());
	hWres3->SetLineColor(kBlue);
	hWres3->Draw("histsame");
	
	canr2->cd(3);
	hMM21->SetStats(0);
	hMM21->Scale(1.0/hMM21->Integral());
	hMM21->SetLineColor(kRed);
	hMM21->Draw("hist");
	hMM21->GetXaxis()->SetTitle("#Delta MM^{2} (GeV^{2})");
	hMM23->Scale(1.0/hMM23->Integral());
	hMM23->SetLineColor(kBlue);
	hMM23->Draw("histsame");
	
	canr2->cd(4);
	hthres1->SetStats(0);
	hthres1->Scale(1.0/hthres1->Integral());
	hthres1->SetLineColor(kRed);
	hthres1->Draw("hist");
	hthres1->GetXaxis()->SetTitle("#Delta #theta^{#pi}_{cm} (Deg)");
	hthres3->Scale(1.0/hthres3->Integral());
	hthres3->SetLineColor(kBlue);
	hthres3->Draw("histsame");
	
	canr2->cd(5);
	hphres1->SetStats(0);
	hphres1->Scale(1.0/hphres1->Integral());
	hphres1->SetLineColor(kRed);
	hphres1->Draw("hist");
	hphres1->GetXaxis()->SetTitle("#Delta #phi^{#pi}_{cm} (Deg)");
	hphres3->Scale(1.0/hphres3->Integral());
	hphres3->SetLineColor(kBlue);
	hphres3->Draw("histsame");
	
	
	
	
	
}
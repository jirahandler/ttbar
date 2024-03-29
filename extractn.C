void extractn(){
    TFile *f_in1 = new TFile("a2.root","READ");
    //TFile *f_in2 = new TFile("bckg.root","READ");
    //TFile *fout  = new TFile("analysisn.root","RECREATE");
    TCanvas *c1 = new TCanvas("c1","c1",1200,800) ;
  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);
  //gStyle->SetOptTitle(0);
  gStyle->SetTitleX(0.1f);
  gStyle->SetTitleW(0.8f);
  //c1->cd();
   TLegend* l = new TLegend(0.60,.90,0.85,0.95);
    l->SetBorderSize(0);
    l->SetFillStyle(0);
    l->SetTextFont(42);
    //l->SetMargin(0.4);
        std::string str1;
        std::string str2;
        str1="tag_dl1_2";
        str2="all_dl1_2";
        const char *c11 = str1.c_str();
        const char *c2 = str2.c_str();
        
        TH1F *h1 = (TH1F*)f_in1->Get(c11);
        TH1F *h2 = (TH1F*)f_in1->Get(c2); 
        //h1->Write();
        //h2->Write();
 TH1F* h_ratio = (TH1F*)h1->Clone("ratio");
  h_ratio->Divide(h1,h2,1,1,"B");
  h_ratio->SetLineColor(1);
  h_ratio->SetLineWidth(3);
  //h_ratio->SetFillColor(48);
  //h_ratio->SetFillStyle(3001);
  h_ratio->SetMarkerStyle(20);
  h_ratio->SetTitle("B-Tag Eff vs Lxy(DL1:2.02);Lxy(mm);Efficiency");
  l->AddEntry(h_ratio,"d0max=2.5mm, z0max=2.5mm","l");
  h_ratio->Draw("HIST E0");
  l->Draw();
  c1->Modified();
  c1->Update();
  c1->SaveAs("TaggedvsAll_PU_DL1.png");
}

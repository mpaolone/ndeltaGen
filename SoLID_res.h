TRandom3 *randRes = new TRandom3(0);

//input is GeV, output is smeared momentum in GeV
float pres(float p, float th){ //%
        TF1 f("f","pol2"); //the function is in percentage
        if(th >= 15.0){
                f.SetParameters(2.71904 - 0.0746755*th, -0.403173 + 0.0133169*th, 0.0503813 - 0.00160239*th);
        }else{
                f.SetParameters(0.844686 -0.027475*th, -0.0710175 +0.00513166*th, 0.0164848 -0.00104674*th);
        }
        
        float retval = f.Eval(p);
        if(retval < 0.4) retval = 0.4;
		retval = p*(1.0 + randRes->Gaus(0,retval)/100.0); 
		//retval = p*(1.0 + randRes->Gaus(0,retval)); 
        return retval;
}

//input is in degrees, output is smeared theta in degrees
float thres(float p, float th){  //mr
        //if(th >= 15.0) return 0.27;
        TF1 f("f","expo(0) + pol0(2)");
        f.SetParameters(-0.906512 + 0.0892709*th, -1.02903 +0.00749916*th,  0.149145  - 0.000772653*th);
        
        float retval = f.Eval(p);
		//cout << retval << endl;
        
        if(retval < 0.14) retval = 0.14;
		if(th >= 15.0) retval = 0.27;
		retval = (th*TMath::DegToRad() + randRes->Gaus(0, retval)/1000.0)*TMath::RadToDeg();
        return retval;
        
}

//input is in degrees, output is smeared theta in degrees
float phres(float p, float th, float ph){  //mr
        TF1 f("f","expo(0) + pol0(2)");
        if(th >= 15.0){
                f.SetParameters(4.05968 -0.0331193*th,  -1.07492 + 0.00151554*th,  2.09241 -0.0517049*th);
        }else{
                f.SetParameters( 3.26255  -0.0263838*th, -0.784884 -0.0139965*th,  1.76064 -0.0814243*th);
        }
        
        float retval = f.Eval(p);
        if(retval < 0.5) retval = 0.5;
		retval = (ph*TMath::DegToRad() + randRes->Gaus(0, retval)/1000.0)*TMath::RadToDeg();
        return retval;
}
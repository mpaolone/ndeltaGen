R__LOAD_LIBRARY(libmaid)

extern "C"{
 void get_xn_maid_07_(double *Q2,double *W, double *EI, double *EF, double *tht, double *pht, double *siglab,double *sigcm);

}

void get_maid(){

	//Units are in MeV and degrees
double Q2 = 350000.00; //MeV^2
double W = 1232.0; //MeV
double EI = 4560.; //MeV
double EF = 4030.; //MeV
double tht = 60.0; //Deg
double pht = 0.0; //Deg
double siglab = 0.0; //This will be re-assigned the value for the cross-section in the lab:  units are ub/MeV/sr^2 (i think)
double sigcm = 0.0;  //This will be re-assigned the value for the cross-section in the center of mass:  units are ub/MeV/sr^2 (i think)


get_xn_maid_07_(&Q2,&W,&EI,&EF,&tht,&pht,&siglab,&sigcm);

cout << "cross-section in the lab is: " << siglab <<  " ub/MeV/sr^2 " << endl;


}

use Config;
my $osname = $Config{osname};
my $gppver = "g++-".`gfortran -dumpversion`;
chomp($gppver);


system("gfortran -std=legacy -fcheck=all -ffixed-line-length-132 -fno-automatic -fdefault-real-8  -c get_xn_maid_07.f");

if($osname eq darwin){
	print "Making for os: ".$osname."\n";
	system("$gppver -fpic -dynamiclib  get_xn_maid_07.o -lquadmath -o libmaid.dylib -lgfortran");
}else{
	#if Linux:
	system("g++ -fpic -shared get_xn_maid_07.o -lquadmath -o libmaid.so -lgfortran");
}
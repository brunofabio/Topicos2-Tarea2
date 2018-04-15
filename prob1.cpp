#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
using namespace std;

const double a = 0.05;
const double b = 0.002;
const double c = 0.06;
const double d = 0.004;
const double step = 0.1;

const int numberOfLoops = 4000;


double dxdt(double x, double y){
	return x*(a - b*y);
}

double dydt(double x, double y){
	return -y*(c - d*x);
}

int main(int argc, char** argv){
	
	// x -> presa
	// y -> depredador
	
	double y0Step = 1;
	
	for(int i1 = 0; i1 < 100; i1++){
				
		double x0 = 100;
		double y0 = 10+i1*y0Step;
	
		double x = x0;
		double y = y0;
	

		ofstream af;
		stringstream afN; afN << "./txt/xt" << setfill('0') << setw(4) << i1 << ".txt";
		string afName = afN.str();
		
		ofstream bf;
		stringstream bfN; bfN << "./txt/yt" << setfill('0') << setw(4) << i1 << ".txt";
		string bfName = bfN.str();
		
		af.open(afName);
		bf.open(bfName);

		for(double i1 = 0; i1 < numberOfLoops * step ; i1 += step){
	
			af << i1 << ' ' << x << endl;
			bf << i1 << ' ' << y << endl;
	
			x0=x;
			y0=y;
	
			x += step * dxdt(x0,y0);
			y += step * dydt(x0,y0);
		}
	
		af.close();
		bf.close();
		

	}



	return 0;
}

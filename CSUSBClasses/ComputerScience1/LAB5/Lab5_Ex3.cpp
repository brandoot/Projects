/* Brandon Deo
 * Lab5_Ex3
 * This program calculates volumnes and spheres for cylinder and spheres
 *
 * 24 February 2019
 */
#include<iostream>
#include<cmath>

using namespace std;

//prototypes functions
double sphere_volume(const double& r);
double sphere_surfa(const double& r);
double cyl_sura(const double& r, const double& h);
double cyl_vol(const double& r, const double& h);

int main(){
	//declares variables
	string userinput,sphere,cylinder,exit;
	double r=0,h=0;

	//Informs user of program, prompts user for input
	cout<<"Welcome!To calculate surface area and volume of cylinders and spheres, please enter in sphere or cylinder to go further or enter exit to leave: "<<endl;
	cin>>userinput;

	//if else statements to check which input
		if(userinput=="sphere"){
			cout<<"Now please enter in the radius of the sphere: ";
			cin>>r;
			cout<<"The volume of the sphere is "<<sphere_volume(r)<<" and the surface area is "<<sphere_surfa(r)<<"."<<endl;
		}

		else if(userinput=="cylinder"){
			cout<<"Now please enter in the radius of the cylinder: ";
			cin>>r;
			cout<<endl<<"Now enter the height of the cylinder: ";
			cin>>h;
			cout<<endl<<"The volume of the cylinder is "<<cyl_vol(r,h)<<" and the surface area is "<<cyl_sura(r,h)<<"."<<endl;
		}

		else if(userinput=="exit"){
			cout<<"Bye."<<endl;
		}

		else{
			cout<<"Invalid input please try again."<<endl;
		}

	return 0;

}
//functions to calculate surface areas and volumes of spheres and cylinders
double sphere_volume(const double& r){
	double svolume=(4.0/3.0)*(3.14)*(pow(r,3));

	return svolume;
}

double sphere_surfa(const double& r){
	double ssurfa=(4.0)*(3.14)*(pow(r,2));

	return ssurfa;

}

double cyl_sura(const double& r,const double& h){
	double cyl=(2*3.14*r*h)+(2*3.13*r*r);

	return cyl;
}

double cyl_vol(const double& r, const double& h){
	double cylvol=3.14*h*r*r;

	return cylvol;

}

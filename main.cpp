#include <iostream>
#include <fstream>
#include "components.h"
using namespace std;

void render(Components c){	
	int height = 500;
	int width = 500;
	ColorP pix_col;		
	ofstream my_Img ("image.ppm");	
	if (my_Img.is_open ()){
		my_Img << "P3\n" <<width<<" "<<height<<" 255\n";
		for (int i=0; i<height; i++){
			for (int j=0; j<width; j++){
				pix_col=c.traceray(i,j);
				my_Img<<(int)pix_col.get_r()<<' '<<(int)pix_col.get_g()<<' '<<(int)pix_col.get_b()<<"\n";
			}
		}
		my_Img.close();
	}
	else cout<<"Could not open the file";
}

int main(){
	Components components;
	Light light;
	vector<Sphere> sphere;
	Sphere sph1(Vec3(325,160,220),100,ColorP(127,255,0));
	Sphere sph2(Vec3(215,330,350),150,ColorP(0,128,0));
	sphere.push_back(sph1);
	sphere.push_back(sph2);	
	components.add(sphere);
	components.setLight(light);
	render(components);
	return 0;
}

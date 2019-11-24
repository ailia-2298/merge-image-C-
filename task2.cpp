#include <iostream>
#include <fstream>  
using namespace std;  
#define HSZIE 54 
#define COLS 200 
#define ROWS 200  
//Don't concentrate on read & write functions, just concentrate on reverse function 
void readFile(string fName, unsigned char h[], unsigned char m[][COLS][3]){  
	ifstream in(fName.c_str(),ios::binary);  
	in.read((char*)h,HSZIE);  
	in.read((char*)m,ROWS*COLS*3);  
	in.close(); 
} 
void writeFile(string fName, unsigned char h[], unsigned char m[][COLS][3]){  
	ofstream out(fName.c_str(),ios::binary);  
	out.write((char*)h,HSZIE);  
	out.write((char*)m,ROWS*COLS*3);  
	out.close(); 
} 
void removeRed(unsigned char m1[][COLS][3], unsigned char m2[][COLS][3]){  
int i,j, k, m, n;  
	for (i=0;i<ROWS;i++)   
		for (j=0;j<COLS;j++){    
			m2[i][j][0]=m1[i][j][0];//Assign Green to Green    
			m2[i][j][1]=m1[i][j][1];//Assign Blue to Blue    
			m2[i][j][2]=m1[i][j][2];//Assign 0 to Red   
		}
} 
int main(){  
unsigned char h[HSZIE], m1[ROWS][COLS][3], m2[ROWS][COLS][3];  
readFile("im02.bmp",h, m1);  
removeRed(m1, m2);  
writeFile("result.bmp",h, m2);  
return 0; 
}


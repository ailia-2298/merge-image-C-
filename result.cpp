#include <iostream> 
#include <fstream> 
using namespace std; 
#define HSZIE 1078 
#define COLS 200 
#define ROWS 200  
void readFile(string fName, unsigned char h[], unsigned char m[][COLS]){ 
	ifstream in(fName.c_str(),ios::binary);  
	in.read((char*)h,HSZIE);  
	in.read((char*)m,ROWS*COLS);  
in.close(); 
}
void writeFile(string fName, unsigned char h[], unsigned char m[][COLS]){ 
	ofstream out(fName.c_str(),ios::binary);  
	out.write((char*)h,HSZIE);  
	out.write((char*)m,ROWS*COLS);  
out.close(); 
} 
void merge(unsigned char m1[][COLS], unsigned char m2[][COLS], unsigned char m3[][COLS]){  
	int i,j, k, m, n;  
	for (i=0;i<ROWS;i++)   
	for (j=0;j<COLS/2;j++)    
		m3[i][j]=m1[i][j];

	for (m=0;m<ROWS;m++)   
	for (n=(COLS/2)+1;n<COLS;n++)    
		m3[m][n]=m2[m][n];
} 
int main(){  
	unsigned char h[HSZIE], m1[ROWS][COLS], m2[ROWS][COLS] ,m3[ROWS][COLS];  
	readFile("mm01.bmp",h, m1);  
	readFile("mm02.bmp",h, m2); 
	merge(m1,m2,m3);  
	writeFile("task01.bmp",h,m3);  
return 0; 
}  

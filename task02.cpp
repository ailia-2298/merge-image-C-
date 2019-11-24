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
void merge(unsigned char m1[][COLS], unsigned char m2[][COLS], unsigned char m3[][COLS], unsigned char m4[][COLS], unsigned char m5[][COLS]){  
	int i,j, k, m, n,x,y,a,b;  
	for (i=0;i<ROWS;i++)   
	for (j=0;j<COLS/2;j++)    
		m5[i][j]=m1[i][j];
		
	for (m=0;m<ROWS;m++)   
	for (n=(COLS/2)+1;n<COLS;n++)    
	m5[m][n]=m2[m][n];    	
	for (x=0;x<ROWS/2;x++)   
	for (y=0;y<COLS/2;y++)    
		m5[x][y]=m3[x][y];
		
	for (a=0;a<ROWS/2;a++)   
	for (b=(COLS/2)+1;b<COLS;b++)    
		m5[a][b]=m4[a][b];
} 
int main(){  
	unsigned char h[HSZIE], m1[ROWS][COLS], m2[ROWS][COLS] ,m3[ROWS][COLS],m4[ROWS][COLS],m5[ROWS][COLS];  
	readFile("im01.bmp",h, m1);  
	readFile("im02.bmp",h, m2); 
	readFile("im03.bmp",h, m3); 
	readFile("im04.bmp",h, m4); 
	merge(m1,m2,m3,m4,m5);  
	writeFile("task02.bmp",h,m5);  
return 0; 
}  

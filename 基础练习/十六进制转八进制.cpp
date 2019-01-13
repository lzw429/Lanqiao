#include<iostream>
#define MAX_LEN 100010
using namespace std;
char hexToBin[16][4]={};
void hexToOct(char h[])
{
	char b[4*MAX_LEN]= {};

}

int main()
{
	int n;
	cin>>n;
	for(int i=0; i<n; i++) {
		char h[MAX_LEN] = {};
		hexToOct(h);
		printf("1");
	}
	return 0;
}

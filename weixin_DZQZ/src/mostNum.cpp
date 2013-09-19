/* 
 * question on Aug10.
 * find the greatest num abcdefghijk, where abc,bcd,cde,def are all different prime number 
 * author answer: construct a directive graph, find the longest path. with dynamic solution
 * not done yet
 * */
#include "stdio.h"
#include <set>
#include <map>

using namespace std;

int getSquareRoot(int n){
	int i=2;
	for(;i*i<=n;++i);
	return i-1;
}

bool isPrime(int n){
	int q = getSquareRoot(n);
	int i=2;
	for(;i<=q && n%i != 0;++i);
	return (i<=q) ? false : true;
}

void findGreatestNum(){
	set<int> hundredPrimes;
	multimap<int, int> prefixMap;	
	for(int i= 101;i<1000;i += 10){
		for(int j=0;j<9;j+=2){
			if(isPrime(i+j)){
				hundredPrimes.insert(i+j);
				printf("%d ", i+j);
			}
		}
		printf("\n");
	}
}

int main(int argc, char* argv[]){
	findGreatestNum();
	printf("\n");
	return 0;
}


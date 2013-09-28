/*
*question on Sep19
*split a string to palindromes with least count
*
* test data:
* aabaa, aabaa
* ababcac, aba|b|cac
* bbcbbcbb,
* bbbbb
*/
#include "../header/preliminary.h"

/*
* dynamic programming
*/
void output02(const string& str, int** ppLength, int* pCount, int k, int n){			//k is index
	if(k<0)		return;
	int i = k-1;	
	if(pCount[k] > 1){
		for(;i>=0;i--){
			if(pCount[i] == pCount[k]-1 && ppLength[k][k-i] == 1){
				output02(str, ppLength, pCount, i, n);
				break;
			}
		}
	}else
	  i = -1;
	for(int j=i+1;j<=k;j++)
		printf("%c", str[j]);
	if(k != n-1)
		printf("|");
}
/*
 * time O(n^2), space O(n^2)
 * */
int splitpalindrome02(const string& str){
    int n = str.size();
    int** ppLength = new int*[n];			//longest palindrome ends at str[pos]
    for(int i=0;i<n;i++){					
		ppLength[i] = new int[n+1]();		//for substring of length j ends at str[i], 1 for palindrome and 0 for not
		ppLength[i][1] = 1;
	}
	int* minCount = new int[n]();			//min count of substring
	minCount[0] = 1;
	for(int i=1;i<n;i++)
	  minCount[i] = i+1;
    
    minCount[0] = 1;
	int pos=1;
    while(pos < n){
		for(int b=0;b<pos;b++){			//start of palindrome ends at pos
			if(str[pos] == str[b]){ 
				if(pos-b<3 || ( pos-b > 2 && ppLength[pos-1][pos-1-b] == 1)){
					ppLength[pos][pos-b+1] = 1;
					if(b==0)
					  minCount[pos] = 1;
					else if(minCount[pos] > minCount[b-1]+1)
					  minCount[pos] = minCount[b-1]+1;					
				}
			}
		}
		if(minCount[pos] == pos+1)			//minCount[i] never updated, so it should be following [i-1]
		  minCount[pos] = minCount[pos-1] + 1;
		++pos;
    }
	int res = minCount[n-1];
	printf("minCount[] is ");
    for(int i=0;i<n;i++){
		printf("%d ", minCount[i]);
	}
	printf("\n");
	output02(str, ppLength, minCount, n-1,n);
	printf("\n");
	
	delete[] minCount;
    minCount = 0;
    for(int i=0;i<n;i++){
		delete[] ppLength[i];
		ppLength[i] = 0;
	}
	delete[] ppLength;
	ppLength =0;
	
	return res;
}

int main(int argc, char* argv[]){
    string str;
    while(1){
		if(getline(cin, str) == 0 || str.empty())
			break;
		splitpalindrome02(str);
    }
    return 0;
}

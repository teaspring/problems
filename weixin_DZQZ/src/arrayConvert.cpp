/*
 * question on Aug23, 
 * both source array [n] and target array[n] have digits 0 - (n-1). Optional operation is swap anyone but 0 with 0.  output the conversion.
 * example: {0,1,2}=>{1,0,2}=>{1,2,0}=>{0,2,1}
 * 
 * my solution is BFS actually
 *
 * test data:
 * {0,1,2} => {0,2,1}
 * {0,3,2,1} => {3,1,2,0}
 */

#include "../header/preliminary.h"
#include <vector>
#include <map>
#include <set>

using namespace std;

size_t findZero(vector<int> vec){
    for(size_t i=0;i != vec.size(); ++i){
	if(vec[i] == 0)
	    return i;
    }
    return vec.size();
}

vector<int> vecSwapOnce(vector<int> src, size_t q, size_t t){
    vector<int> next;
    if(q >= src.size() || t >= src.size())
        return next;
    for(size_t i=0;i<src.size();++i){
        if(i == q)
	    next.push_back(src[t]);
	else if(i==t)
	    next.push_back(src[q]);
	else
            next.push_back(src[i]);
    }
    return next;
}

int compareVector(vector<int>& vec1, vector<int>& vec2){
    if(vec1.size() != vec2.size())	
        return 0;
    for(size_t i=0;i!=vec1.size();++i){
	if(vec1[i] != vec2[i])
	    return 0;
    }
    return 1;
}

void outputVec(vector<int> vec){
    cout<<"[";
    vector<int>::iterator iter = vec.begin();
    for(;iter != vec.end()-1;++iter){
	cout<<*iter<<",";
    }
    cout<<*iter;	
    cout<<"]";
}

void outputRecurve(map<vector<int>, vector<int> > vecMap, vector<int> curr, vector<int> start){
    if(compareVector(curr, start)){
	outputVec(start);
	return;
    }else{
	map<vector<int>, vector<int> >::iterator iter = vecMap.find(curr);
	if(iter == vecMap.end())	return;				//error case
	outputRecurve(vecMap, iter->second, start);
	cout<<"=>";
	outputVec(curr);		
    }
}

void convertArray(int* src, int* tgt, int n){
    map<vector<int>, vector<int> >	statusMap;	//value_type is <current status, parent status>
    set<vector<int> > accessed;					//<set> to record all retrieved status
    vector<int> source, target;
    for(int i=0;i<n;i++){
        source.push_back(src[i]);
	target.push_back(tgt[i]);
    }
    vector<int> zero;
    statusMap[source] = zero;
    map<vector<int>, vector<int> >::iterator iter = statusMap.begin();
    while(iter != statusMap.end()){
	bool found=false;
	size_t k = findZero(iter->first);
	if(k == iter->first.size())	break;
	if(accessed.find(iter->first) != accessed.end()){
	    iter++;
	    continue;
	}
	accessed.insert(iter->first);	
	for(size_t i=0;i != iter->first.size();++i){
	    if(i == k)	continue;
	    vector<int> next = vecSwapOnce(iter->first, k, i);
	    if(compareVector(target, next)){
	    	found = true;
	        break;
	    }
	    if(statusMap.find(next) != statusMap.end())	continue;
	    statusMap[next] = iter->first;
	}
        if(found){
            outputRecurve(statusMap, iter->first, source);
	    cout<<"=>";
	    outputVec(target);
	    break;
	}else{
	    iter = statusMap.begin();		//if map is updated, iterator is reset
	}
    }
    accessed.clear();	
    statusMap.clear();
    source.clear();
    target.clear();
    cout<< endl;
    return;
}

void outArr(int* arr, int n){
    for(int i=0;i<n;++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(int argc, char* argv[]){
    while(1){
    	string	str;
	if(getline(cin, str) == 0)
	    break;
	int* arr1 = new int[str.size()]();
	int length1 = splitStr2IntArray(str, arr1);

	str.clear();
	if(getline(cin, str) == 0)
	    break;
	int* arr2 = new int[str.size()]();
	int length2 = splitStr2IntArray(str, arr2);
	if(length1 != length2){
	    cout<<"input source array and target array uncompatible!"<<endl;
	}else{
	    outArr(arr1, length1);
	    outArr(arr2, length2);
	    convertArray(arr1, arr2, length1);
	}
	delete[] arr1;
	arr1 = 0;
	delete[] arr2;
	arr2 = 0;
    }
    return 0;
}


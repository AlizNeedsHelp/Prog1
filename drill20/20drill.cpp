#include "std_lib_facilities.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <array>
#include <algorithm>


template <typename C>
void print(const C& c) {

	for(auto& i:c){
		cout<<i<<' ';
	}
	cout<<endl;
}
template<typename C>
void inc(C& c, int n){
	for (auto& i:c){
		i+=n;
	}
}


template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()

Iter2 orai_copy(Iter1 f1, Iter1 e1, Iter2 f2){
	for (Iter1 p=f1; p!=e1; ++p){
		*f2=*p;
		f2++;
	}
	return f2;
}

//distance




int main()
try { 
	constexpr int size=10;

	int arr[size];
	for (int i = 0; i <size; ++i)arr[i]=i;
	
	array<int, size> ai;
	copy(arr,arr+size, ai.begin());

	vector<int> vi(size);
	copy(arr,arr+size, vi.begin());

	list<int>li(size);
	copy(arr,arr+size, li.begin());

	///kopizott kopi
	array<int, size> ai2=ai;
	vector<int> vi2=vi;
	list<int>li2=li;
	cout<<".............................."<<endl;
	cout<<"Array,vector,list"<<endl;

	//print('Array,vector,list');
	cout<<"Array :";print(ai2);
	cout<<"Vector :";print(vi2); //kollekció
	cout<<"List :";print(li2);

	cout<<".............................."<<endl;
	cout<<"Array,vector,list megnovelve"<<endl;
	inc(ai2,2);
	inc(vi2,3); //megnövelem a számokat
	inc(li2,5);

	cout<<"Array :";print(ai2);
	cout<<"Vector :";print(vi2);//kiirom
	cout<<"List :";print(li2);

	cout<<".............................."<<endl;
	
	orai_copy(ai2.begin(),ai2.end(),vi2.begin());
	orai_copy(li2.begin(),li2.end(),ai2.begin());
	cout<<"Array,vector,list kopizott"<<endl;

	print(ai2);
	print(vi2); //kopizom az egyiket a masikba
	print(li2);

	//olyan iterator ami inteket tartalmaz
	cout<<".............................."<<endl;
	cout<<"Keressuk a 3 számot a vectorban"<<endl;
	print(vi2); 
	vector<int>::iterator vit; 
	vit=find(vi2.begin(), vi2.end(),3);
	if(vit!= vi2.end()){
		cout<<"Found at:"<<distance(vi2.begin(), vit)<<endl;
	}else{
		cout<<"not found"<<endl; 
	}



}catch(exception & e){

	cerr<<"exception: " << e.what() << endl;
	return 1;

}catch(...){

	cerr << "exception\n";
	return 2;

}



#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <numeric>

template<typename K, typename V>
void print(const std::map<K,V>& m){
	for(auto& i:m){//az auto std:pair<K,V> alkot amiben benne van a kulcs és az érték

		std::cout<<i.first<<'\t'<<i.second<<std::endl;
	}	
}

void read_map(std::map<std::string,int>& m){
	std::string s;
	int i=0;
	while(m.size()<10){
		std::cin>>s>>i;
		//m[s]=i; ez ugyan az mint az alatta levo
		m.insert(std::make_pair(s,i));
	}
}





int main()
try { 


	std::map<std::string,int>msi;
	
	
	msi["a"]=2;
	msi["b"]=18;
	msi["sze"]=67;
	msi["ret"]=68;
	msi["lek"]=69;
	msi["te"]=666;
	msi["pa"]=99;
	msi["raszt"]=420;
	msi["au"]=21;
	msi["an"]=20;


	std::cout<<"....................................."<<std::endl;
	print(msi);
	std::cout<<"....................................."<<std::endl;

	msi.erase("a");
	std::cout<<std::endl<<"Egy elem torlese utan: "<<std::endl;
	print(msi);

	std::cout<<"....................................."<<std::endl;
	msi.erase(msi.begin(),msi.end());
	std::cout<<std::endl<<"Minden elem torlese utan: "<<std::endl;
	print(msi);

	std::cout<<"....................................."<<std::endl;
	std::cout<<"Adj meg ertekpart"<<std::endl;
	read_map(msi);
	print(msi);

//////osszeadas//////

	int sum=0;
	for(std::pair<std::string,int> a:msi){
		sum+=a.second;
	}


	std::cout<<"sum of ints:"<<sum<<std::endl;



	///////////////////////////////////////// string int ből int string
	std::map<int,std::string>mis;
	for(std::pair<std::string,int> a:msi){
		mis[a.second]=a.first;
		mis.insert(std::make_pair(a.second,a.first));
	}
	std::cout<<"....................................."<<std::endl;
	std::cout<<"MIS"<<std::endl;
	print(mis); 

}catch(std::exception & e){

	std::cerr<<"Exception: " << e.what() << std::endl;
	return 1;

}catch(...){

	std::cerr << "Unknown exception\n";
	return 2;

}

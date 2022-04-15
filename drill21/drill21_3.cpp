#include<iostream>
#include<stdexcept>
#include<fstream>
#include<vector>
#include<numeric>
#include<algorithm>

class Less_than{
	double v;
	public:
		Less_than(double vv):v{vv}{}
		bool operator()(const double val){return val <v;}
};


template <typename C>
void print(const C& c, char sep = '\n'){
	std::cout<<"Container elements"<<std::endl;

	for (const auto elem:c){
		std::cout<<elem<<sep<<std::endl;
	}
	std::cout<<std::endl;
}



int main()
try { 

	const std::string iname{ "szamok.txt"};
	std::ifstream ifs{iname};
	if (!ifs) throw std::runtime_error("Could not find file:" + iname);

	std::vector<double> vd;
	for (double d;ifs >> d;){
		vd.push_back(d);
	}
    std::cout<<".............................."<<std::endl;
	print(vd);

	std::vector<int>vi;
	for(auto& i:vd){
		vi.push_back(i);
	}
	//std::copy(vd.begin(),vd.end(),vi.begin());--nem jó mert a vi nek nem akkora a mérete mint a vd 
	print(vi);

	for(int i=0;i<vd.size(); i++){
		std::cout<<vd[i]<<'\t'<<vi[i]<<std::endl;
	}


	double d_sum =std::accumulate(vd.begin(), vd.end(),0.0);
	std::cout<<"Sum of vector<double>:" <<d_sum <<std::endl;

	double i_sum =std::accumulate(vi.begin(), vi.end(),0.0);
	std::cout<<"Sum of vector<double>:" <<i_sum <<std::endl;
/////////////////////////////////////////////////////////////////////////
	//double diff_sum =std::
	//std::cout <<"diff:"<< d_sum -i_sum <<"  "<<diff_sum<<std::endl;

	/*int sum_vi = 0;
    sum_vi = accumulate(vi.begin(),vi.end(),sum_vi);
    cout << "Difference of sum_vd and sum_vi: " << sum_vd - sum_vi << '\n';*/
//////////////////////////////////////////////////////////////////////////
	std::reverse(vd.begin(),vd.end());
	print(vd);

	double vd_mean =d_sum/vd.size();
	std::cout<< "Mean value of this"<<vd_mean<<std::endl;



	std::vector<double> vd2 (vd.size());
	auto it= std::copy_if(vd.begin(),vd.end(),vd.begin(),Less_than(vd_mean));
	vd2.resize(std::distance(vd.begin(), it));

    print(vd2);

    std::sort(vd.begin(),vd.end());
    print(vd);





}catch(std::exception & e){

	std::cerr<<"Exception: " << e.what() << std::endl;
	return 1;

}catch(...){

	std::cerr << "Unknown exception\n";
	return 2;

}
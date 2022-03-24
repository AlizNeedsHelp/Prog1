#include<iostream>
#include<vector>
#include<string>

using namespace std;

template<typename T> //azzá fog valtozni ami meg van adva neki, ha string akkor string ha int akkor int
struct S {
	S(T vv =0):val{vv}{} //azért konstruktor mert ugyan az a neve mint a templatenek
	T& get();
	void set(T new_t) {val=new_t;} 
	void operator=(const T& s);
	const T& get() const;//2resz, ez a fuggveny feje ezt ide bemasoljuk lentrol
	private:
	T val;


};

//2 resz

template<typename T> //ostalyon kivul hoztunk letre fuggvenyt
T& S<T>::get(){
	return val;
}

template<typename T> 
const T& S<T>::get()  const{
	return val;
}
template<typename T>
void S<T>::operator=(const T& s){
	val= s;
}

//3resz
template<typename T> 
void read_val(T& v){
	cin>>v;
}

template <typename T>
ostream& operator<< (ostream& os,vector<T> &vv){
	os <<"{";
	for(int i=0;i<vv.size();++i){
		os<<vv[i]<<(i<vv.size()-1?", ":" ");
		}
	os<<"}"<<endl;
	return os;
} //cout <<vec1<<vec2<<vec3



template <typename T>
istream& operator>> (istream& is, vector<T>& vv){
		char ch=0;
		is>>ch;
		if(ch != '{'){
			is.unget();
			return is;
		}
		for(T val; is>>val;){
			vv.push_back(val);
			is>>ch;
			if(ch != ',')break;
		}
		return is;


}


int main(){
	S<int> s; //S tipusu mind 
	S<int> si {37};
	S<char> sc {'c'};
	S<double> sd{3.2};
	S<std::string> ss{"hello"};
	S<std::vector<int>> svi {std::vector<int> {1,1,2,3,5,8}};//std vector tipust tartalmaz--adattagjának a tipusa vector, de amugy S

	cout<< "S<int> : "<< s.get()<<endl;
	cout<< "S<int> : "<< si.get()<<endl;
	cout<< "S<char> : "<< sc.get()<<endl;
	cout<< "S<double> : "<< sd.get()<<endl;
	cout<< "S<string> : "<< ss.get()<<endl;

	cout<<"S<vector> : ";
	for (auto& a: svi.get()){
		cout<< a<< ' ';
	}
	cout<<endl;

	sc.set('s');
	cout<< "S<char> : "<< sc.get()<<endl;

	sd = 42.1;
	cout<< "S<double> : "<< sd.get()<<endl;

	int ii;
	read_val(ii);
	S<int> si2{ii};

	double dd;
	read_val(dd);
	S<double> sd2{dd};

	string ss2;
	read_val(ss2);
	S<string> str {ss2};

	cout<< "S<int> : "<< si2.get()<<endl;
	cout<< "S<double> : "<< sd2.get()<<endl;
	cout<< "S<string> : "<< str.get()<<endl;

	cout<<"S<vector> : ";
	vector<int> vi2;
	read_val(vi2);
	S<vector<int>> svi2 {vi2};

	cout<< "bbsnddbm:" <<svi.get()<<endl;
}

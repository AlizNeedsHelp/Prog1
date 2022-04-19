#include<iostream>
#include "Matrix.h"
#include<iomanip>
#include<cmath>
#include<complex>
#include<cerrno>
#include "MatrixIO.h"



using namespace std;
using namespace Numeric_lib;



int main()
try { 

	cout<<"Size of: \n";

	cout<<"char \t"<<sizeof(char)<< '\n';
	cout<<"short\t"<<sizeof(short)<< '\n';
	cout<<"int \t"<<sizeof(int)<< '\n';
	cout<<"long \t"<<sizeof(long)<< '\n';
	cout<<"float \t"<<sizeof(float)<< '\n';
	cout<<"double \t"<<sizeof(double)<< '\n';
	cout<<"int* \t"<<sizeof(int*)<< '\n';
	cout<<"double* "<<sizeof(double*)<<'\n';


	cout<<"Matrix meretek \n";
	Matrix<int> a(10);

	Matrix<int> b(100);

	Matrix<double> c(10);

	Matrix<int,2> d(10,10);

	Matrix<int,3> e(10,10,10);


	
	cout<< "1d int 10 \t\t"<<sizeof(a)<<'\n';
	cout<< "1d int 100 \t\t"<<sizeof(b)<<'\n';
	cout<< "1d double 10 \t\t"<<sizeof(c)<<'\n';
	cout<< "2d int 10*10 \t\t"<<sizeof(d)<<'\n';
	cout<< "3d int 10*10*10 \t"<<sizeof(e)<<'\n';

	cout<<"\n Number of elements: \n";
	cout<<"a: \t"<<a.size()<<'\n';
	cout<<"b: \t"<<b.size()<<'\n';
	cout<<"c: \t"<<c.size()<<'\n';
	cout<<"d: \t"<<d.size()<<'\n';
	cout<<"e: \t"<<e.size()<<'\n';

	cout<<"Enter int:";
	while (cin>> szam) {
		errno=0;
		double d= sqrt(szam);
		if (errno == EDOM){
			cout<<"Valasszon masik szamot";
		}
		else{ 
				cout<<"Gyök"<<d<< endl; }
}


 	cin.clear();
 	cin.ignore();

 	cout<<"Enter 10 floats";
 	Matrix<double> m2(10);
 	double d2;
 	for (int i = 0; i <m2.size(); ++i)
 	{
 		cin>>d2;
 		if(!cin) throw runtime_error("Problem reading from cin ");
 		m2[i]=d2;
 	}
 	cout<< "Matrix:"<<m2<<'\n';

 	cout<<"Multiplication table:"<<endl;
 	int m;
 	int n;
 	cout<<"Enter n:";
 	cin>>n;
 	cout<<"Enter m:";
 	cin>>m;

 	for (int i = 1; i < n+1; ++i)
 	{
 		for (int j = 1; j < m+1; ++j)
 		{
 			cout<< i*j<<'\t';
 		}
 		cout<<endl;
 	}

 	Matrix<complex<double>>mcomp(10);
 	cout<<"Enter 10 complex numbers like (0,0): ";
 	complex<double> comp;
 	for (int i = 0; i < 10; ++i)
 	{
 		cin>>comp;
 		if(!cin) throw runtime_error("Problem reading from cin ");
 		mcomp[i]=comp;
 	}

 	complex<double> sum;
 	for (Index i = 0; i < mcomp.size(); ++i)
 	{
 		sum+=mcomp[i];
 	}
 	cout<<"Sum:"<<sum<<'\n';





 	Matrix<int,2> m(2,3);
    cout << "\nEnter six ints: ";
    int n;
    for (int i = 0; i<m.dim1(); ++i)
        for (int j =0 ; j<m.dim2(); ++j) {
            cin >> n;
            m(i,j) = n;
        }
    cout << "Matrix:\n" << m << '\n';



}catch(exception & e){

	cerr<<"Exception: " << e.what() << endl;
	return 1;

}catch(...){
	cerr << "Unknown exception\n";
  return 2;
}

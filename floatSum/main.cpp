#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<ctime>
#include <chrono>

using namespace std;
const long max=30000;
long double sumRec=0;

float RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

long double KahanSum(vector<float> &vec)
{
    long double sum = 0.0;
    long double c = 0.0;
    long double y;
    long double t;
  for(float i=0; i <= vec.size()-1; i++)
  {
    y = vec.at(i)-c;
    t = sum + y;
    c = (t - sum) - y;
    sum = t;
  }
  return sum;
}
long double RegSum(vector<float> &vec)
{
    long double sum=0.0;
    for (float i=0; i<=vec.size()-1;i++)
    {
        sum+=vec.at(i);
    }
    return sum;
}

long double recSum(vector<float> &vec)
{
    if (!vec.empty())
    {
    	sumRec+=vec.at(vec.size()-1);
  		vec.pop_back();
        recSum(vec);
	}
    return sumRec;
}


int main()
{
    vector <float> vec;
    vector <float> :: iterator i;
    for (int i = 1; i <=30000; i++)
    {
		vec.push_back(RandomFloat(100,500));
	}
	/*
	cout << "Output of begin and end\t:\t";
    for (i = vec.begin(); i != vec.end(); ++i)
        cout << *i << '\n';
    */
    auto start = chrono::high_resolution_clock::now();
   	cout << "Output of sum by Regular method"<<endl;
    cout<<RegSum(vec)<<endl;
    auto end1 = chrono::high_resolution_clock::now();
    auto diff = end1 - start;
    cout <<"Time elapsed: "<< chrono::duration <double, nano> (diff).count() << " ns\n" << endl;




    start = chrono::high_resolution_clock::now();
    cout << "Output of sum by Kahan Algorithm"<<endl;
    cout<<KahanSum(vec)<<endl;
    end1 = chrono::high_resolution_clock::now();
    diff = end1 - start;
    cout <<"Time elapsed: "<< chrono::duration <double, nano> (diff).count() << " ns\n" << endl;


    start = chrono::high_resolution_clock::now();
    cout << "Output of sum by Recursiv method"<<endl;
    cout<<recSum(vec)<<endl;
    end1 = chrono::high_resolution_clock::now();
    diff = end1 - start;
    cout <<"Time elapsed: "<< chrono::duration <double, nano> (diff).count() << " ns\n" << endl;


    return 0;

}


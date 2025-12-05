#ifndef STATS_H
#define STATS_H

#include <vector>
//Darien Hector
using namespace std;

template <typename T>

class Stats{
	private:
		vector<T> data;
	public:
		Stats(){}
		
		//adds the data to the vector to be stored
		void add(const T& value){
			data.push_back(value);
		}	
		
		int size() const{
			return static_cast<int>(data.size());
		}
		
		//shows the minimum amount of scoops sold of  a flavor
		T min() const{
			T m = data[0];
			for(int i =1;i<size();++i){
			
				if(data[i]<m){
					m = data[i];
				}	
		}
		return m;
	}
	
	//shows the max amount of ice cream sold of a flavor
	T max() const{
			T m = data[0];
			for(int i =1;i<size();++i){
			
				if(data[i]>m){
					m = data[i];
				}	
		}
		return m;
	}
	
	//shows the total amount spent for an ice cream flavor
	T sum() const{
		T s =0;
		for(int i=0; i<size();++i){
			s = s+data[i];
		}
		return s;
	}
	const vector<T>& getdata() const{
		return data;
	}	
	
};
#endif
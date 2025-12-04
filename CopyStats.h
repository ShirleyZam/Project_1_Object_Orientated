#ifndef STATS_H

 #define STATS_H
 
#include <vector>

 using namespace std;
 
template <typename T>

 class Stats {

 private:

     vector<T> data;
 
public:

     Stats() {}
 
    void add(const T& value) {

         data.push_back(value);

     }
 
    int size() const {

         return static_cast<int>(data.size());

     }
 
    T min() const {

         T m = data[0];

         for (int i = 1; i < size(); ++i) {

             if (data[i] < m) {

                 m = data[i];

             }

         }

         return m;

     }
 
    T max() const {

         T m = data[0];

         for (int i = 1; i < size(); ++i) {

             if (data[i] > m) {

                 m = data[i];

             }

         }

         return m;

     }
 
    T sum() const {

         T s = 0;

         for (int i = 0; i < size(); ++i) {

             s = s + data[i];

         }

         return s;

     }
 
    const vector<T>& getdata() const {

         return data;

     }

 };
 
#endif // STATS_H

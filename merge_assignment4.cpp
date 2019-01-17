#include<iostream>
#include<fstream>
using namespace std;
#include "apvector.h"

void readInArrays( apvector<int> &a, apvector <int> &b);
void merge(int, int, int, apvector<int>, apvector<int>, apvector<int>);

int main()
{
    apvector<int> a,b,c;
    
    readInArrays( a, b );    
    
    int lenOfa = a.length();
    int lenOfb = b.length();  
    
    //for (int i = 0; i < a.length(); i++)
        //cout << a[i];  
        
    
    
    int i, j, k = 0;

    //merge(i, j, k, a, b, c);       
    

    system("pause");
    return 0;
}

void readInArrays( apvector<int> &a, apvector <int> &b){
     ifstream infile1("List21.txt");
     ifstream infile2("List22.txt");
     int LenOfa = 0, LenOfb = 0;
     
     int i, j =0;
     
     while (infile1.good()){
         infile1 >> a[i];
         infile1.ignore();
         i++;
         }
     a.resize(i-1);
     
     while (infile2.good()){
         infile2 >> b[j];
         infile2.ignore();
         j++;
         }
     b.resize(j-1);
     
     infile1.close();
     infile2.close();
}

void merge(int i, int j , int k, apvector<int> &a, apvector<int> &b, apvector<int> &c) {
        if (a[i] <= b[j]) {
           c[k] = a[i];
           merge(i++, j, k++, &a, &b, &c);
            }
        else {
             c[k] = b[j];
             merge(i, j++, k++, a, b, c);
             }    
        cout << c[k];
        }

/*Iona Buchanan
Merge sort*/

#include<iostream>
#include<fstream>
using namespace std;
#include "apvector.h"

void readInArrays( apvector<int> &a, apvector <int> &b);
void echoArray( const apvector<int> &a);


int main()
{
    apvector<int> a(1000), b(1000), c(1000);
   
    readInArrays(a, b );    
    
    system("pause");
    
    cout << "Sorted list" << endl;
    
    int i = 0; 
    int j = 0;

    for (int k = 0; k < (a.length() + b.length()-2); k++) {
		    if (a[i] <= b[j]) {
                 c[k] = a[i];
                 i++;
            }
            else if (a[i] > b[j]) {
                 c[k] = b[j];
                 j++;
             }    
        cout << c[k] << endl;
        }

    system("pause");
    return 0;
}

void readInArrays( apvector<int> &a, apvector <int> &b){
     ifstream infile1("List1.txt");
     ifstream infile2("List2.txt");
     int i = 0;
     
     if (! infile1.good() || ! infile2.good()) {
        cout << "Unable to open files" << endl;
        system("pause");
     }
     ;
     while (infile1.good()) {
        infile1 >> a[i++];
     }   
     a.resize(i-1);
     cout << "Sorted List A" << endl;
     echoArray(a); 
   
     i = 0;
     while (infile2.good()) 
        infile2 >> b[i++];
     b.resize(i-1);   
     cout << "Sorted List B" << endl;
     echoArray(b); 
     infile1.close();
     infile2.close();
}

void echoArray( const apvector<int> &a) {
    for (int i = 0; i< a.length(); i++)
        cout << a[i] << endl;
     
}


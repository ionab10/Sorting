/*Iona Buchanan
Merge sort*/

#include<iostream>
#include <cstdlib>
#include <math.h>
#include <stdlib.h> 
#include <time.h> 
#include <allegro.h>

using namespace std;
#include "apvector.h"

void generateArray(apvector<int> &a);
void echoArray( const apvector<int> &a);
void mergeSort(apvector<int> &a, int start, int end);
void merge(apvector<int> &a, int start, int mid, int end);
void bubble(apvector<int> &a);
void quicksort(apvector<int> &a, int left, int right);
void selectionSort(apvector<int> &a);
void insertionSort(apvector<int> &a);
void display(apvector<int> &a, int shape);

int shape = 0;
BITMAP *buffer;


int main() {
	
// Allegro  initialization
    allegro_init();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 640, 0 , 0);
    install_keyboard();
    
    buffer = create_bitmap(640, 640);
    
    apvector<int> a(640);
    generateArray(a); 
    
    int sort = 0;
    
    cout << "To sort:" << endl;
    cout << "dots: enter 0" << endl;
    cout << "lines: enter 1" << endl;
    cout << "rectangles: enter 2" << endl;
    cin >> shape;
    
    if (shape == 2)
       a.resize(160);
    
   display (a, shape);
    
    cout << "\nMerge sort: enter 0" << endl;
    cout << "Bubble sort: enter 1" << endl;
    cout << "Quicksort: enter 2" << endl;
    cout << "Selection sort: enter 3" << endl;
    cout << "Insertion sort: enter 4" << endl;
    cin >> sort;
    
    switch (sort) {
    	case 0:
			mergeSort(a, 0, a.length()-1);
    		break;
		case 1:
			bubble(a);
			break;
		case 2:
			quicksort(a, 0, a.length()-1);
			break;
		case 3: 
			selectionSort(a);
			break;
		case 4: 
			insertionSort(a);
			break;
	}
    
    cout << "Sorted list" << endl;
    echoArray(a);

    system("pause");
    return 0;
}
END_OF_MAIN()

void generateArray( apvector<int> &a){
     for (int i = 0; i < 640; i++)
        a[i] = rand() % 640;
     cout << "List" << endl;
     echoArray(a); 
}

void echoArray( const apvector<int> &a) {
    for (int i = 0; i < a.length()-1; i++)
        cout << a[i] << endl;
     
}

void mergeSort(apvector<int> &a, int start, int end) {
     if (start < end - 1) {
	 	int mid = (start + end)/2;
               
        mergeSort (a, start, mid);              //split
        mergeSort (a, mid, end);                 //split
               
    	merge(a, start, mid, end);                     //merge
    }
}

void merge(apvector<int> &a, int start, int mid, int end) {             
     apvector<int> b;
     b.resize(end - start);
     int i = start;
     int j = mid;
     
     for (int k = 0; k < b.length(); k++) {
		    if (j >= end || (i < mid && a[i] <= a[j])) {                 //if smallest,
                 b[k] = a[i];                                            //add into sorted array
                 i++;
            }
            else {
                 b[k] = a[j];
                 j++;
             }    
        //cout << b[k] << endl;
        }
        
     for (int k = start; k < end; k++)
         a[k] = b[k-start];

         display (a, shape);
         
}

void bubble(apvector<int> &a) {
	for (int j = 0; j < a.length(); j++) {
		for (int i = 0; i < a.length()-1; i++) {
			if (a[i] > a[i+1]) {               //if in wrong order,
				swap(a[i], a[i+1]);            //swap places
                display (a, shape);
			}
		}
	}
}

void quicksort(apvector<int> &a, int left, int right) {
      int i = left;
	  int j = right;

      int temp;

      int pivot = a[(left + right) / 2];       //pivot middle

      while (i <= j) {
            while (a[i] < pivot)
                  i++;
            while (a[j] > pivot)
                  j--;
            if (i <= j) {
                  swap(a[i], a[j]);           //swap sides
                  i++;
                  j--;
            }
      }
      
      if (left < j)
            quicksort(a, left, j);
      if (i < right)
            quicksort(a, i, right);
      
      display (a, shape);

}

void selectionSort(apvector<int> &a) {
	int i,j,min;
	
	for (j = 0; j < a.length()-1; j++) {
    	min = j;
    	for ( i = j+1; i < a.length(); i++) {
        	if (a[i] < a[min])              //find min
            	min = i;
    	}
    	if (min != j) {
        	swap(a[j], a[min]);        //swap smallest into next place
            display (a, shape);
            }
	}
}

void insertionSort(apvector<int> &a) {
     for (int i = 1; i < a.length(); i++) {
         int key= a[i];
         for (int j = i-1; (j>=0) && (a[j] > key); j--) {        //find right place
             swap(a[j+1],a[j]);                                    //insert
                display (a, shape);
             }
        } 
}

void display(apvector<int> &a, int shape) {
     clear(buffer);
     for (int i = 0; i < a.length(); i++) {
     	if (shape == 0)
     		putpixel(buffer, i, a[i], makecol(255, 255, 255));
		else if (shape == 1) 
			line(buffer, i, 0, i, a[i], makecol(255 - a[i], 255 - (a[i]/3), 255));
		else if (shape == 2) 
			rectfill(buffer, 4*i, 0, 4*i+4, a[i], makecol(255 - a[i], 255 - (a[i]/2), 255 - (a[i]/5)));
     }
     blit(buffer, screen, 0, 0, 0, 0, 640, 640);
}
     
     


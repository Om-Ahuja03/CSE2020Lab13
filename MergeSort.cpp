#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
using namespace std;

template <typename C>
void mergeSort( vector<C>& v );

template <typename C>
void mergeSort( vector<C>& v, vector<C>& tmp, int left, int right);

template <typename C>
void merge(vector<C>& v, vector<C>& tmp, int leftPos, int rightPos, int righEnd);

 template <typename C>
 void mergeSort( vector<C>& v )
{
  vector<C> tmp( v.size( ) );
  mergeSort( v, tmp, 0, v.size( ) - 1 );
}
template <typename C>
void mergeSort( vector<C>& v, vector<C>& tmp, int left, int right )
{    
  if( left < right )
  {      
    int center = ( left + right ) / 2;        
      mergeSort( v, tmp, left, center );
      mergeSort( v, tmp, center + 1, right );        
      merge( v, tmp, left, center + 1, right );    
  }
}

template <typename C>
void merge( vector<C>& v, vector<C>& tmp,int leftPos, int rightPos, int rightEnd)
{
  int leftEnd = rightPos - 1;
  int tmpPos = leftPos;
  int numElements = rightEnd - leftPos + 1;

  while( leftPos <= leftEnd && rightPos <= rightEnd )
    if( v[ leftPos ] <= v[ rightPos ] )
      tmp[ tmpPos++ ] =  v[ leftPos++ ];
    else
      tmp[ tmpPos++ ] =  v[ rightPos++ ];
  while( leftPos <= leftEnd )    
    tmp[ tmpPos++ ] = v[ leftPos++ ];
  while( rightPos <= rightEnd )  
    tmp[ tmpPos++ ] = v[ rightPos++ ];
  for( int i = 0; i < numElements; ++i, --rightEnd )
    v[ rightEnd ] = tmp[ rightEnd ];
}
#endif
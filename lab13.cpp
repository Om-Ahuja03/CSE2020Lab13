#include <fstream>
#include "MergeSort.cpp"
#include <iostream>

int main()
{
  vector<int> vec;
  
  ifstream input("sort.txt");
  int num;
  while(input >> num)
  {
      vec.push_back(num);
  }
  input.close();

  mergeSort(vec);
  
  cout << "\nThe merge sort: " << endl;
  for(unsigned int i = 0; i < vec.size(); i++)
  {
      cout << vec[i] << " ";
  }
  cout << endl;
  
  return 0;
}
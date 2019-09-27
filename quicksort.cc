#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void print(vector<int> &V)
{
  for(auto i : V)
  cout<<i<<" ";
  cout<<endl;
}
int partition(vector<int>& V,int left,int right)
{
  int partition_index=left;
  int pivot_element = V[right];
  for(int i=left;i<=right;i++)
  {
    if(V[i]<pivot_element)
    {
      swap(V[i],V[partition_index]);
      partition_index++;
    }
  }
  swap(V[right],V[partition_index]);
  return partition_index;
}
void quickSort(vector<int>& V, int left, int right)
{
  if(left>=right)
  return;
  int partition_index = partition(V,left,right);
  quickSort(V,left,partition_index-1);
  quickSort(V,partition_index+1,right);
}
int main()
{
  ofstream ofile;
  ofile.open("output.txt");
  int num_elements = 0;
  int num_samples = 0;
  cout<<"Enter number of elements: ";
  cin>>num_elements;
  cout<<"Enter number of sample: ";
  cin>>num_samples;
  unsigned int seed = 0;
  vector<int> V(num_elements,0);
  for(int i=0;i<num_elements;i++)
  {
    V[i] = i;
  }

  for(int i=0;i<num_samples;i++)
  {
    // print(V);
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(V,0,V.size()-1);
    // print(V);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<microseconds>(stop - start);
    ofile<<duration.count()<<endl;
    shuffle(V.begin(), V.end(), default_random_engine(seed));
    //print(V);
  }
  ofile.close();
}

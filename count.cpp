#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<time.h>
using namespace std;
int partition(int *a,int i,int j)
{
    if(j-i>=3)
    {
    int change;
    int mid=(i+j)/2;
     if(a[i]>=a[mid]&&a[i]<=a[j])
     {
           
    }else if(a[mid]>=a[i]&&a[mid]<=a[j])
    {
         change=a[mid];
         a[mid]=a[i];
         a[i]=change;        
    } else
    {
         change=a[j];
         a[j]=a[i];
         a[i]=change;
     }
    }
    int key=a[i];
    while(i<j)
    {    
          while(i<j&&key<=a[j])
          {
                j--;
          }
          a[i]=a[j]; 
	  while(i<j&&key>=a[i])
          {
             i++;
          } 
          a[j]=a[i];  
    }
    a[i]=key;
    return i;  
}
int quikSortfind(int *a,int low,int high,int order)
{
    if(order>high)
    {
       return -1;
    }
       int pos=partition(a,low,high);
       if(pos==order)
        return a[pos];
       else if(pos>order)
        return  quikSortfind(a,low,pos-1,order);
       else
        return  quikSortfind(a,pos+1,high,order);
}
int main()
{
     ifstream fin("E:dataset\\Sort_data\\random.txt");        
     int *number=new int[1000000];
     int j=0;
     while(fin>>number[j])
     {
         j++;           
     }  
	 int order;
     cout<<"请输入要查找的第i大的数:";
     cin>>order;
     clock_t start=clock();

     cout<<quikSortfind(number,0,j-1,order)<<" "; 
     clock_t end=clock();
     cout<<"时间为：  "<<(double)(end - start)<<"ms";
}

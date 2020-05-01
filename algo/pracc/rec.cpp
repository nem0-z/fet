#include <iostream> 
using namespace std; 
   
int fun(int a[],int n) 
{ 
  int x; 
  if(n == 1) 
    return a[0]; 
  else
    x = fun(a, n - 1); 
  if(x > a[n - 1]) 
    return x; 
  else
    return a[n - 1]; 
} 

int fun(int i) 
{ 
  if (i % 2) return (i++); 
  else return fun(fun(i - 1)); 
} 
  
int main() 
{ 
  int arr[] = {12, 10, 30, 50, 100}; 
  cout << " " << fun(arr, 5) <<" "; 

   cout << " " << fun(200) << " "; 

  return 0; 
} 

//fun(arr,5) poziva:

//x = fun(arr,4) poziva:

	//x = fun(arr,3) poziva:
	
		//x = fun(arr,2) poziva:

			//x = fun(arr,1) vraca 12
			

       //je li 12 > a[1] tj 10, jest, vrati x
       // vraceno 12, je li 12 > a[2] tj 30 nije, vrati a[2]
       
    // vraceno 30, je li 30 > a[3] tj 50 nije vrati a[3]
    
//vraceno 50, je li 50>a[4] tj 100 nije vrati a[4]

//end

//fun(200)

	//200%2 je 0, znaci vrati fun(fun(199))
			//fun(199) -> 199%2 je 1, vrati 200
	//fun(200)
//ok nemam blage		



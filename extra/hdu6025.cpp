#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int a[100001], pre[100001], nxt[100001];


int gcd(int l, int r){
    return r==0? l: gcd(r, l%r); 
}

int get_max_gcd(int len){
    sort(a, a+len);
    memset(pre, 0, sizeof(int)*len);
    memset(pre, 0, sizeof(int)*len);
    pre[0] = a[0];
    nxt[len-1] = a[len-1];
    for(int i = 1; i< len ; i++){
        pre[i] = gcd(a[i], pre[i-1]);
        nxt[len-1-i] = gcd(a[len-1-i], nxt[len-i]);
    }

    int ans = max(nxt[1], pre[len-2]);

    for(int i = 1;i<len-1;i++){
        int tmp = gcd(pre[i-1], nxt[i+1]);
        if(ans < tmp)
            ans = tmp;
    }
    return ans;
}

//int main(){
    //int n;

    //cin>>n;
    //while(n--){
        //int len;
        //cin>>len;
        //int size = len;

        //while(size--){
            //cin >> a[size]; 
        //}
        
        //cout<<get_max_gcd(len)<<endl;
    //}

//}


using namespace std;    
const long N = 1000000;   
const long NN = 1000000;
int prime[N] = {0},num_prime = 0;    
bool isNotPrime[NN] = {true, true};   
int main()    
{     
     	for(long i = 2 ; i < NN ; i ++)       
       	{            
		    if(! isNotPrime[i])               
	 		    prime[num_prime ++]=i;  
		//关键处1        
		for(long j = 0 ; j < num_prime && i * prime[j] <  N ; j ++)
    		{               
		      	isNotPrime[i * prime[j]] = true;  
	  		if( !(i % prime[j] ) )  //关键处2                  
				break;           
		}        
	}        
	return 0;   
}

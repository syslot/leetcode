//
// Created by syslot on 2019/9/16.
//

#include "../common.h"

class Solution1{
public:
    string getPermutation(int n, int k) {
        int arr[n];
        for(int i = 0;i<n;i++)
            arr[i] = i;
        this->n = n;
        perm(arr, 0);
    }

    void perm(int *arr, int l){
        if(l == this->n -1){
            for(int i = 0;i<this->n;i++)
                cout << arr[i] << " ";
            cout << endl;
            return;
        }else if(l >= this->n)
            return;


        for(int i = l; i< this->n ;i++){
            swap(arr[i],arr[l]);
            perm(arr, l+1);
            swap(arr[i], arr[l]);
        }
    }

    int n;
};

class Solution{
public:
    string getPermutation(int n, int res){
        char arr[n];
        for(int i=0;i<n;i++){
            arr[i]=i + '1';
        }
        this->n = n;
        sum[0] =1;
        for(int i = 1;i<=n;i++)
            sum[i] = sum[i-1] * i;
        if(res > sum[n])
            return "";
        return perm(arr, res, 0);
    }


    string perm(char * arr, int res, int l){
        if(l == this->n-1) {
            string s;
            for (int i = 0; i < this->n; i++)
                s+=arr[i];
            return s;
        }
        for(int i = l;i<this->n;i++){
            if(res > sum[this->n-l-1]){
                res -= sum[this->n-l-1];
                continue;
            }
            swap(arr[i], arr[l]);
            sort(arr+l+1, arr+this->n);
            return perm(arr, res, l+1);

        }

    }

    int sum[10];
    int n;
};

int main(){
    auto n=3, k =3;
    Solution s;
    cout << s.getPermutation(n, k) << endl;
}

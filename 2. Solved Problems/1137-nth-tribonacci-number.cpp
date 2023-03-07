class Solution {
public:
    int tribo(vector<int>& arr, int i, int n){
        if(i == n){
            return arr[i-1] + arr[i-2] + arr[i-3];
        }
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
        return tribo(arr, i+1, n);
    }
    int tribonacci(int n) {
        // Iterative Solution->
        // vector<int> arr(38,0);
        // arr[0]=0;arr[1]=1;arr[2]=1;
        // for(int i = 3; i <=n ; i++)
        // {
        //     arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
        // }
        // return arr[n];

        // Recursive Solution + Dynamic Programming->
        if(n==0){
            return 0;
        }
        if(n==1 || n==2){
            return 1;
        }

        vector<int> arr(38,0);
        arr[0] = 0, arr[1] = 1, arr[2] = 1;
        return tribo(arr, 3, n);
    }
};
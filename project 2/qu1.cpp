#include <iostream>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;
int main() {
    int n;
    scanf("%d" , &n);
    int sequel[n];
    for (int i =0 ; i< n ; i++){
        scanf("%d" , &sequel[i]);
    }
    stack<int> stack;
    int days[n+1];
    for (int i =0; i<n ; ++i){


            int m =0;
            while (! stack.empty()
            && sequel[i] > stack.top()){
                m = max ( m , days[stack.top()]);
                stack.pop();
            }
            if (stack.empty()){
                stack.push(sequel[i]);
                days[stack.top()] = 0;
            }
            else {
                stack.push(sequel[i]);
                days[stack.top()] = m +1;
            }



    }
    int result = days[1] ;
    for (int i =1 ; i< n+1 ; ++i){
        if (days [i] > result){
            result = days[i];
        }
    }
    printf("%d \n" , result);
    return 0;
}

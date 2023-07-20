#include <iostream>

int main() {
    long int n ;
    scanf("%ld" , &n);
    long long int k ;
    scanf("%lld" , &k);
//    printf("%d\n" , n);
    long long int elements[n] ;
//    printf("%d \n", sizeof(elements));
    for (int i=0 ; i<n ; i++){
        scanf("%lld" , &elements[i]);
//        printf("koskhol \n");
    }
//    printf("%d \n",elements[20]);
//    printf("%d\n" , n);
//    printf("%d \n" , k);
//    printf("%d \n", sizeof(elements));
    long int counter =0 ;
    long int toCheck =0 ;
    int pi = 0;
    long int s = 0;
    for ( int i=0 ; i<n; ++i){
//        toCheck =0;
        for (int p = pi; p <= n; ++p) {
            if (s + elements[i] <= k ){
                counter = counter + i - pi +1 ;
                s += elements[i];
                pi=p;
//                i ++;
                break;
            } else{
//                if (i == 0){
//
//                }
                if (i != 0 && p<=i){
                    s -= elements[pi];
                    pi += 1;
                    continue;
                }
            }
        }
    }
    printf("%ld",counter);
}

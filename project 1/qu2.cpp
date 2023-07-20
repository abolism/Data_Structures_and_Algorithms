#include <stdio.h>
long int sumOfElements(long long int elements[] , int i , int j){
    if (i==j){
        return elements[i];
    }
    return sumOfElements(elements,i,j-1)+elements[j];
}
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
    for ( int i=0 ; i<n; ++i){
        toCheck =0;
        for ( int j=i ; j<n ; ++j){
            toCheck += elements[j];
//            if(sumOfElements(elements, i, j)<= k){
//                counter ++;
//            }
            if (toCheck <= k){
                counter ++;
            }

        }
    }
    printf("%ld",counter);
}

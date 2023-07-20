
#include <iostream>
using namespace std;
#include <math.h>

int hashFunc(char i){
    return ((int)i) - 96;
}

int main() {
//    std::cout << "Hello, World!" << std::endl;
//    char n = 'a';
//    printf("%d ",(int)n);
    int n;
    scanf("%d",&n);
    string inputs[n];

    for (int i = 0; i < n; ++i) {
        cin >> inputs[i];
    }
//    for (int i = 0; i < n; ++i) {
//        int counter =0;
//        string toLookAt = inputs[i];
//
//        for (int j = 0; j < (toLookAt.size()-1)/2; ++j) {
//            int size = toLookAt.size();
//            int a=0;
//            int b=0;
//            if (toLookAt[j] == toLookAt[size-1]){
//                a = a*29 + toLookAt[j];
//                b += toLookAt[size-1-j]*pow(29,j);
//                while (a!=b){
//                    continue;
//                }
////                int size = toLookAt.size();
//                if (j==0){
//                    toLookAt.erase(j);
//                    toLookAt.erase(size-1);
//                    counter += 2;
//                    continue;
//                } else{
//                    if (j==(size-1)/2){
//                        counter += 2;
//                        break;
//                    } else{
//                        counter += 2;
//                        toLookAt.erase(0,j);
//                        toLookAt.erase(size-j-1,size-1);
//                        continue;
//                    }
//                }
//            }
//            cout<<counter;
//        }
//    }
//    for (int i = 0; i < n; ++i) {
//        cout << inputs[i]<< "\n";
//    }

    for (int i = 0; i < n; ++i) {
//        long long int j =0;
        string str = inputs[i];
        long long int size = str.size();
        long long int a =0;
        long long int b =0;
//        int reduce =0;
        long long int counter =0;
        long long int power=1;
        for (long long int j = 0; j <= floor((size-1)/2) ; ++j) {
            a=(a*29+hashFunc(str[j]))%20000003;
            b=(b+ hashFunc(str[(size-1)-j])* power)%20000003;
            power = (power*29)%20000003;
            if (a==b){
                if (size%2==0){
                    a = 0;
                    b = 0;
                    power = 1;
                    counter += 2;
                    continue;
                }
                else {
                    if (j == (size - 1) / 2) {
                        counter++;
                        break;
                    } else {
                        if (j == ceil((size - 1) / 2)) {
                            counter += 1;
                            break;
                        } else {
                            a = 0;
                            b = 0;
                            power = 1;
                            counter += 2;
                            continue;
                        }
                    }
                }
            } else{
                if (j==floor(size-1)/2){
                    counter+=1;
                    break;
                }
                else{

                    if (j == floor((size-1)/2)){
                        counter+=1;
                        break;
                    } else {
                        continue;
                    }
                }
            }
//            if ((a!=b || a==0) && j<floor((size-1)/2)){
////                j++;
//                continue;
//            } else if (j== floor((size-1)/2)){
//                counter++;
//                break;
//            }else if(a==b && a!=0){
//                a=0;
//                b=0;
//                power=0;
////                reduce=j+1;
//                counter +=2;
////                str.erase(0,j+1);
////                str.erase(size-1-j,size);
//                if (str.length() == 0){
//
//                    break;
//                }
//                else {
////                    j++;
////                    size = str.size();
//                    continue;
//                }
//            }
//            j++;
//            size = str.size();

        }
//        while (j <=floor((size-1)/2)){
////            str = inputs[i];
////            int k=j-reduce;
//
////            while((a!=b || a==0) && j!= ceil((size-1)/2)){
//            a=a*29+hashFunc(str[j]);
//            b=b+ hashFunc(str[(size-1)-j])* pow(29,power);
//            power++;
//            if ((a!=b || a==0) && j<floor((size-1)/2)){
//                j++;
//                continue;
//            } else if (j== floor((size-1)/2)){
//                counter++;
//                break;
//            }else if(a==b && a!=0){
//                a=0;
//                b=0;
//                power=0;
////                reduce=j+1;
//                counter +=2;
////                str.erase(0,j+1);
////                str.erase(size-1-j,size);
//                if (str.length() == 0){
//
//                    break;
//                }
//                else {
//                    j++;
////                    size = str.size();
//                    continue;
//                }
//            }
//            j++;
////            size = str.size();
//        }
        cout << counter << "\n";
        continue;
    }

    return 0;
}
#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    int m;
    cin >> n;
    cin >> m;
    map<int , char> positionToDirection;
    map<int , int> positionToAnswer;
    for (int i = 0; i < m; ++i) {
        int c,r;
        char d;
        scanf("%d %d %c" , &c,&r,&d);

        if (positionToDirection.find(c)->second != positionToDirection.end()->second) {
//            positionToAnswer.insert({c,0});
//            int result = positionToAnswer.lower_bound(c)->second;
//            printf("%d\n", result);
            int zero =0;
            printf("%d\n",zero);
        }
        else{
            if (d == 'L') {
                positionToDirection.insert({c,d});
                auto lowerBound = positionToDirection.lower_bound(c);
                if (positionToDirection.begin() == lowerBound) {
                    positionToAnswer.insert({c, c});
                } else {
                    lowerBound--;
                    if ((*lowerBound).second== 'U') {
                        positionToAnswer.insert({c, c - (*lowerBound).first});
                    } else {
                        positionToAnswer.insert({c, c - (*lowerBound).first +
                                                    positionToAnswer.find((*lowerBound).first)->second});
                    }
                }
            } else {
//                positionToAnswer.end()->first < c
                if (positionToDirection.upper_bound(c)->second == 0) {
                    positionToAnswer.insert({c, r});
                } else {
                    if (positionToDirection.upper_bound(c)->second == 'L') {
                        positionToAnswer.insert({c, positionToAnswer.upper_bound(c)->first - c});
                    } else {
                        positionToAnswer.insert({c, positionToAnswer.upper_bound(c)->first - c +
                                                    positionToAnswer.upper_bound(c)->second});
                    }
                }
                positionToDirection.insert({c,d});
            }
            int result = positionToAnswer.lower_bound(c)->second;
            printf("%d\n", result);
        }
    }
    return 0;
}

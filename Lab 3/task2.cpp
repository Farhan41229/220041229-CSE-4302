#include<bits/stdc++.h>
using namespace std;

class RationalNumber {
    private:
        int numerator;
        int denominator;

    public:
        void assign(int num,int denom) { 
            if (denom == 0 ){
                cout<<"You can not assign 0 as denominator"<<endl;
                return;
            }

            else{
                numerator = num;
                denominator = denom;
            }
        }

        float convert() {
            return numerator/denominator;
        }

        void invert(){
            if (numerator == 0 ){
                cout<<"You can not assign 0 as denominator. Inversion Failed"<<endl;
                return;
            }
            else{
                swap(numerator,denominator);
            }
        }

        void print(){
            cout<<"The Rational Number is "<<numerator<<"/"<<denominator<<endl;
        }



};


int main(){

}
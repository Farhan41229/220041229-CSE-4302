#include<bits/stdc++.h>
using namespace std;

int main (){
    int number1,number2,number3,number4;
    char dummychar;
    cout<<"Enter first fraction: "<<'\n';
    cin >> number1 >> dummychar >> number2;

    cout<<"Enter second fraction: "<<'\n';
    cin >> number3 >> dummychar >> number4;

    int numerator = (number1*number4) + (number2*number3);
    int denominator = (number2*number4);

    cout << "Sum = " << numerator << "/" << denominator << endl;


}
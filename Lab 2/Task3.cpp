#include<bits/stdc++.h>
using namespace std;

struct fraction
{
    char dummychar;
    int number1;
    int number2;
};

int main(){
    fraction fraction1, fraction2;

    cout<<"Enter first fraction: "<<'\n';
    cin >> fraction1.number1 >> fraction1.dummychar >> fraction1.number2;

    cout<<"Enter second fraction: "<<'\n';
    cin >> fraction2.number1 >> fraction2.dummychar >> fraction2.number2;

    int numerator = (fraction1.number1*fraction2.number2) + (fraction1.number2*fraction2.number1);
    int denominator = (fraction1.number2*fraction2.number2);

    cout << "Sum = " << numerator << "/" << denominator << endl;


}
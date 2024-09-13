#include<bits/stdc++.h>
using namespace std;

class Car{
    private:
    string brandname;
    string model;
    int year;
    string fuel_type;
    int mileage;

    public:
    Car(string brandname, string model, int year, string fuel_type, int mileage){
        this->brandname = brandname;
        this->model = model;
        this->year = year;
        this->fuel_type = fuel_type;
        this->mileage = mileage;
    }

    void ShowInfo(){
        cout<<"Brand: "<<this->brandname<<"\n"<<"Model: "<<this->model<<"\n"<<"year: "<<this->year<<"\n"<<"Fuel type: "<<this->fuel_type<<"\n"<<"Mileage: "<<this->mileage<<" km/l"<<endl;
    }

    void Fuel_Efficient(){
        if(fuel_type == "Electric"){
            cout<<"This car is electric, efficiency measured in km/charge."<<endl;
        }
        if(mileage > 15) cout<<"This car is fuel efficient."<<endl;
        else cout<<"This car is not fuel efficient"<<endl;
    }

    void Fuel_Consumption(){
    if(mileage == 0){
        cout << "This car does not use conventional fuel, so fuel consumption cannot be calculated." << endl;
    } else {
        int result = ceil((100/mileage) * 1.2);
        cout << "Estimated cost for 100km: " << result << endl;
    }
}




};

int main(){
    Car c1("Toyota", "Corolla", 2015, "Petrol", 15);
    cout<<"Car 1: "<<endl;
    c1.ShowInfo();
    c1.Fuel_Efficient();
    c1.Fuel_Consumption();


    Car c2("Tesla", "Model S", 2020, "Electric", 0);
    cout<<"Car 2: "<<endl;
    c2.ShowInfo();
    c2.Fuel_Efficient();
    c2.Fuel_Consumption();


    Car c3("Ford", "F-150", 2018, "Diesel", 12);
    cout<<"Car 3: "<<endl;
    c3.ShowInfo();
    c3.Fuel_Efficient();
    c3.Fuel_Consumption();


    Car c4("Honda", "Accord", 2017, "Hybrid", 18);
    cout<<"Car 4: "<<endl;
    c4.ShowInfo();
    c4.Fuel_Efficient();
    c4.Fuel_Consumption();
}
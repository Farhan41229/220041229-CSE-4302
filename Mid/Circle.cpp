#include<bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793

class Circle{
    private:
        float x, y;
        float radius;
    public:
        
        Circle (){
            x = 0, y = 0,radius = 0;
        }
        Circle(float a, float b, float radius){
            x = a;
            y = b;
            this->radius = radius;
        }
        Circle(float r){
            radius = r;
        }
        ~Circle(){
            // cout<<"Destroyed"<<endl;
        }
        void input(){
            cout<<"Enter the x: "<<endl;
            cin>>x;
            cout<<"Enter the y: "<<endl;
            cin>>y;
            cout<<"Enter the radius: "<<endl;
            cin>>radius;
        }
        void display(){
            cout<<"x: "<<x<<endl;
            cout<<"y: "<<y<<endl;
            cout<<"radius: "<<radius<<endl;
        }
        float getArea(){
            return (PI*radius*radius);
        }
        float getCircumference(){
            return (2*PI*radius);
        }
        void scale(float factor){
            radius = factor * radius;
        }
        Circle operator ++(){
            return Circle(++radius);
        }
        Circle operator ++(int){
            return Circle(radius++);
        }
        Circle operator --(){
            return Circle(--radius);
        }
        Circle operator --(int){
            return Circle(radius--);
        }
        bool operator ==(const Circle &b){
            return radius == b.radius;
        }
        
        
};

void SortByArea(Circle a[], int n){
    for(int pos = 0; pos <= n-2; pos++){

		Circle current = a[pos];
		int min_position = pos;
		for(int j=pos; j<n; j++){

			if(a[j].getArea() < a[min_position].getArea()){
				min_position = j;
			}

        }
		swap(a[min_position],a[pos]);
	}
}

int main(){
        Circle a(0,0,5);
        cout<<a.getArea()<<endl;
        cout<<a.getCircumference()<<endl;
        Circle b(0,0,50);
        ++b;
        b++;
        b.display();
        // bool check = a==b;
        // cout<<"check: "<<check<<endl;
        // cout<<endl<<endl;
        // Circle array[10];
        // for(int i=0; i<10; i++){
        //     cout<<"Circle No: "<<i+1<<endl;
        //     array[i].input();
        // }
        // SortByArea(array, 10);
        // for(int i=0; i<3; i++){
        //     cout<<"Circle No: "<<i+1<<endl;
        //     array[i].display();
        // }
}
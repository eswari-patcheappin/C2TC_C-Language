#include<iostream>
#include<cmath>
using namespace std;

class Shape{
    protected:
        string name;
    public:
        Shape(string shapeName){
            name=shapeName;
        }
    virtual ~Shape(){
        cout<<name<<" destroyed."<<endl;
    }
    virtual void calculateArea()=0;
};

class Rectangle: public Shape{
    private:
        double length, breadth;
    public:
        Rectangle(double l, double b):Shape("Rectangle"),length(l), breadth(b){}
        void calculateArea()override{
            double area=length*breadth;
            cout<<"Aera of Rectangle: "<<area<<endl;
        }
};

class Circle: public Shape{
    private:
        double radius;
    public:
        Circle(double r):Shape("Circle"),radius(r){}
        void calculateArea()override{
            double area = M_PI*radius*radius;
            cout<<"Area of Circle: "<<area<<endl;
        }
};

class Triangle: public Shape{
    private:
        double base, height;
    public:
        Triangle(double b, double h):Shape("Triangle"),base(b), height(h){}
        void calculateArea()override{
            double area=0.5*base*height;
            cout<<"Area of Triangle: "<<area<<endl;
        }
};

int main(){
    Shape* shapes[3];
    shapes[0]=new Rectangle(10,5);
    shapes[1]=new Circle(7);
    shapes[2]=new Triangle(6,4);
    for(int i=0;i<3;i++){
        shapes[i]->calculateArea();
    }
    for(int i=0;i<3;i++){
        delete shapes[i];
    }
    return 0;
}
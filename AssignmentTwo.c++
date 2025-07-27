#include<iostream>
using namespace std;

class Complex{
    private:
        float real, imag;
    public:
        Complex(float r=0, float i=0){
            real=r;imag=i;
        }
        Complex operator+ (const Complex &c){
            return Complex(real+c.real,imag+c.imag);
        }
        Complex operator- (const Complex &c){
            return Complex(real-c.real,imag-c.imag);
        }
        Complex operator* (const Complex &c){
            float r=real*c.real-imag*c.imag;
            float i=real*c.imag+imag*c.real;
            return Complex(r,i);
        }
        bool operator== (const Complex &c){
            return (real==c.real && imag==c.imag);
        }
        friend istream& operator>> (istream &in, Complex &c){
            cout<<"Enter real part: ";
            in>>c.real;
            cout<<"Enter imaginary part: ";
            in>>c.imag;
            return in;
        }
        friend ostream& operator<< (ostream &out, const Complex &c){
            out<<c.real;
            if(c.imag>=0)out<<" + "<<c.imag<<"i";
            else out<<" - "<<-c.imag<<"i";
            return out;
        }
};

int main(){
    Complex c1,c2;
    cout<<"Enter firt complex number:\n";
    cin>>c1;
    cout<<"\nEnter second complex number:\n";
    cin>>c2;
    int ch;
    do{
        cout<<"\n--- Complex Number Calculator---\n";
        cout<<"1.add\n2.Subtract\n3.Multiply\n4.Compare\n5.Exit\n";
        cout<<"Enter your Choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Sum = "<<(c1+c2)<<endl;
                break;
            case 2:
                cout<<"Difference = "<<(c1-c2)<<endl;
                break;
            case 3:
                cout<<"Product = "<<(c1*c2)<<endl;
                break;
            case 4:
                if(c1==c2){
                    cout<<"Both complex number are equal.\n";
                }else{
                    cout<<"Complex numbers are different.\n";
                }
                break;
            case 5:
                cout<<"Existing..\n";
                break;
            default:
                cout<<"Invalid choice! Try again.\n";
        }
    }while(ch!=5);
    return 0;
}
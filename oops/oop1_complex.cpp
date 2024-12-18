#include <iostream>
using namespace std;
class complex
{
    public:
    int r,i;
    
    complex()
    {
        r=0;
        i=0;
    }
    
    complex(int r,int i)
    {
        this->r=r;
        this->i=i;
     }
    
    complex operator+(complex c2)
    {
        complex add;
        add.r=r+c2.r;
        add.i=i+c2.i;
        return add;
    }
  
  
  complex operator*(complex &c2) 
  {
      complex mul;
        mul.r= (r * c2.r) - (i * c2.i);
        mul.i = (r * c2.i) + (i * c2.r);
        return mul;
    }
  
 friend istream& operator>>(istream& in,complex &s)
 {
     cout<<"Enter real and img part: \n";
     in>>s.r>>s.i;
     return in;
 }
    
    friend ostream& operator<<(ostream& out,complex &s)
 {
     out<<s.r<<"+"<<s.i<<"i"<<endl;
     return out;
}
     
};

int main()
{   
    
    complex c1,c2;
    cin>>c1;
    cin>>c2;
    
    complex add=c1+c2;

    complex mul=c1*c2;
    cout<<"Addition= ";
    cout<<add;
     cout<<"Mul= ";
    cout<<mul;
    return 0;
}
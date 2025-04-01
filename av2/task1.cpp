#include <iostream>
#include <cmath>
using namespace std;
class Triagolnik {
private:
    float a,b,c;
public:
    Triagolnik(float aa,float bb,float cc) {
        a=aa;
        b=bb;
        c=cc;
    }~Triagolnik() {
        cout<<"DESTRUKORRRRR!!!"<<endl;
    }

    float perimetar() {
        return a+b+c;
    }
    float plostina() {
        float s = perimetar();
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
};


int main() {
    float a,b,c;
    cin>>a>>b>>c;
    Triagolnik t(a,b,c);
    cout<<t.perimetar()<<endl;
    cout<<t.plostina()<<endl;
    return 0;
}
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

class Axis {
    double x, y;
public:
    void input()
    {
        cout<<"Input x and y"<<endl;
        cin>>x>>y;
    };
    double get_x()
    {
        return x;
    };
    double get_y()
    {
        return y;
    };
};


int main() {
    const int t=10;
    int sum_x=0;
    int sum_y=0;
    int sum_x2=0;
    int sum_y2=0;
    int sum_xy=0;
    Axis ax[t];
    for (int i=0; i<t; i++) {
        ax[i].input();
        sum_x=sum_x+ax[i].get_x();
        sum_y=sum_y+ax[i].get_y();
        sum_x2=sum_x2+pow(ax[i].get_x(), 2);
        sum_y2=sum_y2+pow(ax[i].get_y(), 2);
        sum_xy=sum_xy+ax[i].get_y()*ax[i].get_x();
    };
    double X=(double)sum_x/(double)t;
    double Y=(double)sum_y/(double)t;
    double k=(sum_xy-(sum_x*sum_y)/(double)t)/(sum_x2-pow(sum_x, 2)/(double)t);
    double b=Y-X*k;
    if (b>0) cout<<fixed<<setprecision(4)<<"y="<<k<<"x"<<"+"<<b<<endl;
    else cout<<fixed<<setprecision(4)<<"y="<<k<<"x"<<b<<endl;
    system("pause");
    return 0;
}
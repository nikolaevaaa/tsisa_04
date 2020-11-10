#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

double Func (double x,double y)
{
    double f=-sqrt(log(1+x*x+y*y));
    return f;
}

struct Point{
public:
    double x;
    double y;
    double fit;
};

double Average (std::vector<Point> v)
{
    double av=0.0,sum=0.0;
    for (int i=0;i<4;i++ )
    {
        sum+=v[i].fit;
    }
    av=(double)sum/4;
    return av;
}

bool Compare(Point& p1, Point& p2){
    return p1.fit > p2.fit;
};

int main() {
    double p=0.4,fitm=0.0;
    int N=1,a=-1,b=1,c=-1,d=1;
    std::vector<Point> v;
    for (int i=0;i<4;i++)
    {
        Point crom;
        crom.x= (double)(a + rand() * 1./RAND_MAX * (b - a));
        crom.y=(double)(c + rand() * 1./RAND_MAX * (d - c));
        crom.fit=Func(crom.x,crom.y);
        v.push_back(crom);
    }
    std::sort(v.begin(), v.end(), Compare);
    std::cout << "Number " << N;
    fitm=v[0].fit;
    std::cout<<"  Max Fit: "<<fitm<<"  Average: "<<Average(v)<<std::endl;

    std::vector<Point> new_v;
    int k=2;
    while (k<11)
    {

        new_v[0].x=v[0].x;
        new_v[0].y=v[1].y;
        new_v[0].fit=Func(new_v[0].x,new_v[0].y);

        new_v[1].x=v[1].x;
        new_v[1].y=v[0].y;
        new_v[1].fit=Func(new_v[1].x,new_v[1].y);

        new_v[2].x=v[0].x;
        new_v[2].y=v[2].y;
        new_v[2].fit=Func(new_v[2].x,new_v[2].y);

        new_v[3].x=v[2].x;
        new_v[3].y=v[0].y;
        new_v[3].fit=Func(new_v[3].x,new_v[3].y);

        std::cout << "№ " << k;
        for (int j=0;j<new_v.size();j++)
        {
            if (v[j].fit>fitm) fitm=v[j].fit;
        }
        std::cout<<"  Max Fit: "<<fitm<<"  Average: "<<Average(new_v)<<std::endl;
        v=new_v;

        std::sort(v.begin(), v.end(), Compare);
        k++;
    }


    return 0;
}

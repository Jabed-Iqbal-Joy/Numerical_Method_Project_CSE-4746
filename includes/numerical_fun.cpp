#include<bits/stdc++.h>
#include <cstdlib>
#include <iomanip>
#include <windows.h>
using namespace std;
#define pi acos(-1.0)
#define pb push_back

void welcome()
{
    cout << "\t\t**********************************" << endl;
    cout << "\t\t*                                *" << endl;
    cout << "\t\t*        Welcome to NM Project   *" << endl;
    cout << "\t\t*                                *" << endl;
    cout << "\t\t**********************************" << endl;
    //cout << "\t\tEnjoy your experience." << endl;
    Sleep(5000);
    system("cls");
}

void introduction()
{
    cout<<"\n\n\t\tProject Title : Numerical Solution of Non-linear Equations\n\n\n";

    //cout<< ""
    cout << "This program finds the root of a non-linear equation using Numerical method." << endl;
    cout << "Equation: f(x) = sin(x) + x^3 - 2x = 0" << endl;
    cout << "\n\nWe will apply the numerical method to find the root of this equation.";
    cout << "The approximate root will be displayed, along with the value of f(root)." << endl;
    cout << "\n\nLet's get started!" << endl;

}

void menu()
{
    cout << "Numerical Methods for Non-linear Equations" << endl;
    cout << "=========================================" << endl;

    cout << endl;
    cout << "Choose a numerical method:" << endl;
    cout << "1. Bisection Method" << endl;
    cout << "2. Newton-Raphson Method" << endl;
    cout << "3. Secant Method" << endl;
    cout << "4. Fixed-Point Method" << endl;
    cout << "5. False-Position Method" << endl;
    cout << "6. Result analysis" <<endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice (1-7): ";
}


double fx(double x)
{
    double ans=0;
    ans=(sin(x*M_PI / 180.0)+ (x*x*x) -(2*x));
    return ans;
}

double fxp(double x)
{
    double ans=0;
    ans= (cos(x*M_PI/180.0)+(3*x*x)-2);
    return ans;
}



void bisectionMethod()
{
    double lowerlimit=-5,upperlimit=-1,x0;
    double iiter=0;
    if(fx(lowerlimit)*fx(upperlimit)<=0)
    {
        cout<<setw(10)<<setfill(' ')<<"a     ";
        cout<<setw(10)<<setfill(' ')<<"b     ";
        cout<<setw(10)<<setfill(' ')<<"x0     ";
        cout<<setw(10)<<setfill(' ')<<"f(a)  ";
        cout<<setw(10)<<setfill(' ')<<"f(b)  ";
        cout<<setw(10)<<setfill(' ')<<"f(x0)  ";
        cout<<setw(10)<<setfill(' ')<<"f(|a-b|)";
        cout<<endl;
        cout<<fixed<<setprecision(5);
        while(fabs(lowerlimit-upperlimit)>1e-5)
        {
            x0= (lowerlimit+upperlimit)/2;
            double fa,fb,fx0;
            fa=fx(lowerlimit);
            fb=fx(upperlimit);
            fx0=fx(x0);
            iiter++;
            cout<<setw(10)<<setfill(' ')<<lowerlimit;
            cout<<setw(10)<<setfill(' ')<<upperlimit;
            cout<<setw(10)<<setfill(' ')<<x0;
            cout<<setw(10)<<setfill(' ')<<fa;
            cout<<setw(10)<<setfill(' ')<<fb;
            cout<<setw(10)<<setfill(' ')<<fx0;
            cout<<setw(10)<<setfill(' ')<<fabs(lowerlimit-upperlimit)<<endl;
            if(fa*fx0<0)
                upperlimit=x0;
            else lowerlimit=x0;
        }
        double root = (lowerlimit+upperlimit)/2;
        cout<<"Root  : "<<root<<endl;
    }
}

void bisectionMethod(double *rroot,double *iter)
{
    double lowerlimit=-1,upperlimit=-5,x0;
    double iiter=0;
    if(fx(lowerlimit)*fx(upperlimit)<=0)
    {
        while(fabs(lowerlimit-upperlimit)>1e-5)
        {
            x0= (lowerlimit+upperlimit)/2;
            double fa,fb,fx0;
            fa=fx(lowerlimit);
            fb=fx(upperlimit);
            fx0=fx(x0);
            iiter++;
            if(fa*fx0<0)
                upperlimit=x0;
            else lowerlimit=x0;
        }
        double root = (lowerlimit+upperlimit)/2;
        *iter=iiter;
        *rroot=root;
    }
}


void newtonRaphsonMethod()
{
    double x=0,nx=1,i=1,iiter=0;
    cout<<"X0 = 0\n";
    while(fabs(nx-x)>=1e-5)
    {
        x=nx;
        nx=x-(fx(x)/fxp(x));
        cout<<"X"<<(int)iiter<<" = "<<nx<<endl;
        iiter++;
    }
    double root = nx;
    cout<<"Root  : "<<root<<endl;
}

void newtonRaphsonMethod(double *rroot,double *iter)
{
    double x=0,nx=1,i=1,iiter=0;
    while(fabs(nx-x)>=1e-5)
    {
        x=nx;
        nx=x-(fx(x)/fxp(x));
        iiter++;
    }
    double root = nx;
    *iter=iiter;
    *rroot=root;
}

void secantMethod()
{
    double x1=1,x2=4,x3=3,iiter=3;
    cout<<"x1 = "<<x1<<endl;
    cout<<"x2 = "<<x2<<endl;
    while(fabs(x1-x2)>=0.0005)
    {
        x3 = x2 - ((fx(x2)*(x2-x1))/(fx(x2)-fx(x1)));
        cout<<"x"<<iiter<<" = "<<x3<<endl;
        iiter++;
        x1=x2;
        x2=x3;

    }
    double root = x3;
    cout<<"Root  : "<<root<<endl;
}
void secantMethod(double *rroot,double *iter)
{
    double x1=1,x2=4,x3=3,iiter=0;
    while(fabs(x1-x2)>=0.0005)
    {
        x3 = x2 - ((fx(x2)*(x2-x1))/(fx(x2)-fx(x1)));
        iiter++;
        x1=x2;
        x2=x3;

    }
    double root = x3;
    *iter=iiter;
    *rroot=root;
}


double gx(double x)
{
    return (sin(x*M_PI/180.0)+(x*x*x))/2.0;
}


void fixedPointIterationMethod()
{
    cout<<fixed<<setprecision(7)<<endl;
    double x0=0,x1=-3.1,iiter=0;
    while(fabs(x1-x0)>=0.0005)

    {
        x0=x1;
        x1=gx(x0);
        cout<<iiter++<<"\t\t"<<x0<<"\t\t"<<x1<<"\t\t"<<fabs(x0-x1)<<endl;
    }
    double root = x1;
    cout<<"Root  : "<<root<<endl;
}
void fixedPointIterationMethod(double *rroot,double *iter)
{
    double x0=0,x1=1.1,iiter=0;
    while(fabs(x1-x0)>=0.0005)

    {
        x0=x1;
        x1=gx(x0);
        iiter++;
    }
    double root = x1;
    *iter=iiter;
    *rroot=root;
}



void false_positionMethod()
{
    double x1=1,x2=4,x3;
    int iiter=3;
    cout<<"x1 = "<<x1<<endl;
    cout<<"x2 = "<<x2<<endl;
    while(fabs(x1-x2)>=0.0005)
    {
        x3 = x2 - ((fx(x2)*(x2-x1))/(fx(x2)-fx(x1)));
        cout<<"x"<<iiter<<" = "<<x3<<endl;
        iiter++;
        x1=x2;
        x2=x3;

    }
    cout<<"x"<<iiter<<" = "<<x3<<endl;
}
void false_positionMethod(double *rroot,double *iter)
{
    double x1=1,x2=4,x3;
    int iiter=3;
    while(fabs(x1-x2)>=0.0005)
    {
        x3 = x2 - ((fx(x2)*(x2-x1))/(fx(x2)-fx(x1)));
        iiter++;
        x1=x2;
        x2=x3;

    }
    double root=x3;
    *iter=iiter;
    *rroot=root;
}


void result_analysis()
{
    vector<pair<double,string>> acr;
    vector<pair<double,string>> itr;
    cout<<fixed<<setprecision(8);
    cout<<"Here Given Equation f(x) = sin(x) + x^3 - 2x.\n\n\n";
    cout<<left<<setw(15)<<setfill(' ')<<"Method";
    cout<<left<<setw(15)<<setfill(' ')<<"Bisection";
    cout<<left<<setw(15)<<setfill(' ')<<"Newton-Rafson";
    cout<<left<<setw(15)<<setfill(' ')<<"   Secant";
    cout<<left<<setw(15)<<setfill(' ')<<"Fixed-Point";
    cout<<left<<setw(15)<<setfill(' ')<<"False-Position";
    cout<<endl;
    cout<<endl;
    double b_iter,b_root,nr_root,nr_iter,se_root,se_iter,fix_root,fix_iter,fal_root,fal_iter;
    bisectionMethod(&b_root,&b_iter);
    newtonRaphsonMethod(&nr_root,&nr_iter);
    secantMethod(&se_root,&se_iter);
    fixedPointIterationMethod(&fix_root,&fix_iter);
    false_positionMethod(&fal_root,&fal_iter);
    itr.pb({b_iter,"Bisection Method"});
    itr.pb({nr_iter,"Newton Rafson Method"});
    itr.pb({se_iter,"Secant Method"});
    itr.pb({fix_iter,"Fixed Point Method"});
    itr.pb({fal_iter,"False Position Method"});
    sort(itr.begin(),itr.end());

    cout<<left<<setw(15)<<setfill(' ')<<"Root";
    cout<<left<<setw(15)<<setfill(' ')<<b_root;
    cout<<left<<setw(15)<<setfill(' ')<<nr_root;
    cout<<left<<setw(15)<<setfill(' ')<<se_root;
    cout<<left<<setw(15)<<setfill(' ')<<fix_root;
    cout<<left<<setw(15)<<setfill(' ')<<fal_root<<endl;
    cout<<endl;

    cout<<left<<setw(15)<<setfill(' ')<<"Fx(Root)";
    cout<<left<<setw(15)<<setfill(' ')<<fx(b_root);
    cout<<left<<setw(15)<<setfill(' ')<<fx(nr_root);
    cout<<left<<setw(15)<<setfill(' ')<<fx(se_root);
    cout<<left<<setw(15)<<setfill(' ')<<fx(fix_root);
    cout<<left<<setw(15)<<setfill(' ')<<fx(fal_root)<<endl;
    cout<<endl;

    cout<<left<<setw(15)<<setfill(' ')<<"Error";
    cout<<left<<setw(15)<<setfill(' ')<<fabs(0.000-fx(b_root));
    cout<<left<<setw(15)<<setfill(' ')<<fabs(0.000-fx(nr_root));
    cout<<left<<setw(15)<<setfill(' ')<<fabs(0.000-fx(se_root));
    cout<<left<<setw(15)<<setfill(' ')<<fabs(0.000-fx(fix_root));
    cout<<left<<setw(15)<<setfill(' ')<<fabs(0.000-fx(fal_root))<<endl;
    cout<<endl;
    acr.pb({fabs(0.000-fx(b_root)),"Bisection Method"});
    acr.pb({fabs(0.000-fx(nr_root)),"Newton Rafson Method"});
    acr.pb({fabs(0.000-fx(se_root)),"Secant Method"});
    acr.pb({fabs(0.000-fx(fix_root)),"Fixed Point Method"});
    acr.pb({fabs(0.000-fx(fal_root)),"False Position Method"});
    sort(acr.begin(),acr.end());


    cout<<left<<setw(15)<<setfill(' ')<<"Iteration";
    cout<<left<<setw(15)<<setfill(' ')<<(int)b_iter;
    cout<<left<<setw(15)<<setfill(' ')<<(int)nr_iter;
    cout<<left<<setw(15)<<setfill(' ')<<(int)se_iter;
    cout<<left<<setw(15)<<setfill(' ')<<(int)fix_iter;
    cout<<left<<setw(15)<<setfill(' ')<<(int)fal_iter<<endl;
    cout<<endl<<endl<<endl;

    cout<<"Efficiency => "<<itr[0].second<<" find root in minimum iteration.\n\n\n";
    cout<<"Accuracy => "<<acr[0].second<<"\n\n\n\n\n\n";

}


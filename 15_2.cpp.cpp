/*
    g++ drill15_2.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill15_2 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

using Graph_lib::Font;

double konstans(double x){return 1;}
double egyenes(double x){return x/2;}
double parabola(double x){return x*x;}
double cosegy(double x){return cos(x)+egyenes(x);}


int main(){

     using namespace Graph_lib;

     const int xmax = 600;
    const int ymax = 600;

    const int x_orig = xmax/2;
    const int y_orig = ymax/2;
    const Point orig(x_orig,y_orig);

    const int r_min = -10;
    const int r_max = 11;

    const int n_points = 400;

    const int x_scale = 20;
    const int y_scale = 20;

    Point tl(600,50);
    Simple_window win(tl,xmax,ymax,"Function graphs");

    const int xlength = xmax - 200;
    const int ylength = ymax - 200;

    Axis x(Axis::x,Point(100,y_orig),xlength,xlength/x_scale,"1 == 20 pixels");
    x.set_color(Color::red);
    win.attach(x);
    Axis y(Axis::y,Point(x_orig,500),ylength,ylength/y_scale,"1 == 20 pixels");
    y.set_color(Color::red);
    win.attach(y);
    win.wait_for_button();

    Function egyen(konstans,r_min,r_max,orig,n_points,x_scale,y_scale);
    win.attach(egyen);
    win.wait_for_button();

    Function egyenes1(egyenes,r_min,r_max,orig,n_points,x_scale,y_scale);
    win.attach(egyenes1);
    win.wait_for_button();

    Function para(parabola,r_min,r_max,orig,n_points,x_scale,y_scale);
    win.attach(para);
    win.wait_for_button();

    Function cosin(cos,r_min,r_max,orig,n_points,x_scale,y_scale);
    cosin.set_color(Color::blue);
    win.attach(cosin);
    win.wait_for_button();

    Function scos(cosegy,r_min,r_max,orig,n_points,x_scale,y_scale);
    win.attach(scos);
    win.wait_for_button();
}
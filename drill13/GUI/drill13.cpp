#include "../GUI/Graph.h"
#include "../GUI/Simple_window.h"

#include <iostream>
#include <string>

using namespace Graph_lib;

int main(){

	try{


        srand(time(0));
        int x = 8;
        int y = 8;


		Point t1(300, 50);
		Simple_window win(t1, 1000, 800, "My window");
		win.wait_for_button();

		Lines grid;
		int x_size = 800;
		int y_size = 800;
		for (int i = 100; i <= x_size; i+=100)
		{
			grid.add(Point(i,0), Point(i, y_size));
			grid.add(Point(0,i), Point(x_size, i));
		}
		win.attach(grid);
		win.wait_for_button();
		
		Vector_ref<Rectangle> vr;
		for (int i = 0; i < 8; ++i){
			vr.push_back(new Rectangle{Point(i*100,i*100),100,100});
			vr[vr.size()-1].set_fill_color(Color::red);
			vr[vr.size()-1].set_color(Color::invisible);
			win.attach(vr[vr.size()-1]);
		}
		win.wait_for_button();

		Image iu {Point{500,100},"meme.jpg"};
		win.attach(iu);
		win.set_label("IQ");
		win.wait_for_button();

		Image ii {Point{0,300},"meme.jpg"};
		win.attach(ii);
		win.set_label("IQ");
		win.wait_for_button();

		Image io {Point{100,600},"meme.jpg"};
		win.attach(io);
		win.set_label("IQ");
		win.wait_for_button();


		int r1 = (rand()%x)*100, r2 = (rand()%y)*100;

        /*Image ip (Point{r1, r2}, "loong.jpg");
        win.attach(ip);
        win.set_label("Hoosszu cica");
        win.wait_for_button();*/
        while(true){
        	win.set_label("Hoosszu cica");
            ip.move(-r1, -r2);
            r1 = (rand()%x)*100, r2 = (rand()%y)*100;
            ip.move(r1, r2);
            win.attach(ip);
            win.wait_for_button();
        }

		
	}catch(exception & e){

		cerr<<"exception: " << e.what() << endl;
		return 1;

	}catch(...){

		cerr << "exception\n";
		return 2;

	}

}
/* 
Project: L6 Recursive Art
Purpose: To gain an understanding of the three laws of recursion, understand the properties of recursion,and gain an 
understading of how to reach a base case.
Authors:
C-Turtle by Jesse  W.  Walker, GetRandom by Jan Pearce
Recursive Art by Luke Wilson
References: N/A
 */
#include "CTurtle.hpp"  
#include <iostream> 
#include <random> 
#include <chrono> 
namespace ct = cturtle;
using namespace std;
//generates a random number
class Getrandom {
public:
    Getrandom(int size) {
        auto seed = chrono::system_clock::now().time_since_epoch().count(); 
        default_random_engine generator(seed);			
        uniform_int_distribution<int> intdist(1.25, size); 
        self_rand_int_ = intdist(generator);			
    }
    int roll() {
        return self_rand_int_;
    }
private:
    int self_rand_int_;
};

class Square {
public:
//constructor
	Square() {
		max_width;
		max_height;
		new_width;
		new_height;
	}
//draws the intial screen
	void draw_screen(ct::Turtle& turtle) {		
		turtle.penup();
		turtle.goTo(-400, 300);
		turtle.pendown();
		for (int i = 0; i < 2; i++) {
			turtle.forward(800);
			turtle.right(90);
			turtle.forward(600);
			turtle.right(90);
		}
	}
//splits screen in four quadrants randomly
	void set_frame(ct::Turtle& turtle) { 	
		turtle.goTo(-400, 300);
		int w = 800;                             
		int h = 600;							 
		Getrandom rand_w(w);							
		Getrandom rand_h(h);
		int ran_w = rand_w.roll();
		int ran_h = rand_h.roll();
//sets a minimum value for randomness
		if (ran_w < w * .25) {					 
			ran_w = w * .25;
		}
		if (ran_h < h * .25) {
			ran_h = h * .25;
		}
//sets a maximum value for randomness
		if (ran_w > w * .75) {				
			ran_w = w * .75;
		}
		if (ran_h > h * .75) {
			ran_h = h * .75;
		}
//draws first plane
		for (int i = 0; i < 2; i++) {		
			turtle.forward(ran_w);
			turtle.right(90);
			turtle.forward(ran_h);
			turtle.right(90);
		}
		turtle.forward(ran_w);
//draws second plane
		for (int i = 0; i < 2; i++) {			
			turtle.forward(800 - ran_w);
			turtle.right(90);
			turtle.forward(ran_h);
			turtle.right(90);
		}
		turtle.penup();							
		turtle.goTo(-400, 300-ran_h);
		turtle.pendown();
//draws third plane
		for (int i = 0; i < 2; i++) {			
			turtle.forward(ran_w);
			turtle.right(90);
			turtle.forward(600-ran_h);
			turtle.right(90);
		}
		turtle.forward(ran_w);
//draws fourth plane
		for (int i = 0; i < 2; i++) {
			turtle.forward(800 - ran_w);
			turtle.right(90);
			turtle.forward(600 - ran_h);
			turtle.right(90);
		}
//set values for intialized variables to be used to fill each quadrant when recursive method is called
		max_width = w;						
		max_height = h;
		new_width = ran_w;
		new_height = ran_h;
//sets up and calls recursive method for first quadrant
		turtle.penup();
		turtle.goTo(-400, 300);
		turtle.pendown();
		recursive_draw(max_width, max_height, new_width, new_height,  turtle);
//sets up and calls recursive method for second quadrant
		turtle.penup();
		turtle.goTo(-400, 300 - new_height);
		turtle.setheading(0);
		turtle.pendown();
		recursive_draw(max_width, max_height, new_width, max_height - new_height, turtle);
//sets up and calls recursive method for third quadrant
		turtle.penup();
		turtle.goTo(-400 + new_width, 300);
		turtle.setheading(0);
		turtle.pendown();
		recursive_draw(max_width, max_height, max_width - new_width, new_height, turtle);
//sets up and calls recursive method for third quadrant
		turtle.penup();
		turtle.goTo(-400 + new_width, 300 - new_height);
		turtle.setheading(0);
		turtle.pendown();
		recursive_draw(max_width, max_height, max_width - new_width, max_height - new_height, turtle);
	}
//recursivley draws squares randomly
	int recursive_draw(int max_width, int max_height, int new_width, int new_height, ct::Turtle& turtle) {
		Getrandom rand_width(100);
		Getrandom rand_height(100);
		float random_width = rand_width.roll() * 0.01;
		float random_height = rand_height.roll() * 0.01;
		bool width_activation = false;
		bool height_activation = false;
//controls min/max of random splitting
		if (random_width < .3) {
			random_width = .3;
		}
		if (random_width > .7) {
			random_width = .7;
		}
		if (random_height < .3) {
			random_height = .3;
		}
		if (random_height > .7) {
			random_height = .7;
		}
//base case vvvv
		if (new_width > 50 && new_height > 50) {
			if (new_width > max_width / 2 || new_height > max_height / 2) {
//splits square vertically if width is over 49% of max width
				if (new_width > max_width * 0.5) {
					turtle.fillcolor(10000 * new_width / random_width);
					turtle.begin_fill();
					for (int i = 0; i < 2; i++) {
						turtle.forward(new_width * random_width);
						turtle.right(90);
						turtle.forward(new_height);
						turtle.right(90);
						width_activation = true;
					}
					turtle.end_fill();
				}
//splits square horizontally if height is over 49% of max width
				if (new_height > max_height * 0.5) {
					turtle.fillcolor(10000 * new_height / random_height);
					turtle.begin_fill();
					for (int i = 0; i < 2; i++) {
						turtle.forward(new_width);
						turtle.right(90);
						turtle.forward(new_height * random_height);
						turtle.right(90);
						height_activation = true;
					}
					turtle.end_fill();
				}
//moves turtle to bigger square so the bigger square can be split
				if (random_width > .5 && width_activation == true) {
					new_width = new_width * random_width;
					max_width = new_width / random_width;
				}
				if (random_height > .5 && height_activation == true) {
					new_height = new_height * random_height;
					max_height = new_height / random_height;
				}
				if (random_width < .5 && width_activation == true) {
					turtle.forward(new_width * random_width);
					new_width = new_width * (1 - random_width);
					max_width = new_width / (1 - random_width);
				}
				if (random_height < .5 && height_activation == true) {
					turtle.goTo(turtle.xcor(), turtle.ycor() - new_height * random_height);
					new_height = new_height * (1 - random_height);
					max_height = new_height / (1 - random_height);
				}
//method recursivley calls itself
				return recursive_draw(max_width, max_height, new_width, new_height, turtle);
			}
		}
		else {
			return 0;
		}
	}
	private:
		int max_width;
		int max_height;
		int new_width;
		int new_height;
};
int main() {
	ct::TurtleScreen screen;
	ct::Turtle turtle(screen);
	turtle.speed(1);
	Square square;
	square.draw_screen(turtle);
	square.set_frame(turtle);
	char a;
	cin >> a;
}
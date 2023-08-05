#pragma once
#include "Circle.h"
#include "Circle2.h"
#include <vector>

using namespace std;

class Controller {
private:
	vector<Circle*> circles;
	vector<Circle2*> circles2;

public:
	Controller(Graphics ^g) {
		for (int i = 0; i < 5; i++) {
			//addCircle();
		}
		circles2.push_back(new Circle2(0,0));
		circles2.push_back(new Circle2(0,g->VisibleClipBounds.Height/2));
		circles2.push_back(new Circle2(0,g->VisibleClipBounds.Height-80));
		circles2.push_back(new Circle2(g->VisibleClipBounds.Width-70, 0));
		circles2.push_back(new Circle2(g->VisibleClipBounds.Width-70, g->VisibleClipBounds.Height / 2));
		circles2.push_back(new Circle2(g->VisibleClipBounds.Width-70, g->VisibleClipBounds.Height - 80));


	}

	~Controller() {}

	void addCircle(int x,int y) {
		Circle* c = new Circle(x,y);
		circles.push_back(c);
	}

	void addCircle2() {
		Circle2* t = new Circle2();
		//circles2.push_back(t);

	}

	void drawEverything(Graphics^ g) {
		for (int i = 0; i < circles.size(); i++) {
			circles[i]->draw(g);
		}
		for (int i = 0; i < circles2.size(); i++) {
			circles2[i]->draw(g);
		}
	}

	void moveEverything(Graphics^ g) {
		for (int i = 0; i < circles.size(); i++) {
			circles[i]->move(g);
		}
		
	}

	void Rebotar(int x, int dx) {
		//rebote
		for (int i = 0; i < circles.size(); i++) {
			for (int j = 0; j < circles2.size(); j++) {
				if (circles[i]->getRectangle().IntersectsWith(circles2[j]->getRectangle())) {
					//circles[i]->setVisible(true);
					//circles2[j]->setVisible(true);
					dx = dx * -1;
				}
				dx--;
			}
		}
	}
	


	void collision() {
		//Verification
		for (int i = 0; i < circles.size(); i++) {
			for (int j = 0; j < circles2.size(); j++) {
				if (circles[i]->getRectangle().IntersectsWith(circles2[j]->getRectangle())) {
					circles[i]->setVisible(false);
					//circles2[j]->setVisible(false);
				}
			}
		}

		if (circles.size()>0) {
			for (int i = 0; i < circles.size() - 1; i++) {
				for (int j = i + 1; j < circles.size(); j++) {
					if (circles[i]->getRectangle().IntersectsWith(circles[j]->getRectangle())) {
						circles[i]->rebote();
						circles[j]->rebote();
						break;
					}
				}

			}
		}
		

		//Elimination
		for (int i = 0; i < circles.size(); i++) {
			if (!circles[i]->getVisible()) {
				circles.erase(circles.begin() + i);
			}
		}

		for (int i = 0; i < circles2.size(); i++) {
			if (!circles2[i]->getVisible()) {
				circles2.erase(circles2.begin() + i);
			}
		}

	}


};
#pragma once
#include <iostream>

using namespace System::Drawing;

class Circle {
private:
	int x, y;
	int radio;
	int dx;
	bool visible;
	int rgb;

public:
	Circle(int x,int y) {
		this->x = x;
		this->y = y;
		//x = rand() % 500;
		//y = rand() % 300 + 100;
		radio = rand() % 10 + 30;
		dx = rand() % 5 + 10;
		visible = true;
		rgb = rand() % 8;
	}

	~Circle() {}

	//Erase - Move - Draw

	void draw(Graphics^ g) {

		//SolidBrush^ b = gcnew SolidBrush(Color::Orange);
		//g->FillEllipse(b, x, y, radio * 2, radio * 2);

		switch (rgb) {
		case 1:
			if (rgb == 1) {
				SolidBrush^ b = gcnew SolidBrush(Color::Blue);
				g->FillEllipse(b, x, y, radio * 2, radio * 2);
				break;
			}
		case 2:
			if (rgb == 2) {
				SolidBrush^ b = gcnew SolidBrush(Color::Yellow);
				g->FillEllipse(b, x, y, radio * 2, radio * 2);
				break;
			}
		case 3:
			if (rgb == 3) {
				SolidBrush ^ b = gcnew SolidBrush(Color::Red);
				g->FillEllipse(b, x, y, radio * 2, radio * 2);
				break;
			}
		case 4:
			if (rgb == 4) {
				SolidBrush ^ b = gcnew SolidBrush(Color::Purple);
				g->FillEllipse(b, x, y, radio * 2, radio * 2);
				break;
			}
		case 5:
			if (rgb == 5) {
				SolidBrush^ b = gcnew SolidBrush(Color::Pink);
				g->FillEllipse(b, x, y, radio * 2, radio * 2);
				break;
			}
		case 6:
			if (rgb == 6) {
				SolidBrush^ b = gcnew SolidBrush(Color::White);
				g->FillEllipse(b, x, y, radio * 2, radio * 2);
				break;
			}
		case 7:
			if (rgb == 7) {
				SolidBrush^ b = gcnew SolidBrush(Color::Cyan);
				g->FillEllipse(b, x, y, radio * 2, radio * 2);
				break;
			}
		case 8:
			if (rgb == 8) {
				SolidBrush^ b = gcnew SolidBrush(Color::Orange);
				g->FillEllipse(b, x, y, radio * 2, radio * 2);
				break;
			}
			
		}
	}

	void rebote() {
		dx *= -1;
	}

	void move(Graphics^ g) {
		if (x < 0 || x + 2 * radio > g->VisibleClipBounds.Width) {
			dx *= -1;
		x += dx;
		}

		else if (x<1 || x + radio> g->VisibleClipBounds.Width) {
			dx *= 1;
		}
		x += dx;
	}

	bool getVisible() { return visible; }
	void setVisible(bool v) { visible = v; }
	//rebote
	//int getX() { return x; }
	//int getY() { return y; }
	//void directX(int x, int dx) { dx=dx*(-1); }

	Rectangle getRectangle() {
		return Rectangle(x, y, 2 * radio, 2 * radio);
	}

};
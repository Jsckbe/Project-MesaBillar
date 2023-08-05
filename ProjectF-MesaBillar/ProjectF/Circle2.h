#pragma once
#include <iostream>

using namespace System::Drawing;

class Circle2 {
private:
	int x, y;
	int ubic;
	int radio;
	//int width, height;
	int dy;
	int dx;
	bool visible;

public:
	Circle2() {
		x = rand() % 500;
		y = rand() % 300 + 100;
		//x = 0;
		//y = 0;
		ubic = rand() % 6;
		radio = rand() % 10 + 30;
		//dx = rand() % 5 + 10;
		dx = 0;
		visible = true;
	}

	Circle2(int x, int y) {
		this->x = x;
		this->y = y;
		//y = rand() % 300 + 100;
		//x = 0;
		//y = 0;
		//ubic = rand() % 6;
		radio = rand() % 10 + 30;
		//dx = rand() % 5 + 10;
		dx = 0;
		visible = true;
	}

	~Circle2() {}

	//Erase - Move - Draw

	void draw(Graphics^ g) {

		SolidBrush^ p = gcnew SolidBrush(Color::Black);
		g->FillEllipse(p, x, y, radio * 2, radio * 2);
	}



	/*void move(Graphics^ g) {
		if (y < 0 || y + height > g->VisibleClipBounds.Height) dy *= -1;
		y += dy;
	}
	*/

	bool getVisible() { return visible; }
	void setVisible(bool v) { visible = v; }

	Rectangle getRectangle() {
		return Rectangle(x, y, 2 * radio, 2 * radio);
	}
};
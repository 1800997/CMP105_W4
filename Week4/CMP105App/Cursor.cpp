#include "Cursor.h"

void Cursor::changeCursor()
{
	int cursorX = input->getMouseX();
	int cursorY = input->getMouseY();

	setPosition(cursorX, cursorY);

}

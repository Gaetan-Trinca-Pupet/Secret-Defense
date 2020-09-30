#ifndef __ITEM_H_
#define __ITEM_H_


class Item
{
	protected:
		int x;
		int y;

		virtual draw()const = 0;
};


#endif
#pragma once
struct Color
{
	//public by default
	unsigned char red,green,blue,alpha;

	Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
		: red(r), green(g), blue(b), alpha(a)
	{ }
};
#include "Surface.h"

Surface::Surface(int width, int height)
	:
	width(width),
	height(height),
	pPixels(new Color[width * height])
{
}

Surface::Surface(const Surface& oikea)
	:
	Surface(oikea.width, oikea.height)
{
	const int nPixels = width * height;
	for (int i = 0; i < nPixels; i++)
	{
		pPixels[i] = oikea.pPixels[i];
	}
}

Surface Surface::operator=(const Surface& oikea)
{
	width = oikea.width;
	height = oikea.height;

	delete[] pPixels;
	pPixels = new Color[width * height];
	const int nPixels = width * height;
	for (int i = 0; i < nPixels; i++)
	{
		pPixels[i] = oikea.pPixels[i];
	}
	return *this;
}

Surface::~Surface()
{
	delete[] pPixels;
	pPixels = nullptr;
}

void Surface::PutPixel(int x, int y, Color c)
{
	pPixels[y * width + x];
}

Color Surface::GetPixel(int x, int y) const
{
	return pPixels[y * width + x];
}

int Surface::GetWidth() const
{
	return width;
}

int Surface::GetHeight() const
{
	return height;
}

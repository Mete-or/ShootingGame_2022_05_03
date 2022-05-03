#pragma once

//���ӿ��� ������ ���Ǵ� �̹��� ���� ����ü//
struct Image
{
	int pvx; //�Ǻ�(x)
	int pvy; //�Ǻ�(y)

	int width;
	int height;
	unsigned int* rgb;
};

class Bitmap
{
private:
public:
	static void ReadBMP(const char* fileName, Image* img);
	static void ReadBMP(const char* fileName, int x, int y, int width, int height, Image* img);

	static void DrawBMP(float px, float py, Image* img);
};


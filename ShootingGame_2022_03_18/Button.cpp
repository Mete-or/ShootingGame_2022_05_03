#include "ShootingGame.h"

Button::Button(float px, float py) : Sprite("", "", true, px, py)
{
	this->state = normal;
}

Button::~Button()
{}

void Button::Start()
{
	SetSprite("Asset/UI/Menu2/normal.bmp"); //��ư..�⺻ �̹���
}

void Button::Update()
{
	if (state == State::normal)
	{

		if (isinImage() == true)
		{
			//hover�� ���� ����
			state = State::hover;


			 //��ư ȣ�� �̹���
			SetSprite("Asset/UI/Menu2/hover.bmp");
		}

		
	}

	else if (state == State::hover)
	{
		if (isinImage() == false)
		{
			state == State::normal;

			SetSprite("Asset/UI/Menu2/normal.bmp");
		}

		if (Input::GetMouseButtonDown(1) == true)
		{
			//Ŭ������ ���� ����
			state == State::click;

			SetSprite("Asset/UI/Menu2/active.bmp");
		
		}
	}
	else if (state == State::click)
	{
	
		if (Input::GetMouseButtonUp(2) == true)
		{
			state = State::normal;

			SetSprite("Asset/UI/Menu2/normal.bmp");
		}
	}
	


	
}

bool Button::isinImage()
{
	//���콺 ��ǥ�� ���ؼ� �̹��� �簢�� ������ ������ �Ǵ��ϱ�
	int x = Input::mouseposition.x;
	int y = Input::mouseposition.y;

	//�̹��� ũ�� ��������

	int width, height;
	ImageRect(width, height);

	//�̹��� �簢�� ��ǥ ���ϱ�

	int x0 = GetPx();
	int x1 = x0 + width;

	int y0 = GetPy();
	int y1 = y0 + height;

	if (x0 < x && x < x1 && y0 < y && y < y1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

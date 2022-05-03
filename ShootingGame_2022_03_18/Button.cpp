#include "ShootingGame.h"

Button::Button(float px, float py) : Sprite("", "", true, px, py)
{
	this->state = normal;
}

Button::~Button()
{}

void Button::Start()
{
	SetSprite("Asset/UI/Menu2/normal.bmp"); //버튼..기본 이미지
}

void Button::Update()
{
	if (state == State::normal)
	{

		if (isinImage() == true)
		{
			//hover로 상태 전이
			state = State::hover;


			 //버튼 호버 이미지
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
			//클릭으로 상태 전이
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
	//마우스 좌표를 구해서 이미지 사각형 안인지 밖인지 판단하기
	int x = Input::mouseposition.x;
	int y = Input::mouseposition.y;

	//이미지 크기 가져오기

	int width, height;
	ImageRect(width, height);

	//이미지 사각형 좌표 구하기

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

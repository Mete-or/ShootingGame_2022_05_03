#pragma once
#include "Sprite.h"

class Button : public Sprite
{
	//버튼 상태 enum
	enum State { normal = 0, hover = 1, click = 2 };

private:
	State state; 
public:
	Button(float px, float py);
	~Button();

	void Start();
	void Update();

	//마우스 좌표가 이미지 안에 있는지 검사하는 함수//
		
	bool isinImage();
};


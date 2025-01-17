#include<raylib.h>
#include<raymath.h>
#include<vector>


struct Bullet
{
	Vector2 pos;
	Vector2 dir;
};



int main()
{
	int screenWidth = 800;
	int screenHeigh = 600;
	InitWindow(screenWidth, screenHeigh, "Test");
	SetTargetFPS(240);
	
	Rectangle playerRect{screenWidth/2, screenHeigh/2, 50,50};
	Vector2 dir{ 0,0 };
	Vector2 mouseDir{ 0,0 };
	float speed = 2;
	Vector2 mPos{ 0,0 };
	Vector2 playerCenter;
	

	std::vector<Bullet> bullets;
	
	float rot;

	Texture2D playerTexture = LoadTexture("arc.png");


	while (!WindowShouldClose())
	{
		if (IsKeyDown(KEY_A))
		{
			dir.x = -1;
		}
		
		if (IsKeyDown(KEY_W))
		{
			dir.y = -1;
		}

		if (IsKeyDown(KEY_D))
		{
			dir.x = 1;
		}
		
		if (IsKeyDown(KEY_S))
		{
			dir.y = 1;
		}
		

		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		{
			bullets.push_back({ playerRect.x, playerRect.y, mouseDir });
		}



		dir = Vector2Normalize(dir);
		playerRect.x += dir.x*speed;
		playerRect.y += dir.y*speed;
		
		dir.x = 0;
		dir.y = 0;
		mPos = GetMousePosition();
		mouseDir = Vector2{ playerRect.x, playerRect.y };
		/*playerCenter = Vector2{ playerRect.x + playerRect.width / 2, playerRect.y + playerRect.height / 2 };*/
		rot = atan2(Vector2Subtract({ playerRect.x,playerRect.y }, mPos).y ,Vector2Subtract({playerRect.x,playerRect.y}, mPos).x);
		
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		DrawFPS(0,0);
		/*ClearBackground(VIOLET);*/

		DrawFPS(0, 0);
		Vector2 mPos = GetMousePosition();
		DrawTexturePro(
						playerTexture,
						{ 0,0, (float)playerTexture.width, (float) playerTexture.height },
						playerRect,
			{ playerRect.width / 2, playerRect.height / 2},
			rot * RAD2DEG, RED
			);

		for (int i = 0; i < bullets.size(); i++ )
		{
			DrawCircleV(bullets[i].pos, 5, BLACK);
		};













		/*DrawRectangleRec(playerRect, RED);*/
	/*	DrawLine(mPos.x, mPos.y, playerRect.width / 2, x+playerRect.y, playerRect.height / 2, BLUE);*/
		/*DrawLineEx(mPos, Vector2{ playerRect.x + playerRect.width / 2, playerRect.y + playerRect.height / 2 }, 5, BLUE)*/;
		/*rawRectangle(mPos.x,mPos.y, 300, 50, GREEN);*/
		/*IsMouseButtonDown(MOUSE_BUTTON_LEFT);
		IsKeyDown(KEY_A);*/

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
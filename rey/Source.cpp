#include<raylib.h>
#include<raymath.h>



int main()
{
	int screenWidth = 800;
	int screenHeigh = 600;
	InitWindow(screenWidth, screenHeigh, "Test");
	SetTargetFPS(240);
	Rectangle playerRect{screenWidth/2, screenHeigh/2, 50,50};
	Vector2 dir{ 0,0 };
	float speed = 2;
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
		
		dir = Vector2Normalize(dir);
		playerRect.x += dir.x*speed;
		playerRect.y += dir.y*speed;
	
		dir.x = 0;
		dir.y = 0;


		BeginDrawing();
		ClearBackground(VIOLET);

		DrawFPS(0, 0);
		Vector2 mPos = GetMousePosition();
		DrawRectangleRec(playerRect, RED);
		/*rawRectangle(mPos.x,mPos.y, 300, 50, GREEN);*/
		/*IsMouseButtonDown(MOUSE_BUTTON_LEFT);
		IsKeyDown(KEY_A);*/

		EndDrawing();
	}

	
	CloseWindow();
	return 0;
}
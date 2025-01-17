//#include<raylib.h>
//#include<raymath.h>
//#include<vector>
//
//
//struct Bullet
//{
//	Vector2 pos;
//	Vector2 dir;
//};
//
//
//
//int main()
//{
//	int screenWidth = 800;
//	int screenHeigh = 600;
//	InitWindow(screenWidth, screenHeigh, "Test");
//	SetTargetFPS(240);
//	
//	Rectangle playerRect{screenWidth/2, screenHeigh/2, 50,50};
//	Vector2 dir{ 0,0 };
//	Vector2 mouseDir{ 0,0 };
//	float speed = 2;
//	Vector2 mPos{ 0,0 };
//	Vector2 playerCenter;
//	
//
//	std::vector<Bullet> bullets;
//	
//	float rot;
//
//	Texture2D playerTexture = LoadTexture("arc.png");
//
//
//	while (!WindowShouldClose())
//	{
//		if (IsKeyDown(KEY_A))
//		{
//			dir.x = -1;
//		}
//		
//		if (IsKeyDown(KEY_W))
//		{
//			dir.y = -1;
//		}
//
//		if (IsKeyDown(KEY_D))
//		{
//			dir.x = 1;
//		}
//		
//		if (IsKeyDown(KEY_S))
//		{
//			dir.y = 1;
//		}
//		
//
//		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
//		{
//			bullets.push_back({ playerRect.x, playerRect.y, mouseDir });
//		}
//
//
//
//		dir = Vector2Normalize(dir);
//		playerRect.x += dir.x*speed;
//		playerRect.y += dir.y*speed;
//		
//		dir.x = 0;
//		dir.y = 0;
//		mPos = GetMousePosition();
//		mouseDir = Vector2{ playerRect.x, playerRect.y };
//		/*playerCenter = Vector2{ playerRect.x + playerRect.width / 2, playerRect.y + playerRect.height / 2 };*/
//		rot = atan2(Vector2Subtract({ playerRect.x,playerRect.y }, mPos).y ,Vector2Subtract({playerRect.x,playerRect.y}, mPos).x);
//		
//		BeginDrawing();
//		ClearBackground(LIGHTGRAY);
//		DrawFPS(0,0);
//		/*ClearBackground(VIOLET);*/
//
//		DrawFPS(0, 0);
//		Vector2 mPos = GetMousePosition();
//		DrawTexturePro(
//						playerTexture,
//						{ 0,0, (float)playerTexture.width, (float) playerTexture.height },
//						playerRect,
//			{ playerRect.width / 2, playerRect.height / 2},
//			rot * RAD2DEG, WHITE
//			);
//
//		for (int i = 0; i < bullets.size(); i++ )
//		{
//		
//			bullets[i].pos.x = Vector2Add(bullets[i].pos, Vector2Scale(bullets[i].dir, bulletSpeed));
//
//			if (bullets[i].pos.x > screenWidth || bullets[i].pos.x < 0 || 
//				bullets[i].pos.y > screenHeight || bullets[i].pos.y < 0 )
//			{
//				bullets.erase(bullets.begin() + i, bullets.begin() + i + 1);
//				i--;
//			}
//		};
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//		/*DrawRectangleRec(playerRect, RED);*/
//	/*	DrawLine(mPos.x, mPos.y, playerRect.width / 2, x+playerRect.y, playerRect.height / 2, BLUE);*/
//		/*DrawLineEx(mPos, Vector2{ playerRect.x + playerRect.width / 2, playerRect.y + playerRect.height / 2 }, 5, BLUE)*/;
//		/*rawRectangle(mPos.x,mPos.y, 300, 50, GREEN);*/
//		/*IsMouseButtonDown(MOUSE_BUTTON_LEFT);
//		IsKeyDown(KEY_A);*/
//
//		EndDrawing();
//	}
//
//	CloseWindow();
//	return 0;
//}


//#include <raylib.h>
//#include <raymath.h>
//#include <vector>
//
//struct Bullet {
//    Vector2 pos;
//    Vector2 dir;
//};
//
//int main() {
//    int screenWidth = 800;
//    int screenHeight = 600;
//    InitWindow(screenWidth, screenHeight, "Test");
//    SetTargetFPS(240);
//
//    Rectangle playerRect{ screenWidth / 2, screenHeight / 2, 50, 50 };
//    Vector2 dir{ 0,0 };
//    Vector2 mouseDir{ 0,0 };
//    float speed = 2;
//    float bulletSpeed = 10; // Определите скорость пуль
//    Vector2 mPos{ 0,0 };
//    std::vector<Bullet> bullets;
//
//    float rot;
//    Texture2D playerTexture = LoadTexture("arc.png");
//
//    while (!WindowShouldClose()) {
//        dir = { 0, 0 }; // Сбрасываем направление
//
//        if (IsKeyDown(KEY_A)) dir.x = -1;
//        if (IsKeyDown(KEY_W)) dir.y = -1;
//        if (IsKeyDown(KEY_D)) dir.x = 1;
//        if (IsKeyDown(KEY_S)) dir.y = 1;
//
//        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
//            mPos = GetMousePosition();
//            Vector2 bulletDir = Vector2Normalize(Vector2Subtract(mPos, Vector2{ playerRect.x + playerRect.width / 2, playerRect.y + playerRect.height / 2 }));
//            bullets.push_back({ { playerRect.x + playerRect.width / 2, playerRect.y + playerRect.height / 2 }, bulletDir });
//        }
//
//        dir = Vector2Normalize(dir);
//        playerRect.x += dir.x * speed;
//        playerRect.y += dir.y * speed;
//
//        mPos = GetMousePosition();
//        rot = atan2(Vector2Subtract(Vector2{ playerRect.x + playerRect.width / 2, playerRect.y + playerRect.height / 2 }, mPos).y, Vector2Subtract(Vector2{ playerRect.x + playerRect.width / 2, playerRect.y + playerRect.height / 2 }, mPos).x);
//
//        for (int i = 0; i < bullets.size(); i++) {
//            bullets[i].pos = Vector2Add(bullets[i].pos, Vector2Scale(bullets[i].dir, bulletSpeed));
//
//            if (bullets[i].pos.x > screenWidth || bullets[i].pos.x < 0 || bullets[i].pos.y > screenHeight || bullets[i].pos.y < 0) {
//                bullets.erase(bullets.begin() + i);
//                i--;
//            }
//        }
//
//        BeginDrawing();
//        ClearBackground(LIGHTGRAY);
//        DrawFPS(0, 0);
//
//        DrawTexturePro(
//            playerTexture,
//            { 0, 0, (float)playerTexture.width, (float)playerTexture.height },
//            playerRect,
//            { playerRect.width / 2, playerRect.height / 2 },
//            rot * RAD2DEG,
//            WHITE
//        );
//
//        for (const Bullet& bullet : bullets) {
//            DrawRectangle(bullet.pos.x, bullet.pos.y, 5, 5, BLUE); // Рисуем пулю
//        }
//
//        EndDrawing();
//    }
//
//    CloseWindow();
//    return 0;
//}

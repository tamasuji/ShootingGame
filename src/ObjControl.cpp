#include "ObjControl.h"


void PlayerControl(PlayerParam* player, BulletParam* player_bullet, int soundmem)
{
	if (player->active == true)
	{
		//ˆÚ“®‘€ì
		if (CheckHitKey(KEY_INPUT_RIGHT))
		{
			player->rect.x += 3;
			if (player->rect.x > WINDOW_W - player->rect.w) 
				player->rect.x = WINDOW_W - player->rect.w;
		}
		if (CheckHitKey(KEY_INPUT_LEFT))
		{
			player->rect.x -= 3;
			if (player->rect.x < 0) player->rect.x = 0;
		}

		//’e‚Ì”­ŽË
		if (CheckHitKey(KEY_INPUT_Z))
		{
			if (player->shotRepeatCounter <= 0)
			{
				for (int i = 0; i < PLAYER_BULLET_MAX; i++)
				{
					if (player_bullet[i].active == false)
					{
						PlaySoundMem(soundmem, DX_PLAYTYPE_BACK);
						int Pw = player->rect.w;
						int Ph = player->rect.h;
						int Sw = player_bullet[i].rect.w;
						int Sh = player_bullet[i].rect.h;

						player_bullet[i].rect.x = (Pw - Sw) / 2 + player->rect.x;
						player_bullet[i].rect.y = (Ph - Sh) / 2 + player->rect.y;

						player_bullet[i].active = true;

						player->shotRepeatCounter = PLAYER_SHOT_REPEAT;
						break;
					}
				}
			}
			else
			{
				player->shotRepeatCounter --;
			}
		}
		else
		{
			player->shotRepeatCounter = 0;
		}
	}
}

void EnemyControl(EnemyParam* enemy)
{
	for (int i = 0; i < ENEMY_UNIT; i++)
	{
		if (enemy[i].active == true)
		{
			if (enemy[i].dir == 1)
			{
				enemy[i].rect.x += 3;
				if (enemy[i].rect.x > WINDOW_W - enemy[i].rect.w)
				{
					enemy[i].rect.x > WINDOW_W - enemy[i].rect.w;
					enemy[i].dir = 0;
				}
			}
			if (enemy[i].dir == 0)
			{
				enemy[i].rect.x -= 3;
				if (enemy[i].rect.x < 0)
				{
					enemy[i].rect.x = 0;
					enemy[i].dir = 1;
				}
			}
		}
	}
}

void BossControl(BossParam* boss, BulletParam* boss_bullet)
{
	if (boss->active == true)
	{
		if (boss->shot == true)
		{
			for (int i = 0; i < BOSS_SHOT_MAX; i++)
			{
				if (boss_bullet[i].active == false)
				{
					int wayshot[BOSS_SHOT_MAX] = { 50,-50,100,-100,0 };
					int Bw = boss->rect.w;
					int Bh = boss->rect.h;
					int Sw = boss_bullet[i].rect.w;
					int Sh = boss_bullet[i].rect.h;

					boss_bullet[i].rect.x = (Bw - Sw) / 2 + boss->rect.x + wayshot[i];
					boss_bullet[i].rect.y = (Bh - Sh) / 2 + boss->rect.y;

					boss_bullet[i].active = true;
				}
			}
		}
		else
		{
			if (boss->dir == 0)
			{
				boss->rect.x -= 3;
				if (boss->rect.x < 0)
				{
					boss->rect.x = 0;
					boss->dir = 1;
				}
			}
			if (boss->dir == 1)
			{
				boss->rect.x += 3;
				if (boss->rect.x > WINDOW_W - boss->rect.w)
				{
					boss->rect.x = WINDOW_W - boss->rect.w;
					boss->dir = 0;
				}
			}
		}

		if (boss->count <= 0)
		{
			boss->shot = !boss->shot;
			boss->count = 360;
		}
		boss->count--;
	}

}

void PlayerBulletControl(BulletParam* player_bullet)
{
	for (int i = 0; i < PLAYER_BULLET_MAX; i++)
	{
		if (player_bullet[i].active == true)
		{
			player_bullet[i].rect.y -= 8;
			if (player_bullet[i].rect.y < (0 + player_bullet[i].rect.h))
			{
				player_bullet[i].active = false;
			}
		}
	}
}

void BossBulletControl(BulletParam* boss_bullet)
{
	for (int i = 0; i < BOSS_SHOT_MAX; i++)
	{
		if (boss_bullet[i].active == true)
		{
			boss_bullet[i].rect.y += 8;
			if (boss_bullet[i].rect.y >= (WINDOW_H - boss_bullet[i].rect.h))
			{
				boss_bullet[i].active = false;
			}
		}
	}
}
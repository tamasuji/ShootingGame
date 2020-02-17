#include "DrawGraph.h"

void BackGroundDrawGraph(BackGroundParam* background)
{
	for (int i = 0; i < BACKGROUND_LAYER; i++)
	{
		int x = background[i].rect.x;
		int y = background[i].rect.y;
		int handle = background[i].handle;

		DrawGraph(x, y, handle, TRUE);
		DrawGraph(x, y - background[i].rect.h, handle, TRUE);
	}
}

void PlayerDrawGraph(PlayerParam* player)
{
	if (player->active == true)
	{
		DrawGraph(player->rect.x, player->rect.y, player->handle, TRUE);
	}
}

void EnemyDrawGraph(EnemyParam* enemy)
{
	for (int i = 0; i < ENEMY_UNIT; i++)
	{
		if (enemy[i].active == true)
		{
			DrawGraph(enemy[i].rect.x, enemy[i].rect.y, enemy[i].handle, TRUE);
		}

	}
}

void BossDrawGraph(BossParam* boss)
{
	if (boss->active)
	{
		DrawGraph(boss->rect.x, boss->rect.y, boss->handle, TRUE);
	}
}

void PlayerBulletDrawGraph(BulletParam* player_bullet)
{
	for (int i = 0; i < PLAYER_BULLET_MAX; i++)
	{
		if (player_bullet[i].active == true)
		{
			DrawGraph(player_bullet[i].rect.x, player_bullet[i].rect.y, player_bullet[i].handle, TRUE);
		}
	}
}

void BossBulletDrawGraph(BulletParam* boss_bullet)
{
	for (int i = 0; i < BOSS_SHOT_MAX; i++)
	{
		if (boss_bullet[i].active)
		{
			DrawGraph(boss_bullet[i].rect.x, boss_bullet[i].rect.y, boss_bullet[i].handle, TRUE);
		}
	}
}

void EnemyExplosionDrawGraph(ExplosionParam* enemy_explosion)
{
	for (int i = 0; i < ENEMY_UNIT; i++)
	{
		if (enemy_explosion[i].active)
		{
			int srcX = enemy_explosion[i].rect.w * enemy_explosion[i].animNum;
			int srcY = 0;

			DrawRectGraph(enemy_explosion[i].rect.x,
				enemy_explosion[i].rect.y,
				srcX,	// SrcX
				srcY,	// SrcY
				enemy_explosion[i].rect.w,
				enemy_explosion[i].rect.h,
				enemy_explosion[i].handle,
				TRUE,
				FALSE);
		}
	}
}

void BossExplosionDrawGraph(ExplosionParam* boss_explosion)
{
	for (int i = 0; i < BOSS_EXPLOSION_COUNT; i++)
	{
		int offset_x[5] = { 48,-48,48,-48, 0 };
		int offset_y[5] = { 48,-48,-48,48, 0 };
		if (boss_explosion[i].active)
		{
			int srcX = boss_explosion[i].rect.w * boss_explosion[i].animNum;
			int srcY = 0;

			DrawRectGraph(
				boss_explosion[i].rect.x + offset_x[i],
				boss_explosion[i].rect.y + offset_y[i],
				srcX,	// SrcX
				srcY,	// SrcY
				boss_explosion[i].rect.w,
				boss_explosion[i].rect.h,
				boss_explosion[i].handle,
				TRUE,
				FALSE);
		}
	}
}
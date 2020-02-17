#include "CheckHit.h"
#include <math.h>

bool CheckHitCircle(const Circle& objA, const Circle& objB)
{

	int x = objA.x - objB.x;	//Xの長さ
	int y = objA.y - objB.y;	//Yの長さ
	//三平方の定理より、底辺の二乗と高さの二乗を足したものは斜辺の二乗
	double length = sqrt(double(x * x) + (y * y)); //objA,objBの距離

	bool hit = length <= (objA.r + objB.r);

	return hit;
}

void CheckHitEnemy(BulletParam* player_bullet, EnemyParam* enemy, ExplosionParam* enemy_explosion )
{
	for (int i = 0; i < PLAYER_BULLET_MAX; i++)
	{
		if (player_bullet[i].active == true)
		{
			for (int j = 0; j < ENEMY_UNIT; j++)
			{
				if (enemy[j].active == true)
				{
					Circle objA;
					Circle objB;

					objA.x = player_bullet[i].rect.x + (player_bullet[i].rect.w / 2);
					objA.y = player_bullet[i].rect.y + (player_bullet[i].rect.h / 2);
					objA.r = PLAYER_BULLET_RADIUS;
					objB.x = enemy[j].rect.x + (enemy[j].rect.w / 2);
					objB.y = enemy[j].rect.y + (enemy[j].rect.h / 2);
					objB.r = ENEMY_RADIUS;
					if (CheckHitCircle(objA,objB))
					{
						player_bullet[i].active = false;
						enemy[j].hp--;
						if (enemy[j].hp <= 0)
						{
							enemy[j].active = false;
							

							enemy_explosion[j].active = true;
							enemy_explosion[j].rect.x = enemy[j].rect.x;
							enemy_explosion[j].rect.y = enemy[j].rect.y;
						}


						break;
					}
				}
			}
		}
	}
	//爆発エフェクト
	for (int i = 0; i < ENEMY_UNIT; i++)
	{
		if (enemy_explosion[i].active == true)
		{
			enemy_explosion[i].animNum++;
			if (enemy_explosion[i].animNum > 7)
			{
				enemy_explosion[i].animNum = 0;
				enemy_explosion[i].active = false;
			}
		}
	}
}

void CheckHitBoss(BulletParam* player_bullet, BossParam* boss, ExplosionParam* boss_explosion )
{
	for (int i = 0; i < PLAYER_BULLET_MAX; i++)
	{
		if (player_bullet[i].active == true)
		{
			if (boss->active == true)
			{
				Circle objA;
				Circle objB;

				objA.x = player_bullet[i].rect.x + (player_bullet[i].rect.w / 2);
				objA.y = player_bullet[i].rect.y + (player_bullet[i].rect.h / 2);
				objA.r = PLAYER_BULLET_RADIUS;
				objB.x = boss->rect.x + (boss->rect.w / 2);
				objB.y = boss->rect.y + (boss->rect.h / 2);
				objB.r = BOSS_RADIUS;
				if (CheckHitCircle(objA,objB))
				{

					player_bullet[i].active = false;
					boss->hp--;
					if (boss->hp <= 0)
					{
						boss->active = false;
						
						for (int j = 0; j < BOSS_EXPLOSION_COUNT; j++)
						{
							boss_explosion[j].active = true;
							boss_explosion[j].rect.x = boss->rect.x;
							boss_explosion[j].rect.y = boss->rect.y;
						}

						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < BOSS_EXPLOSION_COUNT; i++)
	{
		if (boss_explosion[i].active == true)
		{
			boss_explosion[i].animNum++;
			if (boss_explosion[i].animNum > 7)
			{
				boss_explosion[i].animNum = 0;
				boss_explosion[i].active = false;
			}
		}
	}
}

void CheckHitPlayer(PlayerParam* player, BulletParam* boss_bullet)
{
	for (int i = 0; i < BOSS_SHOT_MAX; i++)
	{
		if (boss_bullet[i].active == true)
		{
			if (player->active)
			{
				Circle objA;
				Circle objB;

				objA.x = boss_bullet[i].rect.x + (boss_bullet[i].rect.w / 2);
				objA.y = boss_bullet[i].rect.y + (boss_bullet[i].rect.h / 2);
				objA.r = PLAYER_BULLET_RADIUS;
				objB.x = player->rect.x + (player->rect.w / 2);
				objB.y = player->rect.y + (player->rect.h / 2);
				objB.r = PLAYER_RADIUS;

				if (CheckHitCircle(objA, objB))
				{

					boss_bullet[i].active = false;
					player->active = false;
					break;
				}

			}
		}
	}
}

void CheckHitBossSpawn(BossParam* boss, EnemyParam* enemy)
{
	if (boss->hp >= 1 && boss->active == false)
	{
		int enemy_count = 0;
		for (int i = 0; i < ENEMY_UNIT; i++)
		{
			if (enemy[i].active == true)
			{
				enemy_count++;
			}
		}

		if (enemy_count == 0)
		{
			boss->active = true;
		}
	}
}
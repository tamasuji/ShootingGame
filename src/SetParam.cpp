#include "SetParam.h"

void SetRect(Rect* rect, int x, int y, int w, int h)
{
	rect->x = x;
	rect->y = y;
	rect->w = w;
	rect->h = h;
}

//プレイヤーの初期化処理
void SetPlayer(PlayerParam* player, int Graph)
{
	player->handle = Graph;
	SetRect(&player->rect, 320, 432, 48, 48);
	player->shotRepeatCounter = 0;
	player->active = true;
}

//エネミーの初期化処理
void SetEnemy(EnemyParam* enemy,int Graph) 
{
	for (int i = 0; i < ENEMY_UNIT; i++)
	{
		enemy[i].handle = Graph;
		SetRect(&enemy[i].rect, 48 * (i / 5), 48 * (i % 5), 48, 48);
		enemy[i].active = true;
		enemy[i].hp = 1;
		enemy[i].dir = 1;
	}
}

//爆発エフェクトの初期化処理(エネミー)
void SetEnemyExplosion(ExplosionParam* enemy_explosion, int Graph)
{
	for (int i = 0; i < ENEMY_UNIT; i++)
	{
		enemy_explosion[i].handle = Graph;
		SetRect(&enemy_explosion[i].rect, 320, 240, 48, 48);
		enemy_explosion[i].active = false;
		enemy_explosion[i].animNum = 0;
	}
}

//ボスの初期化処理
void SetBoss(BossParam* boss, int Graph)
{
	boss->handle = Graph;
	SetRect(&boss->rect, (48 * 5), (48 * 2), 90, 87);
	boss->active = false;
	boss->shot = false;
	boss->hp = 20;
	boss->count = 360;
	boss->dir = 1;
}

//爆発エフェクトの初期化処理(ボス)
void SetBossExplosion(ExplosionParam* boss_explosion, int Graph)
{
	for (int i = 0; i < BOSS_EXPLOSION_COUNT; i++)
	{
		boss_explosion[i].handle = Graph;
		SetRect(&boss_explosion[i].rect, 320, 240, 48, 48);
		boss_explosion[i].active = false;
		boss_explosion[i].animNum = 0;
	}
}

//プレイヤーの弾の初期化処理
void SetPlayerBullet(BulletParam* player_bullet, int Graph)
{
	for (int i = 0; i < PLAYER_BULLET_MAX; i++)
	{
		player_bullet[i].handle = Graph;
		SetRect(&player_bullet[i].rect, 0, 0, 16, 16);
		player_bullet[i].active = false;
	}
}

//ボスの弾の初期化処理
void SetBossBullet(BulletParam* boss_bullet, int Graph)
{
	for (int i = 0; i < BOSS_SHOT_MAX; i++)
	{
		boss_bullet[i].handle = Graph;
		SetRect(&boss_bullet[i].rect, 0, 0, 16, 16);
		boss_bullet[i].active = false;
	}
}

void SetBackGround(BackGroundParam* background, int Graph[BACKGROUND_LAYER])
{
	for (int i = 0; i < BACKGROUND_LAYER; i++)
	{
		SetRect(&background[i].rect, 0, 0, WINDOW_W, WINDOW_H);
		background[i].handle = Graph[i];
	}
}
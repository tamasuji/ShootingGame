#pragma once
#include "Definition.h"
#include "WinMain.h"
void SetRect(Rect* rect, int x, int y, int w, int h);
void SetPlayer(PlayerParam* player, int Graph);
void SetEnemy(EnemyParam* enemy, int Graph);
void SetEnemyExplosion(ExplosionParam* enemy_explosion, int Graph);
void SetBoss(BossParam* boss, int Graph);
void SetBossExplosion(ExplosionParam* boss_explosion, int Graph);
void SetPlayerBullet(BulletParam* player_bullet, int Graph);
void SetBossBullet(BulletParam* boss_bullet, int Graph);
void SetBackGround(BackGroundParam* background, int Graph[BACKGROUND_LAYER]);
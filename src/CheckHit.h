#pragma once
#include "Definition.h"

//円同士の当たり判定
//当たっていればTrueを返し、当たって無ければFalseを返す
bool CheckHitCircle(const Circle& objA, const Circle& objB);
void CheckHitEnemy(BulletParam* player_bullet, EnemyParam* enemy, ExplosionParam* enemy_explosion);
void CheckHitBoss(BulletParam* player_bullet, BossParam* boss, ExplosionParam* boss_explosion);
void CheckHitPlayer(PlayerParam* player, BulletParam* boss_bullet);
void CheckHitBossSpawn(BossParam* boss, EnemyParam* enemy);
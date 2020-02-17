#pragma once
#include "Definition.h"
#include "Winmain.h"

void PlayerControl(PlayerParam* player, BulletParam* player_bullet, int soundmem);
void EnemyControl(EnemyParam* enemy);
void BossControl(BossParam* boss, BulletParam* boss_bullet);
void PlayerBulletControl(BulletParam* player_bullet);
void BossBulletControl(BulletParam* boss_bullet);
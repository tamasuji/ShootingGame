#pragma once
#include "Definition.h"

//‰~“¯m‚Ì“–‚½‚è”»’è
//“–‚½‚Á‚Ä‚¢‚ê‚ÎTrue‚ğ•Ô‚µA“–‚½‚Á‚Ä–³‚¯‚ê‚ÎFalse‚ğ•Ô‚·
bool CheckHitCircle(const Circle& objA, const Circle& objB);
void CheckHitEnemy(BulletParam* player_bullet, EnemyParam* enemy, ExplosionParam* enemy_explosion);
void CheckHitBoss(BulletParam* player_bullet, BossParam* boss, ExplosionParam* boss_explosion);
void CheckHitPlayer(PlayerParam* player, BulletParam* boss_bullet);
void CheckHitBossSpawn(BossParam* boss, EnemyParam* enemy);
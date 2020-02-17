#pragma once
#define BACKGROUND_LAYER		3	//背景の層
#define ENEMY_UNIT				20	//敵機の数 
#define PLAYER_BULLET_MAX		6	//プレイヤーの弾の最大数
#define PLAYER_RADIUS			12	//プレイヤーの当たり判定の半径
#define PLAYER_SHOT_REPEAT		3	//繰り返し射撃用のリピートフレーム
#define PLAYER_BULLET_RADIUS	4	//プレイヤー弾の当たり判定の半径
#define ENEMY_RADIUS			12	//エネミーの当たり判定
#define BOSS_RADIUS				45	//ボスのあたり判定の半径
#define BOSS_EXPLOSION_COUNT	5	//ボスの爆発エフェクトの数
#define BOSS_SHOT_MAX			5	//ボスの弾の最大数
#define BOSS_SHOT_REPEAT		3	//ボスが弾を打つ間隔

//当たり判定円情報
struct Circle
{
	int x; //中心座標X
	int y; //中心座標Y
	int r; //円の半径
};
//画像の矩形情報
struct Rect
{
	int x; //中心座標X
	int y; //中心座標Y
	int w; //幅
	int h; //高さ
};

struct ExplosionParam
{
	Rect rect;
	int handle;
	bool active;
	int animNum;	//何番目か
};

struct BossExplosionParam
{
	Rect rect;
	int handle;
	bool active;
	int animNum;
};

//自機のパラメーター
struct PlayerParam
{
	Rect rect;
	int handle;
	int shotRepeatCounter;
	bool active;
};

//エネミーのパラメーター
struct EnemyParam
{
	Rect rect;
	int handle;
	bool active;
	int hp;
	int dir;
};

struct BossParam
{
	Rect rect;
	int handle;
	bool active;
	bool shot;
	int hp;
	int dir;
	int count;
};

//弾のパラメーター
struct BulletParam
{
	Rect rect;
	int handle;
	bool active;
};

struct BossBulletParam
{
	Rect rect;
	int handle;
	bool active;
};

struct BackGroundParam
{
	Rect rect;
	int handle;

};

struct SoundEffectParam
{
	int handle;
};


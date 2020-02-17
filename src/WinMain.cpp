#include "WinMain.h"
#include <math.h>
#include <stdio.h>


//引数をつかってRect構造体に値を設定する


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// DxLibのお約束：ウィンドウ作成と初期化
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetGraphMode(WINDOW_W, WINDOW_H, 32);
	SetBackgroundColor(125, 125, 125);
	SetMainWindowText("シューティングゲーム");
	if (DxLib_Init() == -1) { return -1; }
	SetDrawScreen(DX_SCREEN_BACK);

	//変数宣言
	PlayerParam			player;
	EnemyParam			enemy[ENEMY_UNIT];
	BossParam			boss;
	BulletParam			player_bullet[PLAYER_BULLET_MAX];
	BulletParam			boss_bullet[BOSS_SHOT_MAX];
	ExplosionParam		enemy_explosion[ENEMY_UNIT];
	ExplosionParam		boss_explosion[BOSS_EXPLOSION_COUNT];
	BackGroundParam		background[BACKGROUND_LAYER];
	SoundEffectParam	shotSE;
	
	
	
	
	//画像読み込み
	int	PlayerGraph			= LoadGraph("data/Ship/MyShip.png");
	int EnemyShip00Graph	= LoadGraph("data/Ship/EnemyShip00.png");
	int EnemyExplosionGraph = LoadGraph("data/Explosion/Explosion01.png");
	int BossShipGraph		= LoadGraph("data/Ship/Boss.png");
	int BossShotGraph		= LoadGraph("data/Bullet/Enemy_Bullet.png");
	int BossExplosionGraph	= LoadGraph("data/Explosion/Explosion00.png");
	int ShotGraph			= LoadGraph("data/Bullet/Player_Bullet.png");

	int BackGroundGraph[BACKGROUND_LAYER]
	{
		LoadGraph("data/Bg/background_back.png"),
		LoadGraph("data/Bg/background_middle.png"),
		LoadGraph("data/Bg/background_front.png") 
	};

	//メモリ読み込み
	int shotSoundMem = LoadSoundMem("data/SE/shoot.wav");
	int boomSoundMem = LoadSoundMem("data/SE/boom.wav");


	//プレイヤーの初期化処理
	SetPlayer(&player, PlayerGraph);
	//エネミーの初期化処理
	SetEnemy(enemy, EnemyShip00Graph);
	//エネミーの爆発エフェクトの初期化処理
	SetEnemyExplosion(enemy_explosion, EnemyExplosionGraph);
	//ボスの初期化
	SetBoss(&boss, BossShipGraph);
	//ボスの爆発エフェクトの初期化処理
	SetBossExplosion(boss_explosion, BossExplosionGraph);
	//プレイヤーの弾の初期化
	SetPlayerBullet(player_bullet, ShotGraph);
	//ボスの弾の初期化処理
	SetBossBullet(boss_bullet, BossShotGraph);
	//背景の初期化処理
	SetBackGround(background, BackGroundGraph);



	shotSE.handle = shotSoundMem;

	PlaySound("data/BGM/bgm.mp3", DX_PLAYTYPE_LOOP);

	// ゲームループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// DxLibのお約束：画面クリア
		ClearDrawScreen();
		clsDx();

		//背景スクロール
		for (int i = 0; i < BACKGROUND_LAYER; i++)
		{
			background[i].rect.y += (1 + i);
			if (background[i].rect.y >= WINDOW_H)
			{
				background[i].rect.y -= WINDOW_H;
			}
		}

		//PlayerControl
		PlayerControl(&player, player_bullet, shotSoundMem);
		//プレイヤーの弾の移動
		PlayerBulletControl(player_bullet);
		//enemycontroll
		EnemyControl(enemy);
		//bosscontrol
		BossControl(&boss, boss_bullet);
		//ボスの弾の移動
		BossBulletControl(boss_bullet);


		//当たり判定
		CheckHitEnemy(player_bullet, enemy, enemy_explosion);

		CheckHitBoss(player_bullet, &boss, boss_explosion);

		CheckHitPlayer(&player, boss_bullet);

		CheckHitBossSpawn(&boss, enemy);

		

		//描画処理
		BackGroundDrawGraph(background);
		PlayerDrawGraph(&player);
		EnemyDrawGraph(enemy);
		BossDrawGraph(&boss);
		PlayerBulletDrawGraph(player_bullet);
		BossBulletDrawGraph(boss_bullet);
		EnemyExplosionDrawGraph(enemy_explosion);
		BossExplosionDrawGraph(boss_explosion);

		// DxLibのお約束：画面更新
		ScreenFlip();
	}


	//後始末
	for (int i = 0; i < BACKGROUND_LAYER; i++)
	{
		DeleteGraph(BackGroundGraph[i]);
	}
	DeleteGraph(PlayerGraph);
	DeleteGraph(EnemyShip00Graph);
	DeleteGraph(ShotGraph);
	DeleteGraph(EnemyExplosionGraph);
	DeleteGraph(BossShipGraph);
	DeleteGraph(BossExplosionGraph);
	DeleteGraph(BossShotGraph);
	DeleteSoundMem(shotSoundMem);
	DeleteSoundMem(boomSoundMem);


	// DxLibのお約束：終了処理
	DxLib_End();

	return 0;
}

#pragma once
#define BACKGROUND_LAYER		3	//�w�i�̑w
#define ENEMY_UNIT				20	//�G�@�̐� 
#define PLAYER_BULLET_MAX		6	//�v���C���[�̒e�̍ő吔
#define PLAYER_RADIUS			12	//�v���C���[�̓����蔻��̔��a
#define PLAYER_SHOT_REPEAT		3	//�J��Ԃ��ˌ��p�̃��s�[�g�t���[��
#define PLAYER_BULLET_RADIUS	4	//�v���C���[�e�̓����蔻��̔��a
#define ENEMY_RADIUS			12	//�G�l�~�[�̓����蔻��
#define BOSS_RADIUS				45	//�{�X�̂����蔻��̔��a
#define BOSS_EXPLOSION_COUNT	5	//�{�X�̔����G�t�F�N�g�̐�
#define BOSS_SHOT_MAX			5	//�{�X�̒e�̍ő吔
#define BOSS_SHOT_REPEAT		3	//�{�X���e��łԊu

//�����蔻��~���
struct Circle
{
	int x; //���S���WX
	int y; //���S���WY
	int r; //�~�̔��a
};
//�摜�̋�`���
struct Rect
{
	int x; //���S���WX
	int y; //���S���WY
	int w; //��
	int h; //����
};

struct ExplosionParam
{
	Rect rect;
	int handle;
	bool active;
	int animNum;	//���Ԗڂ�
};

struct BossExplosionParam
{
	Rect rect;
	int handle;
	bool active;
	int animNum;
};

//���@�̃p�����[�^�[
struct PlayerParam
{
	Rect rect;
	int handle;
	int shotRepeatCounter;
	bool active;
};

//�G�l�~�[�̃p�����[�^�[
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

//�e�̃p�����[�^�[
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


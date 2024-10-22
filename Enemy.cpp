#include "Enemy.h"
#include <stdio.h>

Enemy::Enemy() :phase_(0){}

void (Enemy::* Enemy::Phase[])() 
= {
	&Enemy::Approach,
	&Enemy::Shot,
	&Enemy::Leave
};

void Enemy::Update()
{
	(this->*Phase[static_cast<size_t>(phase_)])();

    int select;
	printf("\n次のフェーズへ行こうするには0を処理を終了するには1を入力して下さい\n");
	scanf_s("%d", &select);

    if (select == 1) {
        printf("終了します。\n");
        return;
    }
    else if (select == 0) {
        if (phase_ == 2) {
            phase_ = 0;
        }
        else {
            phase_++;
        }
    }
    else {
        printf("無効な入力です。0または1を入力して下さい。\n");
    }

    Update();
}

void Enemy::Approach()
{
	printf("敵の接近！");
}

void Enemy::Shot()
{
	printf("敵の砲撃！");
}

void Enemy::Leave()
{
	printf("敵の離脱！");
}

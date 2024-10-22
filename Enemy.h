#pragma once

class Enemy {
public:
	Enemy();

	void Update();

	void Approach();

	void Shot();

	void Leave();
private:
	static void (Enemy::* Phase[])();

	size_t phase_;


};
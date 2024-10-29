#include "Hit.h"
#include "Scene.h"

void C_Hit::Map_Player()
{
	C_Player* player = m_hOwner->GetPlayer();
	
	const float playerRight  = player->GetPos().x + player->GetRadius();
	const float playerLeft   = player->GetPos().x - player->GetRadius();
	const float playerTop    = player->GetPos().y + player->GetRadius();
	const float playerBottom = player->GetPos().y - player->GetRadius();

	const float nextRight  = player->GetFuturePos().x + player->GetRadius();
	const float nextLeft   = player->GetFuturePos().x - player->GetRadius();
	const float nextTop    = player->GetFuturePos().y + player->GetRadius();
	const float nextBottom = player->GetFuturePos().y - player->GetRadius();

	C_Map* map = m_hOwner->GetMap();

	for (int h = 0; h < map->GetHeight(); h++) {
		for (int w = 0; w < map->GetWidth(); w++) {
			//0だったら残りの処理を飛ばす
			if (map->GetData(h, w) != 1)continue;
			
			const float mapRight  = map->GetPos(h, w).x + map->GetRadius();
			const float mapLeft   = map->GetPos(h, w).x - map->GetRadius();
			const float mapTop    = map->GetPos(h, w).y + map->GetRadius();
			const float mapBottom = map->GetPos(h, w).y - map->GetRadius();

			if (playerRight > mapLeft && playerLeft < mapRight) {
				//上からの当たり判定
				if (nextBottom < mapTop && nextTop > mapTop) {
					player->MapHitY(mapTop + player->GetRadius(), 0, false);
				}
				//下からの当たり判定
				else if (nextTop > mapBottom && nextBottom < mapBottom) {
					player->MapHitY(mapBottom - player->GetRadius(), 0, true);
				}
			}

			if (playerTop > mapBottom && playerBottom < mapTop) {
				//右からの当たり判定
				if (nextLeft < mapRight && nextRight > mapRight) {
					player->MapHitX(mapRight + player->GetRadius(), 0);
				}
				//左からの当たり判定
				else if (nextRight > mapLeft && nextLeft < mapLeft) {
					player->MapHitX(mapLeft - player->GetRadius(), 0);
				}
			}
		}
	}
}

void C_Hit::Map_Enemy()
{
	C_Enemy* enemy = m_hOwner->GetEnemy();

	const float enemyRight = enemy->GetPos().x + enemy->GetRadius();
	const float enemyLeft = enemy->GetPos().x - enemy->GetRadius();
	const float enemyTop = enemy->GetPos().y + enemy->GetRadius();
	const float enemyBottom = enemy->GetPos().y - enemy->GetRadius();

	const float nextRight = enemy->GetFuturePos().x + enemy->GetRadius();
	const float nextLeft = enemy->GetFuturePos().x - enemy->GetRadius();
	const float nextTop = enemy->GetFuturePos().y + enemy->GetRadius();
	const float nextBottom = enemy->GetFuturePos().y - enemy->GetRadius();

	C_Map* map = m_hOwner->GetMap();

	for (int h = 0; h < map->GetHeight(); h++) {
		for (int w = 0; w < map->GetWidth(); w++) {
			//0だったら残りの処理を飛ばす
			if (map->GetData(h, w) != 1)continue;

			const float mapRight = map->GetPos(h, w).x + map->GetRadius();
			const float mapLeft = map->GetPos(h, w).x - map->GetRadius();
			const float mapTop = map->GetPos(h, w).y + map->GetRadius();
			const float mapBottom = map->GetPos(h, w).y - map->GetRadius();

			if (enemyRight > mapLeft && enemyLeft < mapRight) {
				//上からの当たり判定
				if (nextBottom < mapTop && nextTop > mapTop) {
					enemy->MapHitY(mapTop + enemy->GetRadius(), 0);
				}
				//下からの当たり判定
				else if (nextTop > mapBottom && nextBottom < mapBottom) {
					enemy->MapHitY(mapBottom - enemy->GetRadius(), 0);
				}
			}

			if (enemyTop > mapBottom && enemyBottom < mapTop) {
				//右からの当たり判定
				if (nextLeft < mapRight && nextRight > mapRight) {
					enemy->MapHitX(mapRight + enemy->GetRadius(), 0);
				}
				//左からの当たり判定
				else if (nextRight > mapLeft && nextLeft < mapLeft) {
					enemy->MapHitX(mapLeft - enemy->GetRadius(), 0);
				}
			}
		}
	}
}

void C_Hit::Enemy_Player()
{
	C_Player* player = m_hOwner->GetPlayer();
	C_Enemy* enemy = m_hOwner->GetEnemy();

	const float x = enemy->GetPos().x	- player->GetPos().x;
	const float y = enemy->GetPos().y - player->GetPos().y;
	const float c = sqrt(x * x + y * y);

	const float sumRadius = player->GetRadius() + enemy->GetRadius();

	//距離判定
	if (c < sumRadius) {
		player->SetAlive(false);
	}

}

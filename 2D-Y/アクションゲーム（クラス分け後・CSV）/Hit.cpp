#include "Hit.h"
#include "Scene.h"

void C_Hit::Enemy_Player(int num)
{
	C_Player* player = m_hOwner->GetPlayer();
	C_Enemy* enemy = m_hOwner->GetEnemy(num);

	const float x = enemy->GetPos().x	- player->GetPos().x;
	const float y = enemy->GetPos().y - player->GetPos().y;
	const float c = sqrt(x * x + y * y);

	const float sumRadius = player->GetRadius() + enemy->GetRadius();

	//距離判定
	if (c < sumRadius) {
		player->SetAlive(false);
	}

}

void C_Hit::MapRectHit(C_CharaBase* base)
{
	if (base == nullptr)return;

	const float baseRight = base->GetPos().x + base->GetRadius();
	const float baseLeft = base->GetPos().x - base->GetRadius();
	const float baseTop = base->GetPos().y + base->GetRadius();
	const float baseBottom = base->GetPos().y - base->GetRadius();

	const float nextRight = base->GetFuturePos().x + base->GetRadius();
	const float nextLeft = base->GetFuturePos().x - base->GetRadius();
	const float nextTop = base->GetFuturePos().y + base->GetRadius();
	const float nextBottom = base->GetFuturePos().y - base->GetRadius();

	C_Map* map = m_hOwner->GetMap();

	for (int h = 0; h < map->GetHeight(); h++) {
		for (int w = 0; w < map->GetWidth(); w++) {
			//0だったら残りの処理を飛ばす
			if (map->GetData(h, w) != 1)continue;

			const float mapRight = map->GetPos(h, w).x + map->GetRadius();
			const float mapLeft = map->GetPos(h, w).x - map->GetRadius();
			const float mapTop = map->GetPos(h, w).y + map->GetRadius();
			const float mapBottom = map->GetPos(h, w).y - map->GetRadius();

			if (baseRight > mapLeft && baseLeft < mapRight) {
				//上からの当たり判定
				if (nextBottom < mapTop && nextTop > mapTop) {
					base->MapHitY(mapTop + base->GetRadius(), 0, false);
				}
				//下からの当たり判定
				else if (nextTop > mapBottom && nextBottom < mapBottom) {
					base->MapHitY(mapBottom - base->GetRadius(), 0, true);
				}
			}

			if (baseTop > mapBottom && baseBottom < mapTop) {
				//右からの当たり判定
				if (nextLeft < mapRight && nextRight > mapRight) {
					base->MapHitX(mapRight + base->GetRadius(), 0);
				}
				//左からの当たり判定
				else if (nextRight > mapLeft && nextLeft < mapLeft) {
					base->MapHitX(mapLeft - base->GetRadius(), 0);
				}
			}
		}
	}
}

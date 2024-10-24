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
			//0‚¾‚Á‚½‚çŽc‚è‚Ìˆ—‚ð”ò‚Î‚·
			if (map->GetData(h, w) != 1)continue;

			const float mapRight  = map->GetPos(h, w).x + map->GetRadius();
			const float mapLeft   = map->GetPos(h, w).x - map->GetRadius();
			const float mapTop    = map->GetPos(h, w).y + map->GetRadius();
			const float mapBottom = map->GetPos(h, w).y - map->GetRadius();

			if (playerRight > mapLeft && playerLeft < mapRight) {
				//ã‚©‚ç‚Ì“–‚½‚è”»’è
				if (nextBottom < mapTop && nextTop > mapTop) {
					player->MapHitY(mapTop + player->GetRadius(), 0, false);
				}
				//‰º‚©‚ç‚Ì“–‚½‚è”»’è
				else if (nextTop > mapBottom && nextBottom < mapBottom) {
					player->MapHitY(mapBottom - player->GetRadius(), 0, true);
				}
			}

			if (playerTop > mapBottom && playerBottom < mapTop) {
				//‰E‚©‚ç‚Ì“–‚½‚è”»’è
				if (nextLeft < mapRight && nextRight > mapRight) {
					player->MapHitX(mapRight + player->GetRadius(), 0);
				}
				//¶‚©‚ç‚Ì“–‚½‚è”»’è
				else if (nextRight > mapLeft && nextLeft < mapLeft) {
					player->MapHitX(mapLeft - player->GetRadius(), 0);
				}
			}
		}
	}
}

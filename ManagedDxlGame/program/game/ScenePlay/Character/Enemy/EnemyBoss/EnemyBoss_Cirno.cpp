#include "EnemyBoss_Cirno.h"
#include "../../../Bullet/Enemy/BulletHell.h"

namespace inl {

	std::vector<Shared<EnemyBullet>> EnemyBoss_Cirno::_bullet_normal_cirno;
	std::vector<Shared<EnemyBullet>> EnemyBoss_Cirno::_bullet_icicleFall_cirno;
	std::vector<Shared<EnemyBullet>> EnemyBoss_Cirno::_bullet_perfectFreeze_cirno;
	bool EnemyBoss_Cirno::_isUsingBullet_normal_cirno;
	bool EnemyBoss_Cirno::_isUsingBullet_icicleFall_cirno;
	bool EnemyBoss_Cirno::_isUsingBullet_perfectFreeze_cirno;


	EnemyBoss_Cirno::EnemyBoss_Cirno(const EnemyBossInfo& info) : EnemyBossBase(info) {

		_collideSize = { 50,50,50 };
		_at = 6;

		_WARPING_DURATION = 8.0f;
	}


	void EnemyBoss_Cirno::SetMeshInfo() {

		Shared<CustomException> cus = std::make_shared<CustomException>();

		auto texture =
			cus->TryLoadTexture("graphics/bossTexture/Cirno.png", "inl::EnemyBoss_Cirno::SetMeshInfo()");

		_mesh = dxe::Mesh::CreateCubeMV(100);
		_mesh->setTexture(texture);

		_mesh->pos_ = { 0, 0, 0 };
		_mesh->scl_ = { 1.0f, 1.0f, 1.0f };
	}


	void EnemyBoss_Cirno::InitBulletHellInstance() {

		_bulletHell = std::make_shared<BulletHell>(_mesh);
	}


	void EnemyBoss_Cirno::AttackPlayer(const float deltaTime) {

		if (!_bulletHell) return;

		if (4 == EnemyBossBase::_bossHp.size() || 2 == EnemyBossBase::_bossHp.size()) {

			_isUsingBullet_normal_cirno = true;
			_bulletHell->ShotBulletHell_Normal_Cirno(deltaTime);

			CheckCollision_BulletHellBulletsAndPlayer_DRY(_bullet_normal_cirno);
		}
		else {
			_isUsingBullet_normal_cirno = false;
		}

		if (3 == EnemyBossBase::_bossHp.size()) {
			_isUsingBullet_icicleFall_cirno = true;
			_bulletHell->ShotBulletHell_IcicleFall_Cirno(deltaTime);

			CheckCollision_BulletHellBulletsAndPlayer_DRY(_bullet_icicleFall_cirno);
		}
		else {
			_isUsingBullet_icicleFall_cirno = false;
		}

		if (1 == EnemyBossBase::_bossHp.size()) {
			_isUsingBullet_perfectFreeze_cirno = true;
			_bulletHell->ShotBulletHell_PerfectFreeze_Cirno(deltaTime);

			CheckCollision_BulletHellBulletsAndPlayer_DRY(_bullet_perfectFreeze_cirno);
		}
		else {
			_isUsingBullet_perfectFreeze_cirno = false;
		}
	}



	void EnemyBoss_Cirno::DoRoutineMoves(const float deltaTime) {

		LookAtPlayer();

		ActKeepDistanceToPlayer(deltaTime);

		WarpToRandomPos(deltaTime);

		AttackPlayer(deltaTime);
	}


	void EnemyBoss_Cirno::RenderBossSpellCardName() {
		int x = 650;
		int y = 700;

		std::string spell = "Spell:";

		SetFontSize(17);
		switch (EnemyBossBase::_bossHp.size())
		{
		case 4:
			DrawFormatString(x, y, -1, "%sNormal", spell.c_str());        break;
		case 3:
			DrawFormatString(x, y, -1, "%sIcicleFall", spell.c_str());    break;
		case 2:
			DrawFormatString(x, y, -1, "%sNormal", spell.c_str());        break;
		case 1:
			DrawFormatString(x, y, -1, "%sPerfectFreeze", spell.c_str()); break;
		}
		SetFontSize(DEFAULT_FONT_SIZE);
	}


	void EnemyBoss_Cirno::Render() {

		if (_isDead) return;

		_mesh->render(ScenePlay::GetInstance()->_mainCamera);

		ShowHpGage_EnemyBoss();
		RenderBossSpellCardName();
	}


	bool EnemyBoss_Cirno::Update(const float deltaTime) {

		if (_isDead) return false;

		DoRoutineMoves(deltaTime);
		return true;
	}
}
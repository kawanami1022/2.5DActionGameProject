#pragma once
#include "BaseScene.h"
#include <memory>
#include <vector>
#include <string>

class AssetManager;
class EntityManager;
class Environment;
class EffectManager;
class CombatManager;

class EndingScene :
    public BaseScene
{
    friend Environment;
    friend class BombEquip;
    friend class SwordEquip;
    friend class BombShot;
    friend class ShurikenShot;
    friend class MeleeAttack;
    friend class EnergyBullet;
    friend class FlyingEye;
    friend class Mushroom;
    friend class Skeleton;
private:
    std::unique_ptr<AssetManager> assetMng_;
    void Update(const float& deltaTime) override;
    void FadeInUpdate(const float& deltaTime);
    void GameUpdate(const float& deltaTime);

    void Render() override;
public:
    EndingScene(SceneManager&, KeyboardInput&);
    ~EndingScene();
};


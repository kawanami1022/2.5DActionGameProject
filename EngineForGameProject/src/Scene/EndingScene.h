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
    bool isBossAdded = false;
    float timer_ = 0.0f;

    using UpdateFunc_t = void(EndingScene::*)(const float&);
    UpdateFunc_t updateFunc_;
    using RenderFunc_t = void(EndingScene::*)();
    RenderFunc_t renderFunc_;


    std::unique_ptr<AssetManager> assetMng_;
    void Update(const float& deltaTime) override;
    void FadeInUpdate(const float& deltaTime);
    void GameUpdate(const float& deltaTime);

    void Render() override;
public:
    EndingScene(SceneManager&, KeyboardInput&);
    ~EndingScene();
};


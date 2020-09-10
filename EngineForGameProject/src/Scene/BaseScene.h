#pragma once

#include <memory>

class SceneManager;
class KeyboardInput;

class BaseScene
{
protected:
	BaseScene(SceneManager&,KeyboardInput&);
	SceneManager& sceneMng_;
	KeyboardInput& sceneInput_;
	unsigned int frame_=0;
public:
	virtual ~BaseScene() = default;

	virtual void ProcessInput() = 0;
	virtual void Update(const float& deltaTime) = 0;
	virtual void Render() = 0;
	
};


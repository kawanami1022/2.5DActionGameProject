#pragma once

class Entity;

class Component
{
public:
	Component(Entity& owner);
	virtual ~Component() = default;
	virtual void Initialize() = 0;
	virtual void Update(const float& deltaTime) = 0;
	virtual void Render() = 0;
protected:
	Entity& owner_;
};


#pragma once

#include <vector>

#include "DynamicObject.h"

class DestroyableGroundObject;

class Bomb : public DynamicObject
{
public:

	static const uint16_t BombCost = 10; // ��������� ����� � �����

	void Draw() const override;

	void Accept(const Visitor& v) override;

	DestroyableGroundObject* CheckDestoyableObjects();

	void addObserver(DestroyableGroundObject* obj);

private:
	std::vector<DestroyableGroundObject*> observerVec;
};


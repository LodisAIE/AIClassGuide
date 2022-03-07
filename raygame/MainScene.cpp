#include "MainScene.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Player.h"
#include "Agent.h"
#include "SeekComponent.h"

void MainScene::start()
{
	Player* player = new Player(50, 50, "Player");
	player->getTransform()->setScale({ 50,50 });
	player->addComponent(new SpriteComponent("Images/player.png"));
	MoveComponent* playerMove = player->addComponent<MoveComponent>();

	Agent* agent = new Agent();
	agent->getTransform()->setScale({ 50,50 });
	agent->setMaxForce(50);
	agent->addComponent(new SpriteComponent("Images/enemy.png"));
	SeekComponent* comp = new SeekComponent();
	comp->setTarget(player);
	agent->addComponent(comp);
	addActor(player);
	addActor(agent);
}

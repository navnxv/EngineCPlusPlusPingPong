//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.cpp
// implementation of MyGame, an implementation of exGameInterface
//

#include "Game/Private/Game.h"

#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h"
#include "RenderComponent.h"
#include "PhysicsManager.h"
#include "RenderManager.h"
#include "TopBlockerComponent.h"
#include "BottomBlockerComponent.h"
#include "BallComponent.h"
#include "CircleCollider.h"
#include <cstdlib>
#include <ctime>

float random = 0;

//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* gWindowName = "Sample EngineX Game";

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::MyGame()
	: m_Engine( nullptr )
	, m_FontID( -1 )
	, m_UpP1( false )
	, m_UpP2( false )
	, m_DownP1( false )
	, m_DownP2( false )
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::~MyGame()
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Initialize(exEngineInterface* pEngine)
{
	
	m_Engine = pEngine;

	m_FontID = m_Engine->LoadFont("Resources/Nunito-Regular.ttf", 32);

	m_PaddleLeftGO = new GameObject();
	m_PaddleLeft = new PaddleLeft({30.0f, 230.0f} , {50.0f, 330.0f}, m_PaddleLeftGO);
	m_PaddleLeft->Initialize();
	//m_PaddleRightGO->SetTransform(m_PaddleLeft->GetTransformTop());

	m_PaddleRightGO = new GameObject();
	m_PaddleRight = new PaddleRight({ 730.0f, 230.0f }, { 750.0f, 330.0f }, m_PaddleRightGO);
	m_PaddleRight->Initialize();
	//m_PaddleRightGO->SetTransform(m_PaddleRight->GetTransformTop());


	m_TopBlockerComponent = new GameObject();
	m_TopBlockerComponent->AddComponent(new TopBlockerComponent(m_TopBlockerComponent));
	m_TopBlockerComponent->Initialize();

	m_BottomBlockerComponent = new GameObject();
	m_BottomBlockerComponent->AddComponent(new BottomBlockerComponent(m_BottomBlockerComponent));
	m_BottomBlockerComponent->Initialize();

	m_BallComponentGO = new GameObject();
	m_BallComponent = new BallComponent(m_BallComponentGO, { 400.0f, 275.0 });
	m_BallComponent->Initialize();
	

	m_TextPosition.x = 50.0f;
	m_TextPosition.y = 50.0f;


	std::srand(std::time(nullptr));

	int random_num = std::rand() % 2;

	if (random_num == 0) {
		random_num = -2;
	}
	else {
		random_num = 2;
	}

	random = random_num;
}


//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* MyGame::GetWindowName() const
{
	return gWindowName;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::GetClearColor( exColor& color ) const
{
	color.mColor[0] = 128;
	color.mColor[1] = 128;
	color.mColor[2] = 128;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEvent( SDL_Event* pEvent )
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEventsConsumed()
{
	int nKeys = 0;
	const Uint8 *pState = SDL_GetKeyboardState( &nKeys );

	m_UpP1 = pState[SDL_SCANCODE_W];
	m_DownP1 = pState[SDL_SCANCODE_S];

	m_UpP2 = pState[SDL_SCANCODE_UP];
	m_DownP2 = pState[SDL_SCANCODE_DOWN];
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Run( float fDeltaT )
{
	exVector2 temp = { 0,0 };

	if (m_UpP1)
	{
		temp = {0, -40.0f * fDeltaT *5};
	}
	else if (m_DownP1)
	{
		temp = {0, 40.0f * fDeltaT*5};
	}

	if ((m_PaddleLeft->GetTransformTop() + temp).y >= 30.0f && (m_PaddleLeft->GetTransformBottom() + temp).y <= 557.0f)
	{
		m_PaddleLeft->SetTransform(m_PaddleLeft->GetTransformTop() + temp, m_PaddleLeft->GetTransformBottom() + temp);
		m_PaddleRightGO->SetTransform(m_PaddleLeft->GetTransformTop() + temp);
	}


	exVector2 temp2 = { 0,0 };

	if (m_UpP2)
	{
		temp2 = { 0, -40.0f * fDeltaT * 5 };
	}
	else if (m_DownP2)
	{
		temp2 = { 0, 40.0f * fDeltaT * 5 };
	}

	if ((m_PaddleRight->GetTransformTop() + temp2).y >= 30.0f && (m_PaddleRight->GetTransformBottom() + temp2).y <= 557.0f)
	{
		m_PaddleRight->SetTransform(m_PaddleRight->GetTransformTop() + temp2, m_PaddleRight->GetTransformBottom() + temp2);
		//m_PaddleRightGO->SetTransform(m_PaddleRight->GetTransformTop() + temp2);
	}


	if (m_BallComponent->GetTranform().x < -10.0f || m_BallComponent->GetTranform().x > 810.0f)
	{
		int random_num = std::rand() % 2;

		/*if (random_num == 0) {
			random_num = -2;
		}
		else {
			random_num = 2;
		}*/

		random = random_num;
		m_BallComponent->SetTransform({ 400.0f, 275.0 });
	}

	exVector2 tempBall = { 0,0 };
	tempBall = { m_BallComponent->GetTranform().x + (-2), m_BallComponent->GetTranform().y + random};
	m_BallComponentGO->SetTransform(tempBall);
	m_BallComponent->SetTransform(tempBall);

	for (RenderComponent* componentIterator : RenderComponent::mAllRenderingComponents)
	{
		componentIterator->Render(m_Engine);
	}
	RENDER_MANAGER->RenderObjects(m_Engine);
	PHYSICS_MANAGER->CalculatePhysics();
}

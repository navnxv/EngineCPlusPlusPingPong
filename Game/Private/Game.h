//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.h
// definition of MyGame, an implementation of exGameInterface
//

#include "Game/Public/GameInterface.h"
#include "Engine/Public/EngineTypes.h"
#include "PaddleLeft.h"
#include "PaddleRight.h"
#include "BallComponent.h"
#include "CircleCollider.h"

//-----------------------------------------------------------------
//-----------------------------------------------------------------
class Error;
class SpaceshipComponent; 
class MyGame : public exGameInterface
{
public:

								MyGame();
	virtual						~MyGame();

	virtual void				Initialize( exEngineInterface* pEngine );

	virtual const char*			GetWindowName() const;
	virtual void				GetClearColor( exColor& color ) const;

	virtual void				OnEvent( SDL_Event* pEvent );
	virtual void				OnEventsConsumed();

	virtual void				Run( float fDeltaT );

private:

	exEngineInterface*			m_Engine;

	int							m_FontID;

	bool						m_UpP1;
	bool						m_UpP2;
	bool						m_DownP1;
	bool						m_DownP2;

	bool						m_Right;
	bool						m_Left;

	exVector2					m_TextPosition;


	GameObject* m_PaddleLeftGO;
	PaddleLeft* m_PaddleLeft;

	GameObject* m_PaddleRightGO;
	PaddleRight* m_PaddleRight;


	GameObject* m_TopBlockerComponent;
	GameObject* m_BottomBlockerComponent;

	GameObject* m_BallComponentGO;
	BallComponent* m_BallComponent;

	PhysicsComponent* physicsComponent;

};

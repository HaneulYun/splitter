#include <Windows.h>
#include <time.h>
#include <vector>
#include <deque>
#include <atlimage.h>
#include <fmod.hpp>

#define PI	3.141592

#include "Matrix.h"
#include "Vertex.h"
#include "Vector.h"

#include "Timer.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "SoundManager.h"

#include "Gdi.h"
#include "BaseRender.h"
#include "BaseObject.h"

#include "ImageObject.h"
#include "Text.h"
#include "ButtonObject.h"

#include "VFXBase.h"
#include "DestroyFX.h"
#include "ShellFX.h"
#include "TearElement.h"
#include "TearFX.h"
#include "AfterimageFX.h"
#include "EffectManager.h"

#include "BulletBase.h"
#include "BulletStraight.h"
#include "BulletManager.h"

#include "EnemyBase.h"
#include "EnemyComingRectangle.h"
#include "EnemyRotatingRectangle.h"
#include "EnemyRotatingTwoTriangleUp.h"
#include "EnemyRotatingTwoTriangleDown.h"
#include "EnemyRotatingTriangleHavingShield.h"
#include "EnemyRotatingTriangleShield.h"
#include "EnemyComingFastSpear.h"
#include "EnemySwirlingPentagon.h"
#include "EnemyCorpsBossRectangle.h"
#include "EnemyCorpsMiniRectangle.h"
#include "EnemyHalfSegment.h"
#include "Player.h"
#include "EnemyManager.h"

#include "IProcess.h"
#include "BaseScene.h"

#include "SceneNULL.h"
#include "IntroScene.h"
#include "OptionScene.h"
#include "GameSceneBase.h"
#include "Stage01Scene.h"
#include "EndlessModeScene.h"
#include "MenuScene.h"
#include "GameoverScene.h"
#include "NILScene.h"

#include "BaseWindow.h"
#include "WndSystem.h"
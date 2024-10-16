#include "GameObject.h"

using namespace std;

class GameTitle : public GameObject
{
protected:
	virtual void prepareBrush();
public:			
	GameTitle(float x = 50, float y = 28); //Set coordinates
};


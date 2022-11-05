#include "esp_random.h"
#include "MathProxy.h"
#include<stdlib.h>
int MathProxy::proxyFloor (float x)
{
	return (int) floor(x);
}
int MathProxy::proxyCeil (float x)
{
	return (int) ceil(x);
}
int MathProxy::proxyRound (float x)
{
	return (int) round(x);
}
float MathProxy::proxyAbs (float x)
{
	return abs(x);
}
int MathProxy::getRandomInt(int min, int max)
{
	return min + (random() % (max-min));
}
bool MathProxy::getRandomBool()
{
	return getRandomInt(1,2)==1;
}
int MathProxy::getRandomWay(){
	return getRandomInt(1,2)==1?1:-1;
}


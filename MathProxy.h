#ifndef MATH_PROXY_H
#define MATH_PROXY_H

#include <math.h>
class MathProxy
{
	public:
		static int proxyFloor(float x);
		static int proxyCeil(float x);
		static int proxyRound(float x);
		static float proxyAbs(float x);
		static int getRandomInt(int min, int max);
		static bool getRandomBool();
		static int getRandomWay();
};
#endif

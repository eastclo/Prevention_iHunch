#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <cstring>
#include <thread>
#include <mutex>
#include <cmath>
#include <ctime>
#include <queue>

#define BAD 0
#define GOOD 1
#define SKIP 2
class RecordTime {
public:
	int status;
	clock_t prev;
	clock_t alarmed;

	RecordTime() {
		status = -1;
		prev = 0;
		alarmed = 0;
	};
};

class Point {
public:
	int x, y;

	Point() {
		x = -1, y = -1;
	}
	Point(int x, int y) : x(x), y(y) {}
	Point operator+(Point& ref) {
		return Point(x + ref.x, y + ref.y);
	}
	Point operator/(const int &ref) {
		return Point(x/ref, y/ref);
	}
};

class Points {
public:
	Point Nose, rEye, lEye, lEar, rEar, lShoulder, rShoulder, Neck;
	Points() : Nose(), rEye(), lEye(), lEar(), rEar(), lShoulder(), rShoulder(), Neck() {}
	Points(Point Nose, Point rEye, Point lEye, Point lEar, Point rEar, Point lSoulder, Point rShoulder, Point Neck)
		: Nose(Nose), rEye(rEye), lEye(lEye), lEar(lEar), rEar(rEar), lShoulder(lShoulder), rShoulder(rShoulder), Neck(Neck) {}

	int length(Point A, Point B) {
		int x = A.x - B.x;
		int y = A.y - B.y;
		return sqrt(x * x + y * y);
	};
	bool isPointExist(Point A) {
		return !(A.x == -1 || A.y == -1);
	};
	Points operator+(Points &ref) {
		return Points(Nose + ref.Nose, rEye + ref.rEye, lEye + ref.lEye, lEar + ref.lEar,
			rEar + ref.rEar, lShoulder + ref.lShoulder, rShoulder + ref.rShoulder, Neck + ref.Neck);
	}
	Points operator/(const int &ref) {
		return Points(Nose/ref, rEye/ref, lEye/ref, lEar/ref,
			rEar/ref, lShoulder/ref, rShoulder/ref, Neck/ref);
	}
};

int startFix(void);
void editChildProccessPath(char* path);
int ConnectClient(HANDLE hNamePipe);
void checkEndSignal(bool sign);
void judgePose();
void operatorQueue(Points *ret, bool how);
bool judge(Points cur);
int setSTDPose(); //초기 자세 설정
int ConnectClient2(HANDLE hNamePipe); //초기 자세 설정
void sendText(); 
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int WARRIOR_NUM=5;

class Headquarter;

// 武士类
class Warrior {
    public:
    // 静态变量表示各种武士名和初始生命值
        static string names[WARRIOR_NUM];
        static int initialLifeValue[WARRIOR_NUM];
    private:
        Headquarter *pHeadquarter;
        int id; // id
        int typeId; // 类别

    public:
        Warrior(Headquarter *p, int id, int typeId) {
            this->pHeadquarter = p;
            this->id = id;
            this->typeId = typeId;
        }
        void printResult(int nTime);
};

// 司令部类
class Headquarter {
    public:
        static int makingSeq[2][WARRIOR_NUM];
    private:
        int color; // 颜色，红魔军司令部，蓝魔军司令部
        int totalLifeValue; // 生命元
        bool isStopped;

        Warrior * pWarrior[1000];
        int curMakingSeqIdx;
        int warriorNum[WARRIOR_NUM];
        int totalWarriorNum;
    public:
        friend class Warrior;

        void init(int color, int lv) {
            this->color = color;
            totalLifeValue = lv;
            isStopped = false;
            curMakingSeqIdx = 0;
            for (int i = 0; i < WARRIOR_NUM; i++)
                warriorNum[i] = 0;
            totalWarriorNum = 0;
        }

        // 武士消亡
        ~Headquarter() {
            for (int i = 0; i < totalWarriorNum; i++)
                delete pWarrior[i];
        }

        string getColor() {
            return color == 0 ? "red" : "blue";
        }

        int produce(int nTime);
};

string Warrior::names[WARRIOR_NUM] = {"dragon", "ninja", "iceman", "lion", "wolf"};
int Warrior::initialLifeValue[WARRIOR_NUM];
// 两个司令部武士的制作顺序序列
int Headquarter::makingSeq[2][WARRIOR_NUM] = {{2, 3, 4, 1, 0}, {3, 0, 1, 2, 4}};

// 输出出生信息
void Warrior::printResult(int nTime) {
    string color = pHeadquarter->getColor();
    printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n", nTime,
    color.c_str(), names[typeId].c_str(), id, initialLifeValue[typeId], pHeadquarter->warriorNum[typeId],
    names[typeId].c_str(), color.c_str());
}

// 制造武士
int Headquarter::produce(int nTime) {
    if (isStopped) {
        return 1;
    }
    // 寻找当前生命元能制造的武士
    int count = 0;
    while (totalLifeValue < Warrior::initialLifeValue[makingSeq[color][curMakingSeqIdx]] && count < WARRIOR_NUM) {
        curMakingSeqIdx = (curMakingSeqIdx + 1) % WARRIOR_NUM;
        count++;
    }
    int typeId = makingSeq[color][curMakingSeqIdx];
    if (Warrior::initialLifeValue[typeId] > totalLifeValue) {
        isStopped = true;
        printf("%03d %s headquarter stops making warriors\n", nTime, getColor().c_str());
        return 1;
    }

    // 制造武士
    totalLifeValue -= Warrior::initialLifeValue[typeId];
    pWarrior[totalWarriorNum] = new Warrior(this, totalWarriorNum + 1, typeId);
    curMakingSeqIdx = (curMakingSeqIdx + 1) % WARRIOR_NUM;
    warriorNum[typeId]++;
    pWarrior[totalWarriorNum++]->printResult(nTime);
    return 0;
}

int main() {
    int n, totalLifeValue;
    Headquarter redHead, blueHead;
    scanf("%d", &n);
    int caseNo = 1;
    while (n--) {
        printf("Case:%d\n", caseNo++);
        scanf("%d", &totalLifeValue);
        for (int i = 0; i < WARRIOR_NUM; i++)
            scanf("%d", &Warrior::initialLifeValue[i]);

        redHead.init(0, totalLifeValue);
        blueHead.init(1, totalLifeValue);

        int nTime = 0;
        while (true) {
            int isRedStopped = redHead.produce(nTime);
            int isBlueStopped = blueHead.produce(nTime++);
            if (isRedStopped == 1 && isBlueStopped == 1)
                break;
        }
    }
    return 0;
}

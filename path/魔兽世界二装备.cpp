#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int WARRIOR_NUM = 5;

class Headquarter;

class Weapon {
    public:
        static string names[3];
    private:
        int typeId;
    public:
        Weapon(int typeId) {
            this->typeId = typeId;
        }
        string getName() {
            return names[typeId];
        }
};

//  武士基类
class Warrior {
    public:
    // 静态变量表示各种武士名和初始生命值
        static string names[WARRIOR_NUM];
        static int initialLifeValue[WARRIOR_NUM];
    public:
        Headquarter *pHeadquarter;
        int id; // id
        int typeId; // 类别

    public:
        Warrior(Headquarter *p, int id) {
            this->pHeadquarter = p;
            this->id = id;
        }
        virtual void printResult(int nTime); // 加virtual才能实现多态
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

        int getTotalLifeValue() {
            return totalLifeValue;
        }

        string getColor() {
            return color == 0 ? "red" : "blue";
        }

        int produce(int nTime);
};

// 龙兵
class Dragon:public Warrior {
    private:
        Weapon *pWeapon;
        double morale;
    public:
        Dragon(Headquarter *p, int id): Warrior(p, id) {
            typeId = 0;
            pWeapon = new Weapon(id % 3);
            morale = 1.0 * pHeadquarter->getTotalLifeValue() / Warrior::initialLifeValue[0];
        }
        ~Dragon() {
            delete pWeapon;
        }
        void printResult(int nTime) {
            Warrior::printResult(nTime);
            printf("It has a %s,and it's morale is %.2f\n", pWeapon->getName().c_str(), morale);
        }
};

class Ninja:public Warrior {
    private:
        Weapon * pWeapon1, *pWeapon2;
    public:
        Ninja(Headquarter *p, int id): Warrior(p, id) {
            typeId = 1;
            pWeapon1 = new Weapon(id % 3);
            pWeapon2 = new Weapon((id + 1) % 3);
        }
        ~Ninja() {
            delete pWeapon1;
            delete pWeapon2;
        }
        void printResult(int nTime) {
            Warrior::printResult(nTime);
            printf("It has a %s and a %s\n", pWeapon1->getName().c_str(), pWeapon2->getName().c_str());
        }
};

class Iceman:public Warrior {
    private:
        Weapon *pWeapon;
    public:
        Iceman(Headquarter *p, int id): Warrior(p, id) {
            typeId = 2;
            pWeapon = new Weapon(id % 3);
        }
        ~Iceman() {
            delete pWeapon;
        }
        void printResult(int nTime) {
            Warrior::printResult(nTime);
            printf("It has a %s\n", pWeapon->getName().c_str());
        }
};

class Lion:public Warrior {
    private:
        int loyalty;
    public:
        Lion(Headquarter *p,int id): Warrior(p, id) {
            typeId = 3;
            loyalty = pHeadquarter->getTotalLifeValue();
        }
        void printResult(int nTime) {
            Warrior::printResult(nTime);
            printf("It's loyalty is %d\n", loyalty);
        }
};

class Wolf:public Warrior {
    public:
        Wolf(Headquarter *p, int id): Warrior(p, id) {
            typeId = 4;
        }
};

void Warrior::printResult(int nTime) {
    string color = pHeadquarter->getColor();
    printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n", nTime, color.c_str(),
    names[typeId].c_str(), id, initialLifeValue[typeId], pHeadquarter->warriorNum[typeId],
    names[typeId].c_str(), color.c_str());
}

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
    Warrior *p = NULL;
    switch (typeId) {
        case 0:
            p = new Dragon(this, totalWarriorNum + 1);
            break;
        case 1:
            p = new Ninja(this, totalWarriorNum + 1);
            break;
        case 2:
            p = new Iceman(this, totalWarriorNum + 1);
            break;
        case 3:
            p = new Lion(this, totalWarriorNum + 1);
            break;
        case 4:
            p = new Wolf(this, totalWarriorNum + 1);
            break;
    }
    pWarrior[totalWarriorNum] = p;
    curMakingSeqIdx = (curMakingSeqIdx + 1) % WARRIOR_NUM;
    warriorNum[typeId]++;
    pWarrior[totalWarriorNum++]->printResult(nTime);
    return 0;
}

string Weapon::names[3] = {"sword", "bomb", "arrow"};
string Warrior::names[WARRIOR_NUM] = {"dragon", "ninja", "iceman", "lion", "wolf"};
int Warrior::initialLifeValue[WARRIOR_NUM];
// 两个司令部武士的制作顺序序列
int Headquarter::makingSeq[2][WARRIOR_NUM] = {{2, 3, 4, 1, 0}, {3, 0, 1, 2, 4}};

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
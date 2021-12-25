/**
Created by gang wang on 2021/10/12
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

const int WARRIOR_NUM = 5;

class Warrior;
class Headquarter;

// 记录每个城市武士数量
Warrior *pWarrior[22][2];
int warriorNum[22];

Warrior *pWarriorTemp[22][2];
int warriorNumTemp[22];

int N; // 城市数量
int K; // lion每前进一步忠诚度就降低K

class Weapon {
    public:
        static string names[3];
    private:
        int typeId; // 武器有三种，sword, bomb,和arrow，编号分别为0,1,2
        int remainingUseTimes; // 剩余使用次数
    public:
        friend class Warrior;

        Weapon(int typeId) {
            this->typeId = typeId; // bomb只能用一次，arrow可以用2次，sword可以一直用
            remainingUseTimes = typeId == 2 ? 2 : 1;
        }

        int getTypeId() {
            return typeId;
        }

        int getRemainingUseTimes() {
            return remainingUseTimes;
        }

        void setRemainingUseTimes(int times) {
            remainingUseTimes = times;
        }
};

bool cmpBeforeFight(Weapon * pWeapon1, Weapon * pWeapon2) { // 战斗前武器排序，编号小的在前。相同编号用过的在前
    if (pWeapon1->getTypeId() != pWeapon2->getTypeId()) {
        return pWeapon1->getTypeId() < pWeapon2->getTypeId();
    } else {
        return pWeapon1->getRemainingUseTimes() < pWeapon2->getRemainingUseTimes();
    }
}

bool cmpBeforeGrab(Weapon * pWeapon1, Weapon * pWeapon2) { // 抢武器前武器排序，编号小的在前。相同编号没用过的在前
    if (pWeapon1->getTypeId() != pWeapon2->getTypeId()) {
        return pWeapon1->getTypeId() < pWeapon2->getTypeId();
    } else {
        return pWeapon1->getRemainingUseTimes() > pWeapon2->getRemainingUseTimes();
    }
}

//  武士基类
class Warrior {
    public:
        // 静态类变量表示各种武士名字、初始生命值以及攻击力，和typeId对应
        static string names[WARRIOR_NUM];
        static int initialLifeValue[WARRIOR_NUM];
        static int force[WARRIOR_NUM];
    protected:
        Headquarter *pHeadquarter;
        int id; // id
        int typeId; // 类别
        int lifeValue; // 生命值
        Weapon *pWeapon[10]; // 武士手里武器总数不超过10件
        int weaponNum;
    public:
        Warrior(Headquarter *p, int id) {
            this->pHeadquarter = p;
            this->id = id;
            weaponNum = 0;
        }

        ~Warrior() {
            for (int i = 0; i < weaponNum; i++) {
                delete pWeapon[i];
            }
        }

        int getId() { return id; }

        int getTypeId() { return typeId; }

        int getColor();

        int getLifeValue() { return lifeValue; }

        void setLifeValue(int value) { lifeValue = value; }

        int getWeaponNum() { return weaponNum; }

        void setWeaponNum(int num) { weaponNum = num; }

        Weapon ** getWeapon() {
            return pWeapon;
        }

        // 给武器排序
        void sortWeapon(int time) {
            if (time == 0) { // 被抢前武器排序
                sort(pWeapon, pWeapon + weaponNum, cmpBeforeGrab);
            } else  { // 战斗前武器排序
                sort(pWeapon, pWeapon + weaponNum, cmpBeforeFight);
            }
        }

        virtual void move(int hour, int cityId); // 武士前进

        void captureWeapon(Warrior * enemy); // 缴获被杀死敌人的武器

        void attack(Warrior *enemy, int & weaponId); // 攻击敌人

        bool isStoppingAttack() { // 判断是否没有武器，或只有sword武器，由于自身攻击力太低，导致sword武器攻击里都为0, 返回true
            int attackPower = 0;
            for (int i = 0; i < weaponNum; i++) {
                if (pWeapon[i]->getTypeId() == 0) {
                    attackPower = Warrior::force[typeId] * 2 / 10;
                    if (attackPower > 0) {
                        return false;
                    }
                } else {
                    return false;
                }
            }
            return true;
        }

        virtual void printBornMessage(int hour) { // 武士降生
            string color = getColor() == 0 ? "red" : "blue";
            printf("%03d:00 %s %s %d born\n", hour, color.c_str(), names[typeId].c_str(), id);
        }

        void printWeaponMessage(int hour) { // 武士报告武器情况
            int swordNum = 0, bombNum = 0, arrowNum = 0;
            for (int i = 0; i < weaponNum; i++) {
                if (pWeapon[i]->typeId == 0) {
                    swordNum++;
                } else if (pWeapon[i]->typeId == 1) {
                    bombNum++;
                } else if (pWeapon[i]->typeId == 2) {
                    arrowNum++;
                }
            }
            string str_color = getColor() == 0 ? "red" : "blue";
            printf("%03d:55 %s %s %d has %d sword %d bomb %d arrow and %d elements\n", hour, str_color.c_str(),
                   Warrior::names[typeId].c_str(), id, swordNum, bombNum, arrowNum, lifeValue);
        }
};

// 司令部类
class Headquarter {
    public:
        static int makingSeq[2][WARRIOR_NUM];
    private:
        int color; // 颜色，红魔军司令部，蓝魔军司令部
        int totalLifeValue; // 生命元
        bool isStopMakingWarrior; // 是否停止制造武士
        bool conquered; // 是否被占领

        int totalWarriorNum;
        int curMakingSeqIdx;
    public:
        friend class Warrior;

        void init(int color, int lv) {
            this->color = color;
            totalLifeValue = lv;
            isStopMakingWarrior = false;
            conquered = false;
            totalWarriorNum = 0;
            curMakingSeqIdx = 0;
        }

        bool isConquered() {
            return conquered;
        }

        void setConquered() {
            conquered = true;
        }

        int getTotalLifeValue() {
            return totalLifeValue;
        }

        void produce(int hour); // 制造武士

        // 司令部报告生命元数量
        void printTotalLifeValue(int hour) {
            string str_color = color == 0 ? "red" : "blue";
            printf("%03d:50 %d elements in %s headquarter\n", hour, totalLifeValue, str_color.c_str());
        }
};

// 定义两个全局变量
Headquarter redHead, blueHead;

// 武士子类
// 龙
class Dragon : public Warrior {
    public:
        Dragon(Headquarter *p, int id) : Warrior(p, id) {
            typeId = 0;
            lifeValue = Warrior::initialLifeValue[typeId];
            weaponNum = 1;
            pWeapon[0] = new Weapon(id % 3);
        }

        void cheer(int hour, int cityId) { // 龙欢呼
            string color = getColor() == 0 ? "red" : "blue";
            printf("%03d:40 %s dragon %d yelled in city %d\n", hour, color.c_str(), id, cityId);
        }
};

// 忍者
class Ninja : public Warrior {
    public:
        Ninja(Headquarter *p, int id) : Warrior(p, id) {
            typeId = 1;
            lifeValue = Warrior::initialLifeValue[typeId];
            weaponNum = 2;
            pWeapon[0] = new Weapon(id % 3);
            pWeapon[1] = new Weapon((id + 1) % 3);
        }
};

// 冰人
class Iceman : public Warrior {
    public:
        Iceman(Headquarter *p, int id) : Warrior(p, id) {
            typeId = 2;
            lifeValue = Warrior::initialLifeValue[typeId];
            weaponNum = 1;
            pWeapon[0] = new Weapon(id % 3);
        }

        void move(int hour, int cityId) { // iceman每前进一步，生命值减少10%
            lifeValue -= lifeValue / 10;
            Warrior::move(hour, cityId);
        }
};

// 狮子
class Lion : public Warrior {
    private:
        int loyalty;
    public:
        Lion(Headquarter *p, int id) : Warrior(p, id) {
            typeId = 3;
            lifeValue = Warrior::initialLifeValue[typeId];
            loyalty = pHeadquarter->getTotalLifeValue();
            weaponNum = 1;
            pWeapon[0] = new Weapon(id % 3);
        }

        int getLoyalty() { return loyalty; }

        void move(int hour, int cityId) { // lion每前进一步忠诚度就降低K
            loyalty -= K;
            Warrior::move(hour, cityId);
        }

        void escape(int hour, int cityId) { // 狮子逃跑
            string color = getColor() == 0 ? "red" : "blue";
            printf("%03d:05 %s lion %d ran away\n", hour, color.c_str(), id);
            if (warriorNum[cityId] == 2 && pWarrior[cityId][0] == this) {
                pWarrior[cityId][0] = pWarrior[cityId][1];
            }
            warriorNum[cityId] -= 1;
            delete this;
        }

        void printBornMessage(int hour) { // lion降生时，多输出一行忠诚度
            Warrior::printBornMessage(hour);
            printf("Its loyalty is %d\n", loyalty);
        }
};

// 狼
class Wolf : public Warrior {
    public:
        Wolf(Headquarter *p, int id) : Warrior(p, id) {
            typeId = 4;
            lifeValue = Warrior::initialLifeValue[typeId];
        }

        void grabWeapon(Warrior * enemy, int hour, int cityId); // wolf抢敌人的武器
};

int Warrior::getColor() {
    return pHeadquarter->color;
}

// 武士移动
void Warrior::move(int hour, int cityId) {
    int color = getColor();
    // 红魔军武士(color == 0)由西向东移动，蓝魔军武士由东向西移动
    int direction = color == 0 ? 1 : -1;
    // 移动到temp位置
    pWarriorTemp[cityId + direction][warriorNumTemp[cityId + direction]] = this;
    warriorNumTemp[cityId + direction] += 1;
}

// 武士战斗胜利后缴获 敌人的武器
void Warrior::captureWeapon(Warrior *enemy) {
    // 先给武器排序
    enemy->sortWeapon(0);
    Weapon** pEnemyWeapon = enemy->getWeapon();
    int enemyWeaponNum = enemy->getWeaponNum(); // 敌人武器数量
    if (enemyWeaponNum == 0) {
        return;
    }
    int weaponId = weaponNum, enemyWeaponId = 0;
    // 缴获敌人所有武器，自己武器满10件则不再缴获
    while (weaponId < 10 && enemyWeaponId < enemyWeaponNum) {
        pWeapon[weaponId++] = pEnemyWeapon[enemyWeaponId++];
    }
    setWeaponNum(weaponId);
    int i;
    // 将敌人剩余武器前移
    for (i = 0; enemyWeaponId < enemyWeaponNum; enemyWeaponId++) {
        pEnemyWeapon[i++] = pEnemyWeapon[enemyWeaponId];
    }
    enemy->setWeaponNum(i);
}

void Warrior::attack(Warrior *enemy, int & weaponId) {
    Weapon *p = pWeapon[weaponId];
    int attackPower;
    switch (p->getTypeId()) {
        case 0: // 使用sword攻击
            attackPower = Warrior::force[typeId] * 2 / 10; // sword的攻击力是使用者当前攻击力的20%
            enemy->setLifeValue(enemy->getLifeValue() - attackPower);
            weaponId = (weaponId + 1) % weaponNum;
            break;
        case 1: // 使用bomb攻击
            attackPower = Warrior::force[typeId] * 4 / 10; // bomb的攻击力是使用者当前攻击力的40%
            enemy->setLifeValue(enemy->getLifeValue() - attackPower);
            attackPower = attackPower * 1 / 2;  // bomb会导致使用者受到攻击，对使用者的攻击力是对敌人取整后的攻击力的1/2
            if (getTypeId() != 1) { // ninja 使用bomb不会让自己受伤
                setLifeValue(getLifeValue() - attackPower);
            }
            // bomb只能用一次，用过就失效了
            if (weaponId + 1 == weaponNum) { // 武器失效，是最后一件武器，直接删除
                weaponId = 0;
            } else { // 武器失效，用后面的武器填补其位置
                for (int i = weaponId + 1; i < weaponNum; i++) { // Bomb一旦使用就没了
                    pWeapon[i - 1] = pWeapon[i];
                }
            }
            weaponNum -= 1;
            delete p; // 删除武器
            break;
        case 2: // 使用arrow攻击
            attackPower = Warrior::force[typeId] * 3 / 10; // arrow的攻击力是使用者当前攻击力的30%
            enemy->setLifeValue(enemy->getLifeValue() - attackPower);
            if (p->getRemainingUseTimes() == 2) { // 一个arrow可以用两次。
                p->setRemainingUseTimes(1);
                weaponId = (weaponId + 1) % weaponNum;
            } else { // 同bomb
                if (weaponId + 1 == weaponNum) {
                    weaponId = 0;
                } else {
                    for (int i = weaponId + 1; i < weaponNum; i++) {
                        pWeapon[i - 1] = pWeapon[i];
                    }
                }
                weaponNum -= 1;
                delete p;
            }
            break;
    }
}

// wolf抢敌人的武器
void Wolf::grabWeapon(Warrior *enemy, int hour, int cityId) {
    // 先给武器排序
    enemy->sortWeapon(0);
    int enemyWeaponNum = enemy->getWeaponNum(); // 敌人武器数量
    Weapon** pEnemyWeapon = enemy->getWeapon();
    if (enemyWeaponNum == 0) {
        return;
    }
    int enemyMinWeaponNum = 1; // 敌人编号最小的那种武器数量
    while (enemyMinWeaponNum < enemyWeaponNum && pEnemyWeapon[enemyMinWeaponNum]->getTypeId() == pEnemyWeapon[0]->getTypeId()) {
        enemyMinWeaponNum++;
    }
    int weaponId = weaponNum, enemyWeaponId = 0;
    while (weaponId < 10 && enemyWeaponId < enemyMinWeaponNum) {
        pWeapon[weaponId++] = pEnemyWeapon[enemyWeaponId++];
    }
    string str_color = getColor() == 0 ? "red" : "blue";
    string str_enemy_color = getColor() == 1 ? "red" : "blue";
    printf("%03d:35 %s wolf %d took %d %s from %s %s %d in city %d\n", hour, str_color.c_str(),
           id, enemyWeaponId, Weapon::names[pEnemyWeapon[0]->getTypeId()].c_str(), str_enemy_color.c_str(),
           Warrior::names[enemy->getTypeId()].c_str(), enemy->getId(), cityId);
    setWeaponNum(weaponId);
    int i;
    for (i = 0; enemyWeaponId < enemyWeaponNum; enemyWeaponId++) {
        pEnemyWeapon[i++] = pEnemyWeapon[enemyWeaponId];
    }
    enemy->setWeaponNum(i);
}

// 司令部制造武士
void Headquarter::produce(int hour) {
    if (isStopMakingWarrior) {
        return;
    }
    int typeId = makingSeq[color][curMakingSeqIdx];
    if (Warrior::initialLifeValue[typeId] > totalLifeValue) {
        isStopMakingWarrior = true;
        return;
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
    if (color == 0) {
        pWarrior[0][warriorNum[0]++] = p;
    } else if (color == 1) {
        pWarrior[N + 1][warriorNum[N + 1]++] = p;
    }
    totalWarriorNum++;
    curMakingSeqIdx = (curMakingSeqIdx + 1) % WARRIOR_NUM;
    p->printBornMessage(hour);
}

// 所有武士移动
void move(int hour) {
    // temp位置清空
    for (int i = 0; i <= N + 1; i++) {
        warriorNumTemp[i] = 0;
    }
    // 所有武士移动到temp位置
    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j < warriorNum[i]; j++) {
            pWarrior[i][j]->move(hour, i);
        }
    }

    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j < warriorNumTemp[i]; j++) {
            Warrior * p = pWarriorTemp[i][j];
            int color = p->getColor();
            int id = p->getId();
            int typeId = p->getTypeId();
            int lifeValue = p->getLifeValue();
            // 蓝魔军武士抵达红魔军司令部
            if (i == 0) {
                printf("%03d:10 blue %s %d reached red headquarter with %d elements and force %d\n", hour,
                    Warrior::names[typeId].c_str(), id, lifeValue, Warrior::force[typeId]);
                // 红魔军司令部被占领
                printf("%03d:10 red headquarter was taken\n", hour);
                redHead.setConquered();
            } else if (i == N + 1) { // 红魔军武士抵达蓝魔军司令部
                printf("%03d:10 red %s %d reached blue headquarter with %d elements and force %d\n", hour,
                Warrior::names[typeId].c_str(), id, lifeValue, Warrior::force[typeId]);
                // 蓝魔军司令部被占领
                printf("%03d:10 blue headquarter was taken\n", hour);
                blueHead.setConquered();
            } else {
                printf("%03d:10 %s %s %d marched to city %d with %d elements and force %d\n", hour,
                    color == 0 ? "red" : "blue", Warrior::names[typeId].c_str(), id, i, lifeValue,
                    Warrior::force[typeId]);
            }
        }
    }

    // 将武士从temp位置拷贝回原位置
    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j < warriorNumTemp[i]; j++) {
            pWarrior[i][j] = pWarriorTemp[i][j];
        }
        warriorNum[i] = warriorNumTemp[i];
    }
}

// 红、蓝武士战斗
void fight(Warrior * redWarrior, Warrior * blueWarrior, int hour, int cityId) {
    // 战斗前先给武器排序
    redWarrior->sortWeapon(1);
    blueWarrior->sortWeapon(1);
    // 攻击次序 在奇数编号城市，红武士先发起攻击; 在偶数编号城市，蓝武士先发起攻击
    int order = cityId % 2 == 1 ? 0 : 1;
    // 使用武器编号
    int redWarriorWeaponId = 0, blueWarriorWeaponId = 0;
    bool isRedWarriorStoppingAttack = redWarrior->isStoppingAttack();
    bool isBlueWarriorStoppingAttack = blueWarrior->isStoppingAttack();
    while (redWarrior->getLifeValue() > 0 && blueWarrior->getLifeValue() > 0) {
        // 双方都还活着，但都没有武器或只有sword武器且sword攻击力为0
        // 战斗中双方的生命值和武器的状态都不再发生变化，跳出循环
        if (isRedWarriorStoppingAttack && isBlueWarriorStoppingAttack) {
            break;
        }
        if (order % 2 == 0 && redWarrior->getWeaponNum() > 0) {
            redWarrior->attack(blueWarrior, redWarriorWeaponId);
            isRedWarriorStoppingAttack = redWarrior->isStoppingAttack();
        } else if (order % 2 == 1 && blueWarrior->getWeaponNum() > 0) {
            blueWarrior->attack(redWarrior, blueWarriorWeaponId);
            isBlueWarriorStoppingAttack = blueWarrior->isStoppingAttack();
        }
        order++;
    }
    // 报告战斗情况
    if (redWarrior->getLifeValue() > 0) {

        if (blueWarrior->getLifeValue() > 0) { // 双方平局
            printf("%03d:40 both red %s %d and blue %s %d were alive in city %d\n",
                   hour, Warrior::names[redWarrior->getTypeId()].c_str(), redWarrior->getId(),
                   Warrior::names[blueWarrior->getTypeId()].c_str(), blueWarrior->getId(), cityId);
            if (redWarrior->getTypeId() == 0) { // dragon在战斗结束后，如果还没有战死，就会欢呼
                Dragon * p = (Dragon *) redWarrior;
                p->cheer(hour, cityId);
            }
            if (blueWarrior->getTypeId() == 0) {
                Dragon * p = (Dragon *) blueWarrior;
                p->cheer(hour, cityId);
            }
        } else { // 红魔军武士杀死蓝魔军武士
            printf("%03d:40 red %s %d killed blue %s %d in city %d remaining %d elements\n",
                   hour, Warrior::names[redWarrior->getTypeId()].c_str(), redWarrior->getId(),
                   Warrior::names[blueWarrior->getTypeId()].c_str(), blueWarrior->getId(), cityId,
                   redWarrior->getLifeValue());
            redWarrior->captureWeapon(blueWarrior);
            pWarrior[cityId][0] = redWarrior;
            warriorNum[cityId] = 1;
            if (redWarrior->getTypeId() == 0) { // dragon在战斗结束后，如果还没有战死，就会欢呼
                Dragon * p = (Dragon *) redWarrior;
                p->cheer(hour, cityId);
            }
            delete blueWarrior;
        }
    } else {
        if (blueWarrior->getLifeValue() > 0) { // 蓝魔军武士杀死红魔君武士
            printf("%03d:40 blue %s %d killed red %s %d in city %d remaining %d elements\n",
                   hour, Warrior::names[blueWarrior->getTypeId()].c_str(), blueWarrior->getId(),
                   Warrior::names[redWarrior->getTypeId()].c_str(), redWarrior->getId(), cityId,
                   blueWarrior->getLifeValue());
            blueWarrior->captureWeapon(redWarrior);
            pWarrior[cityId][0] = blueWarrior;
            warriorNum[cityId] = 1;
            delete redWarrior;
            if (blueWarrior->getTypeId() == 0) { // dragon在战斗结束后，如果还没有战死，就会欢呼
                Dragon * p = (Dragon *) blueWarrior;
                p->cheer(hour, cityId);
            }
        } else { // 同时战死
            printf("%03d:40 both red %s %d and blue %s %d died in city %d\n",
                   hour, Warrior::names[redWarrior->getTypeId()].c_str(), redWarrior->getId(),
                   Warrior::names[blueWarrior->getTypeId()].c_str(), blueWarrior->getId(), cityId);
            warriorNum[cityId] = 0;
            delete redWarrior;
            delete blueWarrior;
        }
    }
}

string Weapon::names[3] = {"sword", "bomb", "arrow"};
string Warrior::names[WARRIOR_NUM] = {"dragon", "ninja", "iceman", "lion", "wolf"};
int Warrior::initialLifeValue[WARRIOR_NUM];
int Warrior::force[WARRIOR_NUM];
// 两个司令部武士的制作顺序序列
int Headquarter::makingSeq[2][WARRIOR_NUM] = {{2, 3, 4, 1, 0}, {3, 0, 1, 2, 4}};

int main() {
    int n;
    scanf("%d", &n);
    int caseNo = 1;
    while (n--) {
        printf("Case %d:\n", caseNo++);
        int totalLifeValue, T; // totalLifeValue司令部初始生命元，两个司令部之间一共有N个城市
        // lion每前进一步，忠诚度就降低K；T 截止时间
        scanf("%d %d %d %d", &totalLifeValue, &N, &K, &T);
        for (int i = 0; i < WARRIOR_NUM; i++) {
            scanf("%d", &Warrior::initialLifeValue[i]);
        }
        for (int i = 0; i < WARRIOR_NUM; i++) {
            scanf("%d", &Warrior::force[i]);
        }

        // 重新初始化司令部生命元数量和每座城市的武士数量
        for (int i = 0; i <= N + 1; i++) {
            warriorNum[i] = 0;
        }
        redHead.init(0, totalLifeValue);
        blueHead.init(1, totalLifeValue);

        // 主程序逻辑
        for (int nTime = 0; nTime <= T; nTime++) {
            int hour = nTime / 60;
            int minute = nTime % 60;
            switch (minute) {
                case 0: // 每个小时的第0分， 双方的司令部中各有一个武士降生
                    redHead.produce(hour);
                    blueHead.produce(hour);
                    break;
                case 5: // 在每个小时的第5分，该逃跑的lion就在这一时刻逃跑了
                    for (int i = 0; i <= N + 1; i++) {
                        for (int j = 0; j < warriorNum[i]; j++) {
                            if (pWarrior[i][j]->getTypeId() == 3) {
                                Lion *pLion = (Lion *) pWarrior[i][j];
                                if (pLion->getColor() == 0) {
                                    if (i != N + 1 && pLion->getLoyalty() <= 0) {
                                        pLion->escape(hour, i);
                                    }
                                }
                                if (pLion->getColor() == 1) {
                                    if (i != 0 && pLion->getLoyalty() <= 0) {
                                        pLion->escape(hour, i);
                                    }
                                }
                            }
                        }
                    }
                    break;
                case 10: // 在每个小时的第10分，所有的武士朝敌人司令部方向前进一步
                    move(hour);
                    break;
                case 35: // 在每个小时的第35分，有wolf及其敌人的城市，wolf要抢夺对方的武器
                    for (int i = 0; i <= N + 1; i++) {
                        if (warriorNum[i] == 2) {
                            if (pWarrior[i][0]->getTypeId() == 4 && pWarrior[i][1]->getTypeId() != 4) {
                                Wolf * p = (Wolf *) pWarrior[i][0];
                                p->grabWeapon(pWarrior[i][1], hour, i);
                            }
                            if (pWarrior[i][1]->getTypeId() == 4 && pWarrior[i][0]->getTypeId() != 4) {
                                Wolf * p = (Wolf *) pWarrior[i][1];
                                p->grabWeapon(pWarrior[i][0], hour, i);
                            }
                        }
                    }
                    break;
                case 40: // 在每个小时的第40分，在有两个武士的城市，会发生战斗
                    for (int i = 0; i <= N + 1; i++) {
                        if (warriorNum[i] == 2) {
                            Warrior *redWarrior = pWarrior[i][0];
                            Warrior *blueWarrior = pWarrior[i][1];
                            fight(redWarrior, blueWarrior, hour, i); // 开始战斗
                        }
                    }
                    break;
                case 50: // 在每个小时的第50分，司令部报告它拥有的生命元数量
                    redHead.printTotalLifeValue(hour);
                    blueHead.printTotalLifeValue(hour);
                    break;
                case 55: // 在每个小时的第55分，每个武士报告其拥有的武器情况
                    for (int i = 0; i <= N + 1; i++) {
                        for (int j = 0; j < warriorNum[i]; j++) {
                            pWarrior[i][j]->printWeaponMessage(hour);
                        }
                    }
                    break;
            }
            if (redHead.isConquered() || blueHead.isConquered())
                break;
        }

        // 清除所有武士
        for (int i = 0; i <= N + 1; i++) {
            for (int j = 0; j < warriorNum[i]; j++) {
                delete pWarrior[i][j];
            }
        }
    }
    return 0;
}
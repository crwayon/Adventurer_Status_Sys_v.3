#include <iostream>
#include <string>
using namespace std;

// 모험가 클래스
class Adventurer {
protected:
    int status[4];      // 스테이터스 배열 [HP, MP, 공격력, 방어력]
    int maxHP;          // 최대 HP
    int maxMP;          // 최대 MP
    int hpPotion;       // HP 포션 개수
    int mpPotion;       // MP 포션 개수
    string className;   // 직업명

public:
    Adventurer() {
        for (int i = 0; i < 4; i++) status[i] = 0;
        maxHP = 0;
        maxMP = 0;
        className = "모험가";
    }

    // 포션 개수 설정 함수 (Call by Pointer)
    void setPotion(int count, int* hpPotion, int* mpPotion) {
        *hpPotion = count;
        *mpPotion = count;
        this->hpPotion = *hpPotion;
        this->mpPotion = *mpPotion;
    }

    void initializeStats() {
        cout << "\n===============================================\n";
        cout << "       여신의 부름받아 TRPG세계에 강림\n";
        cout << "===============================================\n\n";

        cout << "[생명의 여신께서 마나와 생명을 부여합니다]\n\n";

        // HP 입력
        for (bool valid = false; !valid; ) {
            cout << "HP를 입력하세요: ";
            cin >> status[0];
            if (status[0] < 30 || status[0] > 50) {
                cout << "HP는 30 이상 50 이하여야 합니다.\n";
            }
            else {
                maxHP = status[0];
                valid = true;
            }
        }

        // MP 입력
        for (bool valid = false; !valid; ) {
            cout << "MP를 입력하세요: ";
            cin >> status[1];
            if (status[1] < 60 || status[1] > 70) {
                cout << "MP는 60 이상 70 이하여야 합니다.\n";
            }
            else {
                maxMP = status[1];
                valid = true;
            }
        }

        cout << "\n[전쟁의 여신이 그대에게 용맹과 긍지를 부여합니다]\n\n";

        // 공격력 입력 (1~50)
        for (bool valid = false; !valid; ) {
            cout << "공격력을 입력하세요 (1~50): ";
            cin >> status[2];
            if (status[2] <= 0 || status[2] > 50) {
                cout << "공격력은 1 이상 50 이하여야 합니다.\n";
            }
            else valid = true;
        }

        // 방어력 입력 (1~50)
        for (bool valid = false; !valid; ) {
            cout << "방어력을 입력하세요 (1~50): ";
            cin >> status[3];
            if (status[3] <= 0 || status[3] > 50) {
                cout << "방어력은 1 이상 50 이하여야 합니다.\n";
            }
            else valid = true;
        }

        cout << "\n캐릭터 생성이 완료되었습니다!\n";

        // 포션 개수 설정 (5개)
        int hp = 5, mp = 5;
        setPotion(5, &hp, &mp);
    }

    void showStatus() {
        cout << "\n┌─────────────────────────────────┐\n";
        cout << "│      현재 스테이터스            │\n";
        cout << "├─────────────────────────────────┤\n";
        cout << "│ 직업: " << className << "                    │\n";
        cout << "│ HP: " << status[0] << "/" << maxHP << "                    │\n";
        cout << "│ MP: " << status[1] << "/" << maxMP << "                    │\n";
        cout << "│ 공격력: " << status[2] << "                      │\n";
        cout << "│ 방어력: " << status[3] << "                      │\n";
        cout << "│ HP 포션: " << hpPotion << "개                   │\n";
        cout << "│ MP 포션: " << mpPotion << "개                   │\n";
        cout << "└─────────────────────────────────┘\n";
    }

    // 스탯 관리 시스템 - Pointer 사용
    void statManagementSystem(int* hp, int* mp, int* atk, int* def, int* hpPot, int* mpPot, int* maxHp, int* maxMp) {
        int choice;
        bool running = true;

        while (running) {
            cout << "\n===============================================\n";
            cout << "           <스탯 관리 시스템>\n";
            cout << "===============================================\n";
            cout << "1. HP 회복\n";
            cout << "2. MP 회복\n";
            cout << "3. HP 강화\n";
            cout << "4. MP 강화\n";
            cout << "5. 공격 스킬 사용\n";
            cout << "6. 나가기\n";
            cout << "-----------------------------------------------\n";
            cout << "선택: ";
            cin >> choice;

            switch (choice) {
            case 1: { // HP 회복
                if (*hpPot > 0) {
                    int healAmount = 20;
                    if (*hp + healAmount > *maxHp) healAmount = *maxHp - *hp;
                    *hp += healAmount;
                    (*hpPot)--;
                    cout << "\n[HP가 " << healAmount << " 회복되었습니다. 포션이 1개 차감됩니다.]\n";
                    cout << "현재 HP: " << *hp << "/" << *maxHp << "\n";
                    cout << "남은 HP 포션: " << *hpPot << "개\n";
                }
                else {
                    cout << "\n[포션이 부족합니다.]\n";
                }
                break;
            }
            case 2: { // MP 회복
                if (*mpPot > 0) {
                    int healAmount = 20;
                    if (*mp + healAmount > *maxMp) healAmount = *maxMp - *mp;
                    *mp += healAmount;
                    (*mpPot)--;
                    cout << "\n[MP가 " << healAmount << " 회복되었습니다. 포션이 1개 차감됩니다.]\n";
                    cout << "현재 MP: " << *mp << "/" << *maxMp << "\n";
                    cout << "남은 MP 포션: " << *mpPot << "개\n";
                }
                else {
                    cout << "\n[포션이 부족합니다.]\n";
                }
                break;
            }
            case 3: { // HP 강화
                *hp *= 2;
                *maxHp *= 2;
                cout << "\n[HP가 2배로 증가되었습니다.]\n";
                cout << "현재 HP: " << *hp << "/" << *maxHp << "\n";
                break;
            }
            case 4: { // MP 강화
                *mp *= 2;
                *maxMp *= 2;
                cout << "\n[MP가 2배로 증가되었습니다.]\n";
                cout << "현재 MP: " << *mp << "/" << *maxMp << "\n";
                break;
            }
            case 5: { // 공격 스킬 사용 
                const int skillCost = 20;           // 스킬 MP 소모량
                const double dmgMultiplier = 1.5;   // 피해 배율

                if (*mp >= skillCost) {
                    *mp -= skillCost;
                    int damagePreview = static_cast<int>(*atk * dmgMultiplier);

                    cout << "\n[공격 스킬]\n";
                    cout << "피해량: " << damagePreview << " \n";
                    cout << "MP가 " << skillCost << " 소모되었습니다. 현재 MP: " << *mp << "/" << *maxMp << "\n";
                }
                else {
                    cout << "\n[MP가 부족합니다! 필요 MP: " << skillCost << "]\n";
                }
                break;
            }
            case 6: { // 나가기
                cout << "\n[이 세계를 구할 전설의 끝]\n";
                running = false;
                break;
            }
            default:
                cout << "\n[잘못된 선택입니다]\n";
            }

            // 동기화
            status[0] = *hp;
            status[1] = *mp;
            status[2] = *atk;
            status[3] = *def;
            hpPotion = *hpPot;
            mpPotion = *mpPot;
            maxHP = *maxHp;
            maxMP = *maxMp;
        }
    }

    // 오버로드된 스탯 관리 시스템 호출 함수
    void statManagementSystem() {
        statManagementSystem(&status[0], &status[1], &status[2], &status[3],
            &hpPotion, &mpPotion, &maxHP, &maxMP);
    }

    string getClassName() { return className; }
};

int main() {
    Adventurer* player = new Adventurer();
    player->initializeStats();
    player->showStatus();
    player->statManagementSystem();
    delete player;

    cout << "\n게임 종료\n";
    return 0;
}
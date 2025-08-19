#include <iostream>
#include <string>
using namespace std;

class Adventurer {
private:
    int status[4];  // 0: HP, 1: MP, 2: 공격력, 3: 방어력
    int hpPotion;
    int mpPotion;
    string className;

public:
    Adventurer() {
        // 배열 초기화
        for (int i = 0; i < 4; i++) {
            status[i] = 0;
        }
        hpPotion = 5;  // 초기 포션 개수
        mpPotion = 5;
        className = "모험가";
    }

    void initializeStats() {
        cout << "\n===============================================\n";
        cout << "         모험의 시작 TRPG 과제\n";
        cout << "===============================================\n\n";

        // HP와 MP 입력
        cout << "[생명의 여신께서 HP와 MP를 부여합니다]\n\n";

        for (bool valid = false; !valid; ) {
            cout << "HP를 입력하세요: ";
            cin >> status[0];
            cout << "MP를 입력하세요: ";
            cin >> status[1];

            if (status[0] <= 50 || status[1] <= 50) {
                cout << "\n※ HP와 MP는 모두 50보다 커야 합니다. 다시 입력해주세요.\n\n";
            }
            else {
                valid = true;
            }
        }

        cout << "\n[전쟁의 여신이 그대에게 공격력과 방어력을 부여합니다]\n\n";

        // 공격력과 방어력 입력
        for (bool valid = false; !valid; ) {
            cout << "공격력을 입력하세요 (1 이상): ";
            cin >> status[2];
            cout << "방어력을 입력하세요 (1 이상): ";
            cin >> status[3];

            if (status[2] <= 0 || status[3] <= 0) {
                cout << "\n※ 공격력과 방어력은 모두 0보다 커야 합니다. 다시 입력해주세요.\n\n";
            }
            else {
                valid = true;
            }
        }

        cout << "\n캐릭터 생성이 완료되었습니다!\n";
    }

    void showStatus() {
        cout << "\n┌─────────────────────────────────┐\n";
        cout << "│      현재 스테이터스            │\n";
        cout << "├─────────────────────────────────┤\n";
        cout << "│ 직업: " << className << "                    │\n";
        cout << "│ HP: " << status[0] << "                          │\n";
        cout << "│ MP: " << status[1] << "                          │\n";
        cout << "│ 공격력: " << status[2] << "                       │\n";
        cout << "│ 방어력: " << status[3] << "                       │\n";
        cout << "│ HP 포션: " << hpPotion << "개                    │\n";
        cout << "│ MP 포션: " << mpPotion << "개                    │\n";
        cout << "└─────────────────────────────────┘\n";
    }

    void statManagementSystem() {
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
            cout << "6. 현재 상태 확인\n";
            cout << "0. 종료\n";
            cout << "-----------------------------------------------\n";
            cout << "선택: ";
            cin >> choice;

            switch (choice) {
            case 1:  // HP 회복
                if (hpPotion > 0) {
                    status[0] += 20;
                    hpPotion--;
                    cout << "\n[HP가 20 회복되었습니다!]\n";
                    cout << "현재 HP: " << status[0] << "\n";
                    cout << "남은 HP 포션: " << hpPotion << "개\n";
                }
                else {
                    cout << "\n[HP 포션이 없습니다!]\n";
                }
                break;

            case 2:  // MP 회복
                if (mpPotion > 0) {
                    status[1] += 20;
                    mpPotion--;
                    cout << "\n[MP가 20 회복되었습니다!]\n";
                    cout << "현재 MP: " << status[1] << "\n";
                    cout << "남은 MP 포션: " << mpPotion << "개\n";
                }
                else {
                    cout << "\n[MP 포션이 없습니다!]\n";
                }
                break;

            case 3:  // HP 강화
                status[0] *= 2;
                cout << "\n[HP가 2배로 증가되었습니다!]\n";
                cout << "현재 HP: " << status[0] << "\n";
                break;

            case 4:  // MP 강화
                status[1] *= 2;
                cout << "\n[MP가 2배로 증가되었습니다!]\n";
                cout << "현재 MP: " << status[1] << "\n";
                break;

            case 5:  // 공격 스킬 사용
                if (status[1] >= 50) {
                    status[1] -= 50;
                    cout << "\n[스킬을 사용하여 MP가 50 소모되었습니다!]\n";
                    cout << "현재 MP: " << status[1] << "\n";
                }
                else {
                    cout << "\n[MP가 부족합니다! (필요 MP: 50)]\n";
                    cout << "현재 MP: " << status[1] << "\n";
                }
                break;

            case 6:  // 현재 상태 확인
                showStatus();
                break;

            case 0:  // 종료
                cout << "\n[시스템을 종료합니다...]\n";
                running = false;
                break;

            default:
                cout << "\n[잘못된 선택입니다. 다시 선택해주세요.]\n";
            }
        }
    }
};

int main() {
    cout << "===============================================\n";
    cout << "       텍스트 RPG - 모험의 시작\n";
    cout << "===============================================\n";

    Adventurer player;

    // 캐릭터 초기 스탯 설정
    player.initializeStats();

    // 현재 상태 표시
    player.showStatus();

    // 스탯 관리 시스템 실행
    player.statManagementSystem();

    return 0;
}
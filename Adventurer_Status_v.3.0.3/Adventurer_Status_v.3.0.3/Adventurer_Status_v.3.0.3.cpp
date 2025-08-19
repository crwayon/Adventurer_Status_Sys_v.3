#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// 플레이어 구조체
struct Player {
    string name;
    string playerClass;  // 클래스 (모험가로 시작)
    int status[4];       // 0:HP, 1:MP, 2:공격력, 3:방어력
    int maxHp;
    int maxMp;
    int hpPotion;
    int mpPotion;
};

// 함수 선언 (스탯 관리 시스템만 call by pointer 사용)
void initPlayer(Player& player);
void displayCurrentStatus(const Player& player);
void inputInitialStats(int* status);  // call by pointer for 스탯 관리
void statManagementSystem(int* status, int* hpPotion, int* mpPotion, int* maxHp, int* maxMp);  // call by pointer
void showStatMenu();
void setPotion(int count, int* hpPotion, int* mpPotion);  // call by pointer

// 플레이어 초기화
void initPlayer(Player& player) {
    cout << "캐릭터 생성" << endl;
    cout << endl;

    // 기본값 설정
    player.name = "모험가";
    player.playerClass = "모험가";  // 최초 클래스는 모험가

    // 배열 초기화 (0으로 초기화)
    for (int i = 0; i < 4; i++) {
        player.status[i] = 0;
    }

    // 초기 스탯 입력받기
    inputInitialStats(player.status);

    // 최대값 설정
    player.maxHp = player.status[0];
    player.maxMp = player.status[1];

    // 포션 개수를 5로 설정
    setPotion(5, &(player.hpPotion), &(player.mpPotion));

    cout << endl;
    displayCurrentStatus(player);
}

// 초기 스탯 입력 (call by pointer)
void inputInitialStats(int* status) {
    // HP, MP 입력
    cout << "[생명의 여신께서 HP와 MP를 부여합니다]" << endl;

    while (true) {
        cout << "HP를 입력하세요 : ";
        cin >> status[0];  // HP
        cout << "MP를 입력하세요 : ";
        cin >> status[1];  // MP

        if (status[0] > 50 && status[1] > 50) {
            break;
        }
        else {
            cout << "HP와 MP는 모두 50보다 큰 값을 입력해야 합니다. 다시 입력해주세요." << endl;
        }
    }

    // 공격력, 방어력 입력
    cout << "[전쟁의 여신이 그대에게 공격력과 방어력을 부여합니다.]" << endl;

    while (true) {
        cout << "공격력을 입력하세요 : ";
        cin >> status[2];  // 공격력
        cout << "방어력을 입력하세요 : ";
        cin >> status[3];  // 방어력

        if (status[2] > 0 && status[3] > 0) {
            break;
        }
        else {
            cout << "공격력과 방어력은 모두 0보다 큰 값을 입력해야 합니다. 다시 입력해주세요." << endl;
        }
    }
}

// 현재 스테이터스 출력
void displayCurrentStatus(const Player& player) {
    cout << "┌─────────────────────────────────┐" << endl;
    cout << "│        현재 스테이터스          │" << endl;
    cout << "├─────────────────────────────────┤" << endl;
    cout << "│ 직업 : " << setw(24) << left << player.playerClass << "│" << endl;
    cout << "│ HP: " << setw(27) << left << player.status[0] << "│" << endl;
    cout << "│ MP: " << setw(27) << left << player.status[1] << "│" << endl;
    cout << "│ 공격력: " << setw(23) << left << player.status[2] << "│" << endl;
    cout << "│ 방어력: " << setw(23) << left << player.status[3] << "│" << endl;
    cout << "│ HP 포션: " << setw(21) << left << (to_string(player.hpPotion) + "개") << "│" << endl;
    cout << "│ MP 포션: " << setw(21) << left << (to_string(player.mpPotion) + "개") << "│" << endl;
    cout << "└─────────────────────────────────┘" << endl;
}

// 포션 개수 설정 (call by pointer)
void setPotion(int count, int* hpPotion, int* mpPotion) {
    *hpPotion = count;
    *mpPotion = count;
}

// 스탯 관리 시스템 메뉴 출력
void showStatMenu() {
    cout << "=================================================" << endl;
    cout << "             <스탯 관리 시스템>" << endl;
    cout << "=================================================" << endl;
    cout << "1. HP 회복" << endl;
    cout << "2. MP 회복" << endl;
    cout << "3. HP 강화" << endl;
    cout << "4. MP 강화" << endl;
    cout << "5. 공격 스킬 사용" << endl;
    cout << "6. 현재 상태 확인" << endl;
    cout << "0. 종료" << endl;
    cout << "=================================================" << endl;
    cout << "선택: ";
}

// 스탯 관리 시스템 (call by pointer 사용)
void statManagementSystem(int* status, int* hpPotion, int* mpPotion, int* maxHp, int* maxMp) {
    int choice;

    while (true) {
        showStatMenu();
        cin >> choice;

        switch (choice) {
        case 1: { // HP 회복
            if (*hpPotion > 0) {
                status[0] += 20;  // HP 20 증가
                if (status[0] > *maxHp) {
                    status[0] = *maxHp;  // 최대값 제한
                }
                (*hpPotion)--;  // 포션 1개 차감
                cout << "HP가 20 회복되었습니다! 현재 HP: " << status[0] << endl;
                cout << "남은 HP 포션: " << *hpPotion << "개" << endl;
            }
            else {
                cout << "HP 포션이 없습니다!" << endl;
            }
            break;
        }
        case 2: { // MP 회복
            if (*mpPotion > 0) {
                status[1] += 20;  // MP 20 증가
                if (status[1] > *maxMp) {
                    status[1] = *maxMp;  // 최대값 제한
                }
                (*mpPotion)--;  // 포션 1개 차감
                cout << "MP가 20 회복되었습니다! 현재 MP: " << status[1] << endl;
                cout << "남은 MP 포션: " << *mpPotion << "개" << endl;
            }
            else {
                cout << "MP 포션이 없습니다!" << endl;
            }
            break;
        }
        case 3: { // HP 강화
            int oldHp = status[0];
            status[0] *= 2;  // HP 2배 증가
            *maxHp *= 2;     // 최대 HP도 2배 증가
            cout << "HP가 강화되었습니다! " << oldHp << " → " << status[0] << endl;
            cout << "최대 HP도 " << *maxHp << "로 증가했습니다!" << endl;
            break;
        }
        case 4: { // MP 강화
            int oldMp = status[1];
            status[1] *= 2;  // MP 2배 증가
            *maxMp *= 2;     // 최대 MP도 2배 증가
            cout << "MP가 강화되었습니다! " << oldMp << " → " << status[1] << endl;
            cout << "최대 MP도 " << *maxMp << "로 증가했습니다!" << endl;
            break;
        }
        case 5: { // 공격 스킬 사용
            if (status[1] >= 50) {
                status[1] -= 50;  // MP 50 차감
                cout << "공격 스킬을 사용했습니다! MP가 50 차감되었습니다." << endl;
                cout << "현재 MP: " << status[1] << endl;
            }
            else {
                cout << "MP가 부족합니다! (필요 MP: 50, 현재 MP: " << status[1] << ")" << endl;
            }
            break;
        }
        case 6: { // 현재 상태 확인
            cout << "\n===== 현재 스테이터스 =====" << endl;
            cout << "HP: " << status[0] << "/" << *maxHp << endl;
            cout << "MP: " << status[1] << "/" << *maxMp << endl;
            cout << "공격력: " << status[2] << endl;
            cout << "방어력: " << status[3] << endl;
            cout << "HP 포션: " << *hpPotion << "개" << endl;
            cout << "MP 포션: " << *mpPotion << "개" << endl;
            cout << "=========================" << endl;
            break;
        }
        case 0: {
            cout << "스탯 관리 시스템을 종료합니다." << endl;
            return;
        }
        default: {
            cout << "잘못된 선택입니다. 다시 선택해주세요." << endl;
            break;
        }
        }
        cout << endl;
    }
}

// 메인 메뉴 출력
void showMainMenu() {
    cout << "\n===== 텍스트 RPG - 모험의 시작 =====" << endl;
    cout << "=====================================" << endl;
    cout << "      모험의 시작 TRPG 과제" << endl;
    cout << "=====================================" << endl;
    cout << "1. 스탯 관리 시스템" << endl;
    cout << "2. 현재 상태 확인" << endl;
    cout << "3. 전직 시스템 (준비 중)" << endl;
    cout << "0. 게임 종료" << endl;
    cout << "=====================================" << endl;
    cout << "선택: ";
}

int main() {
    Player player;
    int choice;

    // 플레이어 초기화
    initPlayer(player);

    while (true) {
        showMainMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            // 스탯 관리 시스템만 call by pointer 사용
            statManagementSystem(player.status, &player.hpPotion, &player.mpPotion,
                &player.maxHp, &player.maxMp);
            break;
        }
        case 2: {
            displayCurrentStatus(player);
            break;
        }
        case 3: {
            cout << "전직 시스템은 아직 준비 중입니다." << endl;
            break;
        }
        case 0: {
            cout << "게임을 종료합니다. 모험가님, 수고하셨습니다!" << endl;
            return 0;
        }
        default: {
            cout << "잘못된 선택입니다. 다시 선택해주세요." << endl;
            break;
        }
        }
    }

    return 0;
}
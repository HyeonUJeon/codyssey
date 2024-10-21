#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 6

// 후보자 정보 구조체
typedef struct {
    char name[50];
    int id;
    int score;
} Candidate;

// 후보자 배열 초기화
Candidate candidates[MAX_CANDIDATES] = {
    {"박지연", 100001, 0},
    {"Ethan Smith", 100002, 0},
    {"Helena Silva", 100003, 0},
    {"Liam Wilson", 100004, 0},
    {"Sophia Lee", 100005, 0},
    {"Noah Brown", 100006, 0}
};

// 점수 입력 함수
void input_scores() {
    printf("++++++++++++++++++++++++++++++++++++\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        int score;
        printf("후보자: %s\n음악 소양: ", candidates[i].name);
        while (1) {
            scanf("%d", &score);
            if (score >= 10 && score <= 100) break;  // 10 ~ 100 점 사이 입력 확인
            printf("잘못된 값입니다. 다시 입력하세요: ");
        }
        candidates[i].score = score;  // 점수 저장
        printf("------------------------------------\n");
    }
}

// 점수 출력 함수
void print_scores() {
    printf("입력하신 내용을 검토하세요!\n------------------------------------\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d\n", candidates[i].name, candidates[i].score);
    }
}

// 제출 확인 함수
int confirm_submission() {
    char choice;
    printf("제출하시겠습니까? (Y/N): ");
    scanf(" %c", &choice);
    return (choice == 'Y' || choice == 'y');
}

int main() {
    char judge_name[50], expertise[50];

    while (1) {
        // 심사자 이름과 전문 분야 입력
        printf("####################################\n#       오디션 심사 결과 입력       #\n####################################\n");
        printf("> 심사자 이름: ");
        scanf("%s", judge_name);
        printf("> 전문 분야: ");
        scanf("%s", expertise);

        // 점수 입력
        input_scores();

        // 점수 검토
        print_scores();

        // 제출 여부 확인
        if (confirm_submission()) {
            printf("***최종 제출을 완료했습니다.***\n");
            break;
        } else {
            printf("점수 입력을 다시 시작합니다.\n");
        }
    }

    return 0;
}

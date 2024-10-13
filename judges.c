#include <stdio.h>
#include <stdlib.h>

#define MAX_JUDGES 10
#define MAX_INPUT_SIZE 256

// 심사자 정보를 저장하는 배열
char judges_array[MAX_JUDGES][MAX_INPUT_SIZE];

int main() {
    int num_judges;
    int num_project;
    char project_name[50];
    char choice;

    printf("####################################\n");
    printf("#       심사자 풀 데이터 입력       #\n");
    printf("####################################\n");
    printf("> 참여 프로젝트: ");
    scanf("%s", project_name);
    printf("> 심사 풀 인원: ");
    scanf("%d", &num_judges);
    printf("> 선발 멤버 수: ");
    scanf("%d", &num_project);  // & 추가하여 변수 주소 전달
    
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("%d명의 심사자 정보 입력을 시작합니다.\n", num_judges);
    printf("++++++++++++++++++++++++++++++++++++\n");

    // 입력 버퍼 정리
    getchar();  // 버퍼에 남은 개행 문자 제거

    // 심사자 정보 입력
    for (int i = 0; i < num_judges; i++) {
        printf("*심사자 %d: ", i + 1);
        fgets(judges_array[i], sizeof(judges_array[i]), stdin);  // 심사자 정보 입력
    }

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("심사자 풀 입력이 끝났습니다.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    // 심사자 풀 확인 여부 묻기
    printf("“심사자 풀을 확인할까요? (Y/N): ");
    scanf(" %c", &choice);

    if (choice == 'Y') {
        printf("####################################\n");
        printf("#       심사자 풀 데이터 출력       #\n");
        printf("####################################\n");
        for (int i = 0; i < num_judges; i++) {
            printf("[심사자 %d]\n%s-----------------------------------\n", i + 1, judges_array[i]);
        }
    } else {
        printf("프로그램을 종료합니다.\n");
    }

    return 0;
}


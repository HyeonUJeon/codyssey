#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANDIDATE_COUNT 6
#define MILLIWAYS_MEMBER_COUNT 4

// 후보자 데이터 구조체
typedef struct {
    int id;
    char name[50];
    char nickname[20];
    char education[20];
    float height;
    float weight;  // 계산할 값
    char blood_type[3];
    char allergy[20];
    char hobbies[50];
    char sns[50];
    int pass;
    float bmi;  // 계산할 값
} Candidate;

// 후보자 데이터 배열 (문제 3과 문제 5의 데이터 기반)
Candidate candidate_arr[CANDIDATE_COUNT] = {
    {1, "박지연", "Ariel", "고1중퇴", 1.68, 0, "A", "유제품", "댄스 연습, 작곡", "Instagram - @Ariel_Jiyeon", 1, 0},
    {2, "Ethan Smith", "Simba", "중3중퇴", 1.78, 0, "O", "땅콩", "노래 작곡, 헬스 트레이닝", "Twitter - @Simba_Ethan", 1, 0},
    {3, "Helena Silva", "Belle", "중졸", 1.63, 0, "B", "생선", "노래 부르기, 그림 그리기", "Instagram - @Belle_Helena", 1, 0},
    {4, "Liam Wilson", "Aladdin", "중2중퇴", 1.75, 0, "AB", "갑각류", "춤추기, 음악 프로듀싱", "Instagram - @Aladdin_Liam", 1, 0},
    {5, "Lee Hana", "Rose", "대졸", 1.60, 0, "A", "견과류", "피아노 연주", "Instagram - @Rose_Hana", 0, 0},
    {6, "Kim Minjun", "Jay", "대졸", 1.82, 0, "O", "없음", "축구, 음악 감상", "Twitter - @Jay_Minjun", 0, 0}
};

// 밀리웨이즈 멤버 배열
Candidate milliways_arr[MILLIWAYS_MEMBER_COUNT];

// BMI 계산 함수
float calculate_bmi(float height, float weight) {
    return weight / (height * height);
}

// BMI 상태 표시 함수
void display_bmi_status(float bmi) {
    switch ((int)(bmi / 5)) {
        case 3: // 15~19.9
            printf("저체중\n");
            break;
        case 4: case 5: // 20~24.9
            printf("정상\n");
            break;
        case 6: case 7: // 25~29.9
            printf("과체중\n");
            break;
        default: // 30 이상
            printf("비만\n");
            break;
    }
}

// main 함수
int main() {
    int j = 0;
    for (int i = 0; i < CANDIDATE_COUNT; i++) {
        if (candidate_arr[i].pass) {
            // 합격자 정보를 milliways_arr로 복사
            milliways_arr[j] = candidate_arr[i];
            
            // 추가 데이터: BMI 값에 따라 몸무게 설정 및 상태 계산
            printf("Enter weight for %s (kg): ", milliways_arr[j].name);
            scanf("%f", &milliways_arr[j].weight);

            // BMI 계산
            milliways_arr[j].bmi = calculate_bmi(milliways_arr[j].height, milliways_arr[j].weight);
            
            // 결과 출력
            printf("ID: %d, Name: %s, Nickname: %s, BMI: %.2f, Status: ",

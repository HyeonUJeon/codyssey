#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define NAME_LENGTH 50
#define EMAIL_LENGTH 50
#define NATIONALITY_LENGTH 20
#define MAIN_SKILL_LENGTH 20
#define SUB_SKILL_LENGTH 20
#define INTRO_LENGTH 256

// 후보자 구조체 정의
typedef struct {
    char name[NAME_LENGTH];
    char birthdate[11]; // YYYY/MM/DD 형식
    char gender; // 'F' 또는 'M'
    char email[EMAIL_LENGTH];
    char nationality[NATIONALITY_LENGTH];
    float bmi;
    char main_skill[MAIN_SKILL_LENGTH];
    char sub_skill[SUB_SKILL_LENGTH];
    int topik; // TOPIK 등급
    char mbti[5];
    char introduction[INTRO_LENGTH];
    int age; // 만 나이
} Candidate;

// 만 나이를 계산하는 함수
int calculate_age(const char *birthdate) {
    struct tm birth;
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);
    
    sscanf(birthdate, "%d/%d/%d", &birth.tm_year, &birth.tm_mon, &birth.tm_mday);
    birth.tm_year -= 1900; // tm_year는 1900년을 기준으로 하므로 조정
    birth.tm_mon -= 1; // tm_mon은 0부터 시작하므로 조정
    birth.tm_isdst = -1; // 일광 절약 시간제 설정

    time_t birth_time = mktime(&birth);
    
    if (birth_time == -1) {
        return -1; // 잘못된 생일 입력 시
    }

    int age = current_time->tm_year + 1900 - birth.tm_year;
    if (current_time->tm_mon < birth.tm_mon ||
        (current_time->tm_mon == birth.tm_mon && current_time->tm_mday < birth.tm_mday)) {
        age--; // 생일이 지나지 않은 경우
    }
    return age;
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int candidate_count = 0;

    printf("####################################\n");
    printf("     오디션 후보자 데이터 입력\n");
    printf("####################################\n");

    // 후보자 데이터 입력
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%d 번째 후보자의 정보를 입력합니다.\n", i + 1);
        printf("---------------------------------\n");
        
        printf("1. 성명: ");
        fgets(candidates[i].name, NAME_LENGTH, stdin);
        candidates[i].name[strcspn(candidates[i].name, "\n")] = 0; // 개행 문자 제거
        
        printf("2. 생일(YYYY/MM/DD 형식): ");
        fgets(candidates[i].birthdate, 11, stdin);
        candidates[i].birthdate[strcspn(candidates[i].birthdate, "\n")] = 0; // 개행 문자 제거
        
        printf("3. 성별(여성이면 F 또는 남성이면 M): ");
        scanf(" %c", &candidates[i].gender);
        getchar(); // 입력 버퍼 비우기
        
        printf("4. 메일 주소: ");
        fgets(candidates[i].email, EMAIL_LENGTH, stdin);
        candidates[i].email[strcspn(candidates[i].email, "\n")] = 0; // 개행 문자 제거
        
        printf("5. 국적: ");
        fgets(candidates[i].nationality, NATIONALITY_LENGTH, stdin);
        candidates[i].nationality[strcspn(candidates[i].nationality, "\n")] = 0; // 개행 문자 제거
        
        printf("6. BMI: ");
        scanf("%f", &candidates[i].bmi);
        getchar(); // 입력 버퍼 비우기
        
        printf("7. 주 스킬: ");
        fgets(candidates[i].main_skill, MAIN_SKILL_LENGTH, stdin);
        candidates[i].main_skill[strcspn(candidates[i].main_skill, "\n")] = 0; // 개행 문자 제거
        
        printf("8. 보조 스킬: ");
        fgets(candidates[i].sub_skill, SUB_SKILL_LENGTH, stdin);
        candidates[i].sub_skill[strcspn(candidates[i].sub_skill, "\n")] = 0; // 개행 문자 제거
        
        printf("9. 한국어 등급(TOPIK): ");
        scanf("%d", &candidates[i].topik);
        getchar(); // 입력 버퍼 비우기
        
        printf("10. MBTI: ");
        fgets(candidates[i].mbti, 5, stdin);
        candidates[i].mbti[strcspn(candidates[i].mbti, "\n")] = 0; // 개행 문자 제거
        
        printf("11. 소개: ");
        fgets(candidates[i].introduction, INTRO_LENGTH, stdin);
        candidates[i].introduction[strcspn(candidates[i].introduction, "\n")] = 0; // 개행 문자 제거

        // 만 나이 계산
        candidates[i].age = calculate_age(candidates[i].birthdate);
        
        candidate_count++;
        printf("=================================\n");
    }

    // 후보자 데이터 출력
    printf("####################################\n");
    printf("     오디션 후보자 데이터 조회\n");
    printf("####################################\n");
    printf("=============================================================================================\n");
    printf("성   명 | 생   일 | 성별 | 메   일            | 국적 | BMI | 주스킬 | 보조스킬 | TOPIK | MBTI |\n");
    printf("=============================================================================================\n");

    for (int i = 0; i < candidate_count; i++) {
        printf("%s (%d세) |%s | %c   | %s | %s | %.1f | %s | %s | %s | %s |\n",
               candidates[i].name, candidates[i].age, candidates[i].birthdate,
               candidates[i].gender, candidates[i].email, candidates[i].nationality,
               candidates[i].bmi, candidates[i].main_skill, candidates[i].sub_skill,
               (candidates[i].topik == 0) ? "원어민" : (candidates[i].topik == 1) ? "초급" :
               (candidates[i].topik == 2) ? "중급" : "고급", candidates[i].mbti);
        printf("        -------------------------------------------------------------------------------------\n");
        printf("%s     |\n", candidates[i].introduction);
        printf("---------------------------------------------------------------------------------------------\n");
    }

    return 0;
}


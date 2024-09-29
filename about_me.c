#include <stdio.h>

// 구조체 정의
typedef struct {
    char name[20];
    char gender[5];
    char major[30];
    unsigned int experience;  // 경력은 이진수로 표현
    char role[20];
    char skills[100];
    char introduction[600];
} Member;

// 이진수 출력 함수
void print_binary(unsigned int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 8 == 0 && i != 0) {
            printf(" ");
        }
    }
    printf("(2)");
}

// 멤버 정보 출력 함수
void print_member_info(Member member) {
    printf("이름 | %s\t성별 | %s\n", member.name, member.gender); // 성별
    printf("전공 | %s\t경력 | ", member.major); // 전공
    print_binary(member.experience); // 경력
    printf("년\n"); //경력
    printf("역할 | %s\t기술 | %s\n", member.role, member.skills); // 역할, 기술
    printf("---------------------------------------------------------------------\n");
    printf("소개 | %s\n", member.introduction); // 소개
    printf("=====================================================================\n");
}

int main() {
    Member members[5] = {
        // 멤버 정보
        {"아서 덴트", "남", "기계 공학", 15, "아키텍트", "C/C++, 자바, 스프링, 파이썬, 머신러닝/딥러닝",
         "실리콘 밸리에서 SNS, 핀테크, HR, 미디어 등의 다양한 프로젝트에 참여하며 경력을 쌓았습니다. 성공과 실패를 겪으며 얻게된 깨달음을 여러분과 나누고 싶습니다."},
        {"김영진", "남", "컴퓨터 공학", 2, "개발자", "C#, 파이썬, 자바스크립트, 리액트, 코틀린",
         "최근에 MAUI 프레임워크로 진행한 개인 자산 관리 프로젝트에서 소프트웨어 개발에 엄청난 매력을 느꼈습니다. 나의 코드로 현실의 문제를 해결한다니! 마그라테아를 성공적으로 개발하는 것은 저의 버킷 리스트 중 하나가 되었습니다."},
        {"임원철", "남", "전자 공학", 1, "DBA", "자바, PHP, Mongo DB, MS SQL, MySQL",
         "애플리케이션은 결국 데이터를 다루는 방식을 구현한 것이라고 생각합니다. 대학에서 컴퓨터 공학과의 빅데이터 과목을 수강하며 데이터 플랫폼에 관해 매력을 느꼈습니다. 이번 프로젝트의 성공 여부는 데이터에 달렸다고 생각합니다. 마그라테아에서 다룰 데이터를 생각하면 벌써부터 흥분됩니다."},
        {"유고은", "여", "경영 정보", 1, "클라우드", "자바, PowerShell, Azure, AWS, GCP",
         "김영진님과 함께 프로젝트를 진행했으며 클라우드 아키텍처 구현을 담당했습니다. 학창시절 클라우드에 매력을 느껴 마이크로소프트 Azure에 빠져들었는데, 깊이 탐구하다 보니 다른 퍼블릭 클라우드도 어렵지 않게 이해할 수 있었습니다. 마그라테아의 클라우드 아키텍처를 내 손으로 꼭 완성시키고 싶습니다."},
        {"서혜경", "여", "정치외교", 0, "개발자", "파이썬, 스위프트, 코틀린, Node.js, 피그마",
         "학부과정에서 과제로 프로젝트는 많이 진행해봤지만, 기업의 사활이 걸린 실전 프로젝트는 제 인생의 첫 경험입니다. 이 프로젝트에 참여하게 되어 기대도 많이 되는 한편으로, 제가 잘할 수 있을까 염려가 되기도 합니다. 마그라테아 프로젝트에 관해 들었을 때 제 속에서 이 프로젝트는 인생을 걸고 싶다는 생각을 했습니다. 링크드인을 통해 이미 아서님의 명성을 접했던 터라, 이번 프로젝트에 함께할 수 있어서 영광입니다."}
    };

    // 멤버 정보 출력
    printf("[마그라테아] ❤❤ 프로젝트 멤버 소개 ❤❤\n");
    printf("=====================================================================\n");
    for (int i = 0; i < 5; i++) {
        print_member_info(members[i]);
    }

    return 0;
}
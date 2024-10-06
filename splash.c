#include <stdio.h>
#include <stdlib.h>

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void wait_three_seconds() {
    volatile long long i;  // 컴파일러 최적화를 방지하기 위해 volatile 사용
    for (i = 0; i < 3000000000; i++) {
        
    }
}

void printStarsWithMessage(int i)
{
    // 메시지를 배열에 저장
    const char* messages[] = {
        "                         [마그라테아 ver 0.1]                                     *****",
        "           풀 한 포기 없는 황무지에서 반짝이는 행성을 만들내는 곳 마그라테아,                   ****",
        "         사람들이 보지 못하는 잠재력을 찾고 전문가의 손길을 더해 보석을 빗는 곳,                 ***",
        "                         마그라테아에 오신걸 환영합니다.                               **",
        "                                                                               *"
    };

    // 별 출력
    for (int j = 1; j <= i; j++) {
        printf("*");
    }
    
    // 메시지 출력
    if (i >= 1 && i <= 5) {
        printf("%s\n", messages[i - 1]);
    }
}

int main()
{
    char date[11];
    char name[50];

    printf("[현재 날짜를 \"yyyy-mm-dd\" 형식으로 입력하세요]: ");
    scanf("%10s", date);

    printf("[당신의 이름을 입력하세요]: ");
    scanf("%49s", name);

    printf("**입력이 정상적으로 처리되었습니다.**\n");

    wait_three_seconds();

    clear_screen();

    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\n");
   
    for (int i = 1; i <= 5; i++)
    {
       printStarsWithMessage(i);
    }

    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("[사용자]: %s                                         [실행 시간]: %s\n", name, date);
    printf("=======================================================================================\n");

    return 0;
}


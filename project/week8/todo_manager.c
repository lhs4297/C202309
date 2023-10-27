#include <stdio.h>
#define MAX_TASKS 10
#define CHAR_NUM 100
#include <string.h>

char tasks[MAX_TASKS][CHAR_NUM] = { "" }; // 할 일 목록을 저장하기 위한 2차원 배열
int taskCount = 0; // 할 일의 수를 저장하기 위한 변수


// 할일 생성하는 함수
void addTask(char tasks[][CHAR_NUM], int taskCount) {
	printf("할 일을 입력하세요 (공백 없이 입력하세요): ");
	scanf_s("%s", tasks[taskCount], CHAR_NUM);
	printf("할 일 ""%s""가 저장되었습니다\n", tasks[taskCount]);

}


// 할일 삭제하는 함수
void delTask(int delIndex, int taskCount) {
	printf("삭제할 할 일의 번호를 입력해주세요. (1부터 시작):");
	scanf_s("%d", &delIndex);
	if (delIndex > taskCount || delIndex <= 0) {
		printf("삭제 범위가 벗어났습니다.\n");
	}
	else {
		printf("%d. %s : 할 일을 삭제합니다.\n", delIndex, tasks[delIndex - 1]);

		// 배열간 대입 (=배열에 문자 배열인 문자열의 대입) 이 불가능하기 때문에
		// 문자열 복사 함수로 삭제
		strcpy_s(tasks[delIndex - 1], sizeof(tasks[delIndex - 1]), "");

		// 특정 인덱스의 할 일 삭제 후 뒤에 있는 할 일 앞으로 옮기기
		for (int i = delIndex; i < taskCount + 1; i++) {
			strcpy_s(tasks[i - 1], sizeof(tasks[i]), tasks[i]);
		}
	}

}

// 할일 목록 불러오는 함수
void printTask(int taskCount) {
	printf("할 일 목록\n");
	for (int i = 0; i < taskCount; i++) {
		printf("%d. %s \n", i + 1, tasks[i]);
	}
	printf("\n");
}

// 할일 수정하는 함수
void modifyTask(int delIndex, char tasks[][CHAR_NUM], int taskCount) {
	printf("수정할 할 일의 번호를 입력해주세요. (1부터 시작):");
	scanf_s("%d", &delIndex);
	if (delIndex > taskCount || delIndex <= 0) {
		printf("번호의 범위가 벗어났습니다.\n");
	}
	else {   // 삭제하는 함수 변형해서 수정하는 함수로 바꿈
		printf("새로운 일을 입력하세요 (공백 없이 입력하세요): ");
		scanf_s("%s", tasks[taskCount], CHAR_NUM);
		strcpy_s(tasks[delIndex - 1], sizeof(tasks[delIndex - 1]), tasks[taskCount]);   // 배열에 있는 index를 %S에서 받아온 값으로 덮어쓰기
		printf("새로운 일 ""%s""가 저장되었습니다\n", tasks[taskCount]);
	}

}

int main() {



	printf("TODO 리스트 시작! \n");

	while (1) {

		// taskCount 가 10개가 되면 종료하고 아니면 밑의 main함수를 진행
		if (taskCount == 10) {
			printf("------------------------------------------\n");
			printf("할일이 다 찼습니다. 프로그램을 종료합니다.\n");
			printf("------------------------------------------\n");
			break;
		}
		else {



			int choice = -1; // 오류를 방지하기  위해 -1로 지정해 초기화해줌

			// 사용자에게 메뉴를 출력하고, 메뉴를 입력받기
			printf("------------------\n");
			printf("메뉴를 입력해주세요.\n");;
			printf("1. 할 일 추가\n2. 할 일 삭제\n3. 목록 보기\n4. 종료\n5.할 일 수정\n");
			printf("현재 할 일 수 = %d\n", taskCount);
			printf("------------------\n");
			scanf_s("%d", &choice);

			int terminate = 0; // 종료를 위한 flag
			int delIndex = -1;  // 할 일 삭제를 위한 index 저장 변수
			int changeIndex = -1; // 할 일 수정을 위한 index 저장 변수
			char ch; // 할 일 수정시 버퍼를 받기 위한 문자 변수




			// 입력에 따른 기능 수행
			switch (choice) {
			case 1:
				addTask(tasks, taskCount);
				taskCount++;
				break;
			case 2:
				// 할 일 삭제하는 코드 블록
				delTask(delIndex, taskCount);
				taskCount -= 1;
				break;
			case 3:
				printTask(taskCount);
				break;
			case 4:
				terminate = 1;
				break;
			case 5:  // 할일 수정하는 함수 추가
				modifyTask(delIndex, tasks, taskCount);
				break;
			default:
				printf("잘못된 선택입니다. 다시 선택하세요.\n");
			}

			if (terminate == 1) {
				printf("종료를 선택하셨습니다. 프로그램을 종료합니다.\n");
				break;
			}
		}


	}
}
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#define TIMEOUT 5
#define BUF_LEN 1024

int main(void)
{
	struct timeval tv;
	fd_set readfds;
	int ret;

	/* 표준 입력에서 입력을 기다리기 위한 준비 */
	FD_ZERO(&readfds);
	FD_SET(STDIN_FILENO, &readfds);

	/* select가 5초 동안 기다리도록 timeval 구조체 설정 */
	tv.tv_sec = TIMEOUT;
	tv.tv_usec = 0;

	/* 이제 입력을 기다리자! */
	ret = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv);
	if(ret == 1){
		perror("select");
		return 1;
	}
	else if(!ret){
		printf("%d seconds elapsed.\n", TIMEOUT);
		return 0;
	}

	/*
	 * 여기까지 오면 select가 0이 아닌 양수를 반환했다는 의미이므로
	 * 파일 디스크립터에서 즉시 읽기가 가능하다.
	 */

	if(FD_ISSET(STDIN_FILENO, &readfds)){
		char buf[BUF_LEN+1];
		int len;

		/* 여기서 read()는 블록되지 않는다. */
		len = read(STDIN_FILENO, buf, BUF_LEN);
		if(len == -1){
			perror("read");
			return 1;
		}

		if(len){
			buf[len] = '\0';
			printf("read : %s\n", buf);
		}

		return 0;
	}

	fprintf(stderr, "This should not happen!\n");
	return 1;
}

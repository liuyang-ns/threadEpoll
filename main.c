#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Server.h"

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		printf("./a.out port path\n");
		return -1;
	}
	unsigned short port = atoi(argv[1]);
	//�л��������Ĺ���·��
	chdir(argv[2]);

	//��ʼ���������׽���
	int lfd = initListenFd(port);

	//��������������
	epollRun(lfd);

	return 0;
}
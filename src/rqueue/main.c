#include <stdio.h>
#include <stdlib.h>

#include "clib/rqueue/rqueue.h"

int main(int argc, char* argv[])
{
	rqueue_t q;
	rqdata_t data;

	rqueue_reset(&q);
	rqueue_write(&q, 1);
	rqueue_write(&q, 2);
	rqueue_write(&q, 3);
	rqueue_write(&q, 4);
	rqueue_read(&q, &data);

	rqueue_print(&q);

	return 0;
}


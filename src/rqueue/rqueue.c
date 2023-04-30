#include "clib/rqueue/rqueue.h"

#include <stdio.h>
#include <string.h>

rqstatus_t rqueue_reset(rqueue_t *q)
{
	int i = 0;

	q->addr_wr = 0;
	q->addr_rd = 0;
	q->length = RQ_DATA_SIZE;

	memset(q->data, 0, sizeof(q->data));

	return RQUEUE_OK;
}

rqstatus_t rqueue_write(rqueue_t *q, rqdata_t data)
{
	if (rqueue_status(q) == RQUEUE_FULL)
	{
		printf("Write failed, rqueue is full\n");
		return RQUEUE_FULL;
	}

	q->data[q->addr_wr] = data;
	q->addr_wr = (q->addr_wr + 1) % q->length;

	printf("Write success\n");

	return RQUEUE_OK;
}

rqstatus_t rqueue_read(rqueue_t *q, rqdata_t *pdata)
{
	if (rqueue_status(q) == RQUEUE_EMPTY)
	{
		printf("Read failed, rqueue is empty\n");
		return RQUEUE_EMPTY;
	}

	*pdata = q->data[q->addr_rd];
	q->addr_rd = (q->addr_rd + 1) % q->length;

	printf("Read success\n");

	return RQUEUE_OK;
}

rqstatus_t rqueue_status(rqueue_t *q)
{
	if (q->addr_wr == q->addr_rd)
	{
		return RQUEUE_EMPTY;
	}
	else if ((q->addr_wr + 1) % q->length == q->addr_rd)
	{
		return RQUEUE_FULL;
	}
	
	return RQUEUE_OK;
}

int rqueue_count(rqueue_t *q)
{
	if (q->addr_rd <= q->addr_wr)
	{
		return (q->addr_wr - q->addr_rd);
	}

	return q->length + q->addr_wr - q->addr_rd;
}


void rqueue_print(rqueue_t *q)
{
	int i = 0;
	int count = rqueue_count(q);
	
	printf("read addr: %d\n", q->addr_rd);
	printf("write addr: %d\n", q->addr_wr);
	printf("count: %d, data:\n\t", rqueue_count(q));

	for (i = 0; i < count; ++i)
	{
    int index = (q->addr_rd + i) % q->length;
		printf("%d ", q->data[index]);	
	}
	printf("\n");
}


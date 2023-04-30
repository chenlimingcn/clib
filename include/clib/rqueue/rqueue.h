#ifndef RQUEUE_H__
#define RQUEUE_H__

#include <stdint.h>

#define rqdata_t uint8_t

#define RQ_DATA_SIZE 1024

typedef enum
{
	RQUEUE_OK = 0,
	RQUEUE_FULL,
	RQUEUE_EMPTY,
}rqstatus_t;

typedef struct
{
	uint16_t addr_wr;
	uint16_t addr_rd;
	uint16_t length;
	rqdata_t data[RQ_DATA_SIZE];
}rqueue_t;


rqstatus_t rqueue_reset(rqueue_t *q);
rqstatus_t rqueue_read(rqueue_t *q, rqdata_t *pdata);
rqstatus_t rqueue_write(rqueue_t *q, rqdata_t data);

rqstatus_t rqueue_status(rqueue_t *q);
void rqueue_print(rqueue_t *q);

#endif//RQUEUE_H__


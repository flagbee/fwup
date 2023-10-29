#ifndef __QUEUE_H
#define __QUEUE_H

#include <stdint.h>
#include "global.h"

#define ENABLE_ALL_IRQ()    __enable_irq()
#define DISABLE_ALL_IRQ()   __disable_irq()

extern uint8_t queue_init(uint16_t *Front, uint16_t *Rear, uint8_t *PBase, uint16_t Len);
extern uint8_t queue_full(uint16_t *Front, uint16_t *Rear, uint8_t *PBase, uint16_t Len);
extern uint8_t queue_empty(uint16_t *Front, uint16_t *Rear, uint8_t *PBase, uint16_t Len);
extern uint8_t queue_in(uint16_t *Front, uint16_t *Rear, uint8_t *PBase, uint16_t Len, uint8_t *PData);
extern uint8_t queue_out(uint16_t *Front, uint16_t *Rear, uint8_t *PBase, uint16_t Len, uint8_t *PData);
extern uint8_t queue_count(uint16_t *Front, uint16_t *Rear, uint8_t *PBase, uint16_t Len, uint16_t *PCount);

#define QUEUE_INIT(q)       queue_init((uint16_t *) &(q.Front),(uint16_t *) &(q.Rear),(uint8_t *) &(q.PBase[0]),(uint16_t) (sizeof(q.PBase)))
#define QUEUE_FULL(q)       queue_full((uint16_t *) &(q.Front),(uint16_t *) &(q.Rear),(uint8_t *) &(q.PBase[0]),(uint16_t) (sizeof(q.PBase)))
#define QUEUE_EMPTY(q)      queue_empty((uint16_t *) &(q.Front),(uint16_t *) &(q.Rear),(uint8_t *) &(q.PBase[0]),(uint16_t) (sizeof(q.PBase)))
#define QUEUE_IN(q, pdata)  queue_in((uint16_t *) &(q.Front),(uint16_t *) &(q.Rear),(uint8_t *) &(q.PBase[0]),(uint16_t) (sizeof(q.PBase)),(uint8_t *) &pdata)
#define QUEUE_OUT(q, pdata) queue_out((uint16_t *) &(q.Front),(uint16_t *) &(q.Rear),(uint8_t *) &(q.PBase[0]),(uint16_t) (sizeof(q.PBase)),(uint8_t *) &pdata)

typedef struct queue2048 {
    uint16_t    Front;
    uint16_t    Rear;
    uint8_t     PBase[2048 + 1];
} __packed QUEUE2048_S;

#endif /* __QUEUE_H */


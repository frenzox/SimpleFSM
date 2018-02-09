#ifndef SIMPLE_FSM_H
#define SIMPLE_FSM_H

typedef void (*function_pointer)(void *);

typedef struct{
    function_pointer ptr;
    unsigned char first_time;
}SimpleFSM;

#define STATE(name)         void name(SimpleFSM *_sm_)
#define NEXT_STATE(name)    _sm_->ptr = (function_pointer)name
#define INIT(sm,name)       {sm.ptr = (function_pointer)name;sm.first_time=1;}
#define EXEC(sm)            {function_pointer temp=sm.ptr;sm.ptr(&sm);sm.first_time=(temp != sm.ptr);}
#define FIRST               (_sm_->first_time)
#define COMPARE(sm,name)    (sm.ptr == (function_pointer)name)

#endif // SIMPLE_FSM_H

#ifndef BIT_CLC
#define BIT_CLC

#define SET_BIT(num,bit)   num=num|(1<<bit)
#define CLR_BIT(num,bit)   num=num&~(1<<bit)
#define TOGGLE_BIT(num,bit)   num=num^(1<<bit)
#define GEt_BIT(num,bit)   ((num&(1<<bit))>>bit)
#define ASSGIN_BIT_MACRO(num,bit,value)    (value>0)?(SET_BIT(num,bit)):(CLR_BIT(num,bit))
#define ASSGIN_BIT(num,bit,value)           do(if(value==0)\
{\
	CLR_BIT(num,bit);\
}\
else\
{\
   SET_BIT(num,bit);\
})while(0);
   


	                                  
                                               



#endif 


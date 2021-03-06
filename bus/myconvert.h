#ifndef __MY_CONVERT_H

#define __MY_CONVERT_H
#include <stdlib.h>
#include <stdio.h>
typedef int8_t	int8;
typedef int16_t	int16;
typedef int32_t	int32;
typedef int64_t int64;
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;


#define sint2korr(A)    (*((int16 *) (A)))
#define sint3korr(A)    ((int32) ((((uint8) (A)[2]) & 128) ? \
                  (((uint32) 255L << 24) | \
                   (((uint32) (uint8) (A)[2]) << 16) |\
                   (((uint32) (uint8) (A)[1]) << 8) | \
                   ((uint32) (uint8) (A)[0])) : \
                  (((uint32) (uint8) (A)[2]) << 16) |\
                  (((uint32) (uint8) (A)[1]) << 8) | \
                  ((uint32) (uint8) (A)[0])))
#define sint4korr(A)    (*((int32 *) (A)))

            
#define uint8korr(A)    ((uint64)(((uint32) ((uint8) (A)[0])) +\
                    (((uint32) ((uint8) (A)[1])) << 8) +\
                    (((uint32) ((uint8) (A)[2])) << 16) +\
                    (((uint32) ((uint8) (A)[3])) << 24)) +\
            (((uint64) (((uint32) ((uint8) (A)[4])) +\
                    (((uint32) ((uint8) (A)[5])) << 8) +\
                    (((uint32) ((uint8) (A)[6])) << 16) +\
                    (((uint32) ((uint8) (A)[7])) << 24))) <<\
                    32))
            
#define sint8korr(A)    (int64) uint8korr(A)


#define uint2korr(A)    (*((uint16*) (A)))
        
        
#define uint3korr(A)    (uint32) (((uint32) ((uint8) (A)[0])) +\
                  (((uint32) ((uint8) (A)[1])) << 8) +\
                  (((uint32) ((uint8) (A)[2])) << 16))
        
#define uint4korr(A)    (*((uint32 *) (A)))

#define uint5korr(A) ((uint64_t)(((uint32_t) (((uint8_t *) (A))[4])) +\
            (((uint32_t) (((uint8_t *) (A))[3])) << 8) +\
            (((uint32_t) (((uint8_t *) (A))[2])) << 16) +\
            (((uint32_t) (((uint8_t *) (A))[1])) << 24)) +\
            (((uint64_t) (((uint8_t *) (A))[0])) << 32))

        
#define uint6korr(A)    ((int64)(((uint32)    ((uint8) (A)[0]))          + \
                                     (((uint32)    ((uint8) (A)[1])) << 8)   + \
                                     (((uint32)    ((uint8) (A)[2])) << 16)  + \
                                     (((uint32)    ((uint8) (A)[3])) << 24)) + \
                         (((int64) ((uint8) (A)[4])) << 32) +       \
                         (((int64) ((uint8) (A)[5])) << 40))


#define mi_sint1korr(A) ((int8)(*A))
#define mi_uint1korr(A) ((uint8)(*A))

#define mi_sint2korr(A) ((int16) (((int16) (((uint8_t*) (A))[1])) +\
                                  ((int16) ((int16) ((char*) (A))[0]) << 8)))
#define mi_sint3korr(A) ((int32) (((((uint8_t*) (A))[0]) & 128) ? \
                                  (((uint32) 255L << 24) | \
                                   (((uint32) ((uint8_t*) (A))[0]) << 16) |\
                                   (((uint32) ((uint8_t*) (A))[1]) << 8) | \
                                   ((uint32) ((uint8_t*) (A))[2])) : \
                                  (((uint32) ((uint8_t*) (A))[0]) << 16) |\
                                  (((uint32) ((uint8_t*) (A))[1]) << 8) | \
                                  ((uint32) ((uint8_t*) (A))[2])))
#define mi_sint4korr(A) ((int32) (((int32) (((uint8_t*) (A))[3])) +\
                                  ((int32) (((uint8_t*) (A))[2]) << 8) +\
                                  ((int32) (((uint8_t*) (A))[1]) << 16) +\
                                  ((int32) ((int16) ((char*) (A))[0]) << 24)))
#define mi_sint8korr(A) ((longlong) mi_uint8korr(A))
#define mi_uint2korr(A) ((uint16) (((uint16) (((uint8_t*) (A))[1])) +\
                                   ((uint16) (((uint8_t*) (A))[0]) << 8)))
#define mi_uint3korr(A) ((uint32) (((uint32) (((uint8_t*) (A))[2])) +\
                                   (((uint32) (((uint8_t*) (A))[1])) << 8) +\
                                   (((uint32) (((uint8_t*) (A))[0])) << 16)))
#define mi_uint4korr(A) ((uint32) (((uint32) (((uint8_t*) (A))[3])) +\
                                   (((uint32) (((uint8_t*) (A))[2])) << 8) +\
                                   (((uint32) (((uint8_t*) (A))[1])) << 16) +\
                                   (((uint32) (((uint8_t*) (A))[0])) << 24)))
#define mi_uint5korr(A) ((uint64_t)(((uint32) (((uint8_t*) (A))[4])) +\
                                    (((uint32) (((uint8_t*) (A))[3])) << 8) +\
                                    (((uint32) (((uint8_t*) (A))[2])) << 16) +\
                                    (((uint32) (((uint8_t*) (A))[1])) << 24)) +\
                                    (((uint64_t) (((uint8_t*) (A))[0])) << 32))
#define mi_uint6korr(A) ((uint64_t)(((uint32) (((uint8_t*) (A))[5])) +\
                                    (((uint32) (((uint8_t*) (A))[4])) << 8) +\
                                    (((uint32) (((uint8_t*) (A))[3])) << 16) +\
                                    (((uint32) (((uint8_t*) (A))[2])) << 24)) +\
                        (((uint64_t) (((uint32) (((uint8_t*) (A))[1])) +\
                                    (((uint32) (((uint8_t*) (A))[0]) << 8)))) <<\
                                     32))
#define mi_uint7korr(A) ((uint64_t)(((uint32) (((uint8_t*) (A))[6])) +\
                                    (((uint32) (((uint8_t*) (A))[5])) << 8) +\
                                    (((uint32) (((uint8_t*) (A))[4])) << 16) +\
                                    (((uint32) (((uint8_t*) (A))[3])) << 24)) +\
                        (((uint64_t) (((uint32) (((uint8_t*) (A))[2])) +\
                                    (((uint32) (((uint8_t*) (A))[1])) << 8) +\
                                    (((uint32) (((uint8_t*) (A))[0])) << 16))) <<\
                                     32))
#define mi_uint8korr(A) ((uint64_t)(((uint32) (((uint8_t*) (A))[7])) +\
                                    (((uint32) (((uint8_t*) (A))[6])) << 8) +\
                                    (((uint32) (((uint8_t*) (A))[5])) << 16) +\


#define float4get(V,M)   do { *((float *) &(V)) = *((float*) (M)); } while(0)

typedef union {
  double v;
  long m[2];
} doubleget_union;

#define doubleget(V,M)  \
do { doubleget_union _tmp; \
     _tmp.m[0] = *((long*)(M)); \
     _tmp.m[1] = *(((long*) (M))+1); \
     (V) = _tmp.v; } while(0)

#define float8get(V,M)   doubleget((V),(M))
#if 0
int DecodePacketInt(const char*pBuf,uint32 *pPos){
    int n = (int)(uint8)(*pBuf); 
    int i = 0;
    
    if (n < 251){
        *pPos += 1;
        return n; 
    }
    else if (n == 251){
        *pPos += 1;
        return 0;
    }
    else if (n == 252){
        i = uint2korr((pBuf + 1)); *pPos += 3;
        return i;  
    }
    else if (n == 253){
        i = uint3korr((pBuf + 1)); *pPos += 4;
        return i;
    }                   
    else{               
        i = uint4korr((pBuf + 1)); *pPos += 9;
        return i;
    }
} 
#endif

#endif  

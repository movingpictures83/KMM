#ifndef SCOREREADS_H
#define SCOREREADS_H

__global__ void scoreReads(char* genome, int seqLength, int order, float* model, float* scores);

#endif

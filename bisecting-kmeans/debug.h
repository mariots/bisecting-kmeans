//
//  debug.h
//  bisecting-clustermeans
//
//  Created by Mario Jimenez on 10/30/17.
//  Copyright © 2017 mariot. All rights reserved.
//

#ifndef debug_h
#define debug_h

#include <stdio.h>

/* debug functions */
void printSpecificDataPoint(double *data, int requestedElement, int dim);
void printData(double *data, int totalElements, int dim);
void printBoundry(double **cluster_bdry, int cluster, int dim);
void printCentroid(double **cluster_centroid, int cluster, int dim);
void printClusterSize(int *clusterSize, int cluster);
void printClusterStart(int *clusterStart, int cluster);
void printClusterAssign(int *clusterAssign, int ndata);
void printClusterRadius(double *clusterRadius, int cluster);

#endif /* debug_h */

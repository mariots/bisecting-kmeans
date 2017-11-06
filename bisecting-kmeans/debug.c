//
//  debug.c
//  bisecting-kmeans
//
//  Created by Mario Jimenez on 10/30/17.
//  Copyright © 2017 mariot. All rights reserved.
//

#include "debug.h"

/* debug functions */
void printSpecificDataPoint(double *data, int requestedElement, int dim) {
    printf("Element %d\n", requestedElement);
    for (int i = 0; i < dim; i++) {
        printf("array[%d]: %f\n", (dim * requestedElement) + i, data[(dim * requestedElement) + i]);
    }
}

void printElement(double *data, int dim) {
    for (int i = 0; i < dim; i++) {
        printf("array[%d]: %f\n", i, data[i]);
    }
}

void printData(double *data, int totalElements, int dim) {
    for (int i = 0; i < totalElements; i++) {
        if(i % dim == 0) {
            printf("Element %d\n", i / dim);
        }
        printf("array[%d]: %f\n", i, data[i]);
    }
}

void printBoundry(double **cluster_bdry, int k, int dim) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < dim*2; j++) {
            printf("cluster_bdry[%d][%d]: %f\n", i, j, cluster_bdry[i][j]);
        }
    }
}

void printCentroid(double **cluster_centroid, int k, int dim) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < dim; j++) {
            printf("cluster_centroid[%d][%d]: %f\n", i, j, cluster_centroid[i][j]);
        }
    }
    
    /* Test Case
    double dataset[6] = { 1, 4, 2, 5, 3, 6 };
    
    printf("%d\n", (1 + 2 + 3) / 3);
    printf("%d\n", (4 + 5 + 6) / 3);
    
    centroid(dim, dataset, 3, cluster_centroid[0]);
    
    printCentroid(cluster_centroid, 3, dim);
     
     */
}

void printClusterSize(int *clusterSize, int k) {
    for (int i = 0; i < k; i++) {
        printf("cluster_size[%d]: %d\n", i, clusterSize[i]);
    }
}

void printClusterStart(int *clusterStart, int k) {
    for (int i = 0; i < k; i++) {
        printf("cluster_start[%d]: %d\n", i, clusterStart[i]);
    }
}

void printClusterAssign(int *clusterAssign, int elements) {
    for (int i = 0; i < elements; i++) {
        printf("cluster_assign[%d]: %d\n", i, clusterAssign[i]);
    }
}

void printClusterRadius(double *clusterRadius, int k) {
    for (int i = 0; i < k; i++) {
        printf("cluster_radius[%d]: %f\n", i, clusterRadius[i]);
    }
}

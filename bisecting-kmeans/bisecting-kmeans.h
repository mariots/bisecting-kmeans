//
//  bisecting-kmeans.h
//  bisecting-kmeans
//
//  Created by Mario Jimenez on 10/30/17.
//  Copyright © 2017 mariot. All rights reserved.
//

#ifndef bisecting_kmeans_h
#define bisecting_kmeans_h

#include <stdio.h>
#include "dataset.h"
#include "debug.h"

void bisecting_kmeans(int dim, int elements, int totalCoordinates, int clusters, double *data, int *cluster_size, int *cluster_start, double *cluster_radius, double **cluster_centroid, int *cluster_assign);

void get_cluster_subset(int dim, int totalCoordinates, int cluster, double* data, int* cluster_size, int* cluster_assign, double* newCluster);

void get_radius_for_cluster(int dim, int elements, int clusterIndex, double* data, double* cluster_radius, double** cluster_centroid, int* cluster_assign);

int nearest_neighbor_search(int dim, int elements, int totalCoordinates, int clusters, double* query, double* data, int* cluster_size, int* cluster_start, double* cluster_radius, double** cluster_centroid, int* cluster_assign);

#endif /* bisecting_kmeans_h */

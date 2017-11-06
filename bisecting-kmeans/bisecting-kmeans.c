//
//  bisecting-kmeans.c
//  bisecting-kmeans
//
//  Created by Mario Jimenez on 10/30/17.
//  Copyright © 2017 mariot. All rights reserved.
//

#include "bisecting-kmeans.h"

/****************************
 bi-secting kmeans algorithm
 
 1. Compute Centroid (just happens the first time)
 2. Choose left point of the given cluster
 3. Compute right point as furthest point from left point
 4. Divide points into each cluster, assign ech element to closest point
 5. Find centroid of each new cluster
 6. Computer sum of squares on each cluster
 7. For the cluster with the largest error rate from the sum of squares,
    choose that cluster and go to step 2.
 
 ****************************/

void bisecting_kmeans(int dim, int elements, int totalCoordinates, int clusters, double *data, int *cluster_size, int *cluster_start, double *cluster_radius, double **cluster_centroid, int *cluster_assign) {

    // 1. Compute Centroid
    centroid(dim, data, cluster_size[0], cluster_centroid[0]);
    printClusterSize(cluster_size, clusters);
    printCentroid(cluster_centroid, clusters, dim);
    printClusterAssign(cluster_assign, elements);

}

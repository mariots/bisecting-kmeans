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
 4. Divide points into each cluster, assign each element to closest point
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
    
    // Recursive loop:
    
    // Used for inital testing and setting cluster
    int chosenCluster = 0;
    int nextCluster = 1; // This will always be incremented in loop.
    
    // 2. Choose left point of the given cluster
    double *leftPoint = get_element_at_index(dim, chosenCluster, data);
    double *rightPoint;
    int furthestIndex = 0;
    double largestDistance = 0.0;
    
    printElement(leftPoint, dim);
    
    // 3. Compute right point as furthest point from left point
    // For every element in the cluster
    for (int element = 0; element < elements; element++) {
        
        // printf("cluster_assign[element]: %d\n", cluster_assign[element]);
        
        // If the element is in the cluster we are working on
        if(cluster_assign[element] == chosenCluster) {
            
            double *curElement = get_element_at_index(dim, element, data);
            
            // Get the distance between the current element and the leftPoint
            double tempDistance = distance(leftPoint, curElement, dim);
            
            // If the largest distance is less than the current elements distance, set current distance to largest
            // and update the furthestPoint
            if(largestDistance < tempDistance) {
                printf("largestDistance < tempDistance: %f < %f\n", largestDistance, tempDistance);
                largestDistance = tempDistance;
                furthestIndex = element;
                printf("furthestIndex: %d\n", furthestIndex);
            }
        }
    }
    
    rightPoint = get_element_at_index(dim, furthestIndex, data);
    printElement(rightPoint, dim);
    
    // 4. Divide points into each cluster, assign each element to closest point
    
    // For every element in the cluster
    for (int element = 0; element < elements; element++) {
        
        // If the element is in the cluster we are working on
        if(cluster_assign[element] == chosenCluster) {
            
            double *curElement = get_element_at_index(dim, element, data);
            
            // If the distance of the right point is less than the distance from the left point.
            // Set the element to be in the nextCluster and update the size and assign arrays.
            if(distance(rightPoint, curElement, dim) < distance(leftPoint, curElement, dim)) {
                cluster_assign[element] = nextCluster;
                cluster_size[chosenCluster] -= 1;
                cluster_size[nextCluster] += 1;
            }
        }
    }
    printClusterSize(cluster_size, clusters);
    printClusterAssign(cluster_assign, elements);
    
    
}

void bi_partition(int dim, int elements, int totalCoordinates, int clusters, double *data, int *cluster_size, int *cluster_start, double *cluster_radius, double **cluster_centroid, int *cluster_assign, int chosenCluster) {
    
}

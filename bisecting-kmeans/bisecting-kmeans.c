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
 6. Compute sum of squares on each cluster
 7. For the cluster with the largest error rate from the sum of squares,
    choose that cluster and go to step 2.
 
 ****************************/

void bisecting_kmeans(int dim, int elements, int totalCoordinates, int clusters, double* data, int* cluster_size, int* cluster_start, double* cluster_radius, double** cluster_centroid, int* cluster_assign) {

    // 1. Compute Centroid
    centroid(dim, data, cluster_size[0], cluster_centroid[0]);
    printData(data, totalCoordinates, dim);
    printClusterSize(cluster_size, clusters);
    printCentroid(cluster_centroid, clusters, dim);
    printClusterAssign(cluster_assign, elements);
    
    printf("\n\nAll setup\n\n");
    
    int largestErrorCluster = 0;
    
    // Step 7, loop over steps 2 - 6 until we have all our clusters.
    for (int curCluster = 0; curCluster < clusters - 1; curCluster++) {
        
        // Used for inital testing and setting cluster
        int chosenCluster = largestErrorCluster;
        int nextCluster = curCluster + 1; // This will always be incremented in loop.
        printf("\nchosenCluster: %d\n", chosenCluster);
        printf("nextCluster: %d\n\n", nextCluster);
        
        
        // 2. Choose left point of the given cluster
        double* leftPoint = get_element_at_index(dim, chosenCluster, data);
        double* rightPoint;
        int furthestIndex = 0;
        double largestDistance = 0.0;
        
        printf("Left Point: \n");
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
        printf("Right Point: \n");
        printElement(rightPoint, dim);
        
        // 4. Divide points into each cluster, assign each element to closest point
        
        // For every element in the cluster
        for (int element = 0; element < elements; element++) {
            
            // If the element is in the cluster we are working on
            if(cluster_assign[element] == chosenCluster) {
                
                double* curElement = get_element_at_index(dim, element, data);
                
                // If the distance of the right point is less than the distance from the left point.
                // Set the element to be in the nextCluster and update the size and assign arrays.
                if(distance(rightPoint, curElement, dim) < distance(leftPoint, curElement, dim)) {
                    cluster_assign[element] = nextCluster;
                    cluster_size[chosenCluster] -= 1;
                    cluster_size[nextCluster] += 1;
                }
            }
        }
        printf("\nStep 4: New clusters should be assigned.\n");
        printClusterSize(cluster_size, clusters);
        printClusterAssign(cluster_assign, elements);
        
        // 5. Find centroid of each new cluster
        
        double* chosenClusterData = (double *)calloc((cluster_size[chosenCluster] * dim), sizeof(double *));
        double* nextClusterData = (double *)calloc((cluster_size[nextCluster] * dim), sizeof(double *));
        
        get_cluster_subset(dim, totalCoordinates, chosenCluster, data, cluster_size, cluster_assign, chosenClusterData);
        get_cluster_subset(dim, totalCoordinates, nextCluster, data, cluster_size, cluster_assign, nextClusterData);
        
        centroid(dim, chosenClusterData, cluster_size[chosenCluster], cluster_centroid[chosenCluster]);
        centroid(dim, nextClusterData, cluster_size[nextCluster], cluster_centroid[nextCluster]);
        
        // 6. Compute sum of squares on each cluster
        printCentroid(cluster_centroid, clusters, dim);
        largestErrorCluster = sum_of_squares(dim, elements, clusters, data, cluster_size, cluster_assign, cluster_centroid);
        
    }
}

void get_cluster_subset(int dim, int totalCoordinates, int cluster, double* data, int* cluster_size, int* cluster_assign, double* newCluster) {
    
    double* element = (double *)calloc(dim, sizeof(double *));
    int nextIndex = 0;
    
    /*
     For every individual data point:
     Check to see if the element index belongs to the cluster
     if so
     get the element and set it to the next index in the chosenCluster data
     */
    for (int i = 0; i < totalCoordinates; i++) {
        // If the element is in the cluster we are working on
        if(cluster_assign[i] == cluster) {
            element = get_element_at_index(dim, i, data);
            set_element_at_index(dim, nextIndex, element, newCluster);
            nextIndex += 1;
        }
    }
}


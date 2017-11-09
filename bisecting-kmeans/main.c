//
//  main.c
//  bisecting-clustersmeans
//
//  Created by Mario Jimenez on 10/23/17.
//  Copyright © 2017 mariot. All rights reserved.
//

#include <stdio.h>
#include "dataset.h"
#include "bisecting-kmeans.h"
#include "debug.h"

#define dim             2           // Number of Dimensions
#define elements        10          // Number of Elements
#define clusters        4           // Number of Clusters

int main(int argc, const char * argv[]) {
    
    /*
         Setup Variables
     */
    
    int totalCoordinates = elements*dim;    // Total number of coordinates (x, y, z, ..., n)
    double data[elements * dim];            // Number of data points
    
    int cluster_size[clusters] = { elements };  // Size of each clusters cluster
    int cluster_start[clusters];                // Array start of each clusters cluster
    
    double** cluster_boundary;
    double** cluster_centroid;              // For each cluster, have a mean for each dimension
    double cluster_radius[clusters];
    int cluster_assign[elements];           // Assigns each element (note an element is elements*dim values) to a cluster, 0...clusters clusters
    
    // set clusters and cluster_start to 0
    for (int i = 0; i < clusters; i++) {
        cluster_start[i] = 0;
    }
    
    // set cluster_assign to all 0s
    for (int i = 0; i < elements; i++) {
        cluster_assign[i] = 0;
    }
    
    // init cluster_boundary
    cluster_boundary = (double **)calloc(clusters, sizeof(double *));
    
    for (int i = 0; i < clusters; i++) {
        cluster_boundary[i] = (double *)calloc(dim * 2, sizeof(double));
    }
    
    // init cluster_centroid
    cluster_centroid = (double **)calloc(clusters, sizeof(double *));
    
    for (int i = 0; i < clusters; i++) {
        cluster_centroid[i] = (double *)calloc(dim, sizeof(double));
    }
    
    /*
         Finished Setup
     */
    
    generate_elements(totalCoordinates, data);
    
    bisecting_kmeans(dim, elements, totalCoordinates, clusters, data, cluster_size, cluster_start, cluster_radius, cluster_centroid, cluster_assign);
    
    return 0;
}

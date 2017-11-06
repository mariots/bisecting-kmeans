//
//  dataset.c
//  bisecting-kmeans
//
//  Created by Mario Jimenez on 10/23/17.
//  Copyright © 2017 mariot. All rights reserved.
//

#include "dataset.h"

/*********************
  Base data structure
 *********************/

// Generates 'random' data for the dataset
void generate_elements(int totalCoordinates, double* dataset) {
    srand(1);
    
    for(int i = 0; i < totalCoordinates; i++)
    {
        dataset[i] = (double)(rand() % 100);
    }
}

// Returns element at specified index
double* get_element_at_index(int dim, int elementIndex, double* data) {
    return &data[dim*elementIndex]; // [dim * elementIndex]: will give the starting index of the element requested
}

// Sets an element to a index of a data array
void set_element_at_index(int dim, int dataIndex, double* element, double* data) {
    for (int i = 0; i < dim; i++) {
        data[(dim * dataIndex) + i] = element[i];
    }
}

// Returns an element from the cluster_centroid at specified index to the dataElement argument
void get_cluster_centroid_element(int dim, int cluster, double* dataElement, double** cluster_centroid) {
    for (int i = 0; i < dim; i++) {
        dataElement[i] = cluster_centroid[cluster][i];
    }
}

// Set a size dim data point to a specific cluster of the cluster_centroid
void set_cluster_centroid(int dim, int cluster, double* data, double** cluster_centroid) {
    for (int i = 0; i < dim; i++) {
        cluster_centroid[cluster][i] = data[i];
    }
}

/*********************
  Calculate functions
 *********************/

double distance(double* element1, double* element2, int dim) {
    // Euclidian Distance Formula: d(a,b) = sqrt( (a1-b1)^2 + (a2-b2)^2 + (a3-b3)^2 + (a4-b4)^2 )
    double distance = 0.0;
    
    for (int i = 0; i < dim; i++) {
        distance += ((element1[i] - element2[i]) * (element1[i] - element2[i]));
    }
    
    return sqrt(distance);
}

/*
 
 For a given dataset, find the centroid
 
 */
void centroid(int dim, double* dataset, int numElements, double* cluster_centroid) {
    
    double total;
    
    /* For each Dimension */
    for (int indexOfDimension = 0; indexOfDimension < dim; indexOfDimension++) {
        
        total = 0.0; // Rest Total
        
        /* For each element in the dataset */
        for (int element = 0; element < numElements; element++) {
            total += dataset[(dim * element) + indexOfDimension];
        }
        
        cluster_centroid[indexOfDimension] = total / (double) numElements;
    }
}


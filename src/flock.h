//
//  flock.h
//  EcoMesh
//
//  Created by Stefan Hendriks on 11/08/15.
//
//

#ifndef __EcoMesh__flock__
#define __EcoMesh__flock__

#include <stdio.h>
#include "ofMain.h"
#include <vector>

class Flock
{
public:
    Flock(ofVec2f location);
    
    void move();
    void draw();
    
    void swim(int force);
    
private:
    ofVec2f location;
    
    ofMesh my1Mesh;
    
    int angles;
    
    float *noiseXOff;
    float *noiseYOff;
    
    ofVec3f *my1MeshPnts;
//    ofVec3f *my1MeshPntsI;
    
    int swimming;
    int swimFreq;
    int swimCounter;
    
    float swimSize;
    
    bool constMode = false;
};


#endif /* defined(__EcoMesh__flock__) */

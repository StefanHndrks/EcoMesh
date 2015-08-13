//
//  flock.cpp
//  EcoMesh
//
//  Created by Stefan Hendriks on 11/08/15.
//
//

#include "flock.h"

Flock::Flock(ofVec2f location)
{
    /*value initialization*/
    this->location = location;
    
    int size = ofRandom(4, 15);
    
    swimFreq = 25;
    swimCounter = 31;
    swimSize = 0;
    swimming = 0;
    
    if (ofRandom(1) < 0.2) {
        constMode = true;
    } // if
    
    /*Mesh initialization*/ {
        my1Mesh.setMode(OF_PRIMITIVE_LINES);
        my1Mesh.enableColors();
    
        angles = 5;
        if (size > 9) {
            angles = int(ofRandom(2, 4)) * 2 + 1;
        } // if
    
        my1MeshPnts = new ofVec3f[angles * 2];

        ofVec3f my1MeshPntO(size, 0, 0);
    
        float rotate = ofRandom(360);
        my1MeshPntO.rotate(0, 0, rotate);
    
        noiseXOff = new float[angles * 2];
        noiseYOff = new float[angles * 2];
    
        for (int i = 0; i < angles; i++) {
            my1MeshPnts[i] = my1MeshPntO.getRotated(0, 0, ((360 / angles) * i) + ofRandom(-5, 5));
            my1Mesh.addVertex(my1MeshPnts[i]);
        
            my1Mesh.addIndex(i);
            my1Mesh.addIndex((i + 1) % angles);
        
            noiseXOff[i] = ofRandom(1000);
            noiseYOff[i] = ofRandom(1000);
        } // for
        if (size > 9) {
            ofVec3f my1MeshPntI(size / 2, 0, 0);
            my1MeshPntI.rotate(0, 0, rotate + ofRandom(-10, 10));
        
            for (int i = 0; i < angles; i++) {
                my1MeshPnts[i + angles] = my1MeshPntI.getRotated(0, 0, ((360 / angles) * i) + ofRandom(-5, 5));
                my1Mesh.addVertex(my1MeshPnts[i + angles]);
            
                my1Mesh.addIndex(i + angles);
                my1Mesh.addIndex(((i + 1) % angles) + angles);
            
                my1Mesh.addIndex(i);
                my1Mesh.addIndex(i + angles);
            
                noiseXOff[i + angles] = ofRandom(1000);
                noiseYOff[i + angles] = ofRandom(1000);
            } // for
        } // if
    } // Mesh initialization
}

void Flock::swim(int force) {
    if (swimCounter > swimFreq && force > 0) {
        
        swimCounter = 0;
        swimming = 5;
    } // if
    if (swimming > 0) {
        
        swimming--;
        
        swimSize = ((swimSize - 1) * 0.6) + 1;
    }
} // swim()

void Flock::move() {
    int tempForce = 0;
    if (ofRandom(1) < 0.01 || constMode) {
        tempForce = 5;
    } // if
    swim(tempForce);
    
    swimCounter++;
    swimSize = swimSize * 0.94;
    
    cout << swimming << endl;
    cout << swimSize << endl;
    float oSwimSize = (swimSize * 0.4) + 1;
    float iSwimSize = (swimSize * -0.2) + 1;
    
    cout << oSwimSize << endl << endl;
    
    for (int i = 0; i < my1Mesh.getNumVertices(); i++) {
        ofVec2f noise(ofNoise(noiseXOff[i]), ofNoise(noiseYOff[i]));
        noise = (noise * 4) - 2;
        
        if (i < angles) {
            my1Mesh.setVertex(i, (my1MeshPnts[i] * oSwimSize) + noise);
        } else {
            my1Mesh.setVertex(i, (my1MeshPnts[i] * iSwimSize) + noise);
        } // if
        
        noiseXOff[i] += 0.01;
        noiseYOff[i] += 0.01;
    } // for
}

void Flock::draw() {
    ofPushMatrix();
        ofTranslate(location);
    
        my1Mesh.draw();
    ofPopMatrix();
}
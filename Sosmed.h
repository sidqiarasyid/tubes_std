#ifndef SOSMED_H_INCLUDED
#define SOSMED_H_INCLUDED
#include <iostream>
#define idVertex(v) v->idVertex
#define nextVertex(v) v->nextVertex
#define firstEdge(v) v->firstEdge
#define firstVertex(G) G.firstVertex


using namespace std;

typedef struct userNode *adrUser;
typedef struct edge *adrEdge;

struct userNode{
    string userId;
    string username;
    int userAge;
    adrUser nextUser;
    adrEdge firstEdge;
};

struct edge {
    string edgeId;
    adrEdge nextEdge;
};

struct graph{
    adrUser firstNode;
};

void createUser(string id, adrUser adress);
void createGraph(graph G);
void addUsertoGraph(graph G, string id);
void showGraph(graph G);
//deleteUser
//addFriend
//deleteFriend




#endif // SOSMED_H_INCLUDED

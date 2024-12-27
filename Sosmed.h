#ifndef SOSMED_H_INCLUDED
#define SOSMED_H_INCLUDED
#include <iostream>
#define info(p) p->info
#define nextNode(p) p->nextNode
#define nextEdge(p) p->nextEdge
#define firstEdge(p) p->firstEdge
#define firstNode(G) G.firstNode
#define firstCommunity(G) G.firstCommunity

using namespace std;

typedef struct userNode *adrNode;
typedef struct edge *adrEdge;
typedef struct community *adrCommunity;

struct infoUser{
    string userId;
    string username;
    int userAge;
};

struct userNode{
    infoUser info;
    adrNode nextNode;
    adrEdge firstEdge;
};

struct edge {
    infoUser info;
    adrEdge nextEdge;
};

struct community {
    string communityId;
    string communityName;
    adrNode firstUser;
    adrCommunity nextCommunity;
};

struct graph{
    adrNode firstNode;
    adrCommunity firstCommunity;
};

adrNode createUser(infoUser info);
void createGraph(graph &G);
void addUsertoGraph(graph &G, adrNode newNode);
void printUser(graph G);
adrEdge createEdge(infoUser info);
void addEdgetoNode(graph &G, adrNode p, adrEdge e);
void addFriend(graph &G, string user1, string user2);
void printUserFriend(string username, graph G);
adrNode findUser(string username, graph G);
void deleteUser(graph &G, string username);
void deleteFriend(graph &G, string user1, string user2);
void addCommunity(graph &G, string communityName);
void deleteCommunity(graph &G, string communityId);
void deleteUserFromCommunity(graph &G, string username, string communityId);
void printUserInCommunity(string communityName, graph G);
void addUserToCommunity(graph &G, string username, string communityName);
adrCommunity findCommunity(string communityName, graph G);
#endif // SOSMED_H_INCLUDED

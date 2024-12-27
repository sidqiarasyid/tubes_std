#include <iostream>
#include "Sosmed.h"
using namespace std;

void createGraph(graph &G) {
    firstNode(G) = NULL;
    firstCommunity(G) = NULL;
}

adrNode createUser(infoUser info) {
    adrNode p = new userNode;
    info(p) = info;
    firstEdge(p) = NULL;
    nextNode(p) = NULL;
    return p;
}

adrEdge createEdge(infoUser info) {
    adrEdge p = new edge;
    info(p) = info;
    nextEdge(p) = NULL;
    return p;
}

void addUsertoGraph(graph &G, adrNode newNode) {
    if (firstNode(G) == NULL) {
        firstNode(G) = newNode;
    } else {
        adrNode loopNode = firstNode(G);
        while (nextNode(loopNode) != NULL) {
            loopNode = nextNode(loopNode);
        }
        nextNode(loopNode) = newNode;
    }
}

void addEdgetoNode(graph &G, adrNode p, adrEdge e) {
    if (firstEdge(p) == NULL) {
        firstEdge(p) = e;
    } else {
        adrEdge c = firstEdge(p);
        while (nextEdge(c) != NULL) {
            c = nextEdge(c);
        }
        nextEdge(c) = e;
    }
}

void addFriend(graph &G, string user1, string user2) {
    adrNode u1 = findUser(user1, G);
    adrNode u2 = findUser(user2, G);
    if (u1 != NULL && u2 != NULL) {
        adrEdge e1 = createEdge(info(u2));
        adrEdge e2 = createEdge(info(u1));
        addEdgetoNode(G, u1, e1);
        addEdgetoNode(G, u2, e2);
        cout << info(u1).username + " berteman dengan " + info(u2).username + "!" << endl;
    } else {
        cout << "User tidak ditemukan" << endl;
    }
}

void printUserFriend(string username, graph G) {
    adrNode p = findUser(username, G);
    if (p != NULL) {
        adrEdge n = firstEdge(p);
        cout << "Friendlist dari user " << username << ":\n";
        while (n != NULL) {
            cout << "- " + info(n).username << endl;
            n = nextEdge(n);
        }
    } else {
        cout << "User tidak ditemukan" << endl;
    }
}

adrNode findUser(string username, graph G) {
    adrNode p = firstNode(G);
    while (p != NULL) {
        if (info(p).username == username) {
            return p;
        }
        p = nextNode(p);
    }
    return NULL;
}

void printUser(graph G) {
    adrNode p = firstNode(G);
    if (p != NULL) {
        while (p != NULL) {
            cout << "ID: " << info(p).userId << endl;
            cout << "Nama: " << info(p).username << endl;
            cout << "Umur: " << info(p).userAge << endl;
            cout << endl;
            p = nextNode(p);
        }
    } else {
        cout << "Graph Kosong" << endl;
    }
}

void deleteFriend(graph &G, string user1, string user2) {
    adrNode userNode1 = findUser(user1, G);
    adrNode userNode2 = findUser(user2, G);

    if (userNode1 == nullptr || userNode2 == nullptr) {
        cout << "User tidak ditemukan" << endl;
        return;
    }

    adrEdge prevEdge = nullptr;
    adrEdge currEdge = firstEdge(userNode1);
    while (currEdge != nullptr && currEdge->info.username != user2) {
        prevEdge = currEdge;
        currEdge = nextEdge(currEdge);
    }
    if (currEdge != nullptr) {
        if (prevEdge == nullptr) {
            firstEdge(userNode1) = nextEdge(currEdge);
        } else {
            nextEdge(prevEdge) = nextEdge(currEdge);
        }
        delete currEdge;
    }

    prevEdge = nullptr;
    currEdge = firstEdge(userNode2);
    while (currEdge != nullptr && currEdge->info.username != user1) {
        prevEdge = currEdge;
        currEdge = nextEdge(currEdge);
    }
    if (currEdge != nullptr) {
        if (prevEdge == nullptr) {
            firstEdge(userNode2) = nextEdge(currEdge);
        } else {
            nextEdge(prevEdge) = nextEdge(currEdge);
        }
        delete currEdge;
    }

    cout << "Pertemanan antara " << user1 << " dan " << user2 << " telah dihapus" << endl;
}

void deleteUser(graph &G, string username) {
    adrNode prevNode = nullptr;
    adrNode currNode = firstNode(G);

    while (currNode != nullptr && currNode->info.username != username) {
        prevNode = currNode;
        currNode = nextNode(currNode);
    }

    if (currNode == nullptr) {
        cout << "User " << username << " tidak ditemukan" << endl;
        return;
    }

    while (firstEdge(currNode) != nullptr) {
        deleteFriend(G, currNode->info.username, firstEdge(currNode)->info.username);
    }

    if (prevNode == nullptr) {
        firstNode(G) = nextNode(currNode);
    } else {
        nextNode(prevNode) = nextNode(currNode);
    }

    delete currNode;
    cout << "User " << username << " telah dihapus" << endl;
}

void addCommunity(graph &G, string communityName) {
    adrCommunity newCommunity = new community;
    newCommunity->communityName = communityName;
    newCommunity->firstUser = NULL;
    newCommunity->nextCommunity = NULL;

    if (firstCommunity(G) == NULL) {
        firstCommunity(G) = newCommunity;
    } else {
        adrCommunity current = firstCommunity(G);
        while (current->nextCommunity != NULL) {
            current = current->nextCommunity;
        }
        current->nextCommunity = newCommunity;
    }
    cout << "Komunitas " << communityName << " telah dibuat." << endl;
}

void addUserToCommunity(graph &G, string username, string communityName) {
    adrNode userNode = findUser(username, G);
    adrCommunity communityNode = findCommunity(communityName, G);

    if (userNode != NULL && communityNode != NULL) {
        adrNode newMember = createUser(info(userNode)); // Membuat salinan userNode
        if (communityNode->firstUser == NULL) {
            communityNode->firstUser = newMember;
        } else {
            adrNode current = communityNode->firstUser;
            while (nextNode(current) != NULL) {
                current = nextNode(current);
            }
            nextNode(current) = newMember;
        }
        cout << "User " << username << " telah ditambahkan ke komunitas " << communityName << "." << endl;
    } else {
        cout << "User atau komunitas tidak ditemukan." << endl;
    }
}

void deleteUserFromCommunity(graph &G, string username, string communityName) {
    adrCommunity communityNode = findCommunity(communityName, G);
    if (communityNode != NULL) {
        adrNode prevNode = NULL;
        adrNode currNode = communityNode->firstUser;
        while (currNode != NULL && info(currNode).username != username) {
            prevNode = currNode;
            currNode = nextNode(currNode);
        }
        if (currNode != NULL) {
            if (prevNode == NULL) {
                communityNode->firstUser = nextNode(currNode);
            } else {
                nextNode(prevNode) = nextNode(currNode);
            }
            delete currNode;
            cout << "User " << username << " telah dihapus dari komunitas " << communityName << "." << endl;
        } else {
            cout << "User tidak ditemukan dalam komunitas." << endl;
        }
    } else {
        cout << "Komunitas tidak ditemukan." << endl;
    }
}

void printUserInCommunity(string communityName, graph G) {
    adrCommunity communityNode = findCommunity(communityName, G);
    if (communityNode != NULL) {
        adrNode current = communityNode->firstUser;
        if (current == NULL) {
            cout << "Komunitas " << communityName << " tidak memiliki anggota." << endl;
        } else {
            cout << "Anggota komunitas " << communityName << ":\n";
            while (current != NULL) {
                cout << "- " << info(current).username << endl;
                current = nextNode(current);
            }
        }
    } else {
        cout << "Komunitas tidak ditemukan." << endl;
    }
}

adrCommunity findCommunity(string communityName, graph G) {
    adrCommunity current = firstCommunity(G);
    while (current != NULL) {
        if (current->communityName == communityName) {
            return current;
        }
        current = current->nextCommunity;
    }
    return NULL;
}

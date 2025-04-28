// #include <stdio.h>
// #include <stdlib.h>
// #define MAXSIZE_OF_VEX 100
// #define INFINITY 65535
// #define TRUE 1
// #define FALSE 0
// typedef char VertexType;
// typedef int EdgeType;
// //邻接矩阵
// typedef struct {
// 	VertexType vexs[MAXSIZE_OF_VEX];
// 	EdgeType arc[MAXSIZE_OF_VEX][MAXSIZE_OF_VEX];
// 	int numVertexes, numEdges;
// }MGraph;

// //无向图 边上有权值的
// void CreateMGraph(MGraph *G) {
// 	printf("输出顶点数和边数：\n");
// 	scanf("%d,%d", &G->numVertexes, &G->numEdges);
// 	for (int i = 0; i < G->numVertexes; i++) {
// 		scanf(&G->vexs[i]);
// 	}
// 	for (int i = 0; i < G->numVertexes; i++) {
// 		for (int j = 0; j < G->numVertexes; j++) {
// 			G->arc[i][j] = INFINITY;
// 		}
// 	}
	
// 	for (int i, j, w, k = 0; k < G->numEdges; k++) {
// 		printf("输入边（vi,vj）上的下标i,下标j和权w:\n");
// 		scanf("%d %d %d", &i, &j, &w);
// 		G->arc[i][j] = w;
// 		G->arc[i][j] = G->arc[j][i];
// 	}
// }

// //邻接表
// typedef struct EdgeNode {
// 	int adjvex;
// 	EdgeType weight;
// 	struct EdgeNode* next;
// }EdgeNode;
// typedef struct VertexNode {
// 	VertexType data;
// 	EdgeNode* firstedge;
// }VertexNode,AdjList[MAXSIZE_OF_VEX];
// typedef struct {
// 	AdjList adjList;
// 	int numVertexes, numEdges;
// }GraphAdjList;

// void CreateALGraph(GraphAdjList* G) {
// 	printf("输入顶点数和边数：\n");
// 	scanf("%d,%d", &G->numVertexes, &G->numEdges);
// 	for (int i = 0; i < G->numVertexes; i++) {
// 		scanf("%d", &G->adjList[i].data);
// 		G->adjList[i].firstedge = NULL;
// 	}
// 	EdgeNode* e;
// 	for (int i, j, k = 0; k < G->numEdges; k++) {
// 		printf("输入边(vi,vj)上的顶点序号：\n");
// 		scanf("%d,%d", &i, &j);
// 		e = (EdgeNode*)malloc(sizeof(EdgeNode));
// 		e->adjvex = j;
// 		e->next = G->adjList[i].firstedge;
// 		G->adjList[i].firstedge = e;
// 		e = (EdgeNode*)malloc(sizeof(EdgeNode));
// 		e->adjvex = i;
// 		e->next = G->adjList[j].firstedge;
// 		G->adjList[j].firstedge = e;
// 	}
// }

// typedef int Boolean;
// Boolean visited[MAXSIZE_OF_VEX];
// void DFS(MGraph G, int i) {
// 	visited[i] = TRUE;
// 	printf("%c", G.vexs[i]);
// 	for (int j = 0; j < G.numVertexes; j++) {
// 		if (G.arc[i][j] != INFINITY && !visited[j])
// 			DFS(G, j);
// 	}
// }
// void DFSTraverse(MGraph G) {
// 	for (int i = 0; i < G.numVertexes; i++) {
// 		visited[i] = FALSE;
// 	}
// 	for (int i = 0; i < G.numVertexes; i++) {
// 		if (!visited[i])
// 			DFS(G, i);
// 	}
// }

// void DFS(GraphAdjList GL, int i) {
// 	EdgeNode* p;
// 	visited[i] = TRUE;
// 	printf("%c", GL.adjList->data);
// 	p = GL.adjList->firstedge;
// 	while (p) {
// 		if (!visited[p->adjvex])
// 			DFS(GL, p->adjvex);
// 		p = p->next;
// 	}
// }
// void DFSTraverse(GraphAdjList GL) {
// 	for (int i = 0; i < GL.numVertexes; i++) {
// 		visited[i] = FALSE;
// 	}
// 	for (int i = 0; i < GL.numVertexes; i++) {
// 		if (!visited[i])
// 			DFS(GL, i);
// 	}
// }


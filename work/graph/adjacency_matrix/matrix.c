#include <stdio.h>

#define MAX_VERTEX	15

typedef struct{
	
	int nvertex;
	int matrix[MAX_VERTEX][MAX_VERTEX];
}GrapeType;

void init_graph(GrapeType* graph)
{
	for (int ii = 0; ii < MAX_VERTEX; ii++)
	{
		for (int jj = 0; jj < MAX_VERTEX; jj++)
		{
			graph->matrix[ii][jj] = 0;
		}
	}
}

void insert_vertex(GrapeType *graph)
{
	graph->nvertex++;
}

void insert_edge(int start, int end, GrapeType* graph)
{
	graph->matrix[start-1][end-1] = 1;
}

void print_graph(GrapeType* graph)
{
	for (int ii = 0; ii < MAX_VERTEX; ii++)
	{
		for (int jj = 0; jj < MAX_VERTEX; jj++)
		{
			printf("%d ", graph->matrix[ii][jj]);
		}
		printf("\n");
	}
}

int main()
{
	GrapeType graph;
	graph.nvertex = 0;
	int flag = 0, start = 0, end = 0;


	init_graph(&graph);

	while (1)
	{
		printf("1.insert_vertex 2.insert_edge 3.print_graph 4.exit\n");
		scanf("%d", &flag);

		switch (flag)
		{
		case 1:
			insert_vertex(&graph);
			printf("current num_vertex: %d\n", graph.nvertex);
			break;
		case 2:
			printf("start, end:");
			scanf("%d %d", &start, &end);
			insert_edge(start, end, &graph);
			break;
		case 3:
			print_graph(&graph);
			break;
		case 4: return 0;
		}
	}
	return 0;
}

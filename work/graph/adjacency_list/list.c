#include <stdio.h>
#include <stdlib.h>

typedef struct linked_vertex {
	
	int vertex;
	struct linked_vertex* link;
}Linked_vertex;

typedef struct graphtype{

	int nvertex;
	struct graphtype* next_vertex; //vertex 연결 리스트
	
	Linked_vertex* linked_vertex; //인접리스트
}GraphType;

void insert_vertex(GraphType *graphtype)
{
	GraphType* tmp = graphtype;

	while (1)
	{
		if (tmp->next_vertex == NULL) break;
		else tmp = tmp->next_vertex;
		
		
	}

	graphtype->nvertex++;

	tmp->next_vertex = (GraphType *)malloc(sizeof(GraphType));
	tmp->next_vertex->next_vertex = NULL;
	tmp->next_vertex->linked_vertex = NULL;

	printf("nvertex: %d\n", graphtype->nvertex);
}

void insert_edge(int start, int end, GraphType* graphtype)
{
	GraphType* tmp = graphtype;

	for (int ii = 1; ii < start; ii++)
	{
		tmp = tmp->next_vertex;
	}

	Linked_vertex* link = tmp->linked_vertex;

	if (link != NULL) {
	
		while (1)
		{
			if (link->link == NULL) break;
			else link = link->link;
		}


		link->link = (Linked_vertex*)malloc(sizeof(Linked_vertex));
		link->link->vertex = end;
		link->link->link = NULL;
	}

	else if (link == NULL) {
		tmp->linked_vertex = (Linked_vertex*)malloc(sizeof(Linked_vertex));
		tmp->linked_vertex->vertex = end;
		tmp->linked_vertex->link = NULL;
	}
}

void print_graph(GraphType* graphtype)
{
	GraphType* tmp = graphtype;
	Linked_vertex* link = NULL;

	for (int ii = 0; ii < graphtype->nvertex; ii++)
	{
		printf("--[%d]vertex link status--\n", ii+1);
		link = tmp->linked_vertex;
		
		if (link == NULL)
		{
			printf("no link\n");
			continue;
		}

		while(link != NULL)
		{
			printf("data: %d ", link->vertex);
			link = link->link;
		}

		tmp = tmp->next_vertex;
		printf("\n");
	}
}

int main()
{
	int flag = 0, start = 0, end = 0;
	GraphType graphtype;
	graphtype.nvertex = 0;
	graphtype.next_vertex = NULL;
	graphtype.linked_vertex = NULL;

	while (1)
	{
		printf("\n<1. insert_vertex 2.insert_edge 3.print_graph 4.exit>\n");
		scanf("%d", &flag);

		switch (flag)
		{
		case 1:
			insert_vertex(&graphtype);
			break;
		case 2:
			printf("start, end: ");
			scanf("%d %d", &start, &end);
			insert_edge(start, end, &graphtype);
			break;
		case 3:
			print_graph(&graphtype);
			break;
		case 4:
			return 0;
		}

	}

	return 0;
}

#include<iostream>
#include<fstream>

const size_t size = 9;

struct Edge
{
    int start;
    int finish;
    int weight;
};

int cmp(const void* weight1, const void* weight2)
{
    Edge* edge1 = (Edge*)weight1, *edge2 = (Edge*)weight2;
    return edge1->weight - edge2->weight;
}
void kruskal(Edge* array, int* node, int index)
{
    int cost = 0;
    for (size_t i = 0; i < index; i++)
    {
        if (node[array[i].start] > 1 && node[array[i].finish > 1])
        {
            cost += array[i].weight;
            std::cout << "(" << array[i].start << " - " << array[i].finish << ")" << std::endl;
            node[array[i].start]--;
            node[array[i].finish]--;
        }
    }
    std::cout << "\nCost: " << cost << std::endl;
}


int main()
{
    int* node = new int[size];
    Edge* array = new Edge[size * size];
    std::ifstream fin("text.txt");
    int value, index = 0;

    for (size_t i = 0; i < size; i++)
    {
        int count = 0;

        for (size_t j = 0; j < size; j++)
        {
            fin >> value;

            if (value != 0)
            {
                node[i] = ++count;// count number of connections for the top
                if (j > i)
                {
                    array[index].weight = value;
                    array[index].start = i;
                    array[index].finish = j;
                    index++;
                }
            }
        }
    }
    qsort(array, index, sizeof(Edge), cmp);
    kruskal(array, node, index);
    
    /*for (size_t i = 0; i < index; i++)
        std::cout << "(" << array[i].start << ", " << array[i].finish << " - " << array[i].weight << ") ";

    std::cout << std::endl;*/

    int  graph[size][size] = 
    {
      {0,10,25,25,10},
      {1,0,10,15,2},
      {8,9,0,20,10},
      {14,10,24,0,15},
      {10,8,25,27,0}
    };

	return 0;
}
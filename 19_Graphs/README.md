# Graphs

it is datastructer made up of nodes and edges

- nodes - to store data
- edges - to connect nodes

## Types of graphs

- directed graphs (unidirection edges between nodes)
- undirected graphs (bidirectional edges between nodes)
- weighted graph (when there is number on given on edges) it can be directed or undirected normally directed/undirected graph edges weight is 1

## Degree of node

number of edges connected to node is called degree.

## In degree

in directed graph number of incoming edges to a node is in degree

## out degree

in a directed graph number of outgoing edges to a node is out degree

## path 

graph traversal such that all nodes are covered and non of the nodes are visited twice.

## cyclic graph 

it contains a closed path/circle (where started from can be reached again)

undirected graph are always cyclic

## Acyclic graph

there is no cicle in graph. (cannot reach start when traversing again)

## Graph implementation

- using adjancency matrix (using 2D array)
- using adjancency list (using map/list/vector)

### Adjancency matrix

n - number of nodes
- create a 2D matrix of n x n
- fill data with 1 (for edge),  0 for (no edge)
- fill 1 if row index has edge with column index node
-example 4 nodes of undirect grap
0 1 1 0
1 0 1 0
1 1 0 0
0 0 0 0 

### Adjancency list

n - number of nodes
- create n list
- this index of n will represent the node from where you can visit other nodes
- example of directed graph
0 - {1,2}
1 - {3,2}
2 - {3}
3 - {}

### weighed adjancency list

- here in list will be storing to node and its weight also
- example of directed graph
0 - {{1,5},{2,7}}
1 - {{3,2},{2,3}}
2 - {{3,8}}
3 - {}

## Graph Structure

```cpp

```
import networkx as nx
import matplotlib.pyplot as plt
import numpy as np

G = nx.Graph()

matrix = np.array(
    [
        [0, 0, 3, 0],
        [0, 0, 1, 1],
        [3, 1, 0, 1],
        [0, 1, 1, 0]
    ]
)
for i in range(len(matrix)):
    for j in range(len(matrix[0])):
        if matrix[i, j]:
            G.add_edge(i, j, weight=matrix[i][j])

pos = nx.spring_layout(G)
nx.draw(G, pos, with_labels=True)
nx.draw_networkx_edge_labels(G, pos, edge_labels=nx.get_edge_attributes(G, "weight"))
plt.show()
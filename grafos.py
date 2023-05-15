#grafos, bfs, caminho_vertice, dfs

import queue
from collections import deque

BRANCO = 1
CINZA = 2
PRETO = 3

class Grafo:
  def __init__(self, numero_vertices):
    self.vertices = numero_vertices #Isso é um inteiro
    self.matriz = [[0 for _ in range(numero_vertices)] for _ in range(numero_vertices)]
    self.lista = [[] for _ in range(numero_vertices)]
    self.vetor_pai = [None for _ in range(numero_vertices)]
    self.vetor_distancias = [float("inf") for _ in range(numero_vertices)]
    self.vetor_cor = [BRANCO for _ in range(self.vertices)]


  def BFS(self, vertice_inicial):
    self.vetor_cor[vertice_inicial] = CINZA
    self.vetor_distancias[vertice_inicial] = 0
    fila = queue.Queue()
    fila.put(vertice_inicial)

    while fila.empty() == False:
      vertice_analisado = fila.get()

      for vizinhos in self.lista[vertice_analisado]:
        if self.vetor_cor[vizinhos] == BRANCO:
          self.vetor_cor[vizinhos] = CINZA
          self.vetor_distancias[vizinhos] = self.vetor_distancias[vertice_analisado] + 1
          self.vetor_pai[vizinhos] = vertice_analisado
          fila.put(vizinhos)
    
      self.vetor_cor[vertice_analisado] = PRETO
    


  def caminho_vertice(self, origem, destino):
    self.BFS(origem)
    count = self.vetor_distancias[destino]
    if count == 0 or count == float("inf"):
      print("Não há caminho entre os vértices.")
    else:
      pilha = deque()
      pilha.append(destino)
      caminho_vertices = self.vetor_pai[destino]

      while(count != 0):
        pilha.append(caminho_vertices)
        caminho_vertices = self.vetor_pai[caminho_vertices] #encontrando o pai do pai do vértice destino.
        count -= 1

      caminho = []
      for i in range(self.vetor_distancias[destino] + 1):
        caminho.append(pilha.pop())
      
      print(caminho)



  def DFS(self):
    for i in range(self.vertices):
      if(self.vetor_cor[i] == BRANCO):
        self.dfs_visit(i)



  def dfs_visit(self, v_inicial):
    pilha = deque()
    pilha.append(v_inicial)
    self.vetor_cor[v_inicial] = CINZA

    while pilha:
      v_atual = pilha[-1]
      vizinho_ainda_nao_visitado = False

      for vizinhos in self.lista[v_atual]:
        if(self.vetor_cor[vizinhos] == BRANCO):
          self.vetor_cor[vizinhos] = CINZA
          self.vetor_pai[vizinhos] = v_atual
          vizinho_ainda_nao_visitado = True
          pilha.append(vizinhos)
          break
      
      if not vizinho_ainda_nao_visitado:
        pilha.pop()
        self.vetor_cor[v_atual] = PRETO




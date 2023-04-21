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

  def print_info(self):
    print("Matriz de Adjacencia:")
    for i in range(self.vertices):
        print(self.matriz[i])
    print()
    print("Lista de Adjacencia:")
    print(self.lista)
    print()
    print("Vetor distancia:")
    print(self.vetor_distancias)
    print()
    print("Vetor pai:")
    print(self.vetor_pai)
    print()

  def BFS(self, vertice_inicial):
    vetor_cor = [BRANCO for _ in range(self.vertices)] #Vetor de cores iniciado com tudo branco
    vetor_cor[vertice_inicial] = CINZA
    self.vetor_distancias[vertice_inicial] = 0 #Distância do vértice inicial para ele mesmo = 0
    fila = queue.Queue()
    fila.put(vertice_inicial)
    while fila.empty() == False:
        vertice_original = fila.get()
        for elem in self.lista[vertice_original]:
            if vetor_cor[elem] == BRANCO:
                vetor_cor[elem] = CINZA
                self.vetor_distancias[elem] = self.vetor_distancias[vertice_original] + 1
                self.vetor_pai[elem] = vertice_original #Vértice original é um inteiro
                fila.put(elem)
        vetor_cor[vertice_original] = PRETO

  def caminho_vertices(self, vertice_inicial, vertice_final):
     self.BFS(vertice_inicial)
     count = self.vetor_distancias[vertice_final] #Número de iterações do while, de acordo com a distância entre os vértices
     if(count == 0 or count == float("inf")):
        print("Não há caminho entre os vértices.")
     else:
        vertices_percorridos = self.vetor_pai[vertice_final] #inteiro que representa os vértices do caminho
        pilha_caminho = deque() #Pilha
        pilha_caminho.append(vertice_final) #Pilha com os vértices que formam o caminho
        while(count != 0):
           pilha_caminho.append(vertices_percorridos)
           vertices_percorridos = self.vetor_pai[vertices_percorridos] #Obtendo o pai de cada um dos vértices do caminho
           count -=1
        caminho = []
        for i in range(self.vetor_distancias[vertice_final] + 1):
           caminho.append(pilha_caminho.pop())
        print(f"Caminho do vértice {vertice_inicial} ao vértice {vertice_final}:", caminho)
           
           

     
     


        
      

    
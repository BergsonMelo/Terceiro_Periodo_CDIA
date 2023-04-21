from grafo import Grafo

def ler_arquivo(nome_arquivo):
    f = open(nome_arquivo, 'r')
    num_linhas = int(f.readline())
    g = Grafo(num_linhas)
    
    i = 0
    for linhas in f:
        numeros = linhas.split('\t') #Isso é uma lista
        j = 0
        for k in range(g.vertices):
            valor_aresta = int(numeros[k])
            if valor_aresta > 0:
                g.matriz[i][j] = valor_aresta
                g.lista[i].append(j)
            
            j += 1
        i += 1   
    
    return g

grafo = ler_arquivo("pcv10.txt")
grafo.BFS(2)
grafo.print_info()
grafo.caminho_vertices(9, 6)
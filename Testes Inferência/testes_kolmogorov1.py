import numpy as np
import random

def amostra_normal():
    # Especifique as médias e desvios padrão para cada amostra
    medias = [10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100, 105]
    desvios_padrao = [2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21]
    tamanho_da_amostra = [random.randint(10, 40) for _ in range(20)]
    amostras_normais = []

    # Gere 20 amostras de tamanhos diferentes com médias e desvios padrão diferentes
    for tamanho_amostra, media, desvio in zip(tamanho_da_amostra, medias, desvios_padrao):
        amostra = np.random.normal(loc=media, scale=desvio, size=tamanho_amostra)
        amostras_normais.append(amostra)
        

    return amostras_normais

def amostra_gamma():
    parametros = [(2, 1.5), (2, 1), (2, 2), (1, 1.5), (1.5, 1.5), (3, 2), (3, 1), (1, 1), 
                  (2, 3), (4, 2)]
    tamanhos_amostra = [random.randint(15, 40) for _ in range(10)]
    amostras_gamma = []

    for (a, b), tamanho in zip(parametros, tamanhos_amostra):
        amostra = np.random.gamma(shape=a, scale=b, size=tamanho)
        amostras_gamma.append(amostra)
    
    return amostras_gamma

def amostra_quiquadrada():
    graus_de_liberdade = [random.randint(1, 5) for _ in range(10)]
    tamanhos_amostra = [random.randint(15, 40) for _ in range(10)]
    amostras_quiquad = []

    for grau, tamanho in zip(graus_de_liberdade, tamanhos_amostra):
        amostra = np.random.chisquare(df=grau, size=tamanho)
        amostras_quiquad.append(amostra)

    return amostras_quiquad

def amostras_poisson_kolmogorov():
    # Tamanhos de amostra variáveis
    tamanhos_amostra = [random.randint(20, 35) for _ in range(10)]

    # Taxas de ocorrência (lambdas) para cada amostra
    taxas = [3, 4, 3, 1, 5, 6, 2, 3, 4, 1]

    # Lista para armazenar as amostras
    amostras_poisson = []

    # Gere 10 amostras de Poisson com tamanhos de amostra variáveis
    for tamanho, taxa in zip(tamanhos_amostra, taxas):
        amostra = np.random.poisson(lam=taxa, size=tamanho)
        #amostra = np.int64(amostra)
        amostras_poisson.append(amostra)

    return amostras_poisson

def amostras_uniforme_kolmogorov():
    limites = [(0, 5), (2, 4), (1, 5), (3, 7), (4, 6), (0, 3), (1, 4), (2, 5), (3, 6), (5, 8)]

# Tamanhos de amostra variáveis
    tamanhos_amostra = [random.randint(10, 30) for _ in range(10)]

    # Lista para armazenar as amostras
    amostras_uniforme = []

    # Gere 10 amostras de distribuição uniforme com limites e tamanhos variáveis
    for (a, b), tamanho in zip(limites, tamanhos_amostra):
        amostra = np.random.uniform(low=a, high=b, size=tamanho)
        #amostra = np.int64(amostra)
        amostras_uniforme.append(amostra)

    return amostras_uniforme


